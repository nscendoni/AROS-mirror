// debug.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef DEBUG_H
#define	DEBUG_H

//----------------------------------------------------------------------------

#define	d1(x)	;
#define	d2(x)	x;

// from debug.lib
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);

//----------------------------------------------------------------------------

struct Empty_Trashcan_LocaleInfo
{
	APTR li_LocaleBase;
	APTR li_Catalog;
	struct LocaleIFace *li_ILocale;
};

#endif /* DEBUG_H */
