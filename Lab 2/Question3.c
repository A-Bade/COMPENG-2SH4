#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{
	int counter = 0;

	//When the first diagonal value is in the first column.
	for (int x = 0; x < N3; x++)
	{
		int row = x;
		for (int y = 0;y <= x; y++)
		{
			arr[counter] = mat[row][y];
			counter++;
			row--;
		}
	}
	//When the first diagonal value is in the last row.
	for (int d = 1; d < N3; d++)
	{
		int row = N3 - 1;
		for (int f = d; f < N3; f++)
		{
			arr[counter] = mat[row][f];
			counter++;
			row--;
		}
	}
}
