#include <common.h>
#include <cli.h>
#include <command.h>
#include <environment.h>
#include <errno.h>
#include <malloc.h>
#include <nand.h>
#include <search.h>
#include <watchdog.h>
#include <linux/stddef.h>
#include <asm/arch/register.h>
#include <asm/byteorder.h>
#include <asm/io.h>

#define CONFIG_ALT_ENV_OFFSET 0x100000
#define CONFIG_ALT_ENV_OFFSET_REDUND 0x180000
#define CONFIG_ALT_ENV_MAX_ENTRIES 1000

struct env_location {
	const char* name;
	nand_erase_options_t erase_opts;
};

static int altenv_initialized = 0;
static int altenv_valid = 0;
static int altenv_flags = 0;
static int altenv_id = 0;
static struct hsearch_data altenv_htab;

extern int readenv(size_t offset, u_char* buf);

static int altenv_init(void)
{
	int read1_fail = 0, read2_fail = 0;
	int crc1_ok = 0, crc2_ok = 0;
	env_t* ep, *tmp_env1, *tmp_env2;

	if (hcreate_r(CONFIG_ALT_ENV_MAX_ENTRIES, &altenv_htab) == 0) {
		puts("Failed to create hash table");
		return 0;
	}

	tmp_env1 = (env_t*)malloc(CONFIG_ENV_SIZE);
	tmp_env2 = (env_t*)malloc(CONFIG_ENV_SIZE);
	if (tmp_env1 == NULL || tmp_env2 == NULL) {
		puts("Can't allocate buffers for environment\n");
		//		set_default_env("!malloc() failed");
		goto done;
	}

	read1_fail = readenv(CONFIG_ALT_ENV_OFFSET, (u_char*)tmp_env1);
	read2_fail = readenv(CONFIG_ALT_ENV_OFFSET_REDUND, (u_char*)tmp_env2);

	if (read1_fail && read2_fail)
		puts("*** Error - No Valid Environment Area found\n");
	else if (read1_fail || read2_fail)
		puts("*** Warning - some problems detected reading environment; recovered successfully\n");

	crc1_ok = !read1_fail && (crc32(0, tmp_env1->data, ENV_SIZE) == tmp_env1->crc);
	crc2_ok = !read2_fail && (crc32(0, tmp_env2->data, ENV_SIZE) == tmp_env2->crc);

	if (!crc1_ok && !crc2_ok) {
		//		set_default_env("!bad CRC");
		goto done;
	} else if (crc1_ok && !crc2_ok) {
		altenv_valid = 1;
	} else if (!crc1_ok && crc2_ok) {
		altenv_valid = 2;
	} else {
		/* both ok - check serial */
		if (tmp_env1->flags == 255 && tmp_env2->flags == 0)
			altenv_valid = 2;
		else if (tmp_env2->flags == 255 && tmp_env1->flags == 0)
			altenv_valid = 1;
		else if (tmp_env1->flags > tmp_env2->flags)
			altenv_valid = 1;
		else if (tmp_env2->flags > tmp_env1->flags)
			altenv_valid = 2;
		else /* flags are equal - almost impossible */
			altenv_valid = 1;
	}
	free(env_ptr);

	if (altenv_valid == 1)
		ep = tmp_env1;
	else
		ep = tmp_env2;

	altenv_flags = ep->flags;
	if (himport_r(&altenv_htab, (char*)ep->data, sizeof(ep->data), '\0', 0, 0, NULL) == 0) {
		error("Environment import failed: errno = %d\n", errno);
	}

done:
	free(tmp_env1);
	free(tmp_env2);

	return 0;
}

