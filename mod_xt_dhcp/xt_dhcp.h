/**
  Copyright (c) 2014 GreenWave Systems
*/

#ifndef XT_DHCP_H_
#define XT_DHCP_H_

#include <linux/netfilter.h>

enum {
	XT_DHCP_TYPE = 1 << 0
};

/** Binary interface to the user mode part. */
struct xt_dhcp_mtinfo {
	__u32 dhcp_type; /**< Message type */
	__u16 flags;
	__u16 pad;
};

#endif /* XT_DHCP_H_ */
