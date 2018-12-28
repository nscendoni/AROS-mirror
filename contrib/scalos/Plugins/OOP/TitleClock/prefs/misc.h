/*
 *  misc.h - routines for misc stuff
 *
 * $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
 * $Revision: 48481 $
 *
 *  0.1
 *  20010718 DM Created. Added routines for calculating length of a string in a given font (ignoring underscores) and the longest in an array of values
 *
 */

#ifndef MISC_H
#define MISC_H

WORD USTextLength(CONST_STRPTR string, struct TextFont *tf);
WORD MaxLen(int count, ...);

extern int KPrintF(CONST_STRPTR fmt, ...);

#define	d1(x)		;
#define	d2(x)		x;

#endif /* MISC_H */

