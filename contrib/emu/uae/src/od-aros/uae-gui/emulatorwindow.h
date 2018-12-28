#ifndef _EMULATORWINDOW_H_
#define _EMULATORWINDOW_H_

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: emulatorwindow.h 30794 2009-03-08 02:19:07Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Attributes *************************************************************/
enum
{
    MUIA_EmulatorWindow_DisplayObject = TAG_USER | 0x01000000 /* ..G */
};

/*** Variables **************************************************************/
extern struct MUI_CustomClass *EmulatorWindow_CLASS;

/*** Macros *****************************************************************/
#define EmulatorWindowObject BOOPSIOBJMACRO_START(EmulatorWindow_CLASS->mcc_Class)

#endif /* _EMULATORWINDOW_H_ */
