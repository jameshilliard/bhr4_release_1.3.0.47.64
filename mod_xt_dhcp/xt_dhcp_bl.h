/**
  Copyright (c) 2014 GreenWave Reality ApS.
*/

#ifndef XT_DHCP_BL_H_
#define XT_DHCP_BL_H_

#include <linux/types.h>

unsigned int dhcp_bl_mt(const __u8* package, unsigned int len, __u8 messageType);

#endif

