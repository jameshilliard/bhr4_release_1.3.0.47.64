
KERNEL_HEADERS=-I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/linux-3.4.104

AR=arm-greenwave-linux-gnueabihf-ar
RANLIB=arm-greenwave-linux-gnueabihf-ranlib

CC=arm-greenwave-linux-gnueabihf-gcc
CFLAGS = -Wall -g $(KERNEL_HEADERS)

prefix=
exec_prefix=${prefix}
includedir=${prefix}/include
libdir=${exec_prefix}/lib

libbridge_SOURCES= \
	libbridge_devif.c \
	libbridge_if.c \
	libbridge_init.c \
	libbridge_misc.c 

libbridge_OBJECTS=$(libbridge_SOURCES:.c=.o)

all:	libbridge.a

# At present there is no need for a bridge-utils-devel package
install:


clean:
	rm -f *.o libbridge.a

libbridge.a:	$(libbridge_OBJECTS)
	$(AR) rcs $@ $(libbridge_OBJECTS)
	$(RANLIB) $@

%.o: %.c libbridge.h libbridge_private.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

libbridge_compat.o:	libbridge_compat.c if_index.c
	$(CC) $(CFLAGS) -c libbridge_compat.c

