/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: prefs.h 48674 2014-01-02 17:51:04Z neil $

    Desc:
    Lang: English
*/

#ifndef _PREFS_H_
#define _PREFS_H_

#include <libraries/reqtools.h>
#include <dos/dos.h>

/*********************************************************************************************/

BOOL Prefs_HandleArgs(STRPTR from, BOOL use, BOOL save);
BOOL Prefs_ImportFH(BPTR fh);
BOOL Prefs_ExportFH(BPTR fh);
BOOL Prefs_Default(VOID);

/*********************************************************************************************/

extern struct ReqToolsPrefs reqtoolsprefs;

/*********************************************************************************************/

#endif /* _PREFS_H_ */