static int writeenv(size_t offset, u_char* buf)
{
	size_t end = offset + CONFIG_ENV_RANGE;
	size_t amount_saved = 0;
	size_t blocksize, len;
	u_char* char_ptr;

	blocksize = nand_info[0].erasesize;
	len = min(blocksize, CONFIG_ENV_SIZE);

	while (amount_saved < CONFIG_ENV_SIZE && offset < end) {
		if (nand_block_isbad(&nand_info[0], offset)) {
			offset += blocksize;
		} else {
			char_ptr = &buf[amount_saved];
			if (nand_write(&nand_info[0], offset, &len, char_ptr))
				return 1;

			offset += blocksize;
			amount_saved += len;
		}
	}
	if (amount_saved != CONFIG_ENV_SIZE)
		return 1;

	return 0;
}

static int erase_and_write_env(const struct env_location* location, u_char* env_new)
{
	int ret = 0;

	printf("Erasing %s...\n", location->name);
	if (nand_erase_opts(&nand_info[0], &location->erase_opts))
		return 1;

	printf("Writing to %s... ", location->name);
	ret = writeenv(location->erase_opts.offset, env_new);
	puts(ret ? "FAILED!\n" : "OK\n");

	return ret;
}

static int env_print(char* name, int flag)
{
	char* res = NULL;
	ssize_t len;

	if (name) { /* print a single name */
		ENTRY e, *ep;

		e.key = name;
		e.data = NULL;
		hsearch_r(e, FIND, &ep, &altenv_htab, flag);
		if (ep == NULL)
			return 0;
		len = printf("%s=%s\n", ep->key, ep->data);
		return len;
	}

	/* print whole list */
	len = hexport_r(&altenv_htab, '\n', flag, &res, 0, 0, NULL);

	if (len > 0) {
		puts(res);
		free(res);
		return len;
	}

	/* should never happen */
	printf("## Error: cannot export environment\n");
	return 0;
}

static int do_altenv_setenv(cmd_tbl_t* cmdtp, int flag, int argc, char* const argv[])
{
	int i, len;
	char* name, *value, *s;
	ENTRY e, *ep;
	int env_flag = H_INTERACTIVE;

	if (!altenv_initialized) {
		altenv_init();
		altenv_initialized = 1;
	}

	if (argc < 2)
		return CMD_RET_USAGE;

	debug("Initial value for argc=%d\n", argc);
	while (argc > 1 && **(argv + 1) == '-') {
		char* arg = *++argv;

		--argc;
		while (*++arg) {
			switch (*arg) {
				case 'f': /* force */
					env_flag |= H_FORCE;
					break;
				default:
					return CMD_RET_USAGE;
			}
		}
	}
	debug("Final value for argc=%d\n", argc);
	name = argv[1];
	value = argv[2];

	if (strchr(name, '=')) {
		printf("## Error: illegal character '='"
			   "in variable name \"%s\"\n",
			   name);
		return 1;
	}

	altenv_id++;

	/* Delete only ? */
	if (argc < 3 || argv[2] == NULL) {
		int rc = hdelete_r(name, &env_htab, env_flag);
		return !rc;
	}

	/*
     *   * Insert / replace new value
     */
	for (i = 2, len = 0; i < argc; ++i)
		len += strlen(argv[i]) + 1;

	value = malloc(len);
	if (value == NULL) {
		printf("## Can't malloc %d bytes\n", len);
		return 1;
	}
	for (i = 2, s = value; i < argc; ++i) {
		char* v = argv[i];

		while ((*s++ = *v++) != '\0')
			;
		*(s - 1) = ' ';
	}
	if (s != value)
		*--s = '\0';

	e.key = name;
	e.data = value;
	hsearch_r(e, ENTER, &ep, &altenv_htab, env_flag);
	free(value);
	if (!ep) {
		printf("## Error inserting \"%s\" variable, errno=%d\n",
			   name, errno);
		return 1;
	}

	return 0;
}

