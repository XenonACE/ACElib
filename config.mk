# libACE Version
VERSION = 0.1.0

# Default Compiler
CC = gcc

PREFIX=/usr
LIBPREFIX=$(PREFIX)/lib
INCLUDEPREFIX=$(PREFIX)/include

CFLAGS = -Wall -Wextra -Iinclude -DVERSION=\"$(VERSION)\"
