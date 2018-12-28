/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: serialdebug.h 47619 2013-07-02 18:27:20Z neil $
*/

#ifndef SERIALDEBUG_H_
#define SERIALDEBUG_H_

#include <inttypes.h>

extern void serInit();
//void waitBusy();
extern void waitSerIN();
extern void waitSerOUT();
extern void putByte(uint8_t chr);

#endif /* SERIALDEBUG_H_ */
