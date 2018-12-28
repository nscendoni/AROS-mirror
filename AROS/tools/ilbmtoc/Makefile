#   Copyright © 1995-2001, The AROS Development Team. All rights reserved.
#   $Id: Makefile 45346 2012-07-28 13:06:08Z mazze $
#
#   Desc: Makefile for ilbmtoc
#

-include $(TOP)/config/make.cfg

USER_CFLAGS := -Wall -Wunused -O2

HOST_CC	    ?= $(CC)
HOST_STRIP  ?= strip
ILBMTOC     ?= ilbmtoc
MECHO	    ?= echo

all : $(ILBMTOC)

$(ILBMTOC) : ilbmtoc.c
	@$(MECHO) "Compiling $(notdir $@)..."
	@$(HOST_CC) $(HOST_CFLAGS) $(USER_CFLAGS) $< -o $@
	@$(HOST_STRIP) $@

clean:
	@$(RM) -f $(ILBMTOC)
