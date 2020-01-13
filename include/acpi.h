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
    //Shutdown physical machine
	__asm
	(
    "mov $0x5301, %ax;"
    "xor %bx, %bx;"
    "int $0x15;"
    "mov $0x530e, %ax;"
    "xor %bx, %bx;"
    "mov $0x0102, %cx;"
    "int $0x15;"
    "mov $0x5307, %ax;"
    "mov $0x0001, %bx;"
    "mov $0x0003, %cx;"
    "int $0x15;"
		);
}

void crash(string message, string errCode) //Crash
{
	clear();
	
	print("An error occured while system running. /n", 4);
	print("AuroraKernel had returned this error message: /n", 4);
	print(message, 4);
	print("/n", 15);
	print("Err code: /n", 15);
	print(errCode, 15);
}

#endif
