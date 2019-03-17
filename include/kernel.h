/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Header
*/
#ifndef _KERNEL_H_
#define _KERNEL_H_

//Define
#define BUFSIZE 2200

//Include
#include "./types.h"

uint16* TERMINAL_BUFFER;

uint8 inportb (uint16 _port)
{
    	uint8 rv;
    	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    	return rv;
}

void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

uint16 *memsetw(uint16 *dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16 *)dest;
    for(; count != 0; count--) *temp++ = val;
    return dest;
}

#endif