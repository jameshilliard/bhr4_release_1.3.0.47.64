/*
 * (C) Copyright 2012
 * Cortina-systems <www.cortina-systems.com>
 *
 * Derived from drivers/spi/mpc8xxx_spi.c
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
 */

#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <spi.h>
#include <asm/arch/register.h>

/* Register Map */
#define CS75XX_SPI_BASE		0xf0070064
#define CS75XX_SPI_CLK		CS75XX_SPI_BASE + 0x00
#define CS75XX_SPI_CFG		CS75XX_SPI_BASE + 0x04
#define CS75XX_SPI_CTRL		CS75XX_SPI_BASE + 0x08
#define CS75XX_SPI_CA0		CS75XX_SPI_BASE + 0x0C
#define CS75XX_SPI_CA1		CS75XX_SPI_BASE + 0x10
#define CS75XX_SPI_CA2		CS75XX_SPI_BASE + 0x14
#define CS75XX_SPI_WDAT1	CS75XX_SPI_BASE + 0x18
#define CS75XX_SPI_WDAT0	CS75XX_SPI_BASE + 0x1C
#define CS75XX_SPI_RDAT1	CS75XX_SPI_BASE + 0x20
#define CS75XX_SPI_RDAT0	CS75XX_SPI_BASE + 0x24
#define CS75XX_SPI_IE0		CS75XX_SPI_BASE + 0x28
#define CS75XX_SPI_INT0		CS75XX_SPI_BASE + 0x2C
#define CS75XX_SPI_IE1		CS75XX_SPI_BASE + 0x30
#define CS75XX_SPI_INT1		CS75XX_SPI_BASE + 0x34
#define CS75XX_SPI_STAT		CS75XX_SPI_BASE + 0x38
#define CS75XX_SPI_MODE		CS75XX_SPI_BASE + 0x20C

#define	CFG_CMD_NORMAL		0
#define CFG_CMD_ONLY		1
#define CFG_CMD_WRITE		0
#define CFG_CMD_READ		1
#define CFG_SPI			0
#define CFG_MWR			1
#define CFG_CS1			2

#define SPI_CTRL_SSPDONE	1
#define SPI_RETRY_TIMES		256

static PER_SPI_CLK_t		spi_clk;
static PER_SPI_CFG_t		spi_cfg;
static PER_SPI_CTRL_t		spi_ctrl;
static PER_SPI_CA0_t		spi_ca0;
static PER_SPI_CA1_t		spi_ca1;
static PER_SPI_CA2_t		spi_ca2;
static PER_SPI_WDAT0_t		spi_wdat0;
static PER_SPI_WDAT1_t		spi_wdat1;
static PER_SPI_RDAT0_t		spi_rdat0;
static PER_SPI_RDAT1_t		spi_rdat1;
static PER_SPI_STAT_t		spi_stat;

int spi_cs_is_valid(unsigned int bus, unsigned int cs)
{
	return (bus == 0 && cs == 1);
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
	struct spi_slave *slave;

	if (!spi_cs_is_valid(bus, cs)) {
		printf("%s : Chip select ID is wrong!!\n",__func__);
		return NULL;
	}

	slave = malloc(sizeof(struct spi_slave));
	if (!slave) {
		printf("%s : Memory allocation fail!!\n",__func__);
		return NULL;
	}

	slave->bus = bus;
	slave->cs = cs;

	/*
	 * TODO: Some of the code in spi_init() should probably move
	 * here, or into spi_claim_bus() below.
	 */
	spi_clk.wrd = __raw_readl(CS75XX_SPI_CLK);
	spi_clk.bf.ssp_igap = 0;
	spi_clk.bf.counter_load = 8;
	__raw_writel(spi_clk.wrd, CS75XX_SPI_CLK);

	spi_cfg.wrd = __raw_readl(CS75XX_SPI_CFG);
	spi_cfg.bf.micro_wire_cs_sel = 0;
	spi_cfg.bf.sel_ssp_cs = 0x01 << cs;
	__raw_writel(spi_cfg.wrd, CS75XX_SPI_CFG);

	__raw_writel(SPI_MODE_3, CS75XX_SPI_MODE);

	return slave;
}

