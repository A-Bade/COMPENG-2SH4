#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag = 0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	for (int c = 0; c < N2; c++)
	{
		int sum = 0;
		for (int j = 0; j < N2; j++){
				if(c == j)
				{
					continue;
				}
				sum += fabs(mat[c][j]);
			}
			if (fabs(mat[c][c]) > sum)
			{
				isDiag = 1; //True if it matches the row
			}
			else
			{
				isDiag = 0; // False if it dosen't
				break;
			}
		}
    return isDiag;
}
