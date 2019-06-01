/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: domethod.c 41534 2011-09-22 06:26:54Z sonic $
*/

#define ALIB_NO_INLINE_STDARG

#include <aros/debug.h>
#include <intuition/classes.h>

#include "alib_intern.h"

/******************************************************************************

    NAME */
#include <intuition/classusr.h>
#include <proto/alib.h>

	IPTR DoMethodA (

/*  SYNOPSIS */
	Object * obj,
	Msg	 message)

/*  FUNCTION
	Invokes a method on a BOOPSI object. The dispatcher of the class the
	object is inherited from is called. For more information about methods
	a class supports, see the class documentation.

    INPUTS
	obj - The object on which the method is to be performed.
	message - The message. The first field is the same for all methods and
		  specifies which method is to be invoked (see
		  <intuition/classusr.h>).

    RESULT
	Class and method dependent. See the class documentation. A value of 0
	can be a valid return code but can also mean that a method is not
	supported.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	intuition.library/NewObjectA(), intuition.library/SetAttrsA(), intuition.library/GetAttr(),
	intuition.library/DisposeObject(), CoerceMethodA(),
        DoSuperMethodA(), <intuition/classusr.h>

******************************************************************************/
{
    //DBPRINTF("hello world\n")

    if (!obj)
	return 0L;

    ASSERT_VALID_PTR(obj);

    ASSERT_VALID_PTR(OCLASS(obj));
    ASSERT_VALID_PTR(message);

    return CALLHOOKPKT((struct Hook *) OCLASS(obj), obj, message);
} /* DoMethodA */

IPTR DoMethod (Object * obj, IPTR MethodID, ...)
{
    if (!obj)
    	return 0L;

    ASSERT_VALID_PTR(obj);

    ASSERT_VALID_PTR(OCLASS(obj));

    AROS_SLOWSTACKMETHODS_PRE(MethodID)
    retval = CALLHOOKPKT((struct Hook *) OCLASS(obj), obj, AROS_SLOWSTACKMETHODS_ARG(MethodID));
    AROS_SLOWSTACKMETHODS_POST
} /* DoMethod() */
