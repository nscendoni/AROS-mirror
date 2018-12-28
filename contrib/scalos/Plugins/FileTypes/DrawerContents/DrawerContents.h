// DrawerContents.h
// $Date: 2013-12-17 00:38:36 +0100 (Tue, 17 Dec 2013) $
// $Revision: 48586 $

#ifndef DRAWERCONTENTS_H
#define DRAWERCONTENTS_H

int DrawerContentsInit(struct DrawerContentsBase *DrawerContentsBase);
int DrawerContentsOpen(struct DrawerContentsBase *DrawerContentsBase);
void DrawerContentsCleanup(struct DrawerContentsBase *DrawerContentsBase);
LIBFUNC_P3_PROTO(STRPTR, LIBToolTipInfoString,
	A0, struct ScaToolTipInfoHookData *, ttshd,
	A1, CONST_STRPTR, args,
	A6, struct DrawerContentsBase *, DrawerContentsBase, 5);

//---------------------------------------------------------------

// Debugging...
#define	d(x)	;
#define	d1(x)	;
#define	d2(x)	x;

// aus debug.lib
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);

struct DrawerContentsPlugin_LocaleInfo
{
	APTR li_LocaleBase;
	APTR li_Catalog;
	struct LocaleIFace *li_ILocale;
};

#endif /* DRAWERCONTENTS_H */

