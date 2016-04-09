#include <linux/list.h>		/* list_head structure */
#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/if_vlan.h>
#include <linux/ip.h>
#include <linux/jiffies.h>

#include <mach/cs_types.h>
#include "cs_core_logic.h"
#include "cs_hw_accel_manager.h"
#include "cs_fe_mc.h"
#include "cs_core_hmu.h"
#include "cs_core_vtable.h"
#include "cs752x_eth.h"
#include "cs_wfo_csme.h"
#include <mach/cs75xx_pni.h>
#include <mach/cs75xx_ipc_wfo.h>


#ifdef CONFIG_CS752X_PROC
#include "cs752x_proc.h"
extern u32 cs_acp_enable;
extern u32 cs_adapt_debug;
extern u32 cs_ni_fastbridge;
#define DBG(x)	if (cs_adapt_debug & CS752X_ADAPT_WIRELESS) x

#else
#define DBG(x)	{}
#endif /* CONFIG_CS752X_PROC */
#define CS752X_NODE_WIRELESS_POP_VLAN			"wireless_tx_pop_vlan"
#define CS752X_NODE_CP_VLAN_PRIO_TO_DSCP        "cp_vlan_pri_to_dscp"
u32 cs_wireless_tx_pop_vlan = 1;
u32 cs_cp_vlan_pri_to_dscp = 1;
extern struct proc_dir_entry *proc_driver_cs752x_ne;

enum CS_WIRELESS_MEM_STATUS {
	CS_WIRELESS_FREE		= 0,
	CS_WIRELESS_ALLOCATED
};

#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
#define CS_HW_ACCEL_WIRELESS_INTERFACE_MAX 16
#else
#define CS_HW_ACCEL_WIRELESS_INTERFACE_MAX 4
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS  
#define CS_WIRELESS_MAX_PRIO 4
#define CS_DSCP_MASK 0xfc
#define CS_DSCP_SHIFT 2
#define CS_ETHER_TYPE_LEN 2
#define CS_IPH_DSCP_OFFSET 1

#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
#define CS_WIRELESS_ACCEL_VOQ_TABLE_ENTRY_SIZE     256
typedef struct cs_wireless_accel_voq_mapping_s {	
//    u8 vap;
    u8 used;    // 0: NOT use, 1: used
    u8 vap;
    u8 mac_org[2];
} cs_wireless_accel_voq_mapping_t;
cs_wireless_accel_voq_mapping_t cs_wireless_voq_entry[CS_WIRELESS_ACCEL_VOQ_TABLE_ENTRY_SIZE];
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS  



typedef struct cs_wireless_interface_s {	
	u16  status;
	struct net_device *dev;
	int (*cb_start_xmit)(struct sk_buff *skb, struct net_device *dev);
	int (*cb_prio_2_ac)(int prio);
	int (*cb_ac_2_prio)(int ac);
	u16  tx_voq_base;
	u16  egress_port_id;
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
	uint16_t rx_default_hash_idx;
#else
	uint16_t rx_default_hash_idx[CS_WIRELESS_MAX_PRIO];
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
	u16 an_bmg_mac_idx;
} cs_wireless_interfac_t;



static cs_wireless_interfac_t cs_wireless_list[CS_HW_ACCEL_WIRELESS_INTERFACE_MAX];

static spinlock_t cs_wireless_lock;

