/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: preparecontext.c 42527 2011-11-18 05:54:03Z sonic $

    Desc: PrepareContext() - Prepare a task context for dispatch.
    Lang: english
*/

#include <exec/execbase.h>
#include <exec/memory.h>
#include <utility/tagitem.h>

#include "exec_util.h"

BOOL PrepareContext(struct Task *task, APTR entryPoint, APTR fallBack,
                    const struct TagItem *tagList, struct ExecBase *SysBase)
{
    /*
     * The actual implementation of this function is CPU-specific.
     * Please see files in arch/<cpu>-all/exec/ for working examples.
     */
    return FALSE;
} /* PrepareContext() */
