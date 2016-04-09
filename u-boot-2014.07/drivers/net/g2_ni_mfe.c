/***********************************************************************/
/* This file contains unpublished documentation and software           */
/* proprietary to Cortina Systems Incorporated. Any use or disclosure, */
/* in whole or in part, of the information in this file without a      */
/* written consent of an officer of Cortina Systems Incorporated is    */
/* strictly prohibited.                                                */
/* Copyright (c) 2010 by Cortina Systems Incorporated.                 */
/***********************************************************************/
/*
 *
 * g2_ni_mfe.c
 *
 * $Id: g2_ni_mfe.c,v 1.12 2013/01/24 08:56:54 alee Exp $
 */
#include <common.h>
#include <command.h>
#include <malloc.h>
#include <net.h>
#include "g2_ni_mfe.h"

static u32 reg = 0;

#if G2_DBG /*define G2_DBG if individual rx,tx,init needs to be called */

struct eth_device	*dbg_dev;

/* This is a trivial atoi implementation since we don't have one available */
int atoi(char *string)
{
	int length;
	int retval = 0;
	int i;
	int sign = 1;

	length = strlen(string);
	for (i = 0; i < length; i++) {
		retval *= 16;
		if (0 == i && string[0] == '-') {
			sign = -1;
			continue;
		} else if (string[i] <= '9' && string[i] >= '0')
			retval += string[i] - '0';
		else if (string[i] <= 'F' && string[i] >= 'A')
			retval += string[i] - 'A'+10;
		else if (string[i] <= 'f' && string[i] >= 'a')
		  	retval += string[i] - 'a'+10;
		else
                  	break;
	}
	retval *= sign;
	return retval;
}
#endif

u32 reg_read(u32 addr)
{
        return *(volatile u32*)addr;
}
void reg_write(u32 addr, u32 val)
{
         *(volatile u32*)addr = val;
}

void g2_ni_reset(void)
{
	reg_write(GLOBAL_IO_DRIVE_STRENGTH, 0xaab);

	/* NI global resets */
	reg = reg_read(GLOBAL_BLOCK_RESET);
	reg = reg | (RESET_NI); // ->1
	reg_write(GLOBAL_BLOCK_RESET, reg);
	/* Remove resets */
	reg = reg & (~(RESET_NI)); // -> 0
	reg_write(GLOBAL_BLOCK_RESET, reg);

	/* NI ethernet interface reset */
	reg = reg_read(NI_TOP_NI_INTF_RST_CONFIG);
	reg = reg | (INTF_RST_GE);
	reg_write(NI_TOP_NI_INTF_RST_CONFIG, reg);
	reg = reg & ~(INTF_RST_GE);
	reg_write(NI_TOP_NI_INTF_RST_CONFIG, reg);

	/* Only one GMAC can connect to CPU */
	reg = GE_TO_CPU;
	reg_write(NI_TOP_NI_ETH_MGMT_PT_CONFIG, reg);

	return;
}


#define NI_ETH_SPEED_100 0xFFFFFFFE
#define NI_ETH_DUPLEX_FULL 0xFFFFFFD
#define PHY_MODE_MFE_MAC (1 << 12)

#define NI_RX_ENB (1 << 2)
#define NI_TX_ENB (1 << 3)
#define FLOW_CNTL_RX_DSBL (1 << 8)
#define FLOW_CNTL_TX_DSBL (1 << 12)

int g2_phy_write(unsigned int phy_addr, unsigned int offset, unsigned int val)
{
	PER_MDIO_ADDR_t	mdio_addr;
	PER_MDIO_CTRL_t	mdio_ctrl;
	unsigned int	i;

	mdio_addr.bf.mdio_addr 	= phy_addr;
	mdio_addr.bf.mdio_offset= offset;
	mdio_addr.bf.mdio_rd_wr = mdio_rd_wr_WR;
  	reg_write(PER_MDIO_ADDR, mdio_addr.wrd);

  	reg_write(PER_MDIO_WRDATA, val);

	mdio_ctrl.bf.mdiostart = 1;
  	reg_write(PER_MDIO_CTRL, mdio_ctrl.wrd);

	for (i=0; i<PHY_POLL_TIMES; i++)
	{
		mdio_ctrl.wrd = reg_read(PER_MDIO_CTRL);
		if (mdio_ctrl.bf.mdiodone) {
		  	reg_write(PER_MDIO_CTRL, mdio_ctrl.wrd);
		  	break;
		}
	}
	if (i== PHY_POLL_TIMES) {
		printf("Can not access PHY registers!\n");
		return (-1);
	}

	return (0);
}

