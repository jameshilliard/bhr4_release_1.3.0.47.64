
DESTDIR=
KERNEL_HEADERS=-I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/linux-3.4.104

INSTALL=/usr/bin/install -c

prefix=
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
mandir=${prefix}/share/man
distdir = $(PACKAGE)-$(VERSION)

SUBDIRS=libbridge brctl doc

all:
	for x in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$x ; done

clean:
	for x in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$x clean ; done

distclean:	clean
	rm -f config.log
	rm -f config.cache
	rm -f config.status

maintainer-clean: distclean
	rm -f Makefile
	rm -f brctl/Makefile
	rm -f libbridge/Makefile
	rm -f doc/Makefile

install:
	for x in $(SUBDIRS); do $(MAKE) $(MFLAGS) -C $$x install; done

