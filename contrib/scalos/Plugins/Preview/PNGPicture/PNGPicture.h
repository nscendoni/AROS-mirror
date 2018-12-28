// PNGPicture.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef PNGPICTURE_H
#define PNGPICTURE_H

//---------------------------------------------------------------

#include "plugin.h"

//---------------------------------------------------------------

// Debugging...
#define	d(x)	;
#define	d1(x)	;
#define	d2(x)	x;

// aus debug.lib
extern int kprintf(const char *fmt, ...);
extern int KPrintF(const char *fmt, ...);

//---------------------------------------------------------------

#define	MEMPOOL_MEMFLAGS	MEMF_ANY
#define	MEMPOOL_PUDDLESIZE	32768
#define	MEMPOOL_THRESHSIZE	8192

//-----------------------------------------------------------------------------
// defined in  mempools.lib

#ifndef __amigaos4__
extern int _STI_240_InitMemFunctions(void);
extern void _STD_240_TerminateMemFunctions(void);
#endif

//----------------------------------------------------------------------------

#endif /* PNGPICTURE_H */

