/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: String Functionss
*/
#ifndef _STRING_H
#define _STRING_H

//Include
#include "./variables.h"

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

uint8 strcmp(string str1, string str2) //Compare strings
{
    while ((*str1 == *str2) && (*str1 != '\0'))
    {
        str1++;
        str2++;
    }
 
    if (*str1 > *str2)
        return 1;
 
    if (*str1 < *str2)
        return -1;
 
    return 0;
}

uint16 memsetw(uint16* dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16*)dest;
    for(; count != 0; count--) *temp++ = val;

    return *dest;
}

#endif
