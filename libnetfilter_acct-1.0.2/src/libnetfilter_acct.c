/*
 * (C) 2011 by Pablo Neira Ayuso <pablo@netfilter.org>
 * (C) 2011 by Intra2net AG <http://www.intra2net.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 */
#include "internal.h"

#include <time.h>
#include <endian.h>
#include <stdlib.h>
#include <string.h>

#include <libmnl/libmnl.h>
#include <linux/netfilter/nfnetlink.h>
#include <linux/netfilter/nfnetlink_acct.h>

#include <libnetfilter_acct/libnetfilter_acct.h>

/**
 * \mainpage
 *
 * libnetfilter_acct is the userspace library that provides a programming
 * interface (API) to the extended accounting infrastructure. Basically, you
 * can find here a set of helper functions that you can use together with
 * libmnl.
 *
 * libnetfilter_acct homepage is:
 *      http://netfilter.org/projects/libnetfilter_acct/
 *
 * \section Dependencies
 * libnetfilter_acct requires libmnl >= 1.0.0 and the Linux kernel that
 * includes the nfnetlink_acct subsystem (i.e. 3.3.x or any later).
 *
 * \section Main Features
 *  - listing/retrieving existing accounting objects.
 *  - atomically retrieving and reset accounting objects.
 *  - inserting/modifying/deleting accounting objects.
 *
 * \section Git Tree
 * The current development version of libnetfilter_acct can be accessed at
 * https://git.netfilter.org/cgi-bin/gitweb.cgi?p=libnetfilter_acct.git
 *
 * \section using Using libnetfilter_acct
 * To write your own program using libnetfilter_acct, you should start by
 * reading the documentation for libmnl to understand basic operation with
 * Netlink sockets. Moreover, you may want to check the examples available
 * under examples/ in the libnetfilter_acct source code. You can compile
 * these examples by invoking `make check'.
 *
 * \section Authors
 * libnetfilter_acct has been written by Pablo Neira Ayuso.
 */

struct nfacct {
	char		name[NFACCT_NAME_MAX];
	uint64_t	pkts;
	uint64_t	bytes;
	uint32_t	bitset;
};

/**
 * \defgroup nfacct Accounting object handling
 * @{
 */

/**
 * nfacct_alloc - allocate a new accounting object
 *
 * In case of success, this function returns a valid pointer, otherwise NULL
 * s returned and errno is appropriately set.
 */
struct nfacct *nfacct_alloc(void)
{
	return calloc(1, sizeof(struct nfacct));
}
EXPORT_SYMBOL(nfacct_alloc);

/**
 * nfacct_free - release one accounting object
 * \param nfacct pointer to the accounting object
 */
void nfacct_free(struct nfacct *nfacct)
{
	free(nfacct);
}
EXPORT_SYMBOL(nfacct_free);

/**
 * nfacct_attr_set - set one attribute of the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 * \param data pointer to data that will be used to set this attribute
 */
void
nfacct_attr_set(struct nfacct *nfacct, enum nfacct_attr_type type,
		const void *data)
{
	switch(type) {
	case NFACCT_ATTR_NAME:
		strncpy(nfacct->name, data, NFACCT_NAME_MAX);
		nfacct->name[NFACCT_NAME_MAX-1] = '\0';
		nfacct->bitset |= (1 << NFACCT_ATTR_NAME);
		break;
	case NFACCT_ATTR_PKTS:
		nfacct->pkts = *((uint64_t *) data);
		nfacct->bitset |= (1 << NFACCT_ATTR_PKTS);
		break;
	case NFACCT_ATTR_BYTES:
		nfacct->bytes = *((uint64_t *) data);
		nfacct->bitset |= (1 << NFACCT_ATTR_BYTES);
		break;
	}
}
EXPORT_SYMBOL(nfacct_attr_set);

/**
 * nfacct_attr_set_str - set one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 * \param name string that will be used to set this attribute
 */
void
nfacct_attr_set_str(struct nfacct *nfacct, enum nfacct_attr_type type,
		    const char *name)
{
	nfacct_attr_set(nfacct, type, name);
}
EXPORT_SYMBOL(nfacct_attr_set_str);

/**
 * nfacct_attr_set_u64 - set one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 * \param value unsigned 64-bits integer
 */
