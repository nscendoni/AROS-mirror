/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: maygetchar.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/libcall.h>

#include <unistd.h>

#include "kernel_base.h"
#include "kernel_intern.h"

AROS_LH0(int, KrnMayGetChar,
	 struct KernelBase *, KernelBase, 26, Kernel)
{
    AROS_LIBFUNC_INIT
    
    char c;
    int ret;

    ret = KernelBase->kb_PlatformData->iface->read (STDERR_FILENO, &c, 1);
    AROS_HOST_BARRIER

    return (ret == 1) ? c : -1;

    AROS_LIBFUNC_EXIT
}
