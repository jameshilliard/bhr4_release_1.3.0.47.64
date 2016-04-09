
DESTDIR=
KERNEL_HEADERS=-I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/linux-3.4.104

INSTALL=/usr/bin/install -c

prefix=
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
mandir=${prefix}/share/man

SUBDIRS=libbridge brctl

all:

clean:

install:
	mkdir -p $(DESTDIR)$(mandir)/man8
	$(INSTALL) -m 644 brctl.8 $(DESTDIR)$(mandir)/man8
