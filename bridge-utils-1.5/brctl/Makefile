
KERNEL_HEADERS=-I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/linux-3.4.104

CC=arm-greenwave-linux-gnueabihf-gcc
CFLAGS= -Wall -O2 -g   -I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/include -isystem /home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/thirdparty-include -march=armv7-a -mcpu=cortex-a9 -mtune=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard  
LDFLAGS=-L/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/lib -Wl,-O1 -Wl,--as-needed 
INCLUDE=-I../libbridge $(KERNEL_HEADERS) 
LIBS= -L ../libbridge -lbridge -Wl,-rpath-link=/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/lib -Wl,-L/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/lib 

prefix=
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
mandir=${prefix}/share/man

INSTALL=/usr/bin/install -c


common_SOURCES= brctl_cmd.c brctl_disp.c 
brctl_SOURCES=  brctl.c $(common_SOURCES)

common_OBJECTS= $(common_SOURCES:.c=.o)
brctl_OBJECTS= $(brctl_SOURCES:.c=.o)

OBJECTS= $(common_OBJECTS) $(brctl_OBJECTS)

PROGRAMS= brctl 


all:	$(PROGRAMS)

install: $(PROGRAMS)
	mkdir -p $(DESTDIR)$(sbindir)
	$(INSTALL) -m 755 $(PROGRAMS) $(DESTDIR)$(sbindir)

brctl:	$(brctl_OBJECTS) ../libbridge/libbridge.a
	$(CC) $(LDFLAGS) $(brctl_OBJECTS) $(LIBS) -o brctl

%.o: %.c brctl.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< 

clean:
	rm -f *.o brctl core

