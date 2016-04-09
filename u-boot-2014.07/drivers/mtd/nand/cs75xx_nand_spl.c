/*
 * (C) Copyright 2014, Greenwave Systems, Inc.
 * Hoang Tran <hoang.tran@greenwavesystems.com>
 *
 * based on nand_spl_simple code
 *
 */

#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/arch/register.h>
#include <malloc.h>

#include "cs75xx_nand.h"

#define NF_START_BCNT		2000
#define NF_STS_PCNT		20000
#define NF_STS_MSK		0xF00
#define NF_STS_VAL		0

#define REG32(addr)     (*(volatile unsigned long * const)(addr))

#define ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / \
					CONFIG_SYS_NAND_ECCSIZE)
#define ECCTOTAL	(ECCSTEPS * CONFIG_SYS_NAND_ECCBYTES)

static int nand_ecc_pos[] = CONFIG_SYS_NAND_ECCPOS;
static nand_info_t mtd;
static struct nand_chip nand_chip;

static unsigned int reg_wait(unsigned int regaddr, unsigned int mask, unsigned int val, int timeout)
{
	unsigned int i, tmp;

	for (i = timeout; i > 0; i--) {
		tmp = REG32(regaddr);
		if ((tmp & mask) == val)
			return 1;
	}

	return 0;
}

void flash_reset(void)
{
	FLASH_NF_ACCESS_t	nf_access;
	FLASH_NF_ECC_RESET_t	nf_ecc_reset;

	nf_access.wrd = 0;
	nf_access.bf.autoReset = 1;
	REG32(FLASH_NF_ACCESS) = nf_access.wrd;

	nf_ecc_reset.wrd = 0;
	nf_ecc_reset.bf.nflash_reset = 1;
	REG32(FLASH_NF_ECC_RESET) = nf_ecc_reset.wrd;

	reg_wait(FLASH_NF_ECC_RESET, nf_ecc_reset.wrd, 0, NF_START_BCNT);
}

static int dev_ready(void)
{
	int ready, i;
	FLASH_FLASH_ACCESS_START_t flash_start, flash_start_msk;
	FLASH_NF_COUNT_t	nf_cnt;
	FLASH_NF_COMMAND_t	nf_cmd;
	FLASH_NF_ADDRESS_1_t	nf_addr1;
	FLASH_NF_ACCESS_t	nf_access;

	if (!reg_wait(FLASH_STATUS, NF_STS_MSK, NF_STS_VAL, NF_STS_PCNT))
		flash_reset();

	REG32(FLASH_NF_DATA) = 0xffffffff;

	//retry 50 times to read status
	for (i = 2000; i > 0; i--) {
		REG32(FLASH_NF_ECC_CONTROL) =  0x0; //disable ecc gen
		nf_cnt.wrd = 0;
		nf_cnt.bf.nflashRegOobCount = NCNT_EMPTY_OOB;
		nf_cnt.bf.nflashRegDataCount = NCNT_DATA_1;
		nf_cnt.bf.nflashRegAddrCount = NCNT_EMPTY_ADDR;
		nf_cnt.bf.nflashRegCmdCount = NCNT_CMD_1;

		REG32(FLASH_NF_COUNT) = nf_cnt.wrd;

		nf_cmd.wrd = 0;
		nf_cmd.bf.nflashRegCmd0 = NAND_CMD_STATUS;
		REG32(FLASH_NF_COMMAND) = nf_cmd.wrd; //write command
		nf_addr1.wrd = 0;
		REG32(FLASH_NF_ADDRESS_1) =  nf_addr1.wrd; //write address 0x00

		nf_access.wrd = 0;
		nf_access.bf.nflashCeAlt = 0;
		//nf_access.bf.nflashDirWr = ;
		nf_access.bf.nflashRegWidth = 0;

		REG32(FLASH_NF_ACCESS) = nf_access.wrd;
		flash_start.wrd = 0;
		flash_start.bf.nflashRegReq = 1;
		flash_start.bf.nflashRegCmd = 2;
		REG32(FLASH_FLASH_ACCESS_START) = flash_start.wrd;

		flash_start_msk.wrd = 0;
		flash_start_msk.bf.nflashRegReq = 1;
		if (!reg_wait(FLASH_FLASH_ACCESS_START, flash_start_msk.wrd, 0, NF_START_BCNT))
			flash_reset();

		// check I/O 6 Ready/Busy Ready/Busy Ready/Busy Busy : "0" Ready : "1"
      		ready = REG32(FLASH_NF_DATA) & 0xff;
      		if (ready != 0xff)
			return (ready & STS_READY);
	}

	return 0;
}

static int nand_is_bad_block(int block)
{
#if 0
	struct nand_chip *this = mtd.priv;

	nand_command(block, 0, CONFIG_SYS_NAND_BAD_BLOCK_POS,
		NAND_CMD_READOOB);

	/*
	 * Read one byte (or two if it's a 16 bit chip).
	 */
	if (this->options & NAND_BUSWIDTH_16) {
		if (readw(this->IO_ADDR_R) != 0xffff)
			return 1;
	} else {
		if (readb(this->IO_ADDR_R) != 0xff)
			return 1;
	}
#endif

	return 0;
}

