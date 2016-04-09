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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <nand.h>
#include <asm/arch/register.h>
#include <malloc.h>

#include "cs75xx_nand.h"

#define OWN_DMA	0
#define OWN_SW	1
#define	SZ_32M	0x8000
#define	SZ_128M 0x20000

struct cs75xx_nand_host {
	unsigned int		chip_nr;
	unsigned int		col_addr;
	unsigned int		page_addr;
	unsigned int		index;
};

static struct cs75xx_nand_host cs75xx_host;
static struct cs75xx_nand_host *host = &cs75xx_host;

FLASH_TYPE_t			flash_type;
FLASH_STATUS_t			flash_status;
FLASH_NF_ACCESS_t		nf_access;
FLASH_NF_COUNT_t 		nf_cnt;
FLASH_NF_COMMAND_t		nf_cmd;
FLASH_NF_ADDRESS_1_t		nf_addr1;
FLASH_NF_ADDRESS_2_t		nf_addr2;
FLASH_FLASH_ACCESS_START_t	flash_start;
FLASH_NF_ECC_RESET_t		ecc_reset;
FLASH_FLASH_INTERRUPT_t		flash_int_sts;
FLASH_NF_ECC_STATUS_t		ecc_sts;
FLASH_NF_ECC_CONTROL_t		ecc_ctl;
FLASH_NF_ECC_OOB_t		ecc_oob;
FLASH_NF_ECC_GEN0_t		ecc_gen0;
FLASH_NF_BCH_CONTROL_t		bch_ctrl;
FLASH_NF_FIFO_CONTROL_t		fifo_ctl;

DMA_DMA_SSP_RXDMA_CONTROL_t		dma_rxdma_ctrl;
DMA_DMA_SSP_TXDMA_CONTROL_t		dma_txdma_ctrl;
DMA_DMA_SSP_TXQ5_CONTROL_t		dma_txq5_ctrl;
DMA_DMA_SSP_RXQ5_PKTCNT_READ_t		dma_rxq5_pktcnt_read;
DMA_DMA_SSP_TXQ5_PKTCNT_READ_t		dma_txq5_pktcnt_read;
DMA_DMA_SSP_RXQ5_BASE_DEPTH_t		dma_rxq5_base_depth;
DMA_DMA_SSP_RXQ5_WPTR_t			dma_rxq5_wptr;
DMA_DMA_SSP_RXQ5_RPTR_t			dma_rxq5_rptr;
DMA_DMA_SSP_TXQ5_BASE_DEPTH_t		dma_txq5_base_depth;
DMA_DMA_SSP_TXQ5_WPTR_t			dma_txq5_wptr;
DMA_DMA_SSP_TXQ5_RPTR_t			dma_txq5_rptr;
DMA_DMA_SSP_RXQ5_FULL_THRESHOLD_t	dma_rxq5_threshold;
DMA_DMA_SSP_RXQ5_PKTCNT_t		dma_rxq5_pktcnt;
DMA_DMA_SSP_RXQ5_FULL_DROP_PKTCNT_t	dma_rxq5_drop_pktcnt;
DMA_DMA_SSP_TXQ5_PKTCNT_t		dma_txq5_pktcnt;
DMA_DMA_SSP_DMA_SSP_INTERRUPT_0_t	dma_ssp0_intsts;
DMA_DMA_SSP_DMA_SSP_INTENABLE_0_t	dma_ssp0_int_enable;
DMA_DMA_SSP_DMA_SSP_INTERRUPT_1_t	dma_ssp1_intsts;
DMA_DMA_SSP_DMA_SSP_INTENABLE_1_t	dma_ssp1_int_enable;
DMA_DMA_SSP_DESC_INTERRUPT_t		dma_ssp_desc_intsts;
DMA_DMA_SSP_DESC_INTENABLE_t		dma_ssp_desc_int_enable;
DMA_DMA_SSP_RXQ5_INTERRUPT_t		dma_ssp_rxq5_intsts;
DMA_DMA_SSP_RXQ5_INTENABLE_t		dma_ssp_rxq5_int_enable;
DMA_DMA_SSP_TXQ5_INTERRUPT_t		dma_ssp_txq5_intsts;
DMA_DMA_SSP_TXQ5_INTENABLE_t		dma_ssp_txq5_int_enable;

DMA_SSP_TX_DESC_T			*tx_desc;
DMA_SSP_RX_DESC_T			*rx_desc;

static unsigned int *pread, *pwrite;

static unsigned int read_flash_ctrl_reg(unsigned int ofs)
{
	unsigned int *base;

	base = (unsigned int *)(ofs);
	return (*base);
}

static void write_flash_ctrl_reg(unsigned int ofs, unsigned int data)
{
	unsigned int *base;

	base = (unsigned int *)(ofs);
	*base = data;
}

static unsigned int read_dma_ctrl_reg(unsigned int ofs)
{
	unsigned int *base;

	base = (unsigned int *)(ofs);
	return (*base);
}

static void write_dma_ctrl_reg(unsigned int ofs, unsigned int data)
{
	unsigned int *base;

	base = (unsigned int *)(ofs);
	*base = data;
}

static void check_flash_ctrl_status(void)
{
	int rty=0;

	flash_status.wrd = read_flash_ctrl_reg(FLASH_STATUS);
	while (flash_status.bf.nState) {
		flash_status.wrd = read_flash_ctrl_reg(FLASH_STATUS);
		udelay(5);
		if (++rty > 50000) {
			printf("FLASH_STATUS ERROR: %x\n", flash_status.wrd);
			return;
		}
	}

}

/*
 * return register value after "(*reg) & mask == val", with timeout
 */
static unsigned int reg_wait(unsigned int regaddr, unsigned int mask, unsigned int val, int timeout)
{
	unsigned int i, tmp;

	for (i = timeout; i > 0; i--) {
		tmp = read_flash_ctrl_reg(regaddr);
		if ((tmp & mask) == val)
			return 0; //TRUE;
		udelay(5);
	}

	printf("reg_wait error !!  \n");

	return 1; //FALSE;
}

