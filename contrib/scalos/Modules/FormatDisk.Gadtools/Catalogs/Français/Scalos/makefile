# makefile for FormatDisk.ct (translated Texts : français)
# $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
# $Revision: 48481 $
# $Id: makefile 48481 2013-12-01 22:08:26Z mazze $

.SUFFIXES: .ct .catalog

.ct.catalog :
	@printf '\033[32mMake catalog: \033[31m\033[1mfrançais\033[0m\n'
	CatComp ///$*.cd $*.ct CATALOG $*.catalog VB=2
	avail flush

FormatDisk.catalog : FormatDisk.ct ../../../FormatDisk.cd

All: FormatDisk.catalog 
