#ifndef LOCALE_H
#define LOCALE_H

/*
 *   VPDF
 * 
 *   Copyright � 2008 Christian Rosentreter <tokai@binaryriot.org>
 *   Copyright � 2012 Michal Zukowski, Michal Wozniak
 *   All rights reserved.
 *
 *   $Id: locale.h 44996 2012-06-10 16:07:18Z verhaegs $
 */

#define NEW_CATCOMP_ARRAY_IDS
#include "VPDF_strings.h"

void   locale_init(void);
void   locale_cleanup(void);
STRPTR locale_getstr(ULONG);

#define LOCSTR(x) locale_getstr(x##_ID)


#endif /* LOCALE_H */
