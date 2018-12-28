#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright © 2009-2013, The AROS Development Team. All rights reserved.
    $Id: args.h 49081 2014-06-20 14:05:49Z neil $
*/

#include <exec/types.h>

/*** Structures *************************************************************/
enum Argument {
    FROM,
    SAVE,
    COUNT /* Number of arguments */
};

/*** Prototypes *************************************************************/
BOOL ReadArguments(int argc, char **argv);
VOID FreeArguments(VOID);
IPTR GetArgument(enum Argument arg);

/*** Macros *****************************************************************/
#define ARG(a) GetArgument((a))

#endif /* _ARGS_H_ */
