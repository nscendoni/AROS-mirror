/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: replyamigaguidemsg.c 47342 2013-05-04 10:34:30Z mazze $

    Desc: AmigaGuide function ReplyAmigaGuideMsg()
    Lang: english
*/
#include "amigaguide_intern.h"

/*****************************************************************************

    NAME */
#include <proto/amigaguide.h>

        AROS_LH1(void, ReplyAmigaGuideMsg,

/*  SYNOPSIS */
        AROS_LHA(struct AmigaGuideMsg *, msg, A0),

/*  LOCATION */
        struct Library *, AmigaGuideBase, 14, AmigaGuide)

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

    /* FIXME: amigaguide/ReplyAmigaGuideMsg() */
    aros_print_not_implemented ("amigaguide/ReplyAmigaGuideMsg");

    AROS_LIBFUNC_EXIT
} /* ReplyAmigaGuideMsg */
