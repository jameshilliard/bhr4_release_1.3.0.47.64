/*
 * (C) Copyright 2013
 * GreenWave Reality Inc. <www.greenwavereality.com>
 * 
 * Based on bcm53xxx_drv
 * (C) Copyright 2013 Cortina-systems <www.cortina-systems.com>
 * and switch-core.c
 * Copyright (C) 2005 Felix Fietkau <openwrt@nbd.name>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/atomic.h>
#include <asm/uaccess.h>
#include "bcm53125_spi_functions.h"
#include "bcm53125_ioctl.h"

/*********************************************************************************
 * Defines
 ********************************************************************************/
#define CHECK_ERR(func) err = func; if (err) return err

#define ROBO_CTRL_PAGE				0x00	/* Control registers */
#define ROBO_RESET_CTRL				0x79	/* Software Reset Control Register */
#define ROBO_PORT0_CTRL				0x00	/* Port 0 Traffic Control Register */
#define ROBO_PORT1_CTRL				0x01	/* Port 1 Traffic Control Register */
#define ROBO_PORT2_CTRL				0x02	/* Port 2 Traffic Control Register */
#define ROBO_PORT3_CTRL				0x03	/* Port 3 Traffic Control Register */
#define ROBO_PORT4_CTRL				0x04	/* Port 4 Traffic Control Register */
#define ROBO_PORT5_CTRL				0x05	/* Port 5 Traffic Control Register */
#define ROBO_SWITCH_MODE			0x0b	/* Switch Mode Control Register */
#define ROBO_IMP_PORT_OVERRIDE_CTRL	0x0e	/* IMP Port State Override Register */
#define ROBO_RGMII_PORT5_TIMING		0x65	/* RGMII Port 5 Timing Delay Register */
#define ROBO_RGMII_IMP_TIMING		0x60	/* RGMII IMP Timing Delay Register */
#define ROBO_PORT5_STATE_OVERRIDE	0x5d	/* Port 5 State Override Register */

#define BCM53125_DEVICE_NAME	"bcm53125"

/*********************************************************************************
 * Data types
 ********************************************************************************/
struct bcm53125_driver_data {
	struct spi_device		*spiDev;
	dev_t					devNumber;
	struct class			*devClass;
	struct cdev				cdev;
	atomic_t				devNumOpensAvailable;
};

/*********************************************************************************
 * Function prototypes
 ********************************************************************************/
static int bcm53125_open(struct inode *inode, struct file *file);
static int bcm53125_release(struct inode *inode, struct file *file);
static long bcm53125_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/*********************************************************************************
 * Private data
 ********************************************************************************/
static struct bcm53125_driver_data drvData = {
		.devNumOpensAvailable = ATOMIC_INIT(1)
};
static int port5Delay = 1;

static struct file_operations bcm53125_fops = {
		.owner = THIS_MODULE,
		.unlocked_ioctl = bcm53125_unlocked_ioctl,
		.open = bcm53125_open,
		.release = bcm53125_release
};

static int bcm53125_open(struct inode *inode, struct file *file)
{
	if (!atomic_dec_and_test(&drvData.devNumOpensAvailable)) {
		atomic_inc(&drvData.devNumOpensAvailable);
		return -EBUSY;
	}
	return 0;
}

static int bcm53125_release(struct inode *inode, struct file *file)
{
	atomic_inc(&drvData.devNumOpensAvailable);
	return 0;
}

static int bcm53125_get_addr_spec_from_user(struct bcm53125_ioctl_addr_spec *addrSpec, void __user *arg)
{
	int err = 0;
	const struct bcm53125_ioctl_addr_spec *userAddrSpec = (const struct bcm53125_ioctl_addr_spec *)arg;
	CHECK_ERR( __get_user(addrSpec->page, &userAddrSpec->page) );
	CHECK_ERR( __get_user(addrSpec->reg, &userAddrSpec->reg) );
	return err;
}

