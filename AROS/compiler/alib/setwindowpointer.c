/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: setwindowpointer.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Obtain the closes pen to a given color
    Lang: english
*/

#include <exec/types.h>

#include "alib_intern.h"

extern struct IntuitionBase * IntuitionBase;

/*****************************************************************************

    NAME */
#include <utility/tagitem.h>
#include <intuition/intuition.h>
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/intuition.h>

	void SetWindowPointer (

/*  SYNOPSIS */
        struct Window   * window,
	ULONG		  tag1,
	...		  )

/*  FUNCTION
        Varargs version of intuition.library/SetWindowPointerA().

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	intuition.library/SetWindowPointerA()

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_NR_SLOWSTACKTAGS_PRE(tag1)
    SetWindowPointerA (window, AROS_SLOWSTACKTAGS_ARG(tag1));
    AROS_NR_SLOWSTACKTAGS_POST
} /* SetWindowPointer */
