#ifndef _TOOLBAR_H_
#define _TOOLBAR_H_

/*
    Copyright � 2003, The AROS Development Team. All rights reserved.
    $Id: toolbar.h 30794 2009-03-08 02:19:07Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Variables **************************************************************/
extern struct MUI_CustomClass *Toolbar_CLASS;

/*** Macros *****************************************************************/
#define ToolbarObject BOOPSIOBJMACRO_START(Toolbar_CLASS->mcc_Class)

#endif /* _TOOLBAR_H_ */
