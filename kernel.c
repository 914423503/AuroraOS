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

        if(strcmp(cmd, "reboot") == 1)
        {
            reboot();
        }
        else if(strcmp(cmd, "cls") == 1)
        {
            clear();
        } 
        else
        {
            print("Unrecognized command", 1, 1);
        }

        clearStr(cmd);
    }

    //Code Here
}
