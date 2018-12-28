/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: getprotobynumber.c 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH1(struct protoent *, getprotobynumber,

/*  SYNOPSIS */
        AROS_LHA(int, proto, D0),

/*  LOCATION */
        struct Library *, SocketBase, 42, BSDSocket)

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

    aros_print_not_implemented ("getprotobynumber");
#warning TODO: Write BSDSocket/getprotobynumber

    return NULL;

    AROS_LIBFUNC_EXIT

} /* getprotobynumber */
