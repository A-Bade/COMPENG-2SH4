#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2)
{
	int counter = 0;
	int i = 0;
	int j = 0;
	while (i < k1)
	{
		while (pos2[j] < pos1[i])
		{
			val3[counter] = val2[j];
			pos3[counter] = pos2[j];
			counter++;
			j++;
		}
		if (pos2[j] == pos1[i] && (val1[i] + val2[j]) != 0)
		{
			val3[counter] = val2[j] + val1[i];
			pos3[counter]= pos2[j];
			counter++;
			j++;
			i++;
		}
		else if((val1[i] + val2[j]) == 0)
		{
			i++;
			j++;
		}
		else
		{
			val3[counter] = val1[i];
			pos3[counter] = pos1[i];
			counter++;
			i++;
		}
	}
	while (j < k2)
	{
		val3[counter] = val2[j];
		pos3[counter] = pos2[j];
		counter++;
		j++;
	}
	
}
