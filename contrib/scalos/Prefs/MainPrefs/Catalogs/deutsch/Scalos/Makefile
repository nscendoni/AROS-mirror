# makefile for Scalos_Prefs (translated Texts : deutsch)
# $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $

.SUFFIXES: .ct .catalog

.ct.catalog :
	@printf '\033[32mMake catalog: \033[31m\033[1mdeutsch\033[0m\n'
	CatComp ///$*.cd $*.ct CATALOG $*.catalog VB=2
	avail flush

Scalos_Prefs.catalog : Scalos_Prefs.ct ../../../Scalos_Prefs.cd

All: Scalos_Prefs.catalog
