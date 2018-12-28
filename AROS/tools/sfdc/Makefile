# Copyright © 2003, The AROS Development Team. All rights reserved.
# $Id: Makefile 50042 2015-02-06 21:51:25Z NicJA $

include $(TOP)/config/make.cfg

MAIN		= main.pl
CLASSES		= $(wildcard [A-Z]*.pl)
PODS		= SFDCompile.pod

all : $(SFDC)

$(SFDC) : $(MAIN) $(CLASSES) $(PODS)
	@cat $^ | $(SED) "s/SFDC_VERSION/$(VERSION)/g" | $(SED) "s/SFDC_DATE/$(DATE)/g" >$@
	@$(CHMOD) a+x $@
	
clean:
	@$(RM) -f $(SFDC)
