/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: freehpetunit.c 49667 2014-09-30 17:35:27Z neil $
*/

#include "hpet_intern.h"

/*****************************************************************************

    NAME */
#include <proto/hpet.h>

	AROS_LH1(void, FreeHPETUnit,

/*  SYNOPSIS */
	AROS_LHA(ULONG, unit, D0),

/*  LOCATION */
	struct HPETBase *, base, 3, Hpet)

/*  FUNCTION
	Free the specified HPET unit.

    INPUTS
	unit - a number of previously allocated HPET unit.

    RESULT
    	None.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    AROS_LIBFUNC_INIT

    /* Very simple. Even don't need a semaphore. */
    base->units[unit].Owner = NULL;

    AROS_LIBFUNC_EXIT
}
