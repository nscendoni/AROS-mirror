#ifndef _BROWSERWINDOW_PRIVATE_H_
#define _BROWSERWINDOW_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: browserwindow_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>
#include <utility/hooks.h>
#include <libraries/mui.h>

/*** Instance data **********************************************************/
struct BrowserWindow_DATA
{
    Object *tabContextMenu;
    Object *urlString;
    Object *tabs, *tabbed;
    Object *progressBar;
    Object *toolTips;
    Object *searchBar;
    struct Hook goHook;
    struct Hook webSearchHook;
    struct Hook webSearchAcknowledgeHook;
};

#endif /* _BROWSERWINDOW_PRIVATE_H_ */
