#   Copyright © 2011, The AROS Development Team. All rights reserved.
#   $Id: Makefile 38641 2011-05-11 06:10:02Z mazze $
#
#   Desc: Makefile for setrev
#

SRC	:= setrev.c

include $(TOP)/config/make.cfg

all : $(SETREV)

$(SETREV) : $(SRC)
	@$(MECHO) "Compiling $(notdir $@)..."
	@$(HOST_CC) $(HOST_CFLAGS) $(HOST_LDFLAGS) $< -o $@
	@$(HOST_STRIP) $@


clean:
	@$(RM) -f $(SETREV)
