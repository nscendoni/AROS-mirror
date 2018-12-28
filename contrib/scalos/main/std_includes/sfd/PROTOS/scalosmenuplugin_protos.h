#ifndef  CLIB_SCALOSMENUPLUGIN_PROTOS_H
#define  CLIB_SCALOSMENUPLUGIN_PROTOS_H

/*
**	$Id: scalosmenuplugin_protos.h 48481 2013-12-01 22:08:26Z mazze $
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
VOID SCAMenuFunction( struct ScaWindowTask *wt, struct ScaIconNode *in );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_SCALOSMENUPLUGIN_PROTOS_H */
