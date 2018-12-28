/*
    Copyright © 2002-2012, The AROS Development Team. All rights reserved.
    $Id: floattext_private.h 46029 2012-11-12 16:14:47Z neil $
*/

#ifndef _FLOATTEXT_PRIVATE_H_
#define _FLOATTEXT_PRIVATE_H_

#include <exec/types.h>
#include <utility/hooks.h>

struct Floattext_DATA
{
    STRPTR       text;
    BOOL         justify;
    BOOL         typesetting;
    STRPTR       skipchars;
    ULONG        tabsize;
    ULONG        oldwidth;
};

#endif /* _FLOATTEXT_PRIVATE_H_ */
