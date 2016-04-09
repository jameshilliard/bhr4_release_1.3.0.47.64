/*
 *  drivers/serial/serial_g2.c
 *
 * Copyright (c) Greenwave Reality Inc 2014.
 * 		Hoang Tran <hoang.tran@greenwavereality.com>
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
#include <serial.h>
#include "serial_g2.h"

#define IO_WRITE(addr, val) 	(*(volatile unsigned int *)(addr) = (val))
#define IO_READ(addr) 		(*(volatile unsigned int *)(addr))

DECLARE_GLOBAL_DATA_PTR;

/*
 * Cortina G2 has four UARTs, we use the first two, at 115200-8-N-1
 */
#define baudrate		(gd->baudrate) /* CONFIG_BAUDRATE */

#ifdef CONFIG_SYS_SERIAL0
#undef CONFIG_SYS_SERIAL0
#endif

#ifdef CONFIG_SYS_SERIAL1
#undef CONFIG_SYS_SERIAL1
#endif

#define CONFIG_SYS_SERIAL0	PER_UART0_CFG
#define CONFIG_SYS_SERIAL1	PER_UART1_CFG

extern void get_platform_clk(unsigned int *cpu_clk, unsigned int *apb_clk, unsigned int *axi_clk);

int g2_serial_init (unsigned int port)
{
	unsigned int temp;
	unsigned int sample = 0;
	static unsigned int cpu_clk;
	static unsigned int apb_clk;
	static unsigned int axi_clk;

	/*
	 ** First, disable everything.
	 */
	IO_WRITE(port + UCFG, 0x0);

	/* get APB clock rate */
	get_platform_clk(&cpu_clk, &apb_clk, &axi_clk);

	/*
	 ** Set baud rate, 8 bits, 1 stop bit, no parity
	 **
	 */

	/* temp = UART_CLOCK/baudrate; */
	temp = apb_clk/baudrate;
	temp = (temp << 8) | UCFG_EN | UCFG_TX_EN | UCFG_RX_EN 	\
		| UCFG_CHAR_8;
	IO_WRITE(port + UCFG, temp);

	/* sample = (UART_CLOCK/baudrate)/2; */
	sample = (apb_clk/baudrate)/2; 
	sample = (sample < 7) ? 7 : sample;
	IO_WRITE(port + URX_SAMPLE, sample);

	return 0;
}

void g2_serial_puts (const char *s)
{
	while (*s) {
		serial_putc (*s++);
	}
}

static void g2_serial_putc (unsigned int port, char c)
{
	volatile unsigned int status;

	/* Send the character */
	IO_WRITE(port + UTX_DATA, c);

	/* Wait for Tx FIFO not full */
	do {
		status = IO_READ(port + UINFO);
	} while (!(status & UINFO_TX_FIFO_EMPTY));

}

static int g2_serial_getc (unsigned int port)
{
	unsigned int data;

	/* Wait until there is data in the FIFO */
	while ( IO_READ(port + UINFO) & UINFO_RX_FIFO_EMPTY );

	data = IO_READ(port + URX_DATA) & 0xFF;

	return data;
}

static int g2_serial_tstc (int port)
{
	unsigned int status;

	status = IO_READ(port + UINFO);

	if (status & UINFO_RX_FIFO_EMPTY)	/* empty */
		return 0;
	else			/* something in RX FIFO */
		return 1;
}

#define g2_uart(uart, UART)				\
	int g2_##uart##_init(void)			\
	{						\
		return g2_serial_init(UART);		\
	}						\
							\
	void g2_##uart##_setbrg(void)			\
	{						\
		g2_serial_init(UART);			\
	}						\
							\
	void g2_##uart##_putc(const char c)		\
	{						\
		if (c == '\n')				\
			g2_serial_putc(UART, '\r');	\
		g2_serial_putc(UART, c);		\
	}						\
							\
	int g2_##uart##_getc(void)			\
	{						\
		return g2_serial_getc(UART);		\
	}						\
							\
	int g2_##uart##_tstc(void)			\
	{						\
		return g2_serial_tstc(UART);		\
	}						\
	

#define g2_uart_desc(uart)				\
struct serial_device g2_##uart##_dev = {		\
	.name	= "g2_"#uart,				\
	.start	= g2_##uart##_init,			\
	.stop	= NULL,					\
	.setbrg	= g2_##uart##_setbrg,			\
	.putc	= g2_##uart##_putc,			\
	.puts	= g2_serial_puts,			\
	.getc	= g2_##uart##_getc,			\
	.tstc	= g2_##uart##_tstc,			\
};

#define g2_serial_multi(uart, UART)			\
	g2_uart(uart, UART)				\
	g2_uart_desc(uart)				\


#ifdef CONFIG_SYS_SERIAL0
	g2_serial_multi(serial0, CONFIG_SYS_SERIAL0)
#endif
#ifdef CONFIG_SYS_SERIAL1
	g2_serial_multi(serial1, CONFIG_SYS_SERIAL1)
#endif

void g2_serial_initialize(void)
{
	serial_register(&g2_serial0_dev);
	serial_register(&g2_serial1_dev);
}

__weak struct serial_device *default_serial_console(void)
{
	return &g2_serial0_dev;
}