void
nfacct_attr_set_u64(struct nfacct *nfacct, enum nfacct_attr_type type,
		    uint64_t value)
{
	nfacct_attr_set(nfacct, type, &value);
}
EXPORT_SYMBOL(nfacct_attr_set_u64);

/**
 * nfacct_attr_unset - unset one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 */
void
nfacct_attr_unset(struct nfacct *nfacct, enum nfacct_attr_type type)
{
	switch(type) {
	case NFACCT_ATTR_NAME:
		nfacct->bitset &= ~(1 << NFACCT_ATTR_NAME);
		break;
	case NFACCT_ATTR_PKTS:
		nfacct->bitset &= ~(1 << NFACCT_ATTR_PKTS);
		break;
	case NFACCT_ATTR_BYTES:
		nfacct->bitset &= ~(1 << NFACCT_ATTR_BYTES);
		break;
	}
}
EXPORT_SYMBOL(nfacct_attr_unset);

/**
 * nfacct_attr_get - get one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 *
 * This function returns a valid pointer to the attribute data. If a
 * unsupported attribute is used, this returns NULL.
 */
const void *nfacct_attr_get(struct nfacct *nfacct, enum nfacct_attr_type type)
{
	const void *ret = NULL;

	switch(type) {
	case NFACCT_ATTR_NAME:
		if (nfacct->bitset & (1 << NFACCT_ATTR_NAME))
			ret = nfacct->name;
		break;
	case NFACCT_ATTR_PKTS:
		if (nfacct->bitset & (1 << NFACCT_ATTR_PKTS))
			ret = &nfacct->pkts;
		break;
	case NFACCT_ATTR_BYTES:
		if (nfacct->bitset & (1 << NFACCT_ATTR_BYTES))
			ret = &nfacct->bytes;
		break;
	}
	return ret;
}
EXPORT_SYMBOL(nfacct_attr_get);

/**
 * nfacct_attr_get_str - get one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 *
 * This function returns a valid pointer to the beginning of the string.
 * If the attribute is unsupported, this returns NULL.
 */
const char *
nfacct_attr_get_str(struct nfacct *nfacct, enum nfacct_attr_type type)
{
	return nfacct_attr_get(nfacct, type);
}
EXPORT_SYMBOL(nfacct_attr_get_str);

/**
 * nfacct_attr_get_u64 - get one attribute the accounting object
 * \param nfacct pointer to the accounting object
 * \param type attribute type you want to set
 *
 * This function returns a unsigned 64-bits integer. If the attribute is
 * unsupported, this returns NULL.
 */
uint64_t nfacct_attr_get_u64(struct nfacct *nfacct, enum nfacct_attr_type type)
{
	const void *ret = nfacct_attr_get(nfacct, type);
	return ret ? *((uint64_t *)ret) : 0;
}
EXPORT_SYMBOL(nfacct_attr_get_u64);

static int
nfacct_snprintf_plain(char *buf, size_t rem, struct nfacct *nfacct,
		      uint16_t flags)
{
	int ret;

	if (flags & NFACCT_SNPRINTF_F_FULL) {
		ret = snprintf(buf, rem,
			"{ pkts = %.20llu, bytes = %.20llu } = %s;",
			(unsigned long long)
			nfacct_attr_get_u64(nfacct, NFACCT_ATTR_PKTS),
			(unsigned long long)
			nfacct_attr_get_u64(nfacct, NFACCT_ATTR_BYTES),
			nfacct_attr_get_str(nfacct, NFACCT_ATTR_NAME));
	} else {
		ret = snprintf(buf, rem, "%s\n",
			nfacct_attr_get_str(nfacct, NFACCT_ATTR_NAME));
	}

	return ret;
}

#define BUFFER_SIZE(ret, size, rem, offset)		\
	size += ret;					\
	if (ret > rem)					\
		ret = rem;				\
	offset += ret;					\
	rem -= ret;

