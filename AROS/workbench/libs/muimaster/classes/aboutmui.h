/*
    Copyright © 2002-2003, The AROS Development Team. All rights reserved.
    $Id: aboutmui.h 30792 2009-03-07 22:40:04Z neil $
*/

#ifndef _MUI_CLASSES_ABOUTMUI_H
#define _MUI_CLASSES_ABOUTMUI_H

/*** Name *******************************************************************/
#define MUIC_Aboutmui "Aboutmui.mui"

/*** Identifier base (for Zune extensions) **********************************/
#define MUIB_Aboutmui (MUIB_ZUNE | 0x00000000)  

/*** Attributes *************************************************************/
#define MUIA_Aboutmui_Application (MUIB_MUI | 0x00422523) /* V11 i.. Object * */


extern const struct __MUIBuiltinClass _MUI_Aboutmui_desc; /* PRIV */

#endif /* _MUI_CLASSES_ABOUTMUI_H */