static int cs75xx_nand_dev_ready(struct mtd_info *mtd)
{
	int ready;
	FLASH_FLASH_ACCESS_START_t tmp_access;

	check_flash_ctrl_status();

	write_flash_ctrl_reg(FLASH_NF_DATA, 0xffffffff);

	do {
		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0); /** disable ecc gen**/

		nf_cnt.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_DATA_1;
		nf_cnt.bf.nflashRegAddrCount = NCNT_EMPTY_ADDR;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);

		nf_cmd.wrd = 0;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_STATUS;
		write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); /** write read id command**/
		nf_addr1.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); /** write address 0x00**/
		nf_addr2.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd); /** write address 0x00**/

		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		/** nf_access.bf.nflashDirWr = ;**/
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;

		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = FLASH_GO;
		flash_start.bf.nflashRegCmd = FLASH_RD;
		write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

		flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
		tmp_access.wrd = 0;
		tmp_access.bf.nflashRegReq = 1;
		reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

		check_flash_ctrl_status();

		ready = read_flash_ctrl_reg(FLASH_NF_DATA) & 0xff;

	} while (ready == 0xff);

	return (ready & NAND_STATUS_READY);
}

static void cs75xx_nand_select_chip(struct mtd_info *mtd, int chipnr)
{
	switch (chipnr) {
	case -1:
		host->chip_nr = NFLASH_CHIP0_EN;
		break;
	case 0:
		host->chip_nr = NFLASH_CHIP0_EN;
		break;
	case 1:
		host->chip_nr = NFLASH_CHIP1_EN;
		break;

	default:
		host->chip_nr = NFLASH_CHIP0_EN;
		/** BUG();**/
	}

}

static void cs75xx_nand_command(struct mtd_info *mtd, unsigned int command,
			 int column, int page_addr)
{
	register struct nand_chip *chip = mtd->priv;

	FLASH_FLASH_ACCESS_START_t tmp_access;

	/*
	 * Write out the command to the device.
	 */
	if (command == NAND_CMD_SEQIN) {
		if (column >= mtd->writesize) {
			/* OOB area */
			column -= mtd->writesize;
		} else if (column < 256) {
			/* First 256 bytes --> READ0 */
		} else {
			column -= 256;
		}
	}

	/*
	 * Address cycle, when necessary
	 */
	/* Serially input address */
	if (column != -1) {
		/* Adjust columns for 16 bit buswidth */
		if (chip->options & NAND_BUSWIDTH_16)
			column >>= 1;
		host->col_addr = column;
	}

	if (page_addr != -1) {
		host->page_addr = page_addr;
	}

	/*
	 * program and erase have their own busy handlers
	 * status and sequential in needs no delay
	 */
	switch (command) {

	case NAND_CMD_PAGEPROG:
	case NAND_CMD_SEQIN:
	case NAND_CMD_ERASE1:
		return;
	case NAND_CMD_ERASE2:
		check_flash_ctrl_status();

		/* Send commands to erase a page */
		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0); //

		nf_cnt.wrd = 0;
		nf_cmd.wrd = 0;
		nf_addr1.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_EMPTY_DATA;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;

		if( chip->chipsize  > (0x10000 * mtd->writesize)) {
		    nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		} else {
		    nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_2;
		}
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_ERASE1;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_ERASE2;
		nf_addr1.wrd = host->page_addr;
		nf_addr2.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
		write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd);
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd);
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		//nf_access.bf.nflashDirWr = ;
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;

		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = FLASH_GO;
		flash_start.bf.nflashRegCmd = FLASH_RD;  //no data access use read..
		write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);
		flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
		tmp_access.wrd = 0;
		tmp_access.bf.nflashRegReq = 1;
		reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);
		return;
	case NAND_CMD_STATUS:
		check_flash_ctrl_status();

		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0); //disable ecc gen

		nf_cnt.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_DATA_1;
		nf_cnt.bf.nflashRegAddrCount = NCNT_EMPTY_ADDR;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);

		nf_cmd.wrd = 0;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_STATUS;
		write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd);

		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		//nf_access.bf.nflashDirWr = ;
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
		return;

	case NAND_CMD_READID:
		ecc_reset.wrd = 0;
		ecc_reset.bf.eccClear = ECC_CLR;
		ecc_reset.bf.fifoClear = FIFO_CLR;
		ecc_reset.bf.nflash_reset = NF_RESET;
		write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

		check_flash_ctrl_status();

		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0);

		flash_type.wrd = read_flash_ctrl_reg(FLASH_TYPE);

		/*need to check extid byte counts*/
		nf_cnt.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_DATA_8;
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_1;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);

		nf_cmd.wrd = 0;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READID;
		write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd);
		nf_addr1.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd);
		nf_addr2.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

		/* read maker code */
		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

		host->index = 0;
		return;

	case NAND_CMD_RESET:
		check_flash_ctrl_status();
		udelay(chip->chip_delay);
		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0); /** disable ecc gen**/
		nf_cnt.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_EMPTY_DATA;
		nf_cnt.bf.nflashRegAddrCount = NCNT_EMPTY_ADDR;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);

		nf_cmd.wrd = 0;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_RESET;
		write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); /** write read id command**/
		nf_addr1.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); /** write address 0x00**/
		nf_addr2.wrd = 0;
		write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd); /** write address 0x00**/

		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		/** nf_access.bf.nflashDirWr = ;**/
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;

		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = FLASH_GO;
		flash_start.bf.nflashRegCmd = FLASH_WT;
		write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

		tmp_access.wrd = 0;
		tmp_access.bf.nflashRegReq = 1;
		reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);
		flash_start.wrd = read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);

		udelay(100);

		/* This applies to read commands */
	default:
		/*
		 * If we don't have access to the busy pin, we apply the given
		 * command delay
		 */
		if (!chip->dev_ready) {
			udelay(chip->chip_delay);
			return;
		}
	}
	/* Apply this short delay always to ensure that we do wait tWB in
	 * any case on any machine. */
	ndelay(100);

	nand_wait_ready(mtd);
}

static uint8_t cs75xx_nand_read_byte(struct mtd_info *mtd)
{
	unsigned int data = 0;
	FLASH_FLASH_ACCESS_START_t tmp_access;

	flash_start.wrd = 0;
	flash_start.bf.nflashRegReq = FLASH_GO;
	flash_start.bf.nflashRegCmd = FLASH_RD;
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);
	flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);

	tmp_access.wrd = 0;
	tmp_access.bf.nflashRegReq = 1;
	reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 2000);

	data = read_flash_ctrl_reg(FLASH_NF_DATA);
	return (unsigned char)((data >> ((host->index++ <<3) % 32 ) )& 0xff);
}

