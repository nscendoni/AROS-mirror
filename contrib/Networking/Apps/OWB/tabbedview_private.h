#ifndef _TABBEDVIEW_PRIVATE_H_
#define _TABBEDVIEW_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: tabbedview_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>
#include <utility/hooks.h>
#include <libraries/mui.h>

/*** Instance data **********************************************************/
struct TabbedView_DATA
{
    Object *activeObject;
    struct Hook setterHook;
};

#endif /* _TABBEDVIEW_PRIVATE_H_ */
