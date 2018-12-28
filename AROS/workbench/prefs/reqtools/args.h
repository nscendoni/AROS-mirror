#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: args.h 48674 2014-01-02 17:51:04Z neil $
*/

#include <exec/types.h>

/*** Structures *************************************************************/
enum Argument
{
    FROM,
    USE,
    SAVE,
    COUNT  /* Number of arguments */
};

/*** Prototypes *************************************************************/
BOOL ReadArguments(int argc, char **argv);
VOID FreeArguments(VOID);
IPTR GetArgument(enum Argument arg);

/*** Macros *****************************************************************/
#define ARG(a) GetArgument((a))

#endif /* _ARGS_H_ */
