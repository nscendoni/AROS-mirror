/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: switch.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/kernel.h>

#include <kernel_base.h>
#include <kernel_syscall.h>

#include <proto/kernel.h>

/* See rom/kernel/switch.c for documentation */

AROS_LH0(void, KrnSwitch,
    struct KernelBase *, KernelBase, 5, Kernel)
{
    AROS_LIBFUNC_INIT

    /* The real implementation is in Exec/Switch */
    Supervisor(__AROS_GETVECADDR(SysBase,9));

    AROS_LIBFUNC_EXIT
}
