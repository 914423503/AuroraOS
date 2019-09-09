/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: String Functionss
*/
#ifndef _STRING_H
#define _STRING_H

//Include
#include "./variables.h"
#include "./color.h"

uint16 Lenght(string str) //Get string lenght
{
	uint16 i = 1;
    while(str[i])
    { i++; }

    return i;
}

string intConvStr(string b, uint16 i) //From a int get char
{
    char const digit[] = "0123456789";
    string p = b;

    uint16 shifter = i;
    do{
        ++p;
        shifter = shifter/10;
    }while(shifter);

    *p = '\0';
    do{
        *--p = digit[i%10];
        i = i/10;
    }while(i);

    return b;
}

void clearStr(string str) //Clear a string
{
    uint8 i = 0;

    while(str[i])
      { str[i] = ' '; i++; }
}

uint8 strcmp(string a, string b) //String compare
{
        uint32 i = 0;

        while(a[i] && b[i])
        {
            if(a[i] != b[i])
            { return 1; }

            i++;
        }

    return 0;
}

uint8 startsWidth(string a, string b) //If string a starts width string b return 1
{
	uint32 lenghtB = Lenght(b);
	uint32 i = 0;
	uint32 i_ = 0;
	
	while(i < lenghtB)
	{
		if(a[i] == b[i])
		{
			i_++;
		}
		
		i++;
	}
	
	if(i_ == i)
	{
		return 1;
	}
	
	return 0;
}

string cutFromLeft(string a, uint32 b) //Cut a string from left (spaces)
{
	string lav = a;
	uint32 i = 0;
	
	while(i < b)
	{
		lav[i] = ' ';
		
		i++;
	}
	
	return lav;
}	

uint16 memsetw(uint16* dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16*)dest;
    for(; count != 0; count--) *temp++ = val;

    return *dest;
}

#endif
