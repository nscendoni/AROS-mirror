/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: getnetbyaddr.c 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH2(struct netent *, getnetbyaddr,

/*  SYNOPSIS */
        AROS_LHA(long, net,  D0),
        AROS_LHA(int,  type, D1),

/*  LOCATION */
        struct Library *, SocketBase, 38, BSDSocket)

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

    aros_print_not_implemented ("getnetbyaddr");
#warning TODO: Write BSDSocket/getnetbyaddr

    return NULL;

    AROS_LIBFUNC_EXIT

} /* getnetbyaddr */