#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
static int cs_hw_accel_create_rx_default_fwd_hash(int vap_idx)
{
	fe_fwd_result_entry_t fwdrslt_entry;
	fe_voq_pol_entry_t voqpol_entry;
	fe_sw_hash_t key;
	u64 fwd_hm_flag;
	u32 crc32;
	u16 hash_index, crc16;
	unsigned int fwdrslt_idx, voqpol_idx;
	u32 sw_action_id;

	memset(&fwdrslt_entry, 0x0, sizeof(fwdrslt_entry));
	memset(&voqpol_entry, 0x0, sizeof(voqpol_entry));
	memset(&key, 0x0, sizeof(key));
    
	if (cs_core_vtable_get_hashmask_flag_from_apptype(
		CORE_FWD_APP_TYPE_PE_RECIDX, &fwd_hm_flag))
		return -1;

	if (cs_core_vtable_get_hashmask_index_from_apptype(
		CORE_FWD_APP_TYPE_PE_RECIDX, &key.mask_ptr_0_7))
		return -2;

	key.lspid = CPU_PORT;
	key.recirc_idx = vap_idx + 1;
	if (cs_fe_hash_calc_crc(&key, &crc32, &crc16, CRC16_CCITT))
		return -3;

	voqpol_entry.voq_base = CPU_PORT5_VOQ_BASE;			
	
	if (cs_fe_table_add_entry(FE_TABLE_VOQ_POLICER, &voqpol_entry,
		&voqpol_idx))
		return -4;
    
    // For 11AC
    sw_action_id = (CS_FUNC_TYPE_WIRELESS_ACCEL_11AC << 16) + vap_idx + 1;
	DBG(printk("%s:%d:: sw_action_id 0x%x, voqpol_idx %d\n", __func__, __LINE__, sw_action_id, voqpol_idx));
    
    fwdrslt_entry.dest.voq_policy = 1;
	fwdrslt_entry.dest.voq_pol_table_index = voqpol_idx;
	fwdrslt_entry.l3.ip_da_replace_en = 0;
	fwdrslt_entry.l3.ip_sa_replace_en = 0;
	fwdrslt_entry.l3.ip_sa_index = (u16)(sw_action_id & 0x0fff);
	fwdrslt_entry.l3.ip_da_index = (u16)((sw_action_id >> 12) & 0x00ff);
	if (cs_fe_table_add_entry(FE_TABLE_FWDRSLT, &fwdrslt_entry,
		&fwdrslt_idx)) {
		cs_fe_table_del_entry_by_idx(FE_TABLE_VOQ_POLICER,
			voqpol_idx, false);
		return -5;
	}

	if (cs_fe_hash_add_hash(crc32, crc16, key.mask_ptr_0_7,
		(u16)fwdrslt_idx, &cs_wireless_list[vap_idx].rx_default_hash_idx)) {
		cs_fe_fwdrslt_del_by_idx(fwdrslt_idx);
		return -6;
	}

	DBG(printk("%s:%d:: success\n", __func__, __LINE__));

	return 0;
}
#else
static int cs_hw_accel_create_rx_default_fwd_hash(int vap_idx)
{
	fe_fwd_result_entry_t fwdrslt_entry;
	fe_voq_pol_entry_t voqpol_entry;
	fe_sw_hash_t key;
	u64 fwd_hm_flag;
	u32 crc32;
	u16 hash_index, crc16;
	unsigned int fwdrslt_idx, voqpol_idx;
	int  i, j;

	memset(&fwdrslt_entry, 0x0, sizeof(fwdrslt_entry));
	memset(&voqpol_entry, 0x0, sizeof(voqpol_entry));
	memset(&key, 0x0, sizeof(key));

	//for (i = 0; i < 2; i++) {
		for (j = 0; j < CS_WIRELESS_MAX_PRIO; j++) {
			if (cs_core_vtable_get_hashmask_flag_from_apptype(
				CORE_FWD_APP_TYPE_PE_RECIDX, &fwd_hm_flag))
				continue;

			if (cs_core_vtable_get_hashmask_index_from_apptype(
				CORE_FWD_APP_TYPE_PE_RECIDX, &key.mask_ptr_0_7))
				continue;

			key.lspid = CPU_PORT;
			key.recirc_idx = vap_idx * CS_WIRELESS_MAX_PRIO + j + 1;
			if (cs_fe_hash_calc_crc(&key, &crc32, &crc16, CRC16_CCITT))
				continue;

			voqpol_entry.voq_base = CPU_PORT5_VOQ_BASE + vap_idx;			
			
			if (cs_fe_table_add_entry(FE_TABLE_VOQ_POLICER, &voqpol_entry,
				&voqpol_idx))
				continue;

			fwdrslt_entry.dest.voq_pol_table_index = voqpol_idx;
			fwdrslt_entry.l3.ip_da_replace_en = 0;
			fwdrslt_entry.l3.ip_sa_replace_en = 0;
			fwdrslt_entry.l3.ip_sa_index = (u16) j;
			fwdrslt_entry.l3.ip_da_index = 0;
			
			if (cs_fe_table_add_entry(FE_TABLE_FWDRSLT, &fwdrslt_entry,
				&fwdrslt_idx)) {
				cs_fe_table_del_entry_by_idx(FE_TABLE_VOQ_POLICER,
					voqpol_idx, false);
				continue;
			}

			if (cs_fe_hash_add_hash(crc32, crc16, key.mask_ptr_0_7,
				(u16)fwdrslt_idx, &cs_wireless_list[vap_idx].rx_default_hash_idx[j])) {
				cs_fe_fwdrslt_del_by_idx(fwdrslt_idx);
				continue;
			}

		}
	//}
	return 1;
}
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS

static int cs_hw_accel_delete_rx_default_fwd_hash(int vap_idx)
{
	int  i;	
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS 
	if (cs_wireless_list[vap_idx].rx_default_hash_idx != 0) {
		cs_fe_hash_del_hash(cs_wireless_list[vap_idx].rx_default_hash_idx);
		cs_wireless_list[vap_idx].rx_default_hash_idx = 0;
	}
#else 
	for (i = 0; i < CS_WIRELESS_MAX_PRIO; i++) {
		if (cs_wireless_list[vap_idx].rx_default_hash_idx[i] != 0) {
			cs_fe_hash_del_hash(cs_wireless_list[vap_idx].rx_default_hash_idx[i]);
			cs_wireless_list[vap_idx].rx_default_hash_idx[i] = 0;
		}
	}
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
}

