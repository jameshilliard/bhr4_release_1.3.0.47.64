//#define DEBUG
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/random.h>
#include <linux/delay.h>
#include <linux/ioport.h>
#include <linux/platform_device.h>
#include <mach/platform.h>
#include <linux/sysfs.h>

#include "otp_ioctl.h"
#include "otp_keys.h"

#define DRVNAME "otp_memory"

#define OTP_SIZE 1024
#define OTP_TLV_MAGIC 0x3C
#define OTP_MAGIC_FIRST 0x5A
#define OTP_MAGIC_LAST 0xA5

#define T_VALID_START 1
#define T_VALID_END 31

#define OTP_WRITE_SEL 1
#define OTP_LOCK_SEL 6
#define OTP_ADDR GOLDENGATE_OTP_BASE
#define AES_192_KEYLEN 24

static struct platform_device* otp_pdev = NULL;

static int read_one_byte(u32 offset)
{
	unsigned char* p = (unsigned char*)OTP_ADDR;

	if (offset > OTP_SIZE)
		return -1;

	return p[offset];
}

static int program_register(u8 sel, u32 addr, u32 max_addr)
{
	OTP_CTL_t otp_ctrl_inst;
	OTP_PROG_t otp_prog_inst;
	u32* otpprog_reg, *otpctrl_reg;
	int try_cnt;

	memset((void*)&otp_ctrl_inst, 0, sizeof(otp_ctrl_inst));
	memset((void*)&otp_prog_inst, 0, sizeof(otp_prog_inst));

	otp_ctrl_inst.bf.CLKCNT = 0xc8;
	otp_ctrl_inst.bf.TZPCDECPROT_SPARE0 = 0;
	otp_ctrl_inst.bf.TZPCDECPROT_SPARE1 = 0;
	otp_ctrl_inst.bf.TZPCDECPROT_QMPB = 1;
	otp_ctrl_inst.bf.TZPCDECPROT_RTC = 0;
	otp_ctrl_inst.bf.AXIPREVENT = 0;
	otp_ctrl_inst.bf.AXIOPEN = 1;
	otp_ctrl_inst.bf.NP1 = 4;
	otp_ctrl_inst.bf.NP2 = 16;

	otp_prog_inst.bf.ACCESS = 1;
	otp_prog_inst.bf.SEL = sel;
	otp_prog_inst.bf.LOCK = 0;
	otp_prog_inst.bf.FAIL = 0;
	otp_prog_inst.bf.DATA = 1;
	otp_prog_inst.bf.MAXADDR = max_addr;
	otp_prog_inst.bf.ADDR = addr;

	otpctrl_reg = (u32*)OTP_CTL;
	*otpctrl_reg = otp_ctrl_inst.wrd;

	otpprog_reg = (u32*)OTP_PROG;
	*otpprog_reg = otp_prog_inst.wrd;

	try_cnt = 0;
	do {
		udelay(1);
		otp_prog_inst.wrd = *otpprog_reg;
	} while (otp_prog_inst.bf.ACCESS && ++try_cnt < 50);

	if (try_cnt >= 50)
		return 1;

	otp_prog_inst.wrd = *otpprog_reg;
	return otp_prog_inst.bf.FAIL;
}

static int write_one_byte(u32 offset, u32 value)
{
	u32 i;
	u8* otpImage;

	if (offset >= OTP_SIZE || value > 0xff) {
		return 1;
	}

	otpImage = (u8*)(OTP_ADDR);

	for (i = 0; i < 8; ++i) {
		if ((value & (0x01 << i)) == 0) {
			if (otpImage[offset] & (0x01 << i))
				return 1;
			continue;
		} else if (otpImage[offset] & (0x01 << i))
			continue;

		if (program_register(OTP_WRITE_SEL, offset * 8 + i, 0) != 0) {
			return 1;
		}
	}

	if (read_one_byte(offset) == value)
		return 0;

	return 1;
}

