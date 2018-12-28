#ifndef PKG_GUI_H
#define PKG_GUI_H

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: gui.h 30792 2009-03-07 22:40:04Z neil $
*/

#include <exec/types.h>

/****************************************************************************/
/** Prototypes **************************************************************/

BOOL GUI_Open();
void GUI_Close();
void GUI_Update( LONG position, LONG max );

#endif /* PKG_GUI_H */
