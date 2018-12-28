/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: gethostid.c 34494 2010-09-24 11:35:48Z sonic $

    Desc:
    Lang: English
*/

#include "bsdsocket_intern.h"

/*****************************************************************************

    NAME */

        AROS_LH0(long, gethostid,

/*  SYNOPSIS */

/*  LOCATION */
        struct Library *, SocketBase, 48, BSDSocket)

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

    aros_print_not_implemented ("gethostid");
#warning TODO: Write BSDSocket/gethostid

    return 0;

    AROS_LIBFUNC_EXIT

} /* gethostid */
