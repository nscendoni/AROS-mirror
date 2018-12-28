#ifndef _LOCALE_H_
#define _LOCALE_H_

/*
    Copyright © 2012, The AROS Development Team. All rights reserved.
    $Id: locale.h 44805 2012-05-14 17:07:56Z mazze $
*/

#include <exec/types.h>

#define CATCOMP_NUMBERS
#include "strings.h"

/*** Prototypes *************************************************************/
/* Main *********************************************************************/
CONST_STRPTR _(ULONG ID);       /* Get a message, as a STRPTR */
#define __(id) ((IPTR) _(id))   /* Get a message, as an IPTR */

/* Setup ********************************************************************/
VOID Locale_Initialize(VOID);
VOID Locale_Deinitialize(VOID);

#endif /* _LOCALE_H_ */
