/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: openamigaguideasynca.c 47342 2013-05-04 10:34:30Z mazze $

    Desc: AmigaGuide function OpenAmigaGuideAsyncA()
    Lang: english
*/
#include "amigaguide_intern.h"

/*****************************************************************************

    NAME */
#include <proto/amigaguide.h>

        AROS_LH2(AMIGAGUIDECONTEXT, OpenAmigaGuideAsyncA,

/*  SYNOPSIS */
        AROS_LHA(struct NewAmigaGuide *, nag, A0),
        AROS_LHA(struct TagItem *, attrs, D0),

/*  LOCATION */
        struct Library *, AmigaGuideBase, 10, AmigaGuide)

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

    /* FIXME: amigaguide/OpenAmigaGuideAsyncA() */
    aros_print_not_implemented ("amigaguide/OpenAmigaGuideAsyncA");

    return NULL;

    AROS_LIBFUNC_EXIT
} /* OpenAmigaGuideAsyncA */
