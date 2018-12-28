#ifndef _TABS_PRIVATE_H_
#define _TABS_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: tabs_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>
#include <utility/hooks.h>

/*** Instance data **********************************************************/
struct Tabs_DATA
{
    struct Hook *layout_hook;
    ULONG location;
    Object *activeObject;
    Object *closeButton;
    WORD protrusion;
    struct MUI_EventHandlerNode ehn;
};

#endif /* _TABS_PRIVATE_H_ */
