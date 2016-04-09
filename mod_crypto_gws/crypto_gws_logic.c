/**
 * Copyright (c) 2014 GreenWave Systems.
 *
 * Author: Greenwave Systems
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

//#define DEBUG
// Necessary to allow building and running in unit test context
#ifdef __KERNEL__
#include <linux/atomic.h>
#include <linux/crypto.h>
#include <linux/err.h>
#include <linux/poll.h>
#include <linux/scatterlist.h>
#include <linux/sched.h>
#include <linux/slab.h>
#else
#include "linux/types.h"
#include "host_kernel_types.h"
#include "host_kernel_func.h"
#endif
#include "crypto_gws.h"
#include "crypto_gws_logic.h"

#define AUTHBUFSIZE 8
#define ENCKEYLEN 24
#define MAX_IVLEN 32
#define OTP_TLV_KEY_TYPE 0xc

extern int read_OTP_tlv(u8 type, u8* buffer, u16* len);

static int init_crypt_alg(struct crypto_aead **tfm, struct aead_request **req, char *iv, char *key);
static int encrypt(struct gws_crypto_data* cryptoData);
static int decrypt(struct gws_crypto_data* cryptoData);

void cryptoOpen(char operation, struct gws_crypto_data* cryptoData)
{
	cryptoData->operation = operation;
	sema_init(&cryptoData->sem, 1);
	init_waitqueue_head(&cryptoData->inq);
	init_waitqueue_head(&cryptoData->outq);
}

__s32 cryptoPoll(struct file* pFile, poll_table* pPollTable,
		struct gws_crypto_data* cryptoData)
{
	unsigned int mask = 0;

	poll_wait(pFile, &cryptoData->inq, pPollTable);
	poll_wait(pFile, &cryptoData->outq, pPollTable);
	if (cryptoData->Buffer != NULL) {
		mask |= POLLIN | POLLRDNORM;
	}
	if (cryptoData->Buffer == NULL) {
		mask |= POLLOUT | POLLWRNORM;
	}
	return mask;
}

__s32 cryptoWrite(const char * buffer, __u32 length, __u64 * offset, struct gws_crypto_data* cryptoData)
{
	int retVal;
	pr_devel("buffer state(%p, %d)\n", cryptoData->Buffer, cryptoData->BufferSize);
	if (down_interruptible(&cryptoData->sem)) {
		pr_devel("Semaphore unavailable\n");
		return -ERESTARTSYS;
	}
	if (cryptoData->Buffer != NULL) {
		retVal = -EAGAIN;
		goto WriteDone;
	}
	if (length > MAX_PAYLOAD_LENGTH) {
		retVal = -E2BIG;
		goto WriteDone;
	}
	if (length <= AUTHBUFSIZE) {
		retVal = -EFAULT;
		goto WriteDone;
	}
	cryptoData->BufferSize = length + ((cryptoData->operation == GWS_ENCRYPTION) ? AUTHBUFSIZE : 0);
	cryptoData->Buffer = kmalloc(cryptoData->BufferSize, GFP_KERNEL);
	pr_devel("buffer state(%p, %d)\n", cryptoData->Buffer, cryptoData->BufferSize);
	if (copy_from_user(cryptoData->Buffer, buffer, length)) {
		retVal = -EFAULT;
		goto WriteDone;
	};
	pr_devel("Wrote %d bytes\n", length);

	retVal = (cryptoData->operation == GWS_ENCRYPTION) ? encrypt(cryptoData) : decrypt(cryptoData);
	if (retVal) {
		goto WriteDone;
	}
	pr_devel("Crypt complete\n");

	cryptoData->BufferReadPtr = cryptoData->Buffer;
	retVal = length;
WriteDone:
	up(&cryptoData->sem);
	wake_up_interruptible(&cryptoData->inq);
	pr_devel("Write call complete\n");
	return retVal;
}

__s32 cryptoRead(struct file* pFile, char * buffer, __u32 length,__u64 * offset, struct gws_crypto_data* cryptoData)
{
	int remaining = 0;
	int alreadyRead = 0;
	int lengthToRead = length;
	pr_devel("buffer state(%p, %p, %d)\n", cryptoData->Buffer, cryptoData->BufferReadPtr, cryptoData->BufferSize);
	if (length <= AUTHBUFSIZE) {
		return -EFAULT;
	}
	if (down_interruptible(&cryptoData->sem)) {
		pr_devel("Semaphore unavailable\n");
		return -ERESTARTSYS;
	}
	while (cryptoData->Buffer == NULL) {
		up(&cryptoData->sem);
		if (pFile->f_flags & O_NONBLOCK)
			return -EAGAIN;
		pr_devel("reading: going to sleep\n");
		if (wait_event_interruptible(cryptoData->inq, (cryptoData->Buffer != NULL)))
			return -ERESTARTSYS;
		if (down_interruptible(&cryptoData->sem)) {
			pr_devel("Semaphore unavailable\n");
			return -ERESTARTSYS;
		}
	}
	alreadyRead = cryptoData->BufferReadPtr - cryptoData->Buffer;
	if (length > cryptoData->BufferSize - alreadyRead) {
		pr_devel("Remaining buffer size %d smaller than read length\n", cryptoData->BufferSize - alreadyRead);
		lengthToRead = cryptoData->BufferSize - alreadyRead;
	}
	if (lengthToRead <= 0) {
		pr_devel("Buffer already read\n");
		goto cleanup;
	}
	remaining = copy_to_user(buffer, cryptoData->BufferReadPtr, lengthToRead);
	pr_devel("Read %d bytes, %d left\n", lengthToRead - remaining, remaining);
	cryptoData->BufferReadPtr += lengthToRead - remaining;
cleanup:
	if (cryptoData->BufferReadPtr - cryptoData->Buffer >= cryptoData->BufferSize) {
		// All data has been read
		cryptoFree(cryptoData);
	}
	up(&cryptoData->sem);
	wake_up_interruptible(&cryptoData->outq);
	return lengthToRead - remaining;
}

static int init_crypt_alg(struct crypto_aead **tfm, struct aead_request **req, char *iv, char *key)
{
	size_t ivsize;
	int retVal = -EFAULT;
	u16 encCryptSize = ENCKEYLEN;
	*tfm = crypto_alloc_aead("gcm(aes)", 0, 0);
	if (IS_ERR(*tfm)) {
		pr_devel("alg: Failed to load transform for %s: %ld\n", "gcm(aes)", PTR_ERR(*tfm));
		goto alloc_error;
	}
	*req = aead_request_alloc(*tfm, GFP_KERNEL);
	if (!req) {
		pr_devel("alg: Failed to allocate request \n");
		goto request_error;
	}
	key = kmalloc(ENCKEYLEN, GFP_KERNEL);
	if (read_OTP_tlv(OTP_TLV_KEY_TYPE, key, &encCryptSize)) {
		pr_devel("alg: Failed read OTP key \n");
		goto init_error;
	}
	retVal = crypto_aead_setkey(*tfm, key, ENCKEYLEN);
	if (retVal) {
		pr_devel("alg: Failed to setkey \n");
		goto init_error;
	}
	retVal = crypto_aead_setauthsize(*tfm, AUTHBUFSIZE);
	if (retVal) {
		pr_devel("alg: Failed to setauthsize \n");
		goto init_error;
	}
	ivsize = crypto_aead_ivsize(*tfm);
	if (!ivsize || ivsize>MAX_IVLEN) {
		pr_devel("alg: Failed to crypto_aead_ivsize \n");
		goto init_error;
	}
	memset(iv, 0x54, ivsize);
	pr_devel("alg: ivsize=%d", ivsize);
	return 0;
init_error:
	kfree(key);
	kfree(req);
request_error:
	crypto_free_aead(*tfm);
alloc_error:
	return retVal;
}

static int encrypt(struct gws_crypto_data* cryptoData)
{
	struct crypto_aead *tfm = NULL;
	struct aead_request *req = NULL;
	char *key = NULL;
	char axbuf[AUTHBUFSIZE];
	struct scatterlist slAssoc;
	struct scatterlist slSrc;
	struct scatterlist slDst;
	char iv[MAX_IVLEN];
	__u32 dataLen = 0;
	int retVal = -EFAULT;

	retVal = init_crypt_alg(&tfm, &req, iv, key);
	if (retVal) {
		pr_devel("alg: encrypt: Failed to initialize crypto algorithm \n");
		goto init_encrypt_error;
	}
	crypto_aead_clear_flags(tfm, ~0);
	dataLen = cryptoData->BufferSize - AUTHBUFSIZE;
	memset(&axbuf[0], 1, AUTHBUFSIZE);

	sg_init_one(&slSrc, cryptoData->Buffer, dataLen);
	sg_init_one(&slAssoc, &axbuf[0], AUTHBUFSIZE);
	sg_init_one(&slDst, cryptoData->Buffer, dataLen + AUTHBUFSIZE);
	pr_devel("alg: encrypt: sg_init done dataLen=%u", dataLen );
	aead_request_set_callback(req, 0, NULL, NULL);
	aead_request_set_assoc(req, &slAssoc, AUTHBUFSIZE);
	aead_request_set_crypt(req, &slSrc, &slDst, dataLen, iv);
	pr_devel("alg: encrypt: now encrypt");
	retVal = crypto_aead_encrypt(req);
	switch (retVal) {
		case 0:
			pr_devel("alg: encrypt: encrypt ok");
			break;
		case -EINPROGRESS:
		case -EBUSY:
			pr_devel("alg: encrypt: authentication not done yet\n");
			break;
		case -EBADMSG:
			pr_devel("alg: encrypt: authentication failed \n");
			break;
		default:
			pr_devel("alg: encrypt: Failed to decrypt %X \n",retVal);
	}
	kfree(key);
	kfree(req);
	crypto_free_aead(tfm);
init_encrypt_error:
	return retVal;
}

static int decrypt(struct gws_crypto_data* cryptoData)
{
	struct crypto_aead *tfm = NULL;
	char *key = NULL;
	struct aead_request *req;
	struct scatterlist slAssoc;
	struct scatterlist slSrc;
	char iv[MAX_IVLEN];
	char axbuf[AUTHBUFSIZE];
	int retVal = -EFAULT;

	retVal = init_crypt_alg(&tfm, &req, iv, key);
	if (retVal) {
		pr_devel("alg: decrypt: Failed to initialize crypto algorithm \n");
		goto init_decrypt_error;
	}
	crypto_aead_clear_flags(tfm, ~0);
	sg_init_one(&slSrc, cryptoData->Buffer, cryptoData->BufferSize);
	memset(&axbuf[0], 1, AUTHBUFSIZE);
	sg_init_one(&slAssoc, &axbuf[0], AUTHBUFSIZE);

	aead_request_set_callback(req, 0, NULL, NULL);
	aead_request_set_assoc(req, &slAssoc, AUTHBUFSIZE);
	aead_request_set_crypt(req, &slSrc, &slSrc, cryptoData->BufferSize, iv);
	retVal = crypto_aead_decrypt(req);
	switch (retVal) {
		case 0:
			pr_devel("alg: decrypt: encrypt ok");
			//correct read data size (without authentication)
			cryptoData->BufferSize -= AUTHBUFSIZE;
			break;
		case -EINPROGRESS:
		case -EBUSY:
			pr_devel("alg: decrypt: authentication not done yet %X\n", retVal);
			break;
		case -EBADMSG:
			pr_devel("alg: decrypt: authentication failed \n");
			break;
		default:
			pr_devel("alg: decrypt: Failed to decrypt %X \n", retVal);
	}
	kfree(key);
	kfree(req);
	crypto_free_aead(tfm);
init_decrypt_error:
	return retVal;
}

void cryptoClose(struct gws_crypto_data* cryptoData)
{
	cryptoFree(cryptoData);
}

void cryptoFree(struct gws_crypto_data* cryptoData)
{
	if (cryptoData->Buffer != NULL) {
		kfree(cryptoData->Buffer);
		cryptoData->Buffer = NULL;
		cryptoData->BufferReadPtr = NULL;
		cryptoData->BufferSize = 0;
	}
}
