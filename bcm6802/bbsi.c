/*
<:label-BRCM::DUAL/GPL:standard
:>
*/

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/mii.h>
#include <linux/spi/spi.h>
#include <mach/gpio_alloc.h>
#include <asm/gpio.h>
#include "6802_map_part.h"
#include "bbsi.h"

/***************************************************************************
* File Name  : bbsi.c
*
* Description: This file contains the functions for communicating between a brcm
*              cpe chip(eg 6818) to another brcm chip(6802) which is connected
*              as a spi slave device. This protocol used to communicate is BBSI.
*
***************************************************************************/

/*********************************************************************************************************
 * Eg. configuration required for spi slave devices
 *
 * 6368: BcmSpiReserveSlave2(HS_SPI_BUS_NUM, 7, 781000, SPI_MODE_3, SPI_CONTROLLER_STATE_GATE_CLK_SSOFF);
 *
 *
 **********************************************************************************************************/
#define MOCA_STATUS_REG                 (0x06)
#define MOCA_CONFIG_REG                 (0x07)
#define MOCA_ADDR0_REG                  (0x08)
#define MOCA_DATA0_REG                  (0x0c)

#define MOCA_BBSI_READ                  0x80
#define MOCA_BBSI_WRITE                 0x81

#define MOCA_SPI_READ                   1
#define MOCA_SPI_WRITE                  0

#define BUSY_SHIFT                      0x4
#define MAX_STATUS_RETRY                256

#define bcmSpiSlaveResetGpio	pSpiDev->resetGpio
#define bcmSpiSlaveBus	 	pSpiDev->boardInfo.bus_num
#define bcmSpiSlaveId	  	pSpiDev->boardInfo.chip_select
#define bcmSpiSlaveMaxFreq	pSpiDev->boardInfo.max_speed_hz
#define bcmSpiSlaveMode		pSpiDev->boardInfo.mode
#define bcmSpiSlaveCtrState	pSpiDev->boardInfo.controller_data
#define bcmSpiSlaveDevice	pSpiDev->spiDevice
#define bcmSpiSlaveMutex 	pSpiDev->lock

typedef struct _BP_SPISLAVE_INFO {
  unsigned short resetGpio;
  struct spi_board_info boardInfo;
  struct spi_device *spiDevice;
  struct mutex lock;
} BP_SPISLAVE_INFO, *PBP_SPISLAVE_INFO;

BP_SPISLAVE_INFO pspiSlaveInfo[MAX_SPISLAVE_DEV_NUM]= {
	{
		.resetGpio	= 139,
		.boardInfo	= {
			.modalias        = "bcm_HSSpiDev0",
			.controller_data = (void *)NULL, //SPI_CONTROLLER_STATE_GATE_CLK_SSOFF,
			.chip_select     = 3,
			.max_speed_hz    = 8000000,
			.bus_num         = 0,
			.mode            = SPI_MODE_3,
		},
		.spiDevice	= NULL,
	},
	{
		.resetGpio	= 144,
		.boardInfo	= {
			.modalias        = "bcm_HSSpiDev1",
			.controller_data = (void *)NULL, //SPI_CONTROLLER_STATE_GATE_CLK_SSOFF,
			.chip_select     = 2,
			.max_speed_hz    = 8000000,
			.bus_num         = 0,
			.mode            = SPI_MODE_3,
		},
		.spiDevice	= NULL,
	},
};

static void resetSpiSlaveDevice(unsigned short resetGpio);
static int doRead(PBP_SPISLAVE_INFO pSpiDev, unsigned long addr, unsigned long *data, unsigned long len);
static int doWrite(PBP_SPISLAVE_INFO pSpiDev, unsigned long addr, unsigned long data, unsigned long len);

static int isBBSIDone(PBP_SPISLAVE_INFO pSpiDev)
{
	uint8_t read_status[2] = { BBSI_COMMAND_BYTE,// | 0x1, // Do a Read
			   STATUS_REGISTER_ADDR
	};
	uint8_t status;
	int i;
	int ret = 0;

	for (i=0; i<MAX_STATUS_RETRY; i++)
	{
		ret = spi_write_then_read(bcmSpiSlaveDevice, read_status, 2, &status, 1);
		if ( ret )
		{
			printk(KERN_ERR "isBBSIDone: BcmSpiSyncTrans returned error\n");
			ret = 0;
			break;
		}

		if (status & 0xF)
		{
			printk(KERN_ERR "isBBSIDone: BBSI transaction error, status=0x%x\n", status);
			ret = 0;
			break;
		}
		else if ( (status & (1<<BUSY_SHIFT)) == 0 )
		{
			ret = 1;
			break;
		}
	}
	return ret;
}

