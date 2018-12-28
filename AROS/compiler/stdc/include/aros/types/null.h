#ifndef _AROS_TYPES_NULL_H
#define _AROS_TYPES_NULL_H

/*
    Copyright © 2010-2012, The AROS Development Team. All rights reserved.
    $Id: null.h 50458 2015-04-24 14:53:27Z neil $

    NULL
*/

#ifdef NULL
#undef NULL
#endif

#ifndef __cplusplus
#define NULL ((void *)0)
#else
#define NULL 0
#endif

#endif /* _AROS_TYPES_NULL_H */
