/*
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <asm/io.h>
#include <asm/global_data.h>
#include <asm/arch/register.h>

#define MAX_CLK_NUM		7

DECLARE_GLOBAL_DATA_PTR;

void get_platform_clk(unsigned int *cpu_clk, unsigned int *apb_clk,
			unsigned int *axi_clk)
{
	unsigned int	platform_clk[MAX_CLK_NUM][3] = {
				{ 400*1000000, 100*1000000, 133333333},
				{ 600*1000000, 100*1000000, 150*1000000},
				{ 700*1000000, 100*1000000, 140*1000000},
				{ 800*1000000, 100*1000000, 160*1000000},
				{ 900*1000000, 100*1000000, 150*1000000},
				{ 750*1000000, 150*1000000, 150*1000000},
				{ 850*1000000, 170*1000000, 141666667}
			};
	unsigned int 	reg_v;

	reg_v = __raw_readl(GLOBAL_STRAP);
	reg_v = (reg_v >> 1) & 0x07;

	*cpu_clk = platform_clk[reg_v][0];
	*apb_clk = platform_clk[reg_v][1];
	*axi_clk = platform_clk[reg_v][2];
}

int arch_cpu_init(void)
{
	static unsigned int cpu_clk;
	static unsigned int apb_clk;
	static unsigned int axi_clk;

	get_platform_clk(&cpu_clk, &apb_clk, &axi_clk);

	gd->cpu_clk = cpu_clk;
	gd->arch.timer_rate_hz = apb_clk;

	return 0;
}
