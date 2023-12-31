# SPDX-License-Identifier: BSD-3-Clause

top ?= $(abspath ../..)
ifneq ($(CC),)
HOSTCC ?= $(CC)
else
HOSTCC ?= cc
endif

READ_SRC = amdfwread.c
READ_OBJ = $(READ_SRC:%.c=%.o)
TOOL_SRC = amdfwtool.c data_parse.c signed_psp.c handle_file.c
TOOL_OBJ = $(TOOL_SRC:%.c=%.o)
HEADER=amdfwtool.h
TARGETS = amdfwread amdfwtool
WERROR=-Werror
CFLAGS=-O2 -Wall -Wextra -Wshadow ${WERROR}
CFLAGS += -I $(top)/src/commonlib/bsd/include
CFLAGS += -D_GNU_SOURCE # memmem() from string.h

ifneq ($(PKG_CONFIG),)
HOSTPKGCONFIG ?= $(PKG_CONFIG)
else
HOSTPKGCONFIG ?= pkg-config
endif
CFLAGS += $(shell $(HOSTPKGCONFIG) --cflags libcrypto)
LDFLAGS += $(shell $(HOSTPKGCONFIG) --libs libcrypto)

all: $(TARGETS)

amdfwread: $(READ_OBJ)
	$(HOSTCC) $(READ_OBJ) $(LDFLAGS) -o $@

amdfwtool: $(TOOL_OBJ)
	$(HOSTCC) $(TOOL_OBJ) $(LDFLAGS) -o $@

%.o: %.c $(HEADER)
	$(HOSTCC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(TARGETS) $(READ_OBJ) $(TOOL_OBJ)

distclean: clean

help:
	@echo "${TARGETS}: Tools to create and read from AMD firmware combinations"
	@echo "Targets: all, clean, distclean, help"
	@echo "To disable warnings as errors, run make as:"
	@echo "  make all WERROR=\"\""

.PHONY: all clean distclean help
