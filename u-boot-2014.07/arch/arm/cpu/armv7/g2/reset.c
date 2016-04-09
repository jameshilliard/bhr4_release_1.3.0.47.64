/*
 * Common layer for reset
 *
 * (C) Copyright 2013
 * Hoang Tran <hoang.tran@greenwavereality.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <config.h>
#include <asm/io.h>
#include <asm/arch/register.h>

void __weak reset_cpu(unsigned long ignored)
{
        /*
        * To reset, use watchdog to reset whole system
        */
        unsigned int reg_v;

        /* do external reset */
	/* delay in POST, not in here - hoangtran */
	/*
        reg_v = __raw_readl(GLOBAL_SCRATCH);
        reg_v = reg_v | 0x400;
        __raw_writel(reg_v, GLOBAL_SCRATCH);
        udelay(500);
        reg_v = reg_v & (~0x400);
        __raw_writel(reg_v, GLOBAL_SCRATCH);
	*/

        /* Reset all block & subsystem */
        reg_v = __raw_readl(GLOBAL_GLOBAL_CONFIG);
        /* enable axi & L2 reset */
        reg_v &= ~0x00000200;

        /* wd_enable are exclusive with wd0_reset_subsys_enable */
        reg_v &= ~0x0000000E;

        /* reset remap, all block & subsystem */
        reg_v |= 0x000000F0;
        __raw_writel(reg_v, GLOBAL_GLOBAL_CONFIG);

        /* Fire */
        __raw_writel(0, GOLDENGATE_TWD_BASE + 0x28); /* Disable WD */
        __raw_writel(10, GOLDENGATE_TWD_BASE + 0x20); /* LOAD */

        /* Enable watchdog - prescale=256, watchdog mode=1, enable=1 */
        __raw_writel(0x0000FF09, GOLDENGATE_TWD_BASE + 0x28); /* Enable WD */
}
