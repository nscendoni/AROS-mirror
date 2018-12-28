/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cli.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/libcall.h>

#include "kernel_base.h"

AROS_LH0I(void, KrnCli,
	  struct KernelBase *, KernelBase, 9, Kernel)
{
    AROS_LIBFUNC_INIT

    *KernelIFace.IntState = INT_DISABLE;

    AROS_LIBFUNC_EXIT
}
