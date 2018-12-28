/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: changeworkbenchselectiona.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Change the selection state of icons in a named drawer.
    Lang: english
*/

#include <exec/types.h>
#include <exec/ports.h>
#include <utility/tagitem.h>
#include <intuition/intuition.h>

#include "workbench_intern.h"
#include <workbench/workbench.h>

/*****************************************************************************

    NAME */

        #include <proto/workbench.h>

        AROS_LH3(BOOL, ChangeWorkbenchSelectionA,

/*  SYNOPSIS */
        AROS_LHA(STRPTR,            name, A0),
        AROS_LHA(struct Hook *,     hook, A1),
        AROS_LHA(struct TagItem *,  tags, A2),

/*  LOCATION */
        struct WorkbenchBase *, WorkbenchBase, 21, Workbench)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    AROS_LIBFUNC_INIT

    /* No tags defined for this function... */

    return FALSE;

    AROS_LIBFUNC_EXIT
} /* ChangeWorkbenchSelectionA */

