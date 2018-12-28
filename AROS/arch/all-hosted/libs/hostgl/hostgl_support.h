/*
    Copyright 2009-2015, The AROS Development Team. All rights reserved.
    $Id: hostgl_support.h 51001 2015-08-10 17:43:38Z neil $
*/

#ifndef AROSMESA_FUNCS_H
#define AROSMESA_FUNCS_H

#include "hostgl_types.h"

VOID HostGLSelectRastPort(struct hostgl_context * ctx, struct TagItem * tagList);
BOOL HostGLStandardInit(struct hostgl_context * ctx, struct TagItem *tagList);
VOID HostGLRecalculateBufferWidthHeight(struct hostgl_context * ctx);
VOID HostGLFreeContext(struct hostgl_context * ctx);
#endif
