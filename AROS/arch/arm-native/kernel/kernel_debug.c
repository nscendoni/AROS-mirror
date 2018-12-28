/*
    Copyright © 2013-2015, The AROS Development Team. All rights reserved.
    $Id: kernel_debug.c 50368 2015-04-13 23:32:03Z NicJA $
*/

#include <aros/kernel.h>
#include <inttypes.h>

#include <kernel_base.h>
#include <kernel_debug.h>
#include "kernel_intern.h"

int krnPutC(int chr, struct KernelBase *KernelBase)
{
    if (chr == 0x03)
        __arm_arosintern.ARMI_PutChar = NULL;
    else
    {
        if (__arm_arosintern.ARMI_PutChar)
            __arm_arosintern.ARMI_PutChar(chr);
        if (__arm_arosintern.ARMI_SerPutChar)
            __arm_arosintern.ARMI_SerPutChar(chr);
    }
    return 1;
}
