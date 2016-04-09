#ifndef INTERNAL_H
#define INTERNAL_H 1

#include "config.h"
#ifdef HAVE_VISIBILITY_HIDDEN
#	define __visible	__attribute__((visibility("default")))
#	define EXPORT_SYMBOL(x)	typeof(x) (x) __visible
#else
#	define EXPORT_SYMBOL
#endif

#include <endian.h>
#if !defined(htobe64)
#	include <byteswap.h>
#	if __BYTE_ORDER == __LITTLE_ENDIAN
#		define htobe64(x) __bswap_64(x)
#		define betoh64(x) __bswap_64(x)
#	else
#		define htobe64(x) (x)
#		define betoh64(x) (x)
#	endif
#endif

#endif
