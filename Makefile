include config.mk

INC = -I. -I/usr/include
LIB =

CFLAGS = -O3 -Wall -Wextra -std=c99 -pedantic $(INC)
LDFLAGS = $(LIB)

DEFSAVE = -D SAVELOC=\"$(SAVELOC)\"

MAKE = $(CC) $(CFLAGS) $(LDFLAGS) $(DEFSAVE)

all: build

build:
	$(MAKE) tiosave.c -o tiosave
	$(MAKE) tioload.c -o tioload
	chmod +x tiosave
	chmod +x tioload

install: build
	cp tiosave $(INSTALLLOC)
	cp tioload $(INSTALLLOC)

clean:
	rm -f tiosave
	rm -f tioload
