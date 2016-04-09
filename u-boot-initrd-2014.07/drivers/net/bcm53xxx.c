/*
 * (C) Copyright 2013
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
#include <malloc.h>
#include <spi.h>

#define	BCM53125_DUMB_MODE		1

#define BCM53125_CHIP_SELECT		1
#define BCM53125_SPI_MAX_HZ		25000000
#define	BCM53125_SPI_MODE		SPI_MODE_3

#define BCM53125_SPI_RETRY_TIME		0xff
#define MII_MAX_RETRY			0xff

#define BCM53125_SPI_SPIF		0x80
#define BCM53125_SPI_RACK		0x20

/* MII access registers */
#define PSEUDO_PHYAD	0x1E	/* MII Pseudo PHY address */
#define REG_MII_PAGE	0x10	/* MII Page register */
#define REG_MII_ADDR	0x11	/* MII Address register */
#define REG_MII_STATUS	0x12	/* MII Access Status register */
#define REG_MII_DATA0	0x18	/* MII Data register 0 */
#define REG_MII_DATA1	0x19	/* MII Data register 1 */
#define REG_MII_DATA2	0x1a	/* MII Data register 2 */
#define REG_MII_DATA3	0x1b	/* MII Data register 3 */

static	struct spi_slave 		*spi;
static	unsigned int			pre_page = 0xff;

extern int g2_phy_write(int phy_addr, int reg_addr, u16 value);
extern int g2_phy_read(int phy_addr, int reg_addr);
extern struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode);
extern int spi_xfer_cs75xx(struct spi_slave *slave, const void *dout,
		unsigned int bitout, void *din, unsigned int bitin, u32 flags);

static int spi_cmd_read(struct spi_slave *spi, u8 *cmd,
		size_t cmd_len, u8 *data, size_t data_len)
{
	unsigned long flags = SPI_XFER_BEGIN;
	int ret;

	if (data_len == 0)
		flags |= SPI_XFER_END;

	ret = spi_xfer_cs75xx(spi, cmd, cmd_len * 8, data, data_len * 8, flags);
	return ret;
}

static int spi_cmd_write(struct spi_slave *spi, u8 *cmd, size_t cmd_len,
		u8 *data, size_t data_len)
{
	unsigned long flags = SPI_XFER_BEGIN;
	int ret;

	if (data_len == 0)
		flags |= SPI_XFER_END;

	ret = spi_xfer_cs75xx(spi, cmd, cmd_len * 8, data, data_len * 8, flags);
	return ret;
}

static int spi_cmd_init(void)
{

	spi = spi_setup_slave(0, BCM53125_CHIP_SELECT, \
			BCM53125_SPI_MAX_HZ, BCM53125_SPI_MODE);
	if (!spi) {
		debug("SF: Failed to set up slave\n");
		return 1;
	}

	return 0;
}

static int bcm53xxx_spi_read(u8 page, u8 reg, void *val, u8 len)
{
	static unsigned char	cmd[16];
	static unsigned char	data[4];
	unsigned int	i;

	memset(cmd, 0x00, sizeof(cmd));
	memset(data, 0x00, sizeof(data));

	/* Issue a Normal Read Command to poll the SPIF bit in SPI Status Reg */
	cmd[0] = 0x60;
	cmd[1] = 0xfe;
	for (i=0; i< BCM53125_SPI_RETRY_TIME; i++) {
		spi_cmd_read(spi, &cmd[0], 2, &data[0], 1);
		if ((data[0] & BCM53125_SPI_SPIF) == 0)
			break;
	}
	if (i == BCM53125_SPI_RETRY_TIME) {
		printf("%s : SPI slave device does not ready!!(SPI status = 0x%x)\n",__func__, data[0]);
		return 1;
	}

	/* Issue a Normal Write Command to setup the accessed register page
	 * value into the SPI page register(0xFF). */
	if (pre_page != page) {
		cmd[0] = 0x61;
		cmd[1] = 0xff;
		cmd[2] = page;
		spi_cmd_write(spi, &cmd[0], 3, NULL, 0);
		pre_page = page;
	}

	/* Issue a Normal Read Command to setup the required register address.*/
	cmd[0] = 0x60;
	cmd[1] = reg;
	spi_cmd_read(spi, &cmd[0], 2, &data[0], 1);

	/* Issue a Normal Read Command to poll the RACK bit in SPI status
	 * register(0xFE) to determine the completion of read. */
	cmd[0] = 0x60;
	cmd[1] = 0xfe;
	for (i=0; i< BCM53125_SPI_RETRY_TIME; i++) {
		spi_cmd_read(spi, &cmd[0], 2, &data[0], 1);
		if ((data[0] & BCM53125_SPI_RACK) == BCM53125_SPI_RACK)
			break;
	}
	if (i == BCM53125_SPI_RETRY_TIME)
		return 1;

	/* Issue a Normal Read Command to read the specific registers' content
	 * placed in the SPI Data I/O register (0xF0~0xF7). */
	cmd[0] = 0x60;
	cmd[1] = 0xf0;
	spi_cmd_read(spi, &cmd[0], 2, &data[0], len);

	switch (len) {
	case 1:
		*(u8 *)val = data[0];
		break;
	case 2:
		*(u16 *)val = (data[0]<<8) + data[1];
		break;
	case 4:
		*(u32 *)val = (data[0]<<24)+(data[1]<<16)+(data[2]<<8)+data[3];
		break;
	}
	return 0;
}

