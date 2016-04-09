/* tinyproxy - A fast light-weight HTTP proxy
 * Copyright (C) 2004 Robert James Kaes <rjkaes@users.sourceforge.net>
 * Copyright (C) 2009 Michael Adam <obnox@samba.org>
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

/* See 'conf.c' for detailed information. */

#ifndef TINYPROXY_CONF_H
#define TINYPROXY_CONF_H

#define FILTER_ENABLE 1

#include "hashmap.h"
#include "vector.h"

/*
 * Stores a HTTP header created using the AddHeader directive.
 */
typedef struct {
        char *name;
        char *value;
} http_header_t;

/*
 * Hold all the configuration time information.
 */
struct config_s {
        char *logf_name;
        char *config_file;
        unsigned int syslog;    /* boolean */
        unsigned int port;
        char *stathost;
        unsigned int godaemon;  /* boolean */
        unsigned int quit;      /* boolean */
        char *user;
        char *group;
        vector_t listen_addrs;
#ifdef FILTER_ENABLE
        char *filter;
        unsigned int filter_url;        /* boolean */
        unsigned int filter_extended;   /* boolean */
        unsigned int filter_casesensitive;      /* boolean */
#endif                          /* FILTER_ENABLE */
#ifdef XTINYPROXY_ENABLE
        unsigned int add_xtinyproxy; /* boolean */
#endif
#ifdef REVERSE_SUPPORT
        struct reversepath *reversepath_list;
        unsigned int reverseonly;       /* boolean */
        unsigned int reversemagic;      /* boolean */
        char *reversebaseurl;
#endif
#ifdef UPSTREAM_SUPPORT
        struct upstream *upstream_list;
#endif                          /* UPSTREAM_SUPPORT */
        unsigned int wallgarden;  /* boolean */
        char *pidpath;
        unsigned int idletimeout;
        char *bind_address;
        unsigned int bindsame;

        /*
         * The configured name to use in the HTTP "Via" header field.
         */
        char *via_proxy_name;

        unsigned int disable_viaheader; /* boolean */

        /*
         * Error page support.  Map error numbers to file paths.
         */
        hashmap_t errorpages;

        /*
         * Error page to be displayed if appropriate page cannot be located
         * in the errorpages structure.
         */
        char *errorpage_undef;

        /*
         * The HTML statistics page.
         */
        char *statpage;

        vector_t access_list;

        /*
         * Store the list of port allowed by CONNECT.
         */
        vector_t connect_ports;

        /*
         * Map of headers which should be let through when the
         * anonymous feature is turned on.
         */
        hashmap_t anonymous_map;

        /*
         * Extra headers to be added to outgoing HTTP requests.
         */
        vector_t add_headers;
};

extern int reload_config_file (const char *config_fname, struct config_s *conf,
                               struct config_s *defaults);

int config_compile_regex (void);

#endif
