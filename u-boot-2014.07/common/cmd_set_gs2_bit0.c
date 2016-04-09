/*
 * (C) Copyright 2015 GreenwaveSystems.com
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

/*
 * Execute void function
 */
#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/arch/register.h>

#ifdef CONFIG_CMD_CORTINA_GS2_BIT0

#define IO_WRITE(addr, val) (*(volatile unsigned int *)(addr) = (val))
#define IO_READ(addr) (*(volatile unsigned int *)(addr))

typedef void __noreturn (*image_entry_noargs_t)(void);

static int do_set_gs2_bit0(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int bit,tmp;
	if (argc < 2) return CMD_RET_USAGE;
	bit = simple_strtoul(argv[1], NULL, 16) & 0x1U;
	tmp = IO_READ(GLOBAL_SOFTWARE2);
	if (bit) {
		tmp |= 1U;
	} else {
		tmp &= ~1U;
	}
	IO_WRITE(GLOBAL_SOFTWARE2, tmp);
	return 0;
}

/* -------------------------------------------------------------------- */

U_BOOT_CMD(
	set_gs2_bit0, CONFIG_SYS_MAXARGS, 1,	do_set_gs2_bit0,
	"Set Bit 0 of GLOBAL_SOFTWARE2 Reg",
	"bit \n    - set bit value to Bit 0 of GLOBAL_SOFTWARE2 Reg\n"
);

#endif
