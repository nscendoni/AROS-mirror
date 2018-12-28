/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: getcpunumber.c 50470 2015-04-27 23:58:50Z NicJA $

    Desc:
*/

#include <aros/kernel.h>
#include <aros/libcall.h>

#include <kernel_base.h>

/*****************************************************************************

    NAME */
#include <proto/kernel.h>

        AROS_LH0(uint32_t, KrnGetCPUNumber,

/*  SYNOPSIS */

/*  LOCATION */
	struct KernelBase *, KernelBase, 37, Kernel)

/*  FUNCTION
	Return number of the caller CPU

    INPUTS
	None

    RESULT
	Number of the CPU on which the function is called

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    AROS_LIBFUNC_INIT

    /* The actual implementation is entirely architecture-specific */
    return 0;

    AROS_LIBFUNC_EXIT
}
