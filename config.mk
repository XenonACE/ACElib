# ACElib Version
VERSION = 0.1.0

# Default Compiler
CC = tcc

PKG_CONFIG = pkg-config

# Includes and libs
INCS = -Iinclude \
       `$(PKG_CONFIG) gtk+-3.0 --cflags`
LIBS = `$(PKG_CONFIG) gtk+-3.0 --libs`

# Flags
CPPFLAGS = -Wall -Wextra -DVERSION=\"$(VERSION)\" $(INCS)
CFLAGS = $(LIBS)
