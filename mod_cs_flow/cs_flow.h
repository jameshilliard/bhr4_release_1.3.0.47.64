/**
 * Copyright (c) 2015 GreenWave Systems.
 *
 * Author: Greenwave Systems
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef MOD_CS_FLOW_H_
#define MOD_CS_FLOW_H_

#include <linux/ioctl.h>
#include <linux/types.h>

#include <mach/cs_flow_api.h>

/**
 * Device name for cs_flow device
 */
#define CS_FLOW_DEVICE_NAME "cs_flow"

typedef cs_uint16_t cs_flow_id_t;

#define	MAX_FLOWS	128
#define	FLOW_UNUSED	0
typedef cs_flow_id_t flows_t[MAX_FLOWS];

#define CS_FLOW_IOCTL_MAGIC 0xcf

#define CS_FLOW_IOCTL_GET_FLOW		_IOWR(CS_FLOW_IOCTL_MAGIC, 0, cs_flow_t)
#define CS_FLOW_IOCTL_ADD_FLOW		_IOR(CS_FLOW_IOCTL_MAGIC, 1, cs_flow_t)
#define CS_FLOW_IOCTL_DEL_FLOW		_IO(CS_FLOW_IOCTL_MAGIC, 2)
#define CS_FLOW_IOCTL_TICK_FLOW		_IOWR(CS_FLOW_IOCTL_MAGIC, 3, cs_uint32_t)
#define CS_FLOW_IOCTL_GET_ALL_FLOWS	_IOR(CS_FLOW_IOCTL_MAGIC, 4, flows_t)
#define CS_FLOW_IOCTL_DEL_ALL_FLOWS	_IO(CS_FLOW_IOCTL_MAGIC, 5)
#define CS_FLOW_IOCTL_MAX			5

#endif
