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
	while(str[i++]);
	return --i;
}

uint16 *memsetw(uint16 *dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16 *)dest;
    for(; count != 0; count--) *temp++ = val;
    return dest;
}

#endif
