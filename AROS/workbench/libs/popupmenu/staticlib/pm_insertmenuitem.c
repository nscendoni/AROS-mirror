/*
    Copyright � 2010, The AROS Development Team. 
    All rights reserved.
    
    $Id: pm_insertmenuitem.c 33390 2010-05-30 12:14:54Z mazze $
*/

#include <utility/tagitem.h>
#include <proto/alib.h>

/*****************************************************************************

    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/popupmenu.h>
extern struct PopupMenuBase * PopupMenuBase;

	LONG PM_InsertMenuItem(

/*  SYNOPSIS */
	struct PopupMenu *menu,
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

    retval = PM_InsertMenuItemA(menu, AROS_SLOWSTACKTAGS_ARG(tag1));
    
    AROS_SLOWSTACKTAGS_POST
} /* PM_InsertMenuItem */
