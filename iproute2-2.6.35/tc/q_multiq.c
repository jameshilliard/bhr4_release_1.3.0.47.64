/*
 * q_multiq.c		Multiqueue aware qdisc
 *
 * Copyright (c) 2008, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * Author: Alexander Duyck <alexander.h.duyck@intel.com>
 *
 * Original Authors:	PJ Waskiewicz, <peter.p.waskiewicz.jr@intel.com> (RR)
 * 			Alexey Kuznetsov, <kuznet@ms2.inr.ac.ru> (from PRIO)
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
	fprintf(stderr, "Usage: ... multiq [bands (1-8)] ");
	fprintf(stderr, "[burst (16-256)BYTES]  [rate BPS]\n");
	fprintf(stderr, "[min_buffer (0-8k)]  [max_buffer (0-8k)] ");
	fprintf(stderr, "[wred_mode (0-3)]  [wred_adj_range_idx (0-7)]\n");
}

static void explain1(char *arg)
{
	fprintf(stderr, "Illegal \"%s\"\n", arg);
}

static int multiq_parse_opt(struct qdisc_util *qu, int argc, char **argv,
			    struct nlmsghdr *n)
{
	struct tc_multiq_qopt opt;
	struct rtattr *tail;

	memset(&opt, 0, sizeof(opt));
	opt.rate.rate = TCQ_MULTIQ_NOT_SET32;
	opt.burst_size = TCQ_MULTIQ_NOT_SET32;
	opt.min_global_buffer = TCQ_MULTIQ_NOT_SET16;
	opt.max_global_buffer = TCQ_MULTIQ_NOT_SET16;
	opt.wred_mode = TCQ_MULTIQ_NOT_SET8;
	opt.wred_adj_range_idx = TCQ_MULTIQ_NOT_SET8;

	while (argc > 0) {
		if (matches(*argv, "bands") == 0) {
			NEXT_ARG();
			if (get_u16(&opt.bands, *argv, 10)) {
				explain1("bands");
				return -1;
			}
		} else if (matches(*argv, "burst") == 0) {
			NEXT_ARG();
			if (get_size(&opt.burst_size, *argv)) {
				explain1("burst");
				return -1;
			}
			/* burst size is in the range of 16 to 256 */
			if ((opt.burst_size < 16) || (opt.burst_size > 256)) {
				fprintf(stderr, "\"burst\" out of range\n");
				return -1;
			}
		} else if (matches(*argv, "rate") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET32 != opt.rate.rate) {
				fprintf(stderr, "Double \"rate\" spec\n");
				return -1;
			}
			if (get_rate(&opt.rate.rate, *argv)) {
				explain1("rate");
				return -1;
			}
		} else if (matches(*argv, "min_buffer") == 0) {
			NEXT_ARG();
			if (get_u16(&opt.min_global_buffer, *argv, 10)) {
				explain1("min_buffer");
				return -1;
			}
		} else if (matches(*argv, "max_buffer") == 0) {
			NEXT_ARG();
			if (get_u16(&opt.max_global_buffer, *argv, 10)) {
				explain1("max_buffer");
				return -1;
			}
		} else if (matches(*argv, "wred_mode") == 0) {
			NEXT_ARG();
			if (get_u8(&opt.wred_mode, *argv, 10)) {
				explain1("wred_mode");
				return -1;
			}
		} else if (matches(*argv, "wred_adj_range_idx") == 0) {
			NEXT_ARG();
			if (get_u16(&opt.wred_adj_range_idx, *argv, 10)) {
				explain1("wred_adj_range_idx");
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

	tail = NLMSG_TAIL(n);
	addattr_l(n, 1024, TCA_OPTIONS, NULL, 0);
	addattr_l(n, 2024, TCA_MULTIQ_PARMS, &opt, sizeof(opt));
	tail->rta_len = (void *) NLMSG_TAIL(n) - (void *) tail;
	return 0;
}

int multiq_print_opt(struct qdisc_util *qu, FILE *f, struct rtattr *opt)
{
	struct rtattr *tb[TCA_MULTIQ_MAX + 1];
	struct tc_multiq_qopt *qopt;
	SPRINT_BUF(b1);

	if (opt == NULL)
		return 0;

	parse_rtattr_nested(tb, TCA_MULTIQ_MAX, opt);

	if (tb[TCA_MULTIQ_PARMS] == NULL) return -1;

	qopt = RTA_DATA(tb[TCA_MULTIQ_PARMS]);
	if (RTA_PAYLOAD(tb[TCA_MULTIQ_PARMS]) < sizeof(*qopt)) return -1;

	fprintf(f, "bands %u/%u ", qopt->bands, qopt->max_bands);
	if (qopt->burst_size != 0)
		fprintf(f, "burst %s ", sprint_size(qopt->burst_size, b1));
	if (qopt->rate.rate != 0)
		fprintf(f, "rate %s ", sprint_rate(qopt->rate.rate, b1));
	if ((qopt->min_global_buffer != 0) || (qopt->max_global_buffer != 0)) {
		fprintf(f, "min_buffer %u ", qopt->min_global_buffer);
		fprintf(f, "max_buffer %u ", qopt->max_global_buffer);
	}
	fprintf(f, "wred_mode %u wred_adj_range_idx %u", qopt->wred_mode,
			qopt->wred_adj_range_idx);

	return 0;
}

struct qdisc_util multiq_qdisc_util = {
	.id	 	= "multiq",
	.parse_qopt	= multiq_parse_opt,
	.print_qopt	= multiq_print_opt,
};

/* multisubq section */

static void explain_subs(void)
{
	fprintf(stderr, "Usage: ... multisubq [limit U32] [min U32] ");
	fprintf(stderr, "[prio 0-7 weight BYTES] [rate BPS] \n");
	fprintf(stderr, "[wred_enbl 0-1 min_pct_base 0-100 ");
	fprintf(stderr, "max_pct_base 0-100 drop_prob 0-100 ");
	fprintf(stderr, "[lp_filter_const 0-15] ] [min_pct_buffer 0-100 ");
	fprintf(stderr, "max_pct_buffer 0-100]] \n");
}

static int multisubq_parse_opt(struct qdisc_util *qu, int argc, char **argv,
			    struct nlmsghdr *n)
{
	struct tc_multisubq_qopt opt;
	struct rtattr *tail;

	/* initialize the value to NOT_SET for some of the parameters */
	memset(&opt, 0, sizeof(opt));
	opt.limit = TCQ_MULTIQ_NOT_SET32;
	opt.rsrv_depth = TCQ_MULTIQ_NOT_SET32;
	opt.weight = TCQ_MULTIQ_NOT_SET32;
	opt.priority = TCQ_MULTIQ_NOT_SET8;
	opt.rate.rate = TCQ_MULTIQ_NOT_SET32;
	opt.wred.min_pct_base = TCQ_MULTIQ_NOT_SET8;
	opt.wred.max_pct_base = TCQ_MULTIQ_NOT_SET8;
	opt.wred.min_pct_buffer = TCQ_MULTIQ_NOT_SET8;
	opt.wred.max_pct_buffer = TCQ_MULTIQ_NOT_SET8;
	opt.wred.drop_prob = TCQ_MULTIQ_NOT_SET8;
	opt.wred.aqd_lp_filter_const = TCQ_MULTIQ_NOT_SET8;
	opt.wred.enbl = TCQ_MULTIQ_NOT_SET8;

	while (argc > 0) {
		if (matches(*argv, "limit") == 0) {
			NEXT_ARG();
			if (get_u32(&opt.limit, *argv, 10)) {
				explain1("limit");
				return -1;
			}
		} else if (matches(*argv, "min") == 0) {
			NEXT_ARG();
			if (get_u32(&opt.rsrv_depth, *argv, 10)) {
				explain1("min");
				return -1;
			}
		} else if (matches(*argv, "weight") == 0) {
			NEXT_ARG();
			if (get_size(&opt.weight, *argv)) {
				explain1("weight");
				return -1;
			}
			/* when running in SP mode, weight is ignored */
			if ((opt.priority != 0) && 
					(opt.priority != TCQ_MULTIQ_NOT_SET8))
				opt.weight = TCQ_MULTIQ_NOT_SET32;
		} else if (matches(*argv, "prio") == 0) {
			NEXT_ARG();
			if (get_u8(&opt.priority, *argv, 10)) {
				explain1("prio");
				return -1;
			}
			/* when running in SP mode, weight is ignored */
			if (opt.priority != 0)
				opt.weight = TCQ_MULTIQ_NOT_SET32;
			if (opt.priority > 7) {
				explain1("prio");
				return -1;
			}
		} else if (matches(*argv, "rate") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET32 != opt.rate.rate) {
				fprintf(stderr, "Double \"rate\" spec\n");
				return -1;
			}
			if (get_rate(&opt.rate.rate, *argv)) {
				explain1("rate");
				return -1;
			}
		} else if (matches(*argv, "min_pct_base") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.min_pct_base) {
				fprintf(stderr, "Double \"min_pct_base\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.min_pct_base, *argv, 10)) {
				explain1("min_pct_base");
				return -1;
			}
			if (opt.wred.min_pct_base > 100) {
				explain1("min_pct_base");
				return -1;
			}
		} else if (matches(*argv, "max_pct_base") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.max_pct_base) {
				fprintf(stderr, "Double \"max_pct_base\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.max_pct_base, *argv, 10)) {
				explain1("max_pct_base");
				return -1;
			}
			if (opt.wred.max_pct_base > 100) {
				explain1("max_pct_base");
				return -1;
			}
		} else if (matches(*argv, "min_pct_buffer") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.min_pct_buffer) {
				fprintf(stderr, "Double \"min_pct_buffer\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.min_pct_buffer, *argv, 10)) {
				explain1("min_pct_buffer");
				return -1;
			}
			if (opt.wred.min_pct_buffer > 100) {
				explain1("min_pct_buffer");
				return -1;
			}
		} else if (matches(*argv, "max_pct_buffer") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.max_pct_buffer) {
				fprintf(stderr, "Double \"max_pct_buffer\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.max_pct_buffer, *argv, 10)) {
				explain1("max_pct_buffer");
				return -1;
			}
			if (opt.wred.max_pct_buffer > 100) {
				explain1("max_pct_buffer");
				return -1;
			}
		} else if (matches(*argv, "drop_prob") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.drop_prob) {
				fprintf(stderr, "Double \"drop_prob\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.drop_prob, *argv, 10)) {
				explain1("drop_prob");
				return -1;
			}
			if (opt.wred.drop_prob > 100) {
				explain1("drop_prob");
				return -1;
			}
		} else if (matches(*argv, "lp_filter_const") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.aqd_lp_filter_const) {
				fprintf(stderr, "Double \"lp_filter_const\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.aqd_lp_filter_const, *argv, 10)) {
				explain1("lp_filter_const");
				return -1;
			}
			if (opt.wred.aqd_lp_filter_const > 15) {
				explain1("lp_filter_const");
				return -1;
			}
		} else if (matches(*argv, "wred_enbl") == 0) {
			NEXT_ARG();
			if (TCQ_MULTIQ_NOT_SET8 != opt.wred.enbl) {
				fprintf(stderr, "Double \"wred_enbl\" spec\n");
				return -1;
			}
			if (get_u8(&opt.wred.enbl, *argv, 10)) {
				explain1("wred_enbl");
				return -1;
			}
			if (opt.wred.enbl > 1) {
				explain1("wred_enbl");
				return -1;
			}
		} else if (strcmp(*argv, "help") == 0) {
			explain_subs();
			return -1;
		} else {
			fprintf(stderr, "What is \"%s\"?\n", *argv);
			explain_subs();
			return -1;
		}
		argc--; argv++;
	}

	if (1 == opt.wred.enbl) { 
		if ((TCQ_MULTIQ_NOT_SET8 == opt.wred.min_pct_base) || 
				(TCQ_MULTIQ_NOT_SET8 == opt.wred.max_pct_base) || 
				(TCQ_MULTIQ_NOT_SET8 == opt.wred.drop_prob)) {
			fprintf(stderr, "WRED is enabled with inefficient parameters! \n");
			return -1;
		}
		if (opt.wred.min_pct_base >= opt.wred.max_pct_base) {
			fprintf(stderr, "min_pct_base >= max_pct_base!!\n");
			return -1;
		}
		if (((TCQ_MULTIQ_NOT_SET8 != opt.wred.min_pct_buffer) || 
					(TCQ_MULTIQ_NOT_SET8 != opt.wred.max_pct_buffer)) && 
				((TCQ_MULTIQ_NOT_SET8 == opt.wred.min_pct_buffer) || 
				 	(TCQ_MULTIQ_NOT_SET8 == opt.wred.max_pct_buffer))) {
			fprintf(stderr, "only define 1 of the min/max pct of buffer\n");
			return -1;
		}
		if ((TCQ_MULTIQ_NOT_SET8 != opt.wred.min_pct_buffer) && 
				(TCQ_MULTIQ_NOT_SET8 != opt.wred.max_pct_buffer) && 
				(opt.wred.min_pct_buffer >= opt.wred.max_pct_buffer)) {
			fprintf(stderr, "min_pct_buffer >= max_pct_buffer!!\n");
			return -1;
		}
	}

	tail = NLMSG_TAIL(n);
	addattr_l(n, 1024, TCA_OPTIONS, NULL, 0);
	addattr_l(n, 2024, TCA_MULTISUBQ_PARMS, &opt, sizeof(opt));
	tail->rta_len = (void *) NLMSG_TAIL(n) - (void *) tail;
	return 0;
}

