/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: systemp.h 51633 2016-03-08 00:38:42Z mazze $
*/

#ifndef _ZUNE_SYSTEMP_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

extern const struct __MUIBuiltinClass _MUIP_System_desc;

Object *systemclass_get_icon(void);

#endif
