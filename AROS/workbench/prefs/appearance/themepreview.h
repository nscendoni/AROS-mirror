#ifndef _THEMEPREVIEW_H_
#define _THEMEPREVIEW_H_

/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: themepreview.h 48674 2014-01-02 17:51:04Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_ThemePreview                       (TAG_USER | 0x10000000)

/*** Attributes *************************************************************/
#define MUIA_ThemePreview_Theme                 (MUIB_ThemePreview | 1)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *ThemePreview_CLASS;

/*** Macros *****************************************************************/
#define ThemePreviewObject BOOPSIOBJMACRO_START(ThemePreview_CLASS->mcc_Class)

#endif /* _THEMEPREVIEW_H_ */
