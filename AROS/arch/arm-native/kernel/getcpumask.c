/*
    Copyright � 2015, The AROS Development Team. All rights reserved.
    $Id: getcpumask.c 50720 2015-05-19 23:23:22Z neil $

    Desc:
*/

#include <aros/kernel.h>
#include <aros/libcall.h>

#include <kernel_base.h>

AROS_LH1(cpumask_t, KrnGetCPUMask,
	AROS_LHA(cpuid_t, id, D0),
	struct KernelBase *, KernelBase, 38, Kernel)
{
    AROS_LIBFUNC_INIT

    return (1 << id);

    AROS_LIBFUNC_EXIT
}
