/*
    Copyright © 2002-2007, The AROS Development Team. All rights reserved.
    $Id: mui_error.c 45710 2012-08-31 19:01:54Z neil $
*/

#include <proto/muimaster.h>
#include "muimaster_intern.h"

/*****************************************************************************

    NAME */
        AROS_LH0(LONG, MUI_Error,

/*  SYNOPSIS */

/*  LOCATION */
        struct Library *, MUIMasterBase, 11, MUIMaster)

/*  FUNCTION
        Obsolete function. Use SetIoErr()/IoErr() instead.

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        MUI_SetError()

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    return 0;

    AROS_LIBFUNC_EXIT

} /* MUIA_Error */
