#ifndef _TABBEDGROUP_PRIVATE_H_
#define _TABBEDGROUP_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: tabbedgroup_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>

enum { HORIZONTAL_TABBED = 1, VERTICAL_TABBED };

/*** Instance data **********************************************************/
struct TabbedGroup_DATA
{
    BYTE direction;
};

#endif /* _TABBEDGROUP_PRIVATE_H_ */
