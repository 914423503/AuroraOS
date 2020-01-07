/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: Math methods
*/

#ifndef _MATH_H
#define _MATH_H_

#include "./variables.h"

uint32 pow(int b, int ex) //Pow calc
{
    uint32 toReturn = 0;

    for(int i = 0; i < ex; i++)
    {
        toReturn += b;
    }

    return  toReturn;
}

#endif