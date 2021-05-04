/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: KERNEL Header
*/
#ifndef _KERNEL_H_
#define _KERNEL_H_

//Define
#define BUFSIZE 2200

//Include
#include "./variables.h"

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

unsigned short getLwMemory() //Get Low Memory ammount
{
	unsigned short total;
	unsigned char lowmem, highmem;

	outportb(0x70, 0x30);
	lowmem = inportb(0x71);
	outportb(0x70, 0x31);
	highmem = inportb(0x71);

	total = lowmem | highmem << 8;
	return total;
}

#endif
