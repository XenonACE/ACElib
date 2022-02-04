# libACE Version
VERSION = 0.1.0

# Default Compiler
CC = gcc

PREFIX=/usr/lib
INCLUDEPREFIX=/usr/include

CFLAGS = -Wall -Wextra -Iinclude -lX11 -DVERSION=\"$(VERSION)\"
