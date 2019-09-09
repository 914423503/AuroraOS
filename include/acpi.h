/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: ACPI
*/

#ifndef _ACPI_H_
#define _ACPI_H_

//Include
#include "./kernel.h"
#include "./color.h"

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
}

void crash(string message, string errCode) //Crash
{
	clear();
	
	print("An error occured while system running.", 4, 1);
	print("AuroraKernel had returned this error message: ", 4, 1);
	print(message, 4, 1);
	print("Err code: ", 15, 1);
	print(errCode, 15, 1);
}

#endif
