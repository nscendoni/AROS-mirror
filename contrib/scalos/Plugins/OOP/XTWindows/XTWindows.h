// XTWindows.h
// $Date: 2013-12-20 19:19:18 +0100 (Fri, 20 Dec 2013) $
// $Revision: 48601 $

#ifndef	XTWINDOWS_H_INCLUDED
#define	XTWINDOWS_H_INCLUDED

#include <scalos/scalos.h>

#include "plugin.h"

#if defined(__GNUC__) && !defined(mc68000)
#pragma pack(2)
#endif /* __GNUC__ */

struct XTWindowsBase
{
	struct PluginBase xtw_PluginBase;
	struct ScaClassInfo pl_ClassInfo;
};

#if defined(__GNUC__) && !defined(mc68000)
#pragma pack()
#endif /* __GNUC__ */

BOOL initPlugin(struct PluginBase *base);
BOOL closePlugin(struct PluginBase *base);

/* ------------------------------------------------- */

struct XTWindowsInstanceData
	{
	struct ScaWindowTask *windowTask;
	};

/* ------------------------------------------------- */

// from debug.lib
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);


#define	d1(x)		;
#define	d2(x)		{ Forbid(); x; Permit(); }

/* ------------------------------------------------- */

#endif /* XTWINDOWS_H_INCLUDED */