int cs_hw_accel_wirelss_clean_fwd_path_by_mac(char * mac)
{
	cs_core_hmu_value_t hmu_value;
	int i;
	DBG(printk("%s delete mac=%pM\n", __func__, mac));

	hmu_value.type = CS_CORE_HMU_WATCH_IN_MAC_SA;
	for (i = 0; i < 6; i++)
		hmu_value.value.mac_addr[i] = mac[5 - i];
	hmu_value.mask = 0;

	cs_core_hmu_delete_hash(CS_CORE_HMU_WATCH_IN_MAC_SA, &hmu_value);


	hmu_value.type = CS_CORE_HMU_WATCH_OUT_MAC_DA;
	for (i = 0; i < 6; i++)
		hmu_value.value.mac_addr[i] = mac[5 - i];

	cs_core_hmu_delete_hash(CS_CORE_HMU_WATCH_OUT_MAC_DA, &hmu_value);
	
	return 0;
}

int cs_hw_accel_wireless_clean_all_hash(void)
{
	int i, j;
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		if (cs_wireless_list[i].status == CS_WIRELESS_ALLOCATED) {
			if (cs_wireless_list[i].dev)
				cs_hw_accel_wirelss_clean_fwd_path_by_mac(cs_wireless_list[i].dev->dev_addr);	
		}
	}
	
}

void cs_wireless_callback_hma(unsigned long notify_event,
		unsigned long value)
{
	DBG(printk("%s() cs hw accel wireless event%ld\n", __func__,
			notify_event));
	switch (notify_event) {
		case CS_HAM_ACTION_MODULE_DISABLE:
		case CS_HAM_ACTION_CLEAN_HASH_ENTRY:
			cs_hw_accel_wireless_clean_all_hash();
			break;
		case CS_HAM_ACTION_MODULE_REMOVE:			
			break;
		case CS_HAM_ACTION_MODULE_INSERT:			
			break;
	}

}

int cs_hw_accel_wireless_enable(void)
{
	return cs_accel_kernel_module_enable(CS752X_ADAPT_ENABLE_WIRELESS);
}

/* generic proc file handler */
static int read_proc(char *buf, int *eof, const char* name, u32 value)
{
	u32 len = 0;

	len += sprintf(buf, " %s = %d\n", name, value);
	*eof = 1;
	return len;
}

static int write_proc(const char *buffer, unsigned long count, const char* name, u32* value)
{
	char buf[32];
	unsigned long mask;
	ssize_t len;

	len = min(count, (unsigned long)(sizeof(buf) - 1));
	if (copy_from_user(buf, buffer, len))
		goto HW_ACCEL_INVAL_EXIT;

	buf[len] = '\0';
	if (strict_strtoul(buf, 0, &mask))
		goto HW_ACCEL_INVAL_EXIT;

	*value = mask;
	printk(KERN_WARNING "\nSet %s as %d\n", name, *value);

	return count;

HW_ACCEL_INVAL_EXIT:
	printk(KERN_WARNING "\nSet %s ERROR!! \n", name);
	return count;
	/* if we return error code here, PROC fs may retry up to 3 times. */
}

/* file handler for wireless_tx_pop_vlan */
static int cs_proc_node_wireless_tx_pop_vlan_read(char *buf, char **start,
		off_t offset, int count, int *eof, void *data)
{
	return read_proc(buf, eof, CS752X_NODE_WIRELESS_POP_VLAN, cs_wireless_tx_pop_vlan);
}

static int cs_proc_node_wireless_tx_pop_vlan_write(struct file *file,
		const char *buffer, unsigned long count, void *data)
{
	return write_proc(buffer, count, CS752X_NODE_WIRELESS_POP_VLAN, &cs_wireless_tx_pop_vlan);
}

/* file handler for cp_vlan_pri_to_dscp */
static int cs_proc_node_cp_vlan_pri_to_dscp_read(char *buf, char **start,
		off_t offset, int count, int *eof, void *data)
{
	return read_proc(buf, eof, CS752X_NODE_CP_VLAN_PRIO_TO_DSCP, cs_cp_vlan_pri_to_dscp);
}

static int cs_proc_node_cp_vlan_pri_to_dscp_write(struct file *file,
		const char *buffer, unsigned long count, void *data)
{
	return write_proc(buffer, count, CS752X_NODE_CP_VLAN_PRIO_TO_DSCP, &cs_cp_vlan_pri_to_dscp);
}