int g2_phy_read(unsigned int phy_addr, unsigned int offset)
{
	PER_MDIO_ADDR_t	mdio_addr;
	PER_MDIO_CTRL_t	mdio_ctrl;
	unsigned int	i;
	unsigned int	val;

	mdio_addr.bf.mdio_addr 	= phy_addr;
	mdio_addr.bf.mdio_offset= offset;
	mdio_addr.bf.mdio_rd_wr = mdio_rd_wr_RD;
  	reg_write(PER_MDIO_ADDR, mdio_addr.wrd);

	mdio_ctrl.bf.mdiostart = 1;
  	reg_write(PER_MDIO_CTRL, mdio_ctrl.wrd);

	for (i=0; i<PHY_POLL_TIMES; i++)
	{
		mdio_ctrl.wrd = reg_read(PER_MDIO_CTRL);
		if (mdio_ctrl.bf.mdiodone) {
		  	reg_write(PER_MDIO_CTRL, mdio_ctrl.wrd);
		  	break;
		}
	}
	if (i== PHY_POLL_TIMES) {
		printf("Can not access PHY registers!\n");
		return (-1);
	}

	val = reg_read(PER_MDIO_RDDATA);
	return (val);
}

int g2_phy_disable(int port)
{
	unsigned int addr, val;
	
	switch (port) {
	case 0:
		addr = GE_PORT0_PHY_ADDR;
		break;
	case 1:
		addr = GE_PORT1_PHY_ADDR;
		break;
	case 2:
		addr = GE_PORT2_PHY_ADDR;
		break;
	default:
		printf("invalid port %d\n", port);
		return -1;
	}

	if(addr == 0)	/* ignore PHY address 0 */
		return 0;
	
	val = g2_phy_read(addr, 0);
	val = val | (1<<11); /* set power down */
	g2_phy_write(addr, 0, val);
	return 0;
}

int g2_ni_init(struct eth_device *dev, bd_t *bd)
{
	NI_TOP_NI_ETH_MAC_CONFIG0_0_t	mac_cfg0;
	unsigned char 			mac[6];
	
	/* parsing ethaddr and set to NI registers. */
	if (eth_getenv_enetaddr("ethaddr", mac)) {
		reg = (mac[0]<<24) + (mac[1]<<16) + (mac[2]<<8) + mac[3];
		reg_write(NI_TOP_NI_MAC_ADDR0, reg);
		reg = mac[4];
		reg_write(NI_TOP_NI_MAC_ADDR1, reg);
		reg = reg_read(NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE);
		reg = (reg & 0xffffff00) | mac[5];
		reg_write(NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE, reg);

		/* received only Broadcast and Address matched packets */
		reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
		reg = reg & 0xffff3fff;
		reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);
	} else {
		/* received all packets(promiscuous mode) */
		reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
		reg = reg | 0x0000c000;
		reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);
	}

  	/* RX XRAM ADDRESS CONFIG (start and end address) */
  	reg_write(NI_TOP_NI_CPUXRAM_ADRCFG_RX_0,	\
  			((RX_TOP_ADDR<<16)|RX_BASE_ADDR));

  	/* TX XRAM ADDRESS CONFIG (start and end address) */
  	reg_write(NI_TOP_NI_CPUXRAM_ADRCFG_TX_0,	\
  			((TX_TOP_ADDR<<16)|TX_BASE_ADDR));

	/*
	 * Configuration for Management Ethernet 
	 * Interface:
	 * - RGMII 1000 mode
	 * - MAC mode
	 */
	reg = reg_read(NI_TOP_NI_ETH_INT_CONFIG1);
	reg = (reg & ~INTF_CFG_GE1_MASK) | 
		GE1_MAC_INTF_RGMII_1000;
	reg_write(NI_TOP_NI_ETH_INT_CONFIG1, reg);

	/*
	 * Set speed and duplex as default value.
	 */
	mac_cfg0.wrd = reg_read(NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE);
	mac_cfg0.bf.speed = NI_TOP_NI_RTH_MAC_100M;
	mac_cfg0.bf.duplex = NI_TOP_NI_RTH_MAC_FULL;
	mac_cfg0.bf.rx_en = 1;
	mac_cfg0.bf.tx_en = 1;
	mac_cfg0.bf.rx_flow_disable = 0;
	mac_cfg0.bf.tx_flow_disable = 0;
	reg_write(NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE, mac_cfg0.wrd);

