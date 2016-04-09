/**
  Copyright (c) 2013 GreenWave Reality ApS.
*/

//#define DEBUG

#include "xt_trigger.h"
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

struct xt_trigger_internal {
	struct timer_list timer;
	int refcnt;
	char* name;
	__be32 src;
	uint32_t seconds;
	__be16 port;
	bool valid;
};
static struct xt_trigger_internal xt_trigger = {0};
static DEFINE_SPINLOCK(xt_trigger_lock);

static void trigger_timeout(unsigned long data)
{
	pr_devel("xt_TRIGGER (trigger_timeout) removing registration");
	spin_lock_bh(&xt_trigger_lock);
	if (xt_trigger.name) {
		kfree(xt_trigger.name);
		xt_trigger.name = NULL;
	}
	xt_trigger.valid = FALSE;
	spin_unlock_bh(&xt_trigger_lock);
}

static unsigned int trigger_tg4_target(struct sk_buff* skb, const struct xt_action_param* par)
{
	const struct xt_trigger_mtinfo* info = par->targinfo;
	struct nf_conn* ct = NULL;
	const struct iphdr* iph = ip_hdr(skb);

	spin_lock_bh(&xt_trigger_lock);
	if (par->hooknum == NF_INET_FORWARD) {
		if (!xt_trigger.valid) {
			if (xt_trigger.name) {
				kfree(xt_trigger.name);
			}
			xt_trigger.name = kstrdup(info->name, GFP_KERNEL);
			if (xt_trigger.name) {
				xt_trigger.src = iph->saddr;
				xt_trigger.port = 0;
				if (iph->protocol == IPPROTO_TCP) {
					struct tcphdr* tcp_hdr = (struct tcphdr*)((__u32*)iph + iph->ihl);
					xt_trigger.port = tcp_hdr->source;
				} else if (iph->protocol == IPPROTO_UDP) {
					struct udphdr* udp_hdr = (struct udphdr*)((__u32*)iph + iph->ihl);
					xt_trigger.port = udp_hdr->source;
				}
				xt_trigger.seconds = info->seconds;
				xt_trigger.valid = TRUE;
				mod_timer(&xt_trigger.timer, jiffies + msecs_to_jiffies(xt_trigger.seconds * 1000));
				pr_devel("xt_TRIGGER (target) registered=%s SRC=%pI4 sport=%d, starting timer", xt_trigger.name, &xt_trigger.src, htons(xt_trigger.port));
			}
			spin_unlock_bh(&xt_trigger_lock);
			return NF_ACCEPT;
		} else if (xt_trigger.valid && xt_trigger.name && !strcmp(xt_trigger.name, info->name)) {
			spin_unlock_bh(&xt_trigger_lock);
			return NF_ACCEPT;
		}
	} else if (par->hooknum == NF_INET_PRE_ROUTING) {
		enum ip_conntrack_info ctinfo;

		ct = nf_ct_get(skb, &ctinfo);
		NF_CT_ASSERT(ct != NULL && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED));

		if (ctinfo == IP_CT_NEW) {
			if (xt_trigger.valid && xt_trigger.name && !strcmp(xt_trigger.name, info->name)) {
				__be16 dport = 0;

				if (info->flags & XT_TRIGGER_INITIATING_PORT) {
					if (iph->protocol == IPPROTO_TCP) {
						struct tcphdr* tcp_hdr = (struct tcphdr*)((__u32*)iph + iph->ihl);
						dport = tcp_hdr->dest;
					} else if (iph->protocol == IPPROTO_UDP) {
						struct udphdr* udp_hdr = (struct udphdr*)((__u32*)iph + iph->ihl);
						dport = udp_hdr->dest;
					}
					if (dport != xt_trigger.port) {
						pr_devel("xt_TRIGGER (target) destination port NOT same-as-initiating-port, sport=%d dport=%d", htons(xt_trigger.port), htons(dport));
						spin_unlock_bh(&xt_trigger_lock);
						return XT_CONTINUE;
					}
				}
				struct nf_nat_ipv4_range range;

				memset(&range, 0 , sizeof(range));
				range.min_ip = range.max_ip = xt_trigger.src;
				range.flags = NF_NAT_RANGE_MAP_IPS;

				pr_devel("xt_TRIGGER (target) NEW connection, SRC=%pI4 DST=%pI4 sport=%d dport=%d", &iph->saddr, &iph->daddr, htons(xt_trigger.port), htons(dport));
				spin_unlock_bh(&xt_trigger_lock);
				return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_DST);
			}
		}
	}
	spin_unlock_bh(&xt_trigger_lock);
	return XT_CONTINUE;
}

static int trigger_tg4_check(const struct xt_tgchk_param* par)
{
	spin_lock_bh(&xt_trigger_lock);
	xt_trigger.refcnt++;
	spin_unlock_bh(&xt_trigger_lock);
	pr_devel("xt_TRIGGER (check) refcnt=%d", xt_trigger.refcnt);
	return 0;
}

static void trigger_tg4_destroy(const struct xt_tgdtor_param* par)
{
	spin_lock_bh(&xt_trigger_lock);
	if (--xt_trigger.refcnt) {
		pr_devel("xt_TRIGGER (destroy) refcnt=%d", xt_trigger.refcnt);
		spin_unlock_bh(&xt_trigger_lock);
		return;
	}
	pr_devel("xt_TRIGGER (destroy) refcnt=%d", xt_trigger.refcnt);
	if (xt_trigger.name) {
		pr_devel("xt_TRIGGER (destroy) removing %s", xt_trigger.name);
		kfree(xt_trigger.name);
		xt_trigger.name = NULL;
	}
	del_timer_sync(&xt_trigger.timer);
	spin_unlock_bh(&xt_trigger_lock);
}

static struct xt_target trigger_tg_reg __read_mostly = {
	.name = "TRIGGER",
	.revision = 0,
	.family = NFPROTO_IPV4,
	.hooks = (
	    (1 << NF_INET_PRE_ROUTING) |
	    (1 << NF_INET_FORWARD) |
	    (1 << NF_INET_LOCAL_OUT)
	),
	.targetsize = sizeof(struct xt_trigger_mtinfo),
	.target = trigger_tg4_target,
	.checkentry = trigger_tg4_check,
	.destroy = trigger_tg4_destroy,
	.me = THIS_MODULE
};

static int __init trigger_tg_init(void)
{
	setup_timer(&xt_trigger.timer, trigger_timeout, 0);
	return xt_register_target(&trigger_tg_reg);
}

static void __exit trigger_tg_exit(void)
{
	xt_unregister_target(&trigger_tg_reg);
}

module_init(trigger_tg_init);
module_exit(trigger_tg_exit);

MODULE_DESCRIPTION("Xtables: TRIGGER");
MODULE_LICENSE("GPL");
MODULE_ALIAS("xt_TRIGGER");
MODULE_ALIAS("ipt_TRIGGER");
