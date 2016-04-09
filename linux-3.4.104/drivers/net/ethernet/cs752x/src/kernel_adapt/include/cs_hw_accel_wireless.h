#ifndef CS_KERNEL_WIRELESS_HW_ACC_SUPPORT
#define CS_KERNEL_WIRELESS_HW_ACC_SUPPORT 1



int cs_hw_accel_wireless_init(void);
int cs_hw_accel_wireless_exit(void);
int cs_hw_accel_wireless_handle(int voq, struct sk_buff *skb, unsigned int sw_action);

#endif