int cs_hw_accel_wireless_init(void)
{
	int i, j;
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		cs_wireless_list[i].status = CS_WIRELESS_FREE;				
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS
        // For 11AC
	    cs_wireless_list[i].tx_voq_base = CPU_PORT3_VOQ_BASE;
		cs_wireless_list[i].rx_default_hash_idx = 0;
#else
		switch (i) {
			case 0:	cs_wireless_list[i].tx_voq_base = CPU_PORT3_VOQ_BASE + 1; // wl0
					break;
			case 1:	cs_wireless_list[i].tx_voq_base = CPU_PORT4_VOQ_BASE;     // wl1
					break;
			case 2:	cs_wireless_list[i].tx_voq_base = CPU_PORT3_VOQ_BASE;     // wl0.1
					break;
			case 3:	cs_wireless_list[i].tx_voq_base = CPU_PORT4_VOQ_BASE + 4; // wl1.1
					break;
		}
		for (j = 0; j < CS_WIRELESS_MAX_PRIO; j++) {
			cs_wireless_list[i].rx_default_hash_idx[j] = 0;
		}
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
	}
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
	memset(&cs_wireless_voq_entry, 0x0, sizeof(cs_wireless_voq_entry));
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS  
	cs_hw_accel_mgr_register_proc_callback(CS752X_ADAPT_ENABLE_WIRELESS,
					       cs_wireless_callback_hma);

	struct proc_dir_entry *node;

	node = create_proc_entry(CS752X_NODE_WIRELESS_POP_VLAN, S_IRUGO | S_IWUGO, proc_driver_cs752x_ne);
	if (node) {
		node->read_proc = cs_proc_node_wireless_tx_pop_vlan_read;
		node->write_proc = cs_proc_node_wireless_tx_pop_vlan_write;
	} else {
		printk(KERN_ERR "ERROR in creating proc entry (%s)!\n", CS752X_NODE_WIRELESS_POP_VLAN);
	}

	node = create_proc_entry(CS752X_NODE_CP_VLAN_PRIO_TO_DSCP, S_IRUGO | S_IWUGO, proc_driver_cs752x_ne);
	if (node) {
		node->read_proc = cs_proc_node_cp_vlan_pri_to_dscp_read;
		node->write_proc = cs_proc_node_cp_vlan_pri_to_dscp_write;
	} else {
		printk(KERN_ERR "ERROR in creating proc entry (%s)!\n", CS752X_NODE_CP_VLAN_PRIO_TO_DSCP);
	}
}

int cs_hw_accel_wireless_exit(void)
{
	cs_hw_accel_mgr_register_proc_callback(CS752X_ADAPT_ENABLE_WIRELESS, NULL);
	return 0;
}

extern int cs_wfo_mc_mac_table_del_entry(unsigned char* mac_da);
extern int cs_wfo_mc_mac_table_add_entry(unsigned char* mac_da, unsigned char* p_egress_port_id);

int cs_hw_accel_wireless_add_an_bng_entry(int idx, struct net_device *dev) {
	fe_an_bng_mac_entry_t abm_entry;
	int ret;
	int i;
	memset(&abm_entry, 0x0, sizeof(abm_entry));
	abm_entry.sa_da = 0;
	abm_entry.valid = 1;
	abm_entry.pspid_mask = 0;
	abm_entry.pspid = CPU_PORT;
	
	for (i = 0; i < 6; i++)
		*(((unsigned char*)abm_entry.mac) + 6 - 1 - i) = *(((unsigned char*)dev->dev_addr) + i);				
				
	ret = cs_fe_table_add_entry(FE_TABLE_AN_BNG_MAC,
				&abm_entry, &cs_wireless_list[idx].an_bmg_mac_idx);
	if (ret != 0)
		printk("ERROR %s create an bng mac table fail. Error Code = %d\n", __func__, ret);
	return ret;
}

int cs_hw_accel_wireless_del_an_bng_entry(int idx, struct net_device *dev) {
	fe_an_bng_mac_entry_t abm_entry;
	int ret;
	int i;
	ret = cs_fe_table_del_entry_by_idx(FE_TABLE_AN_BNG_MAC,
				cs_wireless_list[idx].an_bmg_mac_idx, false);

	if (ret != 0)
		printk("ERROR %s delete an bng mac table at idx %d fail. Error Code = %d\n", __func__, 
			cs_wireless_list[idx].an_bmg_mac_idx, ret);
	return ret;
}

int cs_hw_accel_wireless_register(struct net_device *dev, int (*cb_start_xmit)(struct sk_buff *, struct net_device *), 
	int (*cb_prio_2_ac)(int prio), 	int (*cb_ac_2_prio)(int ac))
{
	int i;
	int rc;
	u8 egress_port_id;
	printk("%s %pM \n", __func__, dev->dev_addr);
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		if (cs_wireless_list[i].status == CS_WIRELESS_FREE) {
			printk("%s %pM use idx %d\n", __func__, dev->dev_addr, i);
			cs_wireless_list[i].status = CS_WIRELESS_ALLOCATED;
			cs_wireless_list[i].cb_start_xmit = cb_start_xmit;
			cs_wireless_list[i].cb_prio_2_ac = cb_prio_2_ac;
			cs_wireless_list[i].cb_ac_2_prio = cb_ac_2_prio;
			cs_wireless_list[i].dev = dev;
			rc = cs_wfo_mc_mac_table_add_entry(dev->dev_addr, &cs_wireless_list[i].egress_port_id);			
            if ( rc != CS_MC_MAC_ENTRY_STATUS_SUCCESS) {
            	printk("%s cannot allocate a free Multicast MAC entry \n", __func__);
            	return -1;
            }
            cs_hw_accel_create_rx_default_fwd_hash(i);            
            printk("\t allocate idx=%d mc_mac_idx=%d\n", i, cs_wireless_list[i].egress_port_id);
            cs_hw_accel_wireless_add_an_bng_entry(i, dev);
			return i;
		}
	}
	return -1;
}

