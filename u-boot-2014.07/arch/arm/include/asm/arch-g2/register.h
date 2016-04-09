/*
 * register.h
 */
#ifndef __G2_REGISTER_H
#define __G2_REGISTER_H

#include "cs_types.h"

#define GLOBAL_BLOCK_RESET		0xf0000004
#define GLOBAL_BLOCK_RESET_dft                   0x00600000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 reset_ts             :  1 ; /* bits 31:31 */
    cs_uint32 reset_lcd            :  1 ; /* bits 30:30 */
    cs_uint32 reset_phy            :  1 ; /* bits 29:29 */
    cs_uint32 reset_sd             :  1 ; /* bits 28:28 */
    cs_uint32 reset_rram           :  1 ; /* bits 27:27 */
    cs_uint32 reset_rreg           :  1 ; /* bits 26:26 */
    cs_uint32 reset_rniadapt       :  1 ; /* bits 25:25 */
    cs_uint32 reset_rcrypto        :  1 ; /* bits 24:24 */
    cs_uint32 reset_rdma           :  1 ; /* bits 23:23 */
    cs_uint32 reset_rcpu1          :  1 ; /* bits 22:22 */
    cs_uint32 reset_rcpu0          :  1 ; /* bits 21:21 */
    cs_uint32 reset_pwr            :  1 ; /* bits 20:20 */
    cs_uint32 reset_cir            :  1 ; /* bits 19:19 */
    cs_uint32 reset_rtc            :  1 ; /* bits 18:18 */
    cs_uint32 reset_ni_xram        :  1 ; /* bits 17:17 */
    cs_uint32 reset_dma            :  1 ; /* bits 16:16 */
    cs_uint32 reset_per            :  1 ; /* bits 15:15 */
    cs_uint32 reset_flash          :  1 ; /* bits 14:14 */
    cs_uint32 reset_usb            :  1 ; /* bits 13:13 */
    cs_uint32 reset_sata3          :  1 ; /* bits 12:12 */
    cs_uint32 reset_sata2          :  1 ; /* bits 11:11 */
    cs_uint32 reset_sata1          :  1 ; /* bits 10:10 */
    cs_uint32 reset_sata0          :  1 ; /* bits 9:9 */
    cs_uint32 reset_pcie2          :  1 ; /* bits 8:8 */
    cs_uint32 reset_pcie1          :  1 ; /* bits 7:7 */
    cs_uint32 reset_pcie0          :  1 ; /* bits 6:6 */
    cs_uint32 reset_qm             :  1 ; /* bits 5:5 */
    cs_uint32 reset_sdram          :  1 ; /* bits 4:4 */
    cs_uint32 reset_sch            :  1 ; /* bits 3:3 */
    cs_uint32 reset_tm             :  1 ; /* bits 2:2 */
    cs_uint32 reset_fe             :  1 ; /* bits 1:1 */
    cs_uint32 reset_ni             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 reset_ni             :  1 ; /* bits 0:0 */
    cs_uint32 reset_fe             :  1 ; /* bits 1:1 */
    cs_uint32 reset_tm             :  1 ; /* bits 2:2 */
    cs_uint32 reset_sch            :  1 ; /* bits 3:3 */
    cs_uint32 reset_sdram          :  1 ; /* bits 4:4 */
    cs_uint32 reset_qm             :  1 ; /* bits 5:5 */
    cs_uint32 reset_pcie0          :  1 ; /* bits 6:6 */
    cs_uint32 reset_pcie1          :  1 ; /* bits 7:7 */
    cs_uint32 reset_pcie2          :  1 ; /* bits 8:8 */
    cs_uint32 reset_sata0          :  1 ; /* bits 9:9 */
    cs_uint32 reset_sata1          :  1 ; /* bits 10:10 */
    cs_uint32 reset_sata2          :  1 ; /* bits 11:11 */
    cs_uint32 reset_sata3          :  1 ; /* bits 12:12 */
    cs_uint32 reset_usb            :  1 ; /* bits 13:13 */
    cs_uint32 reset_flash          :  1 ; /* bits 14:14 */
    cs_uint32 reset_per            :  1 ; /* bits 15:15 */
    cs_uint32 reset_dma            :  1 ; /* bits 16:16 */
    cs_uint32 reset_ni_xram        :  1 ; /* bits 17:17 */
    cs_uint32 reset_rtc            :  1 ; /* bits 18:18 */
    cs_uint32 reset_cir            :  1 ; /* bits 19:19 */
    cs_uint32 reset_pwr            :  1 ; /* bits 20:20 */
    cs_uint32 reset_rcpu0          :  1 ; /* bits 21:21 */
    cs_uint32 reset_rcpu1          :  1 ; /* bits 22:22 */
    cs_uint32 reset_rdma           :  1 ; /* bits 23:23 */
    cs_uint32 reset_rcrypto        :  1 ; /* bits 24:24 */
    cs_uint32 reset_rniadapt       :  1 ; /* bits 25:25 */
    cs_uint32 reset_rreg           :  1 ; /* bits 26:26 */
    cs_uint32 reset_rram           :  1 ; /* bits 27:27 */
    cs_uint32 reset_sd             :  1 ; /* bits 28:28 */
    cs_uint32 reset_phy            :  1 ; /* bits 29:29 */
    cs_uint32 reset_lcd            :  1 ; /* bits 30:30 */
    cs_uint32 reset_ts             :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} GLOBAL_BLOCK_RESET_t;

#define GLOBAL_STRAP			0xf000000c
#define GLOBAL_IO_DRIVE_STRENGTH	0xf00000b4
#define GLOBAL_SOFTWARE			0xf00000b8
#define GLOBAL_SOFTWARE2		0xf00000bc

#define GLOBAL_GLOBAL_CONFIG		0xf0000010

#define GLOBAL_PIN_MUX			0xf0000018
typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 flash_mux_sel        :  1 ; /* bits 31:31 */
    cs_uint32 fmro_enable          :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 pmux_frac_clk_en_gpio1_16 :  1 ; /* bits 26:26 */
    cs_uint32 pmux_frac_clk_en_gpio1_11 :  1 ; /* bits 25:25 */
    cs_uint32 pmux_frac_clk_en_gpio1_10 :  1 ; /* bits 24:24 */
    cs_uint32 pmux_s2_gpio2_8      :  1 ; /* bits 23:23 */
    cs_uint32 pmux_s3_gpio2_9      :  1 ; /* bits 22:22 */
    cs_uint32 pmux_s2_gpio2_10     :  1 ; /* bits 21:21 */
    cs_uint32 pmux_s3_gpio2_11     :  1 ; /* bits 20:20 */
    cs_uint32 pmux_s0_gpio2_26     :  1 ; /* bits 19:19 */
    cs_uint32 pmux_s1_gpio2_27     :  1 ; /* bits 18:18 */
    cs_uint32 pmux_s2_gpio2_28     :  1 ; /* bits 17:17 */
    cs_uint32 pmux_s3_gpio2_29     :  1 ; /* bits 16:16 */
    cs_uint32 pmux_s1_gpio2_12     :  1 ; /* bits 15:15 */
    cs_uint32 pmux_s0_gpio2_13     :  1 ; /* bits 14:14 */
    cs_uint32 pmux_s0_gpio0_26     :  1 ; /* bits 13:13 */
    cs_uint32 pmux_s1_gpio0_25     :  1 ; /* bits 12:12 */
    cs_uint32 pmux_s1_gpio0_22     :  1 ; /* bits 11:11 */
    cs_uint32 pmux_s0_gpio0_21     :  1 ; /* bits 10:10 */
    cs_uint32 pwm_sf               :  1 ; /* bits 9:9 */
    cs_uint32 pwm_pf               :  1 ; /* bits 8:8 */
    cs_uint32 pwm_nf               :  1 ; /* bits 7:7 */
    cs_uint32 uart_0_hwfc_gpio_enable :  1 ; /* bits 6:6 */
    cs_uint32 uart_0_hwfc_spi_enable :  1 ; /* bits 5:5 */
    cs_uint32 uart_1_hwfc_enable   :  1 ; /* bits 4:4 */
    cs_uint32 uart_0_hwfc_enable   :  1 ; /* bits 3:3 */
    cs_uint32 arm_trace_enable     :  1 ; /* bits 2:2 */
    cs_uint32 pmux_flash           :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pmux_flash           :  2 ; /* bits 1:0 */
    cs_uint32 arm_trace_enable     :  1 ; /* bits 2:2 */
    cs_uint32 uart_0_hwfc_enable   :  1 ; /* bits 3:3 */
    cs_uint32 uart_1_hwfc_enable   :  1 ; /* bits 4:4 */
    cs_uint32 uart_0_hwfc_spi_enable :  1 ; /* bits 5:5 */
    cs_uint32 uart_0_hwfc_gpio_enable :  1 ; /* bits 6:6 */
    cs_uint32 pwm_nf               :  1 ; /* bits 7:7 */
    cs_uint32 pwm_pf               :  1 ; /* bits 8:8 */
    cs_uint32 pwm_sf               :  1 ; /* bits 9:9 */
    cs_uint32 pmux_s0_gpio0_21     :  1 ; /* bits 10:10 */
    cs_uint32 pmux_s1_gpio0_22     :  1 ; /* bits 11:11 */
    cs_uint32 pmux_s1_gpio0_25     :  1 ; /* bits 12:12 */
    cs_uint32 pmux_s0_gpio0_26     :  1 ; /* bits 13:13 */
    cs_uint32 pmux_s0_gpio2_13     :  1 ; /* bits 14:14 */
    cs_uint32 pmux_s1_gpio2_12     :  1 ; /* bits 15:15 */
    cs_uint32 pmux_s3_gpio2_29     :  1 ; /* bits 16:16 */
    cs_uint32 pmux_s2_gpio2_28     :  1 ; /* bits 17:17 */
    cs_uint32 pmux_s1_gpio2_27     :  1 ; /* bits 18:18 */
    cs_uint32 pmux_s0_gpio2_26     :  1 ; /* bits 19:19 */
    cs_uint32 pmux_s3_gpio2_11     :  1 ; /* bits 20:20 */
    cs_uint32 pmux_s2_gpio2_10     :  1 ; /* bits 21:21 */
    cs_uint32 pmux_s3_gpio2_9      :  1 ; /* bits 22:22 */
    cs_uint32 pmux_s2_gpio2_8      :  1 ; /* bits 23:23 */
    cs_uint32 pmux_frac_clk_en_gpio1_10 :  1 ; /* bits 24:24 */
    cs_uint32 pmux_frac_clk_en_gpio1_11 :  1 ; /* bits 25:25 */
    cs_uint32 pmux_frac_clk_en_gpio1_16 :  1 ; /* bits 26:26 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 fmro_enable          :  1 ; /* bits 30:30 */
    cs_uint32 flash_mux_sel        :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} GLOBAL_PIN_MUX_t;

#define GLOBAL_GPIO_MUX_0		0xf000001c
#define GLOBAL_GPIO_MUX_1		0xf0000020
#define GLOBAL_GPIO_MUX_2		0xf0000024
#define GLOBAL_GPIO_MUX_3		0xf0000028
#define GLOBAL_GPIO_MUX_4		0xf000002c

#define GLOBAL_DDR_PLL                           0xf0000030
#define GLOBAL_DDR_PLL_dft                       0x00462be9

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 ddr_phy_reset        :  1 ; /* bits 22:22 */
    cs_uint32 p                    :  6 ; /* bits 21:16 */
    cs_uint32 s                    :  3 ; /* bits 15:13 */
    cs_uint32 enable               :  1 ; /* bits 12:12 */
    cs_uint32 vsel                 :  1 ; /* bits 11:11 */
    cs_uint32 m                    : 10 ; /* bits 10:1 */
    cs_uint32 reset                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 reset                :  1 ; /* bits 0:0 */
    cs_uint32 m                    : 10 ; /* bits 10:1 */
    cs_uint32 vsel                 :  1 ; /* bits 11:11 */
    cs_uint32 enable               :  1 ; /* bits 12:12 */
    cs_uint32 s                    :  3 ; /* bits 15:13 */
    cs_uint32 p                    :  6 ; /* bits 21:16 */
    cs_uint32 ddr_phy_reset        :  1 ; /* bits 22:22 */
    cs_uint32 rsrvd1               :  9 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} GLOBAL_DDR_PLL_t;

#define GLOBAL_ARM_STATE                         0xf0000040
#define GLOBAL_ARM_STATE_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 cpu1_wd_req          :  1 ; /* bits 22:22 */
    cs_uint32 cpu0_wd_req          :  1 ; /* bits 21:21 */
    cs_uint32 pll3_switch_state    :  1 ; /* bits 20:20 */
    cs_uint32 pll2_switch_state    :  1 ; /* bits 19:19 */
    cs_uint32 pll1_switch_state    :  1 ; /* bits 18:18 */
    cs_uint32 pll0_switch_state    :  1 ; /* bits 17:17 */
    cs_uint32 pll3_lock            :  1 ; /* bits 16:16 */
    cs_uint32 pll2_lock            :  1 ; /* bits 15:15 */
    cs_uint32 pll1_lock            :  1 ; /* bits 14:14 */
    cs_uint32 pll0_lock            :  1 ; /* bits 13:13 */
    cs_uint32 l2_clkstopped        :  1 ; /* bits 12:12 */
    cs_uint32 l2_idle              :  1 ; /* bits 11:11 */
    cs_uint32 standbywfe1          :  1 ; /* bits 10:10 */
    cs_uint32 standbywfe0          :  1 ; /* bits 9:9 */
    cs_uint32 standbywfi1          :  1 ; /* bits 8:8 */
    cs_uint32 standbywfi0          :  1 ; /* bits 7:7 */
    cs_uint32 pwrctlo1             :  2 ; /* bits 6:5 */
    cs_uint32 pwrctlo0             :  2 ; /* bits 4:3 */
    cs_uint32 snpnamp1             :  1 ; /* bits 2:2 */
    cs_uint32 snpnamp0             :  1 ; /* bits 1:1 */
    cs_uint32 evento               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 evento               :  1 ; /* bits 0:0 */
    cs_uint32 snpnamp0             :  1 ; /* bits 1:1 */
    cs_uint32 snpnamp1             :  1 ; /* bits 2:2 */
    cs_uint32 pwrctlo0             :  2 ; /* bits 4:3 */
    cs_uint32 pwrctlo1             :  2 ; /* bits 6:5 */
    cs_uint32 standbywfi0          :  1 ; /* bits 7:7 */
    cs_uint32 standbywfi1          :  1 ; /* bits 8:8 */
    cs_uint32 standbywfe0          :  1 ; /* bits 9:9 */
    cs_uint32 standbywfe1          :  1 ; /* bits 10:10 */
    cs_uint32 l2_idle              :  1 ; /* bits 11:11 */
    cs_uint32 l2_clkstopped        :  1 ; /* bits 12:12 */
    cs_uint32 pll0_lock            :  1 ; /* bits 13:13 */
    cs_uint32 pll1_lock            :  1 ; /* bits 14:14 */
    cs_uint32 pll2_lock            :  1 ; /* bits 15:15 */
    cs_uint32 pll3_lock            :  1 ; /* bits 16:16 */
    cs_uint32 pll0_switch_state    :  1 ; /* bits 17:17 */
    cs_uint32 pll1_switch_state    :  1 ; /* bits 18:18 */
    cs_uint32 pll2_switch_state    :  1 ; /* bits 19:19 */
    cs_uint32 pll3_switch_state    :  1 ; /* bits 20:20 */
    cs_uint32 cpu0_wd_req          :  1 ; /* bits 21:21 */
    cs_uint32 cpu1_wd_req          :  1 ; /* bits 22:22 */
    cs_uint32 rsrvd1               :  9 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} GLOBAL_ARM_STATE_t;

#define GOLDENGATE_TWD_BASE		0xf8000600

/*
 * FLASH_axi
 */

#define FLASH_ID                                 0xf0050000
#define FLASH_ID_dft                             0x00000101

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 flashDevID           : 24 ; /* bits 31:8 */
    cs_uint32 flashRevID           :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 flashRevID           :  8 ; /* bits 7:0 */
    cs_uint32 flashDevID           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_ID_t;

#define FLASH_TIMEOUT                            0xf0050004
#define FLASH_TIMEOUT_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 timeout_load         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 timeout_load         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_TIMEOUT_t;

#define FLASH_STATUS                             0xf0050008
#define FLASH_STATUS_dft                         0x06000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 nflash_rbIn_d        :  1 ; /* bits 26:26 */
    cs_uint32 pflash_rbIn_d        :  1 ; /* bits 25:25 */
    cs_uint32 rsrvd2               : 13 ;
    cs_uint32 nState               :  4 ; /* bits 11:8 */
    cs_uint32 pState               :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 sState               :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sState               :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pState               :  4 ; /* bits 7:4 */
    cs_uint32 nState               :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               : 13 ;
    cs_uint32 pflash_rbIn_d        :  1 ; /* bits 25:25 */
    cs_uint32 nflash_rbIn_d        :  1 ; /* bits 26:26 */
    cs_uint32 rsrvd3               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_STATUS_t;

#define FLASH_TYPE                               0xf005000c
#define FLASH_TYPE_dft                           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 16 ;
    cs_uint32 flashPin             :  1 ; /* bits 15:15 */
    cs_uint32 flashType            :  3 ; /* bits 14:12 */
    cs_uint32 flashWidth           :  1 ; /* bits 11:11 */
    cs_uint32 flashSize            :  2 ; /* bits 10:9 */
    cs_uint32 rsrvd1               :  9 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 flashSize            :  2 ; /* bits 10:9 */
    cs_uint32 flashWidth           :  1 ; /* bits 11:11 */
    cs_uint32 flashType            :  3 ; /* bits 14:12 */
    cs_uint32 flashPin             :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_TYPE_t;

#define FLASH_SF_ACCESS                          0xf0050010
#define FLASH_SF_ACCESS_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 14 ;
    cs_uint32 sflashHSRd           :  1 ; /* bits 17:17 */
    cs_uint32 sflashCeAlt          :  1 ; /* bits 16:16 */
    cs_uint32 sflashCnMode         :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 sflashForceBurst     :  1 ; /* bits 13:13 */
    cs_uint32 sflashForceTerm      :  1 ; /* bits 12:12 */
    cs_uint32 sflashAcCode         :  4 ; /* bits 11:8 */
    cs_uint32 sflashOpCode         :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sflashOpCode         :  8 ; /* bits 7:0 */
    cs_uint32 sflashAcCode         :  4 ; /* bits 11:8 */
    cs_uint32 sflashForceTerm      :  1 ; /* bits 12:12 */
    cs_uint32 sflashForceBurst     :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 sflashCnMode         :  1 ; /* bits 15:15 */
    cs_uint32 sflashCeAlt          :  1 ; /* bits 16:16 */
    cs_uint32 sflashHSRd           :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd2               : 14 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_SF_ACCESS_t;

#define FLASH_SF_ADDRESS                         0xf0050014
#define FLASH_SF_ADDRESS_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 sflashRegAddr        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sflashRegAddr        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_SF_ADDRESS_t;

#define FLASH_SF_DATA                            0xf0050018
#define FLASH_SF_DATA_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 sflashRegWData       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sflashRegWData       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_SF_DATA_t;

#define FLASH_SF_TIMING                          0xf005001c
#define FLASH_SF_TIMING_dft                      0x00373737

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sflashClkWidth       :  2 ; /* bits 25:24 */
    cs_uint32 sflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 sflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 sflashIdleTime       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sflashIdleTime       :  8 ; /* bits 7:0 */
    cs_uint32 sflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 sflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 sflashClkWidth       :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd1               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_SF_TIMING_t;

#define FLASH_PF_ACCESS                          0xf0050020
#define FLASH_PF_ACCESS_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 pflashWrPol          :  1 ; /* bits 23:23 */
    cs_uint32 pflashRdPol          :  1 ; /* bits 22:22 */
    cs_uint32 pflashBzPol          :  1 ; /* bits 21:21 */
    cs_uint32 pflashBzChk          :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 pflashCeAlt          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               : 11 ;
    cs_uint32 pflashExtAddr        :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pflashExtAddr        :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               : 11 ;
    cs_uint32 pflashCeAlt          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 pflashBzChk          :  1 ; /* bits 20:20 */
    cs_uint32 pflashBzPol          :  1 ; /* bits 21:21 */
    cs_uint32 pflashRdPol          :  1 ; /* bits 22:22 */
    cs_uint32 pflashWrPol          :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_PF_ACCESS_t;

#define FLASH_PF_TIMING                          0xf0050024
#define FLASH_PF_TIMING_dft                      0x000f0f07

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 pflashClkWidth       :  2 ; /* bits 25:24 */
    cs_uint32 pflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 pflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 pflashIdleTime       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pflashIdleTime       :  8 ; /* bits 7:0 */
    cs_uint32 pflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 pflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 pflashClkWidth       :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd1               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_PF_TIMING_t;

#define FLASH_NF_ACCESS                          0xf0050028
#define FLASH_NF_ACCESS_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  4 ;
    cs_uint32 FIFO_WRTH            :  2 ; /* bits 27:26 */
    cs_uint32 FIFO_RDTH            :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 autoReset            :  1 ; /* bits 16:16 */
    cs_uint32 nflashCeAlt          :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nflashRegWidth       :  2 ; /* bits 11:10 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 nflashExtAddr        :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashExtAddr        :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 nflashRegWidth       :  2 ; /* bits 11:10 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nflashCeAlt          :  1 ; /* bits 15:15 */
    cs_uint32 autoReset            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 FIFO_RDTH            :  2 ; /* bits 25:24 */
    cs_uint32 FIFO_WRTH            :  2 ; /* bits 27:26 */
    cs_uint32 rsrvd4               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ACCESS_t;

#define FLASH_NF_COUNT                           0xf005002c
#define FLASH_NF_COUNT_dft                       0xffffff00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 nflashRegOobCount    : 10 ; /* bits 31:22 */
    cs_uint32 nflashRegDataCount   : 14 ; /* bits 21:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 nflashRegAddrCount   :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 nflashRegCmdCount    :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegCmdCount    :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 nflashRegAddrCount   :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 nflashRegDataCount   : 14 ; /* bits 21:8 */
    cs_uint32 nflashRegOobCount    : 10 ; /* bits 31:22 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_COUNT_t;

#define FLASH_NF_COMMAND                         0xf0050030
#define FLASH_NF_COMMAND_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 nflashRegCmd2        :  8 ; /* bits 23:16 */
    cs_uint32 nflashRegCmd1        :  8 ; /* bits 15:8 */
    cs_uint32 nflashRegCmd0        :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegCmd0        :  8 ; /* bits 7:0 */
    cs_uint32 nflashRegCmd1        :  8 ; /* bits 15:8 */
    cs_uint32 nflashRegCmd2        :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_COMMAND_t;

#define FLASH_NF_ADDRESS_1                       0xf0050034
#define FLASH_NF_ADDRESS_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 nflashRegAddr3       :  8 ; /* bits 31:24 */
    cs_uint32 nflashRegAddr2       :  8 ; /* bits 23:16 */
    cs_uint32 nflashRegAddr1       :  8 ; /* bits 15:8 */
    cs_uint32 nflashRegAddr0       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegAddr0       :  8 ; /* bits 7:0 */
    cs_uint32 nflashRegAddr1       :  8 ; /* bits 15:8 */
    cs_uint32 nflashRegAddr2       :  8 ; /* bits 23:16 */
    cs_uint32 nflashRegAddr3       :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ADDRESS_1_t;

#define FLASH_NF_ADDRESS_2                       0xf0050038
#define FLASH_NF_ADDRESS_2_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 nflashRegAddr4       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegAddr4       :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ADDRESS_2_t;

#define FLASH_NF_DATA                            0xf005003c
#define FLASH_NF_DATA_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 nflashRegWData       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegWData       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_DATA_t;

#define FLASH_NF_TIMING                          0xf0050040
#define FLASH_NF_TIMING_dft                      0x00041703

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 nflashClkWidth       :  3 ; /* bits 26:24 */
    cs_uint32 nflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 nflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 nflashIdleTime       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashIdleTime       :  8 ; /* bits 7:0 */
    cs_uint32 nflashHoldTime       :  8 ; /* bits 15:8 */
    cs_uint32 nflashSetupTime      :  8 ; /* bits 23:16 */
    cs_uint32 nflashClkWidth       :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd1               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_TIMING_t;

#define FLASH_NF_ECC_STATUS                      0xf0050044
#define FLASH_NF_ECC_STATUS_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccDone              :  1 ; /* bits 31:31 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 eccErrWord           :  8 ; /* bits 23:16 */
    cs_uint32 eccErrByte           :  9 ; /* bits 15:7 */
    cs_uint32 eccErrBit            :  4 ; /* bits 6:3 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 eccStatus            :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccStatus            :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 eccErrBit            :  4 ; /* bits 6:3 */
    cs_uint32 eccErrByte           :  9 ; /* bits 15:7 */
    cs_uint32 eccErrWord           :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 eccDone              :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_STATUS_t;

#define FLASH_NF_ECC_CONTROL                     0xf0050048
#define FLASH_NF_ECC_CONTROL_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 23 ;
    cs_uint32 eccEn                :  1 ; /* bits 8:8 */
    cs_uint32 eccCodeSel           :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 eccGenMode           :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               :  1 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 eccGenMode           :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 eccCodeSel           :  4 ; /* bits 7:4 */
    cs_uint32 eccEn                :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_CONTROL_t;

#define FLASH_NF_ECC_OOB                         0xf005004c
#define FLASH_NF_ECC_OOB_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeOob           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeOob           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_OOB_t;

#define FLASH_NF_ECC_GEN0                        0xf0050050
#define FLASH_NF_ECC_GEN0_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen0          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen0          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN0_t;

#define FLASH_NF_ECC_GEN1                        0xf0050054
#define FLASH_NF_ECC_GEN1_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen1          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen1          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN1_t;

#define FLASH_NF_ECC_GEN2                        0xf0050058
#define FLASH_NF_ECC_GEN2_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen2          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen2          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN2_t;

#define FLASH_NF_ECC_GEN3                        0xf005005c
#define FLASH_NF_ECC_GEN3_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen3          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen3          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN3_t;

#define FLASH_NF_ECC_GEN4                        0xf0050060
#define FLASH_NF_ECC_GEN4_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen4          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen4          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN4_t;

#define FLASH_NF_ECC_GEN5                        0xf0050064
#define FLASH_NF_ECC_GEN5_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen5          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen5          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN5_t;

#define FLASH_NF_ECC_GEN6                        0xf0050068
#define FLASH_NF_ECC_GEN6_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen6          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen6          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN6_t;

#define FLASH_NF_ECC_GEN7                        0xf005006c
#define FLASH_NF_ECC_GEN7_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen7          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen7          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN7_t;

#define FLASH_NF_ECC_GEN8                        0xf0050070
#define FLASH_NF_ECC_GEN8_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen8          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen8          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN8_t;

#define FLASH_NF_ECC_GEN9                        0xf0050074
#define FLASH_NF_ECC_GEN9_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen9          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen9          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN9_t;

#define FLASH_NF_ECC_GEN10                       0xf0050078
#define FLASH_NF_ECC_GEN10_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen10         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen10         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN10_t;

#define FLASH_NF_ECC_GEN11                       0xf005007c
#define FLASH_NF_ECC_GEN11_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen11         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen11         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN11_t;

#define FLASH_NF_ECC_GEN12                       0xf0050080
#define FLASH_NF_ECC_GEN12_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen12         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen12         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN12_t;

#define FLASH_NF_ECC_GEN13                       0xf0050084
#define FLASH_NF_ECC_GEN13_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen13         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen13         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN13_t;

#define FLASH_NF_ECC_GEN14                       0xf0050088
#define FLASH_NF_ECC_GEN14_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen14         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen14         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN14_t;

#define FLASH_NF_ECC_GEN15                       0xf005008c
#define FLASH_NF_ECC_GEN15_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 eccCodeGen15         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccCodeGen15         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_GEN15_t;

#define FLASH_NF_FIFO_CONTROL                    0xf0050090
#define FLASH_NF_FIFO_CONTROL_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 fifoDbgSel           :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 fifoCmd              :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 fifoCmd              :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 fifoDbgSel           :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_FIFO_CONTROL_t;

#define FLASH_NF_FIFO_STATUS                     0xf0050094
#define FLASH_NF_FIFO_STATUS_dft                 0x00000004

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  8 ;
    cs_uint32 f_addr_count         :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 f_ptr_wr             :  5 ; /* bits 13:9 */
    cs_uint32 f_ptr_rd             :  5 ; /* bits 8:4 */
    cs_uint32 f_full               :  1 ; /* bits 3:3 */
    cs_uint32 f_empty              :  1 ; /* bits 2:2 */
    cs_uint32 f_state              :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 f_state              :  2 ; /* bits 1:0 */
    cs_uint32 f_empty              :  1 ; /* bits 2:2 */
    cs_uint32 f_full               :  1 ; /* bits 3:3 */
    cs_uint32 f_ptr_rd             :  5 ; /* bits 8:4 */
    cs_uint32 f_ptr_wr             :  5 ; /* bits 13:9 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 f_addr_count         :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_FIFO_STATUS_t;

#define FLASH_NF_FIFO_ADDRESS                    0xf0050098
#define FLASH_NF_FIFO_ADDRESS_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 f_AXADDR             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 f_AXADDR             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_FIFO_ADDRESS_t;

#define FLASH_NF_FIFO_MATCH_ADDRESS              0xf005009c
#define FLASH_NF_FIFO_MATCH_ADDRESS_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 f_AXADDR_compare     : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 f_AXADDR_compare     : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_FIFO_MATCH_ADDRESS_t;

#define FLASH_NF_FIFO_DATA                       0xf00500a0
#define FLASH_NF_FIFO_DATA_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 f_ebuf_mem1          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 f_ebuf_mem1          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_FIFO_DATA_t;

#define FLASH_FLASH_ACCESS_START                 0xf00500a4
#define FLASH_FLASH_ACCESS_START_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 18 ;
    cs_uint32 nflashRegCmd         :  2 ; /* bits 13:12 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 fifoReq              :  1 ; /* bits 2:2 */
    cs_uint32 sflashRegReq         :  1 ; /* bits 1:1 */
    cs_uint32 nflashRegReq         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nflashRegReq         :  1 ; /* bits 0:0 */
    cs_uint32 sflashRegReq         :  1 ; /* bits 1:1 */
    cs_uint32 fifoReq              :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 nflashRegCmd         :  2 ; /* bits 13:12 */
    cs_uint32 rsrvd2               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_FLASH_ACCESS_START_t;

#define FLASH_NF_ECC_RESET                       0xf00500a8
#define FLASH_NF_ECC_RESET_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 nflash_reset         :  1 ; /* bits 2:2 */
    cs_uint32 fifoClear            :  1 ; /* bits 1:1 */
    cs_uint32 eccClear             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 eccClear             :  1 ; /* bits 0:0 */
    cs_uint32 fifoClear            :  1 ; /* bits 1:1 */
    cs_uint32 nflash_reset         :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_ECC_RESET_t;

#define FLASH_FLASH_INTERRUPT                    0xf00500ac
#define FLASH_FLASH_INTERRUPT_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 bchDecIrq            :  1 ; /* bits 7:7 */
    cs_uint32 bchGenIrq            :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 nfWdtIrq             :  1 ; /* bits 4:4 */
    cs_uint32 eccIrq               :  1 ; /* bits 3:3 */
    cs_uint32 f_addr_err           :  1 ; /* bits 2:2 */
    cs_uint32 fifoIrq              :  1 ; /* bits 1:1 */
    cs_uint32 regIrq               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 regIrq               :  1 ; /* bits 0:0 */
    cs_uint32 fifoIrq              :  1 ; /* bits 1:1 */
    cs_uint32 f_addr_err           :  1 ; /* bits 2:2 */
    cs_uint32 eccIrq               :  1 ; /* bits 3:3 */
    cs_uint32 nfWdtIrq             :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 bchGenIrq            :  1 ; /* bits 6:6 */
    cs_uint32 bchDecIrq            :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_FLASH_INTERRUPT_t;

#define FLASH_FLASH_MASK                         0xf00500b0
#define FLASH_FLASH_MASK_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 bchDecIrqMask        :  1 ; /* bits 7:7 */
    cs_uint32 bchGenIrqMask        :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 nfWdtIrqMask         :  1 ; /* bits 4:4 */
    cs_uint32 eccIrqMask           :  1 ; /* bits 3:3 */
    cs_uint32 f_addr_IrqMask       :  1 ; /* bits 2:2 */
    cs_uint32 fifoIrqMask          :  1 ; /* bits 1:1 */
    cs_uint32 flashRegIrqMask      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 flashRegIrqMask      :  1 ; /* bits 0:0 */
    cs_uint32 fifoIrqMask          :  1 ; /* bits 1:1 */
    cs_uint32 f_addr_IrqMask       :  1 ; /* bits 2:2 */
    cs_uint32 eccIrqMask           :  1 ; /* bits 3:3 */
    cs_uint32 nfWdtIrqMask         :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 bchGenIrqMask        :  1 ; /* bits 6:6 */
    cs_uint32 bchDecIrqMask        :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_FLASH_MASK_t;

#define FLASH_NF_BCH_STATUS                      0xf00500b4
#define FLASH_NF_BCH_STATUS_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchGenDone           :  1 ; /* bits 31:31 */
    cs_uint32 bchDecDone           :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               : 22 ;
    cs_uint32 bchErrNum            :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 bchDecStatus         :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchDecStatus         :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 bchErrNum            :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd2               : 22 ;
    cs_uint32 bchDecDone           :  1 ; /* bits 30:30 */
    cs_uint32 bchGenDone           :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_STATUS_t;

#define FLASH_NF_BCH_ERROR_LOC01                 0xf00500b8
#define FLASH_NF_BCH_ERROR_LOC01_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc1           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc0           : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc0           : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc1           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC01_t;

#define FLASH_NF_BCH_ERROR_LOC23                 0xf00500bc
#define FLASH_NF_BCH_ERROR_LOC23_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc3           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc2           : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc2           : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc3           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC23_t;

#define FLASH_NF_BCH_ERROR_LOC45                 0xf00500c0
#define FLASH_NF_BCH_ERROR_LOC45_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc5           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc4           : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc4           : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc5           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC45_t;

#define FLASH_NF_BCH_ERROR_LOC67                 0xf00500c4
#define FLASH_NF_BCH_ERROR_LOC67_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc7           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc6           : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc6           : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc7           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC67_t;

#define FLASH_NF_BCH_ERROR_LOC89                 0xf00500c8
#define FLASH_NF_BCH_ERROR_LOC89_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc9           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc8           : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc8           : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc9           : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC89_t;

#define FLASH_NF_BCH_ERROR_LOC1011               0xf00500cc
#define FLASH_NF_BCH_ERROR_LOC1011_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 bchErrLoc11          : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc10          : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchErrLoc10          : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 bchErrLoc11          : 13 ; /* bits 28:16 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_ERROR_LOC1011_t;

#define FLASH_NF_BCH_CONTROL                     0xf00500d0
#define FLASH_NF_BCH_CONTROL_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 12 ;
    cs_uint32 bchTestCtrl          :  4 ; /* bits 19:16 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 bchErrCap            :  1 ; /* bits 9:9 */
    cs_uint32 bchEn                :  1 ; /* bits 8:8 */
    cs_uint32 bchCodeSel           :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 bchOpcode            :  1 ; /* bits 1:1 */
    cs_uint32 bchCompare           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCompare           :  1 ; /* bits 0:0 */
    cs_uint32 bchOpcode            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 bchCodeSel           :  4 ; /* bits 7:4 */
    cs_uint32 bchEn                :  1 ; /* bits 8:8 */
    cs_uint32 bchErrCap            :  1 ; /* bits 9:9 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 bchTestCtrl          :  4 ; /* bits 19:16 */
    cs_uint32 rsrvd3               : 12 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_CONTROL_t;

#define FLASH_NF_BCH_OOB0                        0xf00500d4
#define FLASH_NF_BCH_OOB0_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeOob0          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeOob0          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_OOB0_t;

#define FLASH_NF_BCH_OOB1                        0xf00500d8
#define FLASH_NF_BCH_OOB1_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeOob1          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeOob1          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_OOB1_t;

#define FLASH_NF_BCH_OOB2                        0xf00500dc
#define FLASH_NF_BCH_OOB2_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeOob2          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeOob2          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_OOB2_t;

#define FLASH_NF_BCH_OOB3                        0xf00500e0
#define FLASH_NF_BCH_OOB3_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeOob3          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeOob3          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_OOB3_t;

#define FLASH_NF_BCH_OOB4                        0xf00500e4
#define FLASH_NF_BCH_OOB4_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeOob4          : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeOob4          : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_OOB4_t;

#define FLASH_NF_BCH_GEN0_0                      0xf00500e8
#define FLASH_NF_BCH_GEN0_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen0_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen0_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN0_0_t;

#define FLASH_NF_BCH_GEN0_1                      0xf00500ec
#define FLASH_NF_BCH_GEN0_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen0_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen0_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN0_1_t;

#define FLASH_NF_BCH_GEN0_2                      0xf00500f0
#define FLASH_NF_BCH_GEN0_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen0_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen0_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN0_2_t;

#define FLASH_NF_BCH_GEN0_3                      0xf00500f4
#define FLASH_NF_BCH_GEN0_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen0_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen0_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN0_3_t;

#define FLASH_NF_BCH_GEN0_4                      0xf00500f8
#define FLASH_NF_BCH_GEN0_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen0_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen0_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN0_4_t;

#define FLASH_NF_BCH_GEN1_0                      0xf00500fc
#define FLASH_NF_BCH_GEN1_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen1_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen1_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN1_0_t;

#define FLASH_NF_BCH_GEN1_1                      0xf0050100
#define FLASH_NF_BCH_GEN1_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen1_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen1_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN1_1_t;

#define FLASH_NF_BCH_GEN1_2                      0xf0050104
#define FLASH_NF_BCH_GEN1_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen1_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen1_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN1_2_t;

#define FLASH_NF_BCH_GEN1_3                      0xf0050108
#define FLASH_NF_BCH_GEN1_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen1_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen1_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN1_3_t;

#define FLASH_NF_BCH_GEN1_4                      0xf005010c
#define FLASH_NF_BCH_GEN1_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen1_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen1_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN1_4_t;

#define FLASH_NF_BCH_GEN2_0                      0xf0050110
#define FLASH_NF_BCH_GEN2_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen2_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen2_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN2_0_t;

#define FLASH_NF_BCH_GEN2_1                      0xf0050114
#define FLASH_NF_BCH_GEN2_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen2_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen2_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN2_1_t;

#define FLASH_NF_BCH_GEN2_2                      0xf0050118
#define FLASH_NF_BCH_GEN2_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen2_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen2_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN2_2_t;

#define FLASH_NF_BCH_GEN2_3                      0xf005011c
#define FLASH_NF_BCH_GEN2_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen2_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen2_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN2_3_t;

#define FLASH_NF_BCH_GEN2_4                      0xf0050120
#define FLASH_NF_BCH_GEN2_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen2_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen2_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN2_4_t;

#define FLASH_NF_BCH_GEN3_0                      0xf0050124
#define FLASH_NF_BCH_GEN3_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen3_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen3_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN3_0_t;

#define FLASH_NF_BCH_GEN3_1                      0xf0050128
#define FLASH_NF_BCH_GEN3_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen3_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen3_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN3_1_t;

#define FLASH_NF_BCH_GEN3_2                      0xf005012c
#define FLASH_NF_BCH_GEN3_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen3_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen3_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN3_2_t;

#define FLASH_NF_BCH_GEN3_3                      0xf0050130
#define FLASH_NF_BCH_GEN3_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen3_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen3_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN3_3_t;

#define FLASH_NF_BCH_GEN3_4                      0xf0050134
#define FLASH_NF_BCH_GEN3_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen3_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen3_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN3_4_t;

#define FLASH_NF_BCH_GEN4_0                      0xf0050138
#define FLASH_NF_BCH_GEN4_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen4_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen4_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN4_0_t;

#define FLASH_NF_BCH_GEN4_1                      0xf005013c
#define FLASH_NF_BCH_GEN4_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen4_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen4_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN4_1_t;

#define FLASH_NF_BCH_GEN4_2                      0xf0050140
#define FLASH_NF_BCH_GEN4_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen4_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen4_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN4_2_t;

#define FLASH_NF_BCH_GEN4_3                      0xf0050144
#define FLASH_NF_BCH_GEN4_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen4_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen4_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN4_3_t;

#define FLASH_NF_BCH_GEN4_4                      0xf0050148
#define FLASH_NF_BCH_GEN4_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen4_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen4_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN4_4_t;

#define FLASH_NF_BCH_GEN5_0                      0xf005014c
#define FLASH_NF_BCH_GEN5_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen5_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen5_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN5_0_t;

#define FLASH_NF_BCH_GEN5_1                      0xf0050150
#define FLASH_NF_BCH_GEN5_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen5_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen5_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN5_1_t;

#define FLASH_NF_BCH_GEN5_2                      0xf0050154
#define FLASH_NF_BCH_GEN5_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen5_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen5_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN5_2_t;

#define FLASH_NF_BCH_GEN5_3                      0xf0050158
#define FLASH_NF_BCH_GEN5_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen5_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen5_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN5_3_t;

#define FLASH_NF_BCH_GEN5_4                      0xf005015c
#define FLASH_NF_BCH_GEN5_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen5_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen5_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN5_4_t;

#define FLASH_NF_BCH_GEN6_0                      0xf0050160
#define FLASH_NF_BCH_GEN6_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen6_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen6_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN6_0_t;

#define FLASH_NF_BCH_GEN6_1                      0xf0050164
#define FLASH_NF_BCH_GEN6_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen6_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen6_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN6_1_t;

#define FLASH_NF_BCH_GEN6_2                      0xf0050168
#define FLASH_NF_BCH_GEN6_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen6_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen6_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN6_2_t;

#define FLASH_NF_BCH_GEN6_3                      0xf005016c
#define FLASH_NF_BCH_GEN6_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen6_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen6_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN6_3_t;

#define FLASH_NF_BCH_GEN6_4                      0xf0050170
#define FLASH_NF_BCH_GEN6_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen6_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen6_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN6_4_t;

#define FLASH_NF_BCH_GEN7_0                      0xf0050174
#define FLASH_NF_BCH_GEN7_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen7_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen7_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN7_0_t;

#define FLASH_NF_BCH_GEN7_1                      0xf0050178
#define FLASH_NF_BCH_GEN7_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen7_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen7_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN7_1_t;

#define FLASH_NF_BCH_GEN7_2                      0xf005017c
#define FLASH_NF_BCH_GEN7_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen7_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen7_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN7_2_t;

#define FLASH_NF_BCH_GEN7_3                      0xf0050180
#define FLASH_NF_BCH_GEN7_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen7_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen7_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN7_3_t;

#define FLASH_NF_BCH_GEN7_4                      0xf0050184
#define FLASH_NF_BCH_GEN7_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen7_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen7_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN7_4_t;

#define FLASH_NF_BCH_GEN8_0                      0xf0050188
#define FLASH_NF_BCH_GEN8_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen8_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen8_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN8_0_t;

#define FLASH_NF_BCH_GEN8_1                      0xf005018c
#define FLASH_NF_BCH_GEN8_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen8_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen8_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN8_1_t;

#define FLASH_NF_BCH_GEN8_2                      0xf0050190
#define FLASH_NF_BCH_GEN8_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen8_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen8_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN8_2_t;

#define FLASH_NF_BCH_GEN8_3                      0xf0050194
#define FLASH_NF_BCH_GEN8_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen8_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen8_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN8_3_t;

#define FLASH_NF_BCH_GEN8_4                      0xf0050198
#define FLASH_NF_BCH_GEN8_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen8_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen8_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN8_4_t;

#define FLASH_NF_BCH_GEN9_0                      0xf005019c
#define FLASH_NF_BCH_GEN9_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen9_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen9_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN9_0_t;

#define FLASH_NF_BCH_GEN9_1                      0xf00501a0
#define FLASH_NF_BCH_GEN9_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen9_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen9_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN9_1_t;

#define FLASH_NF_BCH_GEN9_2                      0xf00501a4
#define FLASH_NF_BCH_GEN9_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen9_2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen9_2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN9_2_t;

#define FLASH_NF_BCH_GEN9_3                      0xf00501a8
#define FLASH_NF_BCH_GEN9_3_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen9_3        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen9_3        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN9_3_t;

#define FLASH_NF_BCH_GEN9_4                      0xf00501ac
#define FLASH_NF_BCH_GEN9_4_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen9_4        : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen9_4        : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN9_4_t;

#define FLASH_NF_BCH_GEN10_0                     0xf00501b0
#define FLASH_NF_BCH_GEN10_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen10_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen10_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN10_0_t;

#define FLASH_NF_BCH_GEN10_1                     0xf00501b4
#define FLASH_NF_BCH_GEN10_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen10_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen10_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN10_1_t;

#define FLASH_NF_BCH_GEN10_2                     0xf00501b8
#define FLASH_NF_BCH_GEN10_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen10_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen10_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN10_2_t;

#define FLASH_NF_BCH_GEN10_3                     0xf00501bc
#define FLASH_NF_BCH_GEN10_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen10_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen10_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN10_3_t;

#define FLASH_NF_BCH_GEN10_4                     0xf00501c0
#define FLASH_NF_BCH_GEN10_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen10_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen10_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN10_4_t;

#define FLASH_NF_BCH_GEN11_0                     0xf00501c4
#define FLASH_NF_BCH_GEN11_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen11_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen11_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN11_0_t;

#define FLASH_NF_BCH_GEN11_1                     0xf00501c8
#define FLASH_NF_BCH_GEN11_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen11_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen11_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN11_1_t;

#define FLASH_NF_BCH_GEN11_2                     0xf00501cc
#define FLASH_NF_BCH_GEN11_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen11_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen11_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN11_2_t;

#define FLASH_NF_BCH_GEN11_3                     0xf00501d0
#define FLASH_NF_BCH_GEN11_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen11_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen11_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN11_3_t;

#define FLASH_NF_BCH_GEN11_4                     0xf00501d4
#define FLASH_NF_BCH_GEN11_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen11_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen11_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN11_4_t;

#define FLASH_NF_BCH_GEN12_0                     0xf00501d8
#define FLASH_NF_BCH_GEN12_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen12_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen12_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN12_0_t;

#define FLASH_NF_BCH_GEN12_1                     0xf00501dc
#define FLASH_NF_BCH_GEN12_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen12_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen12_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN12_1_t;

#define FLASH_NF_BCH_GEN12_2                     0xf00501e0
#define FLASH_NF_BCH_GEN12_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen12_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen12_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN12_2_t;

#define FLASH_NF_BCH_GEN12_3                     0xf00501e4
#define FLASH_NF_BCH_GEN12_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen12_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen12_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN12_3_t;

#define FLASH_NF_BCH_GEN12_4                     0xf00501e8
#define FLASH_NF_BCH_GEN12_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen12_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen12_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN12_4_t;

#define FLASH_NF_BCH_GEN13_0                     0xf00501ec
#define FLASH_NF_BCH_GEN13_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen13_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen13_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN13_0_t;

#define FLASH_NF_BCH_GEN13_1                     0xf00501f0
#define FLASH_NF_BCH_GEN13_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen13_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen13_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN13_1_t;

#define FLASH_NF_BCH_GEN13_2                     0xf00501f4
#define FLASH_NF_BCH_GEN13_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen13_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen13_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN13_2_t;

#define FLASH_NF_BCH_GEN13_3                     0xf00501f8
#define FLASH_NF_BCH_GEN13_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen13_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen13_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN13_3_t;

#define FLASH_NF_BCH_GEN13_4                     0xf00501fc
#define FLASH_NF_BCH_GEN13_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen13_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen13_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN13_4_t;

#define FLASH_NF_BCH_GEN14_0                     0xf0050200
#define FLASH_NF_BCH_GEN14_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen14_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen14_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN14_0_t;

#define FLASH_NF_BCH_GEN14_1                     0xf0050204
#define FLASH_NF_BCH_GEN14_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen14_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen14_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN14_1_t;

#define FLASH_NF_BCH_GEN14_2                     0xf0050208
#define FLASH_NF_BCH_GEN14_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen14_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen14_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN14_2_t;

#define FLASH_NF_BCH_GEN14_3                     0xf005020c
#define FLASH_NF_BCH_GEN14_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen14_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen14_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN14_3_t;

#define FLASH_NF_BCH_GEN14_4                     0xf0050210
#define FLASH_NF_BCH_GEN14_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen14_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen14_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN14_4_t;

#define FLASH_NF_BCH_GEN15_0                     0xf0050214
#define FLASH_NF_BCH_GEN15_0_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen15_0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen15_0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN15_0_t;

#define FLASH_NF_BCH_GEN15_1                     0xf0050218
#define FLASH_NF_BCH_GEN15_1_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen15_1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen15_1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN15_1_t;

#define FLASH_NF_BCH_GEN15_2                     0xf005021c
#define FLASH_NF_BCH_GEN15_2_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen15_2       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen15_2       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN15_2_t;

#define FLASH_NF_BCH_GEN15_3                     0xf0050220
#define FLASH_NF_BCH_GEN15_3_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 bchCodeGen15_3       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen15_3       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN15_3_t;

#define FLASH_NF_BCH_GEN15_4                     0xf0050224
#define FLASH_NF_BCH_GEN15_4_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 bchCodeGen15_4       : 28 ; /* bits 27:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 bchCodeGen15_4       : 28 ; /* bits 27:0 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_NF_BCH_GEN15_4_t;

#define FLASH_FLASH_SPARE_0                      0xf0050228
#define FLASH_FLASH_SPARE_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 flash_spare0         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 flash_spare0         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_FLASH_SPARE_0_t;

#define FLASH_FLASH_SPARE_1                      0xf005022c
#define FLASH_FLASH_SPARE_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 flash_spare1         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 flash_spare1         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} FLASH_FLASH_SPARE_1_t;

/*
 * DMA_SSP
 */

#define DMA_DMA_SSP_RXDMA_CONTROL                0xf0090400
#define DMA_DMA_SSP_RXDMA_CONTROL_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 rx_check_own         :  1 ; /* bits 1:1 */
    cs_uint32 rx_dma_enable        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_dma_enable        :  1 ; /* bits 0:0 */
    cs_uint32 rx_check_own         :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXDMA_CONTROL_t;

#define DMA_DMA_SSP_TXDMA_CONTROL                0xf0090404
#define DMA_DMA_SSP_TXDMA_CONTROL_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 tx_check_own         :  1 ; /* bits 1:1 */
    cs_uint32 tx_dma_enable        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_dma_enable        :  1 ; /* bits 0:0 */
    cs_uint32 tx_check_own         :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXDMA_CONTROL_t;

#define DMA_DMA_SSP_RXQ5_CONTROL                 0xf0090408
#define DMA_DMA_SSP_RXQ5_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 29 ;
    cs_uint32 rxq5_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               :  2 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 rxq5_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd2               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_CONTROL_t;

#define DMA_DMA_SSP_RXQ6_CONTROL                 0xf009040c
#define DMA_DMA_SSP_RXQ6_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 29 ;
    cs_uint32 rxq6_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               :  2 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 rxq6_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd2               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_CONTROL_t;

#define DMA_DMA_SSP_RXQ7_CONTROL                 0xf0090410
#define DMA_DMA_SSP_RXQ7_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 29 ;
    cs_uint32 rxq7_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               :  2 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 rxq7_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd2               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_CONTROL_t;

#define DMA_DMA_SSP_TXQ5_CONTROL                 0xf0090414
#define DMA_DMA_SSP_TXQ5_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 29 ;
    cs_uint32 txq5_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 txq5_en              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq5_en              :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 txq5_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd2               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_CONTROL_t;

#define DMA_DMA_SSP_TXQ6_CONTROL                 0xf0090418
#define DMA_DMA_SSP_TXQ6_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 txq6_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 txq6_sp_en           :  1 ; /* bits 1:1 */
    cs_uint32 txq6_en              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq6_en              :  1 ; /* bits 0:0 */
    cs_uint32 txq6_sp_en           :  1 ; /* bits 1:1 */
    cs_uint32 txq6_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_CONTROL_t;

#define DMA_DMA_SSP_TXQ7_CONTROL                 0xf009041c
#define DMA_DMA_SSP_TXQ7_CONTROL_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 txq7_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 txq7_sp_en           :  1 ; /* bits 1:1 */
    cs_uint32 txq7_en              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq7_en              :  1 ; /* bits 0:0 */
    cs_uint32 txq7_sp_en           :  1 ; /* bits 1:1 */
    cs_uint32 txq7_flush_en        :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_CONTROL_t;

#define DMA_DMA_SSP_RXQ5_PKTCNT_READ             0xf0090420
#define DMA_DMA_SSP_RXQ5_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 rxq5_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rxq5_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq5_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rxq5_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_PKTCNT_READ_t;

#define DMA_DMA_SSP_RXQ6_PKTCNT_READ             0xf0090424
#define DMA_DMA_SSP_RXQ6_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 rxq6_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rxq6_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq6_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rxq6_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_PKTCNT_READ_t;

#define DMA_DMA_SSP_RXQ7_PKTCNT_READ             0xf0090428
#define DMA_DMA_SSP_RXQ7_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 rxq7_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rxq7_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq7_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rxq7_full_drop_msb_clr :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_PKTCNT_READ_t;

#define DMA_DMA_SSP_TXQ5_PKTCNT_READ             0xf009042c
#define DMA_DMA_SSP_TXQ5_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 txq5_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq5_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_PKTCNT_READ_t;

#define DMA_DMA_SSP_TXQ6_PKTCNT_READ             0xf0090430
#define DMA_DMA_SSP_TXQ6_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 txq6_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq6_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_PKTCNT_READ_t;

#define DMA_DMA_SSP_TXQ7_PKTCNT_READ             0xf0090434
#define DMA_DMA_SSP_TXQ7_PKTCNT_READ_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 txq7_msb_clr         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq7_msb_clr         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_PKTCNT_READ_t;

#define DMA_DMA_SSP_RXQ5_BASE_DEPTH              0xf0090438
#define DMA_DMA_SSP_RXQ5_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_BASE_DEPTH_t;

#define DMA_DMA_SSP_RXQ6_BASE_DEPTH              0xf009043c
#define DMA_DMA_SSP_RXQ6_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_BASE_DEPTH_t;

#define DMA_DMA_SSP_RXQ7_BASE_DEPTH              0xf0090440
#define DMA_DMA_SSP_RXQ7_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_BASE_DEPTH_t;

#define DMA_DMA_SSP_RXQ5_WPTR                    0xf0090444
#define DMA_DMA_SSP_RXQ5_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_WPTR_t;

#define DMA_DMA_SSP_RXQ5_RPTR                    0xf0090448
#define DMA_DMA_SSP_RXQ5_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_RPTR_t;

#define DMA_DMA_SSP_RXQ6_WPTR                    0xf009044c
#define DMA_DMA_SSP_RXQ6_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_WPTR_t;

#define DMA_DMA_SSP_RXQ6_RPTR                    0xf0090450
#define DMA_DMA_SSP_RXQ6_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_RPTR_t;

#define DMA_DMA_SSP_RXQ7_WPTR                    0xf0090454
#define DMA_DMA_SSP_RXQ7_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_WPTR_t;

#define DMA_DMA_SSP_RXQ7_RPTR                    0xf0090458
#define DMA_DMA_SSP_RXQ7_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_RPTR_t;

#define DMA_DMA_SSP_TXQ5_BASE_DEPTH              0xf009045c
#define DMA_DMA_SSP_TXQ5_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_BASE_DEPTH_t;

#define DMA_DMA_SSP_TXQ6_BASE_DEPTH              0xf0090460
#define DMA_DMA_SSP_TXQ6_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_BASE_DEPTH_t;

#define DMA_DMA_SSP_TXQ7_BASE_DEPTH              0xf0090464
#define DMA_DMA_SSP_TXQ7_BASE_DEPTH_dft          0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 base                 : 28 ; /* bits 31:4 */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                :  4 ; /* bits 3:0 */
    cs_uint32 base                 : 28 ; /* bits 31:4 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_BASE_DEPTH_t;

#define DMA_DMA_SSP_TXQ5_WPTR                    0xf0090468
#define DMA_DMA_SSP_TXQ5_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_WPTR_t;

#define DMA_DMA_SSP_TXQ5_RPTR                    0xf009046c
#define DMA_DMA_SSP_TXQ5_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_RPTR_t;

#define DMA_DMA_SSP_TXQ6_WPTR                    0xf0090470
#define DMA_DMA_SSP_TXQ6_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_WPTR_t;

#define DMA_DMA_SSP_TXQ6_RPTR                    0xf0090474
#define DMA_DMA_SSP_TXQ6_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_RPTR_t;

#define DMA_DMA_SSP_TXQ7_WPTR                    0xf0090478
#define DMA_DMA_SSP_TXQ7_WPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_WPTR_t;

#define DMA_DMA_SSP_TXQ7_RPTR                    0xf009047c
#define DMA_DMA_SSP_TXQ7_RPTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 index                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 index                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_RPTR_t;

#define DMA_DMA_SSP_RXQ5_FULL_THRESHOLD          0xf0090480
#define DMA_DMA_SSP_RXQ5_FULL_THRESHOLD_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 depth                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_FULL_THRESHOLD_t;

#define DMA_DMA_SSP_RXQ6_FULL_THRESHOLD          0xf0090484
#define DMA_DMA_SSP_RXQ6_FULL_THRESHOLD_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 depth                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_FULL_THRESHOLD_t;

#define DMA_DMA_SSP_RXQ7_FULL_THRESHOLD          0xf0090488
#define DMA_DMA_SSP_RXQ7_FULL_THRESHOLD_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 depth                : 13 ; /* bits 12:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 depth                : 13 ; /* bits 12:0 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_FULL_THRESHOLD_t;

#define DMA_DMA_SSP_RXQ5_PKTCNT                  0xf009048c
#define DMA_DMA_SSP_RXQ5_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_PKTCNT_t;

#define DMA_DMA_SSP_RXQ6_PKTCNT                  0xf0090490
#define DMA_DMA_SSP_RXQ6_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_PKTCNT_t;

#define DMA_DMA_SSP_RXQ7_PKTCNT                  0xf0090494
#define DMA_DMA_SSP_RXQ7_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_PKTCNT_t;

#define DMA_DMA_SSP_RXQ5_FULL_DROP_PKTCNT        0xf0090498
#define DMA_DMA_SSP_RXQ5_FULL_DROP_PKTCNT_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_FULL_DROP_PKTCNT_t;

#define DMA_DMA_SSP_RXQ6_FULL_DROP_PKTCNT        0xf009049c
#define DMA_DMA_SSP_RXQ6_FULL_DROP_PKTCNT_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_FULL_DROP_PKTCNT_t;

#define DMA_DMA_SSP_RXQ7_FULL_DROP_PKTCNT        0xf00904a0
#define DMA_DMA_SSP_RXQ7_FULL_DROP_PKTCNT_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_FULL_DROP_PKTCNT_t;

#define DMA_DMA_SSP_TXQ5_PKTCNT                  0xf00904a4
#define DMA_DMA_SSP_TXQ5_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_PKTCNT_t;

#define DMA_DMA_SSP_TXQ6_PKTCNT                  0xf00904a8
#define DMA_DMA_SSP_TXQ6_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_PKTCNT_t;

#define DMA_DMA_SSP_TXQ7_PKTCNT                  0xf00904ac
#define DMA_DMA_SSP_TXQ7_PKTCNT_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 counter              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter              : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_PKTCNT_t;

#define DMA_DMA_SSP_DMA_SSP_INTERRUPT_0          0xf00904b0
#define DMA_DMA_SSP_DMA_SSP_INTERRUPT_0_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 SSP1_INTi            :  1 ; /* bits 14:14 */
    cs_uint32 SSP0_INTi            :  1 ; /* bits 13:13 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi :  1 ; /* bits 12:12 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_TX_READ_DATAi :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_TX_READ_DESCi :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_RX_READ_DESCi :  1 ; /* bits 7:7 */
    cs_uint32 TXQ7_INTERRUPTi      :  1 ; /* bits 6:6 */
    cs_uint32 TXQ6_INTERRUPTi      :  1 ; /* bits 5:5 */
    cs_uint32 TXQ5_INTERRUPTi      :  1 ; /* bits 4:4 */
    cs_uint32 RXQ7_INTERRUPTi      :  1 ; /* bits 3:3 */
    cs_uint32 RXQ6_INTERRUPTi      :  1 ; /* bits 2:2 */
    cs_uint32 RXQ5_INTERRUPTi      :  1 ; /* bits 1:1 */
    cs_uint32 DESC_INTERRUPTi      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DESC_INTERRUPTi      :  1 ; /* bits 0:0 */
    cs_uint32 RXQ5_INTERRUPTi      :  1 ; /* bits 1:1 */
    cs_uint32 RXQ6_INTERRUPTi      :  1 ; /* bits 2:2 */
    cs_uint32 RXQ7_INTERRUPTi      :  1 ; /* bits 3:3 */
    cs_uint32 TXQ5_INTERRUPTi      :  1 ; /* bits 4:4 */
    cs_uint32 TXQ6_INTERRUPTi      :  1 ; /* bits 5:5 */
    cs_uint32 TXQ7_INTERRUPTi      :  1 ; /* bits 6:6 */
    cs_uint32 AXI_INT_RX_READ_DESCi :  1 ; /* bits 7:7 */
    cs_uint32 AXI_INT_TX_READ_DESCi :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_TX_READ_DATAi :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi :  1 ; /* bits 12:12 */
    cs_uint32 SSP0_INTi            :  1 ; /* bits 13:13 */
    cs_uint32 SSP1_INTi            :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SSP_INTERRUPT_0_t;

#define DMA_DMA_SSP_DMA_SSP_INTENABLE_0          0xf00904b4
#define DMA_DMA_SSP_DMA_SSP_INTENABLE_0_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 SSP1_INTi_en         :  1 ; /* bits 14:14 */
    cs_uint32 SSP0_INTi_en         :  1 ; /* bits 13:13 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi_en :  1 ; /* bits 12:12 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi_en :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi_en :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_TX_READ_DATAi_en :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_TX_READ_DESCi_en :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_RX_READ_DESCi_en :  1 ; /* bits 7:7 */
    cs_uint32 TXQ7_INTERRUPTi_en   :  1 ; /* bits 6:6 */
    cs_uint32 TXQ6_INTERRUPTi_en   :  1 ; /* bits 5:5 */
    cs_uint32 TXQ5_INTERRUPTi_en   :  1 ; /* bits 4:4 */
    cs_uint32 RXQ7_INTERRUPTi_en   :  1 ; /* bits 3:3 */
    cs_uint32 RXQ6_INTERRUPTi_en   :  1 ; /* bits 2:2 */
    cs_uint32 RXQ5_INTERRUPTi_en   :  1 ; /* bits 1:1 */
    cs_uint32 DESC_INTERRUPTi_en   :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DESC_INTERRUPTi_en   :  1 ; /* bits 0:0 */
    cs_uint32 RXQ5_INTERRUPTi_en   :  1 ; /* bits 1:1 */
    cs_uint32 RXQ6_INTERRUPTi_en   :  1 ; /* bits 2:2 */
    cs_uint32 RXQ7_INTERRUPTi_en   :  1 ; /* bits 3:3 */
    cs_uint32 TXQ5_INTERRUPTi_en   :  1 ; /* bits 4:4 */
    cs_uint32 TXQ6_INTERRUPTi_en   :  1 ; /* bits 5:5 */
    cs_uint32 TXQ7_INTERRUPTi_en   :  1 ; /* bits 6:6 */
    cs_uint32 AXI_INT_RX_READ_DESCi_en :  1 ; /* bits 7:7 */
    cs_uint32 AXI_INT_TX_READ_DESCi_en :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_TX_READ_DATAi_en :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi_en :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi_en :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi_en :  1 ; /* bits 12:12 */
    cs_uint32 SSP0_INTi_en         :  1 ; /* bits 13:13 */
    cs_uint32 SSP1_INTi_en         :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SSP_INTENABLE_0_t;

#define DMA_DMA_SSP_DMA_SSP_INTERRUPT_1          0xf00904b8
#define DMA_DMA_SSP_DMA_SSP_INTERRUPT_1_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 SSP1_INTi            :  1 ; /* bits 14:14 */
    cs_uint32 SSP0_INTi            :  1 ; /* bits 13:13 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi :  1 ; /* bits 12:12 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_TX_READ_DATAi :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_TX_READ_DESCi :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_RX_READ_DESCi :  1 ; /* bits 7:7 */
    cs_uint32 TXQ7_INTERRUPTi      :  1 ; /* bits 6:6 */
    cs_uint32 TXQ6_INTERRUPTi      :  1 ; /* bits 5:5 */
    cs_uint32 TXQ5_INTERRUPTi      :  1 ; /* bits 4:4 */
    cs_uint32 RXQ7_INTERRUPTi      :  1 ; /* bits 3:3 */
    cs_uint32 RXQ6_INTERRUPTi      :  1 ; /* bits 2:2 */
    cs_uint32 RXQ5_INTERRUPTi      :  1 ; /* bits 1:1 */
    cs_uint32 DESC_INTERRUPTi      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DESC_INTERRUPTi      :  1 ; /* bits 0:0 */
    cs_uint32 RXQ5_INTERRUPTi      :  1 ; /* bits 1:1 */
    cs_uint32 RXQ6_INTERRUPTi      :  1 ; /* bits 2:2 */
    cs_uint32 RXQ7_INTERRUPTi      :  1 ; /* bits 3:3 */
    cs_uint32 TXQ5_INTERRUPTi      :  1 ; /* bits 4:4 */
    cs_uint32 TXQ6_INTERRUPTi      :  1 ; /* bits 5:5 */
    cs_uint32 TXQ7_INTERRUPTi      :  1 ; /* bits 6:6 */
    cs_uint32 AXI_INT_RX_READ_DESCi :  1 ; /* bits 7:7 */
    cs_uint32 AXI_INT_TX_READ_DESCi :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_TX_READ_DATAi :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi :  1 ; /* bits 12:12 */
    cs_uint32 SSP0_INTi            :  1 ; /* bits 13:13 */
    cs_uint32 SSP1_INTi            :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SSP_INTERRUPT_1_t;

#define DMA_DMA_SSP_DMA_SSP_INTENABLE_1          0xf00904bc
#define DMA_DMA_SSP_DMA_SSP_INTENABLE_1_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 SSP1_INTi_en         :  1 ; /* bits 14:14 */
    cs_uint32 SSP0_INTi_en         :  1 ; /* bits 13:13 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi_en :  1 ; /* bits 12:12 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi_en :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi_en :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_TX_READ_DATAi_en :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_TX_READ_DESCi_en :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_RX_READ_DESCi_en :  1 ; /* bits 7:7 */
    cs_uint32 TXQ7_INTERRUPTi_en   :  1 ; /* bits 6:6 */
    cs_uint32 TXQ6_INTERRUPTi_en   :  1 ; /* bits 5:5 */
    cs_uint32 TXQ5_INTERRUPTi_en   :  1 ; /* bits 4:4 */
    cs_uint32 RXQ7_INTERRUPTi_en   :  1 ; /* bits 3:3 */
    cs_uint32 RXQ6_INTERRUPTi_en   :  1 ; /* bits 2:2 */
    cs_uint32 RXQ5_INTERRUPTi_en   :  1 ; /* bits 1:1 */
    cs_uint32 DESC_INTERRUPTi_en   :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DESC_INTERRUPTi_en   :  1 ; /* bits 0:0 */
    cs_uint32 RXQ5_INTERRUPTi_en   :  1 ; /* bits 1:1 */
    cs_uint32 RXQ6_INTERRUPTi_en   :  1 ; /* bits 2:2 */
    cs_uint32 RXQ7_INTERRUPTi_en   :  1 ; /* bits 3:3 */
    cs_uint32 TXQ5_INTERRUPTi_en   :  1 ; /* bits 4:4 */
    cs_uint32 TXQ6_INTERRUPTi_en   :  1 ; /* bits 5:5 */
    cs_uint32 TXQ7_INTERRUPTi_en   :  1 ; /* bits 6:6 */
    cs_uint32 AXI_INT_RX_READ_DESCi_en :  1 ; /* bits 7:7 */
    cs_uint32 AXI_INT_TX_READ_DESCi_en :  1 ; /* bits 8:8 */
    cs_uint32 AXI_INT_TX_READ_DATAi_en :  1 ; /* bits 9:9 */
    cs_uint32 AXI_INT_RX_WRITE_DESCi_en :  1 ; /* bits 10:10 */
    cs_uint32 AXI_INT_RX_WRITE_DATAi_en :  1 ; /* bits 11:11 */
    cs_uint32 AXI_INT_TX_WRITE_DESCi_en :  1 ; /* bits 12:12 */
    cs_uint32 SSP0_INTi_en         :  1 ; /* bits 13:13 */
    cs_uint32 SSP1_INTi_en         :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SSP_INTENABLE_1_t;

#define DMA_DMA_SSP_DESC_INTERRUPT               0xf00904c0
#define DMA_DMA_SSP_DESC_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 tx_des_err           :  1 ; /* bits 1:1 */
    cs_uint32 rx_des_err           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_des_err           :  1 ; /* bits 0:0 */
    cs_uint32 tx_des_err           :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DESC_INTERRUPT_t;

#define DMA_DMA_SSP_DESC_INTENABLE               0xf00904c4
#define DMA_DMA_SSP_DESC_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 tx_desc_err_en       :  1 ; /* bits 1:1 */
    cs_uint32 rx_desc_err_en       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_desc_err_en       :  1 ; /* bits 0:0 */
    cs_uint32 tx_desc_err_en       :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DESC_INTENABLE_t;

#define DMA_DMA_SSP_RXQ5_INTERRUPT               0xf00904c8
#define DMA_DMA_SSP_RXQ5_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq5_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rxq5_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq5_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq5_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq5_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq5_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq5_eof             :  1 ; /* bits 0:0 */
    cs_uint32 rxq5_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq5_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq5_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq5_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq5_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_INTERRUPT_t;

#define DMA_DMA_SSP_RXQ5_INTENABLE               0xf00904cc
#define DMA_DMA_SSP_RXQ5_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq5_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rxq5_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq5_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq5_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq5_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq5_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq5_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 rxq5_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq5_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq5_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq5_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq5_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_INTENABLE_t;

#define DMA_DMA_SSP_RXQ6_INTERRUPT               0xf00904d0
#define DMA_DMA_SSP_RXQ6_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq6_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rxq6_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq6_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq6_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq6_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq6_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq6_eof             :  1 ; /* bits 0:0 */
    cs_uint32 rxq6_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq6_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq6_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq6_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq6_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_INTERRUPT_t;

#define DMA_DMA_SSP_RXQ6_INTENABLE               0xf00904d4
#define DMA_DMA_SSP_RXQ6_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq6_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rxq6_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq6_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq6_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq6_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq6_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq6_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 rxq6_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq6_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq6_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq6_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq6_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_INTENABLE_t;

#define DMA_DMA_SSP_RXQ7_INTERRUPT               0xf00904d8
#define DMA_DMA_SSP_RXQ7_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq7_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rxq7_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq7_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq7_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq7_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq7_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq7_eof             :  1 ; /* bits 0:0 */
    cs_uint32 rxq7_full            :  1 ; /* bits 1:1 */
    cs_uint32 rxq7_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 rxq7_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rxq7_full_drop_overrun :  1 ; /* bits 4:4 */
    cs_uint32 rxq7_full_drop_cntmsb :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_INTERRUPT_t;

#define DMA_DMA_SSP_RXQ7_INTENABLE               0xf00904dc
#define DMA_DMA_SSP_RXQ7_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 26 ;
    cs_uint32 rxq7_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rxq7_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq7_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq7_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq7_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq7_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxq7_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 rxq7_full_en         :  1 ; /* bits 1:1 */
    cs_uint32 rxq7_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 rxq7_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rxq7_full_drop_overrun_en :  1 ; /* bits 4:4 */
    cs_uint32 rxq7_full_drop_cntmsb_en :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 26 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_INTENABLE_t;

#define DMA_DMA_SSP_TXQ5_INTERRUPT               0xf00904e0
#define DMA_DMA_SSP_TXQ5_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq5_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 txq5_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq5_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq5_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq5_eof             :  1 ; /* bits 0:0 */
    cs_uint32 txq5_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq5_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq5_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_INTERRUPT_t;

#define DMA_DMA_SSP_TXQ5_INTENABLE               0xf00904e4
#define DMA_DMA_SSP_TXQ5_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq5_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 txq5_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq5_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq5_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq5_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 txq5_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq5_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq5_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_INTENABLE_t;

#define DMA_DMA_SSP_TXQ6_INTERRUPT               0xf00904e8
#define DMA_DMA_SSP_TXQ6_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq6_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 txq6_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq6_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq6_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq6_eof             :  1 ; /* bits 0:0 */
    cs_uint32 txq6_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq6_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq6_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_INTERRUPT_t;

#define DMA_DMA_SSP_TXQ6_INTENABLE               0xf00904ec
#define DMA_DMA_SSP_TXQ6_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq6_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 txq6_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq6_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq6_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq6_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 txq6_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq6_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq6_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_INTENABLE_t;

#define DMA_DMA_SSP_TXQ7_INTERRUPT               0xf00904f0
#define DMA_DMA_SSP_TXQ7_INTERRUPT_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq7_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 txq7_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq7_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq7_eof             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq7_eof             :  1 ; /* bits 0:0 */
    cs_uint32 txq7_empty           :  1 ; /* bits 1:1 */
    cs_uint32 txq7_overrun         :  1 ; /* bits 2:2 */
    cs_uint32 txq7_cntmsb          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_INTERRUPT_t;

#define DMA_DMA_SSP_TXQ7_INTENABLE               0xf00904f4
#define DMA_DMA_SSP_TXQ7_INTENABLE_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 txq7_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 txq7_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq7_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq7_eof_en          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txq7_eof_en          :  1 ; /* bits 0:0 */
    cs_uint32 txq7_empty_en        :  1 ; /* bits 1:1 */
    cs_uint32 txq7_overrun_en      :  1 ; /* bits 2:2 */
    cs_uint32 txq7_cntmsb_en       :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_INTENABLE_t;

#define DMA_DMA_SSP_RX_FDES_ADDR                 0xf00904f8
#define DMA_DMA_SSP_RX_FDES_ADDR_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rx_fdaddr            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fdaddr            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RX_FDES_ADDR_t;

#define DMA_DMA_SSP_RX_CDES_ADDR                 0xf00904fc
#define DMA_DMA_SSP_RX_CDES_ADDR_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rx_cdaddr            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_cdaddr            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RX_CDES_ADDR_t;

#define DMA_DMA_SSP_RX_DES_WORD0                 0xf0090500
#define DMA_DMA_SSP_RX_DES_WORD0_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RX_DES_WORD0_t;

#define DMA_DMA_SSP_RX_DES_WORD1                 0xf0090504
#define DMA_DMA_SSP_RX_DES_WORD1_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RX_DES_WORD1_t;

#define DMA_DMA_SSP_TX_FDES_ADDR                 0xf0090508
#define DMA_DMA_SSP_TX_FDES_ADDR_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 tx_fdaddr            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fdaddr            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_FDES_ADDR_t;

#define DMA_DMA_SSP_TX_CDES_ADDR                 0xf009050c
#define DMA_DMA_SSP_TX_CDES_ADDR_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 tx_cdaddr            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_cdaddr            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_CDES_ADDR_t;

#define DMA_DMA_SSP_TX_DES_WORD0                 0xf0090510
#define DMA_DMA_SSP_TX_DES_WORD0_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_DES_WORD0_t;

#define DMA_DMA_SSP_TX_DES_WORD1                 0xf0090514
#define DMA_DMA_SSP_TX_DES_WORD1_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_DES_WORD1_t;

#define DMA_DMA_SSP_TX_DES_WORD2                 0xf0090518
#define DMA_DMA_SSP_TX_DES_WORD2_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_DES_WORD2_t;

#define DMA_DMA_SSP_TX_DES_WORD3                 0xf009051c
#define DMA_DMA_SSP_TX_DES_WORD3_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TX_DES_WORD3_t;

#define DMA_DMA_SSP_RXQ5_FRAG_BUFF_ADDR          0xf0090520
#define DMA_DMA_SSP_RXQ5_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_RXQ5_FRAG_BUFF_SIZE          0xf0090524
#define DMA_DMA_SSP_RXQ5_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ5_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_RXQ6_FRAG_BUFF_ADDR          0xf0090528
#define DMA_DMA_SSP_RXQ6_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_RXQ6_FRAG_BUFF_SIZE          0xf009052c
#define DMA_DMA_SSP_RXQ6_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ6_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_RXQ7_FRAG_BUFF_ADDR          0xf0090530
#define DMA_DMA_SSP_RXQ7_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_RXQ7_FRAG_BUFF_SIZE          0xf0090534
#define DMA_DMA_SSP_RXQ7_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 13 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_RXQ7_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_TXQ5_FRAG_BUFF_ADDR          0xf0090538
#define DMA_DMA_SSP_TXQ5_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_TXQ5_FRAG_BUFF_SIZE          0xf009053c
#define DMA_DMA_SSP_TXQ5_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd3               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ5_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_TXQ6_FRAG_BUFF_ADDR          0xf0090540
#define DMA_DMA_SSP_TXQ6_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_TXQ6_FRAG_BUFF_SIZE          0xf0090544
#define DMA_DMA_SSP_TXQ6_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd3               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ6_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_TXQ7_FRAG_BUFF_ADDR          0xf0090548
#define DMA_DMA_SSP_TXQ7_FRAG_BUFF_ADDR_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 data                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_FRAG_BUFF_ADDR_t;

#define DMA_DMA_SSP_TXQ7_FRAG_BUFF_SIZE          0xf009054c
#define DMA_DMA_SSP_TXQ7_FRAG_BUFF_SIZE_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 buffersize           : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sgm                  :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 cache                :  1 ; /* bits 29:29 */
    cs_uint32 share                :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd3               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_TXQ7_FRAG_BUFF_SIZE_t;

#define DMA_DMA_SSP_DEBUG_0                      0xf0090550
#define DMA_DMA_SSP_DEBUG_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 dmarx_cs             :  5 ; /* bits 24:20 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 rxfout_cs            :  3 ; /* bits 18:16 */
    cs_uint32 rxfer_cs             :  4 ; /* bits 15:12 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rxbuf_cs             :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 rxfin_cs             :  3 ; /* bits 6:4 */
    cs_uint32 rxsch_cs             :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxsch_cs             :  4 ; /* bits 3:0 */
    cs_uint32 rxfin_cs             :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 rxbuf_cs             :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rxfer_cs             :  4 ; /* bits 15:12 */
    cs_uint32 rxfout_cs            :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 dmarx_cs             :  5 ; /* bits 24:20 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DEBUG_0_t;

#define DMA_DMA_SSP_DEBUG_1                      0xf0090554
#define DMA_DMA_SSP_DEBUG_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd5               :  5 ;
    cs_uint32 txfer_cs             :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 rr0_cs               :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 rr1_cs               :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 sp_cs                :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 mux_cs               :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mux_cs               :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 sp_cs                :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 rr1_cs               :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 rr0_cs               :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 txfer_cs             :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd5               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DEBUG_1_t;

#define DMA_DMA_SSP_DEBUG_2                      0xf0090558
#define DMA_DMA_SSP_DEBUG_2_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd6               :  6 ;
    cs_uint32 ssprx_cs             :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 ssptx_cs             :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd4               :  2 ;
    cs_uint32 flash_cs             :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 dmatx_cs             :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 txfin_cs             :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 txfout_cs            :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txfout_cs            :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 txfin_cs             :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 dmatx_cs             :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 flash_cs             :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd4               :  2 ;
    cs_uint32 ssptx_cs             :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 ssprx_cs             :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd6               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DEBUG_2_t;

#define DMA_DMA_SSP_DMA_SPARE_0                  0xf009055c
#define DMA_DMA_SSP_DMA_SPARE_0_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dma_spare0           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dma_spare0           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SPARE_0_t;

#define DMA_DMA_SSP_DMA_SPARE_1                  0xf0090560
#define DMA_DMA_SSP_DMA_SPARE_1_dft              0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dma_spare1           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dma_spare1           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} DMA_DMA_SSP_DMA_SPARE_1_t;

#define NI_TOP_NI_INTF_RST_CONFIG                0xf0010000
#define NI_TOP_NI_INTF_RST_CONFIG_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 intf_rst_ge2         :  1 ; /* bits 2:2 */
    cs_uint32 intf_rst_ge1         :  1 ; /* bits 1:1 */
    cs_uint32 intf_rst_ge0         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 intf_rst_ge0         :  1 ; /* bits 0:0 */
    cs_uint32 intf_rst_ge1         :  1 ; /* bits 1:1 */
    cs_uint32 intf_rst_ge2         :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INTF_RST_CONFIG_t;

#define NI_TOP_NI_ETH_INT_CONFIG1                0xf0010004
#define NI_TOP_NI_ETH_INT_CONFIG1_dft            0x00424242

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  8 ;
    cs_uint32 inv_clk_out_ge2      :  1 ; /* bits 23:23 */
    cs_uint32 tx_use_gefifo_ge2    :  1 ; /* bits 22:22 */
    cs_uint32 rmii_clksrc_ge2      :  1 ; /* bits 21:21 */
    cs_uint32 phy_mode_ge2         :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 int_cfg_ge2          :  3 ; /* bits 18:16 */
    cs_uint32 inv_clk_out_ge1      :  1 ; /* bits 15:15 */
    cs_uint32 tx_use_gefifo_ge1    :  1 ; /* bits 14:14 */
    cs_uint32 rmii_clksrc_ge1      :  1 ; /* bits 13:13 */
    cs_uint32 phy_mode_ge1         :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 int_cfg_ge1          :  3 ; /* bits 10:8 */
    cs_uint32 inv_clk_out_ge0      :  1 ; /* bits 7:7 */
    cs_uint32 tx_use_gefifo_ge0    :  1 ; /* bits 6:6 */
    cs_uint32 rmii_clksrc_ge0      :  1 ; /* bits 5:5 */
    cs_uint32 phy_mode_ge0         :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 int_cfg_ge0          :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_cfg_ge0          :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 phy_mode_ge0         :  1 ; /* bits 4:4 */
    cs_uint32 rmii_clksrc_ge0      :  1 ; /* bits 5:5 */
    cs_uint32 tx_use_gefifo_ge0    :  1 ; /* bits 6:6 */
    cs_uint32 inv_clk_out_ge0      :  1 ; /* bits 7:7 */
    cs_uint32 int_cfg_ge1          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 phy_mode_ge1         :  1 ; /* bits 12:12 */
    cs_uint32 rmii_clksrc_ge1      :  1 ; /* bits 13:13 */
    cs_uint32 tx_use_gefifo_ge1    :  1 ; /* bits 14:14 */
    cs_uint32 inv_clk_out_ge1      :  1 ; /* bits 15:15 */
    cs_uint32 int_cfg_ge2          :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 phy_mode_ge2         :  1 ; /* bits 20:20 */
    cs_uint32 rmii_clksrc_ge2      :  1 ; /* bits 21:21 */
    cs_uint32 tx_use_gefifo_ge2    :  1 ; /* bits 22:22 */
    cs_uint32 inv_clk_out_ge2      :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd4               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_INT_CONFIG1_t;

#define NI_TOP_NI_ETH_INT_CONFIG2                0xf0010008
#define NI_TOP_NI_ETH_INT_CONFIG2_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 10 ;
    cs_uint32 tx_intf_lp_time_ge2  :  1 ; /* bits 21:21 */
    cs_uint32 power_dwn_tx_ge2     :  1 ; /* bits 20:20 */
    cs_uint32 power_dwn_rx_ge2     :  1 ; /* bits 19:19 */
    cs_uint32 inv_rxclk_out_ge2    :  1 ; /* bits 18:18 */
    cs_uint32 inv_clk_in_ge2       :  1 ; /* bits 17:17 */
    cs_uint32 smii_tx_stat_ge2     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 tx_intf_lp_time_ge1  :  1 ; /* bits 13:13 */
    cs_uint32 power_dwn_tx_ge1     :  1 ; /* bits 12:12 */
    cs_uint32 power_dwn_rx_ge1     :  1 ; /* bits 11:11 */
    cs_uint32 inv_rxclk_out_ge1    :  1 ; /* bits 10:10 */
    cs_uint32 inv_clk_in_ge1       :  1 ; /* bits 9:9 */
    cs_uint32 smii_tx_stat_ge1     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 tx_intf_lp_time_ge0  :  1 ; /* bits 5:5 */
    cs_uint32 power_dwn_tx_ge0     :  1 ; /* bits 4:4 */
    cs_uint32 power_dwn_rx_ge0     :  1 ; /* bits 3:3 */
    cs_uint32 inv_rxclk_out_ge0    :  1 ; /* bits 2:2 */
    cs_uint32 inv_clk_in_ge0       :  1 ; /* bits 1:1 */
    cs_uint32 smii_tx_stat_ge0     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 smii_tx_stat_ge0     :  1 ; /* bits 0:0 */
    cs_uint32 inv_clk_in_ge0       :  1 ; /* bits 1:1 */
    cs_uint32 inv_rxclk_out_ge0    :  1 ; /* bits 2:2 */
    cs_uint32 power_dwn_rx_ge0     :  1 ; /* bits 3:3 */
    cs_uint32 power_dwn_tx_ge0     :  1 ; /* bits 4:4 */
    cs_uint32 tx_intf_lp_time_ge0  :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 smii_tx_stat_ge1     :  1 ; /* bits 8:8 */
    cs_uint32 inv_clk_in_ge1       :  1 ; /* bits 9:9 */
    cs_uint32 inv_rxclk_out_ge1    :  1 ; /* bits 10:10 */
    cs_uint32 power_dwn_rx_ge1     :  1 ; /* bits 11:11 */
    cs_uint32 power_dwn_tx_ge1     :  1 ; /* bits 12:12 */
    cs_uint32 tx_intf_lp_time_ge1  :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 smii_tx_stat_ge2     :  1 ; /* bits 16:16 */
    cs_uint32 inv_clk_in_ge2       :  1 ; /* bits 17:17 */
    cs_uint32 inv_rxclk_out_ge2    :  1 ; /* bits 18:18 */
    cs_uint32 power_dwn_rx_ge2     :  1 ; /* bits 19:19 */
    cs_uint32 power_dwn_tx_ge2     :  1 ; /* bits 20:20 */
    cs_uint32 tx_intf_lp_time_ge2  :  1 ; /* bits 21:21 */
    cs_uint32 rsrvd3               : 10 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_INT_CONFIG2_t;

#define NI_TOP_NI_ETH_MGMT_PT_CONFIG             0xf001000c
#define NI_TOP_NI_ETH_MGMT_PT_CONFIG_dft         0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 mgmt_pt_to_fe_also   :  1 ; /* bits 2:2 */
    cs_uint32 port_to_cpu          :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 port_to_cpu          :  2 ; /* bits 1:0 */
    cs_uint32 mgmt_pt_to_fe_also   :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_MGMT_PT_CONFIG_t;

#define NI_TOP_NI_ETH_MAC_CONFIG0_0              0xf0010010
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_STRIDE       12
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_COUNT        3
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_dft          0x0010080c

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 mac_tx_rst           :  1 ; /* bits 31:31 */
    cs_uint32 mac_rx_rst           :  1 ; /* bits 30:30 */
    cs_uint32 send_pg_data         :  1 ; /* bits 29:29 */
    cs_uint32 pass_thru_hdre       :  1 ; /* bits 28:28 */
    cs_uint32 tx_fifo_reset        :  1 ; /* bits 27:27 */
    cs_uint32 tx_auto_xon          :  1 ; /* bits 26:26 */
    cs_uint32 txfifo_thrshld       :  9 ; /* bits 25:17 */
    cs_uint32 txfifo_mode          :  1 ; /* bits 16:16 */
    cs_uint32 lpbk_mode            :  2 ; /* bits 15:14 */
    cs_uint32 tx_drain             :  1 ; /* bits 13:13 */
    cs_uint32 tx_flow_disable      :  1 ; /* bits 12:12 */
    cs_uint32 tx_ipg_sel           :  3 ; /* bits 11:9 */
    cs_uint32 rx_flow_disable      :  1 ; /* bits 8:8 */
    cs_uint32 link_active_mask     :  1 ; /* bits 7:7 */
    cs_uint32 link_stat_mask       :  1 ; /* bits 6:6 */
    cs_uint32 link_status          :  1 ; /* bits 5:5 */
    cs_uint32 crs_polarity         :  1 ; /* bits 4:4 */
    cs_uint32 tx_en                :  1 ; /* bits 3:3 */
    cs_uint32 rx_en                :  1 ; /* bits 2:2 */
    cs_uint32 duplex               :  1 ; /* bits 1:1 */
    cs_uint32 speed                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 speed                :  1 ; /* bits 0:0 */
    cs_uint32 duplex               :  1 ; /* bits 1:1 */
    cs_uint32 rx_en                :  1 ; /* bits 2:2 */
    cs_uint32 tx_en                :  1 ; /* bits 3:3 */
    cs_uint32 crs_polarity         :  1 ; /* bits 4:4 */
    cs_uint32 link_status          :  1 ; /* bits 5:5 */
    cs_uint32 link_stat_mask       :  1 ; /* bits 6:6 */
    cs_uint32 link_active_mask     :  1 ; /* bits 7:7 */
    cs_uint32 rx_flow_disable      :  1 ; /* bits 8:8 */
    cs_uint32 tx_ipg_sel           :  3 ; /* bits 11:9 */
    cs_uint32 tx_flow_disable      :  1 ; /* bits 12:12 */
    cs_uint32 tx_drain             :  1 ; /* bits 13:13 */
    cs_uint32 lpbk_mode            :  2 ; /* bits 15:14 */
    cs_uint32 txfifo_mode          :  1 ; /* bits 16:16 */
    cs_uint32 txfifo_thrshld       :  9 ; /* bits 25:17 */
    cs_uint32 tx_auto_xon          :  1 ; /* bits 26:26 */
    cs_uint32 tx_fifo_reset        :  1 ; /* bits 27:27 */
    cs_uint32 pass_thru_hdre       :  1 ; /* bits 28:28 */
    cs_uint32 send_pg_data         :  1 ; /* bits 29:29 */
    cs_uint32 mac_rx_rst           :  1 ; /* bits 30:30 */
    cs_uint32 mac_tx_rst           :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_MAC_CONFIG0_0_t;

#define NI_TOP_NI_ETH_MAC_CONFIG1_0              0xf0010014
#define NI_TOP_NI_ETH_MAC_CONFIG1_0_STRIDE       12
#define NI_TOP_NI_ETH_MAC_CONFIG1_0_COUNT        3
#define NI_TOP_NI_ETH_MAC_CONFIG1_0_dft          0x00000f00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 wol_passwd6          :  8 ; /* bits 23:16 */
    cs_uint32 ts_add_dis           :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 wol_mac_adr_cnt      :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 wol_passwd_cnt       :  1 ; /* bits 5:5 */
    cs_uint32 wol_secure_on        :  1 ; /* bits 4:4 */
    cs_uint32 wol_ign_err          :  1 ; /* bits 3:3 */
    cs_uint32 wol_chk_da           :  2 ; /* bits 2:1 */
    cs_uint32 wol_pkt_det_en       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 wol_pkt_det_en       :  1 ; /* bits 0:0 */
    cs_uint32 wol_chk_da           :  2 ; /* bits 2:1 */
    cs_uint32 wol_ign_err          :  1 ; /* bits 3:3 */
    cs_uint32 wol_secure_on        :  1 ; /* bits 4:4 */
    cs_uint32 wol_passwd_cnt       :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 wol_mac_adr_cnt      :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ts_add_dis           :  1 ; /* bits 15:15 */
    cs_uint32 wol_passwd6          :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_MAC_CONFIG1_0_t;

#define NI_TOP_NI_ETH_MAC_CONFIG2_0              0xf0010018
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_STRIDE       12
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_COUNT        3
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_dft          0x00ff0000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pause_time           : 16 ; /* bits 31:16 */
    cs_uint32 sup_tx_to_rx_lpbk_data :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 mac_cfg_spare        :  1 ; /* bits 8:8 */
    cs_uint32 mac_addr6            :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mac_addr6            :  8 ; /* bits 7:0 */
    cs_uint32 mac_cfg_spare        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sup_tx_to_rx_lpbk_data :  1 ; /* bits 15:15 */
    cs_uint32 pause_time           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_MAC_CONFIG2_0_t;

#define NI_TOP_NI_ETH_RCV_STAT_0                 0xf0010034
#define NI_TOP_NI_ETH_RCV_STAT_0_STRIDE          4
#define NI_TOP_NI_ETH_RCV_STAT_0_COUNT           3
#define NI_TOP_NI_ETH_RCV_STAT_0_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 rcv_lnk_stat         :  1 ; /* bits 3:3 */
    cs_uint32 rcv_duplex           :  1 ; /* bits 2:2 */
    cs_uint32 rcv_speed            :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rcv_speed            :  2 ; /* bits 1:0 */
    cs_uint32 rcv_duplex           :  1 ; /* bits 2:2 */
    cs_uint32 rcv_lnk_stat         :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_RCV_STAT_0_t;

#define NI_TOP_NI_MAC_ADDR0                      0xf0010040
#define NI_TOP_NI_MAC_ADDR0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 mac_addr0            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mac_addr0            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MAC_ADDR0_t;

#define NI_TOP_NI_MAC_ADDR1                      0xf0010044
#define NI_TOP_NI_MAC_ADDR1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 mac_addr1            :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mac_addr1            :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MAC_ADDR1_t;

#define NI_TOP_NI_WOL_PASSWD_0                   0xf0010048
#define NI_TOP_NI_WOL_PASSWD_0_dft               0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 wol_passwd0          : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 wol_passwd0          : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_PASSWD_0_t;

#define NI_TOP_NI_WOL_PASSWD_1                   0xf001004c
#define NI_TOP_NI_WOL_PASSWD_1_dft               0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 wol_passwd1          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 wol_passwd1          :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_PASSWD_1_t;

#define NI_TOP_NI_PKT_LEN_CONFIG                 0xf0010050
#define NI_TOP_NI_PKT_LEN_CONFIG_dft             0x00400600

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 min_pkt_size         : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 max_pkt_size         : 14 ; /* bits 13:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 max_pkt_size         : 14 ; /* bits 13:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 min_pkt_size         : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd2               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PKT_LEN_CONFIG_t;

#define NI_TOP_NI_PKT_STOR_LEN_CONFIG            0xf0010054
#define NI_TOP_NI_PKT_STOR_LEN_CONFIG_dft        0x00002454

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 18 ;
    cs_uint32 max_stor_pkt_len     : 14 ; /* bits 13:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 max_stor_pkt_len     : 14 ; /* bits 13:0 */
    cs_uint32 rsrvd1               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PKT_STOR_LEN_CONFIG_t;

#define NI_TOP_NI_RX_CNTRL_CONFIG0_0             0xf0010058
#define NI_TOP_NI_RX_CNTRL_CONFIG0_0_STRIDE      8
#define NI_TOP_NI_RX_CNTRL_CONFIG0_0_COUNT       8
#define NI_TOP_NI_RX_CNTRL_CONFIG0_0_dft         0x00400400

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rxctrl_cfg_spare     :  2 ; /* bits 31:30 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 buff_use_thrshld     : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 linkstat_drop_dis    :  1 ; /* bits 10:10 */
    cs_uint32 oam_drop_dis         :  1 ; /* bits 9:9 */
    cs_uint32 ukopcode_drop_dis    :  1 ; /* bits 8:8 */
    cs_uint32 flow_drop_dis        :  1 ; /* bits 7:7 */
    cs_uint32 runt_drop_dis        :  1 ; /* bits 6:6 */
    cs_uint32 ovr_drop_dis         :  1 ; /* bits 5:5 */
    cs_uint32 crc_drop_dis         :  1 ; /* bits 4:4 */
    cs_uint32 shrtfrm_mode         :  1 ; /* bits 3:3 */
    cs_uint32 ff_overrun_drop_dis  :  1 ; /* bits 2:2 */
    cs_uint32 rc_fifo_reset        :  1 ; /* bits 1:1 */
    cs_uint32 rxctrl_dis           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxctrl_dis           :  1 ; /* bits 0:0 */
    cs_uint32 rc_fifo_reset        :  1 ; /* bits 1:1 */
    cs_uint32 ff_overrun_drop_dis  :  1 ; /* bits 2:2 */
    cs_uint32 shrtfrm_mode         :  1 ; /* bits 3:3 */
    cs_uint32 crc_drop_dis         :  1 ; /* bits 4:4 */
    cs_uint32 ovr_drop_dis         :  1 ; /* bits 5:5 */
    cs_uint32 runt_drop_dis        :  1 ; /* bits 6:6 */
    cs_uint32 flow_drop_dis        :  1 ; /* bits 7:7 */
    cs_uint32 ukopcode_drop_dis    :  1 ; /* bits 8:8 */
    cs_uint32 oam_drop_dis         :  1 ; /* bits 9:9 */
    cs_uint32 linkstat_drop_dis    :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 buff_use_thrshld     : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 rxctrl_cfg_spare     :  2 ; /* bits 31:30 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_CNTRL_CONFIG0_0_t;

#define NI_TOP_NI_RX_CNTRL_CONFIG1_0             0xf001005c
#define NI_TOP_NI_RX_CNTRL_CONFIG1_0_STRIDE      8
#define NI_TOP_NI_RX_CNTRL_CONFIG1_0_COUNT       8
#define NI_TOP_NI_RX_CNTRL_CONFIG1_0_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 16 ;
    cs_uint32 rxctrl_byp_voq       :  8 ; /* bits 15:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 rxctrl_byp_cpuptp    :  1 ; /* bits 6:6 */
    cs_uint32 rxctrl_byp_nocrc     :  1 ; /* bits 5:5 */
    cs_uint32 rxctrl_byp_nostuff   :  1 ; /* bits 4:4 */
    cs_uint32 rxctrl_byp_cos       :  3 ; /* bits 3:1 */
    cs_uint32 rxctrl_byp_en        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxctrl_byp_en        :  1 ; /* bits 0:0 */
    cs_uint32 rxctrl_byp_cos       :  3 ; /* bits 3:1 */
    cs_uint32 rxctrl_byp_nostuff   :  1 ; /* bits 4:4 */
    cs_uint32 rxctrl_byp_nocrc     :  1 ; /* bits 5:5 */
    cs_uint32 rxctrl_byp_cpuptp    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 rxctrl_byp_voq       :  8 ; /* bits 15:8 */
    cs_uint32 rsrvd2               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_CNTRL_CONFIG1_0_t;

#define NI_TOP_NI_RX_AGG_CONFIG                  0xf0010098
#define NI_TOP_NI_RX_AGG_CONFIG_dft              0x02880029

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  2 ;
    cs_uint32 rxagg_cfg_spare      :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rx_fifo_full_unset_th :  5 ; /* bits 26:22 */
    cs_uint32 rx_fifo_full_set_th  :  5 ; /* bits 21:17 */
    cs_uint32 rx_fifo_non_correct_err_vlden :  1 ; /* bits 16:16 */
    cs_uint32 rx_fifo_suppkt_less18 :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 rx_fifo_srst         :  1 ; /* bits 8:8 */
    cs_uint32 rx_frm_space         :  6 ; /* bits 7:2 */
    cs_uint32 rx_fifo_dis          :  1 ; /* bits 1:1 */
    cs_uint32 rx_port_cal_dis      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_port_cal_dis      :  1 ; /* bits 0:0 */
    cs_uint32 rx_fifo_dis          :  1 ; /* bits 1:1 */
    cs_uint32 rx_frm_space         :  6 ; /* bits 7:2 */
    cs_uint32 rx_fifo_srst         :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 rx_fifo_suppkt_less18 :  1 ; /* bits 15:15 */
    cs_uint32 rx_fifo_non_correct_err_vlden :  1 ; /* bits 16:16 */
    cs_uint32 rx_fifo_full_set_th  :  5 ; /* bits 21:17 */
    cs_uint32 rx_fifo_full_unset_th :  5 ; /* bits 26:22 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rxagg_cfg_spare      :  1 ; /* bits 29:29 */
    cs_uint32 rsrvd3               :  2 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_AGG_CONFIG_t;

#define NI_TOP_NI_RX_AGGPC_CONFIG                0xf001009c
#define NI_TOP_NI_RX_AGGPC_CONFIG_dft            0x00005f5f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 17 ;
    cs_uint32 pc_ts_wrap_cnt_pg1   :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pc_ts_wrap_cnt_pg0   :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_ts_wrap_cnt_pg0   :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pc_ts_wrap_cnt_pg1   :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd2               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_AGGPC_CONFIG_t;

#define NI_TOP_NI_RX_FIFO_CG_TH                  0xf00100a0
#define NI_TOP_NI_RX_FIFO_CG_TH_dft              0x80c8812c

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rx_fifo_cg_pkt_en    :  1 ; /* bits 31:31 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rx_fifo_cg_pkt_th    : 10 ; /* bits 25:16 */
    cs_uint32 rx_fifo_cg_free_en   :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_fifo_cg_free_th   : 10 ; /* bits 9:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_cg_free_th   : 10 ; /* bits 9:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_fifo_cg_free_en   :  1 ; /* bits 15:15 */
    cs_uint32 rx_fifo_cg_pkt_th    : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rx_fifo_cg_pkt_en    :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_FIFO_CG_TH_t;

#define NI_TOP_NI_RX_FIFO_NOCG_TH                0xf00100a4
#define NI_TOP_NI_RX_FIFO_NOCG_TH_dft            0x80328190

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rx_fifo_nocg_pkt_en  :  1 ; /* bits 31:31 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rx_fifo_nocg_pkt_th  : 10 ; /* bits 25:16 */
    cs_uint32 rx_fifo_nocg_free_en :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_fifo_nocg_free_th : 10 ; /* bits 9:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_nocg_free_th : 10 ; /* bits 9:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_fifo_nocg_free_en :  1 ; /* bits 15:15 */
    cs_uint32 rx_fifo_nocg_pkt_th  : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rx_fifo_nocg_pkt_en  :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_FIFO_NOCG_TH_t;

#define NI_TOP_NI_RX_FIFO_STAT                   0xf00100a8
#define NI_TOP_NI_RX_FIFO_STAT_dft               0x00040000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rxpc_current_pg      :  1 ; /* bits 31:31 */
    cs_uint32 rxfifo_init_done     :  1 ; /* bits 30:30 */
    cs_uint32 rxfifo_voq_cnt       : 11 ; /* bits 29:19 */
    cs_uint32 rxfifo_fb_cnt        : 11 ; /* bits 18:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 rx_fifo_congestion   :  1 ; /* bits 4:4 */
    cs_uint32 rx_rtn_buff_err      :  1 ; /* bits 3:3 */
    cs_uint32 voq_full             :  1 ; /* bits 2:2 */
    cs_uint32 rxfifo_full          :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_non_correct_err_state :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_non_correct_err_state :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_full          :  1 ; /* bits 1:1 */
    cs_uint32 voq_full             :  1 ; /* bits 2:2 */
    cs_uint32 rx_rtn_buff_err      :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_congestion   :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 rxfifo_fb_cnt        : 11 ; /* bits 18:8 */
    cs_uint32 rxfifo_voq_cnt       : 11 ; /* bits 29:19 */
    cs_uint32 rxfifo_init_done     :  1 ; /* bits 30:30 */
    cs_uint32 rxpc_current_pg      :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_FIFO_STAT_t;

#define NI_TOP_NI_RX_PORT_CAL_ACCESS             0xf00100ac
#define NI_TOP_NI_RX_PORT_CAL_ACCESS_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 rxpc_page            :  1 ; /* bits 17:17 */
    cs_uint32 cpu_page             :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 address              :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 address              :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 cpu_page             :  1 ; /* bits 16:16 */
    cs_uint32 rxpc_page            :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_PORT_CAL_ACCESS_t;

#define NI_TOP_NI_RX_PORT_CAL_DATA               0xf00100b0
#define NI_TOP_NI_RX_PORT_CAL_DATA_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 pspid_ts             :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pspid_ts             :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RX_PORT_CAL_DATA_t;

#define NI_TOP_NI_RXFIFO_DBG_ACCESS              0xf00100b4
#define NI_TOP_NI_RXFIFO_DBG_ACCESS_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 debug_mode           :  1 ; /* bits 29:29 */
    cs_uint32 mem_sel              :  2 ; /* bits 28:27 */
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 address              : 10 ; /* bits 9:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 address              : 10 ; /* bits 9:0 */
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 mem_sel              :  2 ; /* bits 28:27 */
    cs_uint32 debug_mode           :  1 ; /* bits 29:29 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_DBG_ACCESS_t;

#define NI_TOP_NI_RXFIFO_DBG_DATA                0xf00100b8
#define NI_TOP_NI_RXFIFO_DBG_DATA_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dbg_rdata            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dbg_rdata            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_DBG_DATA_t;

#define NI_TOP_NI_RXFIFO_DBG1                    0xf00100bc
#define NI_TOP_NI_RXFIFO_DBG1_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 rxfifo_voqm_eccmask  :  7 ; /* bits 7:1 */
    cs_uint32 rxfifo_voqm_dbg      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxfifo_voqm_dbg      :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_voqm_eccmask  :  7 ; /* bits 7:1 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_DBG1_t;

#define NI_TOP_NI_SCH_BP_THLD_ETH                0xf00100c0
#define NI_TOP_NI_SCH_BP_THLD_ETH_dft            0x082a00f8

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 rdy_low_thld_fe      :  5 ; /* bits 27:23 */
    cs_uint32 rdy_high_thld_fe     :  5 ; /* bits 22:18 */
    cs_uint32 rdy_low_thld_ge      :  9 ; /* bits 17:9 */
    cs_uint32 rdy_high_thld_ge     :  9 ; /* bits 8:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rdy_high_thld_ge     :  9 ; /* bits 8:0 */
    cs_uint32 rdy_low_thld_ge      :  9 ; /* bits 17:9 */
    cs_uint32 rdy_high_thld_fe     :  5 ; /* bits 22:18 */
    cs_uint32 rdy_low_thld_fe      :  5 ; /* bits 27:23 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_SCH_BP_THLD_ETH_t;

#define NI_TOP_NI_SCH_BP_THLD_MC                 0xf00100c4
#define NI_TOP_NI_SCH_BP_THLD_MC_dft             0x047f0472

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rdy_low_thld_mc      : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rdy_high_thld_mc     : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rdy_high_thld_mc     : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rdy_low_thld_mc      : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd2               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_SCH_BP_THLD_MC_t;

#define NI_TOP_NI_MISC_CONFIG                    0xf00100c8
#define NI_TOP_NI_MISC_CONFIG_dft                0x00001050

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 14 ;
    cs_uint32 txmib_mode           :  1 ; /* bits 17:17 */
    cs_uint32 rxmib_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 mc_accept_all        :  1 ; /* bits 14:14 */
    cs_uint32 ptp_cpu_cache_cnt    :  5 ; /* bits 13:9 */
    cs_uint32 ptp_hw_cnt_rst       :  1 ; /* bits 8:8 */
    cs_uint32 mr_fe_bp_en          :  1 ; /* bits 7:7 */
    cs_uint32 mr_lspid_inst_cp     :  1 ; /* bits 6:6 */
    cs_uint32 mc_source_filter_on  :  1 ; /* bits 5:5 */
    cs_uint32 mc_lspid_inst_cp     :  1 ; /* bits 4:4 */
    cs_uint32 mc_source_filter_on_hdrvec :  1 ; /* bits 3:3 */
    cs_uint32 eth_sch_rdy_pkt      :  1 ; /* bits 2:2 */
    cs_uint32 mc_pkt_rm_crcerr     :  1 ; /* bits 1:1 */
    cs_uint32 tx_em_crc_inv        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_em_crc_inv        :  1 ; /* bits 0:0 */
    cs_uint32 mc_pkt_rm_crcerr     :  1 ; /* bits 1:1 */
    cs_uint32 eth_sch_rdy_pkt      :  1 ; /* bits 2:2 */
    cs_uint32 mc_source_filter_on_hdrvec :  1 ; /* bits 3:3 */
    cs_uint32 mc_lspid_inst_cp     :  1 ; /* bits 4:4 */
    cs_uint32 mc_source_filter_on  :  1 ; /* bits 5:5 */
    cs_uint32 mr_lspid_inst_cp     :  1 ; /* bits 6:6 */
    cs_uint32 mr_fe_bp_en          :  1 ; /* bits 7:7 */
    cs_uint32 ptp_hw_cnt_rst       :  1 ; /* bits 8:8 */
    cs_uint32 ptp_cpu_cache_cnt    :  5 ; /* bits 13:9 */
    cs_uint32 mc_accept_all        :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 rxmib_mode           :  1 ; /* bits 16:16 */
    cs_uint32 txmib_mode           :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd2               : 14 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MISC_CONFIG_t;

#define NI_TOP_NI_TX_VOQ_LKUP_ACCESS             0xf00100cc
#define NI_TOP_NI_TX_VOQ_LKUP_ACCESS_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 err_parity           :  1 ; /* bits 17:17 */
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 address              :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 address              :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 err_parity           :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TX_VOQ_LKUP_ACCESS_t;

#define NI_TOP_NI_TX_VOQ_LKUP_DATA1              0xf00100d0
#define NI_TOP_NI_TX_VOQ_LKUP_DATA1_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 27 ;
    cs_uint32 txem_crcstate        :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_crcstate        :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               : 27 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TX_VOQ_LKUP_DATA1_t;

#define NI_TOP_NI_TX_VOQ_LKUP_DATA0              0xf00100d4
#define NI_TOP_NI_TX_VOQ_LKUP_DATA0_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 txem_crcstate        : 27 ; /* bits 31:5 */
    cs_uint32 txem_discrc          :  1 ; /* bits 4:4 */
    cs_uint32 txem_voq_did         :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_voq_did         :  4 ; /* bits 3:0 */
    cs_uint32 txem_discrc          :  1 ; /* bits 4:4 */
    cs_uint32 txem_crcstate        : 27 ; /* bits 31:5 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TX_VOQ_LKUP_DATA0_t;

#define NI_TOP_NI_MC_INDX_LKUP_ACCESS            0xf00100d8
#define NI_TOP_NI_MC_INDX_LKUP_ACCESS_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 err_parity           :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 address              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 address              :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 err_parity           :  1 ; /* bits 17:17 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MC_INDX_LKUP_ACCESS_t;

#define NI_TOP_NI_MC_INDX_LKUP_DATA              0xf00100dc
#define NI_TOP_NI_MC_INDX_LKUP_DATA_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 mc_vec               : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mc_vec               : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MC_INDX_LKUP_DATA_t;

#define NI_TOP_NI_PG_DA1                         0xf00100e0
#define NI_TOP_NI_PG_DA1_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_da1               :  8 ; /* bits 31:24 */
    cs_uint32 pg_da2               :  8 ; /* bits 23:16 */
    cs_uint32 pg_da3               :  8 ; /* bits 15:8 */
    cs_uint32 pg_da4               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_da4               :  8 ; /* bits 7:0 */
    cs_uint32 pg_da3               :  8 ; /* bits 15:8 */
    cs_uint32 pg_da2               :  8 ; /* bits 23:16 */
    cs_uint32 pg_da1               :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_DA1_t;

#define NI_TOP_NI_PG_DA2                         0xf00100e4
#define NI_TOP_NI_PG_DA2_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 pg_da5               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_da5               :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_DA2_t;

#define NI_TOP_NI_PG_SA1                         0xf00100e8
#define NI_TOP_NI_PG_SA1_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_sa1               :  8 ; /* bits 31:24 */
    cs_uint32 pg_sa2               :  8 ; /* bits 23:16 */
    cs_uint32 pg_sa3               :  8 ; /* bits 15:8 */
    cs_uint32 pg_sa4               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_sa4               :  8 ; /* bits 7:0 */
    cs_uint32 pg_sa3               :  8 ; /* bits 15:8 */
    cs_uint32 pg_sa2               :  8 ; /* bits 23:16 */
    cs_uint32 pg_sa1               :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_SA1_t;

#define NI_TOP_NI_PG_SA2                         0xf00100ec
#define NI_TOP_NI_PG_SA2_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 pg_sa5               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_sa5               :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_SA2_t;

#define NI_TOP_NI_PG_CFG0                        0xf00100f0
#define NI_TOP_NI_PG_CFG0_dft                    0x00648064

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_frm_cnt           : 16 ; /* bits 31:16 */
    cs_uint32 pg_len_data          :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 pg_len               : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_len               : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 pg_len_data          :  1 ; /* bits 15:15 */
    cs_uint32 pg_frm_cnt           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_CFG0_t;

#define NI_TOP_NI_PG_CFG1                        0xf00100f4
#define NI_TOP_NI_PG_CFG1_dft                    0x81008100

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_vlan2_tpid        : 16 ; /* bits 31:16 */
    cs_uint32 pg_vlan1_tpid        : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_vlan1_tpid        : 16 ; /* bits 15:0 */
    cs_uint32 pg_vlan2_tpid        : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_CFG1_t;

#define NI_TOP_NI_PG_FXPT                        0xf00100f8
#define NI_TOP_NI_PG_FXPT_dft                    0xaaaa5555

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_fxpat             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_fxpat             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG_FXPT_t;

#define NI_TOP_NI_PG0_CFG1                       0xf00100fc
#define NI_TOP_NI_PG0_CFG1_STRIDE                12
#define NI_TOP_NI_PG0_CFG1_COUNT                 3
#define NI_TOP_NI_PG0_CFG1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_type              : 16 ; /* bits 31:16 */
    cs_uint32 pg_sa6               :  8 ; /* bits 15:8 */
    cs_uint32 pg_da6               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_da6               :  8 ; /* bits 7:0 */
    cs_uint32 pg_sa6               :  8 ; /* bits 15:8 */
    cs_uint32 pg_type              : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG0_CFG1_t;

#define NI_TOP_NI_PG0_CFG2                       0xf0010100
#define NI_TOP_NI_PG0_CFG2_STRIDE                12
#define NI_TOP_NI_PG0_CFG2_COUNT                 3
#define NI_TOP_NI_PG0_CFG2_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pg_vlan2             : 16 ; /* bits 31:16 */
    cs_uint32 pg_vlan1             : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_vlan1             : 16 ; /* bits 15:0 */
    cs_uint32 pg_vlan2             : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG0_CFG2_t;

#define NI_TOP_NI_PG0_CNTRL                      0xf0010104
#define NI_TOP_NI_PG0_CNTRL_STRIDE               12
#define NI_TOP_NI_PG0_CNTRL_COUNT                3
#define NI_TOP_NI_PG0_CNTRL_dft                  0x00080000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  8 ;
    cs_uint32 pg_ipg               :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 pg_insfixpattern     :  1 ; /* bits 10:10 */
    cs_uint32 pg_invpat            :  1 ; /* bits 9:9 */
    cs_uint32 pg_insseqnum         :  1 ; /* bits 8:8 */
    cs_uint32 pg_instype           :  1 ; /* bits 7:7 */
    cs_uint32 pg_insvlan1          :  1 ; /* bits 6:6 */
    cs_uint32 pg_insvlan2          :  1 ; /* bits 5:5 */
    cs_uint32 pg_fixedlen          :  1 ; /* bits 4:4 */
    cs_uint32 pg_linerate          :  2 ; /* bits 3:2 */
    cs_uint32 pg_fixedcount        :  1 ; /* bits 1:1 */
    cs_uint32 pg_en                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pg_en                :  1 ; /* bits 0:0 */
    cs_uint32 pg_fixedcount        :  1 ; /* bits 1:1 */
    cs_uint32 pg_linerate          :  2 ; /* bits 3:2 */
    cs_uint32 pg_fixedlen          :  1 ; /* bits 4:4 */
    cs_uint32 pg_insvlan2          :  1 ; /* bits 5:5 */
    cs_uint32 pg_insvlan1          :  1 ; /* bits 6:6 */
    cs_uint32 pg_instype           :  1 ; /* bits 7:7 */
    cs_uint32 pg_insseqnum         :  1 ; /* bits 8:8 */
    cs_uint32 pg_invpat            :  1 ; /* bits 9:9 */
    cs_uint32 pg_insfixpattern     :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 pg_ipg               :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PG0_CNTRL_t;

#define NI_TOP_NI_PC_DA1                         0xf0010120
#define NI_TOP_NI_PC_DA1_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_da1               :  8 ; /* bits 31:24 */
    cs_uint32 pc_da2               :  8 ; /* bits 23:16 */
    cs_uint32 pc_da3               :  8 ; /* bits 15:8 */
    cs_uint32 pc_da4               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_da4               :  8 ; /* bits 7:0 */
    cs_uint32 pc_da3               :  8 ; /* bits 15:8 */
    cs_uint32 pc_da2               :  8 ; /* bits 23:16 */
    cs_uint32 pc_da1               :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_DA1_t;

#define NI_TOP_NI_PC_DA2                         0xf0010124
#define NI_TOP_NI_PC_DA2_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 pc_da5               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_da5               :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_DA2_t;

#define NI_TOP_NI_PC_SA1                         0xf0010128
#define NI_TOP_NI_PC_SA1_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_sa1               :  8 ; /* bits 31:24 */
    cs_uint32 pc_sa2               :  8 ; /* bits 23:16 */
    cs_uint32 pc_sa3               :  8 ; /* bits 15:8 */
    cs_uint32 pc_sa4               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_sa4               :  8 ; /* bits 7:0 */
    cs_uint32 pc_sa3               :  8 ; /* bits 15:8 */
    cs_uint32 pc_sa2               :  8 ; /* bits 23:16 */
    cs_uint32 pc_sa1               :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_SA1_t;

#define NI_TOP_NI_PC_SA2                         0xf001012c
#define NI_TOP_NI_PC_SA2_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 pc_sa5               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_sa5               :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_SA2_t;

#define NI_TOP_NI_PC_CFG0                        0xf0010130
#define NI_TOP_NI_PC_CFG0_dft                    0x00000064

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 pc_len               : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_len               : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_CFG0_t;

#define NI_TOP_NI_PC_CFG1                        0xf0010134
#define NI_TOP_NI_PC_CFG1_dft                    0x81008100

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_vlan2_tpid        : 16 ; /* bits 31:16 */
    cs_uint32 pc_vlan1_tpid        : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_vlan1_tpid        : 16 ; /* bits 15:0 */
    cs_uint32 pc_vlan2_tpid        : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_CFG1_t;

#define NI_TOP_NI_PC_FXPT                        0xf0010138
#define NI_TOP_NI_PC_FXPT_dft                    0xaaaa5555

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_fxpat             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_fxpat             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC_FXPT_t;

#define NI_TOP_NI_PC0_CFG1                       0xf001013c
#define NI_TOP_NI_PC0_CFG1_STRIDE                16
#define NI_TOP_NI_PC0_CFG1_COUNT                 3
#define NI_TOP_NI_PC0_CFG1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_type              : 16 ; /* bits 31:16 */
    cs_uint32 pc_sa6               :  8 ; /* bits 15:8 */
    cs_uint32 pc_da6               :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_da6               :  8 ; /* bits 7:0 */
    cs_uint32 pc_sa6               :  8 ; /* bits 15:8 */
    cs_uint32 pc_type              : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_CFG1_t;

#define NI_TOP_NI_PC0_CFG2                       0xf0010140
#define NI_TOP_NI_PC0_CFG2_STRIDE                16
#define NI_TOP_NI_PC0_CFG2_COUNT                 3
#define NI_TOP_NI_PC0_CFG2_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pc_vlan2             : 16 ; /* bits 31:16 */
    cs_uint32 pc_vlan1             : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_vlan1             : 16 ; /* bits 15:0 */
    cs_uint32 pc_vlan2             : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_CFG2_t;

#define NI_TOP_NI_PC0_CNTRL                      0xf0010144
#define NI_TOP_NI_PC0_CNTRL_STRIDE               16
#define NI_TOP_NI_PC0_CNTRL_COUNT                3
#define NI_TOP_NI_PC0_CNTRL_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 21 ;
    cs_uint32 pc_expfixpattern     :  1 ; /* bits 10:10 */
    cs_uint32 pc_invpat            :  1 ; /* bits 9:9 */
    cs_uint32 pc_expseqnum         :  1 ; /* bits 8:8 */
    cs_uint32 pc_exptype           :  1 ; /* bits 7:7 */
    cs_uint32 pc_expvlan1          :  1 ; /* bits 6:6 */
    cs_uint32 pc_expvlan2          :  1 ; /* bits 5:5 */
    cs_uint32 pc_fixedlen          :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 pc_en                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_en                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 pc_fixedlen          :  1 ; /* bits 4:4 */
    cs_uint32 pc_expvlan2          :  1 ; /* bits 5:5 */
    cs_uint32 pc_expvlan1          :  1 ; /* bits 6:6 */
    cs_uint32 pc_exptype           :  1 ; /* bits 7:7 */
    cs_uint32 pc_expseqnum         :  1 ; /* bits 8:8 */
    cs_uint32 pc_invpat            :  1 ; /* bits 9:9 */
    cs_uint32 pc_expfixpattern     :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd2               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_CNTRL_t;

#define NI_TOP_NI_PC0_STAT                       0xf0010148
#define NI_TOP_NI_PC0_STAT_STRIDE                16
#define NI_TOP_NI_PC0_STAT_COUNT                 3
#define NI_TOP_NI_PC0_STAT_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 pc_dchkstatus        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pc_dchkstatus        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_STAT_t;

#define NI_TOP_NI_RM_CFG                         0xf001016c
#define NI_TOP_NI_RM_CFG_dft                     0x05000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rm_tbinc             :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 debug_mode           :  1 ; /* bits 11:11 */
    cs_uint32 rm_clrtb             :  1 ; /* bits 10:10 */
    cs_uint32 rm_clrcnt            :  1 ; /* bits 9:9 */
    cs_uint32 rm_cntpkts           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 rm_pid               :  4 ; /* bits 4:1 */
    cs_uint32 rm_en                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rm_en                :  1 ; /* bits 0:0 */
    cs_uint32 rm_pid               :  4 ; /* bits 4:1 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 rm_cntpkts           :  1 ; /* bits 8:8 */
    cs_uint32 rm_clrcnt            :  1 ; /* bits 9:9 */
    cs_uint32 rm_clrtb             :  1 ; /* bits 10:10 */
    cs_uint32 debug_mode           :  1 ; /* bits 11:11 */
    cs_uint32 rsrvd2               : 12 ;
    cs_uint32 rm_tbinc             :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RM_CFG_t;

#define NI_TOP_NI_RM_TBMAX                       0xf0010170
#define NI_TOP_NI_RM_TBMAX_dft                   0x00ffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rm_tbmax             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rm_tbmax             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RM_TBMAX_t;

#define NI_TOP_NI_RM_CNTR                        0xf0010174
#define NI_TOP_NI_RM_CNTR_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rm_cnt               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rm_cnt               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RM_CNTR_t;

#define NI_TOP_NI_RM_LASTCNTR                    0xf0010178
#define NI_TOP_NI_RM_LASTCNTR_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rm_lastcnt           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rm_lastcnt           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RM_LASTCNTR_t;

#define NI_TOP_NI_PPS_TRIG_HW_TS                 0xf001017c
#define NI_TOP_NI_PPS_TRIG_HW_TS_dft             0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pps_trigger_hw_ts    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pps_trigger_hw_ts    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PPS_TRIG_HW_TS_t;

#define NI_TOP_NI_INIT_DONE                      0xf0010180
#define NI_TOP_NI_INIT_DONE_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 ni_init_done         :  1 ; /* bits 1:1 */
    cs_uint32 ni_mib_init_done     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ni_mib_init_done     :  1 ; /* bits 0:0 */
    cs_uint32 ni_init_done         :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INIT_DONE_t;

#define NI_TOP_NI_RXMIB_ACCESS                   0xf0010184
#define NI_TOP_NI_RXMIB_ACCESS_dft               0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 port_id              :  3 ; /* bits 7:5 */
    cs_uint32 counter_id           :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter_id           :  5 ; /* bits 4:0 */
    cs_uint32 port_id              :  3 ; /* bits 7:5 */
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXMIB_ACCESS_t;

#define     counter_id_RxUCPktCnt                         0x0
#define     counter_id_RxMCFrmCnt                         0x1
#define     counter_id_RxBCFrmCnt                         0x2
#define     counter_id_RxOAMFrmCnt                        0x3
#define     counter_id_RxJumboFrmCnt                      0x4
#define     counter_id_RxPauseFrmCnt                      0x5
#define     counter_id_RxUnKnownOCFrmCnt                  0x6
#define     counter_id_RxCrcErrFrmCnt                     0x7
#define     counter_id_RxUndersizeFrmCnt                  0x8
#define     counter_id_RxRuntFrmCnt                       0x9
#define     counter_id_RxOvSizeFrmCnt                     0xa
#define     counter_id_RxJabberFrmCnt                     0xb
#define     counter_id_RxInvalidFrmCnt                    0xc
#define     counter_id_RxStatsFrm64Oct                    0xd
#define     counter_id_RxStatsFrm65to127Oct               0xe
#define     counter_id_RxStatsFrm128to255Oct              0xf
#define     counter_id_RxStatsFrm256to511Oct              0x10
#define     counter_id_RxStatsFrm512to1023Oct             0x11
#define     counter_id_RxStatsFrm1024to1518Oct            0x12
#define     counter_id_RxStatsFrm1519to2100Oct            0x13
#define     counter_id_RxStatsFrm2101to9200Oct            0x14
#define     counter_id_RxStatsFrm9201toMaxOct             0x15
#define     counter_id_RxByteCount_Lo                     0x16
#define     counter_id_RxByteCount_Hi                     0x17

#define NI_TOP_NI_RXMIB_DATA1                    0xf0010188
#define NI_TOP_NI_RXMIB_DATA1_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cnt_val_hi           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cnt_val_hi           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXMIB_DATA1_t;

#define NI_TOP_NI_RXMIB_DATA0                    0xf001018c
#define NI_TOP_NI_RXMIB_DATA0_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cnt_val_lo           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cnt_val_lo           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXMIB_DATA0_t;

#define NI_TOP_NI_TXMIB_ACCESS                   0xf0010190
#define NI_TOP_NI_TXMIB_ACCESS_dft               0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 port_id              :  2 ; /* bits 6:5 */
    cs_uint32 counter_id           :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter_id           :  5 ; /* bits 4:0 */
    cs_uint32 port_id              :  2 ; /* bits 6:5 */
    cs_uint32 rsrvd1               :  9 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXMIB_ACCESS_t;

#define     counter_id_TxUCPktCnt                         0x0
#define     counter_id_TxMCFrmCnt                         0x1
#define     counter_id_TxBCFrmCnt                         0x2
#define     counter_id_TxOAMFrmCnt                        0x3
#define     counter_id_TxJumboFrmCnt                      0x4
#define     counter_id_TxPauseFrmCnt                      0x5
#define     counter_id_TxCrcErrFrmCnt                     0x6
#define     counter_id_TxOvSizeFrmCnt                     0x7
#define     counter_id_TxSingleColFrm                     0x8
#define     counter_id_TxMultiColFrm                      0x9
#define     counter_id_TxLateColFrm                       0xa
#define     counter_id_TxExessColFrm                      0xb
#define     counter_id_TxStatsFrm64Oct                    0xd
#define     counter_id_TxStatsFrm65to127Oct               0xe
#define     counter_id_TxStatsFrm128to255Oct              0xf
#define     counter_id_TxStatsFrm256to511Oct              0x10
#define     counter_id_TxStatsFrm512to1023Oct             0x11
#define     counter_id_TxStatsFrm1024to1518Oct            0x12
#define     counter_id_TxStatsFrm1519to2100Oct            0x13
#define     counter_id_TxStatsFrm2101to9200Oct            0x14
#define     counter_id_TxStatsFrm9201toMaxOct             0x15
#define     counter_id_TxByteCount_Lo                     0x16
#define     counter_id_TxByteCount_Hi                     0x17

#define NI_TOP_NI_TXMIB_DATA1                    0xf0010194
#define NI_TOP_NI_TXMIB_DATA1_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cnt_val_hi           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cnt_val_hi           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXMIB_DATA1_t;

#define NI_TOP_NI_TXMIB_DATA0                    0xf0010198
#define NI_TOP_NI_TXMIB_DATA0_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cnt_val_lo           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cnt_val_lo           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXMIB_DATA0_t;

#define NI_TOP_NI_TXEM_CRCERR_ACCESS             0xf001019c
#define NI_TOP_NI_TXEM_CRCERR_ACCESS_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               : 12 ;
    cs_uint32 port_id              :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 port_id              :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               : 12 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_CRCERR_ACCESS_t;

#define NI_TOP_NI_TXEM_CRCERR_DATA               0xf00101a0
#define NI_TOP_NI_TXEM_CRCERR_DATA_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 txem_crcerrcnt       : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_crcerrcnt       : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_CRCERR_DATA_t;

#define NI_TOP_NI_MAL_PKT_DROPCNT                0xf00101a4
#define NI_TOP_NI_MAL_PKT_DROPCNT_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 mal_packets_dropped  : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mal_packets_dropped  : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MAL_PKT_DROPCNT_t;

#define NI_TOP_NI_MAL_PKT_DROPCNT_CFG            0xf00101a8
#define NI_TOP_NI_MAL_PKT_DROPCNT_CFG_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  2 ;
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               : 16 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 debug_mode           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               : 11 ;
    cs_uint32 op_code              :  2 ; /* bits 29:28 */
    cs_uint32 rsrvd3               :  2 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_MAL_PKT_DROPCNT_CFG_t;

#define NI_TOP_NI_CPUXRAM_ADRCFG_RX_0            0xf00101ac
#define NI_TOP_NI_CPUXRAM_ADRCFG_RX_0_STRIDE     4
#define NI_TOP_NI_CPUXRAM_ADRCFG_RX_0_COUNT      9
#define NI_TOP_NI_CPUXRAM_ADRCFG_RX_0_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 rx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_base_addr         : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_base_addr         : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 rx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd2               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ADRCFG_RX_0_t;

#define NI_TOP_NI_CPUXRAM_ADRCFG_TX_0            0xf00101d0
#define NI_TOP_NI_CPUXRAM_ADRCFG_TX_0_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 tx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 tx_base_addr         : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_base_addr         : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 tx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd2               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ADRCFG_TX_0_t;

#define NI_TOP_NI_CPUXRAM_ADRCFG_TX_1            0xf00101d4
#define NI_TOP_NI_CPUXRAM_ADRCFG_TX_1_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 tx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 tx_base_addr         : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_base_addr         : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 tx_top_addr          : 11 ; /* bits 26:16 */
    cs_uint32 rsrvd2               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ADRCFG_TX_1_t;

#define NI_TOP_NI_CPUXRAM_CFG                    0xf00101d8
#define NI_TOP_NI_CPUXRAM_CFG_dft                0x8a00c5ff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 xram_arb_auto_prior  :  1 ; /* bits 31:31 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 xram_pc_wrapcnt      :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_dma_fifo_srst   :  1 ; /* bits 22:22 */
    cs_uint32 xram_rx_mgmtfifo_srst :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_pcachefifo_srst :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_qmfifo_srst  :  1 ; /* bits 19:19 */
    cs_uint32 xram_cntr_op_code    :  2 ; /* bits 18:17 */
    cs_uint32 xram_cntr_debug_mode :  1 ; /* bits 16:16 */
    cs_uint32 xram_mgmt_promisc_mode :  2 ; /* bits 15:14 */
    cs_uint32 xram_mgmt_term_large_pkt :  1 ; /* bits 13:13 */
    cs_uint32 xram_mgmt_dis_drop_ovsz_pkt :  1 ; /* bits 12:12 */
    cs_uint32 rx_x_drop_err_pkt    :  1 ; /* bits 11:11 */
    cs_uint32 tx_1_cpu_pkt_dis     :  1 ; /* bits 10:10 */
    cs_uint32 tx_0_cpu_pkt_dis     :  1 ; /* bits 9:9 */
    cs_uint32 rx_8_cpu_pkt_dis     :  1 ; /* bits 8:8 */
    cs_uint32 rx_7_cpu_pkt_dis     :  1 ; /* bits 7:7 */
    cs_uint32 rx_6_cpu_pkt_dis     :  1 ; /* bits 6:6 */
    cs_uint32 rx_5_cpu_pkt_dis     :  1 ; /* bits 5:5 */
    cs_uint32 rx_4_cpu_pkt_dis     :  1 ; /* bits 4:4 */
    cs_uint32 rx_3_cpu_pkt_dis     :  1 ; /* bits 3:3 */
    cs_uint32 rx_2_cpu_pkt_dis     :  1 ; /* bits 2:2 */
    cs_uint32 rx_1_cpu_pkt_dis     :  1 ; /* bits 1:1 */
    cs_uint32 rx_0_cpu_pkt_dis     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_0_cpu_pkt_dis     :  1 ; /* bits 0:0 */
    cs_uint32 rx_1_cpu_pkt_dis     :  1 ; /* bits 1:1 */
    cs_uint32 rx_2_cpu_pkt_dis     :  1 ; /* bits 2:2 */
    cs_uint32 rx_3_cpu_pkt_dis     :  1 ; /* bits 3:3 */
    cs_uint32 rx_4_cpu_pkt_dis     :  1 ; /* bits 4:4 */
    cs_uint32 rx_5_cpu_pkt_dis     :  1 ; /* bits 5:5 */
    cs_uint32 rx_6_cpu_pkt_dis     :  1 ; /* bits 6:6 */
    cs_uint32 rx_7_cpu_pkt_dis     :  1 ; /* bits 7:7 */
    cs_uint32 rx_8_cpu_pkt_dis     :  1 ; /* bits 8:8 */
    cs_uint32 tx_0_cpu_pkt_dis     :  1 ; /* bits 9:9 */
    cs_uint32 tx_1_cpu_pkt_dis     :  1 ; /* bits 10:10 */
    cs_uint32 rx_x_drop_err_pkt    :  1 ; /* bits 11:11 */
    cs_uint32 xram_mgmt_dis_drop_ovsz_pkt :  1 ; /* bits 12:12 */
    cs_uint32 xram_mgmt_term_large_pkt :  1 ; /* bits 13:13 */
    cs_uint32 xram_mgmt_promisc_mode :  2 ; /* bits 15:14 */
    cs_uint32 xram_cntr_debug_mode :  1 ; /* bits 16:16 */
    cs_uint32 xram_cntr_op_code    :  2 ; /* bits 18:17 */
    cs_uint32 xram_rx_qmfifo_srst  :  1 ; /* bits 19:19 */
    cs_uint32 xram_rx_pcachefifo_srst :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_mgmtfifo_srst :  1 ; /* bits 21:21 */
    cs_uint32 xram_dma_fifo_srst   :  1 ; /* bits 22:22 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_pc_wrapcnt      :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 xram_arb_auto_prior  :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CFG_t;

#define NI_TOP_NI_CPUXRAM_PTCAL0                 0xf00101dc
#define NI_TOP_NI_CPUXRAM_PTCAL0_dft             0x21043210

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd8               :  1 ;
    cs_uint32 xram_pc_ts7          :  3 ; /* bits 30:28 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 xram_pc_ts6          :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 xram_pc_ts5          :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 xram_pc_ts4          :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 xram_pc_ts3          :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 xram_pc_ts2          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_pc_ts1          :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_pc_ts0          :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_pc_ts0          :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_pc_ts1          :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_pc_ts2          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 xram_pc_ts3          :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 xram_pc_ts4          :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 xram_pc_ts5          :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 xram_pc_ts6          :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 xram_pc_ts7          :  3 ; /* bits 30:28 */
    cs_uint32 rsrvd8               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PTCAL0_t;

#define NI_TOP_NI_CPUXRAM_PTCAL1                 0xf00101e0
#define NI_TOP_NI_CPUXRAM_PTCAL1_dft             0x00000043

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd8               :  1 ;
    cs_uint32 xram_pc_ts15         :  3 ; /* bits 30:28 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 xram_pc_ts14         :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 xram_pc_ts13         :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 xram_pc_ts12         :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 xram_pc_ts11         :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 xram_pc_ts10         :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_pc_ts9          :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_pc_ts8          :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_pc_ts8          :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_pc_ts9          :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_pc_ts10         :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 xram_pc_ts11         :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 xram_pc_ts12         :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 xram_pc_ts13         :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 xram_pc_ts14         :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 xram_pc_ts15         :  3 ; /* bits 30:28 */
    cs_uint32 rsrvd8               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PTCAL1_t;

#define NI_TOP_NI_CPUXRAM_SCH_BP_CFG_0           0xf00101e4
#define NI_TOP_NI_CPUXRAM_SCH_BP_CFG_0_STRIDE    4
#define NI_TOP_NI_CPUXRAM_SCH_BP_CFG_0_COUNT     8
#define NI_TOP_NI_CPUXRAM_SCH_BP_CFG_0_dft       0x000000b4

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 16 ;
    cs_uint32 xram_sch_rdy_mode    :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 xram_sch_rdy_free_thld : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_sch_rdy_free_thld : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 xram_sch_rdy_mode    :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_SCH_BP_CFG_0_t;

#define NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0           0xf0010204
#define NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0_STRIDE    24
#define NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0_COUNT     9
#define NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0_dft       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 pkt_rd_ptr           : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_rd_ptr           : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0_t;

#define NI_TOP_NI_CPUXRAM_CPU_STA_RX_0           0xf0010208
#define NI_TOP_NI_CPUXRAM_CPU_STA_RX_0_STRIDE    24
#define NI_TOP_NI_CPUXRAM_CPU_STA_RX_0_COUNT     9
#define NI_TOP_NI_CPUXRAM_CPU_STA_RX_0_dft       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 16 ;
    cs_uint32 int_colsc_thresh_reached :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 pkt_wr_ptr           : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_wr_ptr           : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 int_colsc_thresh_reached :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CPU_STA_RX_0_t;

#define NI_TOP_NI_CPUXRAM_INT_COLSC_CFG_0        0xf001020c
#define NI_TOP_NI_CPUXRAM_INT_COLSC_CFG_0_STRIDE 24
#define NI_TOP_NI_CPUXRAM_INT_COLSC_CFG_0_COUNT  9
#define NI_TOP_NI_CPUXRAM_INT_COLSC_CFG_0_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 int_colsc_en         :  1 ; /* bits 31:31 */
    cs_uint32 int_colsc_first_en   :  1 ; /* bits 30:30 */
    cs_uint32 int_colsc_pkt        : 10 ; /* bits 29:20 */
    cs_uint32 int_colsc_dly_time   : 20 ; /* bits 19:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_colsc_dly_time   : 20 ; /* bits 19:0 */
    cs_uint32 int_colsc_pkt        : 10 ; /* bits 29:20 */
    cs_uint32 int_colsc_first_en   :  1 ; /* bits 30:30 */
    cs_uint32 int_colsc_en         :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_INT_COLSC_CFG_0_t;

#define NI_TOP_NI_CPUXRAM_PKT_CNT_0              0xf0010210
#define NI_TOP_NI_CPUXRAM_PKT_CNT_0_STRIDE       24
#define NI_TOP_NI_CPUXRAM_PKT_CNT_0_COUNT        9
#define NI_TOP_NI_CPUXRAM_PKT_CNT_0_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 pkt_to_xram          : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_to_xram          : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PKT_CNT_0_t;

#define NI_TOP_NI_CPUXRAM_BYT_CNT_0              0xf0010214
#define NI_TOP_NI_CPUXRAM_BYT_CNT_0_STRIDE       24
#define NI_TOP_NI_CPUXRAM_BYT_CNT_0_COUNT        9
#define NI_TOP_NI_CPUXRAM_BYT_CNT_0_dft          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 byt_to_xram          : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 byt_to_xram          : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_BYT_CNT_0_t;

#define NI_TOP_NI_CPUXRAM_PKT_ERR_DRP_0          0xf0010218
#define NI_TOP_NI_CPUXRAM_PKT_ERR_DRP_0_STRIDE   24
#define NI_TOP_NI_CPUXRAM_PKT_ERR_DRP_0_COUNT    9
#define NI_TOP_NI_CPUXRAM_PKT_ERR_DRP_0_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 pkt_drop_err         : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_err         : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PKT_ERR_DRP_0_t;

#define NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_PTP       0xf00102dc
#define NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_PTP_dft   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 pkt_drop_ovrun_ptp   : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_ovrun_ptp   : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_PTP_t;

#define NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_MGMT      0xf00102e0
#define NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_MGMT_dft  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 pkt_drop_ovrun_mgmt  : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_ovrun_mgmt  : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_PKT_OVRN_DRP_MGMT_t;

#define NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0           0xf00102e4
#define NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0_STRIDE    8
#define NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0_COUNT     2
#define NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0_dft       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 pkt_wr_ptr           : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_wr_ptr           : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0_t;

#define NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0          0xf00102e8
#define NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0_STRIDE   8
#define NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0_COUNT    2
#define NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 pkt_rd_ptr           : 11 ; /* bits 10:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_rd_ptr           : 11 ; /* bits 10:0 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0_t;

#define NI_TOP_NI_DMA_PKT_CNT                    0xf00102f4
#define NI_TOP_NI_DMA_PKT_CNT_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 dma_pkt_to_cpu       : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dma_pkt_to_cpu       : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_DMA_PKT_CNT_t;

#define NI_TOP_NI_DMA_BYTE_CNT                   0xf00102f8
#define NI_TOP_NI_DMA_BYTE_CNT_dft               0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dma_byte_to_cpu      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dma_byte_to_cpu      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_DMA_BYTE_CNT_t;

#define NI_TOP_NI_HW_TS_CNTR                     0xf00102fc
#define NI_TOP_NI_HW_TS_CNTR_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ptp_hw_ts            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ptp_hw_ts            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_HW_TS_CNTR_t;

#define NI_TOP_NI_PTP_SWCFG_ACCESS               0xf0010300
#define NI_TOP_NI_PTP_SWCFG_ACCESS_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 access               :  1 ; /* bits 31:31 */
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 rsrvd1               : 27 ;
    cs_uint32 address              :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 address              :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               : 27 ;
    cs_uint32 rbw                  :  1 ; /* bits 30:30 */
    cs_uint32 access               :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PTP_SWCFG_ACCESS_t;

#define     address_PTP_ASYM_CFG_0                        0x0
#define     address_PTP_ASYM_CFG_1                        0x1
#define     address_PTP_ASYM_CFG_2                        0x2
#define     address_PTP_ASYM_CFG_3                        0x3
#define     address_PTP_SWCOR_CFG                         0x4

#define NI_TOP_NI_PTP_SWCFG_DATA1                0xf0010304
#define NI_TOP_NI_PTP_SWCFG_DATA1_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cfg_hi               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cfg_hi               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PTP_SWCFG_DATA1_t;

#define NI_TOP_NI_PTP_SWCFG_DATA0                0xf0010308
#define NI_TOP_NI_PTP_SWCFG_DATA0_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cfg_lo               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cfg_lo               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PTP_SWCFG_DATA0_t;

#define NI_TOP_NI_DEBUG_1                        0xf001030c
#define NI_TOP_NI_DEBUG_1_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ptp_hw_cnt_dbg       :  1 ; /* bits 31:31 */
    cs_uint32 rsrvd1               : 20 ;
    cs_uint32 hd_backoff_dbg       :  1 ; /* bits 10:10 */
    cs_uint32 hd_backoff_cnt       : 10 ; /* bits 9:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 hd_backoff_cnt       : 10 ; /* bits 9:0 */
    cs_uint32 hd_backoff_dbg       :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               : 20 ;
    cs_uint32 ptp_hw_cnt_dbg       :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_DEBUG_1_t;

#define NI_TOP_NI_DEBUG_2                        0xf0010310
#define NI_TOP_NI_DEBUG_2_dft                    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dbg_ptp_hw_cnt       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dbg_ptp_hw_cnt       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_DEBUG_2_t;

#define NI_TOP_NI_SPARE                          0xf0010314
#define NI_TOP_NI_SPARE_dft                      0x0000ff00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 VALUE                : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 VALUE                : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_SPARE_t;

#define NI_TOP_NI_SPARESAMPLE                    0xf0010318
#define NI_TOP_NI_SPARESAMPLE_dft                0x0000ff00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 VALUE                : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 VALUE                : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_SPARESAMPLE_t;

#define NI_TOP_NI_FPGAA_ID                       0xf001031c
#define NI_TOP_NI_FPGAA_ID_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 FPGAA_ID             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 FPGAA_ID             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_FPGAA_ID_t;

#define NI_TOP_NI_PORT_0_INTERRUPT_0             0xf0010320
#define NI_TOP_NI_PORT_0_INTERRUPT_0_STRIDE      8
#define NI_TOP_NI_PORT_0_INTERRUPT_0_COUNT       8
#define NI_TOP_NI_PORT_0_INTERRUPT_0_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rxcntrl_rd_idleI     :  1 ; /* bits 8:8 */
    cs_uint32 txem_crcerr_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    cs_uint32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    cs_uint32 rxcntrl_usage_exceedI :  1 ; /* bits 4:4 */
    cs_uint32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    cs_uint32 txfifo_overrunI      :  1 ; /* bits 2:2 */
    cs_uint32 txfifo_underrunI     :  1 ; /* bits 1:1 */
    cs_uint32 link_stat_chgI       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 link_stat_chgI       :  1 ; /* bits 0:0 */
    cs_uint32 txfifo_underrunI     :  1 ; /* bits 1:1 */
    cs_uint32 txfifo_overrunI      :  1 ; /* bits 2:2 */
    cs_uint32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    cs_uint32 rxcntrl_usage_exceedI :  1 ; /* bits 4:4 */
    cs_uint32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    cs_uint32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    cs_uint32 txem_crcerr_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 rxcntrl_rd_idleI     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PORT_0_INTERRUPT_0_t;

#define NI_TOP_NI_PORT_0_INTENABLE_0             0xf0010324
#define NI_TOP_NI_PORT_0_INTENABLE_0_STRIDE      8
#define NI_TOP_NI_PORT_0_INTENABLE_0_COUNT       8
#define NI_TOP_NI_PORT_0_INTENABLE_0_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rxcntrl_rd_idleIE    :  1 ; /* bits 8:8 */
    cs_uint32 txem_crcerr_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    cs_uint32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    cs_uint32 rxcntrl_usage_exceedIE :  1 ; /* bits 4:4 */
    cs_uint32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    cs_uint32 txfifo_overrunIE     :  1 ; /* bits 2:2 */
    cs_uint32 txfifo_underrunIE    :  1 ; /* bits 1:1 */
    cs_uint32 link_stat_chgIE      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 link_stat_chgIE      :  1 ; /* bits 0:0 */
    cs_uint32 txfifo_underrunIE    :  1 ; /* bits 1:1 */
    cs_uint32 txfifo_overrunIE     :  1 ; /* bits 2:2 */
    cs_uint32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    cs_uint32 rxcntrl_usage_exceedIE :  1 ; /* bits 4:4 */
    cs_uint32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    cs_uint32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    cs_uint32 txem_crcerr_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 rxcntrl_rd_idleIE    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PORT_0_INTENABLE_0_t;

#define NI_TOP_NI_RXFIFO_INTERRUPT_0             0xf0010360
#define NI_TOP_NI_RXFIFO_INTERRUPT_0_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 18 ;
    cs_uint32 rx_fifo_voq_ecc_corr_errI :  1 ; /* bits 13:13 */
    cs_uint32 rx_fifo_voq_ecc_errI :  1 ; /* bits 12:12 */
    cs_uint32 mcal_pkt_dropI       :  1 ; /* bits 11:11 */
    cs_uint32 mal_drop_pkt_cnt_msb_setI :  1 ; /* bits 10:10 */
    cs_uint32 rx_fifo_ll_ecc_corr_errI :  1 ; /* bits 9:9 */
    cs_uint32 rx_fifo_ll_ecc_errI  :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_eop_bf_flI   :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_noeop_af_flI :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_nosopI       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeopI       :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_congI        :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_voq_fullI    :  1 ; /* bits 2:2 */
    cs_uint32 rxfifo_overrunI      :  1 ; /* bits 1:1 */
    cs_uint32 rxfifo_fullI         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxfifo_fullI         :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_overrunI      :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_voq_fullI    :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_congI        :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_noeopI       :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_nosopI       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeop_af_flI :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_eop_bf_flI   :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_ll_ecc_errI  :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_ll_ecc_corr_errI :  1 ; /* bits 9:9 */
    cs_uint32 mal_drop_pkt_cnt_msb_setI :  1 ; /* bits 10:10 */
    cs_uint32 mcal_pkt_dropI       :  1 ; /* bits 11:11 */
    cs_uint32 rx_fifo_voq_ecc_errI :  1 ; /* bits 12:12 */
    cs_uint32 rx_fifo_voq_ecc_corr_errI :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd1               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_INTERRUPT_0_t;

#define NI_TOP_NI_RXFIFO_INTENABLE_0             0xf0010364
#define NI_TOP_NI_RXFIFO_INTENABLE_0_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 18 ;
    cs_uint32 rx_fifo_voq_ecc_corr_errIE :  1 ; /* bits 13:13 */
    cs_uint32 rx_fifo_voq_ecc_errIE :  1 ; /* bits 12:12 */
    cs_uint32 mcal_pkt_dropIE      :  1 ; /* bits 11:11 */
    cs_uint32 mal_drop_pkt_cnt_msb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 rx_fifo_ll_ecc_corr_errIE :  1 ; /* bits 9:9 */
    cs_uint32 rx_fifo_ll_errIE     :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_eop_bf_flIE  :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_noeop_af_flIE :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_nosopIE      :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeopIE      :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_congIE       :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_voq_fullIE   :  1 ; /* bits 2:2 */
    cs_uint32 rxfifo_overrunIE     :  1 ; /* bits 1:1 */
    cs_uint32 rxfifo_fullIE        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxfifo_fullIE        :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_overrunIE     :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_voq_fullIE   :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_congIE       :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_noeopIE      :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_nosopIE      :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeop_af_flIE :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_eop_bf_flIE  :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_ll_errIE     :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_ll_ecc_corr_errIE :  1 ; /* bits 9:9 */
    cs_uint32 mal_drop_pkt_cnt_msb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 mcal_pkt_dropIE      :  1 ; /* bits 11:11 */
    cs_uint32 rx_fifo_voq_ecc_errIE :  1 ; /* bits 12:12 */
    cs_uint32 rx_fifo_voq_ecc_corr_errIE :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd1               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_INTENABLE_0_t;

#define NI_TOP_NI_TXEM_INTERRUPT_0               0xf0010368
#define NI_TOP_NI_TXEM_INTERRUPT_0_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 22 ;
    cs_uint32 txem_ptp_v6csum0_errI :  1 ; /* bits 9:9 */
    cs_uint32 mc_indx_lkup_mem_perrI :  1 ; /* bits 8:8 */
    cs_uint32 tx_voq_lkup_mem_perrI :  1 ; /* bits 7:7 */
    cs_uint32 txem_ptp_cachevoq_errI :  1 ; /* bits 6:6 */
    cs_uint32 txem_ptp_voqchg_errI :  1 ; /* bits 5:5 */
    cs_uint32 rxmib_fifo_ovfI      :  1 ; /* bits 4:4 */
    cs_uint32 txmib_fifo_ovfI      :  1 ; /* bits 3:3 */
    cs_uint32 txrm_cntovfI         :  1 ; /* bits 2:2 */
    cs_uint32 txem_crc_errI        :  1 ; /* bits 1:1 */
    cs_uint32 txem_ififo_ovfI      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_ififo_ovfI      :  1 ; /* bits 0:0 */
    cs_uint32 txem_crc_errI        :  1 ; /* bits 1:1 */
    cs_uint32 txrm_cntovfI         :  1 ; /* bits 2:2 */
    cs_uint32 txmib_fifo_ovfI      :  1 ; /* bits 3:3 */
    cs_uint32 rxmib_fifo_ovfI      :  1 ; /* bits 4:4 */
    cs_uint32 txem_ptp_voqchg_errI :  1 ; /* bits 5:5 */
    cs_uint32 txem_ptp_cachevoq_errI :  1 ; /* bits 6:6 */
    cs_uint32 tx_voq_lkup_mem_perrI :  1 ; /* bits 7:7 */
    cs_uint32 mc_indx_lkup_mem_perrI :  1 ; /* bits 8:8 */
    cs_uint32 txem_ptp_v6csum0_errI :  1 ; /* bits 9:9 */
    cs_uint32 rsrvd1               : 22 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_INTERRUPT_0_t;

#define NI_TOP_NI_TXEM_INTENABLE_0               0xf001036c
#define NI_TOP_NI_TXEM_INTENABLE_0_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 22 ;
    cs_uint32 txem_ptp_v6csum0_errIE :  1 ; /* bits 9:9 */
    cs_uint32 mc_indx_lkup_mem_perrIE :  1 ; /* bits 8:8 */
    cs_uint32 tx_voq_lkup_mem_perrIE :  1 ; /* bits 7:7 */
    cs_uint32 txem_ptp_cachevoq_errIE :  1 ; /* bits 6:6 */
    cs_uint32 txem_ptp_voqchg_errIE :  1 ; /* bits 5:5 */
    cs_uint32 rxmib_fifo_ovfIE     :  1 ; /* bits 4:4 */
    cs_uint32 txmib_fifo_ovfIE     :  1 ; /* bits 3:3 */
    cs_uint32 txrm_cntovfIE        :  1 ; /* bits 2:2 */
    cs_uint32 txem_crc_errIE       :  1 ; /* bits 1:1 */
    cs_uint32 txem_ififo_ovfIE     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_ififo_ovfIE     :  1 ; /* bits 0:0 */
    cs_uint32 txem_crc_errIE       :  1 ; /* bits 1:1 */
    cs_uint32 txrm_cntovfIE        :  1 ; /* bits 2:2 */
    cs_uint32 txmib_fifo_ovfIE     :  1 ; /* bits 3:3 */
    cs_uint32 rxmib_fifo_ovfIE     :  1 ; /* bits 4:4 */
    cs_uint32 txem_ptp_voqchg_errIE :  1 ; /* bits 5:5 */
    cs_uint32 txem_ptp_cachevoq_errIE :  1 ; /* bits 6:6 */
    cs_uint32 tx_voq_lkup_mem_perrIE :  1 ; /* bits 7:7 */
    cs_uint32 mc_indx_lkup_mem_perrIE :  1 ; /* bits 8:8 */
    cs_uint32 txem_ptp_v6csum0_errIE :  1 ; /* bits 9:9 */
    cs_uint32 rsrvd1               : 22 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_INTENABLE_0_t;

#define NI_TOP_NI_PC0_INTERRUPT_0                0xf0010370
#define NI_TOP_NI_PC0_INTERRUPT_0_STRIDE         8
#define NI_TOP_NI_PC0_INTERRUPT_0_COUNT          3
#define NI_TOP_NI_PC0_INTERRUPT_0_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 framelenmismatchI    :  1 ; /* bits 8:8 */
    cs_uint32 datamismatchI        :  1 ; /* bits 7:7 */
    cs_uint32 seqnummismatchI      :  1 ; /* bits 6:6 */
    cs_uint32 typefieldmismatchI   :  1 ; /* bits 5:5 */
    cs_uint32 vlan2fieldmismatchI  :  1 ; /* bits 4:4 */
    cs_uint32 vlan1fieldmismatchI  :  1 ; /* bits 3:3 */
    cs_uint32 srcaddrmismatchI     :  1 ; /* bits 2:2 */
    cs_uint32 dstaddrmismatchI     :  1 ; /* bits 1:1 */
    cs_uint32 dchkoutofsyncI       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dchkoutofsyncI       :  1 ; /* bits 0:0 */
    cs_uint32 dstaddrmismatchI     :  1 ; /* bits 1:1 */
    cs_uint32 srcaddrmismatchI     :  1 ; /* bits 2:2 */
    cs_uint32 vlan1fieldmismatchI  :  1 ; /* bits 3:3 */
    cs_uint32 vlan2fieldmismatchI  :  1 ; /* bits 4:4 */
    cs_uint32 typefieldmismatchI   :  1 ; /* bits 5:5 */
    cs_uint32 seqnummismatchI      :  1 ; /* bits 6:6 */
    cs_uint32 datamismatchI        :  1 ; /* bits 7:7 */
    cs_uint32 framelenmismatchI    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_INTERRUPT_0_t;

#define NI_TOP_NI_PC0_INTENABLE_0                0xf0010374
#define NI_TOP_NI_PC0_INTENABLE_0_STRIDE         8
#define NI_TOP_NI_PC0_INTENABLE_0_COUNT          3
#define NI_TOP_NI_PC0_INTENABLE_0_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 framelenmismatchE    :  1 ; /* bits 8:8 */
    cs_uint32 datamismatchE        :  1 ; /* bits 7:7 */
    cs_uint32 seqnummismatchE      :  1 ; /* bits 6:6 */
    cs_uint32 typefieldmismatchE   :  1 ; /* bits 5:5 */
    cs_uint32 vlan2fieldmismatchE  :  1 ; /* bits 4:4 */
    cs_uint32 vlan1fieldmismatchE  :  1 ; /* bits 3:3 */
    cs_uint32 srcaddrmismatchE     :  1 ; /* bits 2:2 */
    cs_uint32 dstaddrmismatchE     :  1 ; /* bits 1:1 */
    cs_uint32 dchkoutofsyncE       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dchkoutofsyncE       :  1 ; /* bits 0:0 */
    cs_uint32 dstaddrmismatchE     :  1 ; /* bits 1:1 */
    cs_uint32 srcaddrmismatchE     :  1 ; /* bits 2:2 */
    cs_uint32 vlan1fieldmismatchE  :  1 ; /* bits 3:3 */
    cs_uint32 vlan2fieldmismatchE  :  1 ; /* bits 4:4 */
    cs_uint32 typefieldmismatchE   :  1 ; /* bits 5:5 */
    cs_uint32 seqnummismatchE      :  1 ; /* bits 6:6 */
    cs_uint32 datamismatchE        :  1 ; /* bits 7:7 */
    cs_uint32 framelenmismatchE    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_INTENABLE_0_t;

#define NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_0       0xf0010388
#define NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_0_dft   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setI :  1 ; /* bits 31:31 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setI :  1 ; /* bits 30:30 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setI :  1 ; /* bits 29:29 */
    cs_uint32 byt_to_xram_8_cntmsb_setI :  1 ; /* bits 28:28 */
    cs_uint32 byt_to_xram_7_cntmsb_setI :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_6_cntmsb_setI :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_5_cntmsb_setI :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_4_cntmsb_setI :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_3_cntmsb_setI :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_2_cntmsb_setI :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_1_cntmsb_setI :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_0_cntmsb_setI :  1 ; /* bits 20:20 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setI :  1 ; /* bits 19:19 */
    cs_uint32 pkt_to_xram_8_cntmsb_setI :  1 ; /* bits 18:18 */
    cs_uint32 pkt_to_xram_7_cntmsb_setI :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_6_cntmsb_setI :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_5_cntmsb_setI :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_4_cntmsb_setI :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_3_cntmsb_setI :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_2_cntmsb_setI :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_1_cntmsb_setI :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_0_cntmsb_setI :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_drop_err_8_cntmsb_setI :  1 ; /* bits 8:8 */
    cs_uint32 pkt_drop_err_7_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_6_cntmsb_setI :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_5_cntmsb_setI :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_4_cntmsb_setI :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_3_cntmsb_setI :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_2_cntmsb_setI :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_1_cntmsb_setI :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_0_cntmsb_setI :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_err_0_cntmsb_setI :  1 ; /* bits 0:0 */
    cs_uint32 pkt_drop_err_1_cntmsb_setI :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_2_cntmsb_setI :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_3_cntmsb_setI :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_4_cntmsb_setI :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_5_cntmsb_setI :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_6_cntmsb_setI :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_7_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_8_cntmsb_setI :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_to_xram_0_cntmsb_setI :  1 ; /* bits 10:10 */
    cs_uint32 pkt_to_xram_1_cntmsb_setI :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_2_cntmsb_setI :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_3_cntmsb_setI :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_4_cntmsb_setI :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_5_cntmsb_setI :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_6_cntmsb_setI :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_7_cntmsb_setI :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_8_cntmsb_setI :  1 ; /* bits 18:18 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setI :  1 ; /* bits 19:19 */
    cs_uint32 byt_to_xram_0_cntmsb_setI :  1 ; /* bits 20:20 */
    cs_uint32 byt_to_xram_1_cntmsb_setI :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_2_cntmsb_setI :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_3_cntmsb_setI :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_4_cntmsb_setI :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_5_cntmsb_setI :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_6_cntmsb_setI :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_7_cntmsb_setI :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_8_cntmsb_setI :  1 ; /* bits 28:28 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setI :  1 ; /* bits 29:29 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setI :  1 ; /* bits 30:30 */
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setI :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_0_t;

#define NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_0       0xf001038c
#define NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_0_dft   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setIE :  1 ; /* bits 31:31 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setIE :  1 ; /* bits 30:30 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setIE :  1 ; /* bits 29:29 */
    cs_uint32 byt_to_xram_8_cntmsb_setIE :  1 ; /* bits 28:28 */
    cs_uint32 byt_to_xram_7_cntmsb_setIE :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_6_cntmsb_setIE :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_5_cntmsb_setIE :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_4_cntmsb_setIE :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_3_cntmsb_setIE :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_2_cntmsb_setIE :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_1_cntmsb_setIE :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_0_cntmsb_setIE :  1 ; /* bits 20:20 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setIE :  1 ; /* bits 19:19 */
    cs_uint32 pkt_to_xram_8_cntmsb_setIE :  1 ; /* bits 18:18 */
    cs_uint32 pkt_to_xram_7_cntmsb_setIE :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_6_cntmsb_setIE :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_5_cntmsb_setIE :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_4_cntmsb_setIE :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_3_cntmsb_setIE :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_2_cntmsb_setIE :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_1_cntmsb_setIE :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_0_cntmsb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_drop_err_8_cntmsb_setIE :  1 ; /* bits 8:8 */
    cs_uint32 pkt_drop_err_7_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_6_cntmsb_setIE :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_5_cntmsb_setIE :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_4_cntmsb_setIE :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_3_cntmsb_setIE :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_2_cntmsb_setIE :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_1_cntmsb_setIE :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_0_cntmsb_setIE :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_err_0_cntmsb_setIE :  1 ; /* bits 0:0 */
    cs_uint32 pkt_drop_err_1_cntmsb_setIE :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_2_cntmsb_setIE :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_3_cntmsb_setIE :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_4_cntmsb_setIE :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_5_cntmsb_setIE :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_6_cntmsb_setIE :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_7_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_8_cntmsb_setIE :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_to_xram_0_cntmsb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 pkt_to_xram_1_cntmsb_setIE :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_2_cntmsb_setIE :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_3_cntmsb_setIE :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_4_cntmsb_setIE :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_5_cntmsb_setIE :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_6_cntmsb_setIE :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_7_cntmsb_setIE :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_8_cntmsb_setIE :  1 ; /* bits 18:18 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setIE :  1 ; /* bits 19:19 */
    cs_uint32 byt_to_xram_0_cntmsb_setIE :  1 ; /* bits 20:20 */
    cs_uint32 byt_to_xram_1_cntmsb_setIE :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_2_cntmsb_setIE :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_3_cntmsb_setIE :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_4_cntmsb_setIE :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_5_cntmsb_setIE :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_6_cntmsb_setIE :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_7_cntmsb_setIE :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_8_cntmsb_setIE :  1 ; /* bits 28:28 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setIE :  1 ; /* bits 29:29 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setIE :  1 ; /* bits 30:30 */
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setIE :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_0_t;

#define NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_0        0xf0010390
#define NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_0_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 dma_fifo_overrunI    :  1 ; /* bits 23:23 */
    cs_uint32 xram_rx_mgmtfifo_overrunI :  1 ; /* bits 22:22 */
    cs_uint32 xram_rx_ptpfifo_overrunI :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_qmfifo_overrunI :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_8_dis_pktI   :  1 ; /* bits 18:18 */
    cs_uint32 xram_rx_7_dis_pktI   :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_6_dis_pktI   :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_5_dis_pktI   :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_4_dis_pktI   :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_3_dis_pktI   :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_2_dis_pktI   :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_1_dis_pktI   :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_0_dis_pktI   :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_8_ptrbkupI   :  1 ; /* bits 8:8 */
    cs_uint32 xram_rx_7_ptrbkupI   :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_6_ptrbkupI   :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_5_ptrbkupI   :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_4_ptrbkupI   :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_3_ptrbkupI   :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_2_ptrbkupI   :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_1_ptrbkupI   :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_0_ptrbkupI   :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_0_ptrbkupI   :  1 ; /* bits 0:0 */
    cs_uint32 xram_rx_1_ptrbkupI   :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_2_ptrbkupI   :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_3_ptrbkupI   :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_4_ptrbkupI   :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_5_ptrbkupI   :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_6_ptrbkupI   :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_7_ptrbkupI   :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_8_ptrbkupI   :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_0_dis_pktI   :  1 ; /* bits 10:10 */
    cs_uint32 xram_rx_1_dis_pktI   :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_2_dis_pktI   :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_3_dis_pktI   :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_4_dis_pktI   :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_5_dis_pktI   :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_6_dis_pktI   :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_7_dis_pktI   :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_8_dis_pktI   :  1 ; /* bits 18:18 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_qmfifo_overrunI :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_ptpfifo_overrunI :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_mgmtfifo_overrunI :  1 ; /* bits 22:22 */
    cs_uint32 dma_fifo_overrunI    :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_0_t;

#define NI_TOP_NI_CPUXRAM_ERR_INTENABLE_0        0xf0010394
#define NI_TOP_NI_CPUXRAM_ERR_INTENABLE_0_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 dma_fifo_overrunIE   :  1 ; /* bits 23:23 */
    cs_uint32 xram_rx_mgmtfifo_overrunIE :  1 ; /* bits 22:22 */
    cs_uint32 xram_rx_ptpfifo_overrunIE :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_qmfifo_overrunIE :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_8_dis_pktIE  :  1 ; /* bits 18:18 */
    cs_uint32 xram_rx_7_dis_pktIE  :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_6_dis_pktIE  :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_5_dis_pktIE  :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_4_dis_pktIE  :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_3_dis_pktIE  :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_2_dis_pktIE  :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_1_dis_pktIE  :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_0_dis_pktIE  :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_8_ptrbkupIE  :  1 ; /* bits 8:8 */
    cs_uint32 xram_rx_7_ptrbkupIE  :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_6_ptrbkupIE  :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_5_ptrbkupIE  :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_4_ptrbkupIE  :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_3_ptrbkupIE  :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_2_ptrbkupIE  :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_1_ptrbkupIE  :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_0_ptrbkupIE  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_0_ptrbkupIE  :  1 ; /* bits 0:0 */
    cs_uint32 xram_rx_1_ptrbkupIE  :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_2_ptrbkupIE  :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_3_ptrbkupIE  :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_4_ptrbkupIE  :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_5_ptrbkupIE  :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_6_ptrbkupIE  :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_7_ptrbkupIE  :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_8_ptrbkupIE  :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_0_dis_pktIE  :  1 ; /* bits 10:10 */
    cs_uint32 xram_rx_1_dis_pktIE  :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_2_dis_pktIE  :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_3_dis_pktIE  :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_4_dis_pktIE  :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_5_dis_pktIE  :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_6_dis_pktIE  :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_7_dis_pktIE  :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_8_dis_pktIE  :  1 ; /* bits 18:18 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_qmfifo_overrunIE :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_ptpfifo_overrunIE :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_mgmtfifo_overrunIE :  1 ; /* bits 22:22 */
    cs_uint32 dma_fifo_overrunIE   :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ERR_INTENABLE_0_t;

#define NI_TOP_NI_INTERRUPT_0                    0xf0010398
#define NI_TOP_NI_INTERRUPT_0_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 cpuxram_int_stat_err :  1 ; /* bits 14:14 */
    cs_uint32 cpuxram_int_stat_cntr :  1 ; /* bits 13:13 */
    cs_uint32 int_stat_pc2         :  1 ; /* bits 12:12 */
    cs_uint32 int_stat_pc1         :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc0         :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_txem        :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_rxfifo      :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_pspid_7     :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_pspid_6     :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_5     :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_4     :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_3     :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_2     :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_1     :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_0     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_stat_pspid_0     :  1 ; /* bits 0:0 */
    cs_uint32 int_stat_pspid_1     :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_2     :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_3     :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_4     :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_5     :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_6     :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_7     :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_rxfifo      :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_txem        :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_pc0         :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_pc1         :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc2         :  1 ; /* bits 12:12 */
    cs_uint32 cpuxram_int_stat_cntr :  1 ; /* bits 13:13 */
    cs_uint32 cpuxram_int_stat_err :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INTERRUPT_0_t;

#define NI_TOP_NI_INTENABLE_0                    0xf001039c
#define NI_TOP_NI_INTENABLE_0_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 cpuxram_int_stat_err_en :  1 ; /* bits 14:14 */
    cs_uint32 cpuxram_int_stat_cntr_en :  1 ; /* bits 13:13 */
    cs_uint32 int_stat_pc2_en      :  1 ; /* bits 12:12 */
    cs_uint32 int_stat_pc1_en      :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc0_en      :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_txem_en     :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_rxfifo_en   :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_pspid_7_en  :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_pspid_6_en  :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_5_en  :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_4_en  :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_3_en  :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_2_en  :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_1_en  :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_0_en  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_stat_pspid_0_en  :  1 ; /* bits 0:0 */
    cs_uint32 int_stat_pspid_1_en  :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_2_en  :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_3_en  :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_4_en  :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_5_en  :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_6_en  :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_7_en  :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_rxfifo_en   :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_txem_en     :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_pc0_en      :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_pc1_en      :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc2_en      :  1 ; /* bits 12:12 */
    cs_uint32 cpuxram_int_stat_cntr_en :  1 ; /* bits 13:13 */
    cs_uint32 cpuxram_int_stat_err_en :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INTENABLE_0_t;

#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_0    0xf00103a0
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_0_STRIDE 8
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_0_COUNT 9
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_0_dft 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 xram_rx_doneI        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_doneI        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_0_t;

#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_0    0xf00103a4
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_0_STRIDE 8
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_0_COUNT 9
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_0_dft 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 xram_rx_doneIE       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_doneIE       :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_0_t;

#define NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_0      0xf00103e8
#define NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_0_dft  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 xram_tx_1_doneI      :  1 ; /* bits 1:1 */
    cs_uint32 xram_tx_0_doneI      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_tx_0_doneI      :  1 ; /* bits 0:0 */
    cs_uint32 xram_tx_1_doneI      :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_0_t;

#define NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_0      0xf00103ec
#define NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_0_dft  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 xram_tx_1_doneIE     :  1 ; /* bits 1:1 */
    cs_uint32 xram_tx_0_doneIE     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_tx_0_doneIE     :  1 ; /* bits 0:0 */
    cs_uint32 xram_tx_1_doneIE     :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_0_t;

#define NI_TOP_NI_WOL_STAT_0_INT_0               0xf00103f0
#define NI_TOP_NI_WOL_STAT_0_INT_0_STRIDE        8
#define NI_TOP_NI_WOL_STAT_0_INT_0_COUNT         3
#define NI_TOP_NI_WOL_STAT_0_INT_0_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 ni_wol_int           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ni_wol_int           :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_STAT_0_INT_0_t;

#define NI_TOP_NI_WOL_STAT_0_INTENABLE_0         0xf00103f4
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_0_STRIDE  8
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_0_COUNT   3
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_0_dft     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 ni_wol_intIE         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ni_wol_intIE         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_STAT_0_INTENABLE_0_t;

#define NI_TOP_NI_PORT_0_INTERRUPT_1             0xf0010408
#define NI_TOP_NI_PORT_0_INTERRUPT_1_STRIDE      8
#define NI_TOP_NI_PORT_0_INTERRUPT_1_COUNT       8
#define NI_TOP_NI_PORT_0_INTERRUPT_1_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rxcntrl_rd_idleI     :  1 ; /* bits 8:8 */
    cs_uint32 txem_crcerr_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    cs_uint32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    cs_uint32 rxcntrl_usage_exceedI :  1 ; /* bits 4:4 */
    cs_uint32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    cs_uint32 txfifo_overrunI      :  1 ; /* bits 2:2 */
    cs_uint32 txfifo_underrunI     :  1 ; /* bits 1:1 */
    cs_uint32 link_stat_chgI       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 link_stat_chgI       :  1 ; /* bits 0:0 */
    cs_uint32 txfifo_underrunI     :  1 ; /* bits 1:1 */
    cs_uint32 txfifo_overrunI      :  1 ; /* bits 2:2 */
    cs_uint32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    cs_uint32 rxcntrl_usage_exceedI :  1 ; /* bits 4:4 */
    cs_uint32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    cs_uint32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    cs_uint32 txem_crcerr_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 rxcntrl_rd_idleI     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PORT_0_INTERRUPT_1_t;

#define NI_TOP_NI_PORT_0_INTENABLE_1             0xf001040c
#define NI_TOP_NI_PORT_0_INTENABLE_1_STRIDE      8
#define NI_TOP_NI_PORT_0_INTENABLE_1_COUNT       8
#define NI_TOP_NI_PORT_0_INTENABLE_1_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rxcntrl_rd_idleIE    :  1 ; /* bits 8:8 */
    cs_uint32 txem_crcerr_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    cs_uint32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    cs_uint32 rxcntrl_usage_exceedIE :  1 ; /* bits 4:4 */
    cs_uint32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    cs_uint32 txfifo_overrunIE     :  1 ; /* bits 2:2 */
    cs_uint32 txfifo_underrunIE    :  1 ; /* bits 1:1 */
    cs_uint32 link_stat_chgIE      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 link_stat_chgIE      :  1 ; /* bits 0:0 */
    cs_uint32 txfifo_underrunIE    :  1 ; /* bits 1:1 */
    cs_uint32 txfifo_overrunIE     :  1 ; /* bits 2:2 */
    cs_uint32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    cs_uint32 rxcntrl_usage_exceedIE :  1 ; /* bits 4:4 */
    cs_uint32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    cs_uint32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    cs_uint32 txem_crcerr_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 rxcntrl_rd_idleIE    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PORT_0_INTENABLE_1_t;

#define NI_TOP_NI_RXFIFO_INTERRUPT_1             0xf0010448
#define NI_TOP_NI_RXFIFO_INTERRUPT_1_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 18 ;
    cs_uint32 rx_fifo_voq_ecc_corr_errI :  1 ; /* bits 13:13 */
    cs_uint32 rx_fifo_voq_ecc_errI :  1 ; /* bits 12:12 */
    cs_uint32 mcal_pkt_dropI       :  1 ; /* bits 11:11 */
    cs_uint32 mal_drop_pkt_cnt_msb_setI :  1 ; /* bits 10:10 */
    cs_uint32 rx_fifo_ll_ecc_corr_errI :  1 ; /* bits 9:9 */
    cs_uint32 rx_fifo_ll_ecc_errI  :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_eop_bf_flI   :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_noeop_af_flI :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_nosopI       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeopI       :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_congI        :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_voq_fullI    :  1 ; /* bits 2:2 */
    cs_uint32 rxfifo_overrunI      :  1 ; /* bits 1:1 */
    cs_uint32 rxfifo_fullI         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxfifo_fullI         :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_overrunI      :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_voq_fullI    :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_congI        :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_noeopI       :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_nosopI       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeop_af_flI :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_eop_bf_flI   :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_ll_ecc_errI  :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_ll_ecc_corr_errI :  1 ; /* bits 9:9 */
    cs_uint32 mal_drop_pkt_cnt_msb_setI :  1 ; /* bits 10:10 */
    cs_uint32 mcal_pkt_dropI       :  1 ; /* bits 11:11 */
    cs_uint32 rx_fifo_voq_ecc_errI :  1 ; /* bits 12:12 */
    cs_uint32 rx_fifo_voq_ecc_corr_errI :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd1               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_INTERRUPT_1_t;

#define NI_TOP_NI_RXFIFO_INTENABLE_1             0xf001044c
#define NI_TOP_NI_RXFIFO_INTENABLE_1_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 18 ;
    cs_uint32 rx_fifo_voq_ecc_corr_errIE :  1 ; /* bits 13:13 */
    cs_uint32 rx_fifo_voq_ecc_errIE :  1 ; /* bits 12:12 */
    cs_uint32 mcal_pkt_dropIE      :  1 ; /* bits 11:11 */
    cs_uint32 mal_drop_pkt_cnt_msb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 rx_fifo_ll_ecc_corr_errIE :  1 ; /* bits 9:9 */
    cs_uint32 rx_fifo_ll_errIE     :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_eop_bf_flIE  :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_noeop_af_flIE :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_nosopIE      :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeopIE      :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_congIE       :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_voq_fullIE   :  1 ; /* bits 2:2 */
    cs_uint32 rxfifo_overrunIE     :  1 ; /* bits 1:1 */
    cs_uint32 rxfifo_fullIE        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxfifo_fullIE        :  1 ; /* bits 0:0 */
    cs_uint32 rxfifo_overrunIE     :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_voq_fullIE   :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_congIE       :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_noeopIE      :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_nosopIE      :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_noeop_af_flIE :  1 ; /* bits 6:6 */
    cs_uint32 rx_fifo_eop_bf_flIE  :  1 ; /* bits 7:7 */
    cs_uint32 rx_fifo_ll_errIE     :  1 ; /* bits 8:8 */
    cs_uint32 rx_fifo_ll_ecc_corr_errIE :  1 ; /* bits 9:9 */
    cs_uint32 mal_drop_pkt_cnt_msb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 mcal_pkt_dropIE      :  1 ; /* bits 11:11 */
    cs_uint32 rx_fifo_voq_ecc_errIE :  1 ; /* bits 12:12 */
    cs_uint32 rx_fifo_voq_ecc_corr_errIE :  1 ; /* bits 13:13 */
    cs_uint32 rsrvd1               : 18 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_RXFIFO_INTENABLE_1_t;

#define NI_TOP_NI_TXEM_INTERRUPT_1               0xf0010450
#define NI_TOP_NI_TXEM_INTERRUPT_1_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 22 ;
    cs_uint32 txem_ptp_v6csum0_errI :  1 ; /* bits 9:9 */
    cs_uint32 mc_indx_lkup_mem_perrI :  1 ; /* bits 8:8 */
    cs_uint32 tx_voq_lkup_mem_perrI :  1 ; /* bits 7:7 */
    cs_uint32 txem_ptp_cachevoq_errI :  1 ; /* bits 6:6 */
    cs_uint32 txem_ptp_voqchg_errI :  1 ; /* bits 5:5 */
    cs_uint32 rxmib_fifo_ovfI      :  1 ; /* bits 4:4 */
    cs_uint32 txmib_fifo_ovfI      :  1 ; /* bits 3:3 */
    cs_uint32 txrm_cntovfI         :  1 ; /* bits 2:2 */
    cs_uint32 txem_crc_errI        :  1 ; /* bits 1:1 */
    cs_uint32 txem_ififo_ovfI      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_ififo_ovfI      :  1 ; /* bits 0:0 */
    cs_uint32 txem_crc_errI        :  1 ; /* bits 1:1 */
    cs_uint32 txrm_cntovfI         :  1 ; /* bits 2:2 */
    cs_uint32 txmib_fifo_ovfI      :  1 ; /* bits 3:3 */
    cs_uint32 rxmib_fifo_ovfI      :  1 ; /* bits 4:4 */
    cs_uint32 txem_ptp_voqchg_errI :  1 ; /* bits 5:5 */
    cs_uint32 txem_ptp_cachevoq_errI :  1 ; /* bits 6:6 */
    cs_uint32 tx_voq_lkup_mem_perrI :  1 ; /* bits 7:7 */
    cs_uint32 mc_indx_lkup_mem_perrI :  1 ; /* bits 8:8 */
    cs_uint32 txem_ptp_v6csum0_errI :  1 ; /* bits 9:9 */
    cs_uint32 rsrvd1               : 22 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_INTERRUPT_1_t;

#define NI_TOP_NI_TXEM_INTENABLE_1               0xf0010454
#define NI_TOP_NI_TXEM_INTENABLE_1_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 22 ;
    cs_uint32 txem_ptp_v6csum0_errIE :  1 ; /* bits 9:9 */
    cs_uint32 mc_indx_lkup_mem_perrIE :  1 ; /* bits 8:8 */
    cs_uint32 tx_voq_lkup_mem_perrIE :  1 ; /* bits 7:7 */
    cs_uint32 txem_ptp_cachevoq_errIE :  1 ; /* bits 6:6 */
    cs_uint32 txem_ptp_voqchg_errIE :  1 ; /* bits 5:5 */
    cs_uint32 rxmib_fifo_ovfIE     :  1 ; /* bits 4:4 */
    cs_uint32 txmib_fifo_ovfIE     :  1 ; /* bits 3:3 */
    cs_uint32 txrm_cntovfIE        :  1 ; /* bits 2:2 */
    cs_uint32 txem_crc_errIE       :  1 ; /* bits 1:1 */
    cs_uint32 txem_ififo_ovfIE     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txem_ififo_ovfIE     :  1 ; /* bits 0:0 */
    cs_uint32 txem_crc_errIE       :  1 ; /* bits 1:1 */
    cs_uint32 txrm_cntovfIE        :  1 ; /* bits 2:2 */
    cs_uint32 txmib_fifo_ovfIE     :  1 ; /* bits 3:3 */
    cs_uint32 rxmib_fifo_ovfIE     :  1 ; /* bits 4:4 */
    cs_uint32 txem_ptp_voqchg_errIE :  1 ; /* bits 5:5 */
    cs_uint32 txem_ptp_cachevoq_errIE :  1 ; /* bits 6:6 */
    cs_uint32 tx_voq_lkup_mem_perrIE :  1 ; /* bits 7:7 */
    cs_uint32 mc_indx_lkup_mem_perrIE :  1 ; /* bits 8:8 */
    cs_uint32 txem_ptp_v6csum0_errIE :  1 ; /* bits 9:9 */
    cs_uint32 rsrvd1               : 22 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_TXEM_INTENABLE_1_t;

#define NI_TOP_NI_PC0_INTERRUPT_1                0xf0010458
#define NI_TOP_NI_PC0_INTERRUPT_1_STRIDE         8
#define NI_TOP_NI_PC0_INTERRUPT_1_COUNT          3
#define NI_TOP_NI_PC0_INTERRUPT_1_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 framelenmismatchI    :  1 ; /* bits 8:8 */
    cs_uint32 datamismatchI        :  1 ; /* bits 7:7 */
    cs_uint32 seqnummismatchI      :  1 ; /* bits 6:6 */
    cs_uint32 typefieldmismatchI   :  1 ; /* bits 5:5 */
    cs_uint32 vlan2fieldmismatchI  :  1 ; /* bits 4:4 */
    cs_uint32 vlan1fieldmismatchI  :  1 ; /* bits 3:3 */
    cs_uint32 srcaddrmismatchI     :  1 ; /* bits 2:2 */
    cs_uint32 dstaddrmismatchI     :  1 ; /* bits 1:1 */
    cs_uint32 dchkoutofsyncI       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dchkoutofsyncI       :  1 ; /* bits 0:0 */
    cs_uint32 dstaddrmismatchI     :  1 ; /* bits 1:1 */
    cs_uint32 srcaddrmismatchI     :  1 ; /* bits 2:2 */
    cs_uint32 vlan1fieldmismatchI  :  1 ; /* bits 3:3 */
    cs_uint32 vlan2fieldmismatchI  :  1 ; /* bits 4:4 */
    cs_uint32 typefieldmismatchI   :  1 ; /* bits 5:5 */
    cs_uint32 seqnummismatchI      :  1 ; /* bits 6:6 */
    cs_uint32 datamismatchI        :  1 ; /* bits 7:7 */
    cs_uint32 framelenmismatchI    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_INTERRUPT_1_t;

#define NI_TOP_NI_PC0_INTENABLE_1                0xf001045c
#define NI_TOP_NI_PC0_INTENABLE_1_STRIDE         8
#define NI_TOP_NI_PC0_INTENABLE_1_COUNT          3
#define NI_TOP_NI_PC0_INTENABLE_1_dft            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 framelenmismatchE    :  1 ; /* bits 8:8 */
    cs_uint32 datamismatchE        :  1 ; /* bits 7:7 */
    cs_uint32 seqnummismatchE      :  1 ; /* bits 6:6 */
    cs_uint32 typefieldmismatchE   :  1 ; /* bits 5:5 */
    cs_uint32 vlan2fieldmismatchE  :  1 ; /* bits 4:4 */
    cs_uint32 vlan1fieldmismatchE  :  1 ; /* bits 3:3 */
    cs_uint32 srcaddrmismatchE     :  1 ; /* bits 2:2 */
    cs_uint32 dstaddrmismatchE     :  1 ; /* bits 1:1 */
    cs_uint32 dchkoutofsyncE       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dchkoutofsyncE       :  1 ; /* bits 0:0 */
    cs_uint32 dstaddrmismatchE     :  1 ; /* bits 1:1 */
    cs_uint32 srcaddrmismatchE     :  1 ; /* bits 2:2 */
    cs_uint32 vlan1fieldmismatchE  :  1 ; /* bits 3:3 */
    cs_uint32 vlan2fieldmismatchE  :  1 ; /* bits 4:4 */
    cs_uint32 typefieldmismatchE   :  1 ; /* bits 5:5 */
    cs_uint32 seqnummismatchE      :  1 ; /* bits 6:6 */
    cs_uint32 datamismatchE        :  1 ; /* bits 7:7 */
    cs_uint32 framelenmismatchE    :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_PC0_INTENABLE_1_t;

#define NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_1       0xf0010470
#define NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_1_dft   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setI :  1 ; /* bits 31:31 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setI :  1 ; /* bits 30:30 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setI :  1 ; /* bits 29:29 */
    cs_uint32 byt_to_xram_8_cntmsb_setI :  1 ; /* bits 28:28 */
    cs_uint32 byt_to_xram_7_cntmsb_setI :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_6_cntmsb_setI :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_5_cntmsb_setI :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_4_cntmsb_setI :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_3_cntmsb_setI :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_2_cntmsb_setI :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_1_cntmsb_setI :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_0_cntmsb_setI :  1 ; /* bits 20:20 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setI :  1 ; /* bits 19:19 */
    cs_uint32 pkt_to_xram_8_cntmsb_setI :  1 ; /* bits 18:18 */
    cs_uint32 pkt_to_xram_7_cntmsb_setI :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_6_cntmsb_setI :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_5_cntmsb_setI :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_4_cntmsb_setI :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_3_cntmsb_setI :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_2_cntmsb_setI :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_1_cntmsb_setI :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_0_cntmsb_setI :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_drop_err_8_cntmsb_setI :  1 ; /* bits 8:8 */
    cs_uint32 pkt_drop_err_7_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_6_cntmsb_setI :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_5_cntmsb_setI :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_4_cntmsb_setI :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_3_cntmsb_setI :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_2_cntmsb_setI :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_1_cntmsb_setI :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_0_cntmsb_setI :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_err_0_cntmsb_setI :  1 ; /* bits 0:0 */
    cs_uint32 pkt_drop_err_1_cntmsb_setI :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_2_cntmsb_setI :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_3_cntmsb_setI :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_4_cntmsb_setI :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_5_cntmsb_setI :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_6_cntmsb_setI :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_7_cntmsb_setI :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_8_cntmsb_setI :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_to_xram_0_cntmsb_setI :  1 ; /* bits 10:10 */
    cs_uint32 pkt_to_xram_1_cntmsb_setI :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_2_cntmsb_setI :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_3_cntmsb_setI :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_4_cntmsb_setI :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_5_cntmsb_setI :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_6_cntmsb_setI :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_7_cntmsb_setI :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_8_cntmsb_setI :  1 ; /* bits 18:18 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setI :  1 ; /* bits 19:19 */
    cs_uint32 byt_to_xram_0_cntmsb_setI :  1 ; /* bits 20:20 */
    cs_uint32 byt_to_xram_1_cntmsb_setI :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_2_cntmsb_setI :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_3_cntmsb_setI :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_4_cntmsb_setI :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_5_cntmsb_setI :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_6_cntmsb_setI :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_7_cntmsb_setI :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_8_cntmsb_setI :  1 ; /* bits 28:28 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setI :  1 ; /* bits 29:29 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setI :  1 ; /* bits 30:30 */
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setI :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CNTR_INTERRUPT_1_t;

#define NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_1       0xf0010474
#define NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_1_dft   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setIE :  1 ; /* bits 31:31 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setIE :  1 ; /* bits 30:30 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setIE :  1 ; /* bits 29:29 */
    cs_uint32 byt_to_xram_8_cntmsb_setIE :  1 ; /* bits 28:28 */
    cs_uint32 byt_to_xram_7_cntmsb_setIE :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_6_cntmsb_setIE :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_5_cntmsb_setIE :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_4_cntmsb_setIE :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_3_cntmsb_setIE :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_2_cntmsb_setIE :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_1_cntmsb_setIE :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_0_cntmsb_setIE :  1 ; /* bits 20:20 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setIE :  1 ; /* bits 19:19 */
    cs_uint32 pkt_to_xram_8_cntmsb_setIE :  1 ; /* bits 18:18 */
    cs_uint32 pkt_to_xram_7_cntmsb_setIE :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_6_cntmsb_setIE :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_5_cntmsb_setIE :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_4_cntmsb_setIE :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_3_cntmsb_setIE :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_2_cntmsb_setIE :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_1_cntmsb_setIE :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_0_cntmsb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_drop_err_8_cntmsb_setIE :  1 ; /* bits 8:8 */
    cs_uint32 pkt_drop_err_7_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_6_cntmsb_setIE :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_5_cntmsb_setIE :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_4_cntmsb_setIE :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_3_cntmsb_setIE :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_2_cntmsb_setIE :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_1_cntmsb_setIE :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_0_cntmsb_setIE :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 pkt_drop_err_0_cntmsb_setIE :  1 ; /* bits 0:0 */
    cs_uint32 pkt_drop_err_1_cntmsb_setIE :  1 ; /* bits 1:1 */
    cs_uint32 pkt_drop_err_2_cntmsb_setIE :  1 ; /* bits 2:2 */
    cs_uint32 pkt_drop_err_3_cntmsb_setIE :  1 ; /* bits 3:3 */
    cs_uint32 pkt_drop_err_4_cntmsb_setIE :  1 ; /* bits 4:4 */
    cs_uint32 pkt_drop_err_5_cntmsb_setIE :  1 ; /* bits 5:5 */
    cs_uint32 pkt_drop_err_6_cntmsb_setIE :  1 ; /* bits 6:6 */
    cs_uint32 pkt_drop_err_7_cntmsb_setIE :  1 ; /* bits 7:7 */
    cs_uint32 pkt_drop_err_8_cntmsb_setIE :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 pkt_to_xram_0_cntmsb_setIE :  1 ; /* bits 10:10 */
    cs_uint32 pkt_to_xram_1_cntmsb_setIE :  1 ; /* bits 11:11 */
    cs_uint32 pkt_to_xram_2_cntmsb_setIE :  1 ; /* bits 12:12 */
    cs_uint32 pkt_to_xram_3_cntmsb_setIE :  1 ; /* bits 13:13 */
    cs_uint32 pkt_to_xram_4_cntmsb_setIE :  1 ; /* bits 14:14 */
    cs_uint32 pkt_to_xram_5_cntmsb_setIE :  1 ; /* bits 15:15 */
    cs_uint32 pkt_to_xram_6_cntmsb_setIE :  1 ; /* bits 16:16 */
    cs_uint32 pkt_to_xram_7_cntmsb_setIE :  1 ; /* bits 17:17 */
    cs_uint32 pkt_to_xram_8_cntmsb_setIE :  1 ; /* bits 18:18 */
    cs_uint32 pkt_drop_ovrun_ptp_cntmsb_setIE :  1 ; /* bits 19:19 */
    cs_uint32 byt_to_xram_0_cntmsb_setIE :  1 ; /* bits 20:20 */
    cs_uint32 byt_to_xram_1_cntmsb_setIE :  1 ; /* bits 21:21 */
    cs_uint32 byt_to_xram_2_cntmsb_setIE :  1 ; /* bits 22:22 */
    cs_uint32 byt_to_xram_3_cntmsb_setIE :  1 ; /* bits 23:23 */
    cs_uint32 byt_to_xram_4_cntmsb_setIE :  1 ; /* bits 24:24 */
    cs_uint32 byt_to_xram_5_cntmsb_setIE :  1 ; /* bits 25:25 */
    cs_uint32 byt_to_xram_6_cntmsb_setIE :  1 ; /* bits 26:26 */
    cs_uint32 byt_to_xram_7_cntmsb_setIE :  1 ; /* bits 27:27 */
    cs_uint32 byt_to_xram_8_cntmsb_setIE :  1 ; /* bits 28:28 */
    cs_uint32 dma_pkt_to_cpu_cntmsb_setIE :  1 ; /* bits 29:29 */
    cs_uint32 dma_byte_to_cpu_cntmsb_setIE :  1 ; /* bits 30:30 */
    cs_uint32 pkt_drop_ovrun_mgmt_cntmsb_setIE :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_CNTR_INTENABLE_1_t;

#define NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_1        0xf0010478
#define NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_1_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 dma_fifo_overrunI    :  1 ; /* bits 23:23 */
    cs_uint32 xram_rx_mgmtfifo_overrunI :  1 ; /* bits 22:22 */
    cs_uint32 xram_rx_ptpfifo_overrunI :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_qmfifo_overrunI :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_8_dis_pktI   :  1 ; /* bits 18:18 */
    cs_uint32 xram_rx_7_dis_pktI   :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_6_dis_pktI   :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_5_dis_pktI   :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_4_dis_pktI   :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_3_dis_pktI   :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_2_dis_pktI   :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_1_dis_pktI   :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_0_dis_pktI   :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_8_ptrbkupI   :  1 ; /* bits 8:8 */
    cs_uint32 xram_rx_7_ptrbkupI   :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_6_ptrbkupI   :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_5_ptrbkupI   :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_4_ptrbkupI   :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_3_ptrbkupI   :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_2_ptrbkupI   :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_1_ptrbkupI   :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_0_ptrbkupI   :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_0_ptrbkupI   :  1 ; /* bits 0:0 */
    cs_uint32 xram_rx_1_ptrbkupI   :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_2_ptrbkupI   :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_3_ptrbkupI   :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_4_ptrbkupI   :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_5_ptrbkupI   :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_6_ptrbkupI   :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_7_ptrbkupI   :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_8_ptrbkupI   :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_0_dis_pktI   :  1 ; /* bits 10:10 */
    cs_uint32 xram_rx_1_dis_pktI   :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_2_dis_pktI   :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_3_dis_pktI   :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_4_dis_pktI   :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_5_dis_pktI   :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_6_dis_pktI   :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_7_dis_pktI   :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_8_dis_pktI   :  1 ; /* bits 18:18 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_qmfifo_overrunI :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_ptpfifo_overrunI :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_mgmtfifo_overrunI :  1 ; /* bits 22:22 */
    cs_uint32 dma_fifo_overrunI    :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ERR_INTERRUPT_1_t;

#define NI_TOP_NI_CPUXRAM_ERR_INTENABLE_1        0xf001047c
#define NI_TOP_NI_CPUXRAM_ERR_INTENABLE_1_dft    0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 dma_fifo_overrunIE   :  1 ; /* bits 23:23 */
    cs_uint32 xram_rx_mgmtfifo_overrunIE :  1 ; /* bits 22:22 */
    cs_uint32 xram_rx_ptpfifo_overrunIE :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_qmfifo_overrunIE :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_8_dis_pktIE  :  1 ; /* bits 18:18 */
    cs_uint32 xram_rx_7_dis_pktIE  :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_6_dis_pktIE  :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_5_dis_pktIE  :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_4_dis_pktIE  :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_3_dis_pktIE  :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_2_dis_pktIE  :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_1_dis_pktIE  :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_0_dis_pktIE  :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_8_ptrbkupIE  :  1 ; /* bits 8:8 */
    cs_uint32 xram_rx_7_ptrbkupIE  :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_6_ptrbkupIE  :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_5_ptrbkupIE  :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_4_ptrbkupIE  :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_3_ptrbkupIE  :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_2_ptrbkupIE  :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_1_ptrbkupIE  :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_0_ptrbkupIE  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_0_ptrbkupIE  :  1 ; /* bits 0:0 */
    cs_uint32 xram_rx_1_ptrbkupIE  :  1 ; /* bits 1:1 */
    cs_uint32 xram_rx_2_ptrbkupIE  :  1 ; /* bits 2:2 */
    cs_uint32 xram_rx_3_ptrbkupIE  :  1 ; /* bits 3:3 */
    cs_uint32 xram_rx_4_ptrbkupIE  :  1 ; /* bits 4:4 */
    cs_uint32 xram_rx_5_ptrbkupIE  :  1 ; /* bits 5:5 */
    cs_uint32 xram_rx_6_ptrbkupIE  :  1 ; /* bits 6:6 */
    cs_uint32 xram_rx_7_ptrbkupIE  :  1 ; /* bits 7:7 */
    cs_uint32 xram_rx_8_ptrbkupIE  :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 xram_rx_0_dis_pktIE  :  1 ; /* bits 10:10 */
    cs_uint32 xram_rx_1_dis_pktIE  :  1 ; /* bits 11:11 */
    cs_uint32 xram_rx_2_dis_pktIE  :  1 ; /* bits 12:12 */
    cs_uint32 xram_rx_3_dis_pktIE  :  1 ; /* bits 13:13 */
    cs_uint32 xram_rx_4_dis_pktIE  :  1 ; /* bits 14:14 */
    cs_uint32 xram_rx_5_dis_pktIE  :  1 ; /* bits 15:15 */
    cs_uint32 xram_rx_6_dis_pktIE  :  1 ; /* bits 16:16 */
    cs_uint32 xram_rx_7_dis_pktIE  :  1 ; /* bits 17:17 */
    cs_uint32 xram_rx_8_dis_pktIE  :  1 ; /* bits 18:18 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 xram_rx_qmfifo_overrunIE :  1 ; /* bits 20:20 */
    cs_uint32 xram_rx_ptpfifo_overrunIE :  1 ; /* bits 21:21 */
    cs_uint32 xram_rx_mgmtfifo_overrunIE :  1 ; /* bits 22:22 */
    cs_uint32 dma_fifo_overrunIE   :  1 ; /* bits 23:23 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_ERR_INTENABLE_1_t;

#define NI_TOP_NI_INTERRUPT_1                    0xf0010480
#define NI_TOP_NI_INTERRUPT_1_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 cpuxram_int_stat_err :  1 ; /* bits 14:14 */
    cs_uint32 cpuxram_int_stat_cntr :  1 ; /* bits 13:13 */
    cs_uint32 int_stat_pc2         :  1 ; /* bits 12:12 */
    cs_uint32 int_stat_pc1         :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc0         :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_txem        :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_rxfifo      :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_pspid_7     :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_pspid_6     :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_5     :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_4     :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_3     :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_2     :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_1     :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_0     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_stat_pspid_0     :  1 ; /* bits 0:0 */
    cs_uint32 int_stat_pspid_1     :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_2     :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_3     :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_4     :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_5     :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_6     :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_7     :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_rxfifo      :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_txem        :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_pc0         :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_pc1         :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc2         :  1 ; /* bits 12:12 */
    cs_uint32 cpuxram_int_stat_cntr :  1 ; /* bits 13:13 */
    cs_uint32 cpuxram_int_stat_err :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INTERRUPT_1_t;

#define NI_TOP_NI_INTENABLE_1                    0xf0010484
#define NI_TOP_NI_INTENABLE_1_dft                0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 cpuxram_int_stat_err_en :  1 ; /* bits 14:14 */
    cs_uint32 cpuxram_int_stat_cntr_en :  1 ; /* bits 13:13 */
    cs_uint32 int_stat_pc2_en      :  1 ; /* bits 12:12 */
    cs_uint32 int_stat_pc1_en      :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc0_en      :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_txem_en     :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_rxfifo_en   :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_pspid_7_en  :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_pspid_6_en  :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_5_en  :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_4_en  :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_3_en  :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_2_en  :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_1_en  :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_0_en  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 int_stat_pspid_0_en  :  1 ; /* bits 0:0 */
    cs_uint32 int_stat_pspid_1_en  :  1 ; /* bits 1:1 */
    cs_uint32 int_stat_pspid_2_en  :  1 ; /* bits 2:2 */
    cs_uint32 int_stat_pspid_3_en  :  1 ; /* bits 3:3 */
    cs_uint32 int_stat_pspid_4_en  :  1 ; /* bits 4:4 */
    cs_uint32 int_stat_pspid_5_en  :  1 ; /* bits 5:5 */
    cs_uint32 int_stat_pspid_6_en  :  1 ; /* bits 6:6 */
    cs_uint32 int_stat_pspid_7_en  :  1 ; /* bits 7:7 */
    cs_uint32 int_stat_rxfifo_en   :  1 ; /* bits 8:8 */
    cs_uint32 int_stat_txem_en     :  1 ; /* bits 9:9 */
    cs_uint32 int_stat_pc0_en      :  1 ; /* bits 10:10 */
    cs_uint32 int_stat_pc1_en      :  1 ; /* bits 11:11 */
    cs_uint32 int_stat_pc2_en      :  1 ; /* bits 12:12 */
    cs_uint32 cpuxram_int_stat_cntr_en :  1 ; /* bits 13:13 */
    cs_uint32 cpuxram_int_stat_err_en :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_INTENABLE_1_t;

#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_1    0xf0010488
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_1_STRIDE 8
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_1_COUNT 9
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_1_dft 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 xram_rx_doneI        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_doneI        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_RXPKT_0_INTERRUPT_1_t;

#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_1    0xf001048c
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_1_STRIDE 8
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_1_COUNT 9
#define NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_1_dft 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 xram_rx_doneIE       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_rx_doneIE       :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_RXPKT_0_INTENABLE_1_t;

#define NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_1      0xf00104d0
#define NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_1_dft  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 xram_tx_1_doneI      :  1 ; /* bits 1:1 */
    cs_uint32 xram_tx_0_doneI      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_tx_0_doneI      :  1 ; /* bits 0:0 */
    cs_uint32 xram_tx_1_doneI      :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_TXPKT_INTERRUPT_1_t;

#define NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_1      0xf00104d4
#define NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_1_dft  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 xram_tx_1_doneIE     :  1 ; /* bits 1:1 */
    cs_uint32 xram_tx_0_doneIE     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 xram_tx_0_doneIE     :  1 ; /* bits 0:0 */
    cs_uint32 xram_tx_1_doneIE     :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_CPUXRAM_TXPKT_INTENABLE_1_t;

#define NI_TOP_NI_WOL_STAT_0_INT_1               0xf00104d8
#define NI_TOP_NI_WOL_STAT_0_INT_1_STRIDE        8
#define NI_TOP_NI_WOL_STAT_0_INT_1_COUNT         3
#define NI_TOP_NI_WOL_STAT_0_INT_1_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 ni_wol_int           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ni_wol_int           :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_STAT_0_INT_1_t;

#define NI_TOP_NI_WOL_STAT_0_INTENABLE_1         0xf00104dc
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_1_STRIDE  8
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_1_COUNT   3
#define NI_TOP_NI_WOL_STAT_0_INTENABLE_1_dft     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 ni_wol_intIE         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ni_wol_intIE         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_WOL_STAT_0_INTENABLE_1_t;

#define PER_SOFT_RESET                           0xf0070000
#define PER_SOFT_RESET_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 soft_reset           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 soft_reset           :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SOFT_RESET_t;

#define PER_PERIPHERAL_INTERRUPT_0               0xf0070004
#define PER_PERIPHERAL_INTERRUPT_0_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 trngi                :  1 ; /* bits 14:14 */
    cs_uint32 sspi                 :  1 ; /* bits 13:13 */
    cs_uint32 mdioi                :  1 ; /* bits 12:12 */
    cs_uint32 biwi                 :  1 ; /* bits 11:11 */
    cs_uint32 gpio4i               :  1 ; /* bits 10:10 */
    cs_uint32 gpio3i               :  1 ; /* bits 9:9 */
    cs_uint32 gpio2i               :  1 ; /* bits 8:8 */
    cs_uint32 gpio1i               :  1 ; /* bits 7:7 */
    cs_uint32 gpio0i               :  1 ; /* bits 6:6 */
    cs_uint32 spii                 :  1 ; /* bits 5:5 */
    cs_uint32 axii                 :  1 ; /* bits 4:4 */
    cs_uint32 tmr2i                :  1 ; /* bits 3:3 */
    cs_uint32 tmr1i                :  1 ; /* bits 2:2 */
    cs_uint32 soft1i               :  1 ; /* bits 1:1 */
    cs_uint32 soft0i               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 soft0i               :  1 ; /* bits 0:0 */
    cs_uint32 soft1i               :  1 ; /* bits 1:1 */
    cs_uint32 tmr1i                :  1 ; /* bits 2:2 */
    cs_uint32 tmr2i                :  1 ; /* bits 3:3 */
    cs_uint32 axii                 :  1 ; /* bits 4:4 */
    cs_uint32 spii                 :  1 ; /* bits 5:5 */
    cs_uint32 gpio0i               :  1 ; /* bits 6:6 */
    cs_uint32 gpio1i               :  1 ; /* bits 7:7 */
    cs_uint32 gpio2i               :  1 ; /* bits 8:8 */
    cs_uint32 gpio3i               :  1 ; /* bits 9:9 */
    cs_uint32 gpio4i               :  1 ; /* bits 10:10 */
    cs_uint32 biwi                 :  1 ; /* bits 11:11 */
    cs_uint32 mdioi                :  1 ; /* bits 12:12 */
    cs_uint32 sspi                 :  1 ; /* bits 13:13 */
    cs_uint32 trngi                :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PERIPHERAL_INTERRUPT_0_t;

#define PER_PERIPHERAL_INTENABLE_0               0xf0070008
#define PER_PERIPHERAL_INTENABLE_0_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 trnge                :  1 ; /* bits 14:14 */
    cs_uint32 sspe                 :  1 ; /* bits 13:13 */
    cs_uint32 mdioe                :  1 ; /* bits 12:12 */
    cs_uint32 biwe                 :  1 ; /* bits 11:11 */
    cs_uint32 gpio4e               :  1 ; /* bits 10:10 */
    cs_uint32 gpio3e               :  1 ; /* bits 9:9 */
    cs_uint32 gpio2e               :  1 ; /* bits 8:8 */
    cs_uint32 gpio1e               :  1 ; /* bits 7:7 */
    cs_uint32 gpio0e               :  1 ; /* bits 6:6 */
    cs_uint32 spie                 :  1 ; /* bits 5:5 */
    cs_uint32 axie                 :  1 ; /* bits 4:4 */
    cs_uint32 tmr2e                :  1 ; /* bits 3:3 */
    cs_uint32 tmr1e                :  1 ; /* bits 2:2 */
    cs_uint32 soft1e               :  1 ; /* bits 1:1 */
    cs_uint32 soft0e               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 soft0e               :  1 ; /* bits 0:0 */
    cs_uint32 soft1e               :  1 ; /* bits 1:1 */
    cs_uint32 tmr1e                :  1 ; /* bits 2:2 */
    cs_uint32 tmr2e                :  1 ; /* bits 3:3 */
    cs_uint32 axie                 :  1 ; /* bits 4:4 */
    cs_uint32 spie                 :  1 ; /* bits 5:5 */
    cs_uint32 gpio0e               :  1 ; /* bits 6:6 */
    cs_uint32 gpio1e               :  1 ; /* bits 7:7 */
    cs_uint32 gpio2e               :  1 ; /* bits 8:8 */
    cs_uint32 gpio3e               :  1 ; /* bits 9:9 */
    cs_uint32 gpio4e               :  1 ; /* bits 10:10 */
    cs_uint32 biwe                 :  1 ; /* bits 11:11 */
    cs_uint32 mdioe                :  1 ; /* bits 12:12 */
    cs_uint32 sspe                 :  1 ; /* bits 13:13 */
    cs_uint32 trnge                :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PERIPHERAL_INTENABLE_0_t;

#define PER_PERIPHERAL_INTERRUPT_1               0xf007000c
#define PER_PERIPHERAL_INTERRUPT_1_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 trngi                :  1 ; /* bits 14:14 */
    cs_uint32 sspi                 :  1 ; /* bits 13:13 */
    cs_uint32 mdioi                :  1 ; /* bits 12:12 */
    cs_uint32 biwi                 :  1 ; /* bits 11:11 */
    cs_uint32 gpio4i               :  1 ; /* bits 10:10 */
    cs_uint32 gpio3i               :  1 ; /* bits 9:9 */
    cs_uint32 gpio2i               :  1 ; /* bits 8:8 */
    cs_uint32 gpio1i               :  1 ; /* bits 7:7 */
    cs_uint32 gpio0i               :  1 ; /* bits 6:6 */
    cs_uint32 spii                 :  1 ; /* bits 5:5 */
    cs_uint32 axii                 :  1 ; /* bits 4:4 */
    cs_uint32 tmr2i                :  1 ; /* bits 3:3 */
    cs_uint32 tmr1i                :  1 ; /* bits 2:2 */
    cs_uint32 soft1i               :  1 ; /* bits 1:1 */
    cs_uint32 soft0i               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 soft0i               :  1 ; /* bits 0:0 */
    cs_uint32 soft1i               :  1 ; /* bits 1:1 */
    cs_uint32 tmr1i                :  1 ; /* bits 2:2 */
    cs_uint32 tmr2i                :  1 ; /* bits 3:3 */
    cs_uint32 axii                 :  1 ; /* bits 4:4 */
    cs_uint32 spii                 :  1 ; /* bits 5:5 */
    cs_uint32 gpio0i               :  1 ; /* bits 6:6 */
    cs_uint32 gpio1i               :  1 ; /* bits 7:7 */
    cs_uint32 gpio2i               :  1 ; /* bits 8:8 */
    cs_uint32 gpio3i               :  1 ; /* bits 9:9 */
    cs_uint32 gpio4i               :  1 ; /* bits 10:10 */
    cs_uint32 biwi                 :  1 ; /* bits 11:11 */
    cs_uint32 mdioi                :  1 ; /* bits 12:12 */
    cs_uint32 sspi                 :  1 ; /* bits 13:13 */
    cs_uint32 trngi                :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PERIPHERAL_INTERRUPT_1_t;

#define PER_PERIPHERAL_INTENABLE_1               0xf0070010
#define PER_PERIPHERAL_INTENABLE_1_dft           0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 17 ;
    cs_uint32 trnge                :  1 ; /* bits 14:14 */
    cs_uint32 sspe                 :  1 ; /* bits 13:13 */
    cs_uint32 mdioe                :  1 ; /* bits 12:12 */
    cs_uint32 biwe                 :  1 ; /* bits 11:11 */
    cs_uint32 gpio4e               :  1 ; /* bits 10:10 */
    cs_uint32 gpio3e               :  1 ; /* bits 9:9 */
    cs_uint32 gpio2e               :  1 ; /* bits 8:8 */
    cs_uint32 gpio1e               :  1 ; /* bits 7:7 */
    cs_uint32 gpio0e               :  1 ; /* bits 6:6 */
    cs_uint32 spie                 :  1 ; /* bits 5:5 */
    cs_uint32 axie                 :  1 ; /* bits 4:4 */
    cs_uint32 tmr2e                :  1 ; /* bits 3:3 */
    cs_uint32 tmr1e                :  1 ; /* bits 2:2 */
    cs_uint32 soft1e               :  1 ; /* bits 1:1 */
    cs_uint32 soft0e               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 soft0e               :  1 ; /* bits 0:0 */
    cs_uint32 soft1e               :  1 ; /* bits 1:1 */
    cs_uint32 tmr1e                :  1 ; /* bits 2:2 */
    cs_uint32 tmr2e                :  1 ; /* bits 3:3 */
    cs_uint32 axie                 :  1 ; /* bits 4:4 */
    cs_uint32 spie                 :  1 ; /* bits 5:5 */
    cs_uint32 gpio0e               :  1 ; /* bits 6:6 */
    cs_uint32 gpio1e               :  1 ; /* bits 7:7 */
    cs_uint32 gpio2e               :  1 ; /* bits 8:8 */
    cs_uint32 gpio3e               :  1 ; /* bits 9:9 */
    cs_uint32 gpio4e               :  1 ; /* bits 10:10 */
    cs_uint32 biwe                 :  1 ; /* bits 11:11 */
    cs_uint32 mdioe                :  1 ; /* bits 12:12 */
    cs_uint32 sspe                 :  1 ; /* bits 13:13 */
    cs_uint32 trnge                :  1 ; /* bits 14:14 */
    cs_uint32 rsrvd1               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PERIPHERAL_INTENABLE_1_t;

#define PER_IRQ_SOFT1                            0xf0070014
#define PER_IRQ_SOFT1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 softiSet             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 softiSet             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_IRQ_SOFT1_t;

#define PER_IRQ_SOFT0                            0xf0070018
#define PER_IRQ_SOFT0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 softiSet             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 softiSet             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_IRQ_SOFT0_t;

#define PER_TMR_LD1                              0xf007001c
#define PER_TMR_LD1_dft                          0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 load1                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 load1                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_LD1_t;

#define PER_TMR_CTRL1                            0xf0070020
#define PER_TMR_CTRL1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 24 ;
    cs_uint32 timen1               :  1 ; /* bits 7:7 */
    cs_uint32 rlmode1              :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 clksel1              :  2 ; /* bits 3:2 */
    cs_uint32 rsrvd1               :  2 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 clksel1              :  2 ; /* bits 3:2 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rlmode1              :  1 ; /* bits 6:6 */
    cs_uint32 timen1               :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd3               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_CTRL1_t;

#define     timen1_DIS                                    0x0
#define     timen1_ENA                                    0x1
#define     rlmode1_ROLL                                  0x0
#define     rlmode1_LOAD                                  0x1
#define     clksel1_direct                                0x0
#define     clksel1_dv64                                  0x1
#define     clksel1_dv1024                                0x2
#define     clksel1_dv4096                                0x3

#define PER_TMR_CNT1                             0xf0070024
#define PER_TMR_CNT1_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 count1               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 count1               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_CNT1_t;

#define PER_TMR_IE1_0                            0xf0070028
#define PER_TMR_IE1_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_IE1_0_t;

#define PER_TMR_IE1_1                            0xf007002c
#define PER_TMR_IE1_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_IE1_1_t;

#define PER_TMR_INT1_0                           0xf0070030
#define PER_TMR_INT1_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_INT1_0_t;

#define PER_TMR_INT1_1                           0xf0070034
#define PER_TMR_INT1_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_INT1_1_t;

#define PER_TMR_STAT1                            0xf0070038
#define PER_TMR_STAT1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1s                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1s                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_STAT1_t;

#define PER_TMR_LD2                              0xf007003c
#define PER_TMR_LD2_dft                          0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 load2                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 load2                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_LD2_t;

#define PER_TMR_CTRL2                            0xf0070040
#define PER_TMR_CTRL2_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 24 ;
    cs_uint32 timen2               :  1 ; /* bits 7:7 */
    cs_uint32 rlmode2              :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 clksel2              :  2 ; /* bits 3:2 */
    cs_uint32 rsrvd1               :  2 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 clksel2              :  2 ; /* bits 3:2 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 rlmode2              :  1 ; /* bits 6:6 */
    cs_uint32 timen2               :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd3               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_CTRL2_t;

#define     timen2_DIS                                    0x0
#define     timen2_ENA                                    0x1
#define     rlmode2_ROLL                                  0x0
#define     rlmode2_LOAD                                  0x1
#define     clksel2_direct                                0x0
#define     clksel2_dv64                                  0x1
#define     clksel2_dv1024                                0x2
#define     clksel2_dv4096                                0x3

#define PER_TMR_CNT2                             0xf0070044
#define PER_TMR_CNT2_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 count2               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 count2               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_CNT2_t;

#define PER_TMR_IE2_0                            0xf0070048
#define PER_TMR_IE2_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_IE2_0_t;

#define PER_TMR_IE2_1                            0xf007004c
#define PER_TMR_IE2_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1e                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_IE2_1_t;

#define PER_TMR_INT2_0                           0xf0070050
#define PER_TMR_INT2_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_INT2_0_t;

#define PER_TMR_INT2_1                           0xf0070054
#define PER_TMR_INT2_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr1i                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_INT2_1_t;

#define PER_TMR_STAT2                            0xf0070058
#define PER_TMR_STAT2_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 tmr2s                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tmr2s                :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_STAT2_t;

#define PER_TMR_LOADE                            0xf007005c
#define PER_TMR_LOADE_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 29 ;
    cs_uint32 update_tmr2          :  1 ; /* bits 2:2 */
    cs_uint32 update_tmr1          :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               :  1 ;
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 update_tmr1          :  1 ; /* bits 1:1 */
    cs_uint32 update_tmr2          :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd2               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_LOADE_t;

#define PER_TMR_TST                              0xf0070060
#define PER_TMR_TST_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 27 ;
    cs_uint32 pps_timer2_en        :  1 ; /* bits 4:4 */
    cs_uint32 pps_timer1_en        :  1 ; /* bits 3:3 */
    cs_uint32 test2                :  1 ; /* bits 2:2 */
    cs_uint32 test1                :  1 ; /* bits 1:1 */
    cs_uint32 testclksel           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 testclksel           :  1 ; /* bits 0:0 */
    cs_uint32 test1                :  1 ; /* bits 1:1 */
    cs_uint32 test2                :  1 ; /* bits 2:2 */
    cs_uint32 pps_timer1_en        :  1 ; /* bits 3:3 */
    cs_uint32 pps_timer2_en        :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               : 27 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_TMR_TST_t;

#define PER_SPI_CLK                              0xf0070064
#define PER_SPI_CLK_dft                          0x00000002

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 ssp_igap             :  8 ; /* bits 23:16 */
    cs_uint32 counter_load         : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 counter_load         : 16 ; /* bits 15:0 */
    cs_uint32 ssp_igap             :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CLK_t;

#define PER_SPI_CFG                              0xf0070068
#define PER_SPI_CFG_dft                          0x3f090000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 sspcs_en4_gpio       :  1 ; /* bits 31:31 */
    cs_uint32 sspcs_en3_gpio       :  1 ; /* bits 30:30 */
    cs_uint32 pre_ssp_dat_cnt      :  6 ; /* bits 29:24 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ssp_cmd_cnt          :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 sel_ssp_cs           :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 micro_wire_cs_sel    :  5 ; /* bits 6:2 */
    cs_uint32 read_write           :  1 ; /* bits 1:1 */
    cs_uint32 command_cyc          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 command_cyc          :  1 ; /* bits 0:0 */
    cs_uint32 read_write           :  1 ; /* bits 1:1 */
    cs_uint32 micro_wire_cs_sel    :  5 ; /* bits 6:2 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 sel_ssp_cs           :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ssp_cmd_cnt          :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 pre_ssp_dat_cnt      :  6 ; /* bits 29:24 */
    cs_uint32 sspcs_en3_gpio       :  1 ; /* bits 30:30 */
    cs_uint32 sspcs_en4_gpio       :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CFG_t;

#define     micro_wire_cs_sel_SPI                         0x0
#define     micro_wire_cs_sel_MWR                         0x1
#define     read_write_WR                                 0x0
#define     read_write_RD                                 0x1
#define     command_cyc_NORM                              0x0
#define     command_cyc_CONLY                             0x1

#define PER_SPI_CTRL                             0xf007006c
#define PER_SPI_CTRL_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 sspstart             :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sspdone              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sspdone              :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 sspstart             :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CTRL_t;

#define PER_SPI_CA0                              0xf0070070
#define PER_SPI_CA0_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_cmd_addr0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_cmd_addr0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CA0_t;

#define PER_SPI_CA1                              0xf0070074
#define PER_SPI_CA1_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_cmd_addr1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_cmd_addr1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CA1_t;

#define PER_SPI_CA2                              0xf0070078
#define PER_SPI_CA2_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_cmd_addr2        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_cmd_addr2        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_CA2_t;

#define PER_SPI_WDAT1                            0xf007007c
#define PER_SPI_WDAT1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_wdata1           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_wdata1           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_WDAT1_t;

#define PER_SPI_WDAT0                            0xf0070080
#define PER_SPI_WDAT0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_wdata0           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_wdata0           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_WDAT0_t;

#define PER_SPI_RDAT1                            0xf0070084
#define PER_SPI_RDAT1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_rdata1           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_rdata1           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_RDAT1_t;

#define PER_SPI_RDAT0                            0xf0070088
#define PER_SPI_RDAT0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ssp_rdata0           : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssp_rdata0           : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_RDAT0_t;

#define PER_SPI_IE_0                             0xf007008c
#define PER_SPI_IE_0_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 spie                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 spie                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_IE_0_t;

#define PER_SPI_INT_0                            0xf0070090
#define PER_SPI_INT_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 sspi                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sspi                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_INT_0_t;

#define PER_SPI_IE_1                             0xf0070094
#define PER_SPI_IE_1_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 spie                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 spie                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_IE_1_t;

#define PER_SPI_INT_1                            0xf0070098
#define PER_SPI_INT_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 sspi                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 sspi                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_INT_1_t;

#define PER_SPI_STAT                             0xf007009c
#define PER_SPI_STAT_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 ssps                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ssps                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_STAT_t;

#define PER_MDIO_CFG                             0xf00700a0
#define PER_MDIO_CFG_dft                         0x00000001

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 mdio_pre_scale       : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               : 15 ;
    cs_uint32 mdio_manual          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdio_manual          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 15 ;
    cs_uint32 mdio_pre_scale       : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_CFG_t;

#define     mdio_manual_AUTO                              0x0
#define     mdio_manual_MAN                               0x1

#define PER_MDIO_ADDR                            0xf00700a4
#define PER_MDIO_ADDR_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 16 ;
    cs_uint32 mdio_rd_wr           :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 mdio_offset          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mdio_addr            :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdio_addr            :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mdio_offset          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 mdio_rd_wr           :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd3               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ADDR_t;

#define     mdio_rd_wr_WR                                 0x0
#define     mdio_rd_wr_RD                                 0x1
#define     mdio_addr_NORM                                0x0
#define     mdio_addr_CONLY                               0x1

#define PER_MDIO_WRDATA                          0xf00700a8
#define PER_MDIO_WRDATA_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 mdio_wrdata          : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdio_wrdata          : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_WRDATA_t;

#define PER_MDIO_RDDATA                          0xf00700ac
#define PER_MDIO_RDDATA_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 16 ;
    cs_uint32 mdio_rddata          : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdio_rddata          : 16 ; /* bits 15:0 */
    cs_uint32 rsrvd1               : 16 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_RDDATA_t;

#define PER_MDIO_CTRL                            0xf00700b0
#define PER_MDIO_CTRL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 mdiostart            :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 mdiodone             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdiodone             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 mdiostart            :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_CTRL_t;

#define PER_MDIO_AUTO_CFG                        0xf00700b4
#define PER_MDIO_AUTO_CFG_dft                    0x00001f00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 11 ;
    cs_uint32 auto_mdio_reg_to_read :  5 ; /* bits 20:16 */
    cs_uint32 auto_mdio_gpio       :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 auto_mdio_phy_end_idx :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 auto_mdio_phy_start_idx :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 auto_mdio_phy_start_idx :  6 ; /* bits 5:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 auto_mdio_phy_end_idx :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 auto_mdio_gpio       :  1 ; /* bits 15:15 */
    cs_uint32 auto_mdio_reg_to_read :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               : 11 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_AUTO_CFG_t;

#define     auto_mdio_gpio_32                             0x0
#define     auto_mdio_gpio_64                             0x1

#define PER_MDIO_AUTO_INTV                       0xf00700b8
#define PER_MDIO_AUTO_INTV_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 poll_wait_cycles     : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 poll_wait_cycles     : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_AUTO_INTV_t;

#define PER_MDIO_AUTO_RM                         0xf00700bc
#define PER_MDIO_AUTO_RM_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 auto_mdio_bit_mask   : 16 ; /* bits 31:16 */
    cs_uint32 auto_mdio_bit_invert : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 auto_mdio_bit_invert : 16 ; /* bits 15:0 */
    cs_uint32 auto_mdio_bit_mask   : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_AUTO_RM_t;

#define     auto_mdio_bit_mask_UNMASKED                   0x0
#define     auto_mdio_bit_mask_MASKED                     0x1
#define     auto_mdio_bit_invert_NONINV                   0x0
#define     auto_mdio_bit_invert_INV                      0x1

#define PER_MDIO_AUTO_AADDR                      0xf00700c0
#define PER_MDIO_AUTO_AADDR_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 auto_mdio_rddata     : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               : 10 ;
    cs_uint32 auto_mdio_phy_alert_range :  1 ; /* bits 5:5 */
    cs_uint32 auto_mdio_phy_alert_addr :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 auto_mdio_phy_alert_addr :  5 ; /* bits 4:0 */
    cs_uint32 auto_mdio_phy_alert_range :  1 ; /* bits 5:5 */
    cs_uint32 rsrvd1               : 10 ;
    cs_uint32 auto_mdio_rddata     : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_AUTO_AADDR_t;

#define     auto_mdio_phy_alert_range_low                 0x0
#define     auto_mdio_phy_alert_range_hi                  0x1

#define PER_MDIO_ENTAB0                          0xf00700c4
#define PER_MDIO_ENTAB0_dft                      0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 slot_enable0         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 slot_enable0         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ENTAB0_t;

#define PER_MDIO_ENTAB1                          0xf00700c8
#define PER_MDIO_ENTAB1_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 slot_enable1         : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 slot_enable1         : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ENTAB1_t;

#define PER_MDIO_ITAB0                           0xf00700cc
#define PER_MDIO_ITAB0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i                    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i                    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ITAB0_t;

#define PER_MDIO_ITAB1                           0xf00700d0
#define PER_MDIO_ITAB1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i                    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i                    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ITAB1_t;

#define PER_MDIO_IE_0                            0xf00700d4
#define PER_MDIO_IE_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 autopolle            :  1 ; /* bits 1:1 */
    cs_uint32 mdioe                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdioe                :  1 ; /* bits 0:0 */
    cs_uint32 autopolle            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_IE_0_t;

#define PER_MDIO_INT_0                           0xf00700d8
#define PER_MDIO_INT_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 autopolli            :  1 ; /* bits 1:1 */
    cs_uint32 mdioi                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdioi                :  1 ; /* bits 0:0 */
    cs_uint32 autopolli            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_INT_0_t;

#define PER_MDIO_IE_1                            0xf00700dc
#define PER_MDIO_IE_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 autopolle            :  1 ; /* bits 1:1 */
    cs_uint32 mdioe                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdioe                :  1 ; /* bits 0:0 */
    cs_uint32 autopolle            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_IE_1_t;

#define PER_MDIO_INT_1                           0xf00700e0
#define PER_MDIO_INT_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 autopolli            :  1 ; /* bits 1:1 */
    cs_uint32 mdioi                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdioi                :  1 ; /* bits 0:0 */
    cs_uint32 autopolli            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_INT_1_t;

#define PER_MDIO_STAT                            0xf00700e4
#define PER_MDIO_STAT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 30 ;
    cs_uint32 autopolls            :  1 ; /* bits 1:1 */
    cs_uint32 mdios                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdios                :  1 ; /* bits 0:0 */
    cs_uint32 autopolls            :  1 ; /* bits 1:1 */
    cs_uint32 rsrvd1               : 30 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_STAT_t;

#define PER_BIW_CFG                              0xf00700e8
#define PER_BIW_CFG_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 prer                 : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               : 15 ;
    cs_uint32 core_en              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 core_en              :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 15 ;
    cs_uint32 prer                 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_CFG_t;

#define     core_en_DIS                                   0x0
#define     core_en_ENA                                   0x1

#define PER_BIW_CTRL                             0xf00700ec
#define PER_BIW_CTRL_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 start                :  1 ; /* bits 7:7 */
    cs_uint32 stop                 :  1 ; /* bits 6:6 */
    cs_uint32 read                 :  1 ; /* bits 5:5 */
    cs_uint32 write                :  1 ; /* bits 4:4 */
    cs_uint32 ack_in               :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 biwdone              :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biwdone              :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 ack_in               :  1 ; /* bits 3:3 */
    cs_uint32 write                :  1 ; /* bits 4:4 */
    cs_uint32 read                 :  1 ; /* bits 5:5 */
    cs_uint32 stop                 :  1 ; /* bits 6:6 */
    cs_uint32 start                :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_CTRL_t;

#define PER_BIW_TXR                              0xf00700f0
#define PER_BIW_TXR_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 txr                  :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 txr                  :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_TXR_t;

#define PER_BIW_RXR                              0xf00700f4
#define PER_BIW_RXR_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 rxr                  :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rxr                  :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_RXR_t;

#define PER_BIW_ACK                              0xf00700f8
#define PER_BIW_ACK_dft                          0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 29 ;
    cs_uint32 ack_out              :  1 ; /* bits 2:2 */
    cs_uint32 biw_busy             :  1 ; /* bits 1:1 */
    cs_uint32 al                   :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 al                   :  1 ; /* bits 0:0 */
    cs_uint32 biw_busy             :  1 ; /* bits 1:1 */
    cs_uint32 ack_out              :  1 ; /* bits 2:2 */
    cs_uint32 rsrvd1               : 29 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_ACK_t;

#define     biw_busy_FREE                                 0x0
#define     biw_busy_BUSY                                 0x1
#define     al_OK                                         0x0
#define     al_LOST                                       0x1

#define PER_BIW_IE_0                             0xf00700fc
#define PER_BIW_IE_0_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 biwe                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biwe                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_IE_0_t;

#define PER_BIW_INT_0                            0xf0070100
#define PER_BIW_INT_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 biwi                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biwi                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_INT_0_t;

#define PER_BIW_IE_1                             0xf0070104
#define PER_BIW_IE_1_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 biwe                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biwe                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_IE_1_t;

#define PER_BIW_INT_1                            0xf0070108
#define PER_BIW_INT_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 biwi                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biwi                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_INT_1_t;

#define PER_BIW_STAT                             0xf007010c
#define PER_BIW_STAT_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 biws                 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 biws                 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_BIW_STAT_t;

#define PER_UART0_CFG                            0xf0070110
#define PER_UART0_CFG_dft                        0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_CFG_t;

#define     uart_en_DIS                                   0x0
#define     uart_en_ENA                                   0x1
#define     rx_sm_enable_DIS                              0x0
#define     rx_sm_enable_ENA                              0x1
#define     tx_sm_enable_DIS                              0x0
#define     tx_sm_enable_ENA                              0x1
#define     uart_parity_en_DIS                            0x0
#define     uart_parity_en_ENA                            0x1
#define     even_parity_sel_ODD                           0x0
#define     even_parity_sel_EvEN                          0x1
#define     uart_stop_2bit_1                              0x0
#define     uart_stop_2bit_2                              0x1
#define     char_cnt_5                                    0x0
#define     char_cnt_6                                    0x1
#define     char_cnt_7                                    0x2
#define     char_cnt_8                                    0x3

#define PER_UART0_FC                             0xf0070114
#define PER_UART0_FC_dft                         0x00000588

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_FC_t;

#define     no_rts_ENA                                    0x0
#define     no_rts_DIS                                    0x1
#define     inv_rts_POS                                   0x0
#define     inv_rts_NEG                                   0x1
#define     no_cts_ENA                                    0x0
#define     no_cts_DIS                                    0x1
#define     inv_cts_POS                                   0x0
#define     inv_cts_NEG                                   0x1

#define PER_UART0_RX_SAMPLE                      0xf0070118
#define PER_UART0_RX_SAMPLE_dft                  0x0000000f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_RX_SAMPLE_t;

#define PER_UART0_TUN                            0xf007011c
#define PER_UART0_TUN_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_TUN_t;

#define     tx_tune_add_FASTER                            0x0
#define     tx_tune_add_SLOWER                            0x1
#define     rx_tune_add_FASTER                            0x0
#define     rx_tune_add_SLOWER                            0x1

#define PER_UART0_TXDAT                          0xf0070120
#define PER_UART0_TXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_TXDAT_t;

#define PER_UART0_RXDAT                          0xf0070124
#define PER_UART0_RXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_RXDAT_t;

#define PER_UART0_INFO                           0xf0070128
#define PER_UART0_INFO_dft                       0x0000000a

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_INFO_t;

#define PER_UART0_IE_0                           0xf007012c
#define PER_UART0_IE_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_IE_0_t;

#define PER_UART0_IE_1                           0xf0070130
#define PER_UART0_IE_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_IE_1_t;

#define PER_UART0_INT_0                          0xf0070134
#define PER_UART0_INT_0_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_INT_0_t;

#define PER_UART0_INT_1                          0xf0070138
#define PER_UART0_INT_1_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_INT_1_t;

#define PER_UART0_STAT                           0xf007013c
#define PER_UART0_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART0_STAT_t;

#define PER_UART1_CFG                            0xf0070140
#define PER_UART1_CFG_dft                        0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_CFG_t;

#define PER_UART1_FC                             0xf0070144
#define PER_UART1_FC_dft                         0x00000588

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_FC_t;

#define PER_UART1_RX_SAMPLE                      0xf0070148
#define PER_UART1_RX_SAMPLE_dft                  0x0000000f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_RX_SAMPLE_t;

#define PER_UART1_TUN                            0xf007014c
#define PER_UART1_TUN_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_TUN_t;

#define PER_UART1_TXDAT                          0xf0070150
#define PER_UART1_TXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_TXDAT_t;

#define PER_UART1_RXDAT                          0xf0070154
#define PER_UART1_RXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_RXDAT_t;

#define PER_UART1_INFO                           0xf0070158
#define PER_UART1_INFO_dft                       0x0000000a

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_INFO_t;

#define PER_UART1_IE_0                           0xf007015c
#define PER_UART1_IE_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_IE_0_t;

#define PER_UART1_IE_1                           0xf0070160
#define PER_UART1_IE_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_IE_1_t;

#define PER_UART1_INT_0                          0xf0070164
#define PER_UART1_INT_0_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_INT_0_t;

#define PER_UART1_INT_1                          0xf0070168
#define PER_UART1_INT_1_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_INT_1_t;

#define PER_UART1_STAT                           0xf007016c
#define PER_UART1_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART1_STAT_t;

#define PER_UART2_CFG                            0xf0070170
#define PER_UART2_CFG_dft                        0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_CFG_t;

#define PER_UART2_FC                             0xf0070174
#define PER_UART2_FC_dft                         0x00000588

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_FC_t;

#define PER_UART2_RX_SAMPLE                      0xf0070178
#define PER_UART2_RX_SAMPLE_dft                  0x0000000f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_RX_SAMPLE_t;

#define PER_UART2_TUN                            0xf007017c
#define PER_UART2_TUN_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_TUN_t;

#define PER_UART2_TXDAT                          0xf0070180
#define PER_UART2_TXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_TXDAT_t;

#define PER_UART2_RXDAT                          0xf0070184
#define PER_UART2_RXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_RXDAT_t;

#define PER_UART2_INFO                           0xf0070188
#define PER_UART2_INFO_dft                       0x0000000a

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_INFO_t;

#define PER_UART2_IE_0                           0xf007018c
#define PER_UART2_IE_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_IE_0_t;

#define PER_UART2_IE_1                           0xf0070190
#define PER_UART2_IE_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_IE_1_t;

#define PER_UART2_INT_0                          0xf0070194
#define PER_UART2_INT_0_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_INT_0_t;

#define PER_UART2_INT_1                          0xf0070198
#define PER_UART2_INT_1_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_INT_1_t;

#define PER_UART2_STAT                           0xf007019c
#define PER_UART2_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART2_STAT_t;

#define PER_UART3_CFG                            0xf00701a0
#define PER_UART3_CFG_dft                        0x00000003

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 char_cnt             :  2 ; /* bits 1:0 */
    cs_uint32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    cs_uint32 even_parity_sel      :  1 ; /* bits 3:3 */
    cs_uint32 uart_parity_en       :  1 ; /* bits 4:4 */
    cs_uint32 tx_sm_enable         :  1 ; /* bits 5:5 */
    cs_uint32 rx_sm_enable         :  1 ; /* bits 6:6 */
    cs_uint32 uart_en              :  1 ; /* bits 7:7 */
    cs_uint32 baud_count           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_CFG_t;

#define PER_UART3_FC                             0xf00701a4
#define PER_UART3_FC_dft                         0x00000588

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 21 ;
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_wm                :  6 ; /* bits 5:0 */
    cs_uint32 inv_cts              :  1 ; /* bits 6:6 */
    cs_uint32 no_cts               :  1 ; /* bits 7:7 */
    cs_uint32 cts_reg              :  1 ; /* bits 8:8 */
    cs_uint32 inv_rts              :  1 ; /* bits 9:9 */
    cs_uint32 no_rts               :  1 ; /* bits 10:10 */
    cs_uint32 rsrvd1               : 21 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_FC_t;

#define PER_UART3_RX_SAMPLE                      0xf00701a8
#define PER_UART3_RX_SAMPLE_dft                  0x0000000f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_center            : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_RX_SAMPLE_t;

#define PER_UART3_TUN                            0xf00701ac
#define PER_UART3_TUN_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    cs_uint32 rx_tune_add          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    cs_uint32 tx_tune_add          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_TUN_t;

#define PER_UART3_TXDAT                          0xf00701b0
#define PER_UART3_TXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 24 ;
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_data              :  8 ; /* bits 7:0 */
    cs_uint32 rsrvd1               : 24 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_TXDAT_t;

#define PER_UART3_RXDAT                          0xf00701b4
#define PER_UART3_RXDAT_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 23 ;
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_data_lat          :  8 ; /* bits 7:0 */
    cs_uint32 rx_data_vld          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               : 23 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_RXDAT_t;

#define PER_UART3_INFO                           0xf00701b8
#define PER_UART3_INFO_dft                       0x0000000a

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 rx_fifo_full         :  1 ; /* bits 0:0 */
    cs_uint32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_full         :  1 ; /* bits 2:2 */
    cs_uint32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_INFO_t;

#define PER_UART3_IE_0                           0xf00701bc
#define PER_UART3_IE_0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_IE_0_t;

#define PER_UART3_IE_1                           0xf00701c0
#define PER_UART3_IE_1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erre         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erre       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_IE_1_t;

#define PER_UART3_INT_0                          0xf00701c4
#define PER_UART3_INT_0_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_INT_0_t;

#define PER_UART3_INT_1                          0xf00701c8
#define PER_UART3_INT_1_dft                      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_erri         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_erri       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_INT_1_t;

#define PER_UART3_STAT                           0xf00701cc
#define PER_UART3_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 25 ;
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    cs_uint32 rx_stop_errs         :  1 ; /* bits 1:1 */
    cs_uint32 rx_parity_errs       :  1 ; /* bits 2:2 */
    cs_uint32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    cs_uint32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    cs_uint32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    cs_uint32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    cs_uint32 rsrvd1               : 25 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_UART3_STAT_t;

#define PER_GPIO0_CFG                            0xf00701d0
#define PER_GPIO0_CFG_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_CFG_t;

#define     iopmod_OUT                                    0x0
#define     iopmod_IN                                     0x1

#define PER_GPIO0_OUT                            0xf00701d4
#define PER_GPIO0_OUT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_OUT_t;

#define PER_GPIO0_IN                             0xf00701d8
#define PER_GPIO0_IN_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_IN_t;

#define PER_GPIO0_LVL                            0xf00701dc
#define PER_GPIO0_LVL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_LVL_t;

#define     level_LOW                                     0x0
#define     level_HIGH                                    0x1

#define PER_GPIO0_EDGE                           0xf00701e0
#define PER_GPIO0_EDGE_dft                       0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_EDGE_t;

#define     i_edge_LOW                                    0x0
#define     i_edge_HIGH                                   0x1

#define PER_GPIO0_IE                             0xf00701e4
#define PER_GPIO0_IE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_IE_t;

#define PER_GPIO0_INT                            0xf00701e8
#define PER_GPIO0_INT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_INT_t;

#define PER_GPIO0_STAT                           0xf00701ec
#define PER_GPIO0_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO0_STAT_t;

#define PER_GPIO1_CFG                            0xf00701f0
#define PER_GPIO1_CFG_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_CFG_t;

#define PER_GPIO1_OUT                            0xf00701f4
#define PER_GPIO1_OUT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_OUT_t;

#define PER_GPIO1_IN                             0xf00701f8
#define PER_GPIO1_IN_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_IN_t;

#define PER_GPIO1_LVL                            0xf00701fc
#define PER_GPIO1_LVL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_LVL_t;

#define PER_GPIO1_EDGE                           0xf0070200
#define PER_GPIO1_EDGE_dft                       0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_EDGE_t;

#define PER_GPIO1_IE                             0xf0070204
#define PER_GPIO1_IE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_IE_t;

#define PER_GPIO1_INT                            0xf0070208
#define PER_GPIO1_INT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_INT_t;

#define PER_GPIO1_STAT                           0xf007020c
#define PER_GPIO1_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO1_STAT_t;

#define PER_GPIO2_CFG                            0xf0070210
#define PER_GPIO2_CFG_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_CFG_t;

#define PER_GPIO2_OUT                            0xf0070214
#define PER_GPIO2_OUT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_OUT_t;

#define PER_GPIO2_IN                             0xf0070218
#define PER_GPIO2_IN_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_IN_t;

#define PER_GPIO2_LVL                            0xf007021c
#define PER_GPIO2_LVL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_LVL_t;

#define PER_GPIO2_EDGE                           0xf0070220
#define PER_GPIO2_EDGE_dft                       0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_EDGE_t;

#define PER_GPIO2_IE                             0xf0070224
#define PER_GPIO2_IE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_IE_t;

#define PER_GPIO2_INT                            0xf0070228
#define PER_GPIO2_INT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_INT_t;

#define PER_GPIO2_STAT                           0xf007022c
#define PER_GPIO2_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO2_STAT_t;

#define PER_GPIO3_CFG                            0xf0070230
#define PER_GPIO3_CFG_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_CFG_t;

#define PER_GPIO3_OUT                            0xf0070234
#define PER_GPIO3_OUT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_OUT_t;

#define PER_GPIO3_IN                             0xf0070238
#define PER_GPIO3_IN_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_IN_t;

#define PER_GPIO3_LVL                            0xf007023c
#define PER_GPIO3_LVL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_LVL_t;

#define PER_GPIO3_EDGE                           0xf0070240
#define PER_GPIO3_EDGE_dft                       0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_EDGE_t;

#define PER_GPIO3_IE                             0xf0070244
#define PER_GPIO3_IE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_IE_t;

#define PER_GPIO3_INT                            0xf0070248
#define PER_GPIO3_INT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_INT_t;

#define PER_GPIO3_STAT                           0xf007024c
#define PER_GPIO3_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO3_STAT_t;

#define PER_GPIO4_CFG                            0xf0070250
#define PER_GPIO4_CFG_dft                        0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopmod               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_CFG_t;

#define PER_GPIO4_OUT                            0xf0070254
#define PER_GPIO4_OUT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 dataout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_OUT_t;

#define PER_GPIO4_IN                             0xf0070258
#define PER_GPIO4_IN_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 iopdata              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_IN_t;

#define PER_GPIO4_LVL                            0xf007025c
#define PER_GPIO4_LVL_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 level                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_LVL_t;

#define PER_GPIO4_EDGE                           0xf0070260
#define PER_GPIO4_EDGE_dft                       0xffffffff

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 i_edge               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_EDGE_t;

#define PER_GPIO4_IE                             0xf0070264
#define PER_GPIO4_IE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioe                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_IE_t;

#define PER_GPIO4_INT                            0xf0070268
#define PER_GPIO4_INT_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpioi                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_INT_t;

#define PER_GPIO4_STAT                           0xf007026c
#define PER_GPIO4_STAT_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gpios                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_GPIO4_STAT_t;

#define PER_SPI_MODE                             0xf0070270
#define PER_SPI_MODE_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 cfg                  : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 cfg                  : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPI_MODE_t;

#define PER_AXI_TIMEOUT                          0xf0070274
#define PER_AXI_TIMEOUT_dft                      0x000004e2

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 timeout              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 timeout              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_TIMEOUT_t;

#define PER_AXI_REG_CONFIG                       0xf0070278
#define PER_AXI_REG_CONFIG_dft                   0x00000001

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 post_enable          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 post_enable          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_REG_CONFIG_t;

#define PER_AXI_IE_0                             0xf007027c
#define PER_AXI_IE_0_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 pwstrb_erre          :  1 ; /* bits 3:3 */
    cs_uint32 psize_erre           :  1 ; /* bits 2:2 */
    cs_uint32 pdec_erre            :  1 ; /* bits 1:1 */
    cs_uint32 itoie                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 itoie                :  1 ; /* bits 0:0 */
    cs_uint32 pdec_erre            :  1 ; /* bits 1:1 */
    cs_uint32 psize_erre           :  1 ; /* bits 2:2 */
    cs_uint32 pwstrb_erre          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_IE_0_t;

#define PER_AXI_INT_0                            0xf0070280
#define PER_AXI_INT_0_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 pwstrb_erri          :  1 ; /* bits 3:3 */
    cs_uint32 psize_erri           :  1 ; /* bits 2:2 */
    cs_uint32 pdec_erri            :  1 ; /* bits 1:1 */
    cs_uint32 itoii                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 itoii                :  1 ; /* bits 0:0 */
    cs_uint32 pdec_erri            :  1 ; /* bits 1:1 */
    cs_uint32 psize_erri           :  1 ; /* bits 2:2 */
    cs_uint32 pwstrb_erri          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_INT_0_t;

#define PER_AXI_IE_1                             0xf0070284
#define PER_AXI_IE_1_dft                         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 pwstrb_erre          :  1 ; /* bits 3:3 */
    cs_uint32 psize_erre           :  1 ; /* bits 2:2 */
    cs_uint32 pdec_erre            :  1 ; /* bits 1:1 */
    cs_uint32 itoie                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 itoie                :  1 ; /* bits 0:0 */
    cs_uint32 pdec_erre            :  1 ; /* bits 1:1 */
    cs_uint32 psize_erre           :  1 ; /* bits 2:2 */
    cs_uint32 pwstrb_erre          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_IE_1_t;

#define PER_AXI_INT_1                            0xf0070288
#define PER_AXI_INT_1_dft                        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 28 ;
    cs_uint32 pwstrb_erri          :  1 ; /* bits 3:3 */
    cs_uint32 psize_erri           :  1 ; /* bits 2:2 */
    cs_uint32 pdec_erri            :  1 ; /* bits 1:1 */
    cs_uint32 itoii                :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 itoii                :  1 ; /* bits 0:0 */
    cs_uint32 pdec_erri            :  1 ; /* bits 1:1 */
    cs_uint32 psize_erri           :  1 ; /* bits 2:2 */
    cs_uint32 pwstrb_erri          :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               : 28 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_AXI_INT_1_t;

#define PER_SYS_TIMER1                           0xf007028c
#define PER_SYS_TIMER1_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gtimer1              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gtimer1              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER1_t;

#define PER_SYS_TIMER0                           0xf0070290
#define PER_SYS_TIMER0_dft                       0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 gtimer0              : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gtimer0              : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER0_t;

#define PER_SYS_TIMER_COMPARATOR_CPU_01          0xf0070294
#define PER_SYS_TIMER_COMPARATOR_CPU_01_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 comp1                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 comp1                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_01_t;

#define PER_SYS_TIMER_COMPARATOR_CPU_00          0xf0070298
#define PER_SYS_TIMER_COMPARATOR_CPU_00_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 comp0                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 comp0                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_00_t;

#define PER_SYS_TIMER_AUTOINC_CPU_01             0xf007029c
#define PER_SYS_TIMER_AUTOINC_CPU_01_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 autoinc1             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 autoinc1             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_01_t;

#define PER_SYS_TIMER_AUTOINC_CPU_00             0xf00702a0
#define PER_SYS_TIMER_AUTOINC_CPU_00_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 autoinc0             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 autoinc0             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_00_t;

#define PER_SYS_TIMER_CPU_0_INTENABLE            0xf00702a4
#define PER_SYS_TIMER_CPU_0_INTENABLE_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 systimere            :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 systimere            :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_CPU_0_INTENABLE_t;

#define PER_SYS_TIMER_CPU_0_INTERRUPT            0xf00702a8
#define PER_SYS_TIMER_CPU_0_INTERRUPT_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 systimeri            :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 systimeri            :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_CPU_0_INTERRUPT_t;

#define PER_SYS_TIMER_COMPARATOR_CPU_11          0xf00702ac
#define PER_SYS_TIMER_COMPARATOR_CPU_11_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 comp1                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 comp1                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_11_t;

#define PER_SYS_TIMER_COMPARATOR_CPU_10          0xf00702b0
#define PER_SYS_TIMER_COMPARATOR_CPU_10_dft      0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 comp0                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 comp0                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_10_t;

#define PER_SYS_TIMER_AUTOINC_CPU_11             0xf00702b4
#define PER_SYS_TIMER_AUTOINC_CPU_11_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 autoinc1             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 autoinc1             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_11_t;

#define PER_SYS_TIMER_AUTOINC_CPU_10             0xf00702b8
#define PER_SYS_TIMER_AUTOINC_CPU_10_dft         0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 autoinc0             : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 autoinc0             : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_10_t;

#define PER_SYS_TIMER_CPU_1_INTENABLE            0xf00702bc
#define PER_SYS_TIMER_CPU_1_INTENABLE_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 systimere            :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 systimere            :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_CPU_1_INTENABLE_t;

#define PER_SYS_TIMER_CPU_1_INTERRUPT            0xf00702c0
#define PER_SYS_TIMER_CPU_1_INTERRUPT_dft        0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 31 ;
    cs_uint32 systimeri            :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 systimeri            :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               : 31 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SYS_TIMER_CPU_1_INTERRUPT_t;

#define PER_PWM_TIMER_PERIOD                     0xf00702c4
#define PER_PWM_TIMER_PERIOD_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 period               : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 period               : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PWM_TIMER_PERIOD_t;

#define PER_PWM_TIMER_COMP                       0xf00702c8
#define PER_PWM_TIMER_COMP_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 comp                 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 comp                 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_PWM_TIMER_COMP_t;

#define PER_SPARE                                0xf00702cc
#define PER_SPARE_dft                            0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 spare                : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 spare                : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} PER_SPARE_t;

/*
 * SDRAM
 */

#define SDRAM_DENALI_CTL_000                     0xf0500000
#define SDRAM_DENALI_CTL_000_dft                 0x20410000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 version0             : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 dram_class0          :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 start0               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 start0               :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 dram_class0          :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 version0             : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_000_t;

#define SDRAM_DENALI_CTL_001                     0xf0500004
#define SDRAM_DENALI_CTL_001_dft                 0x00010b0f

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE61           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 MAX_CS_REG1          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 MAX_COL_REG1         :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 MAX_ROW_REG1         :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 MAX_ROW_REG1         :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 MAX_COL_REG1         :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 MAX_CS_REG1          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 OBSOLETE61           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_001_t;

#define SDRAM_DENALI_CTL_010                     0xf0500008
#define SDRAM_DENALI_CTL_010_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TRST_PWRON0          :  8 ; /* bits 31:24 */
    cs_uint32 TINIT0               : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TINIT0               : 24 ; /* bits 23:0 */
    cs_uint32 TRST_PWRON0          :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_010_t;

#define SDRAM_DENALI_CTL_011                     0xf050000c
#define SDRAM_DENALI_CTL_011_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE21           :  8 ; /* bits 31:24 */
    cs_uint32 TRST_PWRON1          : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TRST_PWRON1          : 24 ; /* bits 23:0 */
    cs_uint32 OBSOLETE21           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_011_t;

#define SDRAM_DENALI_CTL_020                     0xf0500010
#define SDRAM_DENALI_CTL_020_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 CKE_INACTIVE0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 CKE_INACTIVE0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_020_t;

#define SDRAM_DENALI_CTL_021                     0xf0500014
#define SDRAM_DENALI_CTL_021_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 WRLAT1               :  5 ; /* bits 28:24 */
    cs_uint32 OBSOLETE31           :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 CASLAT_LIN1          :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 INITAREF1            :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 INITAREF1            :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 CASLAT_LIN1          :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 OBSOLETE31           :  8 ; /* bits 23:16 */
    cs_uint32 WRLAT1               :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_021_t;

#define SDRAM_DENALI_CTL_030                     0xf0500018
#define SDRAM_DENALI_CTL_030_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TRC0                 :  8 ; /* bits 31:24 */
    cs_uint32 TRRD0                :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 TBST_INT_INTERVAL0   :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TCCD0                :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TCCD0                :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TBST_INT_INTERVAL0   :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 TRRD0                :  8 ; /* bits 23:16 */
    cs_uint32 TRC0                 :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_030_t;

#define SDRAM_DENALI_CTL_031                     0xf050001c
#define SDRAM_DENALI_CTL_031_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  4 ;
    cs_uint32 TRTP1                :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 TRP1                 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 TWTR1                :  4 ; /* bits 11:8 */
    cs_uint32 TRAS_MIN1            :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TRAS_MIN1            :  8 ; /* bits 7:0 */
    cs_uint32 TWTR1                :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 TRP1                 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 TRTP1                :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd3               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_031_t;

#define SDRAM_DENALI_CTL_040                     0xf0500020
#define SDRAM_DENALI_CTL_040_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE20           : 16 ; /* bits 31:16 */
    cs_uint32 TMOD0                :  8 ; /* bits 15:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TMRD0                :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TMRD0                :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TMOD0                :  8 ; /* bits 15:8 */
    cs_uint32 OBSOLETE20           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_040_t;

#define SDRAM_DENALI_CTL_041                     0xf0500024
#define SDRAM_DENALI_CTL_041_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 AP1                  :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 TCKESR1              :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 TCKE1                :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 WRITEINTERP1         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WRITEINTERP1         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TCKE1                :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 TCKESR1              :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 AP1                  :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_041_t;

#define SDRAM_DENALI_CTL_050                     0xf0500028
#define SDRAM_DENALI_CTL_050_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 TWR_INT0             :  5 ; /* bits 28:24 */
    cs_uint32 TRCD_INT0            :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 TRAS_LOCKOUT0        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 CONCURRENTAP0        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 CONCURRENTAP0        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TRAS_LOCKOUT0        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 TRCD_INT0            :  8 ; /* bits 23:16 */
    cs_uint32 TWR_INT0             :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_050_t;

#define SDRAM_DENALI_CTL_051                     0xf050002c
#define SDRAM_DENALI_CTL_051_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 NO_CMD_INIT1         :  1 ; /* bits 24:24 */
    cs_uint32 TDLL1                : 16 ; /* bits 23:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TDAL1                :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDAL1                :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TDLL1                : 16 ; /* bits 23:8 */
    cs_uint32 NO_CMD_INIT1         :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_051_t;

#define SDRAM_DENALI_CTL_060                     0xf0500030
#define SDRAM_DENALI_CTL_060_dft                 0x00000002

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TCPD0                : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 TFAW0                :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 BSTLEN0              :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BSTLEN0              :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 TFAW0                :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 TCPD0                : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_060_t;

#define SDRAM_DENALI_CTL_061                     0xf0500034
#define SDRAM_DENALI_CTL_061_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 AUTO_REFRESH_MODE1   :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 AREFRESH1            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 REG_DIMM_ENABLE1     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TRP_AB1              :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TRP_AB1              :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 REG_DIMM_ENABLE1     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 AREFRESH1            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 AUTO_REFRESH_MODE1   :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_061_t;

#define SDRAM_DENALI_CTL_070                     0xf0500038
#define SDRAM_DENALI_CTL_070_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TREF0                :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 TRFC0                : 10 ; /* bits 17:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TREF_ENABLE0         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TREF_ENABLE0         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TRFC0                : 10 ; /* bits 17:8 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 TREF0                :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_070_t;

#define SDRAM_DENALI_CTL_071                     0xf050003c
#define SDRAM_DENALI_CTL_071_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TPDEX1               : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 POWER_DOWN1          :  1 ; /* bits 8:8 */
    cs_uint32 TREF1                :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TREF1                :  8 ; /* bits 7:0 */
    cs_uint32 POWER_DOWN1          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TPDEX1               : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_071_t;

#define SDRAM_DENALI_CTL_080                     0xf0500040
#define SDRAM_DENALI_CTL_080_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TXSR0                : 16 ; /* bits 31:16 */
    cs_uint32 TXPDLL0              : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TXPDLL0              : 16 ; /* bits 15:0 */
    cs_uint32 TXSR0                : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_080_t;

#define SDRAM_DENALI_CTL_081                     0xf0500044
#define SDRAM_DENALI_CTL_081_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 PWRUP_SREFRESH_EXIT1 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 SREFRESH1            :  1 ; /* bits 16:16 */
    cs_uint32 TXSNR1               : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TXSNR1               : 16 ; /* bits 15:0 */
    cs_uint32 SREFRESH1            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 PWRUP_SREFRESH_EXIT1 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_081_t;

#define SDRAM_DENALI_CTL_090                     0xf0500048
#define SDRAM_DENALI_CTL_090_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 MR0_DATA_00          :  8 ; /* bits 31:24 */
    cs_uint32 OBSOLETE20           :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 CKE_DELAY0           :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 ENABLE_QUICK_SREFRESH0 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ENABLE_QUICK_SREFRESH0 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 CKE_DELAY0           :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 OBSOLETE20           :  8 ; /* bits 23:16 */
    cs_uint32 MR0_DATA_00          :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_090_t;

#define SDRAM_DENALI_CTL_091                     0xf050004c
#define SDRAM_DENALI_CTL_091_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE51           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 MR1_DATA_01          : 15 ; /* bits 22:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 MR0_DATA_01          :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 MR0_DATA_01          :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 MR1_DATA_01          : 15 ; /* bits 22:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 OBSOLETE51           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_091_t;

#define SDRAM_DENALI_CTL_100                     0xf0500050
#define SDRAM_DENALI_CTL_100_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 MR3_DATA_00          : 15 ; /* bits 30:16 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 MR2_DATA_00          : 15 ; /* bits 14:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 MR2_DATA_00          : 15 ; /* bits 14:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 MR3_DATA_00          : 15 ; /* bits 30:16 */
    cs_uint32 rsrvd2               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_100_t;

#define SDRAM_DENALI_CTL_101                     0xf0500054
#define SDRAM_DENALI_CTL_101_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 BIST_DATA_CHECK1     :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ADDR_SPACE1          :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 BIST_RESULT1         :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 BIST_GO1             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_GO1             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 BIST_RESULT1         :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 ADDR_SPACE1          :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 BIST_DATA_CHECK1     :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_101_t;

#define SDRAM_DENALI_CTL_110                     0xf0500058
#define SDRAM_DENALI_CTL_110_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_START_ADDRESS0  : 24 ; /* bits 31:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 BIST_ADDR_CHECK0     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_ADDR_CHECK0     :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 BIST_START_ADDRESS0  : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_110_t;

#define SDRAM_DENALI_CTL_111                     0xf050005c
#define SDRAM_DENALI_CTL_111_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE21           : 24 ; /* bits 31:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 BIST_START_ADDRESS1  :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_START_ADDRESS1  :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 OBSOLETE21           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_111_t;

#define SDRAM_DENALI_CTL_120                     0xf0500060
#define SDRAM_DENALI_CTL_120_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_DATA_MASK0      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_DATA_MASK0      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_120_t;

#define SDRAM_DENALI_CTL_121                     0xf0500064
#define SDRAM_DENALI_CTL_121_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_DATA_MASK1      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_DATA_MASK1      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_121_t;

#define SDRAM_DENALI_CTL_130                     0xf0500068
#define SDRAM_DENALI_CTL_130_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 ZQCL0                : 12 ; /* bits 27:16 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQINIT0              : 12 ; /* bits 11:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ZQINIT0              : 12 ; /* bits 11:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQCL0                : 12 ; /* bits 27:16 */
    cs_uint32 rsrvd2               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_130_t;

#define SDRAM_DENALI_CTL_131                     0xf050006c
#define SDRAM_DENALI_CTL_131_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 REFRESH_PER_ZQ1      :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 ZQCS1                : 12 ; /* bits 19:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQ_REQ1              :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ZQ_REQ1              :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQCS1                : 12 ; /* bits 19:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 REFRESH_PER_ZQ1      :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_131_t;

#define SDRAM_DENALI_CTL_140                     0xf0500070
#define SDRAM_DENALI_CTL_140_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  5 ;
    cs_uint32 ADDR_PINS0           :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 EIGHT_BANK_MODE0     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 ZQ_IN_PROGRESS0      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQ_ON_SREF_EXIT0     :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ZQ_ON_SREF_EXIT0     :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQ_IN_PROGRESS0      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 EIGHT_BANK_MODE0     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 ADDR_PINS0           :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd4               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_140_t;

#define SDRAM_DENALI_CTL_141                     0xf0500074
#define SDRAM_DENALI_CTL_141_dft                 0x00000a00

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  5 ;
    cs_uint32 COMMAND_AGE_COUNT1   :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 AGE_COUNT1           :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 APREBIT1             :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 COLUMN_SIZE1         :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 COLUMN_SIZE1         :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 APREBIT1             :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 AGE_COUNT1           :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 COMMAND_AGE_COUNT1   :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd4               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_141_t;

#define SDRAM_DENALI_CTL_150                     0xf0500078
#define SDRAM_DENALI_CTL_150_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 PRIORITY_EN0         :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 PLACEMENT_EN0        :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 BANK_SPLIT_EN0       :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 ADDR_CMP_EN0         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ADDR_CMP_EN0         :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 BANK_SPLIT_EN0       :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 PLACEMENT_EN0        :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 PRIORITY_EN0         :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_150_t;

#define SDRAM_DENALI_CTL_151                     0xf050007c
#define SDRAM_DENALI_CTL_151_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  4 ;
    cs_uint32 BURST_ON_FLY_BIT1    :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 SWAP_PORT_RW_SAME_EN1 :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 SWAP_EN1             :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RW_SAME_EN1          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RW_SAME_EN1          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 SWAP_EN1             :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 SWAP_PORT_RW_SAME_EN1 :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 BURST_ON_FLY_BIT1    :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd4               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_151_t;

#define SDRAM_DENALI_CTL_160                     0xf0500080
#define SDRAM_DENALI_CTL_160_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 RESYNC_DLL0          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 Q_FULLNESS0          :  3 ; /* bits 18:16 */
    cs_uint32 OBSOLETE10           :  8 ; /* bits 15:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 REDUC0               :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 REDUC0               :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 OBSOLETE10           :  8 ; /* bits 15:8 */
    cs_uint32 Q_FULLNESS0          :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 RESYNC_DLL0          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_160_t;

#define SDRAM_DENALI_CTL_161                     0xf0500084
#define SDRAM_DENALI_CTL_161_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 INT_STATUS1          : 22 ; /* bits 29:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RESYNC_DLL_PER_AREF_EN1 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RESYNC_DLL_PER_AREF_EN1 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 INT_STATUS1          : 22 ; /* bits 29:8 */
    cs_uint32 rsrvd2               :  2 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_161_t;

#define SDRAM_DENALI_CTL_170                     0xf0500088
#define SDRAM_DENALI_CTL_170_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 INT_MASK0            : 16 ; /* bits 31:16 */
    cs_uint32 OBSOLETE00           : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OBSOLETE00           : 16 ; /* bits 15:0 */
    cs_uint32 INT_MASK0            : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_170_t;

#define SDRAM_DENALI_CTL_171                     0xf050008c
#define SDRAM_DENALI_CTL_171_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE21           : 24 ; /* bits 31:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 INT_MASK1            :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 INT_MASK1            :  6 ; /* bits 5:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 OBSOLETE21           : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_171_t;

#define SDRAM_DENALI_CTL_180                     0xf0500090
#define SDRAM_DENALI_CTL_180_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 OUT_OF_RANGE_ADDR0   : 31 ; /* bits 30:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OUT_OF_RANGE_ADDR0   : 31 ; /* bits 30:0 */
    cs_uint32 rsrvd1               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_180_t;

#define SDRAM_DENALI_CTL_181                     0xf0500094
#define SDRAM_DENALI_CTL_181_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE31           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 OUT_OF_RANGE_TYPE1   :  6 ; /* bits 13:8 */
    cs_uint32 OUT_OF_RANGE_LENGTH1 :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OUT_OF_RANGE_LENGTH1 :  8 ; /* bits 7:0 */
    cs_uint32 OUT_OF_RANGE_TYPE1   :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 OBSOLETE31           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_181_t;

#define SDRAM_DENALI_CTL_190                     0xf0500098
#define SDRAM_DENALI_CTL_190_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_EXP_DATA0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_EXP_DATA0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_190_t;

#define SDRAM_DENALI_CTL_191                     0xf050009c
#define SDRAM_DENALI_CTL_191_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_EXP_DATA1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_EXP_DATA1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_191_t;

#define SDRAM_DENALI_CTL_200                     0xf05000a0
#define SDRAM_DENALI_CTL_200_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_EXP_DATA0       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_EXP_DATA0       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_200_t;

#define SDRAM_DENALI_CTL_201                     0xf05000a4
#define SDRAM_DENALI_CTL_201_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_EXP_DATA1       : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_EXP_DATA1       : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_201_t;

#define SDRAM_DENALI_CTL_210                     0xf05000a8
#define SDRAM_DENALI_CTL_210_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_FAIL_DATA0      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_FAIL_DATA0      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_210_t;

#define SDRAM_DENALI_CTL_211                     0xf05000ac
#define SDRAM_DENALI_CTL_211_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_FAIL_DATA1      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_FAIL_DATA1      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_211_t;

#define SDRAM_DENALI_CTL_220                     0xf05000b0
#define SDRAM_DENALI_CTL_220_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_FAIL_DATA0      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_FAIL_DATA0      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_220_t;

#define SDRAM_DENALI_CTL_221                     0xf05000b4
#define SDRAM_DENALI_CTL_221_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 BIST_FAIL_DATA1      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_FAIL_DATA1      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_221_t;

#define SDRAM_DENALI_CTL_230                     0xf05000b8
#define SDRAM_DENALI_CTL_230_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 BIST_FAIL_ADDR0      : 31 ; /* bits 30:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 BIST_FAIL_ADDR0      : 31 ; /* bits 30:0 */
    cs_uint32 rsrvd1               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_230_t;

#define SDRAM_DENALI_CTL_231                     0xf05000bc
#define SDRAM_DENALI_CTL_231_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 PORT_CMD_ERROR_ADDR1 : 31 ; /* bits 30:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 PORT_CMD_ERROR_ADDR1 : 31 ; /* bits 30:0 */
    cs_uint32 rsrvd1               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_231_t;

#define SDRAM_DENALI_CTL_240                     0xf05000c0
#define SDRAM_DENALI_CTL_240_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE20           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 PORT_CMD_ERROR_TYPE0 :  2 ; /* bits 9:8 */
    cs_uint32 OBSOLETE00           :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OBSOLETE00           :  8 ; /* bits 7:0 */
    cs_uint32 PORT_CMD_ERROR_TYPE0 :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 OBSOLETE20           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_240_t;

#define SDRAM_DENALI_CTL_241                     0xf05000c4
#define SDRAM_DENALI_CTL_241_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  5 ;
    cs_uint32 R2W_SAMECS_DLY1      :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 R2R_SAMECS_DLY1      :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 ADD_ODT_CLK_W2R_SAMECS1 :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ADD_ODT_CLK_R2W_SAMECS1 :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ADD_ODT_CLK_R2W_SAMECS1 :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ADD_ODT_CLK_W2R_SAMECS1 :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 R2R_SAMECS_DLY1      :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 R2W_SAMECS_DLY1      :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd4               :  5 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_241_t;

#define SDRAM_DENALI_CTL_250                     0xf05000c8
#define SDRAM_DENALI_CTL_250_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 OCD_ADJUST_PUP_CS_00 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 OCD_ADJUST_PDN_CS_00 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 W2W_SAMECS_DLY0      :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 W2R_SAMECS_DLY0      :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 W2R_SAMECS_DLY0      :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 W2W_SAMECS_DLY0      :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 OCD_ADJUST_PDN_CS_00 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 OCD_ADJUST_PUP_CS_00 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_250_t;

#define SDRAM_DENALI_CTL_251                     0xf05000cc
#define SDRAM_DENALI_CTL_251_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 SWLVL_EXIT1          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 SWLVL_START1         :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 SWLVL_LOAD1          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 SW_LEVELING_MODE1    :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 SW_LEVELING_MODE1    :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 SWLVL_LOAD1          :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 SWLVL_START1         :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 SWLVL_EXIT1          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_251_t;

#define SDRAM_DENALI_CTL_260                     0xf05000d0
#define SDRAM_DENALI_CTL_260_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 SWLVL_RESP_10        :  8 ; /* bits 31:24 */
    cs_uint32 SWLVL_RESP_00        :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 LVL_STATUS0          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 SWLVL_OP_DONE0       :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 SWLVL_OP_DONE0       :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 LVL_STATUS0          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 SWLVL_RESP_00        :  8 ; /* bits 23:16 */
    cs_uint32 SWLVL_RESP_10        :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_260_t;

#define SDRAM_DENALI_CTL_261                     0xf05000d4
#define SDRAM_DENALI_CTL_261_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 WRLVL_CS1            :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 WRLVL_REQ1           :  1 ; /* bits 16:16 */
    cs_uint32 SWLVL_RESP_31        :  8 ; /* bits 15:8 */
    cs_uint32 SWLVL_RESP_21        :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 SWLVL_RESP_21        :  8 ; /* bits 7:0 */
    cs_uint32 SWLVL_RESP_31        :  8 ; /* bits 15:8 */
    cs_uint32 WRLVL_REQ1           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 WRLVL_CS1            :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_261_t;

#define SDRAM_DENALI_CTL_270                     0xf05000d8
#define SDRAM_DENALI_CTL_270_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 WRLVL_REFRESH_INTERVAL0 :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 WRLVL_EN0            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 WLMRD0               :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 WLDQSEN0             :  6 ; /* bits 5:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WLDQSEN0             :  6 ; /* bits 5:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 WLMRD0               :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 WRLVL_EN0            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 WRLVL_REFRESH_INTERVAL0 :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_270_t;

#define SDRAM_DENALI_CTL_271                     0xf05000dc
#define SDRAM_DENALI_CTL_271_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 WRLVL_REG_EN1        :  1 ; /* bits 24:24 */
    cs_uint32 OBSOLETE41           : 16 ; /* bits 23:8 */
    cs_uint32 WRLVL_REFRESH_INTERVAL1 :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WRLVL_REFRESH_INTERVAL1 :  8 ; /* bits 7:0 */
    cs_uint32 OBSOLETE41           : 16 ; /* bits 23:8 */
    cs_uint32 WRLVL_REG_EN1        :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_271_t;

#define SDRAM_DENALI_CTL_280                     0xf05000e0
#define SDRAM_DENALI_CTL_280_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 WRLVL_DELAY_10       : 16 ; /* bits 31:16 */
    cs_uint32 WRLVL_DELAY_00       : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WRLVL_DELAY_00       : 16 ; /* bits 15:0 */
    cs_uint32 WRLVL_DELAY_10       : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_280_t;

#define SDRAM_DENALI_CTL_281                     0xf05000e4
#define SDRAM_DENALI_CTL_281_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 WRLVL_DELAY_31       : 16 ; /* bits 31:16 */
    cs_uint32 WRLVL_DELAY_21       : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WRLVL_DELAY_21       : 16 ; /* bits 15:0 */
    cs_uint32 WRLVL_DELAY_31       : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_281_t;

#define SDRAM_DENALI_CTL_290                     0xf05000e8
#define SDRAM_DENALI_CTL_290_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 RDLVL_EDGE0          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 RDLVL_CS0            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_GATE_REQ0      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_REQ0           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_REQ0           :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_GATE_REQ0      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_CS0            :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 RDLVL_EDGE0          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_290_t;

#define SDRAM_DENALI_CTL_291                     0xf05000ec
#define SDRAM_DENALI_CTL_291_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE71           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 RDLVL_GATE_REG_EN1   :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_REG_EN1        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_BEGIN_DELAY_EN1 :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_BEGIN_DELAY_EN1 :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_REG_EN1        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_GATE_REG_EN1   :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 OBSOLETE71           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_291_t;

#define SDRAM_DENALI_CTL_300                     0xf05000f0
#define SDRAM_DENALI_CTL_300_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_END_DELAY_00   : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_BEGIN_DELAY_00 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_BEGIN_DELAY_00 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_END_DELAY_00   : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_300_t;

#define SDRAM_DENALI_CTL_301                     0xf05000f4
#define SDRAM_DENALI_CTL_301_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_OFFSET_DELAY_01 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_MIDPOINT_DELAY_01 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_MIDPOINT_DELAY_01 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_OFFSET_DELAY_01 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_301_t;

#define SDRAM_DENALI_CTL_310                     0xf05000f8
#define SDRAM_DENALI_CTL_310_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_GATE_DELAY_00  :  8 ; /* bits 31:24 */
    cs_uint32 RDLVL_DELAY_00       : 16 ; /* bits 23:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_OFFSET_DIR_00  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_OFFSET_DIR_00  :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_DELAY_00       : 16 ; /* bits 23:8 */
    cs_uint32 RDLVL_GATE_DELAY_00  :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_310_t;

#define SDRAM_DENALI_CTL_311                     0xf05000fc
#define SDRAM_DENALI_CTL_311_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
    cs_uint32 RDLVL_BEGIN_DELAY_11 : 16 ; /* bits 23:8 */
    cs_uint32 RDLVL_GATE_DELAY_01  :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_GATE_DELAY_01  :  8 ; /* bits 7:0 */
    cs_uint32 RDLVL_BEGIN_DELAY_11 : 16 ; /* bits 23:8 */
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_311_t;

#define SDRAM_DENALI_CTL_320                     0xf0500100
#define SDRAM_DENALI_CTL_320_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_MIDPOINT_DELAY_10 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_END_DELAY_10   : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_END_DELAY_10   : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_MIDPOINT_DELAY_10 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_320_t;

#define SDRAM_DENALI_CTL_321                     0xf0500104
#define SDRAM_DENALI_CTL_321_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_OFFSET_DIR_11  :  1 ; /* bits 16:16 */
    cs_uint32 RDLVL_OFFSET_DELAY_11 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_OFFSET_DELAY_11 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_OFFSET_DIR_11  :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_321_t;

#define SDRAM_DENALI_CTL_330                     0xf0500108
#define SDRAM_DENALI_CTL_330_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_GATE_DELAY_10  : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_DELAY_10       : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_DELAY_10       : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_GATE_DELAY_10  : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_330_t;

#define SDRAM_DENALI_CTL_331                     0xf050010c
#define SDRAM_DENALI_CTL_331_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_END_DELAY_21   : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_BEGIN_DELAY_21 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_BEGIN_DELAY_21 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_END_DELAY_21   : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_331_t;

#define SDRAM_DENALI_CTL_340                     0xf0500110
#define SDRAM_DENALI_CTL_340_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_OFFSET_DELAY_20 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_MIDPOINT_DELAY_20 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_MIDPOINT_DELAY_20 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_OFFSET_DELAY_20 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_340_t;

#define SDRAM_DENALI_CTL_341                     0xf0500114
#define SDRAM_DENALI_CTL_341_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
    cs_uint32 RDLVL_DELAY_21       : 16 ; /* bits 23:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_OFFSET_DIR_21  :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_OFFSET_DIR_21  :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_DELAY_21       : 16 ; /* bits 23:8 */
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_341_t;

#define SDRAM_DENALI_CTL_350                     0xf0500118
#define SDRAM_DENALI_CTL_350_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_BEGIN_DELAY_30 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_GATE_DELAY_20  : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_GATE_DELAY_20  : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_BEGIN_DELAY_30 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_350_t;

#define SDRAM_DENALI_CTL_351                     0xf050011c
#define SDRAM_DENALI_CTL_351_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_MIDPOINT_DELAY_31 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_END_DELAY_31   : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_END_DELAY_31   : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_MIDPOINT_DELAY_31 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_351_t;

#define SDRAM_DENALI_CTL_360                     0xf0500120
#define SDRAM_DENALI_CTL_360_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_DELAY_30       :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_OFFSET_DIR_30  :  1 ; /* bits 16:16 */
    cs_uint32 RDLVL_OFFSET_DELAY_30 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_OFFSET_DELAY_30 : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_OFFSET_DIR_30  :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_DELAY_30       :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_360_t;

#define SDRAM_DENALI_CTL_361                     0xf0500124
#define SDRAM_DENALI_CTL_361_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
    cs_uint32 RDLVL_GATE_DELAY_31  : 16 ; /* bits 23:8 */
    cs_uint32 RDLVL_DELAY_31       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_DELAY_31       :  8 ; /* bits 7:0 */
    cs_uint32 RDLVL_GATE_DELAY_31  : 16 ; /* bits 23:8 */
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_361_t;

#define SDRAM_DENALI_CTL_370                     0xf0500128
#define SDRAM_DENALI_CTL_370_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI0_W_PRIORITY0     :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI0_R_PRIORITY0     :  2 ; /* bits 17:16 */
    cs_uint32 AXI0_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI0_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 15:0 */
    cs_uint32 AXI0_R_PRIORITY0     :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI0_W_PRIORITY0     :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd2               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_370_t;

#define SDRAM_DENALI_CTL_371                     0xf050012c
#define SDRAM_DENALI_CTL_371_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI1_R_PRIORITY1     :  2 ; /* bits 25:24 */
    cs_uint32 AXI1_EN_SIZE_LT_WIDTH_INSTR1 : 16 ; /* bits 23:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI0_FIFO_TYPE_REG1  :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI0_FIFO_TYPE_REG1  :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI1_EN_SIZE_LT_WIDTH_INSTR1 : 16 ; /* bits 23:8 */
    cs_uint32 AXI1_R_PRIORITY1     :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd2               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_371_t;

#define SDRAM_DENALI_CTL_380                     0xf0500130
#define SDRAM_DENALI_CTL_380_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 AXI2_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI1_FIFO_TYPE_REG0  :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI1_W_PRIORITY0     :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI1_W_PRIORITY0     :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI1_FIFO_TYPE_REG0  :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI2_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_380_t;

#define SDRAM_DENALI_CTL_381                     0xf0500134
#define SDRAM_DENALI_CTL_381_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE61           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  6 ;
    cs_uint32 AXI2_FIFO_TYPE_REG1  :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI2_W_PRIORITY1     :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI2_R_PRIORITY1     :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI2_R_PRIORITY1     :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI2_W_PRIORITY1     :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI2_FIFO_TYPE_REG1  :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd3               :  6 ;
    cs_uint32 OBSOLETE61           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_381_t;

#define SDRAM_DENALI_CTL_390                     0xf0500138
#define SDRAM_DENALI_CTL_390_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 AXI3_W_PRIORITY0     :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI3_R_PRIORITY0     :  2 ; /* bits 17:16 */
    cs_uint32 AXI3_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI3_EN_SIZE_LT_WIDTH_INSTR0 : 16 ; /* bits 15:0 */
    cs_uint32 AXI3_R_PRIORITY0     :  2 ; /* bits 17:16 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI3_W_PRIORITY0     :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd2               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_390_t;

#define SDRAM_DENALI_CTL_391                     0xf050013c
#define SDRAM_DENALI_CTL_391_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 AXI0_BDW_OVFLOW1     :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 AXI0_BDW1            :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 ARB_CMD_Q_THRESHOLD1 :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 AXI3_FIFO_TYPE_REG1  :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI3_FIFO_TYPE_REG1  :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 ARB_CMD_Q_THRESHOLD1 :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 AXI0_BDW1            :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 AXI0_BDW_OVFLOW1     :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_391_t;

#define SDRAM_DENALI_CTL_400                     0xf0500140
#define SDRAM_DENALI_CTL_400_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 AXI1_CURRENT_BDW0    :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 AXI1_BDW_OVFLOW0     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 AXI1_BDW0            :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 AXI0_CURRENT_BDW0    :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI0_CURRENT_BDW0    :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 AXI1_BDW0            :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 AXI1_BDW_OVFLOW0     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 AXI1_CURRENT_BDW0    :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd4               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_400_t;

#define SDRAM_DENALI_CTL_401                     0xf0500144
#define SDRAM_DENALI_CTL_401_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 AXI3_BDW1            :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 AXI2_CURRENT_BDW1    :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 AXI2_BDW_OVFLOW1     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 AXI2_BDW1            :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI2_BDW1            :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 AXI2_BDW_OVFLOW1     :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 AXI2_CURRENT_BDW1    :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 AXI3_BDW1            :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd4               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_401_t;

#define SDRAM_DENALI_CTL_410                     0xf0500148
#define SDRAM_DENALI_CTL_410_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  7 ;
    cs_uint32 MEM_RST_VALID0       :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 CKE_STATUS0          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 AXI3_CURRENT_BDW0    :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 AXI3_BDW_OVFLOW0     :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 AXI3_BDW_OVFLOW0     :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 AXI3_CURRENT_BDW0    :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 CKE_STATUS0          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 MEM_RST_VALID0       :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd4               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_410_t;

#define SDRAM_DENALI_CTL_411                     0xf050014c
#define SDRAM_DENALI_CTL_411_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 TDFI_PHY_WRLAT1      :  5 ; /* bits 28:24 */
    cs_uint32 DLL_RST_ADJ_DLY1     :  8 ; /* bits 23:16 */
    cs_uint32 DLL_RST_DELAY1       : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DLL_RST_DELAY1       : 16 ; /* bits 15:0 */
    cs_uint32 DLL_RST_ADJ_DLY1     :  8 ; /* bits 23:16 */
    cs_uint32 TDFI_PHY_WRLAT1      :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd1               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_411_t;

#define SDRAM_DENALI_CTL_420                     0xf0500150
#define SDRAM_DENALI_CTL_420_dft                 0x00000600

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE30           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 TDFI_RDDATA_EN0      :  6 ; /* bits 21:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 TDFI_PHY_RDLAT0      :  6 ; /* bits 13:8 */
    cs_uint32 OBSOLETE00           :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OBSOLETE00           :  8 ; /* bits 7:0 */
    cs_uint32 TDFI_PHY_RDLAT0      :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 TDFI_RDDATA_EN0      :  6 ; /* bits 21:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 OBSOLETE30           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_420_t;

#define SDRAM_DENALI_CTL_421                     0xf0500154
#define SDRAM_DENALI_CTL_421_dft                 0x00000400

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_CTRLUPD_MAX1    : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 TDFI_CTRLUPD_MIN1    :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 DRAM_CLK_DISABLE1    :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DRAM_CLK_DISABLE1    :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TDFI_CTRLUPD_MIN1    :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 TDFI_CTRLUPD_MAX1    : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_421_t;

#define SDRAM_DENALI_CTL_430                     0xf0500158
#define SDRAM_DENALI_CTL_430_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_PHYUPD_TYPE10   : 16 ; /* bits 31:16 */
    cs_uint32 TDFI_PHYUPD_TYPE00   : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_PHYUPD_TYPE00   : 16 ; /* bits 15:0 */
    cs_uint32 TDFI_PHYUPD_TYPE10   : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_430_t;

#define SDRAM_DENALI_CTL_431                     0xf050015c
#define SDRAM_DENALI_CTL_431_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_PHYUPD_TYPE31   : 16 ; /* bits 31:16 */
    cs_uint32 TDFI_PHYUPD_TYPE21   : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_PHYUPD_TYPE21   : 16 ; /* bits 15:0 */
    cs_uint32 TDFI_PHYUPD_TYPE31   : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_431_t;

#define SDRAM_DENALI_CTL_440                     0xf0500160
#define SDRAM_DENALI_CTL_440_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 WRLAT_ADJ0           :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 RDLAT_ADJ0           :  6 ; /* bits 21:16 */
    cs_uint32 TDFI_PHYUPD_RESP0    : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_PHYUPD_RESP0    : 16 ; /* bits 15:0 */
    cs_uint32 RDLAT_ADJ0           :  6 ; /* bits 21:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 WRLAT_ADJ0           :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd2               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_440_t;

#define SDRAM_DENALI_CTL_441                     0xf0500164
#define SDRAM_DENALI_CTL_441_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_WRLVL_DLL1      :  8 ; /* bits 31:24 */
    cs_uint32 TDFI_WRLVL_EN1       :  8 ; /* bits 23:16 */
    cs_uint32 DFI_WRLVL_MAX_DELAY1 : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 DFI_WRLVL_MAX_DELAY1 : 16 ; /* bits 15:0 */
    cs_uint32 TDFI_WRLVL_EN1       :  8 ; /* bits 23:16 */
    cs_uint32 TDFI_WRLVL_DLL1      :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_441_t;

#define SDRAM_DENALI_CTL_450                     0xf0500168
#define SDRAM_DENALI_CTL_450_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 TDFI_WRLVL_WW0       : 10 ; /* bits 25:16 */
    cs_uint32 TDFI_WRLVL_RESPLAT0  :  8 ; /* bits 15:8 */
    cs_uint32 TDFI_WRLVL_LOAD0     :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_WRLVL_LOAD0     :  8 ; /* bits 7:0 */
    cs_uint32 TDFI_WRLVL_RESPLAT0  :  8 ; /* bits 15:8 */
    cs_uint32 TDFI_WRLVL_WW0       : 10 ; /* bits 25:16 */
    cs_uint32 rsrvd1               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_450_t;

#define SDRAM_DENALI_CTL_451                     0xf050016c
#define SDRAM_DENALI_CTL_451_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_WRLVL_RESP1     : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_WRLVL_RESP1     : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_451_t;

#define SDRAM_DENALI_CTL_460                     0xf0500170
#define SDRAM_DENALI_CTL_460_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_WRLVL_MAX0      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_WRLVL_MAX0      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_460_t;

#define SDRAM_DENALI_CTL_461                     0xf0500174
#define SDRAM_DENALI_CTL_461_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_GATE_MAX_DELAY1 : 16 ; /* bits 31:16 */
    cs_uint32 RDLVL_MAX_DELAY1     : 16 ; /* bits 15:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_MAX_DELAY1     : 16 ; /* bits 15:0 */
    cs_uint32 RDLVL_GATE_MAX_DELAY1 : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_461_t;

#define SDRAM_DENALI_CTL_470                     0xf0500178
#define SDRAM_DENALI_CTL_470_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_RDLVL_RESPLAT0  :  8 ; /* bits 31:24 */
    cs_uint32 TDFI_RDLVL_LOAD0     :  8 ; /* bits 23:16 */
    cs_uint32 TDFI_RDLVL_DLL0      :  8 ; /* bits 15:8 */
    cs_uint32 TDFI_RDLVL_EN0       :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_RDLVL_EN0       :  8 ; /* bits 7:0 */
    cs_uint32 TDFI_RDLVL_DLL0      :  8 ; /* bits 15:8 */
    cs_uint32 TDFI_RDLVL_LOAD0     :  8 ; /* bits 23:16 */
    cs_uint32 TDFI_RDLVL_RESPLAT0  :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_470_t;

#define SDRAM_DENALI_CTL_471                     0xf050017c
#define SDRAM_DENALI_CTL_471_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE51           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 TDFI_RDLVL_RR1       : 10 ; /* bits 9:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_RDLVL_RR1       : 10 ; /* bits 9:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 OBSOLETE51           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_471_t;

#define SDRAM_DENALI_CTL_480                     0xf0500180
#define SDRAM_DENALI_CTL_480_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_RDLVL_RESP0     : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_RDLVL_RESP0     : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_480_t;

#define SDRAM_DENALI_CTL_481                     0xf0500184
#define SDRAM_DENALI_CTL_481_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_RESP_MASK1     : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_RESP_MASK1     : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_481_t;

#define SDRAM_DENALI_CTL_490                     0xf0500188
#define SDRAM_DENALI_CTL_490_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_GATE_RESP_MASK0 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_GATE_RESP_MASK0 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_490_t;

#define SDRAM_DENALI_CTL_491                     0xf050018c
#define SDRAM_DENALI_CTL_491_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 RDLVL_GATE_PREAMBLE_CHECK_EN1 :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_GATE_EN1       :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_EN1            :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_EN1            :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 RDLVL_GATE_EN1       :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 RDLVL_GATE_PREAMBLE_CHECK_EN1 :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 OBSOLETE41           :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_491_t;

#define SDRAM_DENALI_CTL_500                     0xf0500190
#define SDRAM_DENALI_CTL_500_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_RDLVL_MAX0      : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_RDLVL_MAX0      : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_500_t;

#define SDRAM_DENALI_CTL_501                     0xf0500194
#define SDRAM_DENALI_CTL_501_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE31           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 RDLVL_GATE_DQ_ZERO_COUNT1 :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 RDLVL_DQ_ZERO_COUNT1 :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_DQ_ZERO_COUNT1 :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 RDLVL_GATE_DQ_ZERO_COUNT1 :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd2               :  4 ;
    cs_uint32 OBSOLETE31           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_501_t;

#define SDRAM_DENALI_CTL_510                     0xf0500198
#define SDRAM_DENALI_CTL_510_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 RDLVL_REFRESH_INTERVAL0 :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 RDLVL_ERROR_STATUS0  : 18 ; /* bits 17:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_ERROR_STATUS0  : 18 ; /* bits 17:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 RDLVL_REFRESH_INTERVAL0 :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_510_t;

#define SDRAM_DENALI_CTL_511                     0xf050019c
#define SDRAM_DENALI_CTL_511_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 ODT_ALT_EN1          :  1 ; /* bits 24:24 */
    cs_uint32 RDLVL_GATE_REFRESH_INTERVAL1 : 16 ; /* bits 23:8 */
    cs_uint32 RDLVL_REFRESH_INTERVAL1 :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 RDLVL_REFRESH_INTERVAL1 :  8 ; /* bits 7:0 */
    cs_uint32 RDLVL_GATE_REFRESH_INTERVAL1 : 16 ; /* bits 23:8 */
    cs_uint32 ODT_ALT_EN1          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_511_t;

#define SDRAM_DENALI_CTL_520                     0xf05001a0
#define SDRAM_DENALI_CTL_520_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 SREFRESH_EXIT_NO_REFRESH0 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 TRAS_MAX0            : 17 ; /* bits 16:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TRAS_MAX0            : 17 ; /* bits 16:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 SREFRESH_EXIT_NO_REFRESH0 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_520_t;

#define SDRAM_DENALI_CTL_521                     0xf05001a4
#define SDRAM_DENALI_CTL_521_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 WRITE_MODEREG1       : 26 ; /* bits 25:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 WRITE_MODEREG1       : 26 ; /* bits 25:0 */
    cs_uint32 rsrvd1               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_521_t;

#define SDRAM_DENALI_CTL_530                     0xf05001a8
#define SDRAM_DENALI_CTL_530_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 INHIBIT_DRAM_CMD0    :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 MRSINGLE_DATA_00     : 15 ; /* bits 22:8 */
    cs_uint32 MRW_STATUS0          :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 MRW_STATUS0          :  8 ; /* bits 7:0 */
    cs_uint32 MRSINGLE_DATA_00     : 15 ; /* bits 22:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 INHIBIT_DRAM_CMD0    :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd2               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_530_t;

#define SDRAM_DENALI_CTL_531                     0xf05001ac
#define SDRAM_DENALI_CTL_531_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 UPDATE_ERROR_STATUS1 :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 INT_ACK1             : 21 ; /* bits 20:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 INT_ACK1             : 21 ; /* bits 20:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 UPDATE_ERROR_STATUS1 :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd2               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_531_t;

#define SDRAM_DENALI_CTL_540                     0xf05001b0
#define SDRAM_DENALI_CTL_540_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TDFI_CTRLUPD_INTERVAL0 : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_CTRLUPD_INTERVAL0 : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_540_t;

#define SDRAM_DENALI_CTL_541                     0xf05001b4
#define SDRAM_DENALI_CTL_541_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 PORT_CMD_ERROR_ID1   : 14 ; /* bits 29:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 OUT_OF_RANGE_SOURCE_ID1 : 14 ; /* bits 13:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 OUT_OF_RANGE_SOURCE_ID1 : 14 ; /* bits 13:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 PORT_CMD_ERROR_ID1   : 14 ; /* bits 29:16 */
    cs_uint32 rsrvd2               :  2 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_541_t;

#define SDRAM_DENALI_CTL_550                     0xf05001b8
#define SDRAM_DENALI_CTL_550_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TINIT30              : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 PORT_DATA_ERROR_ID0  : 14 ; /* bits 13:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 PORT_DATA_ERROR_ID0  : 14 ; /* bits 13:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 TINIT30              : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_550_t;

#define SDRAM_DENALI_CTL_551                     0xf05001bc
#define SDRAM_DENALI_CTL_551_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 TINIT41              : 24 ; /* bits 31:8 */
    cs_uint32 TINIT31              :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TINIT31              :  8 ; /* bits 7:0 */
    cs_uint32 TINIT41              : 24 ; /* bits 31:8 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_551_t;

#define SDRAM_DENALI_CTL_560                     0xf05001c0
#define SDRAM_DENALI_CTL_560_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 NO_AUTO_MRR_INIT0    :  1 ; /* bits 24:24 */
    cs_uint32 TINIT50              : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TINIT50              : 24 ; /* bits 23:0 */
    cs_uint32 NO_AUTO_MRR_INIT0    :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_560_t;

#define SDRAM_DENALI_CTL_561                     0xf05001c4
#define SDRAM_DENALI_CTL_561_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE41           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 PWRDN_SHIFT_DELAY1   :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 TMRR1                :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TMRR1                :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 PWRDN_SHIFT_DELAY1   :  6 ; /* bits 13:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 OBSOLETE41           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_561_t;

#define SDRAM_DENALI_CTL_570                     0xf05001c8
#define SDRAM_DENALI_CTL_570_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 PERIPHERAL_MRR_DATA0 :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 READ_MODEREG0        : 17 ; /* bits 16:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 READ_MODEREG0        : 17 ; /* bits 16:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 PERIPHERAL_MRR_DATA0 :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_570_t;

#define SDRAM_DENALI_CTL_571                     0xf05001cc
#define SDRAM_DENALI_CTL_571_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 MR8_DATA_01          :  8 ; /* bits 31:24 */
    cs_uint32 REFRESH_PER_AUTO_TEMPCHK1 :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 AUTO_TEMPCHK_VAL1    :  4 ; /* bits 11:8 */
    cs_uint32 PERIPHERAL_MRR_DATA1 :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 PERIPHERAL_MRR_DATA1 :  8 ; /* bits 7:0 */
    cs_uint32 AUTO_TEMPCHK_VAL1    :  4 ; /* bits 11:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 REFRESH_PER_AUTO_TEMPCHK1 :  8 ; /* bits 23:16 */
    cs_uint32 MR8_DATA_01          :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_571_t;

#define SDRAM_DENALI_CTL_580                     0xf05001d0
#define SDRAM_DENALI_CTL_580_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 ZQRESET0             : 12 ; /* bits 27:16 */
    cs_uint32 MR17_DATA_00         :  8 ; /* bits 15:8 */
    cs_uint32 MR16_DATA_00         :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 MR16_DATA_00         :  8 ; /* bits 7:0 */
    cs_uint32 MR17_DATA_00         :  8 ; /* bits 15:8 */
    cs_uint32 ZQRESET0             : 12 ; /* bits 27:16 */
    cs_uint32 rsrvd1               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_580_t;

#define SDRAM_DENALI_CTL_581                     0xf05001d4
#define SDRAM_DENALI_CTL_581_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  6 ;
    cs_uint32 TDQSCK_MAX1          :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 CONTROLLER_BUSY1     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 LPDDR2_S41           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 NO_ZQ_INIT1          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 NO_ZQ_INIT1          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  7 ;
    cs_uint32 LPDDR2_S41           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 CONTROLLER_BUSY1     :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 TDQSCK_MAX1          :  2 ; /* bits 25:24 */
    cs_uint32 rsrvd4               :  6 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_581_t;

#define SDRAM_DENALI_CTL_590                     0xf05001d8
#define SDRAM_DENALI_CTL_590_dft                 0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  7 ;
    cs_uint32 DISABLE_NARROW_WRAP0 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 WRLVL_ERROR_STATUS0  : 10 ; /* bits 17:8 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 TDQSCK_MIN0          :  2 ; /* bits 1:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDQSCK_MIN0          :  2 ; /* bits 1:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 WRLVL_ERROR_STATUS0  : 10 ; /* bits 17:8 */
    cs_uint32 rsrvd2               :  6 ;
    cs_uint32 DISABLE_NARROW_WRAP0 :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd3               :  7 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_590_t;

#define SDRAM_DENALI_CTL_591                     0xf05001dc
#define SDRAM_DENALI_CTL_591_dft                 0x00000002

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 OBSOLETE51           : 16 ; /* bits 31:16 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 EN_1T_TIMING1        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 TDFI_CTRL_DELAY1     :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 TDFI_CTRL_DELAY1     :  4 ; /* bits 3:0 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 EN_1T_TIMING1        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  7 ;
    cs_uint32 OBSOLETE51           : 16 ; /* bits 31:16 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_DENALI_CTL_591_t;

#define SDRAM_PHY_CTL_64_0                       0xf0500200
#define SDRAM_PHY_CTL_64_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd8               :  3 ;
    cs_uint32 ctrl_HCKE            :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 ctrl_FNC_FB          :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 mode_RUN             :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd5               :  3 ;
    cs_uint32 mode_HIGHZ           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 mode_MUX             :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 mode_NAND            :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 mode_SCAN            :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mode_PHY             :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mode_PHY             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mode_SCAN            :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 mode_NAND            :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 mode_MUX             :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 mode_HIGHZ           :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd5               :  3 ;
    cs_uint32 mode_RUN             :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 ctrl_FNC_FB          :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 ctrl_HCKE            :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd8               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_64_0_t;

#define SDRAM_PHY_CTL_64_1                       0xf0500204
#define SDRAM_PHY_CTL_64_1_dft                   0x00011000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd6               : 11 ;
    cs_uint32 ctrl_CMOSRCV         :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd5               :  3 ;
    cs_uint32 ctrl_SHGATE          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 ctrl_DFDQS           :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_READ_WIDTH      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_DDR3            :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_LPDDR2          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_LPDDR2          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_DDR3            :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_READ_WIDTH      :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_DFDQS           :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 ctrl_SHGATE          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd5               :  3 ;
    cs_uint32 ctrl_CMOSRCV         :  1 ; /* bits 20:20 */
    cs_uint32 rsrvd6               : 11 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_64_1_t;

#define SDRAM_PHY_CTL_65_0                       0xf0500208
#define SDRAM_PHY_CTL_65_0_dft                   0x00000e38

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 20 ;
    cs_uint32 ctrl_DCC             : 12 ; /* bits 11:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_DCC             : 12 ; /* bits 11:0 */
    cs_uint32 rsrvd1               : 20 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_65_0_t;

#define SDRAM_PHY_CTL_65_1                       0xf050020c
#define SDRAM_PHY_CTL_65_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 override_en_DLL_ON   :  1 ; /* bits 31:31 */
    cs_uint32 override_en_START    :  1 ; /* bits 30:30 */
    cs_uint32 override_en_CKSTOP   :  1 ; /* bits 29:29 */
    cs_uint32 override_en_ZQ_START :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd2               : 14 ;
    cs_uint32 gas0_VALIDADJ        :  2 ; /* bits 13:12 */
    cs_uint32 gas0_READADJ         :  4 ; /* bits 11:8 */
    cs_uint32 gas0_GATEADJ         :  4 ; /* bits 7:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 gas0_RD_DISABLE      :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 gas0_RD_DISABLE      :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 gas0_GATEADJ         :  4 ; /* bits 7:4 */
    cs_uint32 gas0_READADJ         :  4 ; /* bits 11:8 */
    cs_uint32 gas0_VALIDADJ        :  2 ; /* bits 13:12 */
    cs_uint32 rsrvd2               : 14 ;
    cs_uint32 override_en_ZQ_START :  1 ; /* bits 28:28 */
    cs_uint32 override_en_CKSTOP   :  1 ; /* bits 29:29 */
    cs_uint32 override_en_START    :  1 ; /* bits 30:30 */
    cs_uint32 override_en_DLL_ON   :  1 ; /* bits 31:31 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_65_1_t;

#define SDRAM_PHY_CTL_66_0                       0xf0500210
#define SDRAM_PHY_CTL_66_0_dft                   0x10108010

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ctrl_INC             :  8 ; /* bits 31:24 */
    cs_uint32 ctrl_START_POINT     :  8 ; /* bits 23:16 */
    cs_uint32 ctrl_REF             :  4 ; /* bits 15:12 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_HALF            :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_DLL_ON          :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_START           :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_START           :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_DLL_ON          :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_HALF            :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_REF             :  4 ; /* bits 15:12 */
    cs_uint32 ctrl_START_POINT     :  8 ; /* bits 23:16 */
    cs_uint32 ctrl_INC             :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_66_0_t;

#define SDRAM_PHY_CTL_66_1                       0xf0500214
#define SDRAM_PHY_CTL_66_1_dft                   0x00000020

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  2 ;
    cs_uint32 ctrl_LOCK_VALUE      : 10 ; /* bits 29:20 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_LOCKED          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_FLOCK           :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_CLOCK           :  1 ; /* bits 8:8 */
    cs_uint32 ctrl_FORCE           :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_FORCE           :  8 ; /* bits 7:0 */
    cs_uint32 ctrl_CLOCK           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_FLOCK           :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_LOCKED          :  1 ; /* bits 16:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_LOCK_VALUE      : 10 ; /* bits 29:20 */
    cs_uint32 rsrvd4               :  2 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_66_1_t;

#define SDRAM_PHY_CTL_67_0                       0xf0500218
#define SDRAM_PHY_CTL_67_0_dft                   0x00000401

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 ctrl_OFFSETD         :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_OFFSETC         :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 ctrl_SHIFTC          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_CKDIS           :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_CKSTOP          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_CKSTOP          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_CKDIS           :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_SHIFTC          :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd3               :  5 ;
    cs_uint32 ctrl_OFFSETC         :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_OFFSETD         :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd5               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_67_0_t;

#define SDRAM_PHY_CTL_67_1                       0xf050021c
#define SDRAM_PHY_CTL_67_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               : 19 ;
    cs_uint32 ctrl_PD              :  5 ; /* bits 12:8 */
    cs_uint32 ctrl_PULLD_DQ        :  4 ; /* bits 7:4 */
    cs_uint32 ctrl_PULLD_DQS       :  4 ; /* bits 3:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_PULLD_DQS       :  4 ; /* bits 3:0 */
    cs_uint32 ctrl_PULLD_DQ        :  4 ; /* bits 7:4 */
    cs_uint32 ctrl_PD              :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               : 19 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_67_1_t;

#define SDRAM_PHY_CTL_68_0                       0xf0500220
#define SDRAM_PHY_CTL_68_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_OFFSETR3        :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_OFFSETR2        :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_OFFSETR1        :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 ctrl_OFFSETR0        :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_OFFSETR0        :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 ctrl_OFFSETR1        :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_OFFSETR2        :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_OFFSETR3        :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd4               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_68_0_t;

#define SDRAM_PHY_CTL_68_1                       0xf0500224
#define SDRAM_PHY_CTL_68_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_OFFSETW3        :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_OFFSETW2        :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_OFFSETW1        :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 ctrl_OFFSETW0        :  7 ; /* bits 6:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_OFFSETW0        :  7 ; /* bits 6:0 */
    cs_uint32 rsrvd1               :  1 ;
    cs_uint32 ctrl_OFFSETW1        :  7 ; /* bits 14:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_OFFSETW2        :  7 ; /* bits 22:16 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_OFFSETW3        :  7 ; /* bits 30:24 */
    cs_uint32 rsrvd4               :  1 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_68_1_t;

#define SDRAM_PHY_CTL_69_0                       0xf0500228
#define SDRAM_PHY_CTL_69_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ctrl_FB_CNT0         :  8 ; /* bits 31:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_FB_OKY          :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_FB_ERR          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_FB_START        :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_FB_START        :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_FB_ERR          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_FB_OKY          :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_FB_CNT0         :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_69_0_t;

#define SDRAM_PHY_CTL_69_1                       0xf050022c
#define SDRAM_PHY_CTL_69_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ctrl_FB_CNT4         :  8 ; /* bits 31:24 */
    cs_uint32 ctrl_FB_CNT3         :  8 ; /* bits 23:16 */
    cs_uint32 ctrl_FB_CNT2         :  8 ; /* bits 15:8 */
    cs_uint32 ctrl_FB_CNT1         :  8 ; /* bits 7:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_FB_CNT1         :  8 ; /* bits 7:0 */
    cs_uint32 ctrl_FB_CNT2         :  8 ; /* bits 15:8 */
    cs_uint32 ctrl_FB_CNT3         :  8 ; /* bits 23:16 */
    cs_uint32 ctrl_FB_CNT4         :  8 ; /* bits 31:24 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_69_1_t;

#define SDRAM_PHY_CTL_70_0                       0xf0500230
#define SDRAM_PHY_CTL_70_0_dft                   0x04252000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd8               :  3 ;
    cs_uint32 ctrl_ZQ_END          :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 ctrl_ZQ_MODE_DDS     :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 ctrl_ZQ_MODE_TERM    :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 ctrl_ZQ_FORCE_IMPN   :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_ZQ_FORCE_IMPP   :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_ZQ_MODE_NOTERM  :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_ZQ_FORCE        :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_ZQ_START        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_ZQ_START        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_ZQ_FORCE        :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_ZQ_MODE_NOTERM  :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_ZQ_FORCE_IMPP   :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd4               :  1 ;
    cs_uint32 ctrl_ZQ_FORCE_IMPN   :  3 ; /* bits 18:16 */
    cs_uint32 rsrvd5               :  1 ;
    cs_uint32 ctrl_ZQ_MODE_TERM    :  3 ; /* bits 22:20 */
    cs_uint32 rsrvd6               :  1 ;
    cs_uint32 ctrl_ZQ_MODE_DDS     :  3 ; /* bits 26:24 */
    cs_uint32 rsrvd7               :  1 ;
    cs_uint32 ctrl_ZQ_END          :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd8               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_70_0_t;

#define SDRAM_PHY_CTL_70_1                       0xf0500234
#define SDRAM_PHY_CTL_70_1_dft                   0x00003000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               : 17 ;
    cs_uint32 ctrl_ZQ_DIV          :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_ZQ_NMON         :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_ZQ_PMON         :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_ZQ_ERROR        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_ZQ_ERROR        :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_ZQ_PMON         :  3 ; /* bits 6:4 */
    cs_uint32 rsrvd2               :  1 ;
    cs_uint32 ctrl_ZQ_NMON         :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd3               :  1 ;
    cs_uint32 ctrl_ZQ_DIV          :  3 ; /* bits 14:12 */
    cs_uint32 rsrvd4               : 17 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_70_1_t;

#define SDRAM_PHY_CTL_71_0                       0xf0500238
#define SDRAM_PHY_CTL_71_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_IO_CAS          :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_IO_RAS          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 ctrl_IO_ADCT         : 22 ; /* bits 21:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_IO_ADCT         : 22 ; /* bits 21:0 */
    cs_uint32 rsrvd1               :  2 ;
    cs_uint32 ctrl_IO_RAS          :  1 ; /* bits 24:24 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_IO_CAS          :  1 ; /* bits 28:28 */
    cs_uint32 rsrvd3               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_71_0_t;

#define SDRAM_PHY_CTL_71_1                       0xf050023c
#define SDRAM_PHY_CTL_71_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd5               :  4 ;
    cs_uint32 ctrl_IO_RDQS         :  4 ; /* bits 27:24 */
    cs_uint32 ctrl_IO_WDQS         :  4 ; /* bits 23:20 */
    cs_uint32 ctrl_IO_DM           :  4 ; /* bits 19:16 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 ctrl_IO_DATA_EN      :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_IO_CK           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_IO_CKE          :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_IO_WEN          :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_IO_WEN          :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 ctrl_IO_CKE          :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 ctrl_IO_CK           :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 ctrl_IO_DATA_EN      :  1 ; /* bits 12:12 */
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 ctrl_IO_DM           :  4 ; /* bits 19:16 */
    cs_uint32 ctrl_IO_WDQS         :  4 ; /* bits 23:20 */
    cs_uint32 ctrl_IO_RDQS         :  4 ; /* bits 27:24 */
    cs_uint32 rsrvd5               :  4 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_71_1_t;

#define SDRAM_PHY_CTL_72_0                       0xf0500240
#define SDRAM_PHY_CTL_72_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ctrl_IO_WDATA        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_IO_WDATA        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_72_0_t;

#define SDRAM_PHY_CTL_72_1                       0xf0500244
#define SDRAM_PHY_CTL_72_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 ctrl_IO_RDATA        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 ctrl_IO_RDATA        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_72_1_t;

#define SDRAM_PHY_CTL_74                         0xf0500250
#define SDRAM_PHY_CTL_74_dft                     0x00a40010

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd5               :  8 ;
    cs_uint32 mon_weight_long_term :  4 ; /* bits 23:20 */
    cs_uint32 mon_weight_short_term :  4 ; /* bits 19:16 */
    cs_uint32 rsrvd4               :  2 ;
    cs_uint32 mon_read_mode        :  2 ; /* bits 13:12 */
    cs_uint32 rsrvd3               :  2 ;
    cs_uint32 mon_group            :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 mon_bl8_size         :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mon_clear_on_read    :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 mon_clear_on_read    :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mon_bl8_size         :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 mon_group            :  2 ; /* bits 9:8 */
    cs_uint32 rsrvd3               :  2 ;
    cs_uint32 mon_read_mode        :  2 ; /* bits 13:12 */
    cs_uint32 rsrvd4               :  2 ;
    cs_uint32 mon_weight_short_term :  4 ; /* bits 19:16 */
    cs_uint32 mon_weight_long_term :  4 ; /* bits 23:20 */
    cs_uint32 rsrvd5               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_74_t;

#define SDRAM_PHY_CTL_75                         0xf0500258
#define SDRAM_PHY_CTL_75_dft                     0x00000f08

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 20 ;
    cs_uint32 nb_axi3_rd_en        :  1 ; /* bits 11:11 */
    cs_uint32 nb_axi2_rd_en        :  1 ; /* bits 10:10 */
    cs_uint32 nb_axi1_rd_en        :  1 ; /* bits 9:9 */
    cs_uint32 nb_axi0_rd_en        :  1 ; /* bits 8:8 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 nb_axi3_wr_en        :  1 ; /* bits 3:3 */
    cs_uint32 nb_axi2_wr_en        :  1 ; /* bits 2:2 */
    cs_uint32 nb_axi1_wr_en        :  1 ; /* bits 1:1 */
    cs_uint32 nb_axi0_wr_en        :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi0_wr_en        :  1 ; /* bits 0:0 */
    cs_uint32 nb_axi1_wr_en        :  1 ; /* bits 1:1 */
    cs_uint32 nb_axi2_wr_en        :  1 ; /* bits 2:2 */
    cs_uint32 nb_axi3_wr_en        :  1 ; /* bits 3:3 */
    cs_uint32 rsrvd1               :  4 ;
    cs_uint32 nb_axi0_rd_en        :  1 ; /* bits 8:8 */
    cs_uint32 nb_axi1_rd_en        :  1 ; /* bits 9:9 */
    cs_uint32 nb_axi2_rd_en        :  1 ; /* bits 10:10 */
    cs_uint32 nb_axi3_rd_en        :  1 ; /* bits 11:11 */
    cs_uint32 rsrvd2               : 20 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_75_t;

#define SDRAM_PHY_CTL_76_0                       0xf0500260
#define SDRAM_PHY_CTL_76_0_dft                   0x08060402

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi0_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi0_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi0_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi0_wr_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi0_wr_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi0_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi0_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi0_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_76_0_t;

#define SDRAM_PHY_CTL_76_1                       0xf0500264
#define SDRAM_PHY_CTL_76_1_dft                   0x06040200

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi0_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi0_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi0_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi0_rd_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi0_rd_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi0_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi0_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi0_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_76_1_t;

#define SDRAM_PHY_CTL_77_0                       0xf0500268
#define SDRAM_PHY_CTL_77_0_dft                   0x08060402

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi1_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi1_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi1_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi1_wr_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi1_wr_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi1_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi1_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi1_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_77_0_t;

#define SDRAM_PHY_CTL_77_1                       0xf050026c
#define SDRAM_PHY_CTL_77_1_dft                   0x06040200

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi1_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi1_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi1_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi1_rd_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi1_rd_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi1_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi1_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi1_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_77_1_t;

#define SDRAM_PHY_CTL_78_0                       0xf0500270
#define SDRAM_PHY_CTL_78_0_dft                   0x08060402

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi2_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi2_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi2_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi2_wr_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi2_wr_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi2_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi2_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi2_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_78_0_t;

#define SDRAM_PHY_CTL_78_1                       0xf0500274
#define SDRAM_PHY_CTL_78_1_dft                   0x06040200

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi2_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi2_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi2_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi2_rd_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi2_rd_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi2_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi2_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi2_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_78_1_t;

#define SDRAM_PHY_CTL_79_0                       0xf0500278
#define SDRAM_PHY_CTL_79_0_dft                   0x08060402

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi3_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi3_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi3_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi3_wr_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi3_wr_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi3_wr_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi3_wr_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi3_wr_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_79_0_t;

#define SDRAM_PHY_CTL_79_1                       0xf050027c
#define SDRAM_PHY_CTL_79_1_dft                   0x06040200

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd4               :  3 ;
    cs_uint32 nb_axi3_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi3_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi3_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi3_rd_threshold0 :  5 ; /* bits 4:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 nb_axi3_rd_threshold0 :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 nb_axi3_rd_threshold1 :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  3 ;
    cs_uint32 nb_axi3_rd_threshold2 :  5 ; /* bits 20:16 */
    cs_uint32 rsrvd3               :  3 ;
    cs_uint32 nb_axi3_rd_threshold3 :  5 ; /* bits 28:24 */
    cs_uint32 rsrvd4               :  3 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_79_1_t;

#define SDRAM_PHY_CTL_80                         0xf0500280
#define SDRAM_PHY_CTL_80_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_80_t;

#define SDRAM_PHY_CTL_81                         0xf0500288
#define SDRAM_PHY_CTL_81_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_81_t;

#define SDRAM_PHY_CTL_82                         0xf0500290
#define SDRAM_PHY_CTL_82_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_82_t;

#define SDRAM_PHY_CTL_83                         0xf0500298
#define SDRAM_PHY_CTL_83_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_83_t;

#define SDRAM_PHY_CTL_84                         0xf05002a0
#define SDRAM_PHY_CTL_84_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_84_t;

#define SDRAM_PHY_CTL_85                         0xf05002a8
#define SDRAM_PHY_CTL_85_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_85_t;

#define SDRAM_PHY_CTL_86                         0xf05002b0
#define SDRAM_PHY_CTL_86_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_86_t;

#define SDRAM_PHY_CTL_87                         0xf05002b8
#define SDRAM_PHY_CTL_87_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_87_t;

#define SDRAM_PHY_CTL_88                         0xf05002c0
#define SDRAM_PHY_CTL_88_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_88_t;

#define SDRAM_PHY_CTL_89                         0xf05002c8
#define SDRAM_PHY_CTL_89_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_89_t;

#define SDRAM_PHY_CTL_90                         0xf05002d0
#define SDRAM_PHY_CTL_90_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_90_t;

#define SDRAM_PHY_CTL_91                         0xf05002d8
#define SDRAM_PHY_CTL_91_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_91_t;

#define SDRAM_PHY_CTL_92                         0xf05002e0
#define SDRAM_PHY_CTL_92_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_92_t;

#define SDRAM_PHY_CTL_93                         0xf05002e8
#define SDRAM_PHY_CTL_93_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_93_t;

#define SDRAM_PHY_CTL_94                         0xf05002f0
#define SDRAM_PHY_CTL_94_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_94_t;

#define SDRAM_PHY_CTL_95                         0xf05002f8
#define SDRAM_PHY_CTL_95_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 axi_mon_read_data    : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_95_t;

#define SDRAM_PHY_CTL_96                         0xf0500300
#define SDRAM_PHY_CTL_96_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               :  8 ;
    cs_uint32 train_rlat           :  4 ; /* bits 23:20 */
    cs_uint32 train_wlat           :  4 ; /* bits 19:16 */
    cs_uint32 rsrvd1               : 11 ;
    cs_uint32 train_rd_mode        :  1 ; /* bits 4:4 */
    cs_uint32 train_clr_buf        :  1 ; /* bits 3:3 */
    cs_uint32 train_mrr_mpr_en     :  1 ; /* bits 2:2 */
    cs_uint32 train_capture_en     :  1 ; /* bits 1:1 */
    cs_uint32 train_dfi_en         :  1 ; /* bits 0:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_dfi_en         :  1 ; /* bits 0:0 */
    cs_uint32 train_capture_en     :  1 ; /* bits 1:1 */
    cs_uint32 train_mrr_mpr_en     :  1 ; /* bits 2:2 */
    cs_uint32 train_clr_buf        :  1 ; /* bits 3:3 */
    cs_uint32 train_rd_mode        :  1 ; /* bits 4:4 */
    cs_uint32 rsrvd1               : 11 ;
    cs_uint32 train_wlat           :  4 ; /* bits 19:16 */
    cs_uint32 train_rlat           :  4 ; /* bits 23:20 */
    cs_uint32 rsrvd2               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_96_t;

#define SDRAM_PHY_CTL_97_0                       0xf0500308
#define SDRAM_PHY_CTL_97_0_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               :  8 ;
    cs_uint32 train_data_mask      :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 train_bank_addr      :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 train_cmd            :  3 ; /* bits 2:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_cmd            :  3 ; /* bits 2:0 */
    cs_uint32 rsrvd1               :  5 ;
    cs_uint32 train_bank_addr      :  3 ; /* bits 10:8 */
    cs_uint32 rsrvd2               :  5 ;
    cs_uint32 train_data_mask      :  8 ; /* bits 23:16 */
    cs_uint32 rsrvd3               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_97_0_t;

#define SDRAM_PHY_CTL_97_1                       0xf050030c
#define SDRAM_PHY_CTL_97_1_dft                   0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd1               :  8 ;
    cs_uint32 train_addr           : 24 ; /* bits 23:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_addr           : 24 ; /* bits 23:0 */
    cs_uint32 rsrvd1               :  8 ;
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_97_1_t;

#define SDRAM_PHY_CTL_98                         0xf0500310
#define SDRAM_PHY_CTL_98_dft                     0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_cmd            : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_cmd            : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_98_t;

#define SDRAM_PHY_CTL_100_0                      0xf0500320
#define SDRAM_PHY_CTL_100_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data0_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data0_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_100_0_t;

#define SDRAM_PHY_CTL_100_1                      0xf0500324
#define SDRAM_PHY_CTL_100_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data0_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data0_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_100_1_t;

#define SDRAM_PHY_CTL_101_0                      0xf0500328
#define SDRAM_PHY_CTL_101_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data1_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data1_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_101_0_t;

#define SDRAM_PHY_CTL_101_1                      0xf050032c
#define SDRAM_PHY_CTL_101_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data1_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data1_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_101_1_t;

#define SDRAM_PHY_CTL_102_0                      0xf0500330
#define SDRAM_PHY_CTL_102_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data2_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data2_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_102_0_t;

#define SDRAM_PHY_CTL_102_1                      0xf0500334
#define SDRAM_PHY_CTL_102_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data2_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data2_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_102_1_t;

#define SDRAM_PHY_CTL_103_0                      0xf0500338
#define SDRAM_PHY_CTL_103_0_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data3_0        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data3_0        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_103_0_t;

#define SDRAM_PHY_CTL_103_1                      0xf050033c
#define SDRAM_PHY_CTL_103_1_dft                  0x00000000

typedef volatile union {
  struct {
#   ifdef CS_BIG_ENDIAN
    cs_uint32 train_data3_1        : 32 ; /* bits 31:0 */
#   else /* CS_LITTLE_ENDIAN */
    cs_uint32 train_data3_1        : 32 ; /* bits 31:0 */
#   endif
  } bf ;
  cs_uint32     wrd ;
} SDRAM_PHY_CTL_103_1_t;

/******************************************************************
 *
 * Block declaration
 *
 ******************************************************************/

/* SDRAM */

typedef struct {
  SDRAM_DENALI_CTL_000_t                   DENALI_CTL_000;                /* addr: 0x00000000 */
  cs_uint32                                rsrvd1[3];
  SDRAM_DENALI_CTL_001_t                   DENALI_CTL_001;                /* addr: 0x00000004 */
  cs_uint32                                rsrvd2[3];
  SDRAM_DENALI_CTL_010_t                   DENALI_CTL_010;                /* addr: 0x00000008 */
  cs_uint32                                rsrvd3[3];
  SDRAM_DENALI_CTL_011_t                   DENALI_CTL_011;                /* addr: 0x0000000c */
  cs_uint32                                rsrvd4[3];
  SDRAM_DENALI_CTL_020_t                   DENALI_CTL_020;                /* addr: 0x00000010 */
  cs_uint32                                rsrvd5[3];
  SDRAM_DENALI_CTL_021_t                   DENALI_CTL_021;                /* addr: 0x00000014 */
  cs_uint32                                rsrvd6[3];
  SDRAM_DENALI_CTL_030_t                   DENALI_CTL_030;                /* addr: 0x00000018 */
  cs_uint32                                rsrvd7[3];
  SDRAM_DENALI_CTL_031_t                   DENALI_CTL_031;                /* addr: 0x0000001c */
  cs_uint32                                rsrvd8[3];
  SDRAM_DENALI_CTL_040_t                   DENALI_CTL_040;                /* addr: 0x00000020 */
  cs_uint32                                rsrvd9[3];
  SDRAM_DENALI_CTL_041_t                   DENALI_CTL_041;                /* addr: 0x00000024 */
  cs_uint32                                rsrvd10[3];
  SDRAM_DENALI_CTL_050_t                   DENALI_CTL_050;                /* addr: 0x00000028 */
  cs_uint32                                rsrvd11[3];
  SDRAM_DENALI_CTL_051_t                   DENALI_CTL_051;                /* addr: 0x0000002c */
  cs_uint32                                rsrvd12[3];
  SDRAM_DENALI_CTL_060_t                   DENALI_CTL_060;                /* addr: 0x00000030 */
  cs_uint32                                rsrvd13[3];
  SDRAM_DENALI_CTL_061_t                   DENALI_CTL_061;                /* addr: 0x00000034 */
  cs_uint32                                rsrvd14[3];
  SDRAM_DENALI_CTL_070_t                   DENALI_CTL_070;                /* addr: 0x00000038 */
  cs_uint32                                rsrvd15[3];
  SDRAM_DENALI_CTL_071_t                   DENALI_CTL_071;                /* addr: 0x0000003c */
  cs_uint32                                rsrvd16[3];
  SDRAM_DENALI_CTL_080_t                   DENALI_CTL_080;                /* addr: 0x00000040 */
  cs_uint32                                rsrvd17[3];
  SDRAM_DENALI_CTL_081_t                   DENALI_CTL_081;                /* addr: 0x00000044 */
  cs_uint32                                rsrvd18[3];
  SDRAM_DENALI_CTL_090_t                   DENALI_CTL_090;                /* addr: 0x00000048 */
  cs_uint32                                rsrvd19[3];
  SDRAM_DENALI_CTL_091_t                   DENALI_CTL_091;                /* addr: 0x0000004c */
  cs_uint32                                rsrvd20[3];
  SDRAM_DENALI_CTL_100_t                   DENALI_CTL_100;                /* addr: 0x00000050 */
  cs_uint32                                rsrvd21[3];
  SDRAM_DENALI_CTL_101_t                   DENALI_CTL_101;                /* addr: 0x00000054 */
  cs_uint32                                rsrvd22[3];
  SDRAM_DENALI_CTL_110_t                   DENALI_CTL_110;                /* addr: 0x00000058 */
  cs_uint32                                rsrvd23[3];
  SDRAM_DENALI_CTL_111_t                   DENALI_CTL_111;                /* addr: 0x0000005c */
  cs_uint32                                rsrvd24[3];
  SDRAM_DENALI_CTL_120_t                   DENALI_CTL_120;                /* addr: 0x00000060 */
  cs_uint32                                rsrvd25[3];
  SDRAM_DENALI_CTL_121_t                   DENALI_CTL_121;                /* addr: 0x00000064 */
  cs_uint32                                rsrvd26[3];
  SDRAM_DENALI_CTL_130_t                   DENALI_CTL_130;                /* addr: 0x00000068 */
  cs_uint32                                rsrvd27[3];
  SDRAM_DENALI_CTL_131_t                   DENALI_CTL_131;                /* addr: 0x0000006c */
  cs_uint32                                rsrvd28[3];
  SDRAM_DENALI_CTL_140_t                   DENALI_CTL_140;                /* addr: 0x00000070 */
  cs_uint32                                rsrvd29[3];
  SDRAM_DENALI_CTL_141_t                   DENALI_CTL_141;                /* addr: 0x00000074 */
  cs_uint32                                rsrvd30[3];
  SDRAM_DENALI_CTL_150_t                   DENALI_CTL_150;                /* addr: 0x00000078 */
  cs_uint32                                rsrvd31[3];
  SDRAM_DENALI_CTL_151_t                   DENALI_CTL_151;                /* addr: 0x0000007c */
  cs_uint32                                rsrvd32[3];
  SDRAM_DENALI_CTL_160_t                   DENALI_CTL_160;                /* addr: 0x00000080 */
  cs_uint32                                rsrvd33[3];
  SDRAM_DENALI_CTL_161_t                   DENALI_CTL_161;                /* addr: 0x00000084 */
  cs_uint32                                rsrvd34[3];
  SDRAM_DENALI_CTL_170_t                   DENALI_CTL_170;                /* addr: 0x00000088 */
  cs_uint32                                rsrvd35[3];
  SDRAM_DENALI_CTL_171_t                   DENALI_CTL_171;                /* addr: 0x0000008c */
  cs_uint32                                rsrvd36[3];
  SDRAM_DENALI_CTL_180_t                   DENALI_CTL_180;                /* addr: 0x00000090 */
  cs_uint32                                rsrvd37[3];
  SDRAM_DENALI_CTL_181_t                   DENALI_CTL_181;                /* addr: 0x00000094 */
  cs_uint32                                rsrvd38[3];
  SDRAM_DENALI_CTL_190_t                   DENALI_CTL_190;                /* addr: 0x00000098 */
  cs_uint32                                rsrvd39[3];
  SDRAM_DENALI_CTL_191_t                   DENALI_CTL_191;                /* addr: 0x0000009c */
  cs_uint32                                rsrvd40[3];
  SDRAM_DENALI_CTL_200_t                   DENALI_CTL_200;                /* addr: 0x000000a0 */
  cs_uint32                                rsrvd41[3];
  SDRAM_DENALI_CTL_201_t                   DENALI_CTL_201;                /* addr: 0x000000a4 */
  cs_uint32                                rsrvd42[3];
  SDRAM_DENALI_CTL_210_t                   DENALI_CTL_210;                /* addr: 0x000000a8 */
  cs_uint32                                rsrvd43[3];
  SDRAM_DENALI_CTL_211_t                   DENALI_CTL_211;                /* addr: 0x000000ac */
  cs_uint32                                rsrvd44[3];
  SDRAM_DENALI_CTL_220_t                   DENALI_CTL_220;                /* addr: 0x000000b0 */
  cs_uint32                                rsrvd45[3];
  SDRAM_DENALI_CTL_221_t                   DENALI_CTL_221;                /* addr: 0x000000b4 */
  cs_uint32                                rsrvd46[3];
  SDRAM_DENALI_CTL_230_t                   DENALI_CTL_230;                /* addr: 0x000000b8 */
  cs_uint32                                rsrvd47[3];
  SDRAM_DENALI_CTL_231_t                   DENALI_CTL_231;                /* addr: 0x000000bc */
  cs_uint32                                rsrvd48[3];
  SDRAM_DENALI_CTL_240_t                   DENALI_CTL_240;                /* addr: 0x000000c0 */
  cs_uint32                                rsrvd49[3];
  SDRAM_DENALI_CTL_241_t                   DENALI_CTL_241;                /* addr: 0x000000c4 */
  cs_uint32                                rsrvd50[3];
  SDRAM_DENALI_CTL_250_t                   DENALI_CTL_250;                /* addr: 0x000000c8 */
  cs_uint32                                rsrvd51[3];
  SDRAM_DENALI_CTL_251_t                   DENALI_CTL_251;                /* addr: 0x000000cc */
  cs_uint32                                rsrvd52[3];
  SDRAM_DENALI_CTL_260_t                   DENALI_CTL_260;                /* addr: 0x000000d0 */
  cs_uint32                                rsrvd53[3];
  SDRAM_DENALI_CTL_261_t                   DENALI_CTL_261;                /* addr: 0x000000d4 */
  cs_uint32                                rsrvd54[3];
  SDRAM_DENALI_CTL_270_t                   DENALI_CTL_270;                /* addr: 0x000000d8 */
  cs_uint32                                rsrvd55[3];
  SDRAM_DENALI_CTL_271_t                   DENALI_CTL_271;                /* addr: 0x000000dc */
  cs_uint32                                rsrvd56[3];
  SDRAM_DENALI_CTL_280_t                   DENALI_CTL_280;                /* addr: 0x000000e0 */
  cs_uint32                                rsrvd57[3];
  SDRAM_DENALI_CTL_281_t                   DENALI_CTL_281;                /* addr: 0x000000e4 */
  cs_uint32                                rsrvd58[3];
  SDRAM_DENALI_CTL_290_t                   DENALI_CTL_290;                /* addr: 0x000000e8 */
  cs_uint32                                rsrvd59[3];
  SDRAM_DENALI_CTL_291_t                   DENALI_CTL_291;                /* addr: 0x000000ec */
  cs_uint32                                rsrvd60[3];
  SDRAM_DENALI_CTL_300_t                   DENALI_CTL_300;                /* addr: 0x000000f0 */
  cs_uint32                                rsrvd61[3];
  SDRAM_DENALI_CTL_301_t                   DENALI_CTL_301;                /* addr: 0x000000f4 */
  cs_uint32                                rsrvd62[3];
  SDRAM_DENALI_CTL_310_t                   DENALI_CTL_310;                /* addr: 0x000000f8 */
  cs_uint32                                rsrvd63[3];
  SDRAM_DENALI_CTL_311_t                   DENALI_CTL_311;                /* addr: 0x000000fc */
  cs_uint32                                rsrvd64[3];
  SDRAM_DENALI_CTL_320_t                   DENALI_CTL_320;                /* addr: 0x00000100 */
  cs_uint32                                rsrvd65[3];
  SDRAM_DENALI_CTL_321_t                   DENALI_CTL_321;                /* addr: 0x00000104 */
  cs_uint32                                rsrvd66[3];
  SDRAM_DENALI_CTL_330_t                   DENALI_CTL_330;                /* addr: 0x00000108 */
  cs_uint32                                rsrvd67[3];
  SDRAM_DENALI_CTL_331_t                   DENALI_CTL_331;                /* addr: 0x0000010c */
  cs_uint32                                rsrvd68[3];
  SDRAM_DENALI_CTL_340_t                   DENALI_CTL_340;                /* addr: 0x00000110 */
  cs_uint32                                rsrvd69[3];
  SDRAM_DENALI_CTL_341_t                   DENALI_CTL_341;                /* addr: 0x00000114 */
  cs_uint32                                rsrvd70[3];
  SDRAM_DENALI_CTL_350_t                   DENALI_CTL_350;                /* addr: 0x00000118 */
  cs_uint32                                rsrvd71[3];
  SDRAM_DENALI_CTL_351_t                   DENALI_CTL_351;                /* addr: 0x0000011c */
  cs_uint32                                rsrvd72[3];
  SDRAM_DENALI_CTL_360_t                   DENALI_CTL_360;                /* addr: 0x00000120 */
  cs_uint32                                rsrvd73[3];
  SDRAM_DENALI_CTL_361_t                   DENALI_CTL_361;                /* addr: 0x00000124 */
  cs_uint32                                rsrvd74[3];
  SDRAM_DENALI_CTL_370_t                   DENALI_CTL_370;                /* addr: 0x00000128 */
  cs_uint32                                rsrvd75[3];
  SDRAM_DENALI_CTL_371_t                   DENALI_CTL_371;                /* addr: 0x0000012c */
  cs_uint32                                rsrvd76[3];
  SDRAM_DENALI_CTL_380_t                   DENALI_CTL_380;                /* addr: 0x00000130 */
  cs_uint32                                rsrvd77[3];
  SDRAM_DENALI_CTL_381_t                   DENALI_CTL_381;                /* addr: 0x00000134 */
  cs_uint32                                rsrvd78[3];
  SDRAM_DENALI_CTL_390_t                   DENALI_CTL_390;                /* addr: 0x00000138 */
  cs_uint32                                rsrvd79[3];
  SDRAM_DENALI_CTL_391_t                   DENALI_CTL_391;                /* addr: 0x0000013c */
  cs_uint32                                rsrvd80[3];
  SDRAM_DENALI_CTL_400_t                   DENALI_CTL_400;                /* addr: 0x00000140 */
  cs_uint32                                rsrvd81[3];
  SDRAM_DENALI_CTL_401_t                   DENALI_CTL_401;                /* addr: 0x00000144 */
  cs_uint32                                rsrvd82[3];
  SDRAM_DENALI_CTL_410_t                   DENALI_CTL_410;                /* addr: 0x00000148 */
  cs_uint32                                rsrvd83[3];
  SDRAM_DENALI_CTL_411_t                   DENALI_CTL_411;                /* addr: 0x0000014c */
  cs_uint32                                rsrvd84[3];
  SDRAM_DENALI_CTL_420_t                   DENALI_CTL_420;                /* addr: 0x00000150 */
  cs_uint32                                rsrvd85[3];
  SDRAM_DENALI_CTL_421_t                   DENALI_CTL_421;                /* addr: 0x00000154 */
  cs_uint32                                rsrvd86[3];
  SDRAM_DENALI_CTL_430_t                   DENALI_CTL_430;                /* addr: 0x00000158 */
  cs_uint32                                rsrvd87[3];
  SDRAM_DENALI_CTL_431_t                   DENALI_CTL_431;                /* addr: 0x0000015c */
  cs_uint32                                rsrvd88[3];
  SDRAM_DENALI_CTL_440_t                   DENALI_CTL_440;                /* addr: 0x00000160 */
  cs_uint32                                rsrvd89[3];
  SDRAM_DENALI_CTL_441_t                   DENALI_CTL_441;                /* addr: 0x00000164 */
  cs_uint32                                rsrvd90[3];
  SDRAM_DENALI_CTL_450_t                   DENALI_CTL_450;                /* addr: 0x00000168 */
  cs_uint32                                rsrvd91[3];
  SDRAM_DENALI_CTL_451_t                   DENALI_CTL_451;                /* addr: 0x0000016c */
  cs_uint32                                rsrvd92[3];
  SDRAM_DENALI_CTL_460_t                   DENALI_CTL_460;                /* addr: 0x00000170 */
  cs_uint32                                rsrvd93[3];
  SDRAM_DENALI_CTL_461_t                   DENALI_CTL_461;                /* addr: 0x00000174 */
  cs_uint32                                rsrvd94[3];
  SDRAM_DENALI_CTL_470_t                   DENALI_CTL_470;                /* addr: 0x00000178 */
  cs_uint32                                rsrvd95[3];
  SDRAM_DENALI_CTL_471_t                   DENALI_CTL_471;                /* addr: 0x0000017c */
  cs_uint32                                rsrvd96[3];
  SDRAM_DENALI_CTL_480_t                   DENALI_CTL_480;                /* addr: 0x00000180 */
  cs_uint32                                rsrvd97[3];
  SDRAM_DENALI_CTL_481_t                   DENALI_CTL_481;                /* addr: 0x00000184 */
  cs_uint32                                rsrvd98[3];
  SDRAM_DENALI_CTL_490_t                   DENALI_CTL_490;                /* addr: 0x00000188 */
  cs_uint32                                rsrvd99[3];
  SDRAM_DENALI_CTL_491_t                   DENALI_CTL_491;                /* addr: 0x0000018c */
  cs_uint32                                rsrvd100[3];
  SDRAM_DENALI_CTL_500_t                   DENALI_CTL_500;                /* addr: 0x00000190 */
  cs_uint32                                rsrvd101[3];
  SDRAM_DENALI_CTL_501_t                   DENALI_CTL_501;                /* addr: 0x00000194 */
  cs_uint32                                rsrvd102[3];
  SDRAM_DENALI_CTL_510_t                   DENALI_CTL_510;                /* addr: 0x00000198 */
  cs_uint32                                rsrvd103[3];
  SDRAM_DENALI_CTL_511_t                   DENALI_CTL_511;                /* addr: 0x0000019c */
  cs_uint32                                rsrvd104[3];
  SDRAM_DENALI_CTL_520_t                   DENALI_CTL_520;                /* addr: 0x000001a0 */
  cs_uint32                                rsrvd105[3];
  SDRAM_DENALI_CTL_521_t                   DENALI_CTL_521;                /* addr: 0x000001a4 */
  cs_uint32                                rsrvd106[3];
  SDRAM_DENALI_CTL_530_t                   DENALI_CTL_530;                /* addr: 0x000001a8 */
  cs_uint32                                rsrvd107[3];
  SDRAM_DENALI_CTL_531_t                   DENALI_CTL_531;                /* addr: 0x000001ac */
  cs_uint32                                rsrvd108[3];
  SDRAM_DENALI_CTL_540_t                   DENALI_CTL_540;                /* addr: 0x000001b0 */
  cs_uint32                                rsrvd109[3];
  SDRAM_DENALI_CTL_541_t                   DENALI_CTL_541;                /* addr: 0x000001b4 */
  cs_uint32                                rsrvd110[3];
  SDRAM_DENALI_CTL_550_t                   DENALI_CTL_550;                /* addr: 0x000001b8 */
  cs_uint32                                rsrvd111[3];
  SDRAM_DENALI_CTL_551_t                   DENALI_CTL_551;                /* addr: 0x000001bc */
  cs_uint32                                rsrvd112[3];
  SDRAM_DENALI_CTL_560_t                   DENALI_CTL_560;                /* addr: 0x000001c0 */
  cs_uint32                                rsrvd113[3];
  SDRAM_DENALI_CTL_561_t                   DENALI_CTL_561;                /* addr: 0x000001c4 */
  cs_uint32                                rsrvd114[3];
  SDRAM_DENALI_CTL_570_t                   DENALI_CTL_570;                /* addr: 0x000001c8 */
  cs_uint32                                rsrvd115[3];
  SDRAM_DENALI_CTL_571_t                   DENALI_CTL_571;                /* addr: 0x000001cc */
  cs_uint32                                rsrvd116[3];
  SDRAM_DENALI_CTL_580_t                   DENALI_CTL_580;                /* addr: 0x000001d0 */
  cs_uint32                                rsrvd117[3];
  SDRAM_DENALI_CTL_581_t                   DENALI_CTL_581;                /* addr: 0x000001d4 */
  cs_uint32                                rsrvd118[3];
  SDRAM_DENALI_CTL_590_t                   DENALI_CTL_590;                /* addr: 0x000001d8 */
  cs_uint32                                rsrvd119[3];
  SDRAM_DENALI_CTL_591_t                   DENALI_CTL_591;                /* addr: 0x000001dc */
  cs_uint32                                rsrvd120[35];
  SDRAM_PHY_CTL_64_0_t                     PHY_CTL_64_0;                  /* addr: 0x00000200 */
  cs_uint32                                rsrvd121[3];
  SDRAM_PHY_CTL_64_1_t                     PHY_CTL_64_1;                  /* addr: 0x00000204 */
  cs_uint32                                rsrvd122[3];
  SDRAM_PHY_CTL_65_0_t                     PHY_CTL_65_0;                  /* addr: 0x00000208 */
  cs_uint32                                rsrvd123[3];
  SDRAM_PHY_CTL_65_1_t                     PHY_CTL_65_1;                  /* addr: 0x0000020c */
  cs_uint32                                rsrvd124[3];
  SDRAM_PHY_CTL_66_0_t                     PHY_CTL_66_0;                  /* addr: 0x00000210 */
  cs_uint32                                rsrvd125[3];
  SDRAM_PHY_CTL_66_1_t                     PHY_CTL_66_1;                  /* addr: 0x00000214 */
  cs_uint32                                rsrvd126[3];
  SDRAM_PHY_CTL_67_0_t                     PHY_CTL_67_0;                  /* addr: 0x00000218 */
  cs_uint32                                rsrvd127[3];
  SDRAM_PHY_CTL_67_1_t                     PHY_CTL_67_1;                  /* addr: 0x0000021c */
  cs_uint32                                rsrvd128[3];
  SDRAM_PHY_CTL_68_0_t                     PHY_CTL_68_0;                  /* addr: 0x00000220 */
  cs_uint32                                rsrvd129[3];
  SDRAM_PHY_CTL_68_1_t                     PHY_CTL_68_1;                  /* addr: 0x00000224 */
  cs_uint32                                rsrvd130[3];
  SDRAM_PHY_CTL_69_0_t                     PHY_CTL_69_0;                  /* addr: 0x00000228 */
  cs_uint32                                rsrvd131[3];
  SDRAM_PHY_CTL_69_1_t                     PHY_CTL_69_1;                  /* addr: 0x0000022c */
  cs_uint32                                rsrvd132[3];
  SDRAM_PHY_CTL_70_0_t                     PHY_CTL_70_0;                  /* addr: 0x00000230 */
  cs_uint32                                rsrvd133[3];
  SDRAM_PHY_CTL_70_1_t                     PHY_CTL_70_1;                  /* addr: 0x00000234 */
  cs_uint32                                rsrvd134[3];
  SDRAM_PHY_CTL_71_0_t                     PHY_CTL_71_0;                  /* addr: 0x00000238 */
  cs_uint32                                rsrvd135[3];
  SDRAM_PHY_CTL_71_1_t                     PHY_CTL_71_1;                  /* addr: 0x0000023c */
  cs_uint32                                rsrvd136[3];
  SDRAM_PHY_CTL_72_0_t                     PHY_CTL_72_0;                  /* addr: 0x00000240 */
  cs_uint32                                rsrvd137[3];
  SDRAM_PHY_CTL_72_1_t                     PHY_CTL_72_1;                  /* addr: 0x00000244 */
  cs_uint32                                rsrvd138[11];
  SDRAM_PHY_CTL_74_t                       PHY_CTL_74;                    /* addr: 0x00000250 */
  cs_uint32                                rsrvd139[7];
  SDRAM_PHY_CTL_75_t                       PHY_CTL_75;                    /* addr: 0x00000258 */
  cs_uint32                                rsrvd140[7];
  SDRAM_PHY_CTL_76_0_t                     PHY_CTL_76_0;                  /* addr: 0x00000260 */
  cs_uint32                                rsrvd141[3];
  SDRAM_PHY_CTL_76_1_t                     PHY_CTL_76_1;                  /* addr: 0x00000264 */
  cs_uint32                                rsrvd142[3];
  SDRAM_PHY_CTL_77_0_t                     PHY_CTL_77_0;                  /* addr: 0x00000268 */
  cs_uint32                                rsrvd143[3];
  SDRAM_PHY_CTL_77_1_t                     PHY_CTL_77_1;                  /* addr: 0x0000026c */
  cs_uint32                                rsrvd144[3];
  SDRAM_PHY_CTL_78_0_t                     PHY_CTL_78_0;                  /* addr: 0x00000270 */
  cs_uint32                                rsrvd145[3];
  SDRAM_PHY_CTL_78_1_t                     PHY_CTL_78_1;                  /* addr: 0x00000274 */
  cs_uint32                                rsrvd146[3];
  SDRAM_PHY_CTL_79_0_t                     PHY_CTL_79_0;                  /* addr: 0x00000278 */
  cs_uint32                                rsrvd147[3];
  SDRAM_PHY_CTL_79_1_t                     PHY_CTL_79_1;                  /* addr: 0x0000027c */
  cs_uint32                                rsrvd148[3];
  SDRAM_PHY_CTL_80_t                       PHY_CTL_80;                    /* addr: 0x00000280 */
  cs_uint32                                rsrvd149[7];
  SDRAM_PHY_CTL_81_t                       PHY_CTL_81;                    /* addr: 0x00000288 */
  cs_uint32                                rsrvd150[7];
  SDRAM_PHY_CTL_82_t                       PHY_CTL_82;                    /* addr: 0x00000290 */
  cs_uint32                                rsrvd151[7];
  SDRAM_PHY_CTL_83_t                       PHY_CTL_83;                    /* addr: 0x00000298 */
  cs_uint32                                rsrvd152[7];
  SDRAM_PHY_CTL_84_t                       PHY_CTL_84;                    /* addr: 0x000002a0 */
  cs_uint32                                rsrvd153[7];
  SDRAM_PHY_CTL_85_t                       PHY_CTL_85;                    /* addr: 0x000002a8 */
  cs_uint32                                rsrvd154[7];
  SDRAM_PHY_CTL_86_t                       PHY_CTL_86;                    /* addr: 0x000002b0 */
  cs_uint32                                rsrvd155[7];
  SDRAM_PHY_CTL_87_t                       PHY_CTL_87;                    /* addr: 0x000002b8 */
  cs_uint32                                rsrvd156[7];
  SDRAM_PHY_CTL_88_t                       PHY_CTL_88;                    /* addr: 0x000002c0 */
  cs_uint32                                rsrvd157[7];
  SDRAM_PHY_CTL_89_t                       PHY_CTL_89;                    /* addr: 0x000002c8 */
  cs_uint32                                rsrvd158[7];
  SDRAM_PHY_CTL_90_t                       PHY_CTL_90;                    /* addr: 0x000002d0 */
  cs_uint32                                rsrvd159[7];
  SDRAM_PHY_CTL_91_t                       PHY_CTL_91;                    /* addr: 0x000002d8 */
  cs_uint32                                rsrvd160[7];
  SDRAM_PHY_CTL_92_t                       PHY_CTL_92;                    /* addr: 0x000002e0 */
  cs_uint32                                rsrvd161[7];
  SDRAM_PHY_CTL_93_t                       PHY_CTL_93;                    /* addr: 0x000002e8 */
  cs_uint32                                rsrvd162[7];
  SDRAM_PHY_CTL_94_t                       PHY_CTL_94;                    /* addr: 0x000002f0 */
  cs_uint32                                rsrvd163[7];
  SDRAM_PHY_CTL_95_t                       PHY_CTL_95;                    /* addr: 0x000002f8 */
  cs_uint32                                rsrvd164[7];
  SDRAM_PHY_CTL_96_t                       PHY_CTL_96;                    /* addr: 0x00000300 */
  cs_uint32                                rsrvd165[7];
  SDRAM_PHY_CTL_97_0_t                     PHY_CTL_97_0;                  /* addr: 0x00000308 */
  cs_uint32                                rsrvd166[3];
  SDRAM_PHY_CTL_97_1_t                     PHY_CTL_97_1;                  /* addr: 0x0000030c */
  cs_uint32                                rsrvd167[3];
  SDRAM_PHY_CTL_98_t                       PHY_CTL_98;                    /* addr: 0x00000310 */
  cs_uint32                                rsrvd168[15];
  SDRAM_PHY_CTL_100_0_t                    PHY_CTL_100_0;                 /* addr: 0x00000320 */
  cs_uint32                                rsrvd169[3];
  SDRAM_PHY_CTL_100_1_t                    PHY_CTL_100_1;                 /* addr: 0x00000324 */
  cs_uint32                                rsrvd170[3];
  SDRAM_PHY_CTL_101_0_t                    PHY_CTL_101_0;                 /* addr: 0x00000328 */
  cs_uint32                                rsrvd171[3];
  SDRAM_PHY_CTL_101_1_t                    PHY_CTL_101_1;                 /* addr: 0x0000032c */
  cs_uint32                                rsrvd172[3];
  SDRAM_PHY_CTL_102_0_t                    PHY_CTL_102_0;                 /* addr: 0x00000330 */
  cs_uint32                                rsrvd173[3];
  SDRAM_PHY_CTL_102_1_t                    PHY_CTL_102_1;                 /* addr: 0x00000334 */
  cs_uint32                                rsrvd174[3];
  SDRAM_PHY_CTL_103_0_t                    PHY_CTL_103_0;                 /* addr: 0x00000338 */
  cs_uint32                                rsrvd175[3];
  SDRAM_PHY_CTL_103_1_t                    PHY_CTL_103_1;                 /* addr: 0x0000033c */
} SDRAM_t;

#endif
