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

    Sleep(9999999);

	clear();

	//Code Here
	print(": ", 15, 0);
}
