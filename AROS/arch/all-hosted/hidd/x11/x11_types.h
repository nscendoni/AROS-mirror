#ifndef X11_TYPES_H
#define X11_TYPES_H

/*
    Copyright © 2016, The AROS Development Team. All rights reserved.
    $Id: x11_types.h 53089 2016-12-22 14:49:32Z neil $
*/

#define timeval sys_timeval
#include <X11/Xutil.h>
#include <X11/Xcursor/Xcursor.h>
#undef timeval

#endif
