#ifndef PROTO_SERSCRIPT_H
#define PROTO_SERSCRIPT_H
/*
    Copyright © 2003-2004, The AROS Development Team. All rights reserved.
    $Id: serscript.h 30794 2009-03-08 02:19:07Z neil $
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef __NOLIBBASE__       
extern struct Library *SerScriptBase;
#endif

#include <libraries/serscript.h>
#include <clib/serscript_protos.h>
#if __SASC
#include <pragmas/serscript_pragmas.h>
#elif __GNUC__
#include <inline/serscript.h>
#endif

#endif /* PROTO_SERSCRIPT_H */