static int init_DMA_SSP(void)
{
	int i;
	DMA_DMA_SSP_RXDMA_CONTROL_t dma_rxdma_ctrl;
	DMA_DMA_SSP_TXDMA_CONTROL_t dma_txdma_ctrl;

	DMA_DMA_SSP_RXQ5_BASE_DEPTH_t dma_rxq5_base_depth;
	DMA_DMA_SSP_TXQ5_BASE_DEPTH_t dma_txq5_base_depth;

	dma_rxdma_ctrl.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXDMA_CONTROL);
	dma_txdma_ctrl.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXDMA_CONTROL);

	if ((dma_rxdma_ctrl.bf.rx_check_own != 1)
			&& (dma_rxdma_ctrl.bf.rx_dma_enable != 1)) {
		dma_rxdma_ctrl.bf.rx_check_own = 1;
		dma_rxdma_ctrl.bf.rx_dma_enable = 1;
		write_dma_ctrl_reg(DMA_DMA_SSP_RXDMA_CONTROL,
				dma_rxdma_ctrl.wrd);
	}
	if ((dma_txdma_ctrl.bf.tx_check_own != 1)
			&& (dma_txdma_ctrl.bf.tx_dma_enable != 1)) {
		dma_txdma_ctrl.bf.tx_check_own = 1;
		dma_txdma_ctrl.bf.tx_dma_enable = 1;
		write_dma_ctrl_reg(DMA_DMA_SSP_TXDMA_CONTROL,
				dma_txdma_ctrl.wrd);
	}

	i = 16;
	tx_desc = (DMA_SSP_TX_DESC_T *) ((u32)malloc((sizeof(DMA_SSP_TX_DESC_T) * FDMA_DESC_NUM)+ i -1) & ~(i - 1));
	rx_desc = (DMA_SSP_RX_DESC_T *) ((u32)malloc((sizeof(DMA_SSP_RX_DESC_T) * FDMA_DESC_NUM)+ i -1) & ~(i - 1));
	//(void *)(((u32)malloc(size + align) + align - 1) & ~(align - 1));
	if (!rx_desc || !tx_desc) {
		printk("Buffer allocation for failed!\n");
		if (rx_desc) {
			kfree(rx_desc);
		}

		if (tx_desc) {
			kfree(tx_desc);
		}

		return 0;
	}

	/* printk("tx_desc_v: %p , rx_desc_v: %p \n", tx_desc, rx_desc); */
	/* set base address and depth */

	dma_rxq5_base_depth.bf.base = ((unsigned int)rx_desc) >> 4;
	dma_rxq5_base_depth.bf.depth = FDMA_DEPTH;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_BASE_DEPTH,
			dma_rxq5_base_depth.wrd);

	dma_txq5_base_depth.bf.base = ((unsigned int)tx_desc) >> 4;
	dma_txq5_base_depth.bf.depth = FDMA_DEPTH;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_BASE_DEPTH,
			dma_txq5_base_depth.wrd);

	memset((unsigned char *)tx_desc, 0,
			(sizeof(DMA_SSP_TX_DESC_T) * FDMA_DESC_NUM));
	memset((unsigned char *)rx_desc, 0,
			(sizeof(DMA_SSP_RX_DESC_T) * FDMA_DESC_NUM));

	for (i = 0; i < FDMA_DESC_NUM; i++) {
		/* set own by sw */
		tx_desc[i].word0.bf.own = OWN_SW;
		/* enable q5 Scatter-Gather memory copy */
		tx_desc[i].word0.bf.sgm_rsrvd = 0x15;
	}

	return 1;
}

static int cs75xx_nand_wait(struct mtd_info *mtd, struct nand_chip *this)
{
	unsigned long	timeo;
	int state = this->state;

	if (state == FL_ERASING)
		timeo = (CONFIG_SYS_HZ * 400) / 1000;
	else
		timeo = (CONFIG_SYS_HZ * 20) / 1000;

	if ((state == FL_ERASING) && (this->options & NAND_IS_AND))
		this->cmdfunc(mtd, NAND_CMD_STATUS_MULTI, -1, -1);
	else
		this->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);

	/** reset_timer(); **/
	timeo += get_timer(0);

	while (1) {
		if (get_timer(0) > timeo) {
			printf("Timeout!");
			return 0x01;
		}

		if (this->dev_ready) {
			if (this->dev_ready(mtd))
				break;
		}
	}

	state = read_flash_ctrl_reg(FLASH_NF_DATA) & 0xff;
	return state;
}

