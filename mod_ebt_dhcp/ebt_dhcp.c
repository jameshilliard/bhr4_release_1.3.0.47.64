/*
 *  ebt_ip -> ebt_dhcp
 *
 *	Authors:
 *	Bart De Schuymer <bdschuym@pandora.be>
 *
 */
#include <linux/ip.h>
#include <net/ip.h>
#include <linux/in.h>
#include <linux/module.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter_bridge/ebtables.h>
#include "ebt_dhcp.h"

#if 0
#define PR_DEBUG(x...) printk(x)
#else
#define PR_DEBUG(x...)
#endif

struct bootp_pkt {              /* BOOTP packet format */
	u8 op;                  /* 1=request, 2=reply */
	u8 htype;               /* HW address type */
	u8 hlen;                /* HW address length */
	u8 hops;                /* Used only by gateways */
	__be32 xid;             /* Transaction ID */
	__be16 secs;            /* Seconds since we started */
	__be16 flags;           /* Just what it says */
	__be32 client_ip;               /* Client's IP address if known */
	__be32 your_ip;         /* Assigned IP address */
	__be32 server_ip;               /* (Next, e.g. NFS) Server's IP address */
	__be32 relay_ip;                /* IP address of BOOTP relay */
	u8 hw_addr[16];         /* Client's HW address */
	u8 serv_name[64];       /* Server host name */
	u8 boot_file[128];      /* Name of boot file */
	__be32 cookie;		/* DHCP / BOOT option cookie */
};

#define	BOOTPREQUEST		0x01
#define DHCP_OPTIONS_COOKIE	0x63825363
#define DHO_PAD			  0
#define DHO_END			255

#define EOF	-1

static inline unsigned getbyte(const struct sk_buff *skb, unsigned offset)
{
	const unsigned char *b;
	unsigned char _b;
	b = skb_header_pointer(skb, offset, sizeof(_b), &_b);
	if (b) return *b;
	PR_DEBUG("dhcp skb EOF!!!\n");
	return EOF;
}

static bool
ebt_dhcp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct ebt_dhcp_info *info = par->matchinfo;
	const struct iphdr *ih;
	struct iphdr _iph;
	const struct udphdr *uh;
	struct udphdr _uh;
	unsigned bootp_off;
	const struct bootp_pkt *bootp;
	struct bootp_pkt _bootp;
	unsigned len;
	unsigned opts;
	unsigned i;
	ih = skb_header_pointer(skb, 0, sizeof(_iph), &_iph);
	if (ih == NULL)
		return false;
	if (ih->protocol != IPPROTO_UDP)
		return false;
	if (ntohs(ih->frag_off) & IP_OFFSET)
		return false;
	uh = skb_header_pointer(skb, ih->ihl*4, sizeof(_uh), &_uh);
	if (uh == NULL)
		return false;
#if 0
	if (ntohs(uh->dest) != 67)
		return false;
	if (ntohs(uh->source) != 68)
		return false;
#endif
	len = ntohs(uh->len);
	if (len < sizeof(_bootp)) {
		PR_DEBUG("dhcp short udp\n");
		return false;
	}
	bootp_off = ih->ihl*4 + sizeof(_uh);
	bootp = skb_header_pointer(skb, bootp_off, sizeof(_bootp), &_bootp);
	/* check op */
	if (bootp->op != BOOTPREQUEST) {
		PR_DEBUG("dhcp wrong op\n");
		return false;
	}
	/* check extension/options cookie */
	if (ntohl(bootp->cookie) != DHCP_OPTIONS_COOKIE) {
		PR_DEBUG("dhcp bad cookie\n");
		return false;
	}
	/* traverse the dhcp msg options, look for MESSAGE TYPE == REQUEST */
	opts = bootp_off + sizeof(_bootp);
	len -= sizeof(_bootp);
	i = 0;
	while (i < len) {
		unsigned opt;
		unsigned l;
		unsigned val;
		if ((opt = getbyte(skb, opts + i + 0)) == EOF) break; /* invalid packet */
		if (opt == DHO_END) break;
		if (opt == DHO_PAD) {
			PR_DEBUG("dhcp padding\n");
			i += 2;
			continue; /* skip */
		}
		if (i+2 >= len) {
			PR_DEBUG("dhcp invalid packet\n");
			break; /* invalid packet!! */
		}
		if ((l = getbyte(skb, opts + i + 1)) == EOF) break; /* invalid packet */
		if ((val = getbyte(skb, opts + i + 2)) == EOF) break; /* invalid packet */
		if (opt == info->optcode) PR_DEBUG("opt code match\n");
		if (val == info->optval) PR_DEBUG("opt val match\n");
		if (FWINV(info->optcode == opt, EBT_DHCP_OPT_CODE)
		&&  FWINV(info->optval == val, EBT_DHCP_OPT_VAL))
			return true;
		i += l;
	}
	PR_DEBUG("dhcp no match\n");
	return false;
}

static int ebt_dhcp_mt_check(const struct xt_mtchk_param *par)
{
	const struct ebt_dhcp_info *info = par->matchinfo;
	const struct ebt_entry *e = par->entryinfo;

	if (e->ethproto != htons(ETH_P_IP) || e->invflags & EBT_IPROTO)
		return -EINVAL;
	if (info->bitmask & ~EBT_DHCP_MASK || info->invflags & ~EBT_DHCP_MASK)
		return -EINVAL;
	/* must have both opt and optval */
	if ((info->bitmask & EBT_DHCP_OPT_MASK) != EBT_DHCP_OPT_MASK)
		return EINVAL;
	PR_DEBUG("dhcp looking for code %d val %d\n", info->optcode, info->optval);
	return 0;
}

static struct xt_match ebt_dhcp_mt_reg __read_mostly = {
	.name		= "dhcp",
	.revision	= 0,
	.family		= NFPROTO_BRIDGE,
	.match		= ebt_dhcp_mt,
	.checkentry	= ebt_dhcp_mt_check,
	.matchsize	= sizeof(struct ebt_dhcp_info),
	.me		= THIS_MODULE,
};

static int __init ebt_dhcp_init(void)
{
	return xt_register_match(&ebt_dhcp_mt_reg);
}

static void __exit ebt_dhcp_fini(void)
{
	xt_unregister_match(&ebt_dhcp_mt_reg);
}

module_init(ebt_dhcp_init);
module_exit(ebt_dhcp_fini);
MODULE_DESCRIPTION("Ebtables: IPv4 DHCP Option match");
MODULE_LICENSE("GPL");
