/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: unlockcamd.c 30792 2009-03-07 22:40:04Z neil $

    Desc: 
    Lang: English
*/

#include <proto/exec.h>

#include "camd_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH1(void, UnlockCAMD,

/*  SYNOPSIS */
	AROS_LHA(APTR, lock, A0),

/*  LOCATION */
	struct CamdBase *, CamdBase, 6, Camd)

/*  FUNCTION
		UnLocks the internal lists in camd.

    INPUTS
		Pointer received from LockCAMD.

    RESULT
		APTR to send to UnlockCAMD

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
		LockCAMD()

    INTERNALS

    HISTORY

	2001-01-12 ksvalast first created

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

	ReleaseSemaphore((struct SignalSemaphore *)lock);

   AROS_LIBFUNC_EXIT
}