static int
nfacct_snprintf_xml_localtime(char *buf, unsigned int rem, const struct tm *tm)
{
        int ret = 0;
        unsigned int size = 0, offset = 0;

        ret = snprintf(buf+offset, rem, "<hour>%d</hour>", tm->tm_hour);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<min>%02d</min>", tm->tm_min);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<sec>%02d</sec>", tm->tm_sec);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<wday>%d</wday>", tm->tm_wday + 1);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<day>%d</day>", tm->tm_mday);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<month>%d</month>", tm->tm_mon + 1);
        BUFFER_SIZE(ret, size, rem, offset);

        ret = snprintf(buf+offset, rem, "<year>%d</year>", 1900 + tm->tm_year);
        BUFFER_SIZE(ret, size, rem, offset);

        return size;
}


static int
nfacct_snprintf_xml(char *buf, size_t rem, struct nfacct *nfacct,
		    uint16_t flags)
{
	int ret = 0;
	unsigned int size = 0, offset = 0;

	ret = snprintf(buf, rem,
			"<obj><name>%s</name>"
			"<pkts>%.20llu</pkts>"
			"<bytes>%.20llu</bytes>",
			nfacct_attr_get_str(nfacct, NFACCT_ATTR_NAME),
			(unsigned long long)
			nfacct_attr_get_u64(nfacct, NFACCT_ATTR_BYTES),
			(unsigned long long)
			nfacct_attr_get_u64(nfacct, NFACCT_ATTR_PKTS));
	BUFFER_SIZE(ret, size, rem, offset);

	if (flags & NFACCT_SNPRINTF_F_TIME) {
		time_t t;
		struct tm tm;

		t = time(NULL);
		if (localtime_r(&t, &tm) == NULL)
			goto err;

		ret = nfacct_snprintf_xml_localtime(buf+offset, rem, &tm);
	        BUFFER_SIZE(ret, size, rem, offset);
	}

	ret = snprintf(buf+offset, rem, "</obj>");
	BUFFER_SIZE(ret, size, rem, offset);

err:
	return ret;
}

/**
 * nfacct_snprintf - print accounting object into one buffer
 * \param buf: pointer to buffer that is used to print the object
 * \param size: size of the buffer (or remaining room in it).
 * \param nfacct: pointer to a valid accounting object.
 * \param type: format output type, NFACCT_SNPRINTF_T_[PLAIN|XML]
 * \param flags: output flags (NFACCT_SNPRINTF_F_FULL).
 *
 * This function returns -1 in case that some mandatory attributes are
 * missing. On sucess, it returns 0.
 */
int nfacct_snprintf(char *buf, size_t size, struct nfacct *nfacct,
		    uint16_t type, uint16_t flags)
{
	int ret = 0;

	switch(type) {
	case NFACCT_SNPRINTF_T_PLAIN:
		ret = nfacct_snprintf_plain(buf, size, nfacct, flags);
		break;
	case NFACCT_SNPRINTF_T_XML:
		ret = nfacct_snprintf_xml(buf, size, nfacct, flags);
		break;
	default:
		ret = -1;
		break;
	}
	return ret;
}
EXPORT_SYMBOL(nfacct_snprintf);

/**
 * @}
 */

/**
 * \defgroup nlmsg Netlink message helper functions
 * @{
 */

/**
 * nfacct_nlmsg_build_hdr - build netlink message header for nfacct subsystem
 * \param buf: buffer where this function outputs the netlink message.
 * \param cmd: nfacct nfnetlink command.
 * \param flags: netlink flags.
 * \param seq: sequence number for this message.
 *
 * Possible commands:
 * - NFNL_MSG_ACCT_NEW: new accounting object.
 * - NFNL_MSG_ACCT_GET: get accounting object.
 * - NFNL_MSG_ACCT_GET_CTRZERO: get accounting object and atomically reset.
 *
 * Examples:
 * - Command NFNL_MSG_ACCT_NEW + flags NLM_F_CREATE | NLM_F_ACK, to create
 *   one new accounting object (if it does not already exists). You receive
 *   one acknoledgment in any case with the result of the operation.
 *
 * - Command NFNL_MSG_ACCT_GET + flags NLM_F_DUMP, to obtain all the
 *   existing accounting objects.
 *
 * - Command NFNL_MSG_ACCT_GET_CTRZERO + flags NLM_F_DUMP, to atomically
 *   obtain all the existing accounting objects and reset them.
 *
 * - Command NFNL_MSG_ACCT_DEL, to delete all existing unused objects.
 *
 * - Command NFNL_MSG_ACCT_DEL, to delete one specific nfacct object (if
 *   unused, otherwise you hit EBUSY).
 */
