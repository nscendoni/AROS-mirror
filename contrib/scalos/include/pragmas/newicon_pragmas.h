#ifndef PRAGMAS_NEWICON_PRAGMAS_H
#define PRAGMAS_NEWICON_PRAGMAS_H

/*
**	$Id: newicon_pragmas.h 48481 2013-12-01 22:08:26Z mazze $
**
**	Direct ROM interface (pragma) definitions.
**
**	Copyright � 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#if defined(LATTICE) || defined(__SASC) || defined(_DCC)
#ifndef __CLIB_PRAGMA_LIBCALL
#define __CLIB_PRAGMA_LIBCALL
#endif /* __CLIB_PRAGMA_LIBCALL */
#else /* __MAXON__, __STORM__ or AZTEC_C */
#ifndef __CLIB_PRAGMA_AMICALL
#define __CLIB_PRAGMA_AMICALL
#endif /* __CLIB_PRAGMA_AMICALL */
#endif /* */

#if defined(__SASC) || defined(__STORM__)
#ifndef __CLIB_PRAGMA_TAGCALL
#define __CLIB_PRAGMA_TAGCALL
#endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __MAXON__, __STORM__ or AZTEC_C */

#ifndef CLIB_NEWICON_PROTOS_H
#include <clib/newicon_protos.h>
#endif /* CLIB_NEWICON_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase GetNewDiskObject 1e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase PutNewDiskObject 24 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase FreeNewDiskObject 2a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase newiconPrivate1 30 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase newiconPrivate2 36 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase newiconPrivate3 3c 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase RemapChunkyImage 42 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase FreeRemappedImage 48 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall NewIconBase GetDefNewDiskObject 4e 001
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_NEWICON_PRAGMAS_H */
