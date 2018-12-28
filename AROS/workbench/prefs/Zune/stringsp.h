/*
    Copyright © 2002, The AROS Development Team. 
    All rights reserved.
    
    $Id: stringsp.h 51633 2016-03-08 00:38:42Z mazze $
*/

#ifndef _ZUNE_STRINGSP_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

extern const struct __MUIBuiltinClass _MUIP_Strings_desc;

Object *stringsclass_get_icon(void);

#endif
