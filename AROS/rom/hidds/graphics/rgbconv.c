/*
    Copyright � 2013, The AROS Development Team. All rights reserved.
    $Id: rgbconv.c 49014 2014-05-18 18:18:56Z deadwood $
*/

#include <exec/types.h>
#include <hidd/graphics.h>

#include "colorconv/rgbconv_macros.h"
#include "colorconv/rgbconv_rgbswap.h"

#include "colorconv/rgbconv_bgra32.h"
#include "colorconv/rgbconv_xrgb32.h"
#include "colorconv/rgbconv_argb32.h"
#include "colorconv/rgbconv_rgba32.h"
#include "colorconv/rgbconv_abgr32.h"
#include "colorconv/rgbconv_rgb24.h"
#include "colorconv/rgbconv_bgr24.h"
#include "colorconv/rgbconv_rgb15.h"
#include "colorconv/rgbconv_bgr15.h"
#include "colorconv/rgbconv_rgb16.h"
#include "colorconv/rgbconv_bgr16.h"
#include "colorconv/rgbconv_rgb16oe.h"
#include "colorconv/rgbconv_bgr16oe.h"
#include "colorconv/rgbconv_rgb15oe.h"
#include "colorconv/rgbconv_bgr15oe.h"
#include "colorconv/rgbconv_bgrx32.h"
#include "colorconv/rgbconv_rgbx32.h"
#include "colorconv/rgbconv_xbgr32.h"

