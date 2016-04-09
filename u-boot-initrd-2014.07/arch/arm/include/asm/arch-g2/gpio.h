/*
 * (C) Copyright 2014
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

#ifndef __ASM_G2_GPIO_H
#define __ASM_G2_GPIO_H

#include <asm/types.h>

#define GPIO_GROUP_MAX	5
#define GPIO_MAX	32

/* GPIO controller */
struct g2_gpio {
	u32	cfg;
	u32	out;
	u32	in;
	u32	lvl;
	u32	edge;
	u32	ie;
	u32	intr;
	u32	stat;
};

/* Offsets */
#define GPIOx_CFG	0x00
#define GPIOx_OUT	0x04
#define GPIOx_IN	0x08
#define GPIOx_LVL	0x0C
#define GPIOx_EDGE	0x10
#define GPIOx_IE	0x14
#define GPIOx_INTR	0x18
#define GPIOx_STAT	0x1C

#define GPIO_BASE(x)	((0x20)*x + PER_GPIO0_CFG)
#define GPIO_CFG(x)	(GPIO_BASE(x) + GPIOx_CFG)
#define GPIO_OUT(x)	(GPIO_BASE(x) + GPIOx_OUT)
#define GPIO_IN(x)	(GPIO_BASE(x) + GPIOx_IN)
#define GPIO_LVL(x)	(GPIO_BASE(x) + GPIOx_LVL)
#define GPIO_EDGE(x)	(GPIO_BASE(x) + GPIOx_EDGE)
#define GPIO_INTR(x)	(GPIO_BASE(x) + GPIOx_INTR)
#define GPIO_STAT(x)	(GPIO_BASE(x) + GPIOx_STAT)

#define GPIO_MUX(x)	(4*x + GLOBAL_GPIO_MUX_BASE)

#define GPIO_VAL(x)	(1 << x)

#ifndef __ASSEMBLY__
typedef enum gpio_select { GPIO_ALT, GPIO_SEL } gpio_select_t;
typedef enum gpio_driver { GPIO_OUT, GPIO_IN } gpio_driver_t;
typedef enum gpio_out	 { GPIO_OUT_0, GPIO_OUT_1, GPIO_NO_CHG } gpio_out_t;

typedef struct {
	unsigned long	add;	/* gpio core base address	*/
	gpio_driver_t	in_out;	/* Driver Setting		*/
	gpio_select_t	alt;	/* Selected Alternate		*/
	gpio_out_t	out_val;/* Default Output Value		*/
} gpio_param_s;
#endif

void gpio_config(int pin, int in_out, int gpio_alt, int val);
void gpio_write_bit(int pin, int val);
void gpio_set_chip_configuration(void);

#endif /* __ASM_G2_GPIO_H */