#if FOR_DEBUG
  	/* Enable MFE ethernet interface */
  	reg = reg_read(NI_TOP_NI_INTF_RST_CONFIG);
  	reg = reg & ~(INTF_RST_GE);
  	reg_write(NI_TOP_NI_INTF_RST_CONFIG, reg);
#endif

  	/* Need to toggle the tx and rx cpu_pkt_dis bit */
  	/* after changing Address config register.      */
  	reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
  	reg = reg | (TX_0_CPU_PKT_DIS | RX_0_CPU_PKT_DIS);
  	reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);
  	reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
  	reg = reg & (~(TX_0_CPU_PKT_DIS | RX_0_CPU_PKT_DIS));
  	reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);

  	return 0;
}


/*********************************************
 * Packet receive routine from Management FE
 * Expects a previously allocated buffer and
 * fills the length
 * Retruns 0 on success -1 on failure
 *******************************************/
int g2_ni_recv(struct eth_device *netdev)
{
	struct g2_ni_priv 	*priv = (struct g2_ni_priv *)(netdev->priv);
	NI_HEADER_X_T		header_x;
	unsigned int		pktlen=0;
	unsigned int 		sw_rx_rd_ptr;
	unsigned int 		hw_rx_wr_ptr;
	volatile u32 		*rx_xram_ptr;
	unsigned int		loop;
	unsigned char   	pkt_buf[2048];
	unsigned int 		*data_ptr;

	/*get the hw write pointer*/
	hw_rx_wr_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_STA_RX_0);
	/*get the sw read pointer*/
	sw_rx_rd_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0);
#if G2_DBG
	printf("%s : RX hw_wr_ptr :%x sw_rd_ptr %x\n",	\
		__func__,hw_rx_wr_ptr,sw_rx_rd_ptr);
