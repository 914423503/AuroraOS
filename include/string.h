/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: String Functionss
*/
#ifndef _STRING_H
#define _STRING_H

//Include
#include "./variables.h"

uint16 Lengh(string str) //Get string lenght
{
	uint16 i = 1;
    while(str[i])
    { i++; }

    return i;
}

string intConvStr(char* b, uint32 i)
{
    char const digit[] = "0123456789";
    char* p = b;

    if(i<0){
        *p++ = '-';
        i *= -1;
    }

    uint32 shifter = i;
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

uint16 memsetw(uint16* dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16*)dest;
    for(; count != 0; count--) *temp++ = val;

    return *dest;
}

#endif
