/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: maygetchar.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/exec.h>

#include "kernel_base.h"

AROS_LH0(int, KrnMayGetChar,
	 struct KernelBase *, KernelBase, 26, Kernel)
{
    AROS_LIBFUNC_INIT

    int c;

    Forbid();
    c = KernelIFace.core_getc();
    Permit();

    return c;

    AROS_LIBFUNC_EXIT
}