int cs_hw_accel_wireless_unregister(struct net_device *dev)
{
	int i;
	printk("%s %pM \n", __func__, dev->dev_addr);
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		if (cs_wireless_list[i].dev == dev) {
			cs_hw_accel_wireless_del_an_bng_entry(i, dev);
			cs_hw_accel_delete_rx_default_fwd_hash(i);  
			cs_wfo_mc_mac_table_del_entry(dev->dev_addr);
			cs_hw_accel_wirelss_clean_fwd_path_by_mac(dev->dev_addr);			
			cs_wireless_list[i].status = CS_WIRELESS_FREE;			
			cs_wireless_list[i].dev = NULL;
			cs_wireless_list[i].an_bmg_mac_idx = 0;
			return i;
		}
	}
	return -1;
}

#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
#error "please fix this patch or disable CONFIG_CS75XX_OFFSET_BASED_QOS"
/* 
 * 8-bit CRC 
 * 
 * POLY x^8 + x^2 + x^1 + 1 
 *      1-00000111 
 *      0x107 
 */ 
static unsigned char crc8_table[256] = 
{ 
  0x00,0x07,0x0e,0x09,0x1c,0x1b,0x12,0x15, 
  0x38,0x3f,0x36,0x31,0x24,0x23,0x2a,0x2d, 
  0x70,0x77,0x7e,0x79,0x6c,0x6b,0x62,0x65, 
  0x48,0x4f,0x46,0x41,0x54,0x53,0x5a,0x5d, 
  0xe0,0xe7,0xee,0xe9,0xfc,0xfb,0xf2,0xf5, 
  0xd8,0xdf,0xd6,0xd1,0xc4,0xc3,0xca,0xcd, 
  0x90,0x97,0x9e,0x99,0x8c,0x8b,0x82,0x85, 
  0xa8,0xaf,0xa6,0xa1,0xb4,0xb3,0xba,0xbd, 
  0xc7,0xc0,0xc9,0xce,0xdb,0xdc,0xd5,0xd2, 
  0xff,0xf8,0xf1,0xf6,0xe3,0xe4,0xed,0xea, 
  0xb7,0xb0,0xb9,0xbe,0xab,0xac,0xa5,0xa2, 
  0x8f,0x88,0x81,0x86,0x93,0x94,0x9d,0x9a, 
  0x27,0x20,0x29,0x2e,0x3b,0x3c,0x35,0x32, 
  0x1f,0x18,0x11,0x16,0x03,0x04,0x0d,0x0a, 
  0x57,0x50,0x59,0x5e,0x4b,0x4c,0x45,0x42, 
  0x6f,0x68,0x61,0x66,0x73,0x74,0x7d,0x7a, 
  0x89,0x8e,0x87,0x80,0x95,0x92,0x9b,0x9c, 
  0xb1,0xb6,0xbf,0xb8,0xad,0xaa,0xa3,0xa4, 
  0xf9,0xfe,0xf7,0xf0,0xe5,0xe2,0xeb,0xec, 
  0xc1,0xc6,0xcf,0xc8,0xdd,0xda,0xd3,0xd4, 
  0x69,0x6e,0x67,0x60,0x75,0x72,0x7b,0x7c, 
  0x51,0x56,0x5f,0x58,0x4d,0x4a,0x43,0x44, 
  0x19,0x1e,0x17,0x10,0x05,0x02,0x0b,0x0c, 
  0x21,0x26,0x2f,0x28,0x3d,0x3a,0x33,0x34, 
  0x4e,0x49,0x40,0x47,0x52,0x55,0x5c,0x5b, 
  0x76,0x71,0x78,0x7f,0x6a,0x6d,0x64,0x63, 
  0x3e,0x39,0x30,0x37,0x22,0x25,0x2c,0x2b, 
  0x06,0x01,0x08,0x0f,0x1a,0x1d,0x14,0x13, 
  0xae,0xa9,0xa0,0xa7,0xb2,0xb5,0xbc,0xbb, 
  0x96,0x91,0x98,0x9f,0x8a,0x8d,0x84,0x83, 
  0xde,0xd9,0xd0,0xd7,0xc2,0xc5,0xcc,0xcb, 
  0xe6,0xe1,0xe8,0xef,0xfa,0xfd,0xf4,0xf3 
}; 
static unsigned char calc_crc8(unsigned char *data, size_t len) 
{ 
    size_t i; 
    unsigned char crc = 0xff; /* 0x00 */ 

    for (i=0; i<len; i++) {
        crc = crc8_table[ (crc ^ *data++) & 0xff] ;
    } 

    return crc; 
} 
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS  

