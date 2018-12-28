/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: codec.h 30792 2009-03-07 22:40:04Z neil $
*/

short DecodeInit(GifHandleType *gifhandle);
short DecodeLines(GifHandleType *gifhandle);
short DecodeEnd(GifHandleType *gifhandle);
short EncodeInit(GifHandleType *gifhandle, short numplanes);
short EncodeLines(GifHandleType *gifhandle);
short EncodeEnd(GifHandleType *gifhandle);
