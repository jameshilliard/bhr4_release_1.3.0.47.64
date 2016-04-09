#

PREFIX=
exec_prefix=${prefix}
ETCDIR=${prefix}/etc
BINDIR=${exec_prefix}/sbin

ULOGD_CONFIGFILE=${prefix}/etc/ulogd.conf

ULOGD_LIB_PATH=${exec_prefix}/lib/ulogd

# Path of libipulog (from iptables)
LIBIPULOG=./libipulog
INCIPULOG=-I./libipulog/include
INCCONFFILE=-I./conffile

CC=arm-greenwave-linux-gnueabihf-gcc
LD=/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/toolchains/arm-cortex-a9_linaro-gcc47/arm-greenwave-linux-gnueabihf/bin/ld
INSTALL=/usr/bin/install -c

CFLAGS=-O2 -g   -I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/include -isystem /home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/thirdparty-include -march=armv7-a -mcpu=cortex-a9 -mtune=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard   -O2 -g   -I/home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/include -isystem /home/jenkins/slave/workspace/BHR4_Release_Build_FiOS1.3_PROD/output/bhr4/thirdparty-include -march=armv7-a -mcpu=cortex-a9 -mtune=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard   -Wall
CFLAGS+=-DULOGD_CONFIGFILE=\"$(ULOGD_CONFIGFILE)\"
# doesn't work for subdirs
#CFLAGS+=$(INCIPULOG) $(INCCONFFILE)
CFLAGS+=-I/lib/modules/`uname -r`/build/include
#CFLAGS+=-DHAVE_CONFIG_H
#CFLAGS+=-g -DDEBUG -DDEBUG_MYSQL -DDEBUG_PGSQL

LIBS=


# Names of the plugins to be compiled
ULOGD_SL:=BASE OPRINT PWSNIFF LOGEMU LOCAL SYSLOG

# mysql output support
#ULOGD_SL+=MYSQL
MYSQL_CFLAGS=-I@MYSQLINCLUDES@ @EXTRA_MYSQL_DEF@
MYSQL_LDFLAGS=@DATABASE_LIB_DIR@ 

# postgreSQL output support
#ULOGD_SL+=PGSQL
PGSQL_CFLAGS=-I@PGSQLINCLUDES@ @EXTRA_PGSQL_DEF@
PGSQL_LDFLAGS=@DATABASE_LIB_DIR@ @PGSQL_LIB@
