#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright © 2010, The AROS Development Team. All rights reserved.
    $Id: args.h 32511 2010-01-30 22:30:26Z mazze $
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
