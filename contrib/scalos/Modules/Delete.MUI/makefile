# makefile for Scalos delete.MUI module
# $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $

#############################################################

SUBDIRS =	Source \

#############################################################

.PHONY: All install clean

#############################################################

All:
	@for name in $(SUBDIRS) ; do \
		$(MAKE) -s --directory=$$name; \
	done

#############################################################

install:
	@for name in $(SUBDIRS) ; do \
		$(MAKE) -s install --directory=$$name; \
	done

#############################################################

clean:
	@for name in $(SUBDIRS) ; do \
		$(MAKE) -s clean --directory=$$name; \
	done

#############################################################
