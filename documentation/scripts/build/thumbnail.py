# -*- coding: iso-8859-1 -*-
# Copyright � 2002, The AROS Development Team. All rights reserved.
# $Id: thumbnail.py 30800 2009-03-08 17:28:50Z neil $

import os.path
import Image

def makeThumbnailPath( originalPath ):
    head, tail = os.path.split( originalPath )
    return os.path.join( head, 'thumbnails', tail )

def makeThumbnail( src, dst, size ):
    image = Image.open( src )
    image = image.convert( 'RGB' )
    image.thumbnail( size, Image.ANTIALIAS )
    image.save( dst )

