/*
 * (C) Copyright 2013
 * GreenWave Reality Inc. <www.greenwavereality.com>
 *
 * Based on bcm53xxx_drv
 * (C) Copyright 2013
 * Cortina-systems <www.cortina-systems.com>
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

#include "bcm53125_spi_functions.h"
#include <linux/printk.h>

#define BCM53125_CMD_READ			0x60
#define BCM53125_CMD_WRITE			0x61

#define BCM53125_SPI_STATUS			0xfe
#define BCM53125_SPI_RETRY_COUNT	0xff
#define BCM53125_SPI_SPIF			0x80
#define BCM53125_SPI_PAGE			0xff
#define BCM53125_SPI_RACK			0x20
#define BCM53125_SPI_DATA0			0xf0

#define BCM53125_SPI_BUS			0
#define BCM53125_DEVICE_ID			0x00053125

#define CHECK_ERR(func) err = func; if (err) return err

static int bcm53125_spi_setup_page(struct spi_device *spiDev, u8 page)
{
	static struct spi_message	m;
	static struct spi_transfer	t[2];
	static u8					cmd[3];
	static u8					data;
	static unsigned int			previousPage = 0xff;
	int							err = 0;
	u32							i;

	spi_message_init(&m);
	memset(&t, 0, sizeof(t));

	/* Issue a Normal Read Command to poll the SPIF bit in SPI Status Reg */
	cmd[0] = BCM53125_CMD_READ;
	cmd[1] = BCM53125_SPI_STATUS;

	for (i = 0; i < BCM53125_SPI_RETRY_COUNT; ++i) {
		t[0].tx_buf = cmd;
		t[0].len = 2;
		spi_message_add_tail(&t[0], &m);

		t[1].rx_buf = &data;
		t[1].len = sizeof(data);
		spi_message_add_tail(&t[1], &m);

		CHECK_ERR( spi_sync_locked(spiDev, &m) );

		if ((data & BCM53125_SPI_SPIF) == 0)
			break;
	}
	if (i == BCM53125_SPI_RETRY_COUNT) {
		printk("%s : SPI slave device not ready!! (SPI status = 0x%x)\n", __func__, data);
		return -ETIMEDOUT;
	}

	/* Issue a Normal Write Command to setup the accessed register page
	 * value into the SPI page register(0xFF). */
	if (page != previousPage) {
		cmd[0] = BCM53125_CMD_WRITE;
		cmd[1] = BCM53125_SPI_PAGE;
		cmd[2] = page;

		t[0].tx_buf = cmd;
		t[0].len = 3;
		spi_message_add_tail(&t[0], &m);

		CHECK_ERR( spi_sync_locked(spiDev, &m) );
		previousPage = page;
	}

	return 0;
}

