/*
 *  ebt_ip -> ebt_dhcp
 *
 *	Authors:
 *	Bart De Schuymer <bart.de.schuymer@pandora.be>
 *
 */

#ifndef __LINUX_BRIDGE_EBT_DHCP_H
#define __LINUX_BRIDGE_EBT_DHCP_H

#include <linux/types.h>

#define EBT_DHCP_MATCH "dhcp"

#define	EBT_DHCP_OPT_CODE	0x01
#define EBT_DHCP_OPT_VAL	0x02
#define EBT_DHCP_OPT_MASK	(EBT_DHCP_OPT_CODE | EBT_DHCP_OPT_VAL)

#define EBT_DHCP_MASK (EBT_DHCP_OPT_MASK)

/* the same values are used for the invflags */
struct ebt_dhcp_info {
	__u8 bitmask;
	__u8 invflags;
	__u8 optcode;
	__u8 optval;
};

#endif
