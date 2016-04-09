/**
 * Copyright (c) 2014 GreenWave Systems.
 *
 * Author: Greenwave Systems
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef MOD_CRYPTO_GWS_H_
#define MOD_CRYPTO_GWS_H_

/**
 * Decryption / encryption of items using device key
 *
 * This kernel module exposes two minor devices. gwr_crypto0 is used for
 * encryption using the OTP key, gwr_crypto1 is used for decryption with
 * the OTP key.
 */

/**
 * Entities to be encrypted / decrypted may not exceed this length
 */
#define MAX_PAYLOAD_LENGTH 2048

/**
 * Device name for crypto device
 */
#define CRYPTO_DEVICE_NAME "gws_crypto"

#endif
