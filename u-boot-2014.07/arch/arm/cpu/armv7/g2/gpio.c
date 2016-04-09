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

#include <common.h>
#include <asm/io.h>
#include <asm/arch/register.h>
#include <asm/arch/gpio.h>

/* Only compile this file for boards with GPIO support */
#if defined(GLOBAL_GPIO_MUX_BASE)

#if defined(CONFIG_SYS_G2_GPIO_TABLE)
gpio_param_s const gpio_tab[GPIO_GROUP_MAX][GPIO_MAX] = CONFIG_SYS_G2_GPIO_TABLE;
#endif

void gpio_config(int pin, int in_out, int gpio_alt, int val)
{
	u32 reg;
	unsigned char gpio_core = pin / GPIO_MAX;
	pin %= GPIO_MAX;

	reg = __raw_readl(GPIO_MUX(gpio_core));
	if (gpio_alt == GPIO_SEL) {
		reg |= GPIO_VAL(pin);
	} else {
		reg &= (~GPIO_VAL(pin));
	}
	__raw_writel(reg, GPIO_MUX(gpio_core));

	reg = __raw_readl(GPIO_CFG(gpio_core));
	if (in_out == GPIO_OUT) {
		reg &= (~GPIO_VAL(pin));
		__raw_writel(reg, GPIO_CFG(gpio_core));
		reg = __raw_readl(GPIO_IN(gpio_core));
		if (val == GPIO_OUT_0)
			reg &= (~GPIO_VAL(pin));
		else if (val == GPIO_OUT_1)
			reg |= GPIO_VAL(pin);
		__raw_writel(reg, GPIO_OUT(gpio_core));
	} else {
		reg |= (GPIO_VAL(pin));
		__raw_writel(reg, GPIO_CFG(gpio_core));
	}
}

void gpio_write_bit(int pin, int val)
{
	u32 reg;
	unsigned char gpio_core = pin / GPIO_MAX;
	pin %= GPIO_MAX;

	reg = __raw_readl(GPIO_MUX(gpio_core));
	if ((reg & GPIO_VAL(pin)) == 0)
		return;
	reg = __raw_readl(GPIO_CFG(gpio_core));
	if (reg & GPIO_VAL(pin))
		return;

	reg = __raw_readl(GPIO_IN(gpio_core));
	if (val == GPIO_OUT_0) 
		reg &= (~GPIO_VAL(pin));
	else
		reg |= GPIO_VAL(pin);
	__raw_writel(reg, GPIO_OUT(gpio_core));
}

#if defined(CONFIG_SYS_G2_GPIO_TABLE)
void gpio_set_chip_configuration(void)
{
	unsigned char gpio_core, i;
	u32	mux, cfg, reg;
	for (gpio_core = 0; gpio_core < GPIO_GROUP_MAX; gpio_core++) {
		mux = 0xffffffff;  
		cfg = 0xffffffff;
		reg = 0x00000000;
		for (i = 0; i < GPIO_MAX; i++) {
			if (gpio_tab[gpio_core][i].alt == GPIO_SEL) {
				mux |= GPIO_VAL(i);
				if (gpio_tab[gpio_core][i].in_out == GPIO_OUT) {
					cfg &= (~GPIO_VAL(i));
					if (gpio_tab[gpio_core][i].out_val == GPIO_OUT_0)
						reg &= (~(GPIO_VAL(i)));
					else
						reg |= (GPIO_VAL(i));
				} else 
					cfg |= GPIO_VAL(i);
			} else 
				mux &= (~GPIO_VAL(i));
		}
		__raw_writel(mux, GPIO_MUX(gpio_core));
		__raw_writel(cfg, GPIO_CFG(gpio_core));
		__raw_writel(reg, GPIO_OUT(gpio_core));
	}
}

#endif /* CONFIG_SYS_G2_GPIO_TABLE */
#endif /* GLOBAL_GPIO_MUX_BASE */
