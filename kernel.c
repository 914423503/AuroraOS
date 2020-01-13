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

	print("AuroraOS is starting... /n", 2);
	
	//Start PCI scanning
	
	//System Initialization
	print("Low RAM Amount: Not Working /n", 15);

	//string val = "";

	//string val = itoa(getLwMemory(), "");

	//print(val, 15, 1);

	print("OK! /n", 14);

    string cmd;
    bool reading = true;

    while(reading)
    {
        print(">>> ", 15);
        cmd = read();

        print("/n", 15);

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
            print("Command       |       What It Does /n", 10);
            print("reboot        |       Reboot the system /n", 15);
            print("shutdown      |       Shutdown the system /n", 15);
            print("cls           |       Clear the screen /n", 15);
            print("help          |       Display this page /n", 15);
			print("about         |       Get system information /n", 15);
			print("echo <str>    |       Print a string /n", 15);
			print("set -<instruments> <args>        |       Set a system variable manually /n", 15);
        }
		else if(strcmp(cmd, "about") == 0)
		{
			print("AuroraOS v.0.3-rc1 beta 1 /n", 15);
			print("AuroraKernel v.0.2.7 beta /n", 15);
			print("Copyright (c) 2018-2020 - Developed by Leonardo Baldazzi /n", 15);
			print("                                                         /n", 15);
			print("In case of bugs please reply on GitHub page /n", 15);
		}
		else if(startsWidth(cmd, "echo ") == 1)
		{
			print(cutFromLeft(cmd, 5), 15);
			print("/n", 15);
		}
		else if (strcmp(cmd, "shutdown") == 0)
		{
			shutdown();
		}
        else if (strcmp(cmd, "set -h") == 0)
        {
                print("Usage: set -<instruments> <args> /n", 15);
                print("Instruments list: /n", 15);
                print("            stpread: Stop reading keyboard cycle (not safe) /n", 15);
                print("/n", 15);
                print("Args list: /n", 15);
                print("            true: Set a variable content to true (use this for stpread) /n", 15);
                print("            false: Set a variable content to false (use this for stpread) /n", 15);
        }
        else if(startsWidth(cmd, "set -stpread ") == 1)
        {
            string args = cutFromLeft(cmd, 13);
            if(strcmp(args, "true") == 0)
            {
                reading = true;
            } else if(strcmp(args, "false") == 0)
            {
                print("Now you can't use your computer, stopping 'reading' cycle /n", 15);
                reading = false;
            } else
            {
                print("Error: Unrecognised parameter passed to stpread, aborting /n", 4);
            }
        }
        else
        {
            print("Unrecognized command /n", 4);
        }

        clearStr(cmd);
    }
}
