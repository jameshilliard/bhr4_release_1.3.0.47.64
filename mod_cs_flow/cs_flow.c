/**
 * Copyright (c) 2015 GreenWave Systems.
 *
 * Author: Greenwave Systems
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "cs_flow.h"

#include <asm/uaccess.h>
#include <linux/atomic.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/types.h>

#define	CS_DEVICE_NO	0

static flows_t active_flows;
static int next_free_flow;

static int add_flow(cs_flow_t *flow)
{
	int i;
	int avail;
	flow->flow_id = 0;
	i = cs_flow_add(CS_DEVICE_NO, flow);
	if (i != CS_OK) return i;
	/* save flow id */
	for (avail=-1, i=0; i < next_free_flow; ++i) {
		if (active_flows[i] == flow->flow_id) return CS_OK;
		if (avail < 0 && active_flows[i] == FLOW_UNUSED) avail = i;
	}
	if (avail < 0) {
		if (next_free_flow < MAX_FLOWS) {
			avail = next_free_flow++;
		} else {
			printk("mod_cs_flow: out of slots for flow 0x%x\n", flow);
			return CS_OK;
		}
	}
	active_flows[avail] = flow->flow_id;
	return CS_OK;
}

static int del_flow(cs_flow_id_t flow_id)
{
	int i;
	/* remove flow id */
	for (i=0; i < next_free_flow; ++i) {
		if (active_flows[i] == flow_id) break;
	}
	if (i < next_free_flow) {
		active_flows[i] = FLOW_UNUSED;
		if (i+1 == next_free_flow) --next_free_flow;
	} else {
		printk("mod_cs_flow: flow 0x%x not found for delete\n", flow_id);
	}
	return cs_flow_delete(CS_DEVICE_NO, flow_id);
}

static int del_all_flows()
{
	int i;
	int f;
	for (f=i=0; i < next_free_flow; ++i) {
		if (active_flows[i] == FLOW_UNUSED) continue;
		cs_flow_delete(CS_DEVICE_NO, active_flows[i]);
		active_flows[i] = FLOW_UNUSED;
		++f;
	}
	next_free_flow = 0;
	return f;
}

static int cs_flow_open(struct inode *inode, struct file *file)
{
	return 0;
}

static int cs_flow_release(struct inode *inode, struct file *file)
{
	return 0;
}

static long cs_flow_ioctl(struct file *file, unsigned cmd, unsigned long arg)
{
	int err;
	cs_flow_id_t flow_id;
	cs_flow_t flow;
	cs_uint32_t tick;
	if (_IOC_TYPE(cmd) != CS_FLOW_IOCTL_MAGIC) return -ENOTTY;
	if (_IOC_NR(cmd) > CS_FLOW_IOCTL_MAX) return -ENOTTY;
	if (_IOC_DIR(cmd) & _IOC_READ)
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	else
		err = 0;
	if (err) return -EFAULT;
	switch (cmd) {
	case CS_FLOW_IOCTL_GET_FLOW:
		err = __copy_from_user(&flow_id, (void *)arg, sizeof(flow_id));
		if (err) return err;
		err = cs_flow_get(CS_DEVICE_NO, flow_id, &flow);
		if (err != CS_OK) return -EINVAL;
		return __copy_to_user((void *)arg, &flow, sizeof(flow));
	case CS_FLOW_IOCTL_ADD_FLOW:
		err = __copy_from_user(&flow, (void *)arg, sizeof(flow));
		if (err) return err;
		err = add_flow(&flow);
		if (err != CS_OK) return -EINVAL;
		return __copy_to_user((void *)arg, &flow, sizeof(flow));
	case CS_FLOW_IOCTL_DEL_FLOW:
		err = del_flow(arg);
		if (err != CS_OK) return -EINVAL;
		return 0;
	case CS_FLOW_IOCTL_TICK_FLOW:
		err = __copy_from_user(&flow_id, (void *)arg, sizeof(flow_id));
		if (err) return err;
		err = cs_flow_get_lastuse_tickcount(CS_DEVICE_NO, flow_id, &tick);
		if (err != CS_OK) return -EINVAL;
		return __copy_to_user((void *)arg, &tick, sizeof(tick));
	case CS_FLOW_IOCTL_GET_ALL_FLOWS:
		return __copy_to_user((void *)arg, &active_flows, sizeof(active_flows));
	case CS_FLOW_IOCTL_DEL_ALL_FLOWS:
		return del_all_flows();
	}
	return -EINVAL;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = cs_flow_open,
	.unlocked_ioctl = cs_flow_ioctl,
	.compat_ioctl = cs_flow_ioctl,
	.llseek = noop_llseek,
	.release = cs_flow_release,
};

static struct miscdevice miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = CS_FLOW_DEVICE_NAME,
	.fops = &fops,
};

static int __init mod_cs_flow_init(void)
{
	int err = 0;
	err = misc_register(&miscdev);
	if (err < 0) {
		pr_err("cs_flow misc_register failed\n");
		return err;
	}
	if (FLOW_UNUSED	!= 0) {
		for (err=0; err < MAX_FLOWS; ++err)
			active_flows[err] = FLOW_UNUSED;
	}
	return 0;
}

static void __exit mod_cs_flow_exit(void)
{
	del_all_flows();
	misc_deregister(&miscdev);
}

module_init(mod_cs_flow_init);
module_exit(mod_cs_flow_exit);

MODULE_DESCRIPTION("cs flow access");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("mod_cs_flow");
MODULE_AUTHOR("Greenwave Systems");
