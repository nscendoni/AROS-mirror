/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cause.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/libcall.h>

#include <signal.h>

#include "kernel_base.h"
#include "kernel_intern.h"

AROS_LH0(void, KrnCause,
	  struct KernelBase *, KernelBase, 3, Kernel)
{
    AROS_LIBFUNC_INIT

    KernelBase->kb_PlatformData->iface->raise(SIGUSR2);
    AROS_HOST_BARRIER

    AROS_LIBFUNC_EXIT
}
