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

#ifndef BCM53125_SPI_FUNCTIONS_H_
#define BCM53125_SPI_FUNCTIONS_H_

#include <linux/spi/spi.h>

#define BCM53125_SPI_MAX_DATA_RW 8

int bcm53125_read_u8(struct spi_device *spiDev, u8 page, u8 reg, u8 *val);
int bcm53125_read_u16(struct spi_device *spiDev, u8 page, u8 reg, u16 *val);
int bcm53125_read_u32(struct spi_device *spiDev, u8 page, u8 reg, u32 *val);
int bcm53125_read_u48(struct spi_device *spiDev, u8 page, u8 reg, u64 *val);
int bcm53125_read_u64(struct spi_device *spiDev, u8 page, u8 reg, u64 *val);
int bcm53125_write_u8(struct spi_device *spiDev, u8 page, u8 reg, u8 val);
int bcm53125_write_u16(struct spi_device *spiDev, u8 page, u8 reg, u16 val);
int bcm53125_write_u32(struct spi_device *spiDev, u8 page, u8 reg, u32 val);
int bcm53125_write_u48(struct spi_device *spiDev, u8 page, u8 reg, u64 val);
int bcm53125_write_u64(struct spi_device *spiDev, u8 page, u8 reg, u64 val);
struct spi_device * bcm53125_spi_get_device(void);

#endif /* BCM53125_SPI_FUNCTIONS_H_ */
