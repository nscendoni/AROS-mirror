/*
 *  screen.h - Functions for grabbing and creating public screens
 *
 * $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
 * $Revision: 48481 $
 *
 *  0.1
 *  20010717 DM Created - only a function for finding public screens ATM
 *
 */


#ifndef SCREEN_H
#define SCREEN_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_SCREENS_H
#include <intuition/screens.h>
#endif

struct Screen *FindPubScreen(STRPTR name);

#endif /* SCREEN_H */


