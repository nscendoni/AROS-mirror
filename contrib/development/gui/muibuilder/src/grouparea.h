/***************************************************************************

  MUIBuilder - MUI interface builder
  Copyright (C) 1990-2009 by Eric Totel
  Copyright (C) 2010-2011 by MUIBuilder Open Source Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  MUIBuilder Support Site: http://sourceforge.net/projects/muibuilder/

  $Id: grouparea.h 48675 2014-01-02 18:34:06Z neil $

***************************************************************************/

#ifndef GROUPAREA_H
#define GROUPAREA_H

//typedef struct ObjGR_AreaGroup
struct ObjGR_AreaGroup
{
    APTR GR_AreaGroup;
    APTR CH_Hide;
    APTR CH_Disable;
    APTR CH_InputMode;
    APTR CH_Phantom;
    APTR SL_Weight;
    APTR CY_Background;
    APTR CY_Frame;
    APTR STR_Char;
    APTR STR_TitleFrame;
    char *STR_CY_Background[24];
    char *STR_CY_Frame[15];
};

#endif
