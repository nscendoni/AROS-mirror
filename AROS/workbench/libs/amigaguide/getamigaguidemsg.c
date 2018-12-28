/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: getamigaguidemsg.c 47342 2013-05-04 10:34:30Z mazze $

    Desc: AmigaGuide function GetAmigaGuideMsg()
    Lang: english
*/
#include "amigaguide_intern.h"

/*****************************************************************************

    NAME */
#include <proto/amigaguide.h>

        AROS_LH1(struct AmigaGuideMsg *, GetAmigaGuideMsg,

/*  SYNOPSIS */
        AROS_LHA(AMIGAGUIDECONTEXT, handle, A0),

/*  LOCATION */
        struct Library *, AmigaGuideBase, 13, AmigaGuide)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS
        This function is unimplemented.

    SEE ALSO

    INTERNALS

    HISTORY


******************************************************************************/
{
    AROS_LIBFUNC_INIT

    /* FIXME: amigaguide/GetAmigaGuideMsg() */
    aros_print_not_implemented ("amigaguide/GetAmigaGuideMsg");

    return NULL;

    AROS_LIBFUNC_EXIT
} /* GetAmigaGuideMsg */
