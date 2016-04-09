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
#include <asm/arch/register.h>
#include <asm/arch/gpio.h>

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_DISPLAY_CPUINFO
/**
 * Print CPU information
 */
int print_cpuinfo(void)
{
	printf("CPU: GoldenGate (CS7542) SoC ASIC\n");
	return 0;
}
#endif

#ifdef CONFIG_DISPLAY_BOARDINFO
/**
 * Print board information
 */
int checkboard(void)
{
	printf("Board: Verizon/GWR BHR4 board\n");
	return 0;
}
#endif

#if 0
static u32 __attribute__((aligned(16384))) page_table[4096];

static inline void delay (unsigned long loops)
{
	__asm__ volatile ("1:\n"
		"subs %0, %1, #1\n"
		"bne 1b":"=r" (loops):"0" (loops));
}
static void mmu_setup(void)
{
	bd_t *bd = gd->bd;
	int i, j;
	u32 reg;

	/* Set up an identity-mapping for all 4GB, rw for everyone */
	for (i = 0; i < 4096; i++)
		page_table[i] = i << 20 | (3 << 10) | 0x12;

	/* Then, enable cacheable and bufferable for RAM only */
	for (j = 0; j < CONFIG_NR_DRAM_BANKS; j++) {
		for (i = bd->bi_dram[j].start >> 20;
			i < (bd->bi_dram[j].start + bd->bi_dram[j].size) >> 20;
			i++) {
			page_table[i] = i << 20 | (3 << 10) | 0x1e; /* C=1 B=1*/
		}
	}

	/* Copy the page table address to cp15 */
	asm volatile("mcr p15, 0, %0, c2, c0, 0"
		     : : "r" (page_table) : "memory");

	/* Set the access control to all-supervisor */
	asm volatile("mcr p15, 0, %0, c3, c0, 0"
		     : : "r" (~0));

	/* and enable the mmu */
	reg = get_cr();	/* get control reg. */
	delay(100);
	set_cr(reg | CR_M);
}
#endif

#ifndef CONFIG_SPL_BUILD
int dram_init(void)
{
	unsigned int	size;

	size = __raw_readl(GLOBAL_SOFTWARE2);
	size = size & 0xfff00000;

	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = size; /*PHYS_SDRAM_1_SIZE; */
	gd->ram_size = size;

//	mmu_setup();

	return 0;
}

void enable_caches(void)
{
	icache_enable();
}

static void disable_remap(void)
{
	unsigned int	reg_val;

	/* Disable ROM map */
	reg_val = __raw_readl(GLOBAL_GLOBAL_CONFIG);
	reg_val = reg_val | 0x0001;
	__raw_writel(reg_val, GLOBAL_GLOBAL_CONFIG);

	/* L2 filter start address */
	__raw_writel(0x00000001, 0xf5010c00);
}

int board_init(void)
{
	/* adress of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x00000100;

	disable_remap();

	gpio_set_chip_configuration();

	return 0;
}
#endif
