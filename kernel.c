/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Main
*/
#include "./include/kernel.h"
#include "./include/color.h"
#include "./include/acpi.h"
#include "./include/Driver/interrups.h"

void kmain()
{
	TERMINAL_BUFFER = (uint16*) VGA_ADDRESS;

	print("AuroraOS is starting...", 2, 1);

	//System Initialization

	print("OK!", 15, 1);

    string cmd = "";
    while(1)
    {
        print(": ", 15, 1);
        cmd = read();

        print("You typed: ", 15, 0);
        print(cmd, 15, 1);

        clearStr(cmd);
    }

    //Code Here
}
