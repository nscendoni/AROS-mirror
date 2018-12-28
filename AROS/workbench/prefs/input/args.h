#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright � 2003, The AROS Development Team. All rights reserved.
    $Id: args.h 32540 2010-02-01 18:28:34Z mazze $
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
