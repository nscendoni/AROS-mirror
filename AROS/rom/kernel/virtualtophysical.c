/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: virtualtophysical.c 47708 2013-07-17 12:22:32Z verhaegs $

    Desc:
*/

#include <aros/kernel.h>
#include <aros/libcall.h>

#include <kernel_base.h>

/*****************************************************************************

    NAME */
#include <proto/kernel.h>

        AROS_LH1I(void *, KrnVirtualToPhysical,

/*  SYNOPSIS */
	AROS_LHA(void *, virtual, A0),

/*  LOCATION */
	struct KernelBase *, KernelBase, 20, Kernel)

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

	/* The implementation is entirely architecture-specific */
	return virtual;

	AROS_LIBFUNC_EXIT
}
