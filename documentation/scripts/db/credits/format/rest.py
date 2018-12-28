# -*- coding: iso-8859-1 -*-
# Copyright � 2002-2006, The AROS Development Team. All rights reserved.
# $Id: rest.py 30800 2009-03-08 17:28:50Z neil $

def format( credits ):
    result  = '=======\n' \
            + 'Credits\n' \
            + '=======\n\n' \
            + ".. This document is automatically generated from db/credits."
              
    for area in credits:
        result += '\n\n' + area[0] + '\n' + '=' * (len( area[0] ) + 3) + '\n\n' 
        
        for name in area[1]:
            result += '+ ' + name + '\n'

    return result
