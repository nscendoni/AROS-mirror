/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: setscheduler.c 47708 2013-07-17 12:22:32Z verhaegs $

    Desc:
*/

#include <aros/kernel.h>

#include <kernel_base.h>

/*****************************************************************************

    NAME */
#include <proto/kernel.h>

        AROS_LH1I(void, KrnSetScheduler,

/*  SYNOPSIS */
	AROS_LHA(KRN_SchedType, sched, D0),

/*  LOCATION */
	struct KernelBase *, KernelBase, 2, Kernel)

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

    AROS_LIBFUNC_EXIT
}
