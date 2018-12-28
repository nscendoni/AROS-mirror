/*
    Copyright © 2011, The AROS Development Team. All rights reserved.
    $Id: kernel_globals.h 47619 2013-07-02 18:27:20Z neil $

    Desc: Global KernelBase access, Amiga hardware specific
    Lang: english
*/

/*
 * getKernelBase() is intentionally not defined in order to produce
 * build errors when referenced. Helps cleaning up the code.
 */

static inline void setKernelBase(struct KernelBase *base)
{
    /* Called from within AllocKernelBase(). Do nothing for now... */
}
