/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Basic GPU Driver
*/

#ifndef _COLOR_H_
#define _COLOR_H_

//Define
#define VGA_ADDRESS 0xB8000 //VGA

//Defining Colors
#define BLACK_COLOR 0
#define BLUE_COLOR 1
#define GREEN_COLOR 2
#define CYAN_COLOR 3
#define RED_COLOR 4
#define MAGENTA_COLOR 5
#define BROWN_COLOR 6
#define LIGHTGRAY_COLOR 7
#define DARKGRAY_COLOR 8
#define LIGHTBLUE_COLOR 9
#define LIGHTGREEN_COLOR 10
#define LIGHTCYAN_COLOR 11
#define LIGHTRED_COLOR 12
#define LIGHTMAGENTA_COLOR 13
#define YELLOW_COLOR 14
#define WHITE_COLOR 15

#define PAINT(a,b) (((b & 0xF) << 8) | (a & 0xFF)) //Make a 2 bytes pixel, background is always black, a is a char, b is foreground color

//Include
#include "./kernel.h"
#include "./string.h"

unsigned int VGA_INDEX;

static uint8 Y_INDEX = 1;
int cursorX = 0, cursorY = 0;
const uint8 width = 80, height = 25, depth = 2; //Screen Resolution and depth

static uint16 VGA_DefaultEntry(unsigned char to_print, uint8 showedColor) //Screen color
{
     if(showedColor == 0)
     {
       return (uint16) to_print | (uint16)BLACK_COLOR << 8;
     } else if (showedColor == 1)
     {
       return (uint16) to_print | (uint16)BLUE_COLOR << 8;
     } else if (showedColor == 2)
     {
       return (uint16) to_print | (uint16)GREEN_COLOR << 8;
     } else if (showedColor == 3)
     {
       return (uint16) to_print | (uint16)CYAN_COLOR << 8;
     } else if (showedColor == 4)
     {
       return (uint16) to_print | (uint16)RED_COLOR << 8;
     } else if (showedColor == 5)
     {
       return (uint16) to_print | (uint16)MAGENTA_COLOR << 8;
     } else if (showedColor == 6)
     {
       return (uint16) to_print | (uint16)BROWN_COLOR << 8;
     } else if (showedColor == 7)
     {
       return (uint16) to_print | (uint16)LIGHTGRAY_COLOR << 8;
     } else if (showedColor == 8)
     {
       return (uint16) to_print | (uint16)DARKGRAY_COLOR << 8;
     } else if (showedColor == 9)
     {
       return (uint16) to_print | (uint16)LIGHTBLUE_COLOR << 8;
     } else if (showedColor == 10)
     {
       return (uint16) to_print | (uint16)LIGHTGREEN_COLOR << 8;
     } else if (showedColor == 11)
     {
       return (uint16) to_print | (uint16)LIGHTCYAN_COLOR << 8;
     } else if (showedColor == 12)
     {
       return (uint16) to_print | (uint16)LIGHTRED_COLOR << 8;
     } else if (showedColor == 13)
     {
       return (uint16) to_print | (uint16)LIGHTMAGENTA_COLOR << 8;
     } else if (showedColor == 14)
     {
       return (uint16) to_print | (uint16)YELLOW_COLOR << 8;
     } else if (showedColor == 15)
     {
       return (uint16) to_print | (uint16)WHITE_COLOR << 8;
     } else
     {
       return (uint16) to_print | (uint16)WHITE_COLOR << 8;
     }
}

void clearVGABuffer(uint16 **buffer)
{
  	for(int i=0;i<BUFSIZE;i++)
	{
    		(*buffer)[i] = '\0';
  	}
  	Y_INDEX = 1;
  	VGA_INDEX = 0;
}

void updateCursor() //Update cursor position
{
    	uint16 pos = cursorY * width + cursorX;                                                      

    	outportb(0x3D4, 0x0F);                                                                
    	outportb(0x3D5, (uint8) (pos & 0xFF));                                                         
    	outportb(0x3D4, 0x0E);                                                                
    	outportb(0x3D5, (uint8) ((pos >> 8) & 0xFF));
}

void clearLine(uint8 from, uint8 to) //Clear a line from an address
{
        uint16 i = width * from * depth;
        string vidmem = (string)VGA_ADDRESS;
        for(;i < (width * ( to + 1) * depth);i++)
        {
                vidmem[i] = 0x0;
        }
}

void clear() //Clear screen
{
	memsetw(VGA_ADDRESS, PAINT(0x20, WHITE_COLOR), width * height / 2);
	cursorX = 0;
	cursorY = 0;
	updateCursor();

	print(" ", 15, 0);
}

void print(string str, uint8 color, uint8 newLine) //Print a string
{
  	int i = 0;

  	while(str[i])
  	{
    		//Write bytes
    		TERMINAL_BUFFER[VGA_INDEX] = VGA_DefaultEntry(str[i], color);
    		i++;
    		VGA_INDEX++;

		cursorX++;
  	}
  	VGA_INDEX = 0;

	if (newLine == 0)
	{ } else if (newLine == 1)
	{
		//Write a new line
		if(Y_INDEX >= 55)
		{
    			Y_INDEX = 0;
    			clearVGABuffer(&TERMINAL_BUFFER);
  		}
  		VGA_INDEX = width*Y_INDEX;
  		Y_INDEX++;

		cursorY++;
		cursorX = 0;
	} else
	{
		print("Error: newLine abiguos", 4, 0);
	}

	updateCursor();
}

#endif
