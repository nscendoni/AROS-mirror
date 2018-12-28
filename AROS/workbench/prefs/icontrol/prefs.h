/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: prefs.h 34357 2010-09-05 19:44:34Z mazze $

    Desc:
    Lang: English
*/

#ifndef _PREFS_H_
#define _PREFS_H_

#include <prefs/icontrol.h>
#include <dos/dos.h>

/*********************************************************************************************/

BOOL Prefs_HandleArgs(STRPTR from, BOOL use, BOOL save);
BOOL Prefs_ImportFH(BPTR fh);
BOOL Prefs_ExportFH(BPTR fh);
BOOL Prefs_Default(VOID);

/*********************************************************************************************/

extern struct IControlPrefs icontrolprefs;

/*********************************************************************************************/

#endif /* _PREFS_H_ */