static int cs75xx_nand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
			      uint8_t *buf, int oob_required, int page)
{
	unsigned int *addr;
	DMA_DMA_SSP_RXQ5_INTERRUPT_t	tmp_dma_ssp_rxq5_intsts;
	DMA_DMA_SSP_TXQ5_INTERRUPT_t	tmp_dma_ssp_txq5_intsts;
	FLASH_FLASH_ACCESS_START_t tmp_access;
	/** chip->read_buf(mtd, buf, mtd->writesize);
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize); **/

	check_flash_ctrl_status();

	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = ECC_CLR;
	ecc_reset.bf.fifoClear = FIFO_CLR;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	flash_int_sts.bf.regIrq = 1;
	write_flash_ctrl_reg(FLASH_FLASH_INTERRUPT, flash_int_sts.wrd);

	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = 1;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	bch_ctrl.wrd = 0;
	write_flash_ctrl_reg(FLASH_NF_BCH_CONTROL, bch_ctrl.wrd);

	ecc_ctl.wrd = 0;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);

	/** disable txq5**/
	dma_txq5_ctrl.bf.txq5_en = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
	dma_ssp_txq5_intsts.bf.txq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);
	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	/** for indirect access with DMA, because DMA not ready	**/
	nf_cnt.wrd = 0;
	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_addr2.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize -1 ;
	nf_cnt.bf.nflashRegDataCount = mtd->writesize-1;

	if(chip->chipsize < (32 << 20)) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		nf_addr1.wrd = (((page & 0x00ffffff)<<8));
		nf_addr2.wrd = ((page & 0xff000000)>>24);
	}
	else if((chip->chipsize >= (32 << 20)) && (chip->chipsize <= (128 << 20))) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;

		if(mtd->writesize > NCNT_512P_DATA) {
			nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
			nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		}
		nf_addr1.wrd = (((page & 0xffff)<<16));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}
	else /** if((chip->chipsize > (128 << 20)) )) **/ {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		nf_addr1.wrd = (((page & 0xffff)<<16));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); /** write read id command**/
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); /** write address 0x0**/
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	nf_access.wrd = 0;
	nf_access.bf.nflashCeAlt = host->chip_nr;
	nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
	/** 	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
	prepare dma descriptor
	nf_access.wrd = read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	**/
	nf_access.bf.nflashExtAddr = ((page << chip->page_shift) / 0x8000000);
	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	addr =  (unsigned int *)((page << chip->page_shift) % 0x8000000);
	addr = (unsigned int *)((unsigned int)addr + (unsigned int)(CONFIG_SYS_FLASH_BASE) );

	/** printf("%s : addr : %p  buf: %p",__func__, addr, buf);
	chip->buffers->databuf
	page tx data desc
	**/
	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);

	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->writesize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)addr;

	/** oob tx desc **/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;

	addr = (unsigned int *)((unsigned int)addr + mtd->writesize);
	/** printf("   oob : addr (%p)  chip->oob_poi (%p) \n", addr, chip->oob_poi); **/
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)addr;

	/** page data rx desc **/
	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->writesize;

	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)(buf);

	/** oob rx desc **/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr =  (unsigned int)(chip->oob_poi);

	/** dma_map_single( NULL, (void *)chip->oob_poi, mtd->oobsize,  DMA_FROM_DEVICE);
	dma_map_single( NULL, (void *)buf, mtd->writesize, DMA_FROM_DEVICE);

	set axi_bus_len = 8

	set fifo control
	**/
	fifo_ctl.wrd = 0;
	fifo_ctl.bf.fifoCmd = FLASH_RD;
	write_flash_ctrl_reg(FLASH_NF_FIFO_CONTROL, fifo_ctl.wrd);

	flash_start.wrd = 0;
	flash_start.bf.fifoReq = FLASH_GO;
	/** flash_start.bf.nflashRegCmd = FLASH_RD;**/
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

	/** update tx write ptr **/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);
	/** dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);

	enable txq5
	**/
	dma_txq5_ctrl.bf.txq5_en = 1;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	/** static UINT32 reg_wait(UINT32 regaddr, UINT32 mask, UINT32 val, int timeout)**/
	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	tmp_access.wrd = 0;
	tmp_access.bf.fifoReq = 1;
	reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

	/**
	  ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);
	  while(!ecc_sts.bf.eccDone)
	  {
	  ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);
	  udelay(1);

	  }

	  write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0);

	 **/

	/** update rx read ptr**/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR, dma_rxq5_rptr.wrd);

	return 0;
}

static int cs75xx_nand_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
				const uint8_t *buf, int oob_required)
{
	int page;
	/** uint8_t *ecc_calc = chip->buffers->ecccalc;**/
	uint32_t *addr;
	DMA_DMA_SSP_RXQ5_INTERRUPT_t	tmp_dma_ssp_rxq5_intsts;
	DMA_DMA_SSP_TXQ5_INTERRUPT_t	tmp_dma_ssp_txq5_intsts;
	FLASH_FLASH_ACCESS_START_t tmp_access;

	check_flash_ctrl_status();

	/** chip->write_buf(mtd, buf, mtd->writesize);
	chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
	**/
	page = host->page_addr;

	ecc_reset.wrd = 3;
	ecc_reset.bf.eccClear = ECC_CLR;
	ecc_reset.bf.fifoClear = FIFO_CLR;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	flash_int_sts.bf.regIrq = 1;
	write_flash_ctrl_reg(FLASH_FLASH_INTERRUPT, flash_int_sts.wrd);

	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = 1;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	/**  Disable ECC function**/
	bch_ctrl.wrd = 0;
	write_flash_ctrl_reg(FLASH_NF_BCH_CONTROL, bch_ctrl.wrd);
	ecc_ctl.wrd = 0;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);

	/** disable txq5 **/
	dma_txq5_ctrl.bf.txq5_en = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);
	/** clr tx/rx eof **/
	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
/** 	dma_ssp_txq5_intsts.bf.txq5_eof = 0;**/
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);
	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
/** 	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0; **/
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	nf_cnt.wrd = 0;
	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_addr2.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize - 1;
	nf_cnt.bf.nflashRegDataCount = mtd->writesize-1;

	if(chip->chipsize < (32 << 20)) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0x00ffffff)<<8));
		nf_addr2.wrd = ((page & 0xff000000)>>24);

	} else if((chip->chipsize >= (32 << 20)) && (chip->chipsize <= (128 << 20))) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) );
		nf_addr2.wrd = ((page & 0xffff0000)>>16);

	} else /** if((chip->chipsize > (128 << 20)) )) **/ {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) );
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd);
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd);
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	/** dma_map_single( NULL, (void *)buf, mtd->writesize, DMA_TO_DEVICE);**/

	nf_access.wrd = 0;
	nf_access.bf.nflashCeAlt = host->chip_nr;
	nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
	/** write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	write
	prepare dma descriptor
	chip->buffers->databuf
	nf_access.wrd = read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	**/
	nf_access.bf.nflashExtAddr = ((page << chip->page_shift) / 0x8000000);
	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	addr =  (unsigned int *)((page << chip->page_shift) % 0x8000000);
	addr = (unsigned int *)((unsigned int)addr + (unsigned int)(CONFIG_SYS_FLASH_BASE) );

	/** page data tx desc **/
	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->writesize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)(buf);

	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->writesize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)addr;

	/** oob rx desc**/
	addr = (unsigned int *)((unsigned int)addr + mtd->writesize);
	/** printf("  oob : addr(%p)  chip->oob_poi(%p) \n",addr, chip->oob_poi);**/

	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)addr;

	/** update page tx write ptr **/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);
	/** set axi_bus_len = 8
	set fifo control
	**/
	fifo_ctl.wrd = 0;
	fifo_ctl.bf.fifoCmd = FLASH_WT;
	write_flash_ctrl_reg(FLASH_NF_FIFO_CONTROL, fifo_ctl.wrd);

	flash_start.wrd = 0;
	flash_start.bf.fifoReq = FLASH_GO;
	/** flash_start.bf.nflashRegCmd = FLASH_WT; **/
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

	/** enable txq5**/
	dma_txq5_ctrl.bf.txq5_en = 1;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	/** static UINT32 reg_wait(UINT32 regaddr, UINT32 mask, UINT32 val, int timeout) **/
	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	/** clr tx/rx eof **/

	dma_ssp_txq5_intsts.bf.txq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);

	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	/**
	//prepare dma descriptor
	//chip->buffers->databuf

	//set axi_bus_len = 8
	//set fifo control

	  fifo_ctl.wrd = 0;
	  fifo_ctl.bf.fifoCmd = FLASH_WT;
	  write_flash_ctrl_reg(FLASH_NF_FIFO_CONTROL, fifo_ctl.wrd);
	//
	flash_start.wrd = 0;
	flash_start.bf.fifoReq = FLASH_GO;
	//flash_start.bf.nflashRegCmd = FLASH_WT;
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

	flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	while(flash_start.bf.fifoReq)
	{
	flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	udelay(1);

	}
	 **/

	/** dma_map_single( NULL, (void *)chip->oob_poi, mtd->oobsize,  DMA_TO_DEVICE);

	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);
	**/
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)(chip->oob_poi);

	/** dma_cache_sync(NULL, chip->oob_poi, mtd->oobsize, DMA_BIDIRECTIONAL);
	update tx write ptr
	**/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);

	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	tmp_access.wrd = 0;
	tmp_access.bf.fifoReq = 1;
	reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

	/** update rx read ptr
	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	**/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR, dma_rxq5_rptr.wrd);

	/** chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
	**/

	return 0;
}

