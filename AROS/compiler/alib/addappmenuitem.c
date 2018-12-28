/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: addappmenuitem.c 45368 2012-08-01 16:42:02Z neil $

    Desc: Varargs version of workbench.library/AddAppMenuItemA()
    Lang: english
*/
#define AROS_TAGRETURNTYPE struct AppMenuItem *
#include <utility/tagitem.h>

/*****************************************************************************

    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/workbench.h>

	struct AppMenuItem * AddAppMenuItem (

/*  SYNOPSIS */
	IPTR id,
	IPTR  userdata,
	STRPTR text,
	struct MsgPort * msgport,
	Tag tag1,
	...)

/*  FUNCTION
        This is the varargs version of workbench.library/AddAppMenuItemA().
        For information see workbench.library/AddAppMenuItemA().

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        workbench.library/AddAppMenuItemA()

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_SLOWSTACKTAGS_PRE(tag1)
    retval = AddAppMenuItemA (id, userdata, text, msgport, AROS_SLOWSTACKTAGS_ARG(tag1));
    AROS_SLOWSTACKTAGS_POST
} /* AddAppMenuItem */