#endif

    	while (sw_rx_rd_ptr != hw_rx_wr_ptr) {
        /* Point to the absolute memory address of XRAM where read pointer is */
		rx_xram_ptr = (u32*)(NI_XRAM_BASE + sw_rx_rd_ptr * 8);

	    	/* Wrap around if required */
		if ((u32)rx_xram_ptr >= priv->rx_xram_end_adr) {
	    		rx_xram_ptr = (unsigned int *)priv->rx_xram_base_adr;
	    	}

        	/* Checking header XR. Do not update the read pointer yet */
        	rx_xram_ptr++; 	/* skip unused 32-bit in Header XR */

		header_x = (NI_HEADER_X_T)(*rx_xram_ptr);/* Header XR [31:0] */
#if G2_DBG
		if (*rx_xram_ptr == 0xffffffff)
			printf("Error !\n");
        	printf("%s : RX next link %x(%d) \n",__func__,	\
        		header_x.bf.next_link,header_x.bf.next_link);
        	printf("%s : bytes_valid %x\n",__func__,	\
        		header_x.bf.bytes_valid);
#endif

		if (header_x.bf.ownership == 0) {
            	/* Check if there are any errors in the packet */
			if (header_x.bf.error_flag) {
              			printf("Error Packet !! error Flag set \n");
              			/*Update the software read pointer*/
              			reg_write(NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0,\
              					header_x.bf.next_link);
              			return 0;
            		}

            		rx_xram_ptr++;	/* Header_E [63:32] */
		    	/* Wrap around if required */
			if ((u32)rx_xram_ptr >= priv->rx_xram_end_adr) {
		    		rx_xram_ptr = (unsigned int *)	\
		    				priv->rx_xram_base_adr;
		    	}

            		rx_xram_ptr++;  /* Header_E [31: 0] */

			pktlen = (*rx_xram_ptr) & 0x2fff;
#if G2_DBG
			printf("%s : rx packet length = %d\n",__func__,pktlen);
#endif
            		rx_xram_ptr++;	/* point to data address */
		    	/* Wrap around if required */
			if ((u32)rx_xram_ptr >= priv->rx_xram_end_adr) {
		    		rx_xram_ptr = (unsigned int *)	\
		    				priv->rx_xram_base_adr;
		    	}

    			data_ptr= (u32 *)pkt_buf;
            		/* Read out the packet */
            		/* Data is in little endian form in the XRAM */
            		/* Send the packet to upper layer */
    			for(loop=0; loop<= pktlen/4; loop++) {
         			*data_ptr++ = *rx_xram_ptr++;
		    		/* Wrap around if required */
				if ((u32)rx_xram_ptr >= priv->rx_xram_end_adr) {
		    			rx_xram_ptr = (unsigned int *)	\
		    				priv->rx_xram_base_adr;
		    		}
    			}
    			memcpy((void*)NetRxPackets[0],pkt_buf,pktlen);
//			NetRxPackets[0] = (unsigned char *)rx_xram_ptr;
            		/* Update the software read pointer */
            		reg_write(NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0,	\
            				header_x.bf.next_link);

			NetReceive(NetRxPackets[0], pktlen-4);
		}

	    	/*get the hw write pointer*/
	    	hw_rx_wr_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_STA_RX_0);
	    	/*get the sw read pointer*/
	    	sw_rx_rd_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0);
	}
    	return 0;
}


/* LITTLE_ENDIAN */

static u32 calc_crc(u32 crc, u8 const *p, u32 len)
{
	int i;

    	while (len--) {
        	crc ^= *p++;
        	for (i = 0; i < 8; i++) {
            		crc = (crc >> 1) ^ ((crc & 1) ? CRCPOLY_LE : 0);
		}
    	}
    	return crc;
}

static int g2_ni_send(struct eth_device *dev, void *packet, int length)
{
	struct g2_ni_priv *priv = (struct g2_ni_priv *)(dev->priv);
	unsigned short	hw_tx_rd_ptr;
	unsigned short	sw_tx_wr_ptr;
	unsigned int	new_pkt_len;
	unsigned char 	valid_bytes=0;
	unsigned int	*tx_xram_ptr;
	unsigned short  next_link = 0;
	unsigned char	*pkt_buf_ptr;
	unsigned int	loop;
	unsigned int 	crc32;
	unsigned int 	hdr_xt=0;
	int  		pad=0;
	unsigned char   pkt_buf[2048];
	unsigned int 	*data_ptr;

	if((NULL == packet) || ( length > 2032 )) {
        	return -1;
	}

	/* Get the hardware read pointer */
	hw_tx_rd_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0);

	/* Get the software write pointer */
	sw_tx_wr_ptr = reg_read(NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0);

#if G2_DBG
	printf("%s : hw_tx_rd_ptr = %x\n",__func__,hw_tx_rd_ptr);
	printf("%s : sw_tx_wr_ptr = %x\n",__func__,sw_tx_wr_ptr);
#endif

	if (hw_tx_rd_ptr != sw_tx_wr_ptr)
	{
		printf("Tx FIFO is not available!\n");
		return 1;
	}

	memset(pkt_buf,0x00,sizeof(pkt_buf));
	memcpy(pkt_buf,(const void *)packet,length);

	pad = 64 - (length + 4);	/* if packet length < 60 */
	pad = (pad < 0) ? 0 : pad;

	new_pkt_len = length + pad ;	/* new packet length */

	pkt_buf_ptr = (unsigned char *)pkt_buf;

	/* Calculate the CRC32 */
	crc32 = ~(calc_crc(~0,(u8*)pkt_buf_ptr,new_pkt_len));
