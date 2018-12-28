#ifndef _LOCALE_H
#define _LOCALE_H

/*
    Copyright © 2003-2004, The AROS Development Team. All rights reserved.
    $Id: locale.h 30792 2009-03-07 22:40:04Z neil $
*/

#include <exec/types.h>

#define CATCOMP_NUMBERS
#include "strings.h"

/*** Prototypes *************************************************************/
/* Main *********************************************************************/
CONST_STRPTR MSG(ULONG id);

/* Setup ********************************************************************/
VOID Locale_Initialize(VOID);
VOID Locale_Deinitialize(VOID);

#endif /* _LOCALE_H */