static int do_altenv_printenv(cmd_tbl_t* cmdtp, int flag, int argc, char* const argv[])
{
	int i;
	int rcode = 0;
	int env_flag = H_HIDE_DOT;

	if (!altenv_initialized) {
		altenv_init();
		altenv_initialized = 1;
	}

	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'a') {
		argc--;
		argv++;
		env_flag &= ~H_HIDE_DOT;
	}

	if (argc == 1) {
		/* print all env vars */
		rcode = env_print(NULL, env_flag);
		if (!rcode)
			return 1;
		printf("\nEnvironment size: %d/%ld bytes\n", rcode, (ulong)ENV_SIZE);
		return 0;
	}

	/* print selected env vars */
	env_flag &= ~H_HIDE_DOT;
	for (i = 1; i < argc; ++i) {
		int rc = env_print(argv[i], env_flag);
		if (!rc) {
			printf("## Error: \"%s\" not defined\n", argv[i]);
			++rcode;
		}
	}

	return rcode;
}

static int do_altenv_saveenv(cmd_tbl_t* cmdtp, int flag, int argc, char* const argv[])
{
	int ret = 0;
	ALLOC_CACHE_ALIGN_BUFFER(env_t, env_new, 1);
	int env_idx = 0;
	static struct env_location location[] = {
		{
		 .name = "NAND",
		 .erase_opts = {
			 .length = CONFIG_ENV_RANGE,
			 .offset = CONFIG_ALT_ENV_OFFSET,
		 },
		},
		{
		 .name = "redundant NAND",
		 .erase_opts = {
			 .length = CONFIG_ENV_RANGE,
			 .offset = CONFIG_ALT_ENV_OFFSET_REDUND,
		 },
		},
	};
	char* res = NULL;

	if (!altenv_initialized) {
		altenv_init();
		altenv_initialized = 1;
	}

	if (CONFIG_ENV_RANGE < CONFIG_ENV_SIZE)
		return 1;

	res = (char*)env_new->data;
	ret = hexport_r(&altenv_htab, '\0', 0, &res, ENV_SIZE, 0, NULL);
	env_new->crc = crc32(0, env_new->data, ENV_SIZE);
	env_new->flags = ++altenv_flags; /* increase the serial */
	env_idx = (altenv_valid == 1);

	ret = erase_and_write_env(&location[env_idx], (u_char*)env_new);
	if (!ret) {
		/* preset other copy for next write */
		altenv_valid = altenv_valid == 2 ? 1 : 2;
		return ret;
	}

	env_idx = (env_idx + 1) & 1;
	ret = erase_and_write_env(&location[env_idx], (u_char*)env_new);
	if (!ret)
		printf("Warning: primary env write failed, redundancy is lost!\n");

	return ret;
}

static int do_altenv_toggle_boot_partition(cmd_tbl_t* cmdtp, int flag, int argc, char* const argv[])
{
	ENTRY e, *ep;

    static char boot_partition_str[] = "boot_partition";
    static char zero_str[] = "0";
    static char one_str[] = "1";

	if (!altenv_initialized) {
		altenv_init();
		altenv_initialized = 1;
	}

	e.key = boot_partition_str;
	e.data = NULL;
	hsearch_r(e, FIND, &ep, &altenv_htab, 0);
	if (ep == NULL)
		return 0;

	e.data = zero_str;
	if (strcmp(ep->data, zero_str) == 0) {
        e.data = one_str;
	} 
	hsearch_r(e, ENTER, &ep, &altenv_htab, 0);

	return 0;
}

U_BOOT_CMD_COMPLETE(
	alt_setenv, CONFIG_SYS_MAXARGS, 0, do_altenv_setenv,
	"set environment variables for alternative environment",
	"name\n"
	"    - delete environment variable 'name'",
	var_complete);

U_BOOT_CMD_COMPLETE(
	alt_printenv, CONFIG_SYS_MAXARGS, 1, do_altenv_printenv,
	"print environment variables from alternative environment",
	"[name] ...\n"
	"    - print value of environment variable 'name'",
	var_complete);

U_BOOT_CMD(
	alt_saveenv, 1, 0, do_altenv_saveenv,
	"save alternative environment variables to alternative storage",
	"");

U_BOOT_CMD(
	alt_toggle_boot_partition, 1, 0, do_altenv_toggle_boot_partition,
	"toggle boot_partition in alternative environment",
	"");

