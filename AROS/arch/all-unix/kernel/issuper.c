/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: issuper.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/libcall.h>

#include "kernel_base.h"
#include "kernel_unix.h"

AROS_LH0I(int, KrnIsSuper,
	  struct KernelBase *, KernelBase, 13, Kernel)
{
    AROS_LIBFUNC_INIT

    return UKB(KernelBase)->SupervisorCount;

    AROS_LIBFUNC_EXIT
}