static int write_one_tlv(u32 offset, u8* addr, u32 len)
{
	u32 i, last_index;
	u8* p;

	p = addr + len - 1;
	last_index = OTP_SIZE - 1;

	for (i = 0; i < len && offset < last_index; ++offset, --p, ++i) {
		if (write_one_byte(offset, *p) != 0)
			return i + 1;
	}

	if (i == len)
		return 0;

	return i;
}

static u32 find_write_pos(void)
{
	u32 write_pos;
	unsigned char* otpImage;

	write_pos = OTP_SIZE - 2;
	otpImage = (unsigned char*)OTP_ADDR;

	for (; write_pos > 0; --write_pos) {
		if (otpImage[write_pos] != 0) {
			break;
		}
	}

	if (write_pos >= OTP_SIZE - 2)
		return 0;
	return ++write_pos;
}

static int write_magic(void)
{
	if (read_one_byte(OTP_SIZE - 1) == OTP_MAGIC_LAST)
		return 0;

	if (write_one_byte(OTP_SIZE - 1, OTP_MAGIC_LAST) == 0)
		return 0;

	if (read_one_byte(0) == OTP_MAGIC_FIRST)
		return 0;

	if (write_one_byte(0, OTP_MAGIC_FIRST) == 0)
		return 0;

	return 1;
}

int write_tlv(u8* addr, u32 len)
{
	u32 write_pos, write_bytes, skip_len;
	u8 skip_tlv[4];

	write_pos = find_write_pos();
	if (write_pos == 0 || write_pos + len > (OTP_SIZE - 1))
		return 1;

	do {
		write_bytes = write_one_tlv(write_pos, addr, len);

		if (write_bytes == 0)
			break;

		skip_len = 0;
		do {
			/* Write a *SKIP* TLV to skip the errors.  */
			skip_len += write_bytes;
			write_pos += write_bytes;

			if (write_pos + skip_len + 4 > (OTP_SIZE - 1))
				return 1;

			skip_tlv[0] = OTP_TLV_MAGIC;
			skip_tlv[1] = 0x08;
			skip_tlv[2] = skip_len & 0xFF;
			skip_tlv[3] = skip_len >> 8;

			write_bytes = write_one_tlv(write_pos, skip_tlv, 4);

			if (write_bytes == 0) {
				write_pos += 4;
				break;
			}
		} while (1);
	} while (1);

	return write_magic();
}

/**
 * return 0 if not found,
 */
int find_tlv_pos(u32 tlv_type)
{
	u8 type;
	u8* ptrotp, *end;
	u16 len;

	ptrotp = (u8*)(OTP_ADDR + OTP_SIZE - 1);
	end = (u8*)(OTP_ADDR + 1);

	for (;;) {
		/*
		 * stop processing when not
		 * enough space is left to hold
		 * a TLV (4 bytes minimum)
		 */
		if (ptrotp - end < 4)
			break;

		if (ptrotp[0] != OTP_TLV_MAGIC) {
			ptrotp--; /* skip to next byte and try again */
			continue;
		}

		type = ptrotp[-1];
		if (type < T_VALID_START || type > T_VALID_END) {
			ptrotp--;
			continue;
		}

		len = ptrotp[-2] | (ptrotp[-3] << 8);
		if (len > ptrotp - end) {
			ptrotp--;
			continue;
		}

		if (type != tlv_type) {
			ptrotp -= 4 + len;
			continue;
		}

		return (int)ptrotp - OTP_ADDR;
	}

	return 0;
}

/**
 * Check OTP is blank or has data.
 *
 * return 0 if valid; others are invalid.
 */
static int check_otp_valid(void)
{
	u8* otp;

	otp = (u8*)(OTP_ADDR);

	if (otp[OTP_SIZE - 1] == OTP_MAGIC_LAST)
		return 0;

	if (otp[0] == OTP_MAGIC_FIRST)
		return 0;

	if (otp[OTP_SIZE - 1] == 0 || otp[0] == 0)
		return 0;

	return 1;
}

/**
 * read TLV content by TLV type
 *
 * return non-zero value if failed.
 */
