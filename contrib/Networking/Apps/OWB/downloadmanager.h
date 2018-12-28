#ifndef _DOWNLOADMANAGER_H
#define _DOWNLOADMANAGER_H

/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: downloadmanager.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <utility/tagitem.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_DownloadManager                 (TAG_USER | 0x10000100)

/*** Attributes *************************************************************/
#define MUIA_DownloadManager_Preferences     (MUIB_DownloadManager|0x00000000)

/*** Methods ****************************************************************/
#define MUIM_DownloadManager_UpdateInterface (MUIB_DownloadManager|0x00000000)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *DownloadManager_CLASS;

/*** Macros *****************************************************************/
#define DownloadManagerObject BOOPSIOBJMACRO_START(DownloadManager_CLASS->mcc_Class)

#endif
