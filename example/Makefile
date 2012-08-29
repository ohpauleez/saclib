# =========================
#  Makefile for the example
# =========================

INCLUDES = -I${saclib}/include
CFLAGS  = -O -I${saclib}/include
CFLAGSD  = -g
LDFLAGS = -O
LDFLAGSD = -g
LIB = ${saclib}/lib/saclibo.a
LIBD = ${saclib}/lib/saclibd.a

all: ipfac itime simple

ipfac: ipfac.c
	${CC} $(CFLAGS) $(LDFLAGS) ipfac.c $(LIB) -o ipfac

ipfacd: ipfac.c
	${CC} $(CFLAGSD) $(LDFLAGSD) ${INCLUDES} ipfac.c $(LIBD) -o ipfacd

itime: itime.c
	${CC} $(CFLAGS) $(LDFLAGS) itime.c $(LIB) -o itime

power: power.c
	${CC} $(CFLAGS) $(LDFLAGS) power.c $(LIB) -o power

product: product.c
	${CC} $(CFLAGS) $(LDFLAGS) product.c $(LIB) -o product

simple: simple.c
	${CC} $(CFLAGS) $(LDFLAGS) simple.c $(LIB) -o simple

ftest: ftest.c
	${CC} $(CFLAGS) $(LDFLAGS) ftest.c $(LIB) -o ftest

ftestd: ftest.c
	${CC} -g  -I${saclib}/include ftest.c $(LIBD) -o ftestd

Test: Test.c
	${CC} $(CFLAGS) $(LDFLAGS) ow.c Test.c $(LIB) -o Test

Testd: Test.c
	${CC} -g  -I${saclib}/include ow.c Test.c $(LIBD) -o Testd
