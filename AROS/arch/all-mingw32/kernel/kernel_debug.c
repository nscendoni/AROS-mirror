/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: kernel_debug.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/exec.h>

#include <stdarg.h>

#include "hostinterface.h"
#include "kernel_base.h"
#include "kernel_cpu.h"
#include "kernel_mingw32.h"

/*
 * KernelBase is an optional parameter here. During
 * very early startup it can be NULL.
 */
int krnPutC(int chr, struct KernelBase *KernelBase)
{
    int r;

    /*
     * During early boot SysBase may hold some old value (after warm reboot),
     * but KernelBase is always NULL.
     */
    if (KernelBase)
	Forbid();

    r = HostIFace->KPutC(chr);

    if (KernelBase)
	Permit();

    return r;
}