struct nlmsghdr *
nfacct_nlmsg_build_hdr(char *buf, uint8_t cmd, uint16_t flags, uint32_t seq)
{
	struct nlmsghdr *nlh;
	struct nfgenmsg *nfh;

	nlh = mnl_nlmsg_put_header(buf);
	nlh->nlmsg_type = (NFNL_SUBSYS_ACCT << 8) | cmd;
	nlh->nlmsg_flags = NLM_F_REQUEST | flags;
	nlh->nlmsg_seq = seq;

	nfh = mnl_nlmsg_put_extra_header(nlh, sizeof(struct nfgenmsg));
	nfh->nfgen_family = AF_UNSPEC;
	nfh->version = NFNETLINK_V0;
	nfh->res_id = 0;

	return nlh;
}
EXPORT_SYMBOL(nfacct_nlmsg_build_hdr);

/**
 * nfacct_nlmsg_build_payload - build payload from accounting object
 * \param nlh: netlink message that you want to use to add the payload.
 * \param nfacct: pointer to a accounting object
 */
void nfacct_nlmsg_build_payload(struct nlmsghdr *nlh, struct nfacct *nfacct)
{
	if (nfacct->bitset & (1 << NFACCT_ATTR_NAME))
		mnl_attr_put_strz(nlh, NFACCT_NAME, nfacct->name);

	if (nfacct->bitset & (1 << NFACCT_ATTR_PKTS))
		mnl_attr_put_u64(nlh, NFACCT_PKTS, htobe64(nfacct->pkts));

	if (nfacct->bitset & (1 << NFACCT_ATTR_BYTES))
		mnl_attr_put_u64(nlh, NFACCT_BYTES, htobe64(nfacct->bytes));
}
EXPORT_SYMBOL(nfacct_nlmsg_build_payload);

static int nfacct_nlmsg_parse_attr_cb(const struct nlattr *attr, void *data)
{
	const struct nlattr **tb = data;
	int type = mnl_attr_get_type(attr);

	if (mnl_attr_type_valid(attr, NFACCT_MAX) < 0)
		return MNL_CB_OK;

	switch(type) {
	case NFACCT_NAME:
		if (mnl_attr_validate(attr, MNL_TYPE_STRING) < 0) {
			perror("mnl_attr_validate");
			return MNL_CB_ERROR;
		}
		break;
	case NFACCT_PKTS:
	case NFACCT_BYTES:
		if (mnl_attr_validate(attr, MNL_TYPE_U64) < 0) {
			perror("mnl_attr_validate");
			return MNL_CB_ERROR;
		}
		break;
	}
	tb[type] = attr;
	return MNL_CB_OK;
}

/**
 * nfacct_nlmsg_parse_payload - set accounting object attributes from message
 * \param nlh: netlink message that you want to use to add the payload.
 * \param nfacct: pointer to a accounting object
 *
 * This function returns -1 in case that some mandatory attributes are
 * missing. On sucess, it returns 0.
 */
int
nfacct_nlmsg_parse_payload(const struct nlmsghdr *nlh, struct nfacct *nfacct)
{
	struct nlattr *tb[NFACCT_MAX+1] = {};
	struct nfgenmsg *nfg = mnl_nlmsg_get_payload(nlh);

	mnl_attr_parse(nlh, sizeof(*nfg), nfacct_nlmsg_parse_attr_cb, tb);
	if (!tb[NFACCT_NAME] && !tb[NFACCT_PKTS] && !tb[NFACCT_BYTES])
		return -1;

	nfacct_attr_set_str(nfacct, NFACCT_ATTR_NAME,
			    mnl_attr_get_str(tb[NFACCT_NAME]));
	nfacct_attr_set_u64(nfacct, NFACCT_ATTR_PKTS,
			    be64toh(mnl_attr_get_u64(tb[NFACCT_PKTS])));
	nfacct_attr_set_u64(nfacct, NFACCT_ATTR_BYTES,
			    be64toh(mnl_attr_get_u64(tb[NFACCT_BYTES])));

	return 0;
}
EXPORT_SYMBOL(nfacct_nlmsg_parse_payload);

/**
 * @}
 */
