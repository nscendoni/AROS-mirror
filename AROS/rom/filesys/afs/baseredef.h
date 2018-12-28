#ifndef BASEREDEF_H
#define BASEREDEF_H

/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: baseredef.h 35730 2010-11-23 21:26:31Z jmcmullan $
*/

#ifdef DOSBase
#	undef DOSBase
#endif
#define DOSBase afsbase->dosbase
#endif

