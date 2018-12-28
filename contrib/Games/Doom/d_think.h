// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: d_think.h 30794 2009-03-08 02:19:07Z neil $
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
//  MapObj data. Map Objects or mobjs are actors, entities,
//  thinker, take-your-pick... anything that moves, acts, or
//  suffers state changes of more or less violent nature.
//
//-----------------------------------------------------------------------------


#ifndef __D_THINK__
#define __D_THINK__


#ifdef __GNUG__
#pragma interface
#endif



//
// Experimental stuff.
// To compile this as "ANSI C with classes"
//  we will need to handle the various
//  action functions cleanly.
//
typedef  void (*actionf_v)();
typedef  void (*actionf_p1)( void* );
typedef  void (*actionf_p2)( void*, void* );

typedef union
{
  actionf_p1	acp1;
  actionf_v	acv;
  actionf_p2	acp2;

} actionf_t;





// Historically, "think_t" is yet another
//  function pointer to a routine to handle
//  an actor.
typedef actionf_t  think_t;


// Doubly linked list of actors.
typedef struct thinker_s
{
    struct thinker_s*	prev;
    struct thinker_s*	next;
    think_t		function;
    
} thinker_t;



#endif
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.2  2000/06/28 20:43:47  bernie
// remove alien #pragma directives. Perhaps for Metrowerks?
//
// Revision 1.1  2000/02/29 18:21:06  stegerg
// Doom port based on ADoomPPC. Read README.AROS!
//
//
//-----------------------------------------------------------------------------
