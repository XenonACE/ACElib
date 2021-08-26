include config.mk

SOURCES = src/app.c src/api.c
OBJECTS = $(SOURCES:.c=.o)

all: acelib

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c -fPIC $<

acelib: $(OBJECTS)
	$(CC) -shared -o $@.so $(CPPFLAGS) $(CFLAGS) $(OBJECTS)

.PHONY: clean install

clean:
	rm -f acelib.so $(OBJECTS)

install: acelib
	cp -f acelib.so /usr/local/lib
	cp -f include/ACE.h /usr/local/include
	cp -f ./ACE.pc /usr/share/pkgconfig/
