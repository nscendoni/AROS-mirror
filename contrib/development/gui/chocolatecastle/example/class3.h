#ifndef Class3_H
#define Class3_H

/*
    Copyright © 2012, The AROS Development Team. All rights reserved.
    $Id: class3.h 48675 2014-01-02 18:34:06Z neil $
*/

#include <exec/types.h>
#include <libraries/mui.h>

/*** Identifier base ********************************************************/
#define MUIB_Class3           (TAG_USER|0x00000000)

/*** Attributes *************************************************************/

/*** Variables **************************************************************/
extern struct MUI_CustomClass *Class3_CLASS;

/*** Macros *****************************************************************/
#define Class3Object BOOPSIOBJMACRO_START(Class3_CLASS->mcc_Class)

#endif
