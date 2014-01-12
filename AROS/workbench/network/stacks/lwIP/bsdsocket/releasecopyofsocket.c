/*
    Copyright � 2000-2010, The AROS Development Team. All rights reserved.
    $Id$

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH2(LONG, ReleaseCopyOfSocket,

/*  SYNOPSIS */
        AROS_LHA(LONG, sd, D0),
        AROS_LHA(LONG, id, D1),

/*  LOCATION */
        struct bsdsocketBase *, bsdsocketBase, 26, BSDSocket)

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

    int ns;

    ns = bsd_socket_dup2(bsdsocketBase->bsd, sd, -1);
    return bsd_socket_release(bsdsocketBase->bsd, ns, id);

    AROS_LIBFUNC_EXIT

} /* ReleaseCopyOfSocket */
