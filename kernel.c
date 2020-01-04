/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Kernel Main
*/
#include "./include/kernel.h"
#include "./include/color.h"
#include "./include/acpi.h"
#include "./include/Driver/pci.h"
#include "./include/Driver/keyboard.h"

void kmain()
{
	TERMINAL_BUFFER = (uint16*) VGA_ADDRESS;

	print("AuroraOS is starting...", 2, 1);
	
	//Start PCI scanning
	
	//System Initialization
	print("RAM: ", 15, 1);
	//print(intConvStr((char*)100000000, getAmmountOfRam()), 15, 1);

	print("OK!", 14, 1);

    string cmd;
    bool reading = true;

    while(reading)
    {
        print(": ", 15, 1);
        cmd = read();
		
		print("                                                           ", 15, 1);
		
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
            print("Command       |       What It Does", 10, 1);
            print("reboot        |       Reboot the system", 15, 1);
            print("shutdown      |       Shutdown the system", 15, 1);
            print("cls           |       Clear the screen", 15, 1);
            print("help          |       Display this page", 15, 1);
			print("about         |       Get system information", 15, 1);
			print("echo <str>    |       Print a string", 15, 1);
			print("set -<instruments> <args>        |       Set a system variable manually", 15, 1);
        }
		else if(strcmp(cmd, "about") == 0)
		{
			print("AuroraOS v.0.2.7", 15, 1);
			print("AuroraKernel v.0.2.5 beta", 15, 1);
			print("Copyright (c) 2018-2020 - Developed by Leonardo Baldazzi", 15, 1);
			print("                                                        ", 15, 1);
			print("In case of bugs please reply on GitHub page", 15, 1);
		}
		else if(startsWidth(cmd, "echo ") == 1)
		{
			print(cutFromLeft(cmd, 5), 15, 1);
		}
		else if (strcmp(cmd, "shutdown") == 0)
		{
			shutdown();
		}
        else if (strcmp(cmd, "set -h") == 0)
        {
                print("Usage: set -<instruments> <args>", 15, 1);
                print("Instruments list:", 15, 1);
                print("            stpread: Stop reading keyboard cycle (not safe)", 15, 1);
                print("                                                        ", 15, 1);
                print("Args list:", 15, 1);
                print("            true: Set a variable content to true (use this for stpread)", 15, 1);
                print("            false: Set a variable content to false (use this for stpread)", 15, 1);
        }
        else if(startsWidth(cmd, "set -stpread ") == 1)
        {
            string args = cutFromLeft(cmd, 13);
            if(strcmp(args, "             true") == 0)
            {
                reading = true;
            } else if(strcmp(args, "             false") == 0)
            {
                print("Now you can't use your computer, stopping 'reading' cycle", 15, 1);
                reading = false;
            } else
            {
                print("Error: Unrecognised parameter passed to stpread, aborting", 4, 1);
            }
        }
        else
        {
            print("Unrecognized command", 1, 1);
        }

        clearStr(cmd);
    }
}
