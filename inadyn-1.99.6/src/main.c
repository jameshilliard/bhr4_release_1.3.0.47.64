/* Small cmd line program useful for maintaining an IP address in a Dynamic DNS system.
 *
 * Copyright (C) 2003-2004  Narcis Ilisei <inarcis2002@hotpop.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <stdlib.h>

#include "debug_if.h"
#include "dyndns.h"
#include "errorcode.h"

/**
   basic resource allocations for the dyn_dns object
*/
static int alloc_context(ddns_t **pctx)
{
	int rc = 0;
	ddns_t *ctx;
	int http_to_dyndns_constructed = 0;
	int http_to_ip_constructed = 0;
	int i;

	if (!pctx)
		return RC_INVALID_POINTER;

	*pctx = (ddns_t *)malloc(sizeof(ddns_t));
	if (!*pctx)
		return RC_OUT_OF_MEMORY;

	do {
		ctx = *pctx;
		memset(ctx, 0, sizeof(ddns_t));

		/* Alloc space for http_to_ip_server data */
		ctx->work_buflen = DYNDNS_HTTP_RESPONSE_BUFFER_SIZE;
		ctx->work_buf = (char *)malloc(ctx->work_buflen);
		if (!ctx->work_buf) {
			rc = RC_OUT_OF_MEMORY;
			break;
		}

		/* Alloc space for request data */
		ctx->request_buflen = DYNDNS_HTTP_REQUEST_BUFFER_SIZE;
		ctx->request_buf = (char *)malloc(ctx->request_buflen);
		if (!ctx->request_buf) {
			rc = RC_OUT_OF_MEMORY;
			break;
		}

		ctx->cmd = NO_CMD;
		ctx->startup_delay_sec = DYNDNS_DEFAULT_STARTUP_SLEEP;
		ctx->normal_update_period_sec = DYNDNS_DEFAULT_SLEEP;
		ctx->sleep_sec = DYNDNS_DEFAULT_SLEEP;
		ctx->total_iterations = DYNDNS_DEFAULT_ITERATIONS;
		ctx->cmd_check_period = DYNDNS_DEFAULT_CMD_CHECK_PERIOD;
		ctx->force_addr_update = 0;

		i = 0;
		while (i < DYNDNS_MAX_SERVER_NUMBER)
		{
			memcpy(ctx->info[i].protocol, "http", 4);
			ctx->info[i++].creds.encoded_password = NULL;
		}

		ctx->initialized = 0;
	}
	while (0);

	if (rc) {

		if (ctx->work_buf)
			free(ctx->work_buf);

		if (ctx->request_buf)
			free(ctx->work_buf);

		free(ctx);
		*pctx = NULL;
	}

	return 0;
}

static void free_context(ddns_t *ctx)
{
	int i;

	free(ctx->work_buf);
	ctx->work_buf = NULL;

	free(ctx->request_buf);
	ctx->request_buf = NULL;

	for (i = 0; i < DYNDNS_MAX_SERVER_NUMBER; i++) {
		ddns_info_t *info = &ctx->info[i];

		free(info->creds.encoded_password);
		info->creds.encoded_password = NULL;
	}

	free(ctx->cfgfile);
	ctx->cfgfile = NULL;

	free(ctx->pidfile);
	ctx->pidfile = NULL;

	free(ctx->external_command);
	ctx->external_command = NULL;

	free(ctx->bind_interface);
	ctx->bind_interface = NULL;

	free(ctx->check_interface);
	ctx->check_interface = NULL;

	free(ctx->cache_file);
	ctx->cache_file = NULL;

	free(ctx);
}

int main(int argc, char *argv[])
{
	int rc = 0, restart;
	ddns_t *ctx = NULL;

	do {
		restart = 0;

		rc = alloc_context(&ctx);
		if (rc == RC_OK) {
			DO(os_install_signal_handler(ctx));

			rc = ddns_main_loop(ctx, argc, argv);
			if (rc == RC_RESTART)
				restart = 1;

			free_context(ctx);
		}
	} while (restart);

	os_close_dbg_output();

	return rc;
}

/**
 * Local Variables:
 *  version-control: t
 *  indent-tabs-mode: t
 *  c-file-style: "linux"
 * End:
 */
