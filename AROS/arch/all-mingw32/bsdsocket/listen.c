/*
    Copyright © 2000-2010, The AROS Development Team. All rights reserved.
    $Id: listen.c 34494 2010-09-24 11:35:48Z sonic $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH2(int, listen,

/*  SYNOPSIS */
        AROS_LHA(int, s,       D0),
        AROS_LHA(int, backlog, D1),

/*  LOCATION */
        struct Library *, SocketBase, 7, BSDSocket)

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

    aros_print_not_implemented ("listen");
#warning TODO: Write BSDSocket/listen

    return 0;

    AROS_LIBFUNC_EXIT

} /* listen */
