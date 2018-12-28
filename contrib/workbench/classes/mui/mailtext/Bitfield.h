/***************************************************************************

 Mailtext - An MUI Custom Class for eMessage display
 Copyright (C) 1996-2001 by Olaf Peters
 Copyright (C) 2002-2006 by Mailtext Open Source Team

 GCC & OS4 Portage by Alexandre Balaban

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 Mailtext OpenSource project :  http://sourceforge.net/projects/mailtext/

 $Id: Bitfield.h 36659 2011-01-18 13:26:51Z neil $

***************************************************************************/

#ifndef BITFIELD_H
#define BITFIELD_H

#include <exec/types.h>

typedef struct BitfieldStruct
{
    BYTEBITS bits[32] ;
} Bitfield ;

BOOL BF_IsSet(const Bitfield *bitfield, const unsigned char bit) ;

void BF_Set(Bitfield *bitfield,   const unsigned char bit) ;
void BF_Unset(Bitfield *bitfield, const unsigned char bit) ;

void BF_ClearBitfield(Bitfield *bitfield) ;
void BF_FillBitfield(Bitfield *bitfield, const unsigned char *chars) ;

#endif /* BITFIELD_H */

