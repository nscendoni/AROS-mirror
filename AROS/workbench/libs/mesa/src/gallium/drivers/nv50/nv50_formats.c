/*
 * Copyright 2010 Christoph Bumiller
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "nv50_screen.h"
#include "nv50_texture.h"
#include "nv50_reg.h"
#include "pipe/p_defines.h"

#define A_(cr, cg, cb, ca, t0, t1, t2, t3, sz, r)	    \
   NV50TIC_0_0_MAPR_##cr | NV50TIC_0_0_TYPER_##t0 |         \
   NV50TIC_0_0_MAPG_##cg | NV50TIC_0_0_TYPEG_##t1 |	    \
   NV50TIC_0_0_MAPB_##cb | NV50TIC_0_0_TYPEB_##t2 |	    \
   NV50TIC_0_0_MAPA_##ca | NV50TIC_0_0_TYPEA_##t3 |         \
   NV50TIC_0_0_FMT_##sz,                                    \
   NV50TCL_VERTEX_ARRAY_ATTRIB_FORMAT_##sz |                \
   NV50TCL_VERTEX_ARRAY_ATTRIB_TYPE_##t0 |                  \
   (NV50TCL_VERTEX_ARRAY_ATTRIB_TYPE_##t0 << 3) | (r << 31)

#define B_(cr, cg, cb, ca, t0, t1, t2, t3, sz, r)   \
   NV50TIC_0_0_MAPR_##cr | NV50TIC_0_0_TYPER_##t0 | \
   NV50TIC_0_0_MAPG_##cg | NV50TIC_0_0_TYPEG_##t1 | \
   NV50TIC_0_0_MAPB_##cb | NV50TIC_0_0_TYPEB_##t2 | \
   NV50TIC_0_0_MAPA_##ca | NV50TIC_0_0_TYPEA_##t3 | \
   NV50TIC_0_0_FMT_##sz, 0

#define VERTEX_BUFFER PIPE_BIND_VERTEX_BUFFER
#define SAMPLER_VIEW  PIPE_BIND_SAMPLER_VIEW
#define RENDER_TARGET PIPE_BIND_RENDER_TARGET
#define DEPTH_STENCIL PIPE_BIND_DEPTH_STENCIL
#define SCANOUT       PIPE_BIND_SCANOUT

/* for vertex buffers: */
#define NV50TIC_0_0_FMT_8_8_8 NV50TIC_0_0_FMT_8_8_8_8
#define NV50TIC_0_0_FMT_16_16_16 NV50TIC_0_0_FMT_16_16_16_16
#define NV50TIC_0_0_FMT_32_32_32 NV50TIC_0_0_FMT_32_32_32_32

/* NOTE: using NV50_2D_DST_FORMAT for substitute formats used with 2D engine */

