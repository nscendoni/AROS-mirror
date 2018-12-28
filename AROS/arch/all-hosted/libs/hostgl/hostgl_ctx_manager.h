/*
    Copyright 2011, The AROS Development Team. All rights reserved.
    $Id: hostgl_ctx_manager.h 51001 2015-08-10 17:43:38Z neil $
*/

#ifndef HOSTGL_CTX_MANAGER_H
#define HOSTGL_CTX_MANAGER_H

#include "hostgl_types.h"

GLAContext HostGL_GetCurrentContext();
VOID HostGL_SetCurrentContext(GLAContext ctx);
VOID HostGL_Lock();
VOID HostGL_UnLock();
VOID HostGL_UpdateGlobalGLXContext();
Display * HostGL_GetGlobalX11Display();

#endif /* HOSTGL_CTX_MANAGER_H */
