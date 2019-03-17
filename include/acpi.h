/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: ACPI
*/

#ifndef _ACPI_H_
#define _ACPI_H_

//Include
#include "./kernel.h"

void reboot() //Reboot system
{
    	uint8 good = 0x02;
	while (good & 0x02)
	{
		good = inportb(0x64);
	}

	outportb(0x64, 0xFE);
	asm volatile ("hlt"); //HLT cpu
}

void shutdown() //Shutdowh system
{
	__asm__ __volatile__ ("cli");
	__asm__ __volatile__ ("hlt");
}

#endif
