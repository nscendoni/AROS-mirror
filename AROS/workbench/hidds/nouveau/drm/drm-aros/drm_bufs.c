/*
    Copyright 2009-2011, The AROS Development Team. All rights reserved.
    $Id: drm_bufs.c 41758 2011-10-05 20:14:12Z deadwood $
*/

#include "drmP.h"

int drm_order(unsigned long size)
{
    int order;
    unsigned long tmp;

    for (order = 0, tmp = size >> 1; tmp; tmp >>= 1, order++) ;

    if (size & (size - 1))
        ++order;

    return order;
}