#define SCCF(SRCPIXFMT, DSTPIXFMT) \
    rgbconvertfuncs[FMT_##SRCPIXFMT - FIRST_RGB_STDPIXFMT][FMT_##DSTPIXFMT - FIRST_RGB_STDPIXFMT] = convert_##SRCPIXFMT##_##DSTPIXFMT##_generic;

void SetRGBConversionFunctions(HIDDT_RGBConversionFunction rgbconvertfuncs[NUM_RGB_STDPIXFMT][NUM_RGB_STDPIXFMT])
{
    /* ARGB32 to #? */
    SCCF(ARGB32,RGB16)   SCCF(ARGB32,BGR16)   SCCF(ARGB32,RGB15)   SCCF(ARGB32,BGR15)
    SCCF(ARGB32,BGRA32)  SCCF(ARGB32,RGBA32)  SCCF(ARGB32,ABGR32)  SCCF(ARGB32,RGB24)
    SCCF(ARGB32,BGR24)   SCCF(ARGB32,RGB16OE) SCCF(ARGB32,BGR16OE) SCCF(ARGB32,RGB15OE)
    SCCF(ARGB32,BGR15OE) SCCF(ARGB32,XRGB32)  SCCF(ARGB32,BGRX32)  SCCF(ARGB32,RGBX32)
    SCCF(ARGB32,XBGR32)

    /* BGRA32 to #? */
    SCCF(BGRA32,RGB16)   SCCF(BGRA32,BGR16)   SCCF(BGRA32,RGB15)   SCCF(BGRA32,BGR15)
    SCCF(BGRA32,ARGB32)  SCCF(BGRA32,RGBA32)  SCCF(BGRA32,ABGR32)  SCCF(BGRA32,RGB24)
    SCCF(BGRA32,BGR24)   SCCF(BGRA32,RGB16OE) SCCF(BGRA32,BGR16OE) SCCF(BGRA32,RGB15OE)
    SCCF(BGRA32,BGR15OE) SCCF(BGRA32,XRGB32)  SCCF(BGRA32,BGRX32)  SCCF(BGRA32,RGBX32)
    SCCF(BGRA32,XBGR32)

    /* RGBA32 to #? */
    SCCF(RGBA32,RGB16)   SCCF(RGBA32,BGR16)   SCCF(RGBA32,RGB15)   SCCF(RGBA32,BGR15)
    SCCF(RGBA32,BGRA32)  SCCF(RGBA32,ARGB32)  SCCF(RGBA32,ABGR32)  SCCF(RGBA32,RGB24)
    SCCF(RGBA32,BGR24)   SCCF(RGBA32,RGB16OE) SCCF(RGBA32,BGR16OE) SCCF(RGBA32,RGB15OE)
    SCCF(RGBA32,BGR15OE) SCCF(RGBA32,XRGB32)  SCCF(RGBA32,BGRX32)  SCCF(RGBA32,RGBX32)
    SCCF(RGBA32,XBGR32)

    /* ABGR32 to #? */
    SCCF(ABGR32,RGB16)   SCCF(ABGR32,BGR16)   SCCF(ABGR32,RGB15)   SCCF(ABGR32,BGR15)
    SCCF(ABGR32,BGRA32)  SCCF(ABGR32,ARGB32)  SCCF(ABGR32,RGBA32)  SCCF(ABGR32,RGB24)
    SCCF(ABGR32,BGR24)   SCCF(ABGR32,RGB16OE) SCCF(ABGR32,BGR16OE) SCCF(ABGR32,RGB15OE)
    SCCF(ABGR32,BGR15OE) SCCF(ABGR32,XRGB32)  SCCF(ABGR32,BGRX32)  SCCF(ABGR32,RGBX32)
    SCCF(ABGR32,XBGR32)

    /* RGB24 to #? */
    SCCF(RGB24,RGB16)    SCCF(RGB24,BGR16)    SCCF(RGB24,RGB15)    SCCF(RGB24,BGR15)
    SCCF(RGB24,ARGB32)   SCCF(RGB24,BGRA32)   SCCF(RGB24,RGBA32)   SCCF(RGB24,ABGR32)
    SCCF(RGB24,BGR24)    SCCF(RGB24,RGB16OE)  SCCF(RGB24,BGR16OE)  SCCF(RGB24,RGB15OE)
    SCCF(RGB24,BGR15OE)  SCCF(RGB24,XRGB32)   SCCF(RGB24,BGRX32)   SCCF(RGB24,RGBX32)
    SCCF(RGB24,XBGR32)

    /* BGR24 to #? */
    SCCF(BGR24,RGB16)    SCCF(BGR24,BGR16)    SCCF(BGR24,RGB15)    SCCF(BGR24,BGR15)
    SCCF(BGR24,ARGB32)   SCCF(BGR24,BGRA32)   SCCF(BGR24,RGBA32)   SCCF(BGR24,ABGR32)
    SCCF(BGR24,RGB24)    SCCF(BGR24,RGB16OE)  SCCF(BGR24,BGR16OE)  SCCF(BGR24,RGB15OE)
    SCCF(BGR24,BGR15OE)  SCCF(BGR24,XRGB32)   SCCF(BGR24,BGRX32)   SCCF(BGR24,RGBX32)
    SCCF(BGR24,XBGR32)

    /* RGB15 to #? */
    SCCF(RGB15,RGB16)    SCCF(RGB15,BGR16)    SCCF(RGB15,BGR15)    SCCF(RGB15,ARGB32)
    SCCF(RGB15,BGRA32)   SCCF(RGB15,RGBA32)   SCCF(RGB15,ABGR32)   SCCF(RGB15,RGB24)
    SCCF(RGB15,BGR24)    SCCF(RGB15,RGB16OE)  SCCF(RGB15,RGB15OE)  SCCF(RGB15,BGR16OE)
    SCCF(RGB15,BGR15OE)  SCCF(RGB15,XRGB32)   SCCF(RGB15,BGRX32)   SCCF(RGB15,RGBX32)
    SCCF(RGB15,XBGR32)

    /* BGR15 to #? */
    SCCF(BGR15,RGB16)    SCCF(BGR15,BGR16)    SCCF(BGR15,RGB15)    SCCF(BGR15,ARGB32)
    SCCF(BGR15,BGRA32)   SCCF(BGR15,RGBA32)   SCCF(BGR15,ABGR32)   SCCF(BGR15,RGB24)
    SCCF(BGR15,BGR24)    SCCF(BGR15,RGB16OE)  SCCF(BGR15,RGB15OE)  SCCF(BGR15,BGR16OE)
    SCCF(BGR15,BGR15OE)  SCCF(BGR15,XRGB32)   SCCF(BGR15,BGRX32)   SCCF(BGR15,RGBX32)
    SCCF(BGR15,XBGR32)

    /* RGB16 to #? */
    SCCF(RGB16,RGB15)    SCCF(RGB16,BGR16)    SCCF(RGB16,BGR15)    SCCF(RGB16,ARGB32)
    SCCF(RGB16,BGRA32)   SCCF(RGB16,RGBA32)   SCCF(RGB16,ABGR32)   SCCF(RGB16,RGB24)
    SCCF(RGB16,BGR24)    SCCF(RGB16,RGB16OE)  SCCF(RGB16,RGB15OE)  SCCF(RGB16,BGR16OE)
    SCCF(RGB16,BGR15OE)  SCCF(RGB16,XRGB32)   SCCF(RGB16,BGRX32)   SCCF(RGB16,RGBX32)
    SCCF(RGB16,XBGR32)

    /* BGR16 to #? */
    SCCF(BGR16,RGB15)    SCCF(BGR16,RGB16)    SCCF(BGR16,BGR15)    SCCF(BGR16,ARGB32)
    SCCF(BGR16,BGRA32)   SCCF(BGR16,RGBA32)   SCCF(BGR16,ABGR32)   SCCF(BGR16,RGB24)
    SCCF(BGR16,BGR24)    SCCF(BGR16,RGB16OE)  SCCF(BGR16,RGB15OE)  SCCF(BGR16,BGR16OE)
    SCCF(BGR16,BGR15OE)  SCCF(BGR16,XRGB32)   SCCF(BGR16,BGRX32)   SCCF(BGR16,RGBX32)
    SCCF(BGR16,XBGR32)

    /* RGB16OE to #? */
    SCCF(RGB16OE,RGB16)   SCCF(RGB16OE,RGB15)  SCCF(RGB16OE,BGR16)   SCCF(RGB16OE,BGR15)
    SCCF(RGB16OE,ARGB32)  SCCF(RGB16OE,BGRA32) SCCF(RGB16OE,RGBA32)  SCCF(RGB16OE,ABGR32)
    SCCF(RGB16OE,RGB24)   SCCF(RGB16OE,BGR24)  SCCF(RGB16OE,RGB15OE) SCCF(RGB16OE,BGR16OE)
    SCCF(RGB16OE,BGR15OE) SCCF(RGB16OE,XRGB32) SCCF(RGB16OE,BGRX32)  SCCF(RGB16OE,RGBX32)
    SCCF(RGB16OE,XBGR32)

    /* BGR16OE to #? */
    SCCF(BGR16OE,RGB16)   SCCF(BGR16OE,RGB15)  SCCF(BGR16OE,BGR16)   SCCF(BGR16OE,BGR15)
    SCCF(BGR16OE,ARGB32)  SCCF(BGR16OE,BGRA32) SCCF(BGR16OE,RGBA32)  SCCF(BGR16OE,ABGR32)
    SCCF(BGR16OE,RGB24)   SCCF(BGR16OE,BGR24)  SCCF(BGR16OE,RGB15OE) SCCF(BGR16OE,RGB16OE)
    SCCF(BGR16OE,BGR15OE) SCCF(BGR16OE,XRGB32) SCCF(BGR16OE,BGRX32)  SCCF(BGR16OE,RGBX32)
    SCCF(BGR16OE,XBGR32)

    /* RGB15OE to #? */
    SCCF(RGB15OE,RGB16)   SCCF(RGB15OE,RGB15)  SCCF(RGB15OE,BGR16)   SCCF(RGB15OE,BGR15)
    SCCF(RGB15OE,ARGB32)  SCCF(RGB15OE,BGRA32) SCCF(RGB15OE,RGBA32)  SCCF(RGB15OE,ABGR32)
    SCCF(RGB15OE,RGB24)   SCCF(RGB15OE,BGR24)  SCCF(RGB15OE,RGB16OE) SCCF(RGB15OE,BGR16OE)
    SCCF(RGB15OE,BGR15OE) SCCF(RGB15OE,XRGB32) SCCF(RGB15OE,BGRX32)  SCCF(RGB15OE,RGBX32)
    SCCF(RGB15OE,XBGR32)

    /* BGR15OE to #? */
    SCCF(BGR15OE,RGB16)   SCCF(BGR15OE,RGB15)  SCCF(BGR15OE,BGR16)   SCCF(BGR15OE,BGR15)
    SCCF(BGR15OE,ARGB32)  SCCF(BGR15OE,BGRA32) SCCF(BGR15OE,RGBA32)  SCCF(BGR15OE,ABGR32)
    SCCF(BGR15OE,RGB24)   SCCF(BGR15OE,BGR24)  SCCF(BGR15OE,RGB16OE) SCCF(BGR15OE,BGR16OE)
    SCCF(BGR15OE,RGB15OE) SCCF(BGR15OE,XRGB32) SCCF(BGR15OE,BGRX32)  SCCF(BGR15OE,RGBX32)
    SCCF(BGR15OE,XBGR32)

    /* XRGB32 to #? */
    SCCF(XRGB32,RGB16)   SCCF(XRGB32,BGR16)   SCCF(XRGB32,RGB15)   SCCF(XRGB32,BGR15)
    SCCF(XRGB32,ARGB32)  SCCF(XRGB32,BGRA32)  SCCF(XRGB32,RGBA32)  SCCF(XRGB32,ABGR32)
    SCCF(XRGB32,RGB24)   SCCF(XRGB32,BGR24)   SCCF(XRGB32,RGB16OE) SCCF(XRGB32,BGR16OE)
    SCCF(XRGB32,RGB15OE) SCCF(XRGB32,BGR15OE) SCCF(XRGB32,BGRX32)  SCCF(XRGB32,RGBX32)
    SCCF(XRGB32,XBGR32)

    /* BGRX32 to #? */
    SCCF(BGRX32,RGB16)   SCCF(BGRX32,BGR16)   SCCF(BGRX32,RGB15)   SCCF(BGRX32,BGR15)
    SCCF(BGRX32,ARGB32)  SCCF(BGRX32,BGRA32)  SCCF(BGRX32,RGBA32)  SCCF(BGRX32,ABGR32)
    SCCF(BGRX32,RGB24)   SCCF(BGRX32,BGR24)   SCCF(BGRX32,RGB16OE) SCCF(BGRX32,BGR16OE)
    SCCF(BGRX32,RGB15OE) SCCF(BGRX32,BGR15OE) SCCF(BGRX32,XRGB32)  SCCF(BGRX32,RGBX32)
    SCCF(BGRX32,XBGR32)

    /* RGBX32 to #? */
    SCCF(RGBX32,RGB16)   SCCF(RGBX32,BGR16)   SCCF(RGBX32,RGB15)   SCCF(RGBX32,BGR15)
    SCCF(RGBX32,BGRA32)  SCCF(RGBX32,ARGB32)  SCCF(RGBX32,ABGR32)  SCCF(RGBX32,RGBA32)
    SCCF(RGBX32,RGB24)   SCCF(RGBX32,BGR24)   SCCF(RGBX32,RGB16OE) SCCF(RGBX32,BGR16OE)
    SCCF(RGBX32,RGB15OE) SCCF(RGBX32,BGR15OE) SCCF(RGBX32,XRGB32)  SCCF(RGBX32,BGRX32)
    SCCF(RGBX32,XBGR32)

    /* XBGR32 to #? */
    SCCF(XBGR32,RGB16)   SCCF(XBGR32,BGR16)   SCCF(XBGR32,RGB15)   SCCF(XBGR32,BGR15)
    SCCF(XBGR32,BGRA32)  SCCF(XBGR32,ARGB32)  SCCF(XBGR32,RGBA32)  SCCF(XBGR32,ABGR32)
    SCCF(XBGR32,RGB24)   SCCF(XBGR32,BGR24)   SCCF(XBGR32,RGB16OE) SCCF(XBGR32,BGR16OE)
    SCCF(XBGR32,RGB15OE) SCCF(XBGR32,BGR15OE) SCCF(XBGR32,XRGB32)  SCCF(XBGR32,BGRX32)
    SCCF(XBGR32,RGBX32)
}
