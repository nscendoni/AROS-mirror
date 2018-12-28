// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: p_tick.h 30794 2009-03-08 02:19:07Z neil $
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
//	?
//
//-----------------------------------------------------------------------------


#ifndef __P_TICK__
#define __P_TICK__


#ifdef __GNUG__
#pragma interface
#endif


// Called by C_Ticker,
// can call G_PlayerExited.
// Carries out all thinking of monsters and players.
void P_Ticker (void);



#endif
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.1  2000/02/29 18:21:06  stegerg
// Doom port based on ADoomPPC. Read README.AROS!
//
//
//-----------------------------------------------------------------------------
