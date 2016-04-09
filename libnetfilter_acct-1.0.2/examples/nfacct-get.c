/* This example is in the public domain. */
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libmnl/libmnl.h>
#include <libnetfilter_acct/libnetfilter_acct.h>

static int nfacct_cb(const struct nlmsghdr *nlh, void *data)
{
	struct nfacct *nfacct;
	char buf[4096];

	nfacct = nfacct_alloc();
	if (nfacct == NULL) {
		perror("OOM");
		goto err;
	}

	if (nfacct_nlmsg_parse_payload(nlh, nfacct) < 0) {
		perror("nfacct_parse_nl_msg");
		goto err_free;
	}

	nfacct_snprintf(buf, sizeof(buf), nfacct,
			NFACCT_SNPRINTF_T_PLAIN, NFACCT_SNPRINTF_F_FULL);
	printf("%s\n", buf);

err_free:
	nfacct_free(nfacct);
err:
	return MNL_CB_OK;
}

int main(int argc, char *argv[])
{
	struct mnl_socket *nl;
	char buf[MNL_SOCKET_BUFFER_SIZE];
	struct nlmsghdr *nlh;
	uint32_t portid, seq;
	int ret, full = 1;
	bool zeroctr = false;

	if (argc > 2) {
		fprintf(stderr, "Usage: %s [-z]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (argc == 2 && strncmp(argv[1], "-z", strlen("-z")) == 0)
		zeroctr = true;

	seq = time(NULL);
	nlh = nfacct_nlmsg_build_hdr(buf, zeroctr ?
					NFNL_MSG_ACCT_GET_CTRZERO :
					NFNL_MSG_ACCT_GET,
				     NLM_F_DUMP, seq);

	nl = mnl_socket_open(NETLINK_NETFILTER);
	if (nl == NULL) {
		perror("mnl_socket_open");
		exit(EXIT_FAILURE);
	}

	if (mnl_socket_bind(nl, 0, MNL_SOCKET_AUTOPID) < 0) {
		perror("mnl_socket_bind");
		exit(EXIT_FAILURE);
	}
	portid = mnl_socket_get_portid(nl);

	if (mnl_socket_sendto(nl, nlh, nlh->nlmsg_len) < 0) {
		perror("mnl_socket_send");
		exit(EXIT_FAILURE);
	}

	ret = mnl_socket_recvfrom(nl, buf, sizeof(buf));
	while (ret > 0) {
		ret = mnl_cb_run(buf, ret, seq, portid, nfacct_cb, &full);
		if (ret <= 0)
			break;
		ret = mnl_socket_recvfrom(nl, buf, sizeof(buf));
	}
	if (ret == -1) {
		perror("error");
		exit(EXIT_FAILURE);
	}
	mnl_socket_close(nl);

	return EXIT_SUCCESS;
}
