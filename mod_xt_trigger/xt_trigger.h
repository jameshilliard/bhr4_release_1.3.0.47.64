/**
  Copyright (c) 2013 GreenWave Reality ApS.
*/

#ifndef XT_TRIGGER_H_
#define XT_TRIGGER_H_

#include <linux/netfilter.h>

enum {
    XT_TRIGGER_TRIGGER         = 1 << 0,
    XT_TRIGGER_INITIATING_PORT = 1 << 1,
    XT_TRIGGER_SECONDS         = 1 << 2,
    XT_TRIGGER_NAME            = 1 << 3,
};

#define XT_TRIGGER_MAXNAMELEN 32

/* Private data structure for each rule with a TRIGGER target */
struct xt_trigger_mtinfo {
	__u32 seconds;
	__u16 flags;
	__u16 pad;
	char name[XT_TRIGGER_MAXNAMELEN];
};

#endif /* XT_TRIGGER_H_ */

