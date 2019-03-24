/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Interrups
*/

#ifndef _INTERRUPS_H_
#define _INTERRUPS_H_

//Include
#include "../variables.h"
#include "../kernel.h"

uint8 isInterrupsInitializated = 0;

void init()
{
    outportb(0x21,0xfd);
    outportb(0xa1,0xff);
    asm("sti");

    isInterrupsInitializated = 1;
}

#endif