/* Offset-based
 *							TX 				RX  
 * 11AC                     72~79           88-95
 * 11n                      80~87           88-95
 * ----------------------------------------------
 * Flow-based 
 *							TX 				RX  
 * wireless_device[0]  		73,75,77,79		88
 * wireless_device[1]  		80~83			89
 * wireless_device[2]  		72,74,76,78		90
 * wireless_device[3]  		84~87			91
 */
extern int cs752x_fast_bridging(struct sk_buff *skb); 
int cs_hw_accel_wireless_handle(int voq, struct sk_buff *skb, unsigned int sw_action)
{
	int i;
	int dev_id;
	int direction;
	int ac_queue;
	struct net_device *dev;
	cs_kernel_accel_cb_t *cs_cb = CS_KERNEL_SKB_CB(skb);
	
	if (voq >= CPU_PORT5_VOQ_BASE) {
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
		dev_id = (sw_action & 0xffff) - 1;
#else
		dev_id = voq - CPU_PORT5_VOQ_BASE;
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
		direction = 1;
	} else {
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
        dev_id = *(skb->data+10);
        memcpy(skb->data+10, cs_wireless_voq_entry[*(skb->data+11)].mac_org, 2);
#else
		dev_id = (voq - CPU_PORT3_VOQ_BASE) / 4;
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
		if (dev_id < 2) {
			// wl0 and wl0.1 interleaved
			dev_id = ((voq - CPU_PORT3_VOQ_BASE) & 1) ? 0 : 2;
			ac_queue = 3 - ((voq - CPU_PORT3_VOQ_BASE)/2) % 4;
		} else {
			dev_id = (2 == dev_id) ? 1 : 3;
			ac_queue = 3 - (voq - CPU_PORT3_VOQ_BASE) % 4;
		}
		direction = 0;
	} 		
	if (dev_id > CS_HW_ACCEL_WIRELESS_INTERFACE_MAX)
		return 1;
		
	if (cs_wireless_list[dev_id].status != CS_WIRELESS_ALLOCATED)
		return 1;
		
	DBG(printk("%s dev_id=%d direction=%s voq=%d sw_action=0x%x\n", __func__, dev_id, (direction == 0)?"TX":"RX", voq, sw_action));
	if (direction == 0) {
		/*For wifi TX, hit the hash and directly send to wifi driver*/
		if (cs_cb != NULL) {
			cs_cb->common.sw_only = CS_SWONLY_STATE;
		}		
		skb->dev = cs_wireless_list[dev_id].dev;
		skb->priority = cs_wireless_list[dev_id].cb_ac_2_prio(ac_queue);
		cs_wireless_list[dev_id].cb_start_xmit(skb, cs_wireless_list[dev_id].dev);
		DBG(printk("\t ac_queue=%d skb->priority =%d %pM %pM %02X%02X%02X%02X\n", ac_queue, skb->priority, skb->data, skb->data + 6, skb->data[12],skb->data[13], skb->data[14],skb->data[15]));	
	} else {
		/*For wifi RX, doesn't hit the hash*/
		if (cs_cb != NULL) {
			cs_cb->common.module_mask |= CS_MOD_MASK_WIRELESS;
			if (cs_hw_accel_wireless_enable()) {
				cs_cb->common.ingress_port_id = SW_WIRELESS_PORT;				
			} else {
				cs_cb->common.sw_only = CS_SWONLY_STATE;
			}
		}
		skb->dev = cs_wireless_list[dev_id].dev;	
		skb->priority = cs_wireless_list[dev_id].cb_ac_2_prio(sw_action);		
#ifdef CONFIG_CS752X_PROC
		skb->mac_header = skb->data;
		skb->data = skb->data + ETH_HLEN;
		skb->len -= ETH_HLEN;
		if ((cs_ni_fastbridge != 0) && (cs752x_fast_bridging(skb) == 0))
			goto SKB_HANDLED;

		skb->data = skb->data - ETH_HLEN;
		skb->len += ETH_HLEN;
#endif		
		
#ifdef CONFIG_CS75XX_NI_EXPERIMENTAL_SW_CACHE_MANAGEMENT
		/* ...invalidate remainder of packet */
		if(skb->tail > skb->map_end && (skb->map_end != NULL) ){
			  	dma_map_single(NULL, skb->map_end,
                                        SKB_DATA_ALIGN(skb->tail - skb->map_end),
                                        DMA_FROM_DEVICE);
                        	skb->dirty_buffer = 1;
	                        skb->map_end = NULL;
		}
#endif
		skb->protocol = eth_type_trans(skb, skb->dev);
		skb->priority = cs_wireless_list[dev_id].cb_ac_2_prio(sw_action);				
		netif_receive_skb(skb);
	}	
SKB_HANDLED:	
	return 0;
}

