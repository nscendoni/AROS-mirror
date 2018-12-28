/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: connect.c 34494 2010-09-24 11:35:48Z sonic $

    Desc:
    Lang: English
*/

#include <sys/socket.h>

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH3(int, connect,

/*  SYNOPSIS */
        AROS_LHA(int,               s,       D0),
        AROS_LHA(struct sockaddr *, name,    A0),
        AROS_LHA(int,               namelen, D1),

/*  LOCATION */
        struct Library *, SocketBase, 9, BSDSocket)

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

    aros_print_not_implemented ("connect");
#warning TODO: Write BSDSocket/connect

    return 0;

    AROS_LIBFUNC_EXIT

} /* connect */
