#ifndef _BROWSERPREFERENCES_PRIVATE_H_
#define _BROWSERPREFERENCES_PRIVATE_H_

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: browserpreferences_private.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/types.h>

/*** Instance data **********************************************************/
struct BrowserPreferences_DATA
{
    STRPTR downloadDestination;
    BOOL requestDownloadedFileName;
};

#endif /* _BROWSERPREFERENCES_PRIVATE_H_ */