static int cs75xx_nand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
				uint8_t *buf, int oob_required, int page)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *p = buf;
	/*uint8_t *ecc_calc = chip->buffers->ecccalc;*/
	uint8_t *ecc_code = chip->buffers->ecccode;
	uint32_t *eccpos = chip->ecc.layout->eccpos, *addr;;
	DMA_DMA_SSP_RXQ5_INTERRUPT_t	tmp_dma_ssp_rxq5_intsts;
	DMA_DMA_SSP_TXQ5_INTERRUPT_t	tmp_dma_ssp_txq5_intsts;
	FLASH_FLASH_ACCESS_START_t tmp_access;
	FLASH_NF_ECC_STATUS_t	tmp_ecc_sts;

	check_flash_ctrl_status();

	p = buf;
	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = ECC_CLR;
	ecc_reset.bf.fifoClear = FIFO_CLR;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	flash_int_sts.bf.regIrq = 1;
	write_flash_ctrl_reg(FLASH_FLASH_INTERRUPT, flash_int_sts.wrd);

	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = 1;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	ecc_ctl.wrd = 0;
	if((eccsize-1) == NCNT_512P_DATA)
		ecc_ctl.bf.eccGenMode = ECC_GEN_512;
	else
		ecc_ctl.bf.eccGenMode = ECC_GEN_256;
	ecc_ctl.bf.eccEn = ECC_ENABLE;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);

	/*disable txq5*/
	dma_txq5_ctrl.bf.txq5_en = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
	dma_ssp_txq5_intsts.bf.txq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);
	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	/*for indirect access with DMA, because DMA not ready	*/
	nf_cnt.wrd = 0;
	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_addr2.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize - 1;
	nf_cnt.bf.nflashRegDataCount = mtd->writesize-1;

	if(chip->chipsize < (32 << 20))
	{
	nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		nf_addr1.wrd = (((page & 0x00ffffff)<<8));
		nf_addr2.wrd = ((page & 0xff000000)>>24);
	}
	else if((chip->chipsize >= (32 << 20)) && (chip->chipsize <= (128 << 20)))
	{
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;

		if(mtd->writesize > NCNT_512P_DATA) {
			nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
			nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		}
		nf_addr1.wrd = (((page & 0xffff)<<16));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}
	else /*if((chip->chipsize > (128 << 20)) ))*/
	{
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		nf_addr1.wrd = (((page & 0xffff)<<16));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); /*write read id command*/
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); /*write address 0x0*/
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	nf_access.wrd = 0;
	nf_access.bf.nflashCeAlt = host->chip_nr;
	nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
	/*	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);
	prepare dma descriptor
	nf_access.wrd = read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	*/
	nf_access.bf.nflashExtAddr = ((page << chip->page_shift) / 0x8000000);
	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	addr =  (unsigned int *)((page << chip->page_shift) % 0x8000000);
	addr = (unsigned int *)((unsigned int)addr + (unsigned int)(CONFIG_SYS_FLASH_BASE) );

	/*printf("%s : addr : %p  buf: %p",__func__, addr, buf);
	chip->buffers->databuf
	page tx data desc
	*/
	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);

	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->writesize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)addr;

	/*oob tx desc*/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;

	addr = (unsigned int *)((unsigned int)addr + mtd->writesize);
	/*printf("   oob : addr (%p)  chip->oob_poi (%p) \n", addr, chip->oob_poi);*/
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)addr;

	/*page data rx desc*/
	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->writesize;

	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)(buf);

	/*oob rx desc*/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr =  (unsigned int)(chip->oob_poi);

	/*dma_map_single( NULL, (void *)chip->oob_poi, mtd->oobsize, DMA_FROM_DEVICE);
	dma_map_single( NULL, (void *)buf, mtd->writesize, DMA_FROM_DEVICE);

	set axi_bus_len = 8

	set fifo control
	*/
	fifo_ctl.wrd = 0;
	fifo_ctl.bf.fifoCmd = FLASH_RD;
	write_flash_ctrl_reg(FLASH_NF_FIFO_CONTROL, fifo_ctl.wrd);

	flash_start.wrd = 0;
	flash_start.bf.fifoReq = FLASH_GO;
	/*flash_start.bf.nflashRegCmd = FLASH_RD;*/
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

	/*update tx write ptr*/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);
	/*dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);

	enable txq5
	*/
	dma_txq5_ctrl.bf.txq5_en = 1;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	tmp_access.wrd = 0;
	tmp_access.bf.fifoReq = 1;
	reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

	/**
	  ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);
	  while(!ecc_sts.bf.eccDone)
	  {
	  ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);
	  udelay(1);

	  }

	  write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0);

	dma_cache_sync(NULL, buf, mtd->writesize, DMA_BIDIRECTIONAL);
	dma_cache_sync(NULL, chip->oob_poi, mtd->oobsize, DMA_BIDIRECTIONAL);
	update rx read ptr
	**/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR, dma_rxq5_rptr.wrd);

	ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);

	tmp_ecc_sts.wrd = 0;
	tmp_ecc_sts.bf.eccDone = 1;

	reg_wait(FLASH_NF_ECC_STATUS, tmp_ecc_sts.wrd , tmp_ecc_sts.wrd, 1000);

	ecc_ctl.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_CONTROL );  /**disable ecc gen**/
	ecc_ctl.bf.eccEn = 0;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);  /**disable ecc gen**/
	/**dma_cache_maint((void *)chip->oob_poi, mtd->oobsize, DMA_FROM_DEVICE);
	dma_cache_maint((void *)buf, mtd->writesize, DMA_FROM_DEVICE);
	**/

	for (i = 0; i < chip->ecc.total; i++)
		ecc_code[i] = chip->oob_poi[eccpos[i]];

	/** 	printf("ecc_code(%x) :\n",chip->ecc.total);
		for (i = 0; i < chip->ecc.total; i++)
		  printf(" %x", ecc_code[i]);
	**/
	for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		ecc_oob.wrd =	ecc_code[i] | ecc_code[i+1]<<8 | ecc_code[i+2]<<16;
		write_flash_ctrl_reg(FLASH_NF_ECC_OOB, ecc_oob.wrd);

		ecc_ctl.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_CONTROL);
		ecc_ctl.bf.eccCodeSel = (i/eccbytes);
		write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);

		ecc_sts.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);

		switch(ecc_sts.bf.eccStatus)
		{
			case ECC_NO_ERR:
				/** printf("ECC no error!!\n");**/
				break;
			case ECC_1BIT_DATA_ERR:
				/* flip the bit */
				p[ecc_sts.bf.eccErrByte] ^= (1 << ecc_sts.bf.eccErrBit);
				/** printf("ecc_code- %x (%x) :\n",i ,chip->ecc.total);**/
				ecc_gen0.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_GEN0 + (4*(i/eccbytes)));
				/** for (i = 0; i < chip->ecc.total; i++)
				  printf(" %x", ecc_code[i]);
				**/
				printf("\nECC one bit data error(%x)!!(org: %x) HW(%xs) page(%x)\n", (i/eccbytes),ecc_oob.wrd, ecc_gen0.wrd, page);
				break;
			case ECC_1BIT_ECC_ERR:
				/** printf("ecc_code- %x (%x) :\n",i ,chip->ecc.total);**/
				ecc_gen0.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_GEN0 + (4*(i/eccbytes)));
				/** for (i = 0; i < chip->ecc.total; i++)
				  printf(" %x", ecc_code[i]);
				**/
				printf("\nECC one bit ECC error(%x)!!(org: %x) HW(%xs) page(%x)\n", (i/eccbytes), ecc_oob.wrd, ecc_gen0.wrd, page);
				break;
			case ECC_UNCORRECTABLE:
				mtd->ecc_stats.failed++;
				ecc_gen0.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_GEN0 + (4*(i/eccbytes)));
				/** printf("ecc_code- %x (%x) :\n",i ,chip->ecc.total);
				for (i = 0; i < chip->ecc.total; i++)
				  printf(" %x", ecc_code[i]);
				**/
				printf("\nECC uncorrectable error(%x)!!(org: %x) HW(%xs) page(%x)\n", (i/eccbytes), ecc_oob.wrd, ecc_gen0.wrd, page);
				break;
		}

	}

	return 0;
}

