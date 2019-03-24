/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Main
*/
#include "./include/kernel.h"
#include "./include/color.h"
#include "./include/time.h"
#include "./include/Driver/interrups.h"

void kmain()
{
	TERMINAL_BUFFER = (uint16*) VGA_ADDRESS;

	print("AuroraOS is starting...", 2, 1);

	//System Initialization

    print("Enabling Interrups", 15, 1);
    init();

	print("OK!", 15, 1);
    Sleep(9999999);

    print(": ", 15, 1);

    //Code Here
}
