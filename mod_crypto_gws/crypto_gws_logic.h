/**
  Copyright (c) 2014 GreenWave Reality ApS.
*/

#ifndef MOD_CRYPTO_GWS_BL_H_
#define MOD_CRYPTO_GWS_BL_H_

#define GWS_ENCRYPTION 0X00
#define GWS_DECRYPTION 0X01

#define SUCCESS 0

/*********************************************************************************
 * Data types
 ********************************************************************************/
struct gws_crypto_data {
	char* Buffer;
	char* BufferReadPtr;
	__u32 BufferSize; // size of content in buffer
	char operation;
	struct semaphore sem;  /* mutual exclusion semaphore  */
	wait_queue_head_t inq, outq;
};

struct crypto_driver_data {
	struct gws_crypto_data encryptionData;
	struct gws_crypto_data decryptionData;
	atomic_t numberOfOpensAvailable;
};

void cryptoOpen(char, struct gws_crypto_data*);
__s32 cryptoPoll(struct file*, poll_table*, struct gws_crypto_data*);
__s32 cryptoWrite(const char*, __u32, __u64*, struct gws_crypto_data*);
__s32 cryptoRead(struct file*, char*, __u32, __u64*, struct gws_crypto_data*);
void cryptoClose(struct gws_crypto_data*);
void cryptoFree(struct gws_crypto_data*);

#endif

