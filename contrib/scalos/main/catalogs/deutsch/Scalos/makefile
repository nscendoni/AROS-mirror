# makefile for Scalos (translated Texts deutsch)
# $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
# $Revision: 48481 $

.SUFFIXES: .ct .catalog

all: scalos.catalog

scalos.catalog : scalos.ct ../../../scalos.cd
	@printf '\033[32mMake catalog: \033[31m\033[1mdeutsch \033[0m\n'
	CatComp ///scalos.cd scalos.ct CATALOG $@ VB=2
	avail flush
