/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kernel_objects.h 48424 2013-11-18 09:28:30Z neil $

    Desc:
*/

/* This file is a small abstraction, provided for future implementation of slab allocator */

#include <proto/exec.h>

#define krnAllocCPUContext() AllocMem(KernelBase->kb_ContextSize, MEMF_CLEAR)
#define krnAllocIntrNode() AllocMem(sizeof(struct IntrNode), MEMF_PUBLIC)

#define krnFreeIntrNode(n) FreeMem(n, sizeof(struct IntrNode))
