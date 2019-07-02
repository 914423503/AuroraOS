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
		
		print("                                                        ", 15, 1);
		
        if(strcmp(cmd, "cls") == 0)
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
            print("cls           |       Clear the screen (Not Working)", 15, 1);
            print("help          |       Display this page", 15, 1);
			print("about         |       Get system information", 15, 1);
        }
		else if(strcmp(cmd, "about") == 0)
		{
			print("AuroraOS v.0.2 alpha", 15, 1);
			print("AuroraKernel v.0.1.2", 15, 1);
			print("Copyright (c) 2018-2019 - Developed by Leonardo Baldazzi", 15, 1);
			print("", 15, 1);
			print("In case of bugs please reply on GitHub page", 15, 1);
		}
        else
        {
            print("Unrecognized command", 1, 1);
        }

        clearStr(cmd);
    }

    //Code Here
}