static inline void cs_hw_accel_wireless_ipv4_change_dscp(struct sk_buff *skb, u8 value)
{
	struct iphdr *iph = skb->data + ETH_ALEN * 2 + 2;
	u32 check = ntohs((__force __be16)iph->check);
	u8 dsfield = (iph->tos & (__u8)(~CS_DSCP_MASK)) | (value << CS_DSCP_SHIFT);
	check += iph->tos;
	if ((check+1) >> 16) check = (check+1) & 0xffff;
	check -= dsfield;
	check += check >> 16; /* adjust carry */
	iph->check = (__force __sum16)htons(check);
	iph->tos = dsfield;
}


int cs_hw_accel_wireless_tx(struct sk_buff *skb)
{
	int i;
	int dev_id = -1;
	struct net_device *dev = skb->dev;
	int voq;
	cs_kernel_accel_cb_t *cs_cb = CS_KERNEL_SKB_CB(skb);
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
        u8 crc;
        u8 idx;
#endif
	
	/*Remove vlan priority */
	if (cs_wireless_tx_pop_vlan == 1) {

		DBG(printk("GWS: %s %pM %pM %02X%02X%02X%02X %02X%02X%02X%02X\n",
			__func__, skb->data, skb->data + 6, skb->data[12],skb->data[13],skb->data[14],skb->data[15]
			,skb->data[16],skb->data[17],skb->data[18],skb->data[19]));

		struct ethhdr *eth;
		eth = (struct ethhdr *)skb->data;
		if (eth->h_proto == htons(ETH_P_8021Q)) {

			/* save VLAN priority for use in setting DSCP */
			const u8 vlan_prio = skb->data[14] >> 5;
			DBG(printk("GWS Tag: %s skb->data[14] = %02X, vlan_prio = %02X\n", __func__, skb->data[14], vlan_prio));

			/*pop out 1st tag*/
			memmove(skb->data + VLAN_HLEN, skb->data, ETH_ALEN * 2);
			skb_pull(skb, VLAN_HLEN);

			/* set DSCP */
			DBG(printk("GWS Tag: %s iphdr dscp %02X\n"
					, __func__, skb->data[ETH_ALEN * 2 + CS_ETHER_TYPE_LEN + CS_IPH_DSCP_OFFSET]));
			if (cs_cp_vlan_pri_to_dscp) {
				switch (vlan_prio) {
					case 1: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x25); break;
					case 2: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x00); break;
					case 4: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x20); break;
					case 5: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x28); break;
					case 6: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x30); break;
					case 7: cs_hw_accel_wireless_ipv4_change_dscp(skb, 0x38); break;
				}
			}
			DBG(printk("GWS Tag: %s iphdr dscp after %02X\n"
					, __func__, skb->data[ETH_ALEN * 2 + CS_ETHER_TYPE_LEN + CS_IPH_DSCP_OFFSET]));
		}

		DBG(printk("GWS: %s after %pM %pM %02X%02X%02X%02X\n", __func__, skb->data, skb->data + 6, skb->data[12],skb->data[13],skb->data[14],skb->data[15]));
	}
	
	if (cs_cb == NULL) 
		return 0;
	
	if (!cs_hw_accel_wireless_enable())
		return 0;
		
	if ((cs_cb->common.tag != CS_CB_TAG) ||
		(cs_cb->common.sw_only & (CS_SWONLY_DONTCARE |
						  CS_SWONLY_STATE)))
		return 0;		
		
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		if (cs_wireless_list[i].dev == dev) {
			dev_id = i;	
			break;
		}
	}
	
	if (dev_id == -1)
		return -1;
		
	if (cs_wireless_list[dev_id].status != CS_WIRELESS_ALLOCATED)
		return -1;
	cs_cb->common.module_mask |= CS_MOD_MASK_WIRELESS;
	if ((cs_cb->common.module_mask & CS_MOD_MASK_IPV4_MULTICAST) ||
	    (cs_cb->common.module_mask & CS_MOD_MASK_IPV6_MULTICAST)){
    	cs_cb->action.voq_pol.d_voq_id = cs_wireless_list[dev_id].tx_voq_base + 3 -
    			(CS_WIRELESS_MAX_PRIO - 1);
	} else {
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
    idx = crc = calc_crc8(skb->data+ETH_ALEN, ETH_ALEN);
    if (cs_wireless_voq_entry[crc].used) {
        idx++;
        do {
            if (!cs_wireless_voq_entry[idx].used) {
                break;
            }
            idx++;
        } while(idx != crc);
        if (idx == crc) {
            printk("%s:%d:: ERROR!! mac sa table full\n", __func__, __LINE__, crc);
            //FIXME:
        }
    }
    cs_wireless_voq_entry[idx].used = 1;
    cs_wireless_voq_entry[idx].vap = dev_id;
    memcpy(cs_wireless_voq_entry[idx].mac_org, skb->data+10, 2);
    
    *(skb->data+10) = dev_id; // sa_mac[4]: vaps
    *(skb->data+11) = crc;    // sa_mac[5]: mac index
    cs_cb->action.voq_pol.voq_policy = 1;
	cs_cb->action.voq_pol.d_voq_id = cs_wireless_list[dev_id].tx_voq_base;
#else
	/*reverse AC to VOQ mapping*/
	if (0 == dev_id || 2 == dev_id) {
		cs_cb->action.voq_pol.d_voq_id = cs_wireless_list[dev_id].tx_voq_base +
				(3 - cs_wireless_list[dev_id].cb_prio_2_ac(skb->priority))*2;
	} else {
		cs_cb->action.voq_pol.d_voq_id = cs_wireless_list[dev_id].tx_voq_base + 3 -
			cs_wireless_list[dev_id].cb_prio_2_ac(skb->priority);
	}
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
    }
	cs_cb->action.voq_pol.cos_nop = 1;
	cs_cb->common.egress_port_id = cs_wireless_list[dev_id].egress_port_id;
	cs_core_logic_add_connections(skb);

