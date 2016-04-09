/*
 * Copyright (C) 2009 Kay Sievers <kay.sievers@vrfy.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details:
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include <sys/stat.h>
#include <glib.h>
#include <acl/libacl.h>
#include <libudev.h>

static int debug;

static int set_facl(const char* filename, uid_t uid, int add)
{
	int get;
	acl_t acl;
	acl_entry_t entry = NULL;
	acl_entry_t e;
	acl_permset_t permset;
	int ret;

	/* read current record */
	acl = acl_get_file(filename, ACL_TYPE_ACCESS);
	if (!acl)
		return -1;

	/* locate ACL_USER entry for uid */
	get = acl_get_entry(acl, ACL_FIRST_ENTRY, &e);
	while (get == 1) {
		acl_tag_t t;

		acl_get_tag_type(e, &t);
		if (t == ACL_USER) {
			uid_t *u;

			u = (uid_t*)acl_get_qualifier(e);
			if (u == NULL) {
				ret = -1;
				goto out;
			}
			if (*u == uid) {
				entry = e;
				acl_free(u);
				break;
			}
			acl_free(u);
		}

		get = acl_get_entry(acl, ACL_NEXT_ENTRY, &e);
	}

	/* remove ACL_USER entry for uid */
	if (!add) {
		if (entry == NULL) {
			ret = 0;
			goto out;
		}
		acl_delete_entry(acl, entry);
		goto update;
	}

	/* create ACL_USER entry for uid */
	if (entry == NULL) {
		ret = acl_create_entry(&acl, &entry);
		if (ret != 0)
			goto out;
		acl_set_tag_type(entry, ACL_USER);
		acl_set_qualifier(entry, &uid);
	}

	/* add permissions for uid */
	acl_get_permset(entry, &permset);
	acl_add_perm(permset, ACL_READ|ACL_WRITE);
update:
	/* update record */
	if (debug)
		printf("%c%u %s\n", add ? '+' : '-', uid, filename);
	acl_calc_mask(&acl);
	ret = acl_set_file(filename, ACL_TYPE_ACCESS, acl);
	if (ret != 0)
		goto out;
out:
	acl_free(acl);
	return ret;
}

/* check if a given uid is listed */
static int uid_in_list(GSList *list, uid_t uid)
{
	GSList *l;

	for (l = list; l != NULL; l = g_slist_next(l))
		if (uid == GPOINTER_TO_UINT(l->data))
			return 1;
	return 0;
}

/* return list of current uids of local active sessions */
static GSList *uids_with_local_active_session(const char *own_id)
{
	GSList *list = NULL;
	GKeyFile *keyfile;

	keyfile = g_key_file_new();
	if (g_key_file_load_from_file(keyfile, "/var/run/ConsoleKit/database", 0, NULL)) {
		gchar **groups;

		groups = g_key_file_get_groups(keyfile, NULL);
		if (groups != NULL) {
			int i;

			for (i = 0; groups[i] != NULL; i++) {
				uid_t u;

				if (!g_str_has_prefix(groups[i], "Session "))
					continue;
				if (own_id != NULL &&g_str_has_suffix(groups[i], own_id))
					continue;
				if (!g_key_file_get_boolean(keyfile, groups[i], "is_local", NULL))
					continue;
				if (!g_key_file_get_boolean(keyfile, groups[i], "is_active", NULL))
					continue;
				u = g_key_file_get_integer(keyfile, groups[i], "uid", NULL);
				if (u > 0 && !uid_in_list(list, u))
					list = g_slist_prepend(list, GUINT_TO_POINTER(u));
			}
			g_strfreev(groups);
		}
	}
	g_key_file_free(keyfile);

	return list;
}

/* ConsoleKit calls us with special variables */
static int consolekit_called(const char *action, uid_t *uid, const char **own_session, int *add)
{
	int a;
	uid_t u;
	const char *s;
	const char *session;

	if (action == NULL || strcmp(action, "session_active_changed") != 0)
		return -1;

	s = getenv("CK_SESSION_IS_LOCAL");
	if (s == NULL)
		return -1;
	if (strcmp(s, "true") != 0)
		return 0;

	s = getenv("CK_SESSION_IS_ACTIVE");
	if (s == NULL)
		return -1;
	if (strcmp(s, "true") == 0)
		a = 1;
	else
		a = 0;

	session = getenv("CK_SESSION_ID");
	if (session == NULL)
		return -1;

	s = getenv("CK_SESSION_USER_UID");
	if (s == NULL)
		return -1;
	u = strtoul(s, NULL, 10);
	if (u == 0)
		return 0;

	*own_session = session;
	*uid = u;
	*add = a;
	return 0;
}