#if G2_DBG
	printf("crc32 is 0x%x \n", crc32);
	printf("G2_DBG ~crc32 is 0x%x \n",~crc32);
	printf( "pkt len %d \n", new_pkt_len);
#endif
	memcpy ( (pkt_buf_ptr+new_pkt_len), (u8 *)(&crc32), sizeof(crc32));
	new_pkt_len = new_pkt_len + 4;	/* add CRC */

	valid_bytes = new_pkt_len % 8;
	valid_bytes = valid_bytes ? valid_bytes : 0;
#if G2_DBG
  	printf("valid_bytes %x\n",valid_bytes);
#endif

	next_link = sw_tx_wr_ptr + (new_pkt_len+7) / 8 ; /* for headr XT */
	next_link = next_link + 1; /* add header */
	/* Wrap around if required */
	if(next_link > priv->tx_xram_end) {
#if G2_DBG
		printf("Wrap around next_link = %x \n",next_link);
#endif
		next_link = priv->tx_xram_start +	\
			(next_link - (priv->tx_xram_end+1));
	}

#if G2_DBG
	printf("TX next_link %x\n",next_link);
#endif

	hdr_xt = 0x80000000 | (valid_bytes << 12) | next_link;

	tx_xram_ptr = (unsigned int *)(NI_XRAM_BASE + sw_tx_wr_ptr * 8);

	/* Wrap around if required */
	if ((u32)tx_xram_ptr >= priv->tx_xram_end_adr) {
		tx_xram_ptr = (unsigned int *)priv->tx_xram_base_adr;
	}

	/* skip first 4 bytes before copying the headerXT */
	tx_xram_ptr ++;

	*tx_xram_ptr = hdr_xt;
	tx_xram_ptr++;

	/* Wrap around if required */
	if ((u32)tx_xram_ptr >= priv->tx_xram_end_adr) {
		tx_xram_ptr = (unsigned int *)priv->tx_xram_base_adr;
	}

	/* Now to copy the data . The first byte on the line goes first */
	data_ptr= (unsigned int *)pkt_buf_ptr;
	for(loop=0; loop<= new_pkt_len/4; loop++) {
		*tx_xram_ptr++ = *data_ptr++;
		/* Wrap around if required */
		if ((u32)tx_xram_ptr >= priv->tx_xram_end_adr) {
			tx_xram_ptr = (unsigned int *)priv->tx_xram_base_adr;
	    	}
	}

	/* Publish the write pointer */
	reg_write(NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0,next_link);

	return 0;
}

void g2_ni_halt(struct eth_device *netdev)
{
#if FOR_DEBUG
	/* MFE MAC configuration Disable tx and rx */
	reg = reg_read(NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE);
	reg = reg & ~(NI_RX_ENB);
	reg = reg & ~(NI_TX_ENB);
	reg_write(NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE, reg);

	/* Disable MFE ethernet interface */
	reg = reg_read(NI_TOP_NI_INTF_RST_CONFIG);
	reg = reg | (INTF_RST_GE1) ;
	reg_write(NI_TOP_NI_INTF_RST_CONFIG, reg);
#endif
	return;
}

