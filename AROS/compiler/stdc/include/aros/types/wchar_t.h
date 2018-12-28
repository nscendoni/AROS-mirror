#ifndef _AROS_TYPES_WCHAR_T_H
#define _AROS_TYPES_WCHAR_T_H

/*
    Copyright � 2010-2012, The AROS Development Team. All rights reserved.
    $Id: wchar_t.h 50458 2015-04-24 14:53:27Z neil $
*/

#ifndef __cplusplus

#ifdef __WCHAR_TYPE__
typedef __WCHAR_TYPE__ wchar_t;
#else
typedef short wchar_t;
#endif

#endif

#endif /* _AROS_TYPES_WCHAR_T_H */