int kerSysBcmSpiSlaveInit(int dev)
{
	unsigned long data;
	int32_t       retVal = 0;
	int           status = SPI_STATUS_OK;
	PBP_SPISLAVE_INFO pSpiDev;

	if(dev >= MAX_SPISLAVE_DEV_NUM)
		return(SPI_STATUS_ERR);

	printk(KERN_INFO "%s called for dev %d\n", __FUNCTION__, dev);
	pSpiDev = &pspiSlaveInfo[dev];

	mutex_init(&pSpiDev->lock);

	resetSpiSlaveDevice(pSpiDev->resetGpio);

	/* crate SPI device */
	pSpiDev->spiDevice = spi_new_device(
		spi_busnum_to_master(pSpiDev->boardInfo.bus_num),
		&pSpiDev->boardInfo);
	if (NULL != pSpiDev->spiDevice)
	{
		printk(KERN_ERR "%s: BcmSpiReserveSlave2 returned error %d\n", __FUNCTION__, status);
		return(SPI_STATUS_ERR);
	}

	if ((kerSysBcmSpiSlaveRead(dev, SUN_TOP_CTRL_CHIP_FAMILY_ID, &data, 4) == -1) ||
			(data == 0) || (data == 0xffffffff))
	{
		printk(KERN_ERR "%s: Failed to read the SUN_TOP_CTRL_CHIP_FAMILY_ID: 0x%08lx\n", __FUNCTION__, data);
		return -1;
	} else {
		printk(KERN_INFO "%s: SUN_TOP_CTRL_CHIP_FAMILY_ID: 0x%08lx\n", __FUNCTION__, data);
	}

	if ((kerSysBcmSpiSlaveRead(dev, SUN_TOP_CTRL_PRODUCT_ID, &data, 4) == -1) ||
			(data == 0) || (data == 0xffffffff))
	{
		printk(KERN_ERR "%s: Failed to read the SUN_TOP_CTRL_PRODUCT_ID: 0x%08lx\n", __FUNCTION__, data);
		return -1;
	} else {
		printk(KERN_INFO "%s: SUN_TOP_CTRL_PRODUCT_ID: 0x%08lx\n", __FUNCTION__, data);
	}

	return( retVal );

}

int kerSysBcmSpiSlaveRead(int dev, unsigned long addr, unsigned long *data, unsigned long len)
{
	PBP_SPISLAVE_INFO pSpiDev;
	int ret;

	if( dev >= MAX_SPISLAVE_DEV_NUM || (pSpiDev = &pspiSlaveInfo[dev]) == NULL )
		return(-1);

	mutex_lock(&bcmSpiSlaveMutex);
	ret = doRead(pSpiDev, addr, data, len);
	mutex_unlock(&bcmSpiSlaveMutex);

	return(ret);
}


int kerSysBcmSpiSlaveWrite(int dev, unsigned long addr, unsigned long data, unsigned long len)
{
	PBP_SPISLAVE_INFO pSpiDev;
	int ret;

	if( dev >= MAX_SPISLAVE_DEV_NUM || (pSpiDev = &pspiSlaveInfo[dev]) == NULL )
		return(-1);

	mutex_lock(&bcmSpiSlaveMutex);
	ret = doWrite(pSpiDev, addr, data, len);
	mutex_unlock(&bcmSpiSlaveMutex);

	return(ret);
}

int kerSysBcmSpiSlaveReadBuf(int dev, unsigned long addr, unsigned long *data, unsigned long len, unsigned int unitSize)
{
	int ret = SPI_STATUS_ERR;
	PBP_SPISLAVE_INFO pSpiDev;

	if( dev >= MAX_SPISLAVE_DEV_NUM || (pSpiDev = &pspiSlaveInfo[dev]) == NULL )
		return(-1);

	mutex_lock(&bcmSpiSlaveMutex);

	while(len >= unitSize)
	{
		if (doRead(pSpiDev, addr, data, unitSize))
		{
			printk(KERN_ERR "kerSysBcmSpiSlaveReadBuf: read to addr:0x%lx failed\n", addr);
			ret = SPI_STATUS_ERR;
			break;
		}

		len  -= unitSize;
		addr += unitSize;
		data = (unsigned long *)( (unsigned long)data + unitSize ) ;
	}

	mutex_unlock(&bcmSpiSlaveMutex);

	return ret;
}
EXPORT_SYMBOL(kerSysBcmSpiSlaveReadBuf);

int kerSysBcmSpiSlaveWriteBuf(int dev, unsigned long addr, unsigned long *data, unsigned long len, unsigned int unitSize)
{
	int ret = SPI_STATUS_ERR;
	PBP_SPISLAVE_INFO pSpiDev;

	if( dev >= MAX_SPISLAVE_DEV_NUM || (pSpiDev = &pspiSlaveInfo[dev]) == NULL )
		return(-1);


	mutex_lock(&bcmSpiSlaveMutex);

	while(len >= unitSize)
	{
		if (doWrite(pSpiDev, addr, cpu_to_be32(*data), len))
		{
			printk(KERN_ERR "kerSysBcmSpiSlaveWriteBuf: write to addr:0x%lx failed\n", addr);
			ret = SPI_STATUS_ERR;
			break;
		}

		len  -= unitSize;
		addr += unitSize;
		data = (unsigned long *)( (unsigned long)data + unitSize ) ;
	}

	mutex_unlock(&bcmSpiSlaveMutex);

    return ret;

}
EXPORT_SYMBOL(kerSysBcmSpiSlaveWriteBuf);