int multisubq_print_opt(struct qdisc_util *qu, FILE *f, struct rtattr *opt)
{
	struct rtattr *tb[TCA_MULTIQ_MAX + 1];
	struct tc_multisubq_qopt *qopt;
	SPRINT_BUF(b1);

	if (opt == NULL)
		return 0;

	parse_rtattr_nested(tb, TCA_MULTISUBQ_MAX, opt);

	if (tb[TCA_MULTISUBQ_PARMS] == NULL) return -1;

	qopt = RTA_DATA(tb[TCA_MULTISUBQ_PARMS]);
	if (RTA_PAYLOAD(tb[TCA_MULTISUBQ_PARMS]) < sizeof(*qopt)) return -1;

	fprintf(f, "prio %u ", qopt->priority);
	fprintf(f, "weight %s ", sprint_size(qopt->weight, b1));
	fprintf(f, "limit %u ", qopt->limit);
	if (0 != qopt->rsrv_depth)
		fprintf(f, "min %u ", qopt->rsrv_depth);
	if (qopt->rate.rate)
		fprintf(f, "rate %s ", sprint_rate(qopt->rate.rate, b1));
	if (0 != qopt->wred.enbl) {
		fprintf(f, "\n\tWRED enabled:  ");
		fprintf(f, "min_pct_base %u ", qopt->wred.min_pct_base);
		fprintf(f, "max_pct_base %u ", qopt->wred.max_pct_base);
		fprintf(f, "drop_prob %u ", qopt->wred.drop_prob);
		fprintf(f, "lp_filter_const %u ", qopt->wred.aqd_lp_filter_const);
		if ((TCQ_MULTIQ_NOT_SET8 != qopt->wred.min_pct_buffer) && 
				(TCQ_MULTIQ_NOT_SET8 != qopt->wred.max_pct_buffer)) {
			fprintf(f, "min_pct_buffer %u ", qopt->wred.min_pct_buffer);
			fprintf(f, "max_pct_buffer %u ", qopt->wred.max_pct_buffer);
		}
	} else fprintf(f, "WRED disabled ");

	return 0;
}

struct qdisc_util multisubq_qdisc_util = {
	.id	 	= "multisubq",
	.parse_qopt	= multisubq_parse_opt,
	.print_qopt	= multisubq_print_opt,
};
