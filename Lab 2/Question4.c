#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[])
{
	int i = 0;
	while (word[i]!='\0')
	{
		int ascii_address = word[i];
		if (ascii_address <= 90 && ascii_address >= 65)
		{
			freq[ascii_address - 65] += 1;
		}
		else if(ascii_address <= 122 && ascii_address >= 97)
		{
			freq[ascii_address - 97] += 1;
		}
			i++;
	}
}
