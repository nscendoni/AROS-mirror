/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: gethostbyaddr.c 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH3(struct hostent *, gethostbyaddr,

/*  SYNOPSIS */
        AROS_LHA(char *, addr, A0),
        AROS_LHA(int,    len,  D0),
        AROS_LHA(int,    type, D1),

/*  LOCATION */
        struct Library *, SocketBase, 36, BSDSocket)

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

    aros_print_not_implemented ("gethostbyaddr");
#warning TODO: Write BSDSocket/gethostbyaddr

    return NULL;

    AROS_LIBFUNC_EXIT

} /* gethostbyaddr */
