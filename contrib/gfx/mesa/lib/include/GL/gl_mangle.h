/* $Id$ */

/*
 * Mesa 3-D graphics library
 * Version:  3.0
 * Copyright (C) 1995-1998  Brian Paul
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


/*
 * $Log$
 * Revision 1.1  2005/01/11 14:58:29  NicJA
 * AROSMesa 3.0
 *
 * - Based on the official mesa 3 code with major patches to the amigamesa driver code to get it working.
 * - GLUT not yet started (ive left the _old_ mesaaux, mesatk and demos in for this reason)
 * - Doesnt yet work - the _db functions seem to be writing the data incorrectly, and color picking also seems broken somewhat - giving most things a blue tinge (those that are currently working)
 *
 * Revision 3.2  1998/03/26 02:43:00  brianp
 * removed ^M characters
 *
 * Revision 3.1  1998/03/17 02:40:52  brianp
 * updated by Randy Frank
 *
 * Revision 3.0  1998/02/20 05:04:45  brianp
 * initial rev
 *
 */


/*
 * If you compile Mesa with USE_MGL_NAMESPACE defined then you can link
 * your application both with OpenGL and Mesa.  The Mesa functions will
 * be redefined so they are prefixed with "mgl" instead of "gl".
 * Contributed by Randy Frank (rfrank@rsinc.com)
 */


