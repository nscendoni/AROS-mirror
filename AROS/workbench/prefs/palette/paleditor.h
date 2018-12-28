#ifndef _PALEDITOR_H_
#define _PALEDITOR_H_

/*
    Copyright © 2010, The AROS Development Team. All rights reserved.
    $Id: paleditor.h 32694 2010-02-18 20:46:47Z mazze $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_PalEditor                  (TAG_USER | 0x10000000)

/*** Variables **************************************************************/
extern struct MUI_CustomClass *PalEditor_CLASS;

/*** Macros *****************************************************************/
#define PalEditorObject BOOPSIOBJMACRO_START(PalEditor_CLASS->mcc_Class)

#endif /* _PALEDITOR_H_ */
