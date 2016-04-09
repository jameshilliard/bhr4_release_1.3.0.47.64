/*
 * Copyright (C) 2003-2004  Narcis Ilisei
 * Copyright (C) 2006  Steve Horbachuk
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

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#include "os.h"
#include "debug_if.h"

#define MAXSTRING 1024

/**
    The dbg destination.
    DBG_SYS_LOG for SysLog
    DBG_STD_LOG for standard console
*/
static int global_mod_dbg_dest = DBG_STD_LOG;
/**
    Returns the dbg destination.
    DBG_SYS_LOG for SysLog
    DBG_STD_LOG for standard console
*/
int get_dbg_dest(void)
{
	return global_mod_dbg_dest;
}

void set_dbg_dest(int dest)
{
	global_mod_dbg_dest = dest;
}

static char *current_time(void)
{
	time_t now;
	struct tm *timeptr;
	static const char wday_name[7][3] = {
		"Sun", "Mon", "Tue", "Wed",
		"Thu", "Fri", "Sat"
	};
	static const char mon_name[12][3] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	static char result[26];

	time(&now);
	timeptr = localtime(&now);

	sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d:",
		wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
		timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec, 1900 + timeptr->tm_year);

	return result;
}

void os_printf(int prio, char *fmt, ...)
{
	va_list args;
	static char message[MAXSTRING + 1];

	message[MAXSTRING] = 0;
	va_start(args, fmt);
	vsnprintf(message, sizeof(message), fmt, args);
	va_end(args);

	if (get_dbg_dest() == DBG_SYS_LOG) {
		syslog(prio, "%s", message);
		return;
	}

	printf("%s %s\n", current_time(), message);
	fflush(stdout);
}

/**
 * Opens the dbg output for the required destination.
 *
 * WARNING : Open and Close bg output are quite error prone!
 * They should be called din pairs!
 * TODO:
 *  some simple solution that involves storing the dbg output device name (and filename)
 */
int os_open_dbg_output(int dest, const char *name, const char *logfile)
{
	int rc = 0;
	FILE *pF;

	set_dbg_dest(dest);

	switch (get_dbg_dest()) {
	case DBG_SYS_LOG:
		if (name == NULL) {
			rc = RC_INVALID_POINTER;
			break;
		}
		rc = os_syslog_open(name);
		break;

	case DBG_FILE_LOG:
		if (logfile == NULL) {
			rc = RC_INVALID_POINTER;
			break;
		}

		pF = freopen(logfile, "ab", stdout);
		if (pF == NULL)
			rc = RC_FILE_IO_OPEN_ERROR;
		break;

	case DBG_STD_LOG:
	default:
		rc = 0;
	}

	return rc;
}

/**
 * Closes the dbg output device.
 */
int os_close_dbg_output(void)
{
	int rc = 0;

	switch (get_dbg_dest()) {
	case DBG_SYS_LOG:
		rc = os_syslog_close();
		break;

	case DBG_FILE_LOG:
		fclose(stdout);
		rc = 0;
		break;

	case DBG_STD_LOG:
	default:
		rc = 0;
	}

	return rc;
}

/**
 * Local Variables:
 *  version-control: t
 *  indent-tabs-mode: t
 *  c-file-style: "linux"
 * End:
 */
