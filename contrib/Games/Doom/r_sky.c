// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: r_sky.c 30794 2009-03-08 02:19:07Z neil $
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
// Revision 1.1  2000/02/29 18:21:05  stegerg
// Doom port based on ADoomPPC. Read README.AROS!
//
//
// DESCRIPTION:
//  Sky rendering. The DOOM sky is a texture map like any
//  wall, wrapping around. A 1024 columns equal 360 degrees.
//  The default sky map is 256 columns and repeats 4 times
//  on a 320 screen?
//  
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: r_sky.c 30794 2009-03-08 02:19:07Z neil $";


// Needed for FRACUNIT.
#include "m_fixed.h"

// Needed for Flat retrieval.
#include "r_data.h"

#include "doomstat.h"


#ifdef __GNUG__
#pragma implementation "r_sky.h"
#endif
#include "r_sky.h"


//
// sky mapping
//
int			skyflatnum;
int			skytexture;
int			skytexturemid;



//
// R_InitSkyMap
// Called whenever the view size changes.
//
void R_InitSkyMap (void)
{
//  skyflatnum = R_FlatNumForName ( SKYFLATNAME );
  skytexturemid = 100*FRACUNIT;
}

