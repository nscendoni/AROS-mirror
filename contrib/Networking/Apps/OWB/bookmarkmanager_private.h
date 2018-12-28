#ifndef _BOOKMARKMANAGER_PRIVATE_H_
#define _BOOKMARKMANAGER_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: bookmarkmanager_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>
#include <utility/hooks.h>
#include <libraries/mui.h>
#include <sqlite3.h>

/*** Instance data **********************************************************/
struct BookmarkManager_DATA
{
    sqlite3 *db;
    Object *bookmarks_list;
    Object *label_string, *url_string;
    Object *openOnStartup_check, *showInQuickLaunch_check;
    Object *bookmarks_menu;
    struct Hook create_hook, destroy_hook, display_hook;
    STRPTR selectedURL;
};

struct Bookmark
{
    unsigned long long id;
    char *label;
    char *url;
    Object *menuItem;
};

#endif /* _BOOKMARKMANAGER_PRIVATE_H_ */
