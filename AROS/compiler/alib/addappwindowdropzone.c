/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: addappwindowdropzone.c 45368 2012-08-01 16:42:02Z neil $

    Desc: Varargs version of workbench.library/AddAppWindowDropZoneA()
    Lang: english
*/
#define AROS_TAGRETURNTYPE struct AppWindowDropZone *
#include <dos/bptr.h>
#include <utility/tagitem.h>

/*****************************************************************************

    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/workbench.h>

        struct AppWindowDropZone * AddAppWindowDropZone(

/*  SYNOPSIS */
        struct AppWindow * aw,
        IPTR               id,
        IPTR               userdata,
        Tag                tag1,
        ...)

/*  FUNCTION
        This is the varargs version of workbench.library/AddAppWindowDropZoneA().
        For information see workbench.library/AddAppWindowDropZoneA().

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        workbench.library/AddAppWindowDropZoneA()

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_SLOWSTACKTAGS_PRE(tag1)
    retval = AddAppWindowDropZoneA( aw, id, userdata, AROS_SLOWSTACKTAGS_ARG(tag1));
    AROS_SLOWSTACKTAGS_POST
} /* AddAppWindowDropZone */
