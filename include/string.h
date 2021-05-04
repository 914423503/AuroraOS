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
void print(const string str, uint8 color);

#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

uint16 Lenght(string str) //Get string lenght
{
	uint16 i = 1;
    while(str[i])
    { i++; }

    return i;
}

/*
string itoa(int i, string b) //From a int get string
{
    //NOT WORKING
} */


void clearStr(string str) //Clear a string
{
    uint8 i = 0;
    while(str[i])
      { str[i] = 0; i++; }
}

uint8 strcmp(string a, string b) //String compare (from linux source code)
{
	unsigned char c1, c2;

	while (1) {
		c1 = *a++;
		c2 = *b++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)
			break;
	}
	return 0;
}

uint8 startsWidth(string a, string b) //If string a starts with string b return 1
{
	uint32 lenghtB = Lenght(b);
	uint32 i = 0;
	
	while(i < lenghtB)
	{
		if(a[i] != b[i])
		{
			return 0;
		}
		
		i++;
	}
	
	return 1;
}

string cutFromLeft(string a, uint32 b) //Cut a string from left
{
    string lav = a;
    string ret = "";
    uint32 pos = 0;

    if(!(Lenght(a) - b <= 0))
    {
        for (uint32 i = 1; i <= Lenght(a); i++) {
            if (i >= b) {
                ret[pos] = lav[i];

                pos++;
            }
        }

        return ret;
    }
    else
    {
        print("Error in cutFromLeft method: cut pointer not valid /n", 4);
		
		return NULL;
    }
}	

uint16 memsetw(uint16* dest, uint16 val, uint32 count) //Mem set by 32bit word
{
    uint16 *temp = (uint16*)dest;
    for(; count != 0; count--) *temp++ = val;

    return *dest;
}

#endif
