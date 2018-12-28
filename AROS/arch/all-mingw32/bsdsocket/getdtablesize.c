/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: getdtablesize.c 34530 2010-09-28 10:50:58Z sonic $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH0(int, getdtablesize,

/*  SYNOPSIS */

/*  LOCATION */
        struct TaskBase *, taskBase, 23, BSDSocket)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    return taskBase->dTableSize;

    AROS_LIBFUNC_EXIT

} /* getdtablesize */