void spi_cs_activate(struct spi_slave *slave)
{
	spi_cfg.wrd = __raw_readl(CS75XX_SPI_CFG);
	spi_cfg.bf.micro_wire_cs_sel = 0;
	spi_cfg.bf.sel_ssp_cs = 0x01 << slave->cs;
	__raw_writel(spi_cfg.wrd, CS75XX_SPI_CFG);
	return;
}

void spi_cs_deactivate(struct spi_slave *slave)
{
	spi_cfg.wrd = __raw_readl(CS75XX_SPI_CFG);
	spi_cfg.bf.micro_wire_cs_sel = 0;
	spi_cfg.bf.sel_ssp_cs = 0;
	__raw_writel(spi_cfg.wrd, CS75XX_SPI_CFG);
	return;
}

void spi_free_slave(struct spi_slave *slave)
{
	free(slave);
}

void spi_init(void)
{
	return;
}

int spi_claim_bus(struct spi_slave *slave)
{
	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	return;
}

int spi_xfer_cs75xx(struct spi_slave *slave, const void *dout, unsigned int bitout,
		void *din, unsigned int bitin, unsigned long flags)
{
	unsigned char	*buf8;
	unsigned int 	bytein;
	unsigned int 	byteout;
	unsigned int	value = 0;
	unsigned int 	i;

	byteout = bitout / 8;
	bytein = bitin / 8;

	if (flags & SPI_XFER_BEGIN)
		spi_cs_activate(slave);

	spi_cfg.wrd = __raw_readl(CS75XX_SPI_CFG);
	if (din) {	/* read command */
		spi_cfg.bf.command_cyc = CFG_CMD_NORMAL;
		spi_cfg.bf.read_write = CFG_CMD_READ;
		spi_cfg.bf.ssp_cmd_cnt = bitout - 1 ;
		spi_cfg.bf.pre_ssp_dat_cnt = bitin - 1;
	} else {	/* write command */
		spi_cfg.bf.command_cyc = CFG_CMD_ONLY;
		spi_cfg.bf.read_write = CFG_CMD_WRITE;
		spi_cfg.bf.ssp_cmd_cnt = bitout - 1;
		spi_cfg.bf.pre_ssp_dat_cnt = 0;
	}
	__raw_writel(spi_cfg.wrd, CS75XX_SPI_CFG);

	if (dout) {
		buf8 = (u8 *)dout;
		for (i = 0; i < byteout; i++) {
			if ((i % 4) == 0)
				value = 0;

			value |= ((u32)(*buf8)) << (24 - 8 * (i % 4));
			buf8++;

			if ((i & 3) == 3)
				__raw_writel(value, CS75XX_SPI_CA0 + 4 * (i / 4));
		}
		if (i % 4)
			__raw_writel(value, CS75XX_SPI_CA0 + 4 * (i / 4));
	}

	/* Run and Transfer! */
	spi_ctrl.bf.sspstart = 1;
	__raw_writel(spi_ctrl.wrd, CS75XX_SPI_CTRL);

	for (i = 0; i < SPI_RETRY_TIMES; i++) {
		spi_ctrl.wrd = __raw_readl(CS75XX_SPI_CTRL);
		if (spi_ctrl.bf.sspdone == SPI_CTRL_SSPDONE)
			break;
		else
			udelay(10);
	}

	if (i < SPI_RETRY_TIMES)
		__raw_writel(SPI_CTRL_SSPDONE, CS75XX_SPI_CTRL);
	else
		printf("%s : SPI timeout !\n",__func__);

	if (din) {
		buf8 = (u8 *)din;
		for (i = 0; i < bytein; i++) {
			if ((i % 4) == 0)
				value = __raw_readl(CS75XX_SPI_RDAT0 + 4 * (i / 4));
			*buf8 = (value >> (i * 8)) & 0xFF;
			buf8++;
		}
	}

	if (flags & SPI_XFER_END)
		spi_cs_deactivate(slave);

	return 0;
}

int  spi_xfer(struct spi_slave *slave, unsigned int bitlen, const void *dout,
		void *din, unsigned long flags)
{
	return spi_xfer_cs75xx(slave, dout, bitlen, din, bitlen, flags);
}
