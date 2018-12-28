#ifndef _AROS_TYPES_IOVEC_S_H
#define _AROS_TYPES_IOVEC_S_H

/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: iovec_s.h 50458 2015-04-24 14:53:27Z neil $
*/

#include <aros/types/size_t.h>

struct iovec
{
    void        *iov_base;
    size_t       iov_len;
};

#endif /* _AROS_TYPES_IOVEC_S_H */
