/**
  Copyright (c) 2014 GreenWave Systems.
*/

//#define DEBUG

#include "xt_dhcp.h"
#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/spinlock.h>
#include <linux/ip.h>
#include <linux/skbuff.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter/nf_conntrack_common.h>
#include <net/netfilter/nf_nat.h>
#include <net/netfilter/nf_conntrack.h>

static unsigned int dhcp_mt_match(struct sk_buff* skb, const struct xt_action_param* par)
{
	pr_devel("dhcp_mt (match)");
	return 0;
}

static int dhcp_mt_check(const struct xt_tgchk_param* par)
{
	pr_devel("dhcp_mt (check)");
	return 0;
}

static void dhcp_mt_destroy(const struct xt_tgdtor_param* par)
{
	pr_devel("dhcp_mt (destroy)");
}

static struct xt_match dhcp_mt_reg __read_mostly = {
	.name = "dhcp",
	.revision = 0,
	.family = NFPROTO_IPV4,
	.proto = (IPPROTO_UDP),
	.match = dhcp_mt_match,
	.checkentry = dhcp_mt_check,
	.destroy = dhcp_mt_destroy,
	.matchsize = sizeof(struct xt_dhcp_mtinfo),
	.me = THIS_MODULE
};

static int __init dhcp_mt_init(void)
{
	return xt_register_match(&dhcp_mt_reg);
}

static void __exit dhcp_mt_exit(void)
{
	xt_unregister_match(&dhcp_mt_reg);
}

module_init(dhcp_mt_init);
module_exit(dhcp_mt_exit);

MODULE_DESCRIPTION("Xtables: Match specific DHCP message types");
MODULE_LICENSE("GPL");
MODULE_ALIAS("xt_dhcp");
MODULE_ALIAS("ipt_dhcp");
