#ifndef _CONFIGURATIONEDITOR_H_
#define _CONFIGURATIONEDITOR_H_

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: configurationeditor.h 30794 2009-03-08 02:19:07Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Variables **************************************************************/
extern struct MUI_CustomClass *ConfigurationEditor_CLASS;

/*** Macros *****************************************************************/
#define ConfigurationEditorObject BOOPSIOBJMACRO_START(ConfigurationEditor_CLASS->mcc_Class)

#endif /* _CONFIGURATIONEDITOR_H_ */
