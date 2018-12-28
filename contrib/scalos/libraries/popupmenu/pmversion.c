//
// pmversion.c
//
// PopupMenu Library - Version information
//
// Copyright (C)1996-2001 Henrik Isaksson <henrik@boing.nu>
// All Rights Reserved.
//
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $
//

#if defined(__amigaos4__) || defined(__MORPHOS__)
#define __CPU__ "PPC"
#elif defined( _M68020)
#ifdef _M68030
#ifdef _M68040
#ifdef _M68060
#define __CPU__ "060"
#else
#define __CPU__ "040"
#endif
#else
#define __CPU__ "030"
#endif
#else
#define __CPU__ "020"
#endif
#else
#define __CPU__ "000"
#endif


char _LibID[] = "$VER: popupmenu.library-" __CPU__ " 10.11 (02.01.2010) �1996-2010 Henrik Isaksson";
