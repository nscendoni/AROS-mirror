/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cpu_init.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/symbolsets.h>
#include <exec/types.h>

#include "kernel_base.h"

static int cpu_Init(struct KernelBase *KernelBase)
{
    /* All x86-64 processors have SSE */
    KernelBase->kb_ContextSize = AROS_ROUNDUP2(sizeof(struct AROSCPUContext), 16) + sizeof(struct FPXContext);
    return TRUE;
}

ADD2INITLIB(cpu_Init, 5);
