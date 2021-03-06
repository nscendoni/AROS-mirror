/*
    Copyright � 2002, The AROS Development Team. 
    All rights reserved.
    
    $Id: mui_aslrequesttags.c 33390 2010-05-30 12:14:54Z mazze $
*/

#define AROS_TAGRETURNTYPE BOOL
#include <utility/tagitem.h>
#include <proto/alib.h>

/*****************************************************************************

    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/muimaster.h>
extern struct Library * MUIMasterBase;

	BOOL MUI_AslRequestTags (

/*  SYNOPSIS */
	APTR requester,
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
    
    retval = MUI_AslRequest(requester, AROS_SLOWSTACKTAGS_ARG(tag1));
    
    AROS_SLOWSTACKTAGS_POST
} /* MUI_AslRequestTags */
