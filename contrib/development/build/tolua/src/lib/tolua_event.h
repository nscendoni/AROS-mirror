/* tolua: event functions
** Support code for Lua bindings.
** Written by Waldemar Celes
** TeCGraf/PUC-Rio
** Apr 2003
** $Id: tolua_event.h 30794 2009-03-08 02:19:07Z neil $
*/

/* This code is free software; you can redistribute it and/or modify it.
** The software provided hereunder is on an "as is" basis, and
** the author has no obligation to provide maintenance, support, updates,
** enhancements, or modifications.
*/

#ifndef TOLUA_EVENT_H
#define TOLUA_EVENT_H

#include "tolua++.h"

TOLUA_API void tolua_moduleevents (lua_State* L);
TOLUA_API int tolua_ismodulemetatable (lua_State* L);
TOLUA_API void tolua_classevents (lua_State* L);

#endif
