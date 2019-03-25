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
    uint8 i =0;
    while(1)
    {
        print(": ", 15, 1);
        cmd = read();

        print("Yout typed: ", 15, 0);
        print(cmd, 15, 1);

        while(cmd[i]) //Clear string
        { cmd[i] = ' '; i++; }

        i = 0;
    }

    //Code Here
}
