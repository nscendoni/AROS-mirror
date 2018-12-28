// locale.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef LOCALE_H
#define LOCALE_H

struct Scalos_LocaleInfo
{
	APTR li_LocaleBase;
	APTR li_Catalog;
	struct LocaleIFace *li_ILocale;
};

CONST_STRPTR      GetLocString(LONG lStrnum);

#define	Scalos_NUMBERS
#include STR(SCALOSLOCALE)


#endif

