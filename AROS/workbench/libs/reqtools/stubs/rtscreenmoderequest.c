/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: rtscreenmoderequest.c 33390 2010-05-30 12:14:54Z mazze $

    Desc:
    Lang: english
*/

#define AROS_TAGRETURNTYPE ULONG
#include <utility/tagitem.h>
#include <libraries/reqtools.h>

#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/reqtools.h>

extern struct ReqToolsBase * ReqToolsBase;

/*****************************************************************************

    NAME */
	ULONG rtScreenModeRequest (

/*  SYNOPSIS */
	struct rtScreenModeRequester *screenmodereq,
	char *title,
	Tag tag1, 
	...)

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
    AROS_SLOWSTACKTAGS_PRE(tag1)

    retval = rtScreenModeRequestA(screenmodereq, title, AROS_SLOWSTACKTAGS_ARG(tag1));

    AROS_SLOWSTACKTAGS_POST
    
} /* rtScreenModeRequest */
