/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: asksoftstyle.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Graphics function AskSoftStyle()
    Lang: English
*/

/*****************************************************************************

    NAME */
#include <graphics/rastport.h>
#include <proto/graphics.h>

	AROS_LH1I(ULONG, AskSoftStyle,

/*  SYNOPSIS */
	AROS_LHA(struct RastPort *, rp, A1),

/*  LOCATION */
	struct GfxBase *, GfxBase, 14, Graphics)

/*  FUNCTION

    Query algorithmically generated style attributes. These are the bits
    valid to set via SetSoftStyle().

    INPUTS

    pr   --  pointer to rastport

    RESULT

    Algorithmically generated style bits (bits not defined are also set).

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    SetSoftStyle(), graphics/text.h

    INTERNALS

    HISTORY

    24.7.98  SDuvan  implemented

*****************************************************************************/


{
    AROS_LIBFUNC_INIT
      
    if(rp->Font == NULL)
	return 0;
    
    return ~rp->Font->tf_Style;
    
    AROS_LIBFUNC_EXIT
} /* AskSoftStyle */