#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
    memcpy(skb->data+10, cs_wireless_voq_entry[idx].mac_org, 2);
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS  

    DBG(printk("%s dev_id=%d skb->priority=%d voq_id=%d\n",
    		__func__, dev_id, skb->priority, cs_cb->action.voq_pol.d_voq_id));
	return 0;
}

extern int ni_special_start_xmit_none_bypass_ne(u16 recirc_idx, u32 buf0, int len0, u32 buf1, int len1, struct sk_buff *skb);

int cs_hw_accel_wireless_rx(struct sk_buff *skb)
{
	int i;
	int dev_id = -1;
	struct net_device *dev = skb->dev;
	int voq;
	cs_kernel_accel_cb_t *cs_cb;
	u16 recirc_idx;
	char * data_ptr;
	
	if (!cs_hw_accel_wireless_enable())
		return -1;
		
	for (i = 0; i < CS_HW_ACCEL_WIRELESS_INTERFACE_MAX; i++) {
		if (cs_wireless_list[i].dev == dev) {
			dev_id = i;	
			break;
		}
	}
	
	if (dev_id == -1)
		return -1;
		
	if (cs_wireless_list[dev_id].status != CS_WIRELESS_ALLOCATED)
		return -1;
	
	if (skb_shinfo(skb)->nr_frags)
		return -1;
	

	/*xmit skb to NE*/					
	skb_push(skb, ETH_HLEN);
#ifdef CONFIG_CS75XX_OFFSET_BASED_QOS  
	recirc_idx = dev_id + 1;
#else
	recirc_idx = dev_id * CS_WIRELESS_MAX_PRIO + cs_wireless_list[dev_id].cb_prio_2_ac(skb->priority) + 1;
#endif //CONFIG_CS75XX_OFFSET_BASED_QOS
	DBG(printk("%s dev_id=%d recirc_idx=%d \n", __func__, dev_id, recirc_idx));

#ifdef CONFIG_CS752X_PROC
	if(cs_acp_enable & CS75XX_ACP_ENABLE_NI){
		data_ptr = virt_to_phys(skb->data)|GOLDENGATE_ACP_BASE;
	}
	else
#endif
#ifdef CONFIG_CS75XX_NI_EXPERIMENTAL_SW_CACHE_MANAGEMENT
			data_ptr = dma_map_single(NULL, (void *)skb->data,
					skb->dirty_buffer ? skb->len : SMP_CACHE_BYTES,
					DMA_TO_DEVICE);
#else /* CONFIG_CS75XX_NI_EXPERIMENTAL_SW_CACHE_MANAGEMENT */
			data_ptr = dma_map_single(NULL, (void *)skb->data, skb->len,
						DMA_TO_DEVICE);		
#endif /* CONFIG_CS75XX_NI_EXPERIMENTAL_SW_CACHE_MANAGEMENT */
	ni_special_start_xmit_none_bypass_ne(recirc_idx, data_ptr, skb->len, 0, 0, skb) ;

	return 0;
}

EXPORT_SYMBOL(cs_hw_accel_wireless_init);
EXPORT_SYMBOL(cs_hw_accel_wireless_exit);
EXPORT_SYMBOL(cs_hw_accel_wireless_unregister);
EXPORT_SYMBOL(cs_hw_accel_wireless_register);
EXPORT_SYMBOL(cs_hw_accel_wireless_handle);
EXPORT_SYMBOL(cs_hw_accel_wireless_tx);
EXPORT_SYMBOL(cs_hw_accel_wireless_rx);
EXPORT_SYMBOL(cs_hw_accel_wirelss_clean_fwd_path_by_mac);
