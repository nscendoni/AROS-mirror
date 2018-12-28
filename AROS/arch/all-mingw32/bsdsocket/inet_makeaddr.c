/*
    Copyright © 2000-2010, The AROS Development Team. All rights reserved.
    $Id: inet_makeaddr.c 34494 2010-09-24 11:35:48Z sonic $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH2(unsigned long, Inet_MakeAddr,

/*  SYNOPSIS */
        AROS_LHA(int, net, D0),
        AROS_LHA(int, lna, D1),

/*  LOCATION */
        struct Library *, SocketBase, 33, BSDSocket)

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

    aros_print_not_implemented ("Inet_MakeAddr");
#warning TODO: Write BSDSocket/Inet_MakeAddr

    return 0;

    AROS_LIBFUNC_EXIT

} /* Inet_MakeAddr */
