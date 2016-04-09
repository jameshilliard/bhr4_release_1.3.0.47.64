/*
 * (C) Copyright 2013
 * Greenwave Reality Inc.
 * Hoang Tran <hoang.tran@greenwavereality.com>
 *
 * Configuration settings for the GWR-BHR4 board.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */
#define CONFIG_G2
#define CONFIG_SMP

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_NO_FLASH
#define CONFIG_SYS_GENERIC_BOARD

/*
 * Enable kernel FIT image support
 */
#define CONFIG_FIT
#define CONFIG_LIBFTD
#define CONFIG_FIT_VERBOSE

/*
 * Enable signed kernel FIT image
 */
#define CONFIG_FIT_SIGNATURE
#define CONFIG_FORCE_SIGNATURE_CHECK
#define CONFIG_RSA

/*
 * Enable u-boot Device Control Tree to embed kernel public key
 */
#define CONFIG_OF_CONTROL
#define CONFIG_OF_SEPARATE

#define CONFIG_DEFAULT_DEVICE_TREE g2_bhr4

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS			1
#define PHYS_SDRAM_1				0x00000000
#define PHYS_SDRAM_1_SIZE			0x10000000
#define CONFIG_SYS_SDRAM_BASE			PHYS_SDRAM_1
#define CONFIG_SYS_MALLOC_LEN			(1 << 20)	/* Reserved for malloc	*/
#define CONFIG_SYS_INIT_SP_ADDR			0x08000000
#define CONFIG_SYS_FLASH_BASE			0xe0000000

/* Timer Configuration */
#define CONFIG_SYS_HZ				(1000)

/*-----------------------------------------------------------------------
 * Miscellaneous configurable options
 */
#define CONFIG_BOOTDELAY			3
#undef CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_CBSIZE			1024

#define CONFIG_SYS_PROMPT			"=> "
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CONSOLE_INFO_QUIET		/* don't print console @ startup*/

#define CONFIG_SYS_HUSH_PARSER			/* Use the HUSH parser		*/

