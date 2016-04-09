/*
 *
 * q_ingress.c             INGRESS.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 *
 * Authors:    J Hadi Salim
 *
 * This is here just in case it is needed
 * useless right now; might be useful in the future
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "utils.h"
#include "tc_util.h"

static void explain(void)
{
	fprintf(stderr, "Usage: ... ingress [rate_enbl (0-1) rate BPS ");
	fprintf(stderr, "cbs (128-1M)BYTES pbs (128-1M)BYTES ");
	fprintf(stderr, "[bypass_yellow (0-1)] [bypass_red (0-1)]\n");
}

static void explain1(char *arg)
{
	fprintf(stderr, "Illegal \"%s\"\n", arg);
}

static int ingress_parse_opt(struct qdisc_util *qu, int argc, char **argv, struct nlmsghdr *n)
{
	struct tc_ingress_qopt opt;
	struct rtattr *tail;

	/* initialize the opt data structure with all 1's */
	memset(&opt, 0xff, sizeof(opt));

	while (argc > 0) {
		if (strcmp(*argv, "handle") == 0) {
			NEXT_ARG();
		} else if (strcmp(*argv, "rate_enbl") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET8 != opt.rate_enbl) {
				fprintf(stderr, "Double \"rate_enbl\" spec\n");
				return -1;
			}
			if (get_u8(&opt.rate_enbl, *argv, 10)) {
				explain1("rate_enbl");
				return -1;
			}
			if ((0 != opt.rate_enbl) && (1 != opt.rate_enbl)) {
				explain1("rate_enbl");
				return -1;
			}
		} else if (strcmp(*argv, "rate") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET32 != opt.rate.rate) {
				fprintf(stderr, "Double \"rate\" spec\n");
				return -1;
			}
			if (get_rate(&opt.rate.rate, *argv)) {
				explain1("rate");
				return -1;
			}
		} else if (strcmp(*argv, "cbs") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET32 != opt.cbs) {
				fprintf(stderr, "Double \"cbs\" spec\n");
				return -1;
			}
			if (get_size(&opt.cbs, *argv)) {
				explain1("cbs");
				return -1;
			}
		} else if (strcmp(*argv, "pbs") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET32 != opt.pbs) {
				fprintf(stderr, "Double \"pbs\" spec\n");
				return -1;
			}
			if (get_size(&opt.pbs, *argv)) {
				explain1("pbs");
				return -1;
			}
		} else if (strcmp(*argv, "bypass_yellow") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET8 != opt.bypass_yellow) {
				fprintf(stderr, "Double \"bypass_yellow\" spec\n");
				return -1;
			}
			if (get_u8(&opt.bypass_yellow, *argv, 10)) {
				explain1("bypass_yellow");
				return -1;
			}
			if ((0 != opt.bypass_yellow) && (1 != opt.bypass_yellow)) {
				explain1("bypass_yellow");
				return -1;
			}
		} else if (strcmp(*argv, "bypass_red") == 0) {
			NEXT_ARG();
			if (TCQ_INGRESS_NOT_SET8 != opt.bypass_red) {
				fprintf(stderr, "Double \"bypass_red\" spec\n");
				return -1;
			}
			if (get_u8(&opt.bypass_red, *argv, 10)) {
				explain1("bypass_red");
				return -1;
			}
			if ((0 != opt.bypass_red) && (1 != opt.bypass_red)) {
				explain1("bypass_red");
				return -1;
			}
		} else if (strcmp(*argv, "help") == 0) {
			explain();
			return -1;
		} else {
			fprintf(stderr, "What is \"%s\"?\n", *argv);
			explain();
			return -1;
		}
		argc--; argv++;
	}

	if (1 == opt.rate_enbl) {
		/* when it's enabled the rate limit on top of the source port, 
		 * we need to make sure all the required parameters are given */
		if ((TCQ_INGRESS_NOT_SET32 == opt.rate.rate) || 
				(TCQ_INGRESS_NOT_SET32 == opt.cbs) || 
				(TCQ_INGRESS_NOT_SET32 == opt.pbs)) {
			fprintf(stderr, "Ingress rate limit is enabled with ");
			fprintf(stderr, "inefficient parameters!\n");
			return -1;
		}
		if (opt.cbs >= opt.pbs) {
			fprintf(stderr, "CBS should be less than PBS!\n");
			return -1;
		}
	}
	tail = NLMSG_TAIL(n);
	addattr_l(n, 1024, TCA_OPTIONS, NULL, 0);
	addattr_l(n, 2024, TCA_INGRESS_PARMS, &opt, sizeof(opt));
	tail->rta_len = (void *) NLMSG_TAIL(n) - (void *) tail;

	return 0;
}

static int ingress_print_opt(struct qdisc_util *qu, FILE *f, struct rtattr *opt)
{
	struct rtattr *tb[TCA_INGRESS_MAX + 1];
	struct tc_ingress_qopt *qopt;
	SPRINT_BUF(b1);

	if (opt == NULL) return 0;

	parse_rtattr_nested(tb, TCA_INGRESS_MAX, opt);

	if (tb[TCA_INGRESS_PARMS] == NULL) return -1;

	qopt = RTA_DATA(tb[TCA_INGRESS_PARMS]);
	if (RTA_PAYLOAD(tb[TCA_INGRESS_PARMS]) < sizeof(*qopt)) return -1;

	if (1 == qopt->rate_enbl) {
		fprintf(f, "Policing enabled: ");
		fprintf(f, "rate %s ", sprint_rate(qopt->rate.rate, b1));
		fprintf(f, "cbs %s ", sprint_size(qopt->cbs, b1));
		fprintf(f, "pbs %s ", sprint_size(qopt->pbs, b1));
		fprintf(f, "bypass_yellow %d ", qopt->bypass_yellow);
		fprintf(f, "bypass_red %d\n", qopt->bypass_red);
	} else fprintf(f, "Policing disabled. -- ");

	return 0;
}

struct qdisc_util ingress_qdisc_util = {
	.id		= "ingress",
	.parse_qopt	= ingress_parse_opt,
	.print_qopt	= ingress_print_opt,
};