#define glClearIndex mglClearIndex
#define glClearColor mglClearColor
#define glClear  mglClear
#define glIndexMask mglIndexMask
#define glColorMask mglColorMask
#define glAlphaFunc mglAlphaFunc
#define glBlendFunc mglBlendFunc
#define glLogicOp mglLogicOp
#define glCullFace  mglCullFace
#define glFrontFace mglFrontFace
#define glPointSize mglPointSize
#define glLineWidth mglLineWidth
#define glLineStipple mglLineStipple
#define glPolygonMode mglPolygonMode
#define glPolygonOffset mglPolygonOffset
#define glPolygonStipple mglPolygonStipple
#define glGetPolygonStipple mglGetPolygonStipple
#define glEdgeFlag mglEdgeFlag
#define glEdgeFlagv mglEdgeFlagv
#define glScissor  mglScissor
#define glClipPlane mglClipPlane
#define glGetClipPlane mglGetClipPlane
#define glDrawBuffer mglDrawBuffer
#define glReadBuffer mglReadBuffer
#define glEnable mglEnable
#define glDisable mglDisable
#define glIsEnabled mglIsEnabled
#define glEnableClientState mglEnableClientState
#define glDisableClientState mglDisableClientState
#define glGetBooleanv mglGetBooleanv
#define glGetDoublev mglGetDoublev
#define glGetFloatv mglGetFloatv
#define glGetIntegerv mglGetIntegerv
#define glPushAttrib mglPushAttrib
#define glPopAttrib mglPopAttrib
#define glPushClientAttrib mglPushClientAttrib
#define glPopClientAttrib mglPopClientAttrib
#define glRenderMode mglRenderMode
#define glGetError mglGetError
#define glGetString mglGetString
#define glFinish mglFinish
#define glFlush mglFlush
#define glHint mglHint
#define glClearDepth mglClearDepth
#define glDepthFunc mglDepthFunc
#define glDepthMask mglDepthMask
#define glDepthRange mglDepthRange
#define glClearAccum mglClearAccum
#define glAccum mglAccum
#define glMatrixMode mglMatrixMode
#define glOrtho mglOrtho
#define glFrustum mglFrustum
#define glViewport mglViewport
#define glPushMatrix mglPushMatrix
#define glPopMatrix mglPopMatrix
#define glLoadIdentity mglLoadIdentity
#define glLoadMatrixd mglLoadMatrixd
#define glLoadMatrixf mglLoadMatrixf
#define glMultMatrixd mglMultMatrixd
#define glMultMatrixf mglMultMatrixf
#define glRotated mglRotated
#define glRotatef mglRotatef
#define glScaled mglScaled
#define glScalef mglScalef
#define glTranslated mglTranslated
#define glTranslatef mglTranslatef
#define glIsList mglIsList
#define glDeleteLists mglDeleteLists
#define glGenLists mglGenLists
#define glNewList mglNewList
#define glEndList mglEndList
#define glCallList mglCallList
#define glCallLists mglCallLists
#define glListBase mglListBase
#define glBegin mglBegin
#define glEnd mglEnd
#define glVertex2d mglVertex2d
#define glVertex2f mglVertex2f
#define glVertex2i mglVertex2i
#define glVertex2s mglVertex2s
#define glVertex3d mglVertex3d
#define glVertex3f mglVertex3f
#define glVertex3i mglVertex3i
#define glVertex3s mglVertex3s
#define glVertex4d mglVertex4d
#define glVertex4f mglVertex4f
#define glVertex4i mglVertex4i
#define glVertex4s mglVertex4s
#define glVertex2dv mglVertex2dv
#define glVertex2fv mglVertex2fv
#define glVertex2iv mglVertex2iv
#define glVertex2sv mglVertex2sv
#define glVertex3dv mglVertex3dv
#define glVertex3fv mglVertex3fv
#define glVertex3iv mglVertex3iv
#define glVertex3sv mglVertex3sv
#define glVertex4dv mglVertex4dv
#define glVertex4fv mglVertex4fv
#define glVertex4iv mglVertex4iv
#define glVertex4sv mglVertex4sv
#define glNormal3b mglNormal3b
#define glNormal3d mglNormal3d
#define glNormal3f mglNormal3f
#define glNormal3i mglNormal3i
#define glNormal3s mglNormal3s
#define glNormal3bv mglNormal3bv
#define glNormal3dv mglNormal3dv
#define glNormal3fv mglNormal3fv
#define glNormal3iv mglNormal3iv
#define glNormal3sv mglNormal3sv
#define glIndexd mglIndexd
#define glIndexf mglIndexf
#define glIndexi mglIndexi
#define glIndexs mglIndexs
#define glIndexub mglIndexub
#define glIndexdv mglIndexdv
#define glIndexfv mglIndexfv
#define glIndexiv mglIndexiv
#define glIndexsv mglIndexsv
#define glIndexubv mglIndexubv
#define glColor3b mglColor3b
#define glColor3d mglColor3d
#define glColor3f mglColor3f
#define glColor3i mglColor3i
#define glColor3s mglColor3s
#define glColor3ub mglColor3ub
#define glColor3ui mglColor3ui
#define glColor3us mglColor3us
#define glColor4b mglColor4b
#define glColor4d mglColor4d
#define glColor4f mglColor4f
#define glColor4i mglColor4i
#define glColor4s mglColor4s
#define glColor4ub mglColor4ub
#define glColor4ui mglColor4ui
#define glColor4us mglColor4us
#define glColor3bv mglColor3bv
#define glColor3dv mglColor3dv
#define glColor3fv mglColor3fv
#define glColor3iv mglColor3iv
#define glColor3sv mglColor3sv
#define glColor3ubv mglColor3ubv
#define glColor3uiv mglColor3uiv
#define glColor3usv mglColor3usv
#define glColor4bv mglColor4bv
#define glColor4dv mglColor4dv
#define glColor4fv mglColor4fv
#define glColor4iv mglColor4iv
#define glColor4sv mglColor4sv
#define glColor4ubv mglColor4ubv
#define glColor4uiv mglColor4uiv
#define glColor4usv mglColor4usv
#define glTexCoord1d mglTexCoord1d
#define glTexCoord1f mglTexCoord1f
#define glTexCoord1i mglTexCoord1i
#define glTexCoord1s mglTexCoord1s
#define glTexCoord2d mglTexCoord2d
#define glTexCoord2f mglTexCoord2f
#define glTexCoord2i mglTexCoord2i
#define glTexCoord2s mglTexCoord2s
#define glTexCoord3d mglTexCoord3d
#define glTexCoord3f mglTexCoord3f
#define glTexCoord3i mglTexCoord3i
#define glTexCoord3s mglTexCoord3s
#define glTexCoord4d mglTexCoord4d
#define glTexCoord4f mglTexCoord4f
#define glTexCoord4i mglTexCoord4i
#define glTexCoord4s mglTexCoord4s
#define glTexCoord1dv mglTexCoord1dv
#define glTexCoord1fv mglTexCoord1fv
#define glTexCoord1iv mglTexCoord1iv
#define glTexCoord1sv mglTexCoord1sv
#define glTexCoord2dv mglTexCoord2dv
#define glTexCoord2fv mglTexCoord2fv
#define glTexCoord2iv mglTexCoord2iv
#define glTexCoord2sv mglTexCoord2sv
#define glTexCoord3dv mglTexCoord3dv
#define glTexCoord3fv mglTexCoord3fv
#define glTexCoord3iv mglTexCoord3iv
#define glTexCoord3sv mglTexCoord3sv
#define glTexCoord4dv mglTexCoord4dv
#define glTexCoord4fv mglTexCoord4fv
#define glTexCoord4iv mglTexCoord4iv
#define glTexCoord4sv mglTexCoord4sv
#define glRasterPos2d mglRasterPos2d
#define glRasterPos2f mglRasterPos2f
#define glRasterPos2i mglRasterPos2i
#define glRasterPos2s mglRasterPos2s
#define glRasterPos3d mglRasterPos3d
#define glRasterPos3f mglRasterPos3f
#define glRasterPos3i mglRasterPos3i
#define glRasterPos3s mglRasterPos3s
#define glRasterPos4d mglRasterPos4d
#define glRasterPos4f mglRasterPos4f
#define glRasterPos4i mglRasterPos4i
#define glRasterPos4s mglRasterPos4s
#define glRasterPos2dv mglRasterPos2dv
#define glRasterPos2fv mglRasterPos2fv
#define glRasterPos2iv mglRasterPos2iv
#define glRasterPos2sv mglRasterPos2sv
#define glRasterPos3dv mglRasterPos3dv
#define glRasterPos3fv mglRasterPos3fv
#define glRasterPos3iv mglRasterPos3iv
#define glRasterPos3sv mglRasterPos3sv
#define glRasterPos4dv mglRasterPos4dv
#define glRasterPos4fv mglRasterPos4fv
#define glRasterPos4iv mglRasterPos4iv
#define glRasterPos4sv mglRasterPos4sv
#define glRectd mglRectd
#define glRectf mglRectf
#define glRecti mglRecti
#define glRects mglRects
#define glRectdv mglRectdv
#define glRectfv mglRectfv
#define glRectiv mglRectiv
#define glRectsv mglRectsv
#define glVertexPointer mglVertexPointer
#define glNormalPointer mglNormalPointer
#define glColorPointer mglColorPointer
#define glIndexPointer mglIndexPointer
#define glTexCoordPointer mglTexCoordPointer
#define glEdgeFlagPointer mglEdgeFlagPointer
#define glGetPointerv mglGetPointerv
#define glArrayElement mglArrayElement
#define glDrawArrays mglDrawArrays
#define glDrawElements mglDrawElements
#define glInterleavedArrays mglInterleavedArrays
#define glShadeModel mglShadeModel
#define glLightf mglLightf
#define glLighti mglLighti
#define glLightfv mglLightfv
#define glLightiv mglLightiv
#define glGetLightfv mglGetLightfv
#define glGetLightiv mglGetLightiv
#define glLightModelf mglLightModelf
#define glLightModeli mglLightModeli
#define glLightModelfv mglLightModelfv
#define glLightModeliv mglLightModeliv
#define glMaterialf mglMaterialf
#define glMateriali mglMateriali
#define glMaterialfv mglMaterialfv
#define glMaterialiv mglMaterialiv
#define glGetMaterialfv mglGetMaterialfv
#define glGetMaterialiv mglGetMaterialiv
#define glColorMaterial mglColorMaterial
#define glPixelZoom mglPixelZoom
#define glPixelStoref mglPixelStoref
#define glPixelStorei mglPixelStorei
#define glPixelTransferf mglPixelTransferf
#define glPixelTransferi mglPixelTransferi
#define glPixelMapfv mglPixelMapfv
#define glPixelMapuiv mglPixelMapuiv
#define glPixelMapusv mglPixelMapusv
#define glGetPixelMapfv mglGetPixelMapfv
#define glGetPixelMapuiv mglGetPixelMapuiv
#define glGetPixelMapusv mglGetPixelMapusv
#define glBitmap mglBitmap
#define glReadPixels mglReadPixels
#define glDrawPixels mglDrawPixels
#define glCopyPixels mglCopyPixels
#define glStencilFunc mglStencilFunc
#define glStencilMask mglStencilMask
#define glStencilOp mglStencilOp
#define glClearStencil mglClearStencil
#define glTexGend mglTexGend
#define glTexGenf mglTexGenf
#define glTexGeni mglTexGeni
#define glTexGendv mglTexGendv
#define glTexGenfv mglTexGenfv
#define glTexGeniv mglTexGeniv
#define glGetTexGendv mglGetTexGendv
#define glGetTexGenfv mglGetTexGenfv
#define glGetTexGeniv mglGetTexGeniv
#define glTexEnvf mglTexEnvf
#define glTexEnvi mglTexEnvi
#define glTexEnvfv mglTexEnvfv
#define glTexEnviv mglTexEnviv
#define glGetTexEnvfv mglGetTexEnvfv
#define glGetTexEnviv mglGetTexEnviv
#define glTexParameterf mglTexParameterf
#define glTexParameteri mglTexParameteri
#define glTexParameterfv mglTexParameterfv
#define glTexParameteriv mglTexParameteriv
#define glGetTexParameterfv mglGetTexParameterfv
#define glGetTexParameteriv mglGetTexParameteriv
#define glGetTexLevelParameterfv mglGetTexLevelParameterfv
#define glGetTexLevelParameteriv mglGetTexLevelParameteriv
#define glTexImage1D mglTexImage1D
#define glTexImage2D mglTexImage2D
#define glGetTexImage mglGetTexImage
#define glGenTextures mglGenTextures
#define glDeleteTextures mglDeleteTextures
#define glBindTexture mglBindTexture
#define glPrioritizeTextures mglPrioritizeTextures
#define glAreTexturesResident mglAreTexturesResident
#define glIsTexture mglIsTexture
#define glTexSubImage1D mglTexSubImage1D
#define glTexSubImage2D mglTexSubImage2D
#define glCopyTexImage1D mglCopyTexImage1D
#define glCopyTexImage2D mglCopyTexImage2D
#define glCopyTexSubImage1D mglCopyTexSubImage1D
#define glCopyTexSubImage2D mglCopyTexSubImage2D
#define glMap1d mglMap1d
#define glMap1f mglMap1f
#define glMap2d mglMap2d
#define glMap2f mglMap2f
#define glGetMapdv mglGetMapdv
#define glGetMapfv mglGetMapfv
#define glGetMapiv mglGetMapiv
#define glEvalCoord1d mglEvalCoord1d
#define glEvalCoord1f mglEvalCoord1f
#define glEvalCoord1dv mglEvalCoord1dv
#define glEvalCoord1fv mglEvalCoord1fv
#define glEvalCoord2d mglEvalCoord2d
#define glEvalCoord2f mglEvalCoord2f
#define glEvalCoord2dv mglEvalCoord2dv
#define glEvalCoord2fv mglEvalCoord2fv
#define glMapGrid1d mglMapGrid1d
#define glMapGrid1f mglMapGrid1f
#define glMapGrid2d mglMapGrid2d
#define glMapGrid2f mglMapGrid2f
#define glEvalPoint1 mglEvalPoint1
#define glEvalPoint2 mglEvalPoint2
#define glEvalMesh1 mglEvalMesh1
#define glEvalMesh2 mglEvalMesh2
#define glFogf mglFogf
#define glFogi mglFogi
#define glFogfv mglFogfv
#define glFogiv mglFogiv
#define glFeedbackBuffer mglFeedbackBuffer
#define glPassThrough mglPassThrough
#define glSelectBuffer mglSelectBuffer
#define glInitNames mglInitNames
#define glLoadName mglLoadName
#define glPushName mglPushName
#define glPopName mglPopName
#define glBlendEquationEXT mglBlendEquationEXT
#define glBlendColorEXT mglBlendColorEXT
#define glPolygonOffsetEXT mglPolygonOffsetEXT
#define glVertexPointerEXT mglVertexPointerEXT
#define glNormalPointerEXT mglNormalPointerEXT
#define glColorPointerEXT mglColorPointerEXT
#define glIndexPointerEXT mglIndexPointerEXT
#define glTexCoordPointerEXT mglTexCoordPointerEXT
#define glEdgeFlagPointerEXT mglEdgeFlagPointerEXT
#define glGetPointervEXT mglGetPointervEXT
#define glArrayElementEXT mglArrayElementEXT
#define glDrawArraysEXT mglDrawArraysEXT
#define glGenTexturesEXT mglGenTexturesEXT
#define glDeleteTexturesEXT mglDeleteTexturesEXT
#define glBindTextureEXT mglBindTextureEXT
#define glPrioritizeTexturesEXT mglPrioritizeTexturesEXT
#define glAreTexturesResidentEXT mglAreTexturesResidentEXT
#define glIsTextureEXT mglIsTextureEXT
#define glTexImage3DEXT mglTexImage3DEXT
#define glTexSubImage3DEXT mglTexSubImage3DEXT
#define glCopyTexSubImage3DEXT mglCopyTexSubImage3DEXT
#define glColorTableEXT mglColorTableEXT
#define glColorSubTableEXT mglColorSubTableEXT
#define glGetColorTableEXT mglGetColorTableEXT
#define glGetColorTableParameterfvEXT mglGetColorTableParameterfvEXT
#define glGetColorTableParameterivEXT mglGetColorTableParameterivEXT
#define glMultiTexCoord1dSGIS mglMultiTexCoord1dSGIS
#define glMultiTexCoord1dvSGIS mglMultiTexCoord1dvSGIS
#define glMultiTexCoord1fSGIS mglMultiTexCoord1fSGIS
#define glMultiTexCoord1fvSGIS mglMultiTexCoord1fvSGIS
#define glMultiTexCoord1iSGIS mglMultiTexCoord1iSGIS
#define glMultiTexCoord1ivSGIS mglMultiTexCoord1ivSGIS
#define glMultiTexCoord1sSGIS mglMultiTexCoord1sSGIS
#define glMultiTexCoord1svSGIS mglMultiTexCoord1svSGIS
#define glMultiTexCoord2dSGIS mglMultiTexCoord2dSGIS
#define glMultiTexCoord2dvSGIS mglMultiTexCoord2dvSGIS
#define glMultiTexCoord2fSGIS mglMultiTexCoord2fSGIS
#define glMultiTexCoord2fvSGIS mglMultiTexCoord2fvSGIS
#define glMultiTexCoord2iSGIS mglMultiTexCoord2iSGIS
#define glMultiTexCoord2ivSGIS mglMultiTexCoord2ivSGIS
#define glMultiTexCoord2sSGIS mglMultiTexCoord2sSGIS
#define glMultiTexCoord2svSGIS mglMultiTexCoord2svSGIS
#define glMultiTexCoord3dSGIS mglMultiTexCoord3dSGIS
#define glMultiTexCoord3dvSGIS mglMultiTexCoord3dvSGIS
#define glMultiTexCoord3fSGIS mglMultiTexCoord3fSGIS
#define glMultiTexCoord3fvSGIS mglMultiTexCoord3fvSGIS
#define glMultiTexCoord3iSGIS mglMultiTexCoord3iSGIS
#define glMultiTexCoord3ivSGIS mglMultiTexCoord3ivSGIS
#define glMultiTexCoord3sSGIS mglMultiTexCoord3sSGIS
#define glMultiTexCoord3svSGIS mglMultiTexCoord3svSGIS
#define glMultiTexCoord4dSGIS mglMultiTexCoord4dSGIS
#define glMultiTexCoord4dvSGIS mglMultiTexCoord4dvSGIS
#define glMultiTexCoord4fSGIS mglMultiTexCoord4fSGIS
#define glMultiTexCoord4fvSGIS mglMultiTexCoord4fvSGIS
#define glMultiTexCoord4iSGIS mglMultiTexCoord4iSGIS
#define glMultiTexCoord4ivSGIS mglMultiTexCoord4ivSGIS
#define glMultiTexCoord4sSGIS mglMultiTexCoord4sSGIS
#define glMultiTexCoord4svSGIS mglMultiTexCoord4svSGIS
#define glMultiTexCoordPointerSGIS mglMultiTexCoordPointerSGIS
#define glSelectTextureSGIS mglSelectTextureSGIS
#define glSelectTextureCoordSetSGIS mglSelectTextureCoordSetSGIS
#define glPointParameterfEXT mglPointParameterfEXT
#define glPointParameterfvEXT mglPointParameterfvEXT
#define glWindowPos2iMESA mglWindowPos2iMESA
#define glWindowPos2sMESA mglWindowPos2sMESA
#define glWindowPos2fMESA mglWindowPos2fMESA
#define glWindowPos2dMESA mglWindowPos2dMESA
#define glWindowPos2ivMESA mglWindowPos2ivMESA
#define glWindowPos2svMESA mglWindowPos2svMESA
#define glWindowPos2fvMESA mglWindowPos2fvMESA
#define glWindowPos2dvMESA mglWindowPos2dvMESA
#define glWindowPos3iMESA mglWindowPos3iMESA
#define glWindowPos3sMESA mglWindowPos3sMESA
#define glWindowPos3fMESA mglWindowPos3fMESA
#define glWindowPos3dMESA mglWindowPos3dMESA
#define glWindowPos3ivMESA mglWindowPos3ivMESA
#define glWindowPos3svMESA mglWindowPos3svMESA
#define glWindowPos3fvMESA mglWindowPos3fvMESA
#define glWindowPos3dvMESA mglWindowPos3dvMESA
#define glWindowPos4iMESA mglWindowPos4iMESA
#define glWindowPos4sMESA mglWindowPos4sMESA
#define glWindowPos4fMESA mglWindowPos4fMESA
#define glWindowPos4dMESA mglWindowPos4dMESA
#define glWindowPos4ivMESA mglWindowPos4ivMESA
#define glWindowPos4svMESA mglWindowPos4svMESA
#define glWindowPos4fvMESA mglWindowPos4fvMESA
#define glWindowPos4dvMESA mglWindowPos4dvMESA
#define glResizeBuffersMESA mglResizeBuffersMESA
#define glDrawRangeElements mglDrawRangeElements
#define glTexImage3D mglTexImage3D
#define glTexSubImage3D mglTexSubImage3D
#define glCopyTexSubImage3D mglCopyTexSubImage3D
