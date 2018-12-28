/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kernel_globals.h 48424 2013-11-18 09:28:30Z neil $

    Desc:
*/

/*
    Copyright © 2011, The AROS Development Team. All rights reserved.
    $Id: kernel_globals.h 48424 2013-11-18 09:28:30Z neil $

    Desc: Global KernelBase access
    Lang: english
*/

#ifndef KERNEL_GLOBALS_H
#define KERNEL_GLOBALS_H

struct KernelBase;
extern struct KernelBase *KernelBase;

static inline struct KernelBase *getKernelBase(void)
{
    return KernelBase;
}

static inline void setKernelBase(struct KernelBase *base)
{
    KernelBase = base;
}

#endif /* KERNEL_GLOBALS_H */
