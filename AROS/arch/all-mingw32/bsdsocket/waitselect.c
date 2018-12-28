/*
    Copyright © 2000-2010, The AROS Development Team. All rights reserved.
    $Id: waitselect.c 34494 2010-09-24 11:35:48Z sonic $

    Desc:
    Lang: English
*/

#include <devices/timer.h>

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH6(int, WaitSelect,

/*  SYNOPSIS */
        AROS_LHA(int,              nfds,      D0),
        AROS_LHA(fd_set *,         readfds,   A0),
        AROS_LHA(fd_set *,         writefds,  A1),
        AROS_LHA(fd_set *,         exceptfds, A2),
        AROS_LHA(struct timeval *, timeout,   A3),
        AROS_LHA(ULONG *,          sigmask,   D1),

/*  LOCATION */
        struct Library *, SocketBase, 21, BSDSocket)

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

    aros_print_not_implemented ("WaitSelect");
#warning TODO: Write BSDSocket/WaitSelect

    return 0;

    AROS_LIBFUNC_EXIT

} /* WaitSelect */