int cpu_eth_init(bd_t *bis)
{
	struct eth_device 	*dev;
	struct g2_ni_priv 	*priv;
	unsigned char 		mac[6];
	unsigned int		val;
	unsigned int 		phy_addr;
	unsigned int 		vendor_id, chip_id, phy_id;

	dev = (struct eth_device *)malloc (sizeof *dev);
	if (NULL == dev)
		return 1;
	memset (dev, 0, sizeof *dev);

	priv = (struct g2_ni_priv *)malloc (sizeof (*priv));
	if (NULL == priv)
		return 0;
	memset (priv, 0, sizeof *priv);

	priv->rx_xram_base_adr	= NI_XRAM_BASE + (RX_BASE_ADDR * 8);
	priv->rx_xram_end_adr	= NI_XRAM_BASE + ((RX_TOP_ADDR + 1) * 8);
	priv->rx_xram_start	= RX_BASE_ADDR;
	priv->rx_xram_end	= RX_TOP_ADDR;
	priv->tx_xram_base_adr	= NI_XRAM_BASE + (TX_BASE_ADDR * 8);
	priv->tx_xram_end_adr	= NI_XRAM_BASE + ((TX_TOP_ADDR + 1) * 8);
	priv->tx_xram_start	= TX_BASE_ADDR;
	priv->tx_xram_end	= TX_TOP_ADDR;

#if G2_DBG
	printf("rx_base_addr:%x\t rx_top_addr %x\n",	\
		priv->rx_xram_start,priv->rx_xram_end);
	printf("tx_base_addr:%x\t tx_top_addr %x\n",	\
		priv->tx_xram_start,priv->tx_xram_end);
	printf("rx physical start address = %x end address = %x\n",	\
		priv->rx_xram_base_adr, priv->rx_xram_end_adr);
	printf("tx physical start address = %x end address = %x\n",	\
		priv->tx_xram_base_adr, priv->tx_xram_end_adr);
#endif

  	g2_ni_reset();

	/* set MDIO pre-scale value */
  	reg = reg_read(PER_MDIO_CFG);
  	reg = reg | 0x00200000;
  	reg_write(PER_MDIO_CFG, reg);

	for (phy_addr = 1; phy_addr < 31; phy_addr++) {
		vendor_id = g2_phy_read(phy_addr, 2);
		chip_id   = g2_phy_read(phy_addr, 3);
		phy_id = vendor_id <<16 | chip_id;

		if ((phy_id & PHY_ID_MASK) == PHY_ID_RTL8211) {
			/*
			 * Disable response PHYAD=0 function of
			 * RTL8211 series PHY
			 */
			
			/* REG31 write 0x0007, set to extension page */
			g2_phy_write(phy_addr, 31, 0x0007);
			
			/* REG30 write 0x002C, set to extension page 44 */
			g2_phy_write(phy_addr, 30, 0x002C);
			
			/* 
			 * REG27 write bit[2] =0
			 * disable response PHYAD=0  function.
			 * we should read REG27 and clear bit[2], and write back
			 */
			val = g2_phy_read(phy_addr, 27);
			val &= ~(1<<2);
			g2_phy_write(phy_addr, 27, val);
			
			/* REG31 write 0X0000, back to page0 */
			g2_phy_write(phy_addr, 31, 0x0000);
		}
		
	}

	/* parsing ethaddr and set to NI registers. */
	if (eth_getenv_enetaddr("ethaddr",mac)) {
		reg = (mac[0]<<24) + (mac[1]<<16) + (mac[2]<<8) + mac[3];
		reg_write(NI_TOP_NI_MAC_ADDR0, reg);
		reg = mac[4];
		reg_write(NI_TOP_NI_MAC_ADDR1, reg);
		reg = reg_read(NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE);
		reg = (reg & 0xffffff00) | mac[5];
		reg_write(NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE, reg);

		/* received only Broadcast and Address matched packets */
		reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
		reg = reg & 0xffff3fff;
		reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);
	} else {
		/* received all packets(promiscuous mode) */
		reg = reg_read(NI_TOP_NI_CPUXRAM_CFG);
		reg = reg | 0x0000c000;
		reg_write(NI_TOP_NI_CPUXRAM_CFG, reg);
	}

	sprintf (dev->name, "eth%d", CONFIG_G2_EMAC_ACT);
	dev->priv = priv;
	dev->init = g2_ni_init;
	dev->halt = g2_ni_halt;
	dev->send = g2_ni_send;
	dev->recv = g2_ni_recv;

	eth_register (dev);

#if G2_DBG
	dbg_dev = dev;
