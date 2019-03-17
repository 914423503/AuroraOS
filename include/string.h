/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: String Functionss
*/
#ifndef _STRING_H
#define _STRING_H

//Include
#include "./types.h"

uint16 Lengh(string str) //Get string lenght
{
	uint16 i = 1;
	while(str[i++]);
	return --i;
}

#endif
