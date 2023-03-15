#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	for (int a = 0; a < size ; a++)
	{
			vector3[a] = vector1[a] + vector2[a]; //each element in vector3 is equal to the element in vector1+element in vector2
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod = 0;

	//write your code below to calculate the prod value
    for (int b = 0; b < size; b++)
    {
    		prod += (vector1[b] * vector2[b]); // The product of each element will be added to variable prod
    }
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    L2 = sqrt(scalar_prod(vector1,vector1,size));
	//write your code here
	// you should call function scalar_prod().
	
	//finally, return the L2 norm 
    return L2;
}