int read_OTP_tlv(u8 type, u8* buffer, u16* len)
{
	int pos, i;
	u16 data_len;
	u8* otp, *p;

	otp = (u8*)(OTP_ADDR);
	if ((otp[OTP_SIZE - 1] != OTP_MAGIC_LAST) && (otp[0] != OTP_MAGIC_FIRST))
		return 1;

	pos = find_tlv_pos(type);
	if (pos <= 0)
		return 1;

	p = otp + pos - 2;
	data_len = p[0] | (p[-1] << 8);

	if (data_len > *len)
		return 1;

	p -= 2;
	for (i = 0; i < data_len; ++i, ++buffer, --p)
		*buffer = *p;

	*len = data_len;
	return 0;
}
EXPORT_SYMBOL(read_OTP_tlv);

int write_OTP_tlv(u8 type, u16 len, u8* value)
{
	char tlv[256];

	if (check_otp_valid() != 0)
		return 1;

	tlv[0] = OTP_TLV_MAGIC;
	tlv[1] = type;
	tlv[2] = len & 0xff;
	tlv[3] = len >> 8;
	memcpy(tlv + 4, value, len);

	return write_tlv(tlv, len + 4);
}

/**
 * return 0 if not existed
 */
static int is_TLV_existed(u8 type)
{
	if (check_otp_valid() != 0)
		return 0;

	return find_tlv_pos(type);
}

static int lock_OTP(void)
{
#ifdef LOCK_OTP
	pr_devel("%s:%d - Locking OTP", __FUNCTION__, __LINE__);
	return program_register(OTP_LOCK_SEL, 0, 0);
#else
	pr_devel("%s:%d - OTP locking disabled", __FUNCTION__, __LINE__);
	return 0;
#endif
}

/* test TLV type !
 * Modify by customer.
 */
#define DEVICE_KEY_TLV_TYPE 0xc
#define FIRMWARE_KEY_TLV_TYPE 0x01

static int configure_crypto_core0_to_use_OTP(u8* buffer, int len)
{
	/* Empty function ! Implemented by customer */

	return 0;
}

static long otp_handler_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
	int rc;
	const u16 key_len = sizeof(firmware_upgrade_pub_key);

	if (_IOC_TYPE(cmd) != OTP_IOCTL_MAGIC) return -ENOTTY;
	if (_IOC_NR(cmd) > OTP_IOCTL_MAX) return -ENOTTY;

	/*
	 *  Where to extract key and how to extract is implemented by customers.
	 */

	if (is_TLV_existed(FIRMWARE_KEY_TLV_TYPE) == 0) {
		rc = write_OTP_tlv(FIRMWARE_KEY_TLV_TYPE, key_len, firmware_upgrade_pub_key);
		if (rc != 0)
			return -EFAULT;
	}

	if (is_TLV_existed(FIRMWARE_KEY_TLV_TYPE) && is_TLV_existed(DEVICE_KEY_TLV_TYPE)) {
		lock_OTP();
	}

	return 0;
}

static int is_OTP_locked(void)
{
	OTP_PROG_t* otpprog_reg = (OTP_PROG_t*)OTP_PROG;
	return otpprog_reg->bf.LOCK ? 1 : 0;
}

static ssize_t otp_show_locked(struct device* dev, struct device_attribute* attr, char* buf)
{
	return sprintf(buf, "%d\n", is_OTP_locked());
}

static ssize_t otp_store_locked(struct device* dev, struct device_attribute* attr, const char* buf, size_t count)
{
	return -EIO;
}

static struct device_attribute otp_locked_file = __ATTR(is_locked, S_IRUGO, otp_show_locked, otp_store_locked);

static int otp_probe(struct platform_device* pdev)
{
	int ret = 0;
	struct resource* res = NULL;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		pr_err("%s:%d - platform_get_resource() failed", __FUNCTION__, __LINE__);
		ret = -ENODEV;
	} else {
		if (!request_mem_region_exclusive(res->start, resource_size(res), DRVNAME)) {
			pr_err("%s:%d - request_mem_region_exclusive() failed", __FUNCTION__, __LINE__);
			ret = -EBUSY;
		}
	}
	ret = device_create_file(&pdev->dev, &otp_locked_file);
	return ret;
}

