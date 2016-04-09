include $(top_srcdir)/Make_global.am
lib_LTLIBRARIES = libnetfilter_acct.la

libnetfilter_acct_la_LIBADD = ${LIBMNL_LIBS}
libnetfilter_acct_la_LDFLAGS = -Wl,--version-script=$(srcdir)/libnetfilter_acct.map -version-info $(LIBVERSION)
libnetfilter_acct_la_SOURCES = libnetfilter_acct.c	\
			       libnetfilter_acct.map	\
			       internal.h
