/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2003
 * Texas Instruments, <www.ti.com>
 * Kshitij Gupta <Kshitij@ti.com>
 *
 * (C) Copyright 2004
 * ARM Ltd.
 * Philippe Robin, <philippe.robin@arm.com>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/global_data.h>

#ifdef CONFIG_SYS_TIMERBASE
#undef CONFIG_SYS_TIMERBASE
#endif
#define CONFIG_SYS_TIMERBASE	  0xf007001c

DECLARE_GLOBAL_DATA_PTR;

/*
 * U-Boot expects a 32 bit timer, running at CONFIG_SYS_HZ
 * CONFIG_SYS_HZ is NOT configurable but constant 1000 Hz
 */

/* Keep total timer count to avoid losing decrements < div_timer */
static unsigned long long lastdec;	 /* Timer reading at last call */

/* CONFIG_SYS_HZ = CONFIG_SYS_HZ_CLOCK/(div_clock * div_timer) */
static ulong timestamp;		/* U-Boot ticks since startup */

#define READ_TIMER (*(volatile ulong *)(CONFIG_SYS_TIMERBASE+8))
#define TIMER_LOAD_VAL	0xffffffff

/* all function return values in U-Boot ticks i.e. (1/CONFIG_SYS_HZ) sec
 *  - unless otherwise stated
 */

/* starts up a counter
 * - the Integrator/CP timer can be set up to issue an interrupt */
extern void get_platform_clk(unsigned int *cpu_clk, unsigned int *apb_clk,
			unsigned int *axi_clk);

int timer_init(void)
{
	static unsigned int cpu_clk;
	static unsigned int apb_clk;
	static unsigned int axi_clk;

	get_platform_clk(&cpu_clk, &apb_clk, &axi_clk);

	gd->arch.timer_rate_hz = apb_clk;

	/* Load timer with initial value */
	*(volatile ulong *)(CONFIG_SYS_TIMERBASE + 0) = TIMER_LOAD_VAL;
	*(volatile ulong *)(CONFIG_SYS_TIMERBASE + 4) = 0x000000C0;

	reset_timer_masked();

	return (0);
}

/*
 * timer without interrupts
 */
void reset_timer(void)
{
	reset_timer_masked();
}

/*
 * This function must return milliseconds
 */
ulong get_timer(ulong base_ticks)
{
	return get_timer_masked () - base_ticks;
}

void set_timer(ulong ticks)
{
	timestamp = ticks;
}

/* delay usec useconds */
void __udelay (unsigned long usec)
{
	long tmo;
	unsigned long now, last = READ_TIMER;

	/* tmo  = usec * (CONFIG_TIMER_CLOCK / 1000000); */
	tmo  = usec * (gd->arch.timer_rate_hz / 1000000);

	while (tmo > 0) {
		now = READ_TIMER;
		if (last < now) /* timer overflow */
			tmo -= TIMER_LOAD_VAL + last - now;
		else
			tmo -= last - now;
		last = now;
	}
}

void reset_timer_masked (void)
{
	/* capure current decrementer value    */
	/* lastdec = READ_TIMER / (CONFIG_TIMER_CLOCK / CONFIG_SYS_HZ); */
	lastdec = READ_TIMER / (gd->arch.timer_rate_hz / CONFIG_SYS_HZ);
	/* start "advancing" time stamp from 0 */
	timestamp = 0L;
}

/* converts the timer reading to U-Boot ticks	       */
/* the timestamp is the number of ticks since reset    */

ulong get_timer_masked (void)
{
	/* current tick value @ 1 tick per msec */
	/* ulong now = READ_TIMER / (CONFIG_TIMER_CLOCK / CONFIG_SYS_HZ); */
	ulong now = READ_TIMER / (gd->arch.timer_rate_hz / CONFIG_SYS_HZ);

	if (lastdec < now) /* count down timer underflow */
		/* timestamp+= TIMER_LOAD_VAL/(CONFIG_TIMER_CLOCK/CONFIG_SYS_HZ) -now+lastdec; */
		timestamp += TIMER_LOAD_VAL / (gd->arch.timer_rate_hz / CONFIG_SYS_HZ) \
		            - now + lastdec;
	else
		timestamp += lastdec - now;

	lastdec = now;

	return timestamp;
}

/* waits specified delay value and resets timestamp */
void udelay_masked (unsigned long usec)
{
	udelay(usec);
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
	return (unsigned long long)get_timer(0);
}

/*
 * Return the timebase clock frequency
 * i.e. how often the timer decrements
 */
ulong get_tbclk (void)
{
	return CONFIG_SYS_HZ;
}