static long bcm53125_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct bcm53125_ioctl_addr_spec addrSpec;
	int err = 0;

	if (_IOC_TYPE(cmd) != BCM53125_IOCTL_MAGIC) return -ENOTTY;
	if (_IOC_NR(cmd) > BCM53125_IOCTL_MAX) return -ENOTTY;
	if (_IOC_DIR(cmd) & _IOC_READ)
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	if (err) return -EFAULT;

	CHECK_ERR( bcm53125_get_addr_spec_from_user(&addrSpec, (void __user *)arg) );

	switch (cmd) {
	case BCM53125_IOCTL_READ_U8_REG:
	{
		u8 val;
		CHECK_ERR( bcm53125_read_u8(drvData.spiDev, addrSpec.page, addrSpec.reg, &val) );
		CHECK_ERR( __put_user(val, &((struct bcm53125_ioctl_u8_register *)arg)->value) );
	}
		break;

	case BCM53125_IOCTL_READ_U16_REG:
	{
		u16 val;
		CHECK_ERR( bcm53125_read_u16(drvData.spiDev, addrSpec.page, addrSpec.reg, &val) );
		CHECK_ERR( __put_user(val, &((struct bcm53125_ioctl_u16_register *)arg)->value) );
	}
		break;

	case BCM53125_IOCTL_READ_U32_REG:
	{
		u32 val;
		CHECK_ERR( bcm53125_read_u32(drvData.spiDev, addrSpec.page, addrSpec.reg, &val) );
		CHECK_ERR( __put_user(val, &((struct bcm53125_ioctl_u32_register *)arg)->value) );
	}
		break;

	case BCM53125_IOCTL_READ_U48_REG:
	{
		u64 val;
		CHECK_ERR( bcm53125_read_u48(drvData.spiDev, addrSpec.page, addrSpec.reg, &val) );
		CHECK_ERR( __put_user(val, &((struct bcm53125_ioctl_u64_register *)arg)->value) );
	}
		break;

	case BCM53125_IOCTL_READ_U64_REG:
	{
		u64 val;
		CHECK_ERR( bcm53125_read_u64(drvData.spiDev, addrSpec.page, addrSpec.reg, &val) );
		CHECK_ERR( __put_user(val, &((struct bcm53125_ioctl_u64_register *)arg)->value) );
	}
		break;

	case BCM53125_IOCTL_WRITE_U8_REG:
	{
		u8 val;
		CHECK_ERR( __get_user(val, &((struct bcm53125_ioctl_u8_register *)arg)->value) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, addrSpec.page, addrSpec.reg, val) );
	}
		break;

	case BCM53125_IOCTL_WRITE_U16_REG:
	{
		u16 val;
		CHECK_ERR( __get_user(val, &((struct bcm53125_ioctl_u16_register *)arg)->value) );
		CHECK_ERR( bcm53125_write_u16(drvData.spiDev, addrSpec.page, addrSpec.reg, val) );
	}
		break;

	case BCM53125_IOCTL_WRITE_U32_REG:
	{
		u32 val;
		CHECK_ERR( __get_user(val, &((struct bcm53125_ioctl_u32_register *)arg)->value) );
		CHECK_ERR( bcm53125_write_u32(drvData.spiDev, addrSpec.page, addrSpec.reg, val) );
	}
		break;

	case BCM53125_IOCTL_WRITE_U48_REG:
	{
		u64 val;
		// For some strange reason, __get_user is not defined for 64-bit values on an ARM
		// so use __copy_from_user as fallback
		CHECK_ERR( __copy_from_user(&val, &((struct bcm53125_ioctl_u64_register *)arg)->value, sizeof(u64)) );
		CHECK_ERR( bcm53125_write_u48(drvData.spiDev, addrSpec.page, addrSpec.reg, val) );
	}
		break;

	case BCM53125_IOCTL_WRITE_U64_REG:
	{
		u64 val;
		// For some strange reason, __get_user is not defined for 64-bit values on an ARM
		// so use __copy_from_user as fallback
		CHECK_ERR( __copy_from_user(&val, &((struct bcm53125_ioctl_u64_register *)arg)->value, sizeof(u64)) );
		CHECK_ERR( bcm53125_write_u64(drvData.spiDev, addrSpec.page, addrSpec.reg, val) );
	}
		break;

	default:
		return -ENOTTY;
	}
	return 0;
}

