#ifndef _PRINTEREDITOR_H_
#define _PRINTEREDITOR_H_

/*
    Copyright © 2004, The AROS Development Team. All rights reserved.
    $Id: editor.h 48674 2014-01-02 17:51:04Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_PrinterEditor                  (TAG_USER | 0x10000000)

#define MUIM_PrinterEditor_Refresh          (MUIB_PrinterEditor + 1)
#define MUIM_PrinterEditor_Sync             (MUIB_PrinterEditor + 2)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *PrinterEditor_CLASS;

/*** Macros *****************************************************************/
#define PrinterEditorObject BOOPSIOBJMACRO_START(PrinterEditor_CLASS->mcc_Class)

#endif /* _PRINTEREDITOR_H_ */
