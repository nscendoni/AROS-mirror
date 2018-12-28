// sqlite3_base.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef SQLITE3BASE_H
#define SQLITE3BASE_H

#include <exec/types.h>
#include <exec/lists.h>
#include <exec/libraries.h>
#include <devices/timer.h>
#include <scalos/scalos.h>


struct SQLite3Base
{
	struct Library sql3_LibNode;

	struct SegList *sql3_SegList;

	BOOL sql3_Initialized;
	BOOL sql3_SemaAdded;

	T_TIMEREQUEST *sql3_TimerIO;
};

//----------------------------------------------------------------------------

// Debugging...
#define	d(x)	;
#define	d1(x)	;
#ifdef NDEBUG
#define	d2(x)	;
#else
#define	d2(x)	x;
#endif

// aus debug.lib
#ifdef __AROS__
#include <clib/arossupport_protos.h>
#define KPrintF kprintf
#else
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);
#endif

//----------------------------------------------------------------------------

#endif /* SQLITE3BASE_H */