static int bcm53xxx_spi_write(u8 page, u8 reg, void *val, u8 len)
{
	static unsigned char	cmd[16];
	static unsigned char	data[4];
	unsigned int		i;

	memset(cmd, 0x00, sizeof(cmd));
	memset(data, 0x00, sizeof(data));

	/* Issue a Normal Read Command to poll the SPIF bit in SPI Status Reg */
	cmd[0] = 0x60;
	cmd[1] = 0xfe;
	for (i=0; i< BCM53125_SPI_RETRY_TIME; i++) {
		spi_cmd_read(spi, &cmd[0], 2, &data[0], 1);
		if ((data[0] & BCM53125_SPI_SPIF) == 0)
			break;
	}
	if (i == BCM53125_SPI_RETRY_TIME)
		return 1;

	/* Issue a Normal Write Command to setup the accessed register page
	 * value into the SPI page register(0xFF). */
	if (pre_page != page) {
		cmd[0] = 0x61;
		cmd[1] = 0xff;
		cmd[2] = page;
		spi_cmd_write(spi, &cmd[0], 3, NULL, 0);
		pre_page = page;
	}

	/* Issue a Normal Write Command to setup the accessed register address
	 * value, followed by the write content starting from a low byte. */
	cmd[0] = 0x61;
	cmd[1] = reg;
	memcpy(&cmd[2], (u8 *)val, len);
	spi_cmd_write(spi, &cmd[0], 2 + len, NULL, 0);

	return 0;
}

int bcm53xxx_read_reg(u8 page, u8 reg, void *val, u8 len)
{
	return bcm53xxx_spi_read(page, reg, val, len);
}

int bcm53xxx_write_reg(u8 page, u8 reg, void *val, u8 len)
{
	return bcm53xxx_spi_write(page, reg, val, len);
}

int bcm53xxx_disable_phy(void)
{
	unsigned int	i;
	unsigned short	phy_val;

	for (i = 0; i < 5; i++) {
		bcm53xxx_spi_read(10+i, 0, &phy_val, 2);
		phy_val = phy_val | 0x0800;
		bcm53xxx_spi_read(10+i, 0, &phy_val, 2);
	}
	return 0;
}

