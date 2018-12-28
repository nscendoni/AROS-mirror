/*
** libfuncs.h
 *
 * $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
 * $Revision: 48481 $
 *
** 20th May 2000
** David McMinn
** Defines the prototypes for the only public function in the plugin
*/

#ifndef LIBFUNCS_H
#define LIBFUNCS_H

#include <scalos/scalos.h>

#include "defs.h"
#include "libbase.h"

LIBFUNC_PROTO(GetClassInfo, libbase, struct ScaClassInfo *);

BOOL UserLibInit(struct myLibBase *myLibBase);
void UserLibCleanup(struct myLibBase *myLibBase);

extern struct myLibBase *globalLibBase;

#define	d1(x)		;
#define	d2(x)		x;

extern int KPrintF(CONST_STRPTR fmt, ...);
extern int kprintf(CONST_STRPTR fmt, ...);

#endif

