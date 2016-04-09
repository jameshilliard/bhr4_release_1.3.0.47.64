/*
 * (C) Copyright 2014 Greenwave Systems, Inc.
 * Hoang Tran <hoang.tran@greenwavesystems.com>
 *
 */
#include <common.h>
#include <spl.h>

DECLARE_GLOBAL_DATA_PTR;

#define IO_WRITE(addr, val) (*(volatile unsigned int *)(addr) = (val))
#define IO_READ(addr) (*(volatile unsigned int *)(addr))

void board_init_f(ulong dummy)
{
	unsigned int time_stamp;
	unsigned int dly;
	unsigned int temp;

	/* Clear the BSS. */
	memset(__bss_start, 0, __bss_end - __bss_start);

	/* Set global data pointer. */
	gd = &gdata;

	time_stamp = IO_READ(0xf0000000);
	if (time_stamp & 0x00008000) {	/* A1 chip */
		/* External Reset */
		time_stamp = IO_READ(0xf00000c0);
		time_stamp |= 0x400;
		IO_WRITE(0xf00000c0, time_stamp);
		time_stamp = IO_READ(0xf00000c0);

		/* Switch ref_clk to 25MHz */
		time_stamp = IO_READ(0xf0000010);
		IO_WRITE(0xf0000010, time_stamp | 0x00040000);

		for (dly = 0; dly < 50000; dly++) {
			temp = IO_READ(0xf00000c0);
			dly += temp; //wilson
			dly -= IO_READ(0xf00000c0);
		}

		/* Release external reset */
		time_stamp = IO_READ(0xf00000c0);
		time_stamp &= ~0x400;
		IO_WRITE(0xf00000c0 , time_stamp);
		time_stamp = IO_READ(0xf00000c0);
	}

	timer_init();

	//preloader_console_init();
	dram_init();

	board_init_r(NULL, 0);
}

u32 spl_boot_device(void)
{
	return BOOT_DEVICE_NAND;
}
