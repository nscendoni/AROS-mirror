/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: getamigaguidestring.c 47342 2013-05-04 10:34:30Z mazze $

    Desc: AmigaGuide function GetAmigaGuideString()
    Lang: english
*/
#include "amigaguide_intern.h"

/*****************************************************************************

    NAME */
#include <proto/amigaguide.h>

        AROS_LH1(STRPTR, GetAmigaGuideString,

/*  SYNOPSIS */
        AROS_LHA(ULONG, id, D0),

/*  LOCATION */
        struct Library *, AmigaGuideBase, 35, AmigaGuide)

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

    /* FIXME: amigaguide/GetAmigaGuideString() */
    aros_print_not_implemented ("amigaguide/GetAmigaGuideString");

    return NULL;

    AROS_LIBFUNC_EXIT
} /* GetAmigaGuideString */
