/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: getamigaguideattr.c 47342 2013-05-04 10:34:30Z mazze $

    Desc: AmigaGuide function GetAmigaGuideAttr()
    Lang: english
*/
#include "amigaguide_intern.h"

/*****************************************************************************

    NAME */
#include <proto/amigaguide.h>

        AROS_LH3(LONG, GetAmigaGuideAttr,

/*  SYNOPSIS */
        AROS_LHA(Tag, tag, D0),
        AROS_LHA(AMIGAGUIDECONTEXT, handle, A0),
        AROS_LHA(ULONG *, storage, A1),

/*  LOCATION */
        struct Library *, AmigaGuideBase, 19, AmigaGuide)

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

    /* FIXME: amigaguide/GetAmigaGuideAttr() */
    aros_print_not_implemented ("amigaguide/GetAmigaGuideAttr");

    return 0;

    AROS_LIBFUNC_EXIT
} /* GetAmigaGuideAttr */
