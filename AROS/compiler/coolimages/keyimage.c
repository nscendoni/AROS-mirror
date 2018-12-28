/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: keyimage.c 30792 2009-03-07 22:40:04Z neil $
*/

#include "coolimages.h"

#define KEYIMAGE_WIDTH  17
#define KEYIMAGE_HEIGHT 14
#define KEYIMAGE_COLORS 5

static const UBYTE keyimage_data[] =
{
	00,04,04,04,04,04,04,04,04,04,04,04,04,04,04,04,00,
	04,02,02,02,02,02,02,02,02,02,02,02,02,02,02,01,04,
	04,02,02,04,04,04,04,04,04,04,04,04,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,04,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,03,03,03,03,03,03,03,03,03,03,03,03,04,01,04,
	04,02,03,04,04,04,04,04,04,04,04,04,04,04,04,01,04,
	04,02,01,01,01,01,01,01,01,01,01,01,01,01,01,01,04,
	00,04,04,04,04,04,04,04,04,04,04,04,04,04,04,04,00
};

static const UBYTE keyimage_pal[] =
{
	0xb3,0xb3,0xb3,0x38,0x38,0x38,
	0xcc,0xcc,0xcc,0xbb,0xbb,0xbb,
	0x4d,0x4d,0x4d
};

const struct CoolImage cool_keyimage =
{
	keyimage_data,
	keyimage_pal,
	KEYIMAGE_WIDTH,
	KEYIMAGE_HEIGHT,
	KEYIMAGE_COLORS
};
