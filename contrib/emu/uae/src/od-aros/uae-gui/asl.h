#ifndef _ASL_H_
#define _ASL_H_

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: asl.h 30794 2009-03-08 02:19:07Z neil $
*/

#include <exec/types.h>

/*** Modes ******************************************************************/
enum ASLMode
{
    AM_LOAD,
    AM_SAVE
};

/*** Prototypes *************************************************************/
STRPTR ASL_SelectFile();

#endif /* _ASL_H_ */
