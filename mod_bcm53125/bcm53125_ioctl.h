/*
 * (C) Copyright 2013
 * GreenWave Reality Inc. <www.greenwavereality.com>
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

#ifndef BCM53125_IOCTL_H_
#define BCM53125_IOCTL_H_

#include <linux/ioctl.h>
#include <linux/types.h>

struct bcm53125_ioctl_addr_spec {
	__u8 page;
	__u8 reg;
};

struct bcm53125_ioctl_u8_register {
	struct bcm53125_ioctl_addr_spec addrSpec;
	__u8							value;
};

struct bcm53125_ioctl_u16_register {
	struct bcm53125_ioctl_addr_spec addrSpec;
	__u16							value;
};

struct bcm53125_ioctl_u32_register {
	struct bcm53125_ioctl_addr_spec addrSpec;
	__u32							value;
};

struct bcm53125_ioctl_u64_register {
	struct bcm53125_ioctl_addr_spec addrSpec;
	__u64							value;
};

#define BCM53125_IOCTL_MAGIC '#'

#define BCM53125_IOCTL_READ_U8_REG		_IOR(BCM53125_IOCTL_MAGIC, 0, struct bcm53125_ioctl_u8_register		)
#define BCM53125_IOCTL_READ_U16_REG		_IOR(BCM53125_IOCTL_MAGIC, 1, struct bcm53125_ioctl_u16_register	)
#define BCM53125_IOCTL_READ_U32_REG		_IOR(BCM53125_IOCTL_MAGIC, 2, struct bcm53125_ioctl_u32_register	)
#define BCM53125_IOCTL_READ_U48_REG		_IOR(BCM53125_IOCTL_MAGIC, 3, struct bcm53125_ioctl_u64_register	)
#define BCM53125_IOCTL_READ_U64_REG		_IOR(BCM53125_IOCTL_MAGIC, 4, struct bcm53125_ioctl_u64_register	)
#define BCM53125_IOCTL_WRITE_U8_REG		_IOW(BCM53125_IOCTL_MAGIC, 5, struct bcm53125_ioctl_u8_register		)
#define BCM53125_IOCTL_WRITE_U16_REG	_IOW(BCM53125_IOCTL_MAGIC, 6, struct bcm53125_ioctl_u16_register	)
#define BCM53125_IOCTL_WRITE_U32_REG	_IOW(BCM53125_IOCTL_MAGIC, 7, struct bcm53125_ioctl_u32_register	)
#define BCM53125_IOCTL_WRITE_U48_REG	_IOW(BCM53125_IOCTL_MAGIC, 8, struct bcm53125_ioctl_u64_register	)
#define BCM53125_IOCTL_WRITE_U64_REG	_IOW(BCM53125_IOCTL_MAGIC, 9, struct bcm53125_ioctl_u64_register	)
#define BCM53125_IOCTL_MAX										  10

#endif /* BCM53125_IOCTL_H_ */