static int bcm53125_spi_read(struct spi_device *spiDev, u8 page, u8 reg, void *buf, unsigned int count)
{
	static struct spi_message	m;
	static struct spi_transfer	t[2];
	static u8					cmd[2];
	static u8					b;
	int							err = 0;
	u32							i;

	if (count > BCM53125_SPI_MAX_DATA_RW) return -EOVERFLOW;

	spi_message_init(&m);
	memset(&t, 0, sizeof(t));

	CHECK_ERR( bcm53125_spi_setup_page(spiDev, page) );

	/* Issue a Normal Read Command to setup the required register address.*/
	cmd[0] = BCM53125_CMD_READ;
	cmd[1] = reg;

	t[0].tx_buf = cmd;
	t[0].len = sizeof(cmd);
	spi_message_add_tail(&t[0], &m);
	t[1].rx_buf = &b;
	t[1].len = 1;
	spi_message_add_tail(&t[1], &m);

	CHECK_ERR( spi_sync_locked(spiDev, &m) );

	/* Issue a Normal Read Command to poll the RACK bit in SPI status
	 * register(0xFE) to determine the completion of read. */
	cmd[0] = BCM53125_CMD_READ;
	cmd[1] = BCM53125_SPI_STATUS;

	for (i = 0; i < BCM53125_SPI_RETRY_COUNT; ++i) {
		t[0].tx_buf = cmd;
		t[0].len = sizeof(cmd);
		spi_message_add_tail(&t[0], &m);

		t[1].rx_buf = &b;
		t[1].len = 1;
		spi_message_add_tail(&t[1], &m);

		CHECK_ERR( spi_sync_locked(spiDev, &m) );

		if ((b & BCM53125_SPI_RACK) == BCM53125_SPI_RACK)
			break;
	}
	if (i == BCM53125_SPI_RETRY_COUNT) {
		printk("%s : No SPI RACK !!!\n", __func__);
		return -ETIMEDOUT;
	}

	/* Issue a Normal Read Command to read the specific registers' content
	 * placed in the SPI Data I/O register (0xF0~0xF7). */
	cmd[0] = BCM53125_CMD_READ;
	cmd[1] = BCM53125_SPI_DATA0;

	t[0].tx_buf = cmd;
	t[0].len = sizeof(cmd);
	spi_message_add_tail(&t[0], &m);
	t[1].rx_buf = buf;
	t[1].len = count;
	spi_message_add_tail(&t[1], &m);

	CHECK_ERR( spi_sync_locked(spiDev, &m) );

	return 0;
}

static int bcm53125_spi_write(struct spi_device *spiDev, u8 page, u8 reg, void *buf, unsigned int count)
{
	struct spi_message		m;
	struct spi_transfer 	t;
	static u8				cmd[BCM53125_SPI_MAX_DATA_RW + 2];
	int						err = 0;

	if (count > BCM53125_SPI_MAX_DATA_RW) return -EOVERFLOW;

	spi_message_init(&m);
	memset(&t, 0, sizeof(t));

	CHECK_ERR( bcm53125_spi_setup_page(spiDev, page) );

	/* Issue a Normal Write Command to setup the accessed register address
	 * value, followed by the write content starting from a low byte. */
	cmd[0] = BCM53125_CMD_WRITE;
	cmd[1] = reg;
	memcpy(&cmd[2], buf, count);

	t.tx_buf = cmd;
	t.len = count + 2;
	spi_message_add_tail(&t, &m);

	return spi_sync_locked(spiDev, &m);
}

int bcm53125_read_u8(struct spi_device *spiDev, u8 page, u8 reg, u8 *val)
{
	u8	b;
	int	err;
	CHECK_ERR( bcm53125_spi_read(spiDev, page, reg, &b, sizeof(b)) );
	*val = b;
	return 0;
}

int bcm53125_read_u16(struct spi_device *spiDev, u8 page, u8 reg, u16 *val)
{
	u8	buf[sizeof(u16)];
	int err;
	CHECK_ERR( bcm53125_spi_read(spiDev, page, reg, buf, sizeof(buf)) );
	*val = be16_to_cpup((const __be16 *)buf);
	return 0;
}

int bcm53125_read_u32(struct spi_device *spiDev, u8 page, u8 reg, u32 *val)
{
	u8	buf[sizeof(u32)];
	int	err;
	CHECK_ERR( bcm53125_spi_read(spiDev, page, reg, buf, sizeof(buf)) );
	*val = be32_to_cpup((const __be32 *)buf);
	return 0;
}

int bcm53125_read_u48(struct spi_device *spiDev, u8 page, u8 reg, u64 *val)
{
	u8	buf[sizeof(u64)];
	int	err;
	buf[0] = 0;
	buf[1] = 0;
	CHECK_ERR( bcm53125_spi_read(spiDev, page, reg, &buf[2], sizeof(buf) - 2) );
	*val = be64_to_cpup((const __be64 *)buf);
	return 0;
}

