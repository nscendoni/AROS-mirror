/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: clear.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <bootconsole.h>

/* Clear the console */
void con_Clear(void)
{
    switch (scr_Type)
    {
    case SCR_TEXT:
    	txt_Clear();
    	break;

    case SCR_GFX:
    	fb_Clear();
    	break;
    }
}
