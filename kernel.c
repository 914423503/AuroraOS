/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Main
*/
#include "./include/kernel.h"
#include "./include/color.h"
#include "./include/acpi.h"

void kmain()
{
	TERMINAL_BUFFER = (uint16*) VGA_ADDRESS;

	print("AuroraOS is starting...", 2, 1);

	//Code Here
	
	print("OK!", 15, 0);

	shutdown();
}
