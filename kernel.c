/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Main
*/
#include "./include/kernel.h"
#include "./include/color.h"
#include "./include/acpi.h"
#include "./include/time.h"

void kmain()
{
	TERMINAL_BUFFER = (uint16*) VGA_ADDRESS;

	print("AuroraOS is starting...", 2, 1);

	//System Initialization

	print("OK!", 15, 1);

    print("Lenght of 'Hello': ", 15, 1);
    print(intConvStr((string)' ', Lenght("Hello")), 15, 0);

    //Code Here
}