/* add or remove a ACL for a given uid from all matching devices */
static void apply_acl_to_devices(uid_t uid, int add)
{
	struct udev *udev;
	struct udev_enumerate *enumerate;
	struct udev_list_entry *list_entry;

	/* iterate over all devices tagged with ACL_SET */
	udev = udev_new();
	enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_property(enumerate, "ACL_MANAGE", "*");
	udev_enumerate_scan_devices(enumerate);
	udev_list_entry_foreach(list_entry, udev_enumerate_get_list_entry(enumerate)) {
		struct udev_device *device;
		const char *node;

		device = udev_device_new_from_syspath(udev_enumerate_get_udev(enumerate),
						      udev_list_entry_get_name(list_entry));
		if (device == NULL)
			continue;
		node = udev_device_get_devnode(device);
		if (node == NULL)
			continue;
		set_facl(node, uid, add);
		udev_device_unref(device);
	}
	udev_enumerate_unref(enumerate);
	udev_unref(udev);
}

int main (int argc, char* argv[])
{
	static const struct option options[] = {
		{ "action", required_argument, NULL, 'a' },
		{ "device", required_argument, NULL, 'D' },
		{ "user", required_argument, NULL, 'u' },
		{ "debug", no_argument, NULL, 'd' },
		{ "help", no_argument, NULL, 'h' },
		{}
	};
	int add = -1;
	const char *device = NULL;
	uid_t uid = 0;
	const char* own_session = NULL;
	int rc = 0;

	/* valgrind is more important to us than a slice allocator */
	g_slice_set_config (G_SLICE_CONFIG_ALWAYS_MALLOC, 1);

	while (1) {
		int option;

		option = getopt_long(argc, argv, "+a:D:u:dh", options, NULL);
		if (option == -1)
			break;

		switch (option) {
		case 'a':
			if (strcmp(optarg, "add") == 0 || strcmp(optarg, "change") == 0)
				add = 1;
			else if (strcmp(optarg, "remove") == 0)
				add = 0;
			else
				goto out;
			break;
		case 'D':
			device = optarg;
			break;
		case 'u':
			uid = strtoul(optarg, NULL, 10);
			break;
		case 'd':
			debug = 1;
			break;
		case 'h':
			printf("Usage: udev-acl --action=ACTION [--device=DEVICEFILE] [--user=UID]\n\n");
		default:
			goto out;
		}
	}

	if (add < 0 && device == NULL && uid == 0)
		consolekit_called(argv[optind], &uid, &own_session, &add);

	if (add < 0) {
		fprintf(stderr, "missing action\n\n");
		rc = 2;
		goto out;
	}

	if (device != NULL && uid != 0) {
		fprintf(stderr, "only one option, --device=DEVICEFILE or --user=UID expected\n\n");
		rc = 3;
		goto out;
	}

	if (uid != 0) {
		if (add) {
			/* Add ACL for given uid to all matching devices. */
			apply_acl_to_devices(uid, 1);
		} else {
			/*
			 * Remove ACL for given uid from all matching devices
			 * when there is currently no local active session.
			 */
			GSList *list;

			list = uids_with_local_active_session(own_session);
			if (!uid_in_list(list, uid))
				apply_acl_to_devices(uid, 0);
			g_slist_free(list);
		}
	} else if (device != NULL) {
		/*
		 * Add ACLs for all current session uids to a given device.
		 *
		 * Or remove ACLs for uids which do not have any current local
		 * active session. Remove is not really interesting, because in
		 * most cases the device node is removed anyway.
		 */
		GSList *list;
		GSList *l;

		list = uids_with_local_active_session(NULL);
		for (l = list; l != NULL; l = g_slist_next(l)) {
			uid_t u;

			u = GPOINTER_TO_UINT(l->data);
			if (add || !uid_in_list(list, u))
				set_facl(device, u, add);
		}
		g_slist_free(list);
	} else {
		fprintf(stderr, "--device=DEVICEFILE or --user=UID expected\n\n");
		rc = 3;
	}
out:
	return rc;
}
