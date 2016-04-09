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

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <linux/atomic.h>
#include <asm/uaccess.h>
#include "crypto_gws.h"
#include "crypto_gws_logic.h"

/*********************************************************************************
 * Function prototypes
 ********************************************************************************/
static int crypto_open(struct inode*, struct file*);
static unsigned int crypto_poll(struct file*, poll_table*);
static ssize_t crypto_write(struct file*, const char __user* , size_t, loff_t*);
static ssize_t crypto_read(struct file*, char __user*, size_t, loff_t*);
static loff_t crypto_llseek(struct file *filp, loff_t off, int whence);
static int crypto_release(struct inode *inode, struct file *file);

/*********************************************************************************
 * Initialization of Administration Data Structure
 ********************************************************************************/
static struct crypto_driver_data drvData = {
		.numberOfOpensAvailable = ATOMIC_INIT(1),
};

/*********************************************************************************
 * Private data
 ********************************************************************************/
static struct file_operations fops = {
		.owner = THIS_MODULE,
		.poll = crypto_poll,
		.open = crypto_open,
		.write = crypto_write,
		.read = crypto_read,
		.llseek = crypto_llseek,
		.release = crypto_release,
};

static struct miscdevice encryptionDev = {
		.minor = MISC_DYNAMIC_MINOR,
		.name = CRYPTO_DEVICE_NAME "0",
		.fops = &fops,
};

static struct miscdevice decryptionDev = {
		.minor = MISC_DYNAMIC_MINOR,
		.name = CRYPTO_DEVICE_NAME "1",
		.fops = &fops,
};

static int crypto_open(struct inode *pInode, struct file *pFile)
{
	pr_info("device_open(pinode: %p, pfile: %p)\n", pInode, pFile);
	pr_info("device_number: %x\n", pInode->i_rdev);

	if (!atomic_dec_and_test(&drvData.numberOfOpensAvailable)) {
		atomic_inc(&drvData.numberOfOpensAvailable);
		return -EBUSY;
	}

	if (iminor(pInode) == encryptionDev.minor) {
		cryptoOpen(GWS_ENCRYPTION, &drvData.encryptionData);
	} else {
		cryptoOpen(GWS_DECRYPTION, &drvData.decryptionData);
	}
	return SUCCESS;
}

static int crypto_release(struct inode *pInode, struct file *pFile)
{
	pr_info("device_release(%p,%p)\n", pInode, pFile);

	if (iminor(pInode) == encryptionDev.minor) {
		cryptoClose(&drvData.encryptionData);
	} else {
		cryptoClose(&drvData.decryptionData);
	}
	atomic_inc(&drvData.numberOfOpensAvailable);
	return SUCCESS;
}

static unsigned int crypto_poll(struct file* pFile, poll_table* pPollTable)
{
	if (iminor(pFile->f_path.dentry->d_inode) == encryptionDev.minor) {
		return cryptoPoll(pFile, pPollTable, &drvData.encryptionData);
	} else {
		return cryptoPoll(pFile, pPollTable, &drvData.decryptionData);
	}
}

static ssize_t crypto_write(struct file *pFile, const char __user * buffer, size_t length, loff_t * offset)
{
	struct gws_crypto_data* devData;
	pr_devel("encryption_device_write(%p,%s,%d)", pFile, buffer, length);
	if (iminor(pFile->f_path.dentry->d_inode) == encryptionDev.minor) {
		devData = &drvData.encryptionData;
	} else {
		devData = &drvData.decryptionData;
	}
	return cryptoWrite(buffer, length, offset, devData);
}

static ssize_t crypto_read(struct file *pFile, char __user * buffer, size_t length, loff_t * offset)
{
	struct gws_crypto_data* devData;
	pr_devel("encryption_device_read(%p,%p,%d)\n", pFile, buffer, length);
	if (iminor(pFile->f_path.dentry->d_inode) == encryptionDev.minor) {
		devData = &drvData.encryptionData;
	} else {
		devData = &drvData.decryptionData;
	}
	return cryptoRead(pFile, buffer, length, offset, devData);
}

static loff_t crypto_llseek(struct file *filp, loff_t off, int whence)
{
	return -ESPIPE;
}

/*
 * Initialize crypto module - Register the character devices:
 *   /dev/gwr_crypto interface for rsa daemon
 */
static int __init mod_crypto_gwr_init(void)
{
	int err = 0;
	err = misc_register(&encryptionDev);
	if (err < 0) {
		pr_err("encryption misc_register failed\n");
		goto encryptDeviceFailed;
	}
	err = misc_register(&decryptionDev);
	if (err < 0) {
		pr_err("decryption misc_register failed\n");
		goto decryptDeviceFailed;
	}

	return SUCCESS;

decryptDeviceFailed:
	misc_deregister(&encryptionDev);
encryptDeviceFailed:
	return err;
}
module_init(mod_crypto_gwr_init);

#ifdef DEBUG
static void __exit mod_crypto_gwr_exit(void)
{
	misc_deregister(&decryptionDev);
	misc_deregister(&encryptionDev);
}
module_exit(mod_crypto_gwr_exit);
#endif

MODULE_DESCRIPTION("SecureStorage: encryption and decryption using OTP key");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("mod_crypto_gwr");
MODULE_AUTHOR("Greenwave Systems");
