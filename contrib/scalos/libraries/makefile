# makefile f�r Scalos IconObject library (C-Version)
# $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
# $Revision: 48481 $
# $Id: makefile 48481 2013-12-01 22:08:26Z mazze $

#############################################################

SUBDIRS =	preferences 	\
		sqlite		\
		scalosgfx 	\
                iconobject 	\
                popupmenu	\

#############################################################

.PHONY: All install clean

#############################################################

define build_subdir
$(MAKE) -s --directory=$(1);
endef

define install_subdir
$(MAKE) -s install --directory=$(1);
endef

define clean_subdir
$(MAKE) -s clean --directory=$(1);
endef

#############################################################

all:
	@$(foreach subdir,$(SUBDIRS),$(call build_subdir,$(subdir)))

#############################################################

install:
	@$(foreach subdir,$(SUBDIRS),$(call install_subdir,$(subdir)))

#############################################################

clean:
	@$(foreach subdir,$(SUBDIRS),$(call clean_subdir,$(subdir)))

#############################################################
