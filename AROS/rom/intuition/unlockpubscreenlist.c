/*
    Copyright � 1995-2013, The AROS Development Team. All rights reserved.
    Copyright � 2001-2003, The MorphOS Development Team. All Rights Reserved.
    $Id: unlockpubscreenlist.c 48422 2013-11-17 16:07:33Z neil $
*/

#include "intuition_intern.h"

/*****************************************************************************
 
    NAME */
#include <proto/intuition.h>

        AROS_LH0(VOID, UnlockPubScreenList,

/*  SYNOPSIS */

/*  LOCATION */
        struct IntuitionBase *, IntuitionBase, 88, Intuition)

/*  FUNCTION
        Release lock made by LockPubScreenList().

    INPUTS
        None.

    RESULT
        None.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        LockPubScreenList()

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    DEBUG_UNLOCKPUBSCREENLIST(dprintf("UnLockPubScreenList: <%s>\n",
                                      FindTask(NULL)->tc_Node.ln_Name));

    ReleaseSemaphore(&GetPrivIBase(IntuitionBase)->PubScrListLock);

    DEBUG_UNLOCKPUBSCREENLIST(dprintf("UnLockPubScreenList: done\n"));

    AROS_LIBFUNC_EXIT
} /* UnlockPubScreenList */

