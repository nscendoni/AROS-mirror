#ifndef  CLIB_SCALOSPREVIEWPLUGIN_PROTOS_H
#define  CLIB_SCALOSPREVIEWPLUGIN_PROTOS_H

/*
**	$Id: scalospreviewplugin_protos.h 51982 2016-03-15 21:56:01Z NicJA $
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  SCALOS_SCALOS_H
#include <scalos/scalos.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
LONG SCAPreviewGenerate( struct ScaWindowTask *wt, BPTR dirLock, CONST_STRPTR iconName, struct TagItem *tagList );
LONG SCAPreviewGenerateTags( struct ScaWindowTask *wt, BPTR dirLock, CONST_STRPTR iconName, Tag firstTag, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_SCALOSPREVIEWPLUGIN_PROTOS_H */