static int cs75xx_nand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
				  const uint8_t *buf, int oob_required)
{

	int i, j, eccsize = chip->ecc.size, page;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	/*uint8_t *ecc_calc = chip->buffers->ecccalc;*/
	/*const uint8_t *p = buf;*/
	uint32_t *eccpos = chip->ecc.layout->eccpos, *addr;
	DMA_DMA_SSP_RXQ5_INTERRUPT_t	tmp_dma_ssp_rxq5_intsts;
	DMA_DMA_SSP_TXQ5_INTERRUPT_t	tmp_dma_ssp_txq5_intsts;
	FLASH_FLASH_ACCESS_START_t 	tmp_access;
	FLASH_NF_ECC_STATUS_t		tmp_ecc_sts;

	check_flash_ctrl_status();

	page = host->page_addr;

	ecc_reset.wrd = 3;
	ecc_reset.bf.eccClear = ECC_CLR;
	ecc_reset.bf.fifoClear = FIFO_CLR;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	flash_int_sts.bf.regIrq = 1;
	write_flash_ctrl_reg(FLASH_FLASH_INTERRUPT, flash_int_sts.wrd);

	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = 1;
	write_flash_ctrl_reg(FLASH_NF_ECC_RESET, ecc_reset.wrd);

	ecc_ctl.wrd = 0;
	if((eccsize-1) == NCNT_512P_DATA)
		ecc_ctl.bf.eccGenMode = ECC_GEN_512;
	else
		ecc_ctl.bf.eccGenMode = ECC_GEN_256;
	ecc_ctl.bf.eccEn = ECC_ENABLE;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);

	/*disable txq5*/
	dma_txq5_ctrl.bf.txq5_en = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);
	/*clr tx/rx eof*/
	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
	dma_ssp_txq5_intsts.bf.txq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);
	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	nf_cnt.wrd = 0;
	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_addr2.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize - 1;
	nf_cnt.bf.nflashRegDataCount = mtd->writesize-1;

	if(chip->chipsize < (32 << 20)) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0x00ffffff)<<8));
		nf_addr2.wrd = ((page & 0xff000000)>>24);
	} else if((chip->chipsize >= (32 << 20)) && (chip->chipsize <= (128 << 20))) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) );
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	} else /*if((chip->chipsize > (128 << 20)) ))*/ {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) );
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd);
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd);
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	/*dma_map_single( NULL, (void *)buf, mtd->writesize, DMA_TO_DEVICE);*/

	nf_access.wrd = 0;
	nf_access.bf.nflashCeAlt = host->chip_nr;
	nf_access.bf.nflashRegWidth = NFLASH_WIDTH8;
	/*write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	write
	prepare dma descriptor
	chip->buffers->databuf
	nf_access.wrd = read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);
	*/
	nf_access.bf.nflashExtAddr = ((page << chip->page_shift) / 0x8000000);
	write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

	addr =  (unsigned int *)((page << chip->page_shift) % 0x8000000);
	addr = (unsigned int *)((unsigned int)addr + (unsigned int)(CONFIG_SYS_FLASH_BASE) );

	/*page data tx desc*/
	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->writesize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)(buf);

	/*page data rx desc
	printf("cs75xx_nand_write_page_hwecc : addr : %p  buf: %p",addr, buf);
	*/

	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->writesize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)addr;

	/*oob rx desc*/
	addr = (unsigned int *)((unsigned int)addr + mtd->writesize);
	/*printf("  oob : addr(%p)  chip->oob_poi(%p) \n",addr, chip->oob_poi);*/

	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.own = OWN_DMA;
	rx_desc[dma_rxq5_rptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	rx_desc[dma_rxq5_rptr.bf.index].buf_adr = (unsigned int)addr;

	/*update page tx write ptr*/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);
	/*set axi_bus_len = 8
	set fifo control*/
	fifo_ctl.wrd = 0;
	fifo_ctl.bf.fifoCmd = FLASH_WT;
	write_flash_ctrl_reg(FLASH_NF_FIFO_CONTROL, fifo_ctl.wrd);

	flash_start.wrd = 0;
	flash_start.bf.fifoReq = FLASH_GO;
	/*flash_start.bf.nflashRegCmd = FLASH_WT;*/
	write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

	/*enable txq5*/
	dma_txq5_ctrl.bf.txq5_en = 1;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_CONTROL, dma_txq5_ctrl.wrd);

	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	/*clr tx/rx eof*/

	dma_ssp_txq5_intsts.bf.txq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT, dma_ssp_txq5_intsts.wrd);

	dma_ssp_rxq5_intsts.bf.rxq5_eof = 0;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT, dma_ssp_rxq5_intsts.wrd);

	ecc_sts.wrd=read_flash_ctrl_reg(FLASH_NF_ECC_STATUS);
	tmp_ecc_sts.wrd = 0;
	tmp_ecc_sts.bf.eccDone = 1;

	reg_wait(FLASH_NF_ECC_STATUS, tmp_ecc_sts.wrd , tmp_ecc_sts.wrd, 1000);

	ecc_ctl.wrd = read_flash_ctrl_reg( FLASH_NF_ECC_CONTROL);
	ecc_ctl.bf.eccEn= 0;
	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, ecc_ctl.wrd);  /*disable ecc gen*/

	for (i = 0,j = 0; eccsteps; eccsteps--, i++, j += eccbytes) {
		ecc_gen0.wrd = read_flash_ctrl_reg(FLASH_NF_ECC_GEN0 + 4*i);
		chip->oob_poi[eccpos[j]] = ecc_gen0.wrd & 0xff;
		chip->oob_poi[eccpos[j+1]] = (ecc_gen0.wrd >> 8) & 0xff;
		chip->oob_poi[eccpos[j+2]] = (ecc_gen0.wrd >> 16) & 0xff;
	}

	/*dma_map_single( NULL, (void *)chip->oob_poi, mtd->oobsize, DMA_TO_DEVICE);

	dma_txq5_wptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR);
	*/
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.own = OWN_DMA;
	tx_desc[dma_txq5_wptr.bf.index].word0.bf.buf_size = mtd->oobsize;
	tx_desc[dma_txq5_wptr.bf.index].buf_adr = (unsigned int)(chip->oob_poi);

	/*dma_cache_sync(NULL, chip->oob_poi, mtd->oobsize, DMA_BIDIRECTIONAL);
	update tx write ptr
	*/
	dma_txq5_wptr.bf.index = (dma_txq5_wptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_WPTR, dma_txq5_wptr.wrd);

	dma_ssp_rxq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_INTERRUPT);
	tmp_dma_ssp_rxq5_intsts.wrd = 0;
	tmp_dma_ssp_rxq5_intsts.bf.rxq5_eof = 1;

	reg_wait(DMA_DMA_SSP_RXQ5_INTERRUPT, tmp_dma_ssp_rxq5_intsts.wrd , tmp_dma_ssp_rxq5_intsts.wrd, 1000);

	dma_ssp_txq5_intsts.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_TXQ5_INTERRUPT);
	tmp_dma_ssp_txq5_intsts.wrd = 0;
	tmp_dma_ssp_txq5_intsts.bf.txq5_eof = 1;

	reg_wait(DMA_DMA_SSP_TXQ5_INTERRUPT, tmp_dma_ssp_txq5_intsts.wrd , tmp_dma_ssp_txq5_intsts.wrd, 1000);

	flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);

	tmp_access.wrd = 0;
	tmp_access.bf.fifoReq = 1;
	reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

	/*update rx read ptr
	dma_rxq5_rptr.wrd = read_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR);
	*/
	dma_rxq5_rptr.bf.index = (dma_rxq5_rptr.bf.index + 1) % FDMA_DESC_NUM;
	write_dma_ctrl_reg(DMA_DMA_SSP_RXQ5_RPTR, dma_rxq5_rptr.wrd);

	/*chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);*/
	return 0;
}

