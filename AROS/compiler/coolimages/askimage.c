/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: askimage.c 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: english
*/

#include "coolimages.h"

#define ASKIMAGE_WIDTH  16
#define ASKIMAGE_HEIGHT 16
#define ASKIMAGE_COLORS 4

static const UBYTE askimage_data[] =
{
	00,00,00,00,00,03,03,03,03,03,00,00,00,00,00,00,
	00,00,00,03,03,03,03,03,03,03,03,03,00,00,00,00,
	00,00,03,03,03,03,03,03,03,03,03,03,03,00,00,00,
	00,03,03,03,03,02,02,02,02,02,03,03,03,03,00,00,
	00,03,03,03,02,02,02,02,02,02,02,03,03,03,01,00,
	03,03,03,03,02,02,03,03,02,02,02,03,03,03,03,00,
	03,03,03,03,03,03,03,03,02,02,02,03,03,03,03,01,
	03,03,03,03,03,03,03,02,02,02,03,03,03,03,03,01,
	03,03,03,03,03,03,02,02,02,03,03,03,03,03,03,01,
	03,03,03,03,03,03,02,02,02,03,03,03,03,03,03,01,
	00,03,03,03,03,03,03,03,03,03,03,03,03,03,01,01,
	00,03,03,03,03,03,02,02,02,03,03,03,03,03,01,00,
	00,00,03,03,03,03,02,02,02,03,03,03,03,01,01,00,
	00,00,00,03,03,03,03,03,03,03,03,03,01,01,00,00,
	00,00,00,00,01,03,03,03,03,03,01,01,01,00,00,00,
	00,00,00,00,00,00,01,01,01,01,01,00,00,00,00,00
};

static const UBYTE askimage_pal[] =
{
	0xb3,0xb3,0xb3,0x00,0x00,0x00,
	0xe0,0xe0,0xe0,0xc8,0x00,0x00
};

const struct CoolImage cool_askimage =
{
	askimage_data,
	askimage_pal,
	ASKIMAGE_WIDTH,
	ASKIMAGE_HEIGHT,
	ASKIMAGE_COLORS
};
