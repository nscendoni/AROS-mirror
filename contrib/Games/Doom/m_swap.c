// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: m_swap.c 30794 2009-03-08 02:19:07Z neil $
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
// $Log$
// Revision 1.1  2000/02/29 18:21:04  stegerg
// Doom port based on ADoomPPC. Read README.AROS!
//
//
// DESCRIPTION:
//	Endianess handling, swapping 16bit and 32bit.
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: m_swap.c 30794 2009-03-08 02:19:07Z neil $";


#ifdef __GNUG__
#pragma implementation "m_swap.h"
#endif
#include "m_swap.h"


// Needed with big endian.
#ifdef __BIG_ENDIAN__

#error "??????????????????????????????????????"

// Swap 16bit, that is, MSB and LSB byte.
unsigned short SwapSHORT(unsigned short x)
{
    // No masking with 0xFF should be necessary. 
    return (unsigned short)((x>>8) | (x<<8));
}

// Swapping 32bit.
unsigned long SwapLONG( unsigned long x)
{
    return
	(x>>24)
	| ((x>>8) & 0xff00)
	| ((x<<8) & 0xff0000)
	| (x<<24);
}


#endif