static int cs75xx_nand_read_oob_std(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
	int i;
	FLASH_FLASH_ACCESS_START_t tmp_access;

	check_flash_ctrl_status();

	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0); //disable ecc gen

	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_addr2.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize -1 ;
	nf_cnt.bf.nflashRegDataCount = NCNT_EMPTY_DATA;

	if(chip->chipsize < (32 << 20)) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		if(mtd->writesize > NCNT_512P_DATA)
			nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		else
			nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READOOB;

		nf_addr1.wrd = ((page & 0x00ffffff)<<8);
		nf_addr2.wrd = ((page & 0xff000000)>>24);
	}
	else if((chip->chipsize >= (32 << 20)) && (chip->chipsize <= (128 << 20))) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;

		// Jeneng
		if(mtd->writesize > NCNT_512P_DATA){
			nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
			nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		}
		nf_addr1.wrd = (((page & 0xffff)<<16) + (mtd->writesize&0xffff));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);

	} else /*if((chip->chipsize > (128 << 20)) ))*/ {

		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READ0;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_READSTART;
		nf_addr1.wrd = (((page & 0xffff)<<16) + (mtd->writesize&0xffff));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);
	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); //write read id command
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); //write address 0x0
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	pread = (unsigned int *) chip->oob_poi;

	for(i=0;i< mtd->oobsize/4;i++)
	{
		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		//nf_access.bf.nflashDirWr = ;
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH32;
		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = FLASH_GO;
		flash_start.bf.nflashRegCmd = FLASH_RD;
		//flash_start.bf.nflash_random_access = RND_ENABLE;
		write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

		flash_start.wrd=read_flash_ctrl_reg(FLASH_FLASH_ACCESS_START);

		tmp_access.wrd = 0;
		tmp_access.bf.nflashRegReq = 1;
		reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

			pread[i] = read_flash_ctrl_reg(FLASH_NF_DATA);

	}
	return 0;
}

