#ifndef IOS1_H
#define IOS1_H
/*
 * $Id: ios1.h 30794 2009-03-08 02:19:07Z neil $
 *
 * Extensions to SAS/C level 1 IO definition file include:ios1.h
 *
 * Copyright � 1994 AmiTCP/IP Group, <amitcp-group@hut.fi>
 *                  Helsinki University of Technology, Finland.
 *                  All rights reserved.
 */

/*
 * Include SAS/C ios1.h
 */
#ifndef _IOS1_H
#include <include:ios1.h>
#endif

/*
 * Additional flag definitions for the ufbflg field
 * The given value was recommended by SAS.
 */
#ifndef UFB_SOCK
#define UFB_SOCK 0x100 /* AmiTCP/IP socket */
#endif

/*
 * Additional external definitions
 */
extern struct UFB *__allocufb(int *);
#define   allocufb    __allocufb

#endif
