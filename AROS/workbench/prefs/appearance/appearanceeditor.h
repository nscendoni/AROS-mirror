#ifndef _THEMEEDITOR_H_
#define _THEMEEDITOR_H_

/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: appearanceeditor.h 48674 2014-01-02 17:51:04Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_AppearanceEditor                        (TAG_USER | 0x10000000)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *AppearanceEditor_CLASS;

/*** Macros *****************************************************************/
#define AppearanceEditorObject BOOPSIOBJMACRO_START(AppearanceEditor_CLASS->mcc_Class)

#endif /* _THEMEEDITOR_H_ */
