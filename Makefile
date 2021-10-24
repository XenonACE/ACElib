# Xenon API

include config.mk

SOURCES = src/flow.c src/api.c
OBJECTS = $(SOURCES:.c=.o)

all: libace

.c.o:
	$(CC) -c $(CFLAGS) -o $@ -c -fpic $^

libace: $(OBJECTS)
	$(CC) -shared -o $@.so $(CFLAGS) $(OBJECTS)

.PHONY: install clean

install: libace
	cp -f libace.so $(LIBPREFIX)
	cp -f include/ACE.h $(INCLUDEPREFIX)
	cp -f ./ACE.pc /usr/share/pkgconfig/

clean:
	rm -rf libace.so $(OBJECTS)
