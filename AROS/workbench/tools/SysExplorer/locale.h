#ifndef _LOCALE_H
#define _LOCALE_H

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: locale.h 48674 2014-01-02 17:51:04Z neil $
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
