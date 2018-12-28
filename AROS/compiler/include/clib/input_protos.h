#ifndef CLIB_INPUT_PROTOS_H
#define CLIB_INPUT_PROTOS_H

/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: input_protos.h 30792 2009-03-07 22:40:04Z neil $

    Desc: Prototypes for console.device
    Lang: english
*/

#ifndef AROS_LIBCALL_H
#   include <aros/libcall.h>
#endif

/*
    Prototypes
*/

AROS_LP0(UWORD, PeekQualifier,
	struct Device *, InputBase, 7, Input)

#endif /* CLIB_INPUT_PROTOS_H */
