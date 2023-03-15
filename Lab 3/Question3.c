#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr)
{

	
    char **word_list;

    /*write your implementation here*/
    FILE *input_file = fopen(input_filename, "r");
    fscanf(input_file, "%d", nPtr);
    word_list = calloc((*nPtr) * 15, sizeof(char));

    for(int i = 0; i < *nPtr; i++)
    {
    	word_list[i] = calloc(15, sizeof(char));
       	fscanf(input_file, "%s", word_list[i]);
    }

    fclose(input_file);

    return word_list;

}

int compare_str(const char *str1,const char *str2)
{

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	int length1;
	length1 = strlen(str1);

	for(int i = 0; i < length1; i++)
	{

		if(str1[i] > str2[i])
		{
			return 1;
		}

		else if(str1[i] < str2[i])
		{
			return 0;
		}

		if (str2[i] == '\0')
		{
			break;
		}

	}


	/*write your implementation here and update the return accordingly*/
        return -1;
    
}

void sort_words(char **words, int size)
{
   
	/*write your implementation here*/
	for (int j = size; j >= 0; j--)
	{
		for (int i = 0; i < (j - 1); i++)
		{
			if  (compare_str(words[i],words[i + 1]) == 1)
			{
				swap(&words[i], &words[i + 1]);
			}
		}

   }

}

void swap(char **str1, char **str2)
{
 
	/*this is a helper function that you can implement and use to facilitate your development*/
	char *tem;
	tem = *str2;
	*str2 = *str1;
	*str1 = tem;
}

void sort2_words(char **words, int size)
{

   
	/*write your implementation here*/
	for (int i = 1; i < size; i++)
	{
		int a;
		int b;

		a = i;
		b = i-1;
		while( (b >= 0) && (compare_str(words[a], words[b])==0) )
		{
			swap(&words[a], &words[b]);
			a--;
			b--;
		}
	}
    
}