const struct nv50_format nv50_format_table[PIPE_FORMAT_COUNT] =
{
   /* COMMON FORMATS */

   [PIPE_FORMAT_B8G8R8A8_UNORM] = { NV50TCL_RT_FORMAT_A8R8G8B8_UNORM,
    A_(C2, C1, C0, C3, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 1),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET | SCANOUT },

   [PIPE_FORMAT_B8G8R8X8_UNORM] = { NV50TCL_RT_FORMAT_X8R8G8B8_UNORM,
    A_(C2, C1, C0, ONE, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 1),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET | SCANOUT },

   [PIPE_FORMAT_B8G8R8A8_SRGB] = { NV50TCL_RT_FORMAT_A8R8G8B8_SRGB,
    A_(C2, C1, C0, C3, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 1),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_B8G8R8X8_SRGB] = { NV50TCL_RT_FORMAT_X8R8G8B8_SRGB,
    A_(C2, C1, C0, ONE, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 1),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_B5G6R5_UNORM] = { NV50TCL_RT_FORMAT_R5G6B5_UNORM,
    B_(C2, C1, C0, ONE, UNORM, UNORM, UNORM, UNORM, 5_6_5, 1),
    SAMPLER_VIEW | RENDER_TARGET | SCANOUT },

   [PIPE_FORMAT_B5G5R5A1_UNORM] = { NV50TCL_RT_FORMAT_A1R5G5B5_UNORM,
    B_(C2, C1, C0, C3, UNORM, UNORM, UNORM, UNORM, 1_5_5_5, 1),
    SAMPLER_VIEW | RENDER_TARGET | SCANOUT },

   [PIPE_FORMAT_B4G4R4A4_UNORM] = { NV50_2D_DST_FORMAT_R16_UNORM,
    B_(C2, C1, C0, C3, UNORM, UNORM, UNORM, UNORM, 4_4_4_4, 1),
    SAMPLER_VIEW },

   [PIPE_FORMAT_R10G10B10A2_UNORM] = { NV50TCL_RT_FORMAT_A2B10G10R10_UNORM,
    A_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, 2_10_10_10, 0),
    SAMPLER_VIEW | RENDER_TARGET | VERTEX_BUFFER | SCANOUT },

   [PIPE_FORMAT_B10G10R10A2_UNORM] = { NV50TCL_RT_FORMAT_A2R10G10B10_UNORM,
    A_(C2, C1, C0, C3, UNORM, UNORM, UNORM, UNORM, 2_10_10_10, 1),
    SAMPLER_VIEW | RENDER_TARGET | VERTEX_BUFFER },

   /* DEPTH/STENCIL FORMATS */

   [PIPE_FORMAT_Z16_UNORM] = { NV50TCL_ZETA_FORMAT_Z16_UNORM,
    B_(C0, C0, C0, ONE, UNORM, UINT, UINT, UINT, 16_DEPTH, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   [PIPE_FORMAT_Z24_UNORM_S8_USCALED] = { NV50TCL_ZETA_FORMAT_S8Z24_UNORM,
    B_(C0, C0, C0, ONE, UNORM, UINT, UINT, UINT, 8_24, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   [PIPE_FORMAT_Z24X8_UNORM] = { NV50TCL_ZETA_FORMAT_X8Z24_UNORM,
    B_(C0, C0, C0, ONE, UNORM, UINT, UINT, UINT, 8_24, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   [PIPE_FORMAT_S8_USCALED_Z24_UNORM] = { NV50TCL_ZETA_FORMAT_S8Z24_UNORM,
    B_(C1, C1, C1, ONE, UINT, UNORM, UINT, UINT, 24_8, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   [PIPE_FORMAT_Z32_FLOAT] = { NV50TCL_ZETA_FORMAT_Z32_FLOAT,
    B_(C0, C0, C0, ONE, FLOAT, UINT, UINT, UINT, 32_DEPTH, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   [PIPE_FORMAT_Z32_FLOAT_S8X24_USCALED] = {
    NV50TCL_ZETA_FORMAT_Z32_FLOAT_X24S8_UNORM,
    B_(C0, C0, C0, ONE, FLOAT, UINT, UINT, UINT, 32_8, 0),
    SAMPLER_VIEW | DEPTH_STENCIL },

   /* LUMINANCE, ALPHA, INTENSITY */

   [PIPE_FORMAT_L8_UNORM] = { NV50_2D_DST_FORMAT_R8_UNORM,
    A_(C0, C0, C0, ONE, UNORM, UNORM, UNORM, UNORM, 8, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_L8_SRGB] = { NV50_2D_DST_FORMAT_R8_UNORM,
    A_(C0, C0, C0, ONE, UNORM, UNORM, UNORM, UNORM, 8, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_I8_UNORM] = { NV50_2D_DST_FORMAT_R8_UNORM,
    A_(C0, C0, C0, C0, UNORM, UNORM, UNORM, UNORM, 8, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_A8_UNORM] = { NV50TCL_RT_FORMAT_A8_UNORM,
    A_(ZERO, ZERO, ZERO, C0, UNORM, UNORM, UNORM, UNORM, 8, 0),
    SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_L8A8_UNORM] = { NV50_2D_DST_FORMAT_R16_UNORM,
    A_(C0, C0, C0, C1, UNORM, UNORM, UNORM, UNORM, 8_8, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_L8A8_SRGB] = { 0,
    A_(C0, C0, C0, C1, UNORM, UNORM, UNORM, UNORM, 8_8, 0),
    SAMPLER_VIEW },

   /* DXT, RGTC */

   [PIPE_FORMAT_DXT1_RGB] = { 0,
    B_(C0, C1, C2, ONE, UNORM, UNORM, UNORM, UNORM, DXT1, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_DXT1_RGBA] = { 0,
    B_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, DXT1, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_DXT3_RGBA] = { 0,
    B_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, DXT3, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_DXT5_RGBA] = { 0,
    B_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, DXT5, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_RGTC1_UNORM] = { 0,
    B_(C0, ZERO, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, RGTC1, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_RGTC1_SNORM] = { 0,
    B_(C0, ZERO, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, RGTC1, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_RGTC2_UNORM] = { 0,
    B_(C0, C1, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, RGTC2, 0),
    SAMPLER_VIEW },

   [PIPE_FORMAT_RGTC2_SNORM] = { 0,
    B_(C0, C1, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, RGTC2, 0),
    SAMPLER_VIEW },

   /* FLOAT 16 */

   [PIPE_FORMAT_R16G16B16A16_FLOAT] = { NV50TCL_RT_FORMAT_R16G16B16A16_FLOAT,
    A_(C0, C1, C2, C3, FLOAT, FLOAT, FLOAT, FLOAT, 16_16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16G16B16_FLOAT] = { NV50TCL_RT_FORMAT_R16G16B16X16_FLOAT,
    A_(C0, C1, C2, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16G16_FLOAT] = { NV50TCL_RT_FORMAT_R16G16_FLOAT,
    A_(C0, C1, ZERO, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16_FLOAT] = { NV50TCL_RT_FORMAT_R16_FLOAT,
    A_(C0, ZERO, ZERO, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* FLOAT 32 */

   [PIPE_FORMAT_R32G32B32A32_FLOAT] = { NV50TCL_RT_FORMAT_R32G32B32A32_FLOAT,
    A_(C0, C1, C2, C3, FLOAT, FLOAT, FLOAT, FLOAT, 32_32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R32G32B32_FLOAT] = { NV50TCL_RT_FORMAT_R32G32B32X32_FLOAT,
    A_(C0, C1, C2, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R32G32_FLOAT] = { NV50TCL_RT_FORMAT_R32G32_FLOAT,
    A_(C0, C1, ZERO, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R32_FLOAT] = { NV50TCL_RT_FORMAT_R32_FLOAT,
    A_(C0, ZERO, ZERO, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* ODD FORMATS */

   [PIPE_FORMAT_R11G11B10_FLOAT] = { NV50TCL_RT_FORMAT_B10G11R11_FLOAT,
    B_(C0, C1, C2, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 10_11_11, 0),
    SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R9G9B9E5_FLOAT] = { 0,
    B_(C0, C1, C2, ONE, FLOAT, FLOAT, FLOAT, FLOAT, 5_9_9_9, 0),
    SAMPLER_VIEW },

   /* SNORM 32 */

   [PIPE_FORMAT_R32G32B32A32_SNORM] = { 0,
    A_(C0, C1, C2, C3, FLOAT, FLOAT, FLOAT, FLOAT, 32_32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32B32_SNORM] = { 0,
    A_(C0, C1, C2, ONE, SNORM, SNORM, SNORM, SNORM, 32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32_SNORM] = { 0,
    A_(C0, C1, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, 32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32_SNORM] = { 0,
    A_(C0, ZERO, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, 32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* UNORM 32 */

   [PIPE_FORMAT_R32G32B32A32_UNORM] = { 0,
    A_(C0, C1, C2, C3, FLOAT, FLOAT, FLOAT, FLOAT, 32_32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32B32_UNORM] = { 0,
    A_(C0, C1, C2, ONE, UNORM, UNORM, UNORM, UNORM, 32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32_UNORM] = { 0,
    A_(C0, C1, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, 32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32_UNORM] = { 0,
    A_(C0, ZERO, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, 32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* SNORM 16 */

   [PIPE_FORMAT_R16G16B16A16_SNORM] = { NV50TCL_RT_FORMAT_R16G16B16A16_SNORM,
    A_(C0, C1, C2, C3, SNORM, SNORM, SNORM, SNORM, 16_16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16G16B16_SNORM] = { 0,
    A_(C0, C1, C2, ONE, SNORM, SNORM, SNORM, SNORM, 16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16_SNORM] = { NV50TCL_RT_FORMAT_R16G16_SNORM,
    A_(C0, C1, C2, C3, SNORM, SNORM, SNORM, SNORM, 16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16_SNORM] = { NV50TCL_RT_FORMAT_R16_SNORM,
    A_(C0, ZERO, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, 16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* UNORM 16 */

   [PIPE_FORMAT_R16G16B16A16_UNORM] = { NV50TCL_RT_FORMAT_R16G16B16A16_UNORM,
    A_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, 16_16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16G16B16_UNORM] = { 0,
    A_(C0, C1, C2, ONE, UNORM, UNORM, UNORM, UNORM, 16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16_UNORM] = { NV50TCL_RT_FORMAT_R16G16_UNORM,
    A_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, 16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R16_UNORM] = { NV50TCL_RT_FORMAT_R16_UNORM,
    A_(C0, ZERO, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, 16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* SNORM 8 */

   [PIPE_FORMAT_R8G8B8A8_SNORM] = { NV50TCL_RT_FORMAT_A8B8G8R8_SNORM,
    A_(C0, C1, C2, C3, SNORM, SNORM, SNORM, SNORM, 8_8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8G8B8_SNORM] = { 0,
    A_(C0, C1, C2, ONE, SNORM, SNORM, SNORM, SNORM, 8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8G8_SNORM] = { NV50TCL_RT_FORMAT_R8G8_SNORM,
    A_(C0, C1, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, 8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8_SNORM] = { NV50TCL_RT_FORMAT_R8_SNORM,
    A_(C0, ZERO, ZERO, ONE, SNORM, SNORM, SNORM, SNORM, 8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* UNORM 8 */

   [PIPE_FORMAT_R8G8B8A8_UNORM] = { NV50TCL_RT_FORMAT_A8B8G8R8_UNORM,
    A_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8G8B8A8_SRGB] = { NV50TCL_RT_FORMAT_A8B8G8R8_SRGB,
    A_(C0, C1, C2, C3, UNORM, UNORM, UNORM, UNORM, 8_8_8_8, 0),
    SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8G8B8_UNORM] = { NV50TCL_RT_FORMAT_X8B8G8R8_UNORM,
    A_(C0, C1, C2, ONE, UNORM, UNORM, UNORM, UNORM, 8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8G8B8_SRGB] = { NV50TCL_RT_FORMAT_X8B8G8R8_SRGB,
    A_(C0, C1, C2, ONE, UNORM, UNORM, UNORM, UNORM, 8_8_8, 0),
    SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8G8_UNORM] = { NV50TCL_RT_FORMAT_R8G8_UNORM,
    A_(C0, C1, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, 8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   [PIPE_FORMAT_R8_UNORM] = { NV50TCL_RT_FORMAT_R8_UNORM,
    A_(C0, ZERO, ZERO, ONE, UNORM, UNORM, UNORM, UNORM, 8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW | RENDER_TARGET },

   /* SSCALED 32 */

   [PIPE_FORMAT_R32G32B32A32_SSCALED] = { 0,
    A_(C0, C1, C2, C3, SSCALED, SSCALED, SSCALED, SSCALED, 32_32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32B32_SSCALED] = { 0,
    A_(C0, C1, C2, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32_SSCALED] = { 0,
    A_(C0, C1, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32_SSCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* USCALED 32 */

   [PIPE_FORMAT_R32G32B32A32_USCALED] = { 0,
    A_(C0, C1, C2, C3, USCALED, USCALED, USCALED, USCALED, 32_32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32B32_USCALED] = { 0,
    A_(C0, C1, C2, ONE, USCALED, USCALED, USCALED, USCALED, 32_32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32G32_USCALED] = { 0,
    A_(C0, C1, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 32_32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R32_USCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 32, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* SSCALED 16 */

   [PIPE_FORMAT_R16G16B16A16_SSCALED] = { 0,
    A_(C0, C1, C2, C3, SSCALED, SSCALED, SSCALED, SSCALED, 16_16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16B16_SSCALED] = { 0,
    A_(C0, C1, C2, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16_SSCALED] = { 0,
    A_(C0, C1, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16_SSCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* USCALED 16 */

   [PIPE_FORMAT_R16G16B16A16_USCALED] = { 0,
    A_(C0, C1, C2, C3, USCALED, USCALED, USCALED, USCALED, 16_16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16B16_USCALED] = { 0,
    A_(C0, C1, C2, ONE, USCALED, USCALED, USCALED, USCALED, 16_16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16G16_USCALED] = { 0,
    A_(C0, C1, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 16_16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R16_USCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 16, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* SSCALED 8 */

   [PIPE_FORMAT_R8G8B8A8_SSCALED] = { 0,
    A_(C0, C1, C2, C3, SSCALED, SSCALED, SSCALED, SSCALED, 8_8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8G8B8_SSCALED] = { 0,
    A_(C0, C1, C2, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8G8_SSCALED] = { 0,
    A_(C0, C1, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8_SSCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, SSCALED, SSCALED, SSCALED, SSCALED, 8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   /* USCALED 8 */

   [PIPE_FORMAT_R8G8B8A8_USCALED] = { 0,
    A_(C0, C1, C2, C3, USCALED, USCALED, USCALED, USCALED, 8_8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8G8B8_USCALED] = { 0,
    A_(C0, C1, C2, ONE, USCALED, USCALED, USCALED, USCALED, 8_8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8G8_USCALED] = { 0,
    A_(C0, C1, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 8_8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },

   [PIPE_FORMAT_R8_USCALED] = { 0,
    A_(C0, ZERO, ZERO, ONE, USCALED, USCALED, USCALED, USCALED, 8, 0),
    VERTEX_BUFFER | SAMPLER_VIEW },
};
