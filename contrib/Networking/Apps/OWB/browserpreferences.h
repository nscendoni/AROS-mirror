#ifndef _BROWSERPREFERENCES_H
#define _BROWSERPREFERENCES_H

/*
    Copyright � 2009, The AROS Development Team. All rights reserved.
    $Id: browserpreferences.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <utility/tagitem.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_BrowserPreferences                 (TAG_USER | 0x10000100)

/*** Private methods ********************************************************/

/*** Attributes *************************************************************/
#define MUIA_BrowserPreferences_DownloadDestination (MUIB_BrowserPreferences | 0x00000000)
#define MUIA_BrowserPreferences_RequestDownloadedFileName (MUIB_BrowserPreferences | 0x00000001)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *BrowserPreferences_CLASS;

/*** Macros *****************************************************************/
#define BrowserPreferencesObject BOOPSIOBJMACRO_START(BrowserPreferences_CLASS->mcc_Class)

#endif /* _BROWSERPREFERENCES_H */
