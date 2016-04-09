#ifndef _LIBNETFILTER_ACCT_H_
#define _LIBNETFILTER_ACCT_H_

#include <sys/types.h>
#include <stdint.h>
#include <linux/netfilter/nfnetlink_acct.h>

struct nfacct;

enum nfacct_attr_type {
	NFACCT_ATTR_NAME = 0,
	NFACCT_ATTR_PKTS,
	NFACCT_ATTR_BYTES,
};

struct nfacct *nfacct_alloc(void);
void nfacct_free(struct nfacct *nfacct);

void nfacct_attr_set(struct nfacct *nfacct, enum nfacct_attr_type type, const void *data);
void nfacct_attr_set_str(struct nfacct *nfacct, enum nfacct_attr_type type, const char *name);
void nfacct_attr_set_u64(struct nfacct *nfacct, enum nfacct_attr_type type, uint64_t value);
void nfacct_attr_unset(struct nfacct *nfacct, enum nfacct_attr_type type);

const void *nfacct_attr_get(struct nfacct *nfacct, enum nfacct_attr_type type);
const char *nfacct_attr_get_str(struct nfacct *nfacct, enum nfacct_attr_type type);
uint64_t nfacct_attr_get_u64(struct nfacct *nfacct, enum nfacct_attr_type type);

struct nlmsghdr;

struct nlmsghdr *nfacct_nlmsg_build_hdr(char *buf, uint8_t cmd, uint16_t flags, uint32_t seq);
void nfacct_nlmsg_build_payload(struct nlmsghdr *nlh, struct nfacct *nfacct);
int nfacct_nlmsg_parse_payload(const struct nlmsghdr *nlh, struct nfacct *nfacct);

#define NFACCT_SNPRINTF_F_FULL		(1 << 0)
#define NFACCT_SNPRINTF_F_TIME		(1 << 1)

#define NFACCT_SNPRINTF_T_PLAIN 0
#define NFACCT_SNPRINTF_T_XML 1

int nfacct_snprintf(char *buf, size_t size, struct nfacct *nfacct, uint16_t type, uint16_t flags);

#endif
