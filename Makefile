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
	mkdir -p $(DESTDIR)$(PREFIX)
	mkdir -p $(DESTDIR)$(INCLUDEPREFIX)
	mkdir -p $(DESTDIR)/usr/share/pkgconfig
	cp -f libace.so $(DESTDIR)$(PREFIX)
	cp -f include/ACE.h $(DESTDIR)$(INCLUDEPREFIX)
	cp -f ./ACE.pc $(DESTDIR)/usr/share/pkgconfig

clean:
	rm -rf libace.so $(OBJECTS)