static int cs75xx_nand_write_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
			      int page)
{
	int status = 0, i;
	FLASH_FLASH_ACCESS_START_t tmp_access;
	//const uint8_t *buf = chip->oob_poi;
	//int length = mtd->oobsize;

	check_flash_ctrl_status();

	chip->cmdfunc(mtd, NAND_CMD_SEQIN, mtd->writesize, page);
	//chip->write_buf(mtd, buf, length);
	/* Send command to program the OOB data */
	chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);

	write_flash_ctrl_reg(FLASH_NF_ECC_CONTROL, 0x0); //disable ecc gen

	nf_cmd.wrd = 0;
	nf_addr1.wrd = 0;
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = mtd->oobsize- 1;
	nf_cnt.bf.nflashRegDataCount = NCNT_EMPTY_DATA;

	nf_addr2.wrd = 0;

	if(chip->chipsize < SZ_32M ) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_3;

		if(mtd->writesize > NCNT_512P_DATA) {
			nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
			nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
			nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		} else {
			nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_3;
			nf_cmd.bf.nflashRegCmd0 = NAND_CMD_READOOB;  //??
			nf_cmd.bf.nflashRegCmd1 = NAND_CMD_SEQIN;
			nf_cmd.bf.nflashRegCmd2 = NAND_CMD_PAGEPROG;
		}
		//read oob need to add page data size to match correct oob ddress
		nf_addr1.wrd = (((page & 0x00ffffff)<<8));
		nf_addr2.wrd = ((page & 0xff000000)>>24);
	} else if(chip->chipsize <= SZ_128M ) {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_4;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) + (mtd->writesize&0xffff));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);

	} else /* if((chip->chipsize > (128 << 20)) )) */ {
		nf_cnt.bf.nflashRegAddrCount = NCNT_ADDR_5;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_2;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_SEQIN;
		nf_cmd.bf.nflashRegCmd1 = NAND_CMD_PAGEPROG;
		nf_addr1.wrd = (((page & 0xffff)<<16) + (mtd->writesize&0xffff));
		nf_addr2.wrd = ((page & 0xffff0000)>>16);

	}

	write_flash_ctrl_reg(FLASH_NF_COUNT, nf_cnt.wrd);
	write_flash_ctrl_reg(FLASH_NF_COMMAND, nf_cmd.wrd); //write read id command
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_1, nf_addr1.wrd); //write address 0x0
	write_flash_ctrl_reg(FLASH_NF_ADDRESS_2, nf_addr2.wrd);

	pwrite = (unsigned int *) chip->oob_poi;

	for(i=0;i<((mtd->oobsize/4));i++) {
		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = host->chip_nr;
		//nf_access.bf.nflashDirWr = ;
		nf_access.bf.nflashRegWidth = NFLASH_WIDTH32;
		write_flash_ctrl_reg(FLASH_NF_ACCESS, nf_access.wrd);

		write_flash_ctrl_reg(FLASH_NF_DATA,pwrite[i]);

		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = FLASH_GO;
		flash_start.bf.nflashRegCmd = FLASH_WT;
		//flash_start.bf.nflash_random_access = RND_ENABLE;
		write_flash_ctrl_reg(FLASH_FLASH_ACCESS_START, flash_start.wrd);

		tmp_access.wrd = 0;
		tmp_access.bf.nflashRegReq = 1;
		reg_wait(FLASH_FLASH_ACCESS_START, tmp_access.wrd, 0, 1000);

	}
	check_flash_ctrl_status();

	status = chip->waitfunc(mtd, chip);

	return status & NAND_STATUS_FAIL ? -EIO : 0;
}

static void cs75xx_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
}

static void cs75xx_nand_hwctl(struct mtd_info *mtd, int mode)
{
}

static int cs75xx_nand_correct_data(struct mtd_info *mtd, u_char *dat,
				 u_char *read_ecc, u_char *calc_ecc)
{
	return 0;
}

static int cs75xx_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
				  u_char *ecc_code)
{
	return 0;
}

int board_nand_init(struct nand_chip *nand)
{
	init_DMA_SSP();

	/* 5 us command delay time */
	nand->chip_delay = 20;

	nand->cmd_ctrl = cs75xx_nand_cmd_ctrl;
	nand->dev_ready = cs75xx_nand_dev_ready;
	nand->cmdfunc = cs75xx_nand_command;
	nand->select_chip = cs75xx_nand_select_chip;
	nand->read_byte = cs75xx_nand_read_byte;

	nand->ecc.mode = NAND_ECC_HW;
	nand->ecc.size = 256;
	nand->ecc.bytes = 3;
	nand->ecc.strength = 1;

	nand->ecc.calculate = cs75xx_nand_calculate_ecc;
	nand->ecc.hwctl = cs75xx_nand_hwctl;
	nand->ecc.correct = cs75xx_nand_correct_data;
	nand->ecc.read_page_raw = cs75xx_nand_read_page_raw;
	nand->ecc.write_page_raw = cs75xx_nand_write_page_raw;
	nand->ecc.read_page = cs75xx_nand_read_page_hwecc;
	nand->ecc.write_page = cs75xx_nand_write_page_hwecc;
	nand->ecc.read_oob = cs75xx_nand_read_oob_std;
	nand->ecc.write_oob = cs75xx_nand_write_oob_std;

	/* check, if a user supplied wait function given */
	nand->waitfunc = cs75xx_nand_wait;

	return 0;
}
