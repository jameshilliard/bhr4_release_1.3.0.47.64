#ifndef __THIRDPARTY_CG2UTILS_OTP_H__

#include <linux/types.h>
#include <linux/ioctl.h>

#define OTP_IOCTL_MAGIC 'O'

#define OTP_IOCTL_INIT _IO(OTP_IOCTL_MAGIC, 0)
#define OTP_IOCTL_MAX 1

#endif /*  __THIRDPARTY_CG2UTILS_OTP_H__ */