#define CONFIG_LOADS_ECHO			/* echo on for serial download	*/
#define CONFIG_SYS_LOADS_BAUD_CHANGE		/* allow baudrate change	*/

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE			(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS			32
#define CONFIG_SYS_LOAD_ADDR			0x01600000

#define CONFIG_SYS_TEXT_BASE			0x04000000

#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_RUN
#define CONFIG_CMD_LOADB

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_SUBNETMASK

#define CONFIG_BOOTCOMMAND "run mtd_boot;run switch_boot_partition;run mtd_boot;fail"

#define CONFIG_CMDLINE_TAG			/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

#define CONFIG_CMD_BDI
#define CONFIG_CMD_BOOTD
#define CONFIG_CMD_CORTINA_GS2_BIT0
#define CONFIG_CMD_IMI

/*-----------------------------------------------------------------------
 * Serial configuration
 */
#define CONFIG_G2_SERIAL
#define CONFIG_CONS_INDEX			0
#define CONFIG_BAUDRATE				115200
#define CONFIG_SYS_BAUDRATE_TABLE		{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * NAND flash
 */
#define CONFIG_CMD_NAND				1
#define CONFIG_NAND_G2				1
#define CONFIG_SYS_MAX_NAND_DEVICE		1
#define CONFIG_SYS_NAND_BASE			0xE0000000

#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SIZE				0x020000
#define CONFIG_CMD_SAVEENV          1
#define CONFIG_ENV_OFFSET1			0x300000
#define CONFIG_ENV_OFFSET2			0x600000
#define CONFIG_ENV_RANGE			0x080000
#define CONFIG_ENV_OFFSET_REDUND1		0x380000
#define CONFIG_ENV_OFFSET_REDUND2		0x680000

/*-----------------------------------------------------------------------
 * SPI
 */
#define CONFIG_CS75XX_SPI			1
#define CONFIG_CMD_SPI				1

/*-----------------------------------------------------------------------
 * Network interfaces
 */
#define CONFIG_CMD_NET
#define CONFIG_G2_EMAC				1
#define CONFIG_G2_EMAC_ACT			2
#define CONFIG_G2_PHYADDR_GMAC0			1
#define CONFIG_G2_PHYADDR_GMAC1			0
#define CONFIG_G2_PHYADDR_GMAC2			2

/* GbE switch BCM53125 */
#define CONFIG_BCM53XXX_SPI			1

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP

/*
 * Static configuration when assigning fixed address
 */
#define CONFIG_ETHADDR			28:C6:8E:11:22:33
#define CONFIG_ETH1ADDR			28:C6:8E:44:55:66
#define CONFIG_ETH2ADDR			28:C6:8E:77:88:99
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_IPADDR			192.168.1.122
#define CONFIG_SERVERIP			192.168.1.100
#define CONFIG_GATEWAYIP		192.168.1.1
#define CONFIG_BOOTFILE			"uImage"

/* Allow overwrite of ethaddr */
#define CONFIG_ENV_OVERWRITE

/*-----------------------------------------------------------------------
 * MTD, UBI ...
 *----------------------------------------------------------------------*/
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define MTDIDS_DEFAULT		"nand0=cs752x_nand_flash"
#define MTDPARTS_DEFAULT "mtdparts=cs752x_nand_flash:" \
	"512k@0x20000(bootloader)," \
	"512k@0x100000(uboot_env_pri)," \
	"512k@$0x180000(uboot_env_sec)," \
	"1M@0x200000(bootloader_even)," \
	"512k@0x300000(uboot_even_env_pri)," \
	"512k@0x380000(uboot_even_env_sec)," \
	"1M@$0x500000(bootloader_odd)," \
	"512k@0x600000(uboot_odd_env_pri)," \
	"512k@0x680000(uboot_odd_env_sec)," \
	"224M@0x1600000(ubi)"

#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define CONFIG_RBTREE
#define CONFIG_LZO

/*-----------------------------------------------------------------------
 * Default environment
 *----------------------------------------------------------------------*/
#define CONFIG_UBOOT_DEF_ENV \
    "netdev=eth2\0" \
    "baudrate=115200\0" \
    "hostname=bhr4\0" \
    "bootdelay=3\0" \
    "naddr_uboot=0x20000\0" \
    "naddr_uboot_env_pri=0x100000\0" \
    "naddr_uboot_env_sec=0x180000\0" \
    "naddr_uboot_even=0x200000\0" \
    "naddr_uboot_even_env_pri=0x300000\0" \
    "naddr_uboot_even_env_sec=0x380000\0" \
    "naddr_uboot_odd=0x500000\0" \
    "naddr_uboot_odd_env_pri=0x600000\0" \
    "naddr_uboot_odd_env_sec=0x680000\0" \
    "naddr_ubi=0x1600000\0" \
    "nsize_ubi=0xEA00000\0" \
    "raddr_kernel=0x5000000\0" \
    "raddr_tftp=0x5000000\0" \
    "user_dir=bhr4_dev\0" \
    "ramdisk_file=ramdisk.itb\0" \
    "ubifs_file=ubifs.img\0" \
    "bootfile=uImage\0" \
    "mtdparts=" MTDPARTS_DEFAULT "\0" \
    "set_mtdparts=setenv mtdparts mtdparts=cs752x_nand_flash:" \
        "512k@${naddr_uboot}(bootloader)," \
        "512k@${naddr_uboot_env_pri}(uboot_env_pri)," \
        "512k@${naddr_uboot_env_sec}(uboot_env_sec)," \
        "1M@${naddr_uboot_odd}(bootloader_odd)," \
        "512k@${naddr_uboot_odd_env_pri}(uboot_odd_env_pri),"\
        "512k@${naddr_uboot_odd_env_sec}(uboot_odd_env_sec)," \
        "1M@${naddr_uboot_even}(bootloader_even)," \
        "512k@${naddr_uboot_even_env_pri}(uboot_even_env_pri)," \
        "512k@${naddr_uboot_even_env_sec}(uboot_even_env_sec)," \
        "224M@${naddr_ubi}(ubi)\0" \
    "ramargs=setenv bootargs init=/init root=/dev/ram rw\0" \
    "addtty=setenv bootargs ${bootargs} console=ttyS0,${baudrate}\0" \
    "addmisc=setenv bootargs ${bootargs} SB_PHY=PPPS qm_int_buff=${QM_INT_BUFF} boot_partition=${bootId}\0" \
    "addmacaddr=setenv bootargs ${bootargs} ethaddr0=${ethaddr} ethaddr1=${eth1addr} ethaddr2=${eth2addr} wifiaddr0=${wifiaddr0} wifiaddr1=${wifiaddr1}\0" \
    "addmtdparts=setenv bootargs ${bootargs} ${mtdparts}\0" \
    "ubifs_part=ubi part ubi;if test $? -ne 0;then alt_toggle_boot_partition;alt_saveenv;reset;fi\0" \
    "ubifs_mount=ubifsmount ubi:${current_part};if test $? -ne 0;then alt_toggle_boot_partition;alt_saveenv;reset;fi\0" \
    "ubifs_load=ubifsload ${raddr_kernel} /boot/${bootfile};if test $? -ne 0;then alt_toggle_boot_partition;alt_saveenv;reset;fi\0" \
    "set_current_part=if test ${bootId} -eq 0;then setenv current_part rootfs_even;setenv sig_vol sig_even;else setenv current_part rootfs_odd;setenv sig_vol sig_odd;fi\0" \
    "mtd_boot=run set_current_part;run ubifs_part;run ubifs_mount;run ubifs_load;run ramargs addtty addmisc addmacaddr addmtdparts;bootm ${raddr_kernel}\0" \
    "bootcmd=run set_mtdparts mtd_boot;if test $? -ne 0;then alt_toggle_boot_partition;alt_saveenv;reset;fi\0" \
    "net_boot=bcm_init && run net_kernel_load && run set_mtdparts ramargs addtty addmisc addmacaddr addmtdparts " \
        "&& bootm ${raddr_kernel}\0" \
    "net_kernel_load=tftp ${raddr_kernel} ${user_dir}/${ramdisk_file}\0" \
    "root_upd=bcm_init " \
        "&& run set_mtdparts set_current_part " \
        "&& ubi part ubi "\
        "&& tftp ${raddr_tftp} ${user_dir}/rootfs.ubifs " \
        "&& ubi writevol ${raddr_tftp} ${current_part} ${filesize} " \
        "&& tftp ${raddr_tftp} ${user_dir}/sig.ubifs " \
        "&& ubi writevol ${raddr_tftp} ${sig_vol} ${filesize}\0" \
    "ubi_upd=bcm_init && tftp ${raddr_tftp} ${user_dir}/${ubifs_file} && nand erase ${naddr_ubi} ${nsize_ubi} && nand write ${raddr_tftp} ${naddr_ubi} ${filesize}\0" \
    "set_current_bootloader=if test ${bootId} -eq 0;then setenv current_bootloader ${naddr_uboot_even};else setenv current_bootloader ${naddr_uboot_odd;fi\0" \
    "set_current_env=if test ${bootId} -eq 0;then setenv current_env ${naddr_uboot_even_env_pri};else setenv current_env ${naddr_uboot_odd_env_pri};fi\0" \
    "uboot_upd=bcm_init && run set_current_bootloader " \
        "&& tftp ${raddr_tftp} ${user_dir}/bootloader.bin " \
        "&& nand erase clean ${current_bootloader} 0x100000 " \
        "&& nand write ${raddr_tftp} ${current_bootloader} ${filesize}\0" \
    "erase_env=run set_current_env && nand erase clean ${current_env} 0x100000\0"

#define CONFIG_EXTRA_ENV_SETTINGS									\
	CONFIG_UBOOT_DEF_ENV


#define GLOBAL_GPIO_MUX_BASE	GLOBAL_GPIO_MUX_0
#define CONFIG_SYS_G2_GPIO_TABLE {									\
{													\
/* GPIO Core 0 */											\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[00] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[01] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[02] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[03] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[04] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[05] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[06] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[07] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[08] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[09] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[10] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[11] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[12] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[13] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[14] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[15] */						\
{PER_GPIO0_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[16] */						\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[17] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[18] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[19] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[20] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[21] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO0[22] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[23] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[24] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[25] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[26] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[27] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[28] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[29] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[30] */					\
{PER_GPIO0_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO0[31] */					\
},													\
{													\
/* GPIO Core 1 */											\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[00] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[01] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[02] */						\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[03] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[04] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[05] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[06] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[07] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[08] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO1[09] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[10] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[11] */						\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[12] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[13] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[14] */						\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[15] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[16] */						\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[17] */					\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[18] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[19] */						\
{PER_GPIO1_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[20] */					\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[21] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[22] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[23] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[24] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[25] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[26] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[27] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[28] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[29] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[30] */						\
{PER_GPIO1_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO1[31] */						\
},													\
{													\
/* GPIO Core 2 */											\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[00] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[01] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[02] */						\
{PER_GPIO2_CFG, GPIO_OUT, GPIO_SEL, GPIO_OUT_0},/* GPIO2[03] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[04] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[05] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[06] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[07] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[08] */						\
{PER_GPIO2_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[09] */					\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[10] */						\
{PER_GPIO2_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[11] */					\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[12] */						\
{PER_GPIO2_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[13] */					\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[14] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[15] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[16] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[17] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[18] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[19] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[20] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[21] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[22] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[23] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[24] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[25] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[26] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[27] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[28] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[29] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[30] */						\
{PER_GPIO2_CFG, GPIO_IN, GPIO_SEL, GPIO_NO_CHG},/* GPIO2[31] */						\
},													\
{													\
/* GPIO Core 3 */											\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[00] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[01] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[02] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[03] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[04] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[05] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[06] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[07] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[08] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[09] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[10] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[11] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[12] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[13] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[14] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[15] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[16] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[17] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[18] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[19] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[20] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[21] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[22] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[23] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[24] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[25] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[26] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[27] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[28] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[29] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[30] */						\
{PER_GPIO3_CFG, GPIO_IN, GPIO_ALT, GPIO_NO_CHG},/* GPIO3[31] */						\
},													\
{													\
/* GPIO Core 4 */											\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[00] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[01] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[02] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[03] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[04] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[05] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[06] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[07] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[08] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[09] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[10] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[11] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[12] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[13] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[14] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[15] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[16] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[17] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[18] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[19] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[20] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[21] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[22] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[23] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[24] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[25] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[26] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[27] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[28] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[29] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[30] */					\
{PER_GPIO4_CFG, GPIO_OUT, GPIO_SEL, GPIO_NO_CHG},/* GPIO4[31] */					\
}													\
}

#endif /* __CONFIG_H */

