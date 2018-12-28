#ifndef _CALLTIPS_PRIVATE_H_
#define _CALLTIPS_PRIVATE_H_

/*
    Copyright © 2014, Thore Böckelmann. All rights reserved.
    Copyright © 2014, The AROS Development Team. All rights reserved.
    $Id: Calltips_private.h 50720 2015-05-19 23:23:22Z neil $
*/

#include <graphics/gfx.h>
#include <libraries/mui.h>

/*** Instance data **********************************************************/
struct Data
{
    Object *source;
    Object *rootGroup;
    ULONG layout;
    BOOL marginLeft;
    BOOL marginTop;
    struct Rect32 rectangle;
};

#endif /* _CALLTIPS_PRIVATE_H_ */
