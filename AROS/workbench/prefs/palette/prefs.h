/*
    Copyright © 2010, The AROS Development Team. All rights reserved.
    $Id: prefs.h 32694 2010-02-18 20:46:47Z mazze $

    Desc:
    Lang: English
*/

#ifndef _PREFS_H_
#define _PREFS_H_

#include <prefs/palette.h>
#include <dos/dos.h>

/*********************************************************************************************/

BOOL Prefs_HandleArgs(STRPTR from, BOOL use, BOOL save);
BOOL Prefs_ImportFH(BPTR fh);
BOOL Prefs_ExportFH(BPTR fh);
BOOL Prefs_Default(VOID);

/*********************************************************************************************/

extern struct PalettePrefs paletteprefs;

/*********************************************************************************************/

#endif /* _PREFS_H_ */
