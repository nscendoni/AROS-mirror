#ifndef _MUI_CLASSES_RECTANGLE_H
#define _MUI_CLASSES_RECTANGLE_H

/* 
    Copyright © 1999, David Le Corfec.
    Copyright © 2002-2003, The AROS Development Team.
    All rights reserved.

    $Id: rectangle.h 45798 2012-09-14 19:47:19Z neil $
*/

/*** Name *******************************************************************/
#define MUIC_Rectangle          "Rectangle.mui"

/*** Identifier base (for Zune extensions) **********************************/
#define MUIB_Rectangle          (MUIB_ZUNE | 0x00002b00)

/*** Attributes *************************************************************/
#define MUIA_Rectangle_BarTitle (MUIB_MUI | 0x00426689)   /* V11 i.g STRPTR */
#define MUIA_Rectangle_HBar     (MUIB_MUI | 0x0042c943)   /* V7  i.g BOOL   */
#define MUIA_Rectangle_VBar     (MUIB_MUI | 0x00422204)   /* V7  i.g BOOL   */

extern const struct __MUIBuiltinClass _MUI_Rectangle_desc;      /* PRIV */

#endif /* _MUI_CLASSES_RECTANGLE_H */