int bcm53125_read_u64(struct spi_device *spiDev, u8 page, u8 reg, u64 *val)
{
	u8	buf[sizeof(u64)];
	int	err;
	CHECK_ERR( bcm53125_spi_read(spiDev, page, reg, buf, sizeof(buf)) );
	*val = be64_to_cpup((const __be64 *)buf);
	return 0;
}

int bcm53125_write_u8(struct spi_device *spiDev, u8 page, u8 reg, u8 val)
{
	return bcm53125_spi_write(spiDev, page, reg, &val, sizeof(val));
}

int bcm53125_write_u16(struct spi_device *spiDev, u8 page, u8 reg, u16 val)
{
	u16 leVal = cpu_to_le16(val);
	return bcm53125_spi_write(spiDev, page, reg, &leVal, sizeof(leVal));
}

int bcm53125_write_u32(struct spi_device *spiDev, u8 page, u8 reg, u32 val)
{
	u32 leVal = cpu_to_le32(val);
	return bcm53125_spi_write(spiDev, page, reg, &leVal, sizeof(leVal));
}

int bcm53125_write_u48(struct spi_device *spiDev, u8 page, u8 reg, u64 val)
{
	u64 leVal = cpu_to_le64(val);
	return bcm53125_spi_write(spiDev, page, reg, &leVal, sizeof(leVal) - 2);
}

int bcm53125_write_u64(struct spi_device *spiDev, u8 page, u8 reg, u64 val)
{
	u64 leVal = cpu_to_le64(val);
	return bcm53125_spi_write(spiDev, page, reg, &leVal, sizeof(leVal));
}

struct spi_device * bcm53125_spi_get_device(void)
{
	u32 value;
	int err = 0;
	struct spi_device *spiDev = NULL;

	struct spi_master *spi_master = spi_busnum_to_master(BCM53125_SPI_BUS);
	if (!spi_master) {
		printk(KERN_ALERT "No SPI master on bus %d\n", BCM53125_SPI_BUS);
		return NULL;
	}

	spiDev = spi_alloc_device(spi_master);
	if (!spiDev) {
		printk(KERN_ALERT "spi_alloc_device() failed\n");
		goto getFailed;
	}

	spiDev->chip_select = 1;

	/* Check whether this SPI bus.cs is already claimed */
	char buff[64];
	snprintf(buff,
			 sizeof(buff),
			 "%s.%u",
			 dev_name(&spiDev->master->dev),
			 spiDev->chip_select);

	struct device *pdev = bus_find_device_by_name(spiDev->dev.bus, NULL, buff);
	if (pdev) {
		/* We are not going to use this spi_device, so free it */
		spi_dev_put(spiDev);

		spiDev = to_spi_device(pdev);
		int err = spi_setup(spiDev);
		if (err) {
			printk(KERN_ALERT "spi_setup() failed: %d\n", err);
			goto getFailed;
		}
	}
	else {
		spiDev->max_speed_hz = 8 * 1000 * 1000;
		spiDev->mode = SPI_MODE_3;
		spiDev->bits_per_word = 8;

		int err = spi_add_device(spiDev);
		if (err < 0) {
			printk(KERN_ALERT "spi_add_device() failed: %d\n", err);
			goto getFailed;
		}
	}

	/* Read device ID */
	err = bcm53125_read_u32(spiDev, 0x02, 0x30, &value);
	if (err < 0) {
		dev_err(&spiDev->dev, "unable to read id registers, err=%d\n", err);
		goto getFailed;
	}

	if (value == BCM53125_DEVICE_ID) {
		printk("%s : BCM53125 Robo Switch found.\n", __func__);
	}
	else {
		dev_err(&spiDev->dev, "unknown switch family id: 0x%08x\n", value);
		goto getFailed;
	}

	return spiDev;

getFailed:
	if (spiDev)
		spi_dev_put(spiDev);
	put_device(&spi_master->dev);
	return NULL;
}