static int nand_read_page(int block, int page, void *dst)
{
	int i;
	u_char ecc_code[ECCTOTAL];
	u_char oob_data[CONFIG_SYS_NAND_OOBSIZE];
	unsigned char *p = dst;
	unsigned char *page_add;

	FLASH_NF_COUNT_t	nf_cnt;
	FLASH_NF_ECC_RESET_t ecc_reset;
	FLASH_NF_ECC_CONTROL_t	ecc_ctl;
	FLASH_NF_ECC_STATUS_t	ecc_sts, ecc_sts_msk;
	FLASH_NF_ECC_OOB_t	ecc_oob;

	page_add = (unsigned char*)(CONFIG_SYS_NAND_BASE + (block * CONFIG_SYS_NAND_BLOCK_SIZE) + (page * CONFIG_SYS_NAND_PAGE_SIZE));

	while (!dev_ready())
		;

	if (!reg_wait(FLASH_STATUS, NF_STS_MSK, NF_STS_VAL, NF_STS_PCNT))
		flash_reset();

	//ecc reset
	ecc_reset.wrd = 0;
	ecc_reset.bf.eccClear = ECC_CLR;
	ecc_reset.bf.fifoClear = 1;
	REG32(FLASH_NF_ECC_RESET) = ecc_reset.wrd;

	ecc_ctl.wrd = 0;
	ecc_ctl.bf.eccGenMode = 0;	//256 bytes boundary
	ecc_ctl.bf.eccEn = 1;
	REG32(FLASH_NF_ECC_CONTROL) =  ecc_ctl.wrd;

	//set oob size
	nf_cnt.wrd = 0;
	nf_cnt.bf.nflashRegOobCount = CONFIG_SYS_NAND_OOBSIZE - 1;
	REG32(FLASH_NF_COUNT) =  nf_cnt.wrd;

	//set direct access nflashExtAddr, set and let HW switch access area window
  	REG32(FLASH_NF_ACCESS) = 0;

	//read page data
	memcpy(dst, page_add , CONFIG_SYS_NAND_PAGE_SIZE);

	//read oob : assume access with page alignment
	memcpy(oob_data, (page_add + CONFIG_SYS_NAND_PAGE_SIZE), CONFIG_SYS_NAND_OOBSIZE);

	ecc_sts_msk.wrd = 0;
	ecc_sts_msk.bf.eccDone = 1;
	if (!reg_wait(FLASH_NF_ECC_STATUS, ecc_sts_msk.wrd, ecc_sts_msk.wrd, NF_START_BCNT))
		goto fail;

	//diable ecc and make sure in correct ecc mode
	ecc_ctl.wrd = REG32(FLASH_NF_ECC_CONTROL);
	ecc_ctl.bf.eccEn= 0;
	REG32(FLASH_NF_ECC_CONTROL) =  ecc_ctl.wrd;  //disable ecc

	/* Pick the ECC bytes out of the oob data */
	for (i = 0; i < ECCTOTAL; i++)
		ecc_code[i] = oob_data[nand_ecc_pos[i]];

	for (i = 0; i < ECCSTEPS; i++) {
		ecc_oob.wrd = ecc_code[3 * i] | ecc_code[(3 * i) + 1] << 8 | ecc_code[(3 * i) + 2] << 16;
		REG32(FLASH_NF_ECC_OOB) =  ecc_oob.wrd;

		ecc_ctl.wrd = REG32(FLASH_NF_ECC_CONTROL);
		ecc_ctl.bf.eccCodeSel = i;
		REG32(FLASH_NF_ECC_CONTROL) = ecc_ctl.wrd;

		ecc_sts.wrd = REG32(FLASH_NF_ECC_STATUS);

		switch(ecc_sts.bf.eccStatus) {
		case ECC_1BIT_DATA_ERR:
			p[ecc_sts.bf.eccErrByte] ^= (1 << ecc_sts.bf.eccErrBit);
			break;
		case ECC_UNCORRECTABLE:
			goto fail;
		}
		p += CONFIG_SYS_NAND_ECCSIZE;
	}

	return 1;

fail:
	//diable ecc and make sure in correct ecc mode
	REG32(FLASH_NF_ECC_CONTROL) =  0;
	flash_reset();

	return 0;
}

int nand_spl_load_image(uint32_t offs, unsigned int size, void *dst)
{
	unsigned int block, lastblock;
	unsigned int page;

	/*
	 * offs has to be aligned to a page address!
	 */
	block = offs / CONFIG_SYS_NAND_BLOCK_SIZE;
	lastblock = (offs + size - 1) / CONFIG_SYS_NAND_BLOCK_SIZE;
	page = (offs % CONFIG_SYS_NAND_BLOCK_SIZE) / CONFIG_SYS_NAND_PAGE_SIZE;

	while (block <= lastblock) {
		if (!nand_is_bad_block(block)) {
			/*
			 * Skip bad blocks
			 */
			while (page < CONFIG_SYS_NAND_PAGE_COUNT) {
				nand_read_page(block, page, dst);
				dst += CONFIG_SYS_NAND_PAGE_SIZE;
				page++;
			}

			page = 0;
		} else {
			lastblock++;
		}

		block++;
	}

	return 0;
}

/* nand_init() - initialize data to make nand usable by SPL */
void nand_init(void)
{
	/*
	 * Init board specific nand support
	 */
	mtd.priv = &nand_chip;
	nand_chip.IO_ADDR_R = nand_chip.IO_ADDR_W =
		(void  __iomem *)CONFIG_SYS_NAND_BASE;

	flash_reset();

	if (nand_chip.select_chip)
		nand_chip.select_chip(&mtd, 0);
}

/* Unselect after operation */
void nand_deselect(void)
{
	if (nand_chip.select_chip)
		nand_chip.select_chip(&mtd, -1);
}
