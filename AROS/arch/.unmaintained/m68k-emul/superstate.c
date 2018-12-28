/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: superstate.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Switch CPU in supervisor state (if supported)
    Lang: english
*/

/******************************************************************************

    NAME */
#include <proto/exec.h>

	AROS_LH0(void, SuperState,

/*  LOCATION */
	struct ExecBase *, SysBase, 25, Exec)

/*  FUNCTION
	If the CPU supports this, this function activates the supervisor
	mode.

    INPUTS
	None.

    RESULT
	None.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

******************************************************************************/
{
} /* SuperState */

