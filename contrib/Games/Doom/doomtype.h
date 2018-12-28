// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: doomtype.h 30794 2009-03-08 02:19:07Z neil $
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Simple basic typedefs, isolated here to make it easier
//	 separating modules.
//    
//-----------------------------------------------------------------------------


#ifndef __DOOMTYPE__
#define __DOOMTYPE__


#ifndef __BYTEBOOL__
#define __BYTEBOOL__
// Fixed to use builtin bool type with C++.
#ifdef __cplusplus
typedef bool boolean;
#else
typedef enum {false, true} boolean;
#endif
#ifndef byte
typedef unsigned char byte;
#endif
#endif

#ifdef AROS

#define iabs abs

#endif

// Predefined with some OS.
#ifdef LINUX
#include <values.h>
#else
#define MAXCHAR		((char)0x7f)
#define MAXSHORT	((short)0x7fff)

// Max pos 32-bit int.
#ifndef MAXINT
#define MAXINT		((int)0x7fffffff)	
#endif
#define MAXLONG		((long)0x7fffffff)
#define MINCHAR		((char)0x80)
#define MINSHORT	((short)0x8000)

// Max negative 32-bit integer.
#ifndef MININT
#define MININT		((int)0x80000000)	
#endif
#define MINLONG		((long)0x80000000)
#endif




#endif
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.2  2003/07/19 02:59:04  iaint
// Remove unnecessary inclusion of <aros/machine.h>. No file should really
// include this directly, except for one or two other headers.
//
// Revision 1.1  2000/02/29 18:21:06  stegerg
// Doom port based on ADoomPPC. Read README.AROS!
//
//
//-----------------------------------------------------------------------------
