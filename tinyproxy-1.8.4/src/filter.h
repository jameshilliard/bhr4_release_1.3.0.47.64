/* tinyproxy - A fast light-weight HTTP proxy
 * Copyright (C) 1999 George Talusan <gstalusan@uwaterloo.ca>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* See 'filter.c' for detailed information. */

#ifndef _TINYPROXY_FILTER_H_
#define _TINYPROXY_FILTER_H_

#define FILTER_ENABLE 1
#define CLIENT_IP_FILTER 1

typedef enum {
        FILTER_ALLOW,
        FILTER_DENY
} filter_policy_t;

extern void filter_init (void);
extern void filter_destroy (void);
extern void filter_reload (void);
#ifdef CLIENT_IP_FILTER
int filter_domain_url(const char *client_ip_addr, const char *host, const char * url);
#else
extern int filter_domain (const char *host);
extern int filter_url (const char *url);
#endif
extern void filter_set_default_policy (filter_policy_t policy);

#endif
