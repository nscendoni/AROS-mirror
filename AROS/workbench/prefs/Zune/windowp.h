/*
    Copyright © 2002, The AROS Development Team. 
    All rights reserved.
    
    $Id: windowp.h 51633 2016-03-08 00:38:42Z mazze $
*/

#ifndef _ZUNE_WINDOWP_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

extern const struct __MUIBuiltinClass _MUIP_Windows_desc;

Object *windowsclass_get_icon(void);

#endif
