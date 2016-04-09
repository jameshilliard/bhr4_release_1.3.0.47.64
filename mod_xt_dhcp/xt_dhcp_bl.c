/**
  Copyright (c) 2014 GreenWave Reality ApS.
*/

#include "xt_dhcp_bl.h"

#define PROTOCOL_UDP 0x11
#define DHCP_SOURCE_PORT 0x0044
#define DHCP_DESTINATION_PORT 0x0043
#define DHCP_OPTION_END 255
#define DHCP_OPTION_MESSAGE_TYPE 53

unsigned int dhcp_bl_mt(const __u8* package, unsigned int len, __u8 messageType)
{
	unsigned int pos = 0;
	if (len < 28) return 0;
	if ((package[pos+2] << 8) + package[pos+3] != len) return 0;
	if (package[pos+9]!=PROTOCOL_UDP) return 0;
	pos += 20; // IP header
	if ((package[pos] << 8)+package[pos+1] != DHCP_SOURCE_PORT
			&& (package[pos+2] << 8) + package[pos+3] != DHCP_DESTINATION_PORT) return 0;
	if ((package[pos+4] << 8) + package[pos+5] != len-20) return 0;
	pos += 8; // UDP header
	pos += 7*4; // DHCP header
	pos += 4*4; // Client MAC
	pos += 192; // space in protocol
	if (pos + 4 > len) return 0;
	if (((((((package[pos] << 8) + package[pos+1]) << 8) + package[pos+2]) << 8) + package[pos+3])
		!= 0x63825363) return 0;
	pos += 4; // magic cookie

	while (pos < len && package[pos] != DHCP_OPTION_END) {
		if (pos + 1 > len) return 0;
		if (package[pos] != DHCP_OPTION_MESSAGE_TYPE) {
			pos += package[pos+1]+2;
			continue;
		}
		if (pos + 2 > len) return 0;
		if (package[pos+2]==messageType) return 1;
		return 0;
	}
	return 0;
}
