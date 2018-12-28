/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: kernel_debug.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <bootconsole.h>

#include "kernel_base.h"
#include "kernel_debug.h"

int krnPutC(int c, struct KernelBase *KernelBase)
{
    serial_Putc(c);
    return 1;
}
