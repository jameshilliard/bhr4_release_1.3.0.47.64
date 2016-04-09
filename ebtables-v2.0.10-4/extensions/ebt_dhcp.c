/* ebt_ip -> ebt_dhcp
 * 
 * Authors:
 * Bart De Schuymer <bdschuym@pandora.be>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <netdb.h>
#include "../include/ebtables_u.h"
#include <ebt_dhcp.h>

static struct option opts[] =
{
	{ "dhcp-opt-code"      , required_argument, 0, EBT_DHCP_OPT_CODE },
	{ "dhcp-opt-value"     , required_argument, 0, EBT_DHCP_OPT_VAL },
	{ 0 }
};

static void print_help()
{
	printf(
	"dhcp options:\n"
	"  --dhcp-opt-code [!] value\n"
	"  --dhcp-opt-value [!] value\n"
	);
}

static void init(struct ebt_entry_match *match)
{
	struct ebt_dhcp_info *info = (struct ebt_dhcp_info *)match->data;
	info->invflags = 0;
	info->bitmask = 0;
}

static void parse_byte_val(const char *arg, unsigned char *dst)
{
	char *cp;
	long int i;
	i = strtol(arg, &cp, 10);
	if (cp == arg || *cp || i < 0 || i > 0xff)
		ebt_print_error("invalid byte value");
	*dst = i;
}

static int parse(int c, char **argv, int argc, const struct ebt_u_entry *entry,
   unsigned int *flags, struct ebt_entry_match **match)
{
	struct ebt_dhcp_info *info = (struct ebt_dhcp_info *)(*match)->data;

	switch (c) {
	case EBT_DHCP_OPT_CODE:
	case EBT_DHCP_OPT_VAL:
		ebt_check_option2(flags, c);
		info->bitmask |= c;
		if (ebt_check_inverse2(optarg))
			info->invflags |= c;
		if (c == EBT_DHCP_OPT_CODE)
			parse_byte_val(optarg, &info->optcode);
		else
			parse_byte_val(optarg, &info->optval);
		return 1;
	default:
		return 0;
	}
}

static void final_check(const struct ebt_u_entry *entry,
   const struct ebt_entry_match *match, const char *name,
   unsigned int hookmask, unsigned int time)
{
	struct ebt_dhcp_info *info = (struct ebt_dhcp_info *)match->data;
	/* validate ip proto */
	if (entry->ethproto != ETH_P_IP || entry->invflags & EBT_IPROTO)
		ebt_print_error("For DHCP filtering the protocol must be "
		            "specified as IPv4");
	/* we need both optcode and optval */
	if ((info->bitmask & EBT_DHCP_OPT_MASK) != EBT_DHCP_OPT_MASK) 
		ebt_print_error("For DHCP filtering you must set both opt-code and opt-value");
}

static void print(const struct ebt_u_entry *entry,
   const struct ebt_entry_match *match)
{
	struct ebt_dhcp_info *info = (struct ebt_dhcp_info *)match->data;
	if (info->bitmask & EBT_DHCP_OPT_CODE) {
		printf("--dhcp-opt-code ");
		if (info->invflags & EBT_DHCP_OPT_CODE) printf("! ");
		printf("%d ", info->optcode);
	}
	if (info->bitmask & EBT_DHCP_OPT_VAL) {
		printf("--dhcp-opt-value ");
		if (info->invflags & EBT_DHCP_OPT_VAL) printf("! ");
		printf("%d ", info->optval);
	}
}

static int compare(const struct ebt_entry_match *m1,
   const struct ebt_entry_match *m2)
{
	struct ebt_dhcp_info *info1 = (struct ebt_dhcp_info *)m1->data;
	struct ebt_dhcp_info *info2 = (struct ebt_dhcp_info *)m2->data;
	if (info1->bitmask != info2->bitmask)
		return 0;
	if (info1->invflags != info2->invflags)
		return 0;
	if ((info1->bitmask & EBT_DHCP_OPT_CODE)
	&&  info1->optcode != info2->optcode)
		return 0;
	if ((info1->bitmask & EBT_DHCP_OPT_VAL)
	&&  info1->optval != info2->optval)
		return 0;
	return 1;
}

static struct ebt_u_match dhcp_match =
{
	.name		= "dhcp",
	.size		= sizeof(struct ebt_dhcp_info),
	.help		= print_help,
	.init		= init,
	.parse		= parse,
	.final_check	= final_check,
	.print		= print,
	.compare	= compare,
	.extra_ops	= opts,
};

void _init(void)
{
	ebt_register_match(&dhcp_match);
}