int bcm53xxx_init(void)
{
	unsigned int	reg_val;
	int		ret;

	if (spi_cmd_init())
		return 1;

	ret = bcm53xxx_spi_read(2, 0x30, &reg_val, 4);
	if (ret)
		return ret;
	/* printf("Device ID = %x \n",reg_val); */

	/* software reset */
	reg_val = 0x90;
	bcm53xxx_spi_write(0, 0x79, &reg_val, 1);
	udelay(10);
	reg_val = 0x10;
	bcm53xxx_spi_write(0, 0x79, &reg_val, 1);

#ifdef BCM53125_DUMB_MODE
	/* Enable IMP port RGMII RX/TX clock delay. */
	reg_val = 0x03;
	bcm53xxx_spi_write(0, 0x60, &reg_val, 1);

	/* Enable Port 5 RGMII RX/TX clock delay. */
	reg_val = 0x03;
	bcm53xxx_spi_write(0, 0x65, &reg_val, 1);

	/* force IMP port to Link pass */
	bcm53xxx_spi_read(0, 0x0e, &reg_val, 1);
	reg_val = reg_val | 0x81;
	bcm53xxx_spi_write(0, 0x0e, &reg_val, 1);

	/* override the port state of Port 5. */
	bcm53xxx_spi_read(0, 0x5d, &reg_val, 1);
	reg_val = reg_val | 0x40;
	bcm53xxx_spi_write(0, 0x5d, &reg_val, 1);

	/* set port base vlan */
/*	reg_val = 0x10f;
	bcm53xxx_spi_write(0x31, 0x00, &reg_val, 2);

	reg_val = 0x10f;
	bcm53xxx_spi_write(0x31, 0x02, &reg_val, 2);

	reg_val = 0x10f;
	bcm53xxx_spi_write(0x31, 0x04, &reg_val, 2);

	reg_val = 0x10f;
	bcm53xxx_spi_write(0x31, 0x06, &reg_val, 2);

	reg_val = 0x030;
	bcm53xxx_spi_write(0x31, 0x08, &reg_val, 2);

	reg_val = 0x030;
	bcm53xxx_spi_write(0x31, 0x0a, &reg_val, 2);

	reg_val = 0x10f;
	bcm53xxx_spi_write(0x31, 0x10, &reg_val, 2);
*/
#else
	/* Enable Dual-IMP portd (both IMP port and port 5). */
	bcm53xxx_spi_read(2, 0, &reg_val, 1);
	/* reg_val = reg_val | 0xc0; */
	reg_val = reg_val | 0x80; //IMP port only
	bcm53xxx_spi_write(2, 0, &reg_val, 1);

	/* Set port 4 as WAN port. */
	/* reg_val = 0x10; */
	/* bcm53xxx_spi_write(0, 0x26, &reg_val, 2); */

	/* Disable Broadcom tag for IMP & GMII ports. */
	reg_val = 0x00;
	bcm53xxx_spi_write(2, 0x03, &reg_val, 1);

	/* Enable IMP port RGMII RX/TX clock delay. */
	reg_val = 0x03;
	bcm53xxx_spi_write(0, 0x60, &reg_val, 1);

	/* Enable Port 5 RGMII RX/TX clock delay. */
	reg_val = 0x03;
	bcm53xxx_spi_write(0, 0x65, &reg_val, 1);

	/* Enable unicast/multicast/broadcast received from IMP port. */
	reg_val = 0x1c;
	bcm53xxx_spi_write(0, 0x08, &reg_val, 1);

	/* force IMP port to Link pass */
	bcm53xxx_spi_read(0, 0x0e, &reg_val, 1);
	reg_val = reg_val | 0x81;
	bcm53xxx_spi_write(0, 0x0e, &reg_val, 1);

	/* override the port state of Port 5. */
	bcm53xxx_spi_read(0, 0x5d, &reg_val, 1);
	reg_val = reg_val | 0x40;
	bcm53xxx_spi_write(0, 0x5d, &reg_val, 1);

	/* Enable Managed mode & software forwarding. */
	bcm53xxx_spi_read(0, 0x0b, &reg_val, 1);
	reg_val = reg_val | 0x03;
	bcm53xxx_spi_write(0, 0x0b, &reg_val, 1);
#endif
	return 0;
}

int do_bcm_init(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	return bcm53xxx_init();
}

U_BOOT_CMD(
	bcm_init, 1, 0, do_bcm_init,
	"initialize switch chip",
	""
);

int do_bcm_reg(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret, i;
	unsigned int page, reg, val;

	if (spi_cmd_init())
		return -1;

	if (argc < 2) {
		printf("Usage:\nbcm_reg %s\n", cmdtp->help);
		return -1;
	}

	page = simple_strtoul(argv[1], NULL, 10);
	reg = simple_strtoul(argv[2], NULL, 10);

	if (argc == 3) {
		/* read the first 15 registers of the PHY */
		printf("REG addr 0x%x:\n", reg);
		for (i = 0; i < 1; i++) {
			bcm53xxx_read_reg(page, reg, &val, 4);
			printf("Page 0x%04x Reg 0x%04x = 0x%04x\n", page, reg+i*4, val);
		}
		return 0;
	}

	if (argc == 4) {
		/* write cmd */
		val = simple_strtoul(argv[3], NULL, 10);
		ret = bcm53xxx_write_reg(page, reg, &val, 4);
		if (!ret) {
			printf("Page 0x%04x Reg 0x%04x = 0x%04x\n", page, reg, val);
		} else {
			printf("Can't write Page 0x%4x Reg 0x%04X = 0x%04X, ret = %d", page, reg, val, ret);
		}
	}
	return 0;
}

U_BOOT_CMD(
	bcm_reg,	4,	1,	do_bcm_reg,
	"read/write switch internal registers",
	"[page] [reg offset] ([value]) \n"
);
