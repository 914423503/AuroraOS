/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Time Functionss
*/
#ifndef _TIME_H
#define _TIME_H

//Include
#include "./variables.h"

void Sleep(uint32 milli) //Sleep function
{
    volatile uint32 i = 0;
    while(i < milli)
    {
        i++;
    }
}

#endif
