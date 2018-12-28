#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright © 2009-2011, The AROS Development Team. All rights reserved.
    $Id: args.h 48909 2014-04-05 19:40:16Z neil $
*/

#include <exec/types.h>

/*** Structures *************************************************************/
enum Argument {
    FROM,
    USE,
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
