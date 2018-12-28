#ifndef _ARGS_H_
#define _ARGS_H_

/*
    Copyright © 2012, The AROS Development Team. All rights reserved.
    $Id: args.h 44805 2012-05-14 17:07:56Z mazze $
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
