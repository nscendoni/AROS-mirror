#ifndef _LOCALE_H_
#define _LOCALE_H_

/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: locale.h 48674 2014-01-02 17:51:04Z neil $
*/

#include <exec/types.h>

#define CATCOMP_NUMBERS
#include "strings.h"

/*** Prototypes *************************************************************/
/* Main *********************************************************************/
CONST_STRPTR _(LONG ID);       /* Get a message, as a STRPTR */
#define __(id) ((IPTR) _(id))   /* Get a message, as an IPTR */

/* Setup ********************************************************************/
VOID Locale_Initialize(VOID);
VOID Locale_Deinitialize(VOID);

#endif /* _LOCALE_H_ */
