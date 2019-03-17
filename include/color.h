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

/*
void scanString() //Get input by keyboard
{
    string buffstr;
    uint8 i = 0;

    while(1)
    {
        if(inportb(0x64) & 0x1)                 
        {
            switch(inportb(0x60))
            { 
        case 2:
                print('1', 15, 0);
                buffstr[i] = '1';
                i++;
                break;
        case 3:
                print('2', 15, 0);
                buffstr[i] = '2';
                i++;
                break;
        case 4:
                print('3', 15, 0);
                buffstr[i] = '3';
                i++;
                break;
        case 5:
                print('4', 15, 0);
                buffstr[i] = '4';
                i++;
                break;
        case 6:
                print('5', 15, 0);
                buffstr[i] = '5';
                i++;
                break;
        case 7:
                print('6', 15, 0);
                buffstr[i] = '6';
                i++;
                break;
        case 8:
                print('7', 15, 0);
                buffstr[i] = '7';
                i++;
                break;
        case 9:
                print('8', 15, 0);
                buffstr[i] = '8';
                i++;
                break;
        case 10:
                print('9', 15, 0);
                buffstr[i] = '9';
                i++;
                break;
        case 11:
                print('0', 15, 0);
                buffstr[i] = '0';
                i++;
                break;
        case 12:
                print('-', 15, 0);
                buffstr[i] = '-';
                i++;
                break;
        case 13:
                print('=', 15, 0);
                buffstr[i] = '=';
                i++;
                break;
        case 16:
                print('q', 15, 0);
                buffstr[i] = 'q';
                i++;
                break;
        case 17:
                print('w', 15, 0);
                buffstr[i] = 'w';
                i++;
                break;
        case 18:
                print('e', 15, 0);
                buffstr[i] = 'e';
                i++;
                break;
        case 19:
                print('r', 15, 0);
                buffstr[i] = 'r';
                i++;
                break;
        case 20:
                print('t', 15, 0);
                buffstr[i] = 't';
                i++;
                break;
        case 21:
                print('y', 15, 0);
                buffstr[i] = 'y';
                i++;
                break;
        case 22:
                print('u', 15, 0);
                buffstr[i] = 'u';
                i++;
                break;
        case 23:
                print('i', 15, 0);
                buffstr[i] = 'i';
                i++;
                break;
        case 24:
                print('o', 15, 0);
                buffstr[i] = 'o';
                i++;
                break;
        case 25:
                print('p', 15, 0);
                buffstr[i] = 'p';
                i++;
                break;
        case 26:
                print('[', 15, 0);
                buffstr[i] = '[';
                i++;
                break;
        case 27:
                print(']', 15, 0);
                buffstr[i] = ']';
                i++;
                break;
        case 30:
                print('a', 15, 0);
                buffstr[i] = 'a';
                i++;
                break;
        case 31:
                print('s', 15, 0);
                buffstr[i] = 's';
                i++;
                break;
        case 32:
                print('d', 15, 0);
                buffstr[i] = 'd';
                i++;
                break;
        case 33:
                print('f', 15, 0);
                buffstr[i] = 'f';
                i++;
                break;
        case 34:
                print('g', 15, 0);
                buffstr[i] = 'g';
                i++;
                break;
        case 35:
                print('h', 15, 0);
                buffstr[i] = 'h';
                i++;
                break;
        case 36:
                print('j', 15, 0);
                buffstr[i] = 'j';
                i++;
                break;
        case 37:
                print('k', 15, 0);
                buffstr[i] = 'k';
                i++;
                break;
        case 38:
                print('l', 15, 0);
                buffstr[i] = 'l';
                i++;
                break;
        case 39:
                print(';', 15, 0);
                buffstr[i] = ';';
                i++;
                break;
        case 42:
                print('q', 15, 0);
                buffstr[i] = 'q';
                i++;
                break;
        case 44:
                print('z', 15, 0);
                buffstr[i] = 'z';
                i++;
                break;
        case 45:
                print('x', 15, 0);
                buffstr[i] = 'x';
                i++;
                break;
        case 46:
                print('c', 15, 0);
                buffstr[i] = 'c';
                i++;
                break;
        case 47:
                print('v', 15, 0);
                buffstr[i] = 'v';
                i++;
                break;                
        case 48:
                print('b', 15, 0);
                buffstr[i] = 'b';
                i++;
                break;               
        case 49:
                print('n', 15, 0);
                buffstr[i] = 'n';
                i++;
                break;                
        case 50:
                print('m', 15, 0);
                buffstr[i] = 'm';
                i++;
                break;               
        case 51:
                print(',', 15, 0);
                buffstr[i] = ',';
                i++;
                break;                
        case 52:
                print('.', 15, 0);
                buffstr[i] = '.';
                i++;
                break;            
        case 53:
                print('/', 15, 0);
                buffstr[i] = '/';
                i++;
                break;            
        case 54:
                print('.', 15, 0);
                buffstr[i] = '.';
                i++;
                break;            
        case 55:
                print('/', 15, 0);
                buffstr[i] = '/';
                i++;
                break;                     
        case 57:
                print(' ', 15, 0);
                buffstr[i] = ' ';
                i++;
                break;
            }
        }
	updateCursor();
    }
    buffstr[i] = 0;                   
    return buffstr;
}
*/

#endif
