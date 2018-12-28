/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: getcpucount.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/kernel.h>
#include <aros/libcall.h>

#include "kernel_base.h"
#include "kernel_intern.h"
#include "apic.h"

AROS_LH0(unsigned int, KrnGetCPUCount,
	 struct KernelBase *, KernelBase, 36, Kernel)
{
    AROS_LIBFUNC_INIT

    return KernelBase->kb_PlatformData->kb_APIC->count;

    AROS_LIBFUNC_EXIT
}
