#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2)
{

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int size_total;
	size_total = strlen(str1) + strlen(str2);
	z = (char *)calloc(size_total,sizeof(char));

	//For srt1:
	int a = 0;
	while (*(str1 + a) != '\0')
	{
		*(z + a) = *(str1 + a);
		a++;
	}

	//For srt2:
	int b = 0;
	while (*(str2 + b) != '\0')
	{
		*(z + a) = *(str2 + b);
		a++;
		b++;
	}

	/* finally, return the string*/
	return z;
	
}