unsigned long kerSysBcmSpiSlaveReadReg32(int dev, unsigned long addr)
{
	unsigned long data = 0;

	BUG_ON(addr & 3);
	addr &= 0x1fffffff;

	if(kerSysBcmSpiSlaveRead(dev, addr, &data, 4) < 0)
	{
		printk(KERN_ERR "kerSysBcmSpiSlaveReadReg32: dev %d can't read %08lx\n", dev, addr);
	}

	return be32_to_cpu(data);
}
EXPORT_SYMBOL(kerSysBcmSpiSlaveReadReg32);

void kerSysBcmSpiSlaveWriteReg32(int dev, unsigned long addr, unsigned long data)
{
	BUG_ON(addr & 3);
	addr &= 0x1fffffff;

	if(kerSysBcmSpiSlaveWrite(dev, addr, data, 4) < 0)
	{
		printk(KERN_ERR "kerSysBcmSpiSlaveWriteReg32: dev %d can't write %08lx (data %08lx)\n", dev, addr, data);
	}
}
EXPORT_SYMBOL(kerSysBcmSpiSlaveWriteReg32);

static int doRead(PBP_SPISLAVE_INFO pSpiDev, unsigned long addr, unsigned long *data, unsigned long len)
{
	u8		cmd[8];
	u8		buf[4];
	u32			i;
	int			err;
	unsigned int count = (len<4?len:4);

	cmd[0] = MOCA_BBSI_WRITE;;
	cmd[1] = MOCA_CONFIG_REG;
	cmd[2] = (4-count)<<3 | MOCA_SPI_READ;
	cmd[3] = (addr >> 24) & 0xff;
	cmd[4] = (addr >> 16) & 0xff;
	cmd[5] = (addr >>  8) & 0xff;
	cmd[6] = addr & 0xff;

	err = spi_write(bcmSpiSlaveDevice, cmd, 7);
	if (err)
		return err;

	/* Issue a Normal Read Command to read the specific registers' content
	 * placed in the SPI Data I/O register (0xF0~0xF7). */
	cmd[0] = MOCA_BBSI_READ;
	cmd[1] = MOCA_DATA0_REG;

	err = spi_write_then_read(bcmSpiSlaveDevice, cmd, 2, buf, count);
	if (err)
		return err;
	switch (count) {
	case 1:
		*(u8 *)data = buf[0];
		break;
	case 2:
		*(u16 *)data = (buf[0]<<8) + buf[1];
		break;
	case 4:
		*(u32 *)data = (buf[0]<<24)+(buf[1]<<16)+(buf[2]<<8)+buf[3];
		break;
	}

	return(0);
}

static int doWrite(PBP_SPISLAVE_INFO pSpiDev, unsigned long addr, unsigned long data, unsigned long len)
{
	uint8_t buf[12];
	int err;


	buf[0]  = BBSI_COMMAND_BYTE | 0x1;          /* Assumes write signal is 0 */
	buf[1]  = CONFIG_REGISTER_ADDR;       /* Start the writes from this addr */
	buf[2]  = (4-len) << XFER_MODE_SHIFT ; /* Indicates the transaction is 32bit, 24bit, 16bit or 8bit. Len is 1..4 */
	buf[3]  = (addr >> 24) & 0xFF;  /* Assuming MSB bytes are always sent first */
	buf[4]  = (addr >> 16) & 0xFF;
	buf[5]  = (addr >> 8)  & 0xFF;
	buf[6]  = (addr >> 0)  & 0xFF;
	buf[7]  = (data >> 24) & 0xFF;
	buf[8]  = (data >> 16) & 0xFF;
	buf[9]  = (data >> 8)  & 0xFF;
	buf[10] = (data >> 0)  & 0xFF;

	err = spi_write(bcmSpiSlaveDevice, buf, 11);
	if ( err )
	{
		printk(KERN_ERR "SPI Slave Write: BcmSpiSyncTrans returned error\n");
		return(-1);
	}

	if (!isBBSIDone(pSpiDev))
	{
		printk(KERN_ERR "SPI Slave Write: write to addr:0x%lx failed\n", addr);
		return(-1);
	}

	return(0);
}

static void resetSpiSlaveDevice(unsigned short resetGpio)
{

	if (resetGpio == 0xFF)
		return;

	gpio_request(resetGpio, resetGpio == GPIO_MOCA_WAN_RST ? "MOCA_WAN_RST" : "MOCA_LAN_RST");
	gpio_direction_output(resetGpio, 1);
	gpio_set_value(resetGpio, 1);
	mdelay(50);
	gpio_set_value(resetGpio, 0);
	mdelay(50);
	gpio_set_value(resetGpio, 1);
	mdelay(300);
}

