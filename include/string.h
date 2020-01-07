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
#include "./math.h"

//Implicit declaration of function warning:
void print(const string str, uint8 color, uint8 newLine);

#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

uint16 Lenght(string str) //Get string lenght
{
	uint16 i = 1;
    while(str[i])
    { i++; }

    return i;
}

/*
string itoa(uint32 b) //From a int get string
{
    //Not working
}
 */

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

uint8 startsWidth(string a, string b) //If string a starts with string b return 1
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

string cutFromLeft(string a, uint32 b) //Cut a string from left
{
    string lav = a;
    string ret = "";
    uint32 pos = 0;

    if(!(b > Lenght(a)))
    {
        for (uint32 i = 0; i < b; i++) { lav[i] = ' '; }

        for (uint32 i = 0; i < Lenght(a); i++) {
            if (i >= b) {
                ret[pos] = lav[i];

                pos++;
            }
        }

        return ret;
    }
    else
    {
        print("Error in cutFromLeft method: cut pointer not valid", 4, 1);

        return " Error! "; //Error return
    }
}	

uint16 memsetw(uint16* dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16*)dest;
    for(; count != 0; count--) *temp++ = val;

    return *dest;
}

#endif
