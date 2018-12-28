#ifndef _LOCALE_H
#define _LOCALE_H

/*
    Copyright © 2003-2006 AROS Development Team. All rights reserved.
    $Id: locale.h 51542 2016-02-25 19:05:51Z mazze $
*/

#include <exec/types.h>

#define CATCOMP_NUMBERS
#include "strings.h"

/*** Prototypes *************************************************************/
/* Main *********************************************************************/
STRPTR  _(ULONG ID);            /* Get a message, as a STRPTR */
#define __(id) ((IPTR) _(id))   /* Get a message, as an IPTR */

/* Setup ********************************************************************/
BOOL Locale_Initialize(void);
void Locale_Deinitialize(void);

#endif /* _LOCALE_H */