#endif

	return 0;
}

#if G2_DBG
DECLARE_GLOBAL_DATA_PTR;

static int do_eth_init (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	bd_t *bd = gd->bd;
	g2_ni_init(0x00,bd);
	return 0;
}

U_BOOT_CMD(
        eth_init, 2, 1, do_eth_init,
        "eth_init\t- to test eth_init \n",
        "None\n"
);
#endif

#if G2_DBG
static int do_eth_send (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned char 	pkt[1536];
	unsigned int 	i;

	for (i=0; i<1500; i++){
	 	pkt[i] = i % 256;
	}

	for (i=60; i<360; i++) {
		g2_ni_send(dbg_dev,pkt,i);
	}
	return 0;
}

U_BOOT_CMD(
        eth_send, 3, 2, do_eth_send,
        "eth_send\t- to test eth_send \n",
        "None\n"
);

static int do_eth_rx (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	g2_ni_recv(0x00);
	return 0;
}

U_BOOT_CMD(
        eth_rx, 2, 1, do_eth_rx,
        "eth_rx\t- to test eth_rx \n",
        "None\n"
);

static int do_read_phy(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int	phy_adr;
	unsigned int	reg_off;
	unsigned int	reg_val;

	phy_adr = atoi(argv[1]);
	reg_off = atoi(argv[2]);
	reg_val = g2_phy_read(phy_adr,reg_off);
	printf("PHY_ADR = %d offset=%d reg_val=%x \n",phy_adr,reg_off,reg_val);
	return 0;
}

U_BOOT_CMD(
        phy_read, 3, 1, do_read_phy,
        "phy_read\t- to read PHY register \n",
        "None\n"
);

static int do_write_phy(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int	phy_adr;
	unsigned int	reg_off;
	unsigned int	reg_val;

	phy_adr = atoi(argv[1]);
	reg_off = atoi(argv[2]);
	reg_val = atoi(argv[3]);
	g2_phy_write(phy_adr,reg_off,reg_val);
	printf("PHY_ADR = %d offset=%d reg_val=%x \n",phy_adr,reg_off,reg_val);
	return 0;
}

U_BOOT_CMD(
	phy_write, 4, 1, do_write_phy,
        "phy_write\t- to write PHY register \n",
        "None\n"
);

#endif

static int do_phy_reg(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret, i;
	unsigned int phy_addr, reg, val;

	if (argc < 2) {
		printf("Usage:\nphy_reg %s\n", cmdtp->help);
		return -1;
	}

	phy_addr = simple_strtoul(argv[1], NULL, 10);

	if (phy_addr > 31) {
		printf("Usage:\nphy_reg %s\n", cmdtp->help);
		return -1;
	}

	if (argc == 2) {
		/* read the first 15 registers of the PHY */
		printf("PHY addr %d:\n", phy_addr);
		for (i = 0; i < 15; i++) {
			val = g2_phy_read(phy_addr, i);
			printf("Reg 0x%04X = 0x%04X\n", i, val);
		}
		return 0;
	}
	
	reg = simple_strtoul(argv[2], NULL, 10);

	if (argc == 3) {
		/* read cmd */
		val = g2_phy_read(phy_addr, reg);
		printf("PHY addr %d Reg 0x%04X = 0x%04X\n", phy_addr, reg, val);
	} else {
		/* argc > 3*/
		/* write cmd */
		val = simple_strtoul(argv[3], NULL, 10);
		ret = g2_phy_write(phy_addr, reg, val);
		if (!ret) {
			printf("PHY addr %d Reg 0x%04X = 0x%04X\n", 
				phy_addr, reg, val);
		} else {
			printf("Can't write PHY addr %d Reg 0x%04X as 0x%04X,"
				" ret = %d", phy_addr, reg, val, ret);
		}
	}
	return 0;
}

U_BOOT_CMD(
	phy_reg, 4, 1, do_phy_reg,
	"read/write PHY register",
	"[PHY addr] [reg addr] ([value])\n"
	"PHY addr : 0-31\n"
);