static int otp_remove(struct platform_device* pdev)
{
	int ret = 0;
	struct resource* res = NULL;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		pr_err("%s:%d - platform_get_resource() failed", __FUNCTION__, __LINE__);
		ret = -ENODEV;
	} else {
		release_mem_region(res->start, resource_size(res));
	}
	device_remove_file(&pdev->dev, &otp_locked_file);
	return ret;
}

static struct platform_driver otp_memory_driver = {
	.probe = otp_probe,
	.remove = otp_remove,
	.driver = {
		.name = DRVNAME,
		.owner = THIS_MODULE,
	},
};

static const struct file_operations otp_handler_fops = {
	.open = nonseekable_open,
	.unlocked_ioctl = otp_handler_ioctl,
	.compat_ioctl = otp_handler_ioctl,
	.owner = THIS_MODULE,
	.llseek = noop_llseek,
};

static struct miscdevice otp_misc = {
	.minor = 239,
	.name = "otp-handler",
	.fops = &otp_handler_fops,
};

static int __init otp_init(void)
{
	int ret = 0;
	struct resource res = {
		.start = GOLDENGATE_OTP_BASE,
		.end = GOLDENGATE_OTP_BASE + SZ_1K - 1,
		.flags = IORESOURCE_MEM,
	};
	u16 len;
	char buffer[256];

	ret = platform_driver_register(&otp_memory_driver);
	if (ret) {
		pr_err("%s:%d - platform_driver_register() failed ret=%d", __FUNCTION__, __LINE__, ret);
		goto exit_noput;
	}
	otp_pdev = platform_device_alloc(DRVNAME, -1);
	if (!otp_pdev) {
		pr_err("%s:%d - platform_device_alloc() failed", __FUNCTION__, __LINE__);
		ret = -ENOMEM;
		goto exit_noput;
	}
	if (platform_device_add_resources(otp_pdev, &res, 1)) {
		pr_err("%s:%d - platform_device_add_resources() failed", __FUNCTION__, __LINE__);
		ret = -EBUSY;
		goto exit_put;
	}
	if (platform_device_add(otp_pdev)) {
		pr_err("%s:%d - platform_device_add() failed", __FUNCTION__, __LINE__);
		ret = -ENODEV;
		goto exit_put;
	}
	ret = misc_register(&otp_misc);
	if (ret < 0)
		goto exit_put;

	if (is_TLV_existed(DEVICE_KEY_TLV_TYPE) == 0) {
		char aes_key[AES_192_KEYLEN];
		get_random_bytes(aes_key, AES_192_KEYLEN);
		configure_crypto_core0_to_use_OTP(aes_key, AES_192_KEYLEN);
		write_OTP_tlv(DEVICE_KEY_TLV_TYPE, AES_192_KEYLEN, aes_key);
	}

	len = sizeof(buffer);
	read_OTP_tlv(DEVICE_KEY_TLV_TYPE, buffer, &len);
	configure_crypto_core0_to_use_OTP(buffer, len);

	if (is_TLV_existed(FIRMWARE_KEY_TLV_TYPE) && is_TLV_existed(DEVICE_KEY_TLV_TYPE)) {
		lock_OTP();
	}

	return 0;
exit_put:
	platform_device_put(otp_pdev);
exit_noput:
	return ret;
}
module_init(otp_init);

#ifdef DEBUG
static void __exit otp_exit(void)
{
	platform_device_unregister(otp_pdev);
	platform_driver_unregister(&otp_memory_driver);
	misc_deregister(&otp_misc);
}
module_exit(otp_exit);
#endif

MODULE_DESCRIPTION("otp");
MODULE_LICENSE("GPL");
MODULE_ALIAS("mod_otp");
MODULE_AUTHOR("eu@greenwavesystems.com");
