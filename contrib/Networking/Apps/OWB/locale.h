#ifndef _LOCALE_H_
#define _LOCALE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: locale.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>

#define CATCOMP_NUMBERS
#include "strings.h"

CONST_STRPTR _(ULONG ID);       /* Get a message, as a STRPTR */
#define __(id) ((IPTR) _(id))   /* Get a message, as an IPTR */

VOID Locale_Initialize(VOID);
VOID Locale_Deinitialize(VOID);

#endif /* _LOCALE_H_ */