static int bcm53125_init_switch_chip(void)
{
	int err;
	u8	regVal = 0;

	/* Software reset */
	CHECK_ERR( bcm53125_read_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_RESET_CTRL, &regVal) );
	CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_RESET_CTRL, regVal | 0x90) );
	udelay(10);

	/* Enable IMP port RGMII RX/TX clock delay */
	CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_RGMII_IMP_TIMING, 0x03) );

	/* Enable Port 5 RGMII RX/TX delay */
	CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_RGMII_PORT5_TIMING, port5Delay) );

	/* Enable switch forwarding (if not already enabled) */
	CHECK_ERR( bcm53125_read_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_SWITCH_MODE, &regVal) );
	if ((regVal & 0x02) != 0x02) {
		regVal &= ~(0x01);	/* Unmanaged mode */
		regVal |= 0x02;		/* Enable forwarding */
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_SWITCH_MODE, regVal) );
		CHECK_ERR( bcm53125_read_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_SWITCH_MODE, &regVal) );
		if ((regVal & 0x02) != 0x02) {
			printk(KERN_ERR "Failed to enable bcm53125 switch forwarding\n");
			return -EBUSY;
		}

		/* Disable spanning tree for all ports */
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT0_CTRL, 0x00) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT1_CTRL, 0x00) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT2_CTRL, 0x00) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT3_CTRL, 0x00) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT4_CTRL, 0x00) );
		CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT5_CTRL, 0x00) );
	}

	/* Force IMP port to Link pass */
	CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_IMP_PORT_OVERRIDE_CTRL, 0xbb) );

	/* Force Port 5 to Link pass */
	CHECK_ERR( bcm53125_write_u8(drvData.spiDev, ROBO_CTRL_PAGE, ROBO_PORT5_STATE_OVERRIDE, 0x7b) );

	return 0;
}

static int __init bcm53125_init(void)
{
	int err = 0;

	drvData.spiDev = bcm53125_spi_get_device();
	if (!drvData.spiDev)
		return -ENODEV;

	err = bcm53125_init_switch_chip();
	if (err) goto initFailed;

	if (alloc_chrdev_region(&drvData.devNumber, 0, 1, BCM53125_DEVICE_NAME) < 0) {
		printk(KERN_ERR "bcm53125 device register failed\n");
		err = -1;
		goto initFailed;
	}

	drvData.devClass = class_create(THIS_MODULE, BCM53125_DEVICE_NAME);

	cdev_init(&drvData.cdev, &bcm53125_fops);
	drvData.cdev.owner = THIS_MODULE;

	err = cdev_add(&drvData.cdev, drvData.devNumber, 1);
	if (err) {
		printk(KERN_ERR "cdev_add failed\n");
		class_destroy(drvData.devClass);
		unregister_chrdev_region(drvData.devNumber, 1);
		goto initFailed;
	}

	device_create(drvData.devClass, NULL, MKDEV(MAJOR(drvData.devNumber), 0), NULL, BCM53125_DEVICE_NAME);

	return 0;

initFailed:
	spi_dev_put(drvData.spiDev);
	drvData.spiDev = NULL;
	return err;
}
 
static void __exit bcm53125_exit(void)
{
	device_destroy(drvData.devClass, MKDEV(MAJOR(drvData.devNumber), 0));
	cdev_del(&drvData.cdev);
	class_destroy(drvData.devClass);
	unregister_chrdev_region(drvData.devNumber, 1);
	if (drvData.spiDev)
		spi_dev_put(drvData.spiDev);
}

module_init(bcm53125_init);
module_exit(bcm53125_exit);
module_param(port5Delay, int, S_IRUGO);

MODULE_DESCRIPTION("Driver for BCM53125 Switch Chip");
MODULE_VERSION("0.1");
MODULE_AUTHOR("www.greenwavereality.com");
MODULE_LICENSE("GPL");
