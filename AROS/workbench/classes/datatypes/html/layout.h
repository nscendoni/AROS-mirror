/*
    Copyright � 2004, Martin Gierich. All rights reserved.
    Licensed under the terms of the AROS Public License (APL)
    $Id: layout.h 30792 2009-03-07 22:40:04Z neil $

    Desc: Structs for layout engine with wordwrapper
*/

#define DEBUG_LAYOUT 1
#define SHOW_SEGLIST 1

#ifndef D
#if DEBUG_LAYOUT
#define D(x...) x
#else
#define D(x...)
#endif
#endif

#define FONTSIZE 10

/*******************************************************************************************/
/* Prototypes */

