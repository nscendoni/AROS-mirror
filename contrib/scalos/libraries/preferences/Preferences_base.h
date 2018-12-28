// Preferences_base.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef PREFERENCESBASE_H
#define	PREFERENCESBASE_H

#include <exec/types.h>
#include <exec/lists.h>
#include <exec/libraries.h>


struct PreferencesBase
{
	struct Library prb_LibNode;

	struct SegList *prb_SegList;

	BOOL prb_Initialized;

	struct SignalSemaphore prb_MemPoolSemaphore;
	APTR prb_MemPool;

	struct SignalSemaphore prb_PrefsListSem;
	struct List prb_PrefsList;
};

//----------------------------------------------------------------------------

// Debugging...
#define	d(x)	;
#define	d1(x)	;
#define	d2(x)	x;


// aus debug.lib
#ifdef __AROS__
#include <clib/arossupport_protos.h>
#define KPrintF kprintf
#else
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);
#endif

//----------------------------------------------------------------------------

#endif /* PREFERENCESBASE_H */
