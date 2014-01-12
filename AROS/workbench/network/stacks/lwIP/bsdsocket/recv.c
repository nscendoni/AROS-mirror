/*
    Copyright � 2000-2010, The AROS Development Team. All rights reserved.
    $Id$

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH4(int, recv,

/*  SYNOPSIS */
        AROS_LHA(int,    s,     D0),
        AROS_LHA(void *, buf,   A0),
        AROS_LHA(int,    len,   D1),
        AROS_LHA(int,    flags, D2),

/*  LOCATION */
        struct bsdsocketBase *, bsdsocketBase, 13, BSDSocket)

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

    return bsd_recv(bsdsocketBase->bsd, s, buf, len, flags);

    AROS_LIBFUNC_EXIT

} /* recv */
