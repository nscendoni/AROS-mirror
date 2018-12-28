/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: getscheduler.c 47708 2013-07-17 12:22:32Z verhaegs $

    Desc:
*/

#include <aros/kernel.h>

#include <kernel_base.h>

/*****************************************************************************

    NAME */
#include <proto/kernel.h>

        AROS_LH0I(KRN_SchedType, KrnGetScheduler,

/*  SYNOPSIS */

/*  LOCATION */
	struct KernelBase *, KernelBase, 1, Kernel)

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
    
    return SCHED_RR;
    
    AROS_LIBFUNC_EXIT
}
