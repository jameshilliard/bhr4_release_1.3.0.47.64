/* tinyproxy - A fast light-weight HTTP proxy
 * Copyright (C) 2001 Robert James Kaes <rjkaes@users.sourceforge.net>
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

/* See 'conns.c' for detailed information. */

#ifndef TINYPROXY_CONNS_H
#define TINYPROXY_CONNS_H

#include "main.h"
#include "hashmap.h"

/*
 * Connection Definition
 */
struct conn_s {
        int client_fd;
        int server_fd;

        struct buffer_s *cbuffer;
        struct buffer_s *sbuffer;

        /* The request line (first line) from the client */
        char *request_line;

        /* Booleans */
        unsigned int connect_method;
        unsigned int show_stats;

        /*
         * This structure stores key -> value mappings for substitution
         * in the error HTML files.
         */
        hashmap_t error_variables;

        int error_number;
        char *error_string;

        /* A Content-Length value from the remote server */
        struct {
                long int server;
                long int client;
        } content_length;

        /*
         * Store the server's IP (for BindSame)
         */
        char *server_ip_addr;

        /*
         * Store the client's IP and hostname information
         */
        char *client_ip_addr;
        char *client_string_addr;

        /*
         * Store the incoming request's HTTP protocol.
         */
        struct {
                unsigned int major;
                unsigned int minor;
        } protocol;

#ifdef REVERSE_SUPPORT
        /*
         * Place to store the current per-connection reverse proxy path
         */
        char *reversepath;
#endif

        /*
         * Pointer to upstream proxy.
         */
        struct upstream *upstream_proxy;
};

/*
 * Functions for the creation and destruction of a connection structure.
 */
extern struct conn_s *initialize_conn (int client_fd, const char *ipaddr,
                                       const char *string_addr,
                                       const char *sock_ipaddr);
extern void destroy_conn (struct conn_s *connptr);

#endif
