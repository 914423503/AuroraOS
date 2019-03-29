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

    string cmd;
    while(1)
    {
        print(": ", 15, 1);
        cmd = read();

        if(strcmp(cmd, "BugssPrevention") == 0)
        {
            //BugssPrevention
        }
        else if(strcmp(cmd, "cls") == 0)
        {
            clear();
        }
        else if(strcmp(cmd, "reboot") == 0)
        {
            reboot();
        }
        else if(strcmp(cmd, "help") == 0)
        {
            print("Command       |       What It Does", 15, 1);
            print("reboot        |       Reboot the system", 15, 1);
            print("cls           |       Clear the screen", 15, 1);
            print("help          |       Display this page", 15, 1);
        }
        else
        {
            print("Unrecognized command", 1, 1);
        }

        clearStr(cmd);
    }

    //Code Here
}
