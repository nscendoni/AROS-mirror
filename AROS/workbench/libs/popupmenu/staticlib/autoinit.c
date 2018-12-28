/*
    Copyright © 2010, The AROS Development Team. 
    All rights reserved.
    
    $Id: autoinit.c 36648 2011-01-17 14:31:59Z neil $
*/

#include <proto/popupmenu.h>
#include <aros/symbolsets.h>

ADD2LIBS((CONST_STRPTR)"popupmenu.library",10, struct PopupMenuBase *, PopupMenuBase);
