
#include "Questions.h"



int Q1_for(){
	int sum_for = 0;
	int a;
	// calculate your sum below..this has to use for loop
	 for (a = 30; a <= 1000; a++)
	 {
		 if (a%4 == 0)
		 {
			 sum_for += a;
	     }
	 }
	// here, we return the calcualted sum:
	return sum_for;
}
int Q1_while()
{
	int sum_while = 0;
	int b = 30;
	// calculate your sum below..this has to use while loop
	while (b <= 1000)
	{
		if (b%4 == 0)
		{
			sum_while += b;
		}
		        b++;
	}
	// here, we return the calcualted sum:
	return sum_while;
}
int Q1_do(){
	int sum_do = 0;
	int c = 30;
	// calculate your sum below..this has to use do-while loop
	do
	{
		if (c%4 == 0)
		{
			sum_do += c;
		}
				c++;
	}
	while (c <= 1000);
	
	// here, we return the calcualted sum:
	return sum_do;
}
//===============================================================================================
int Q2(int Q2_input)
{
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit = 0;
	
	// Do your coding below to check
	if ((Q2_input<100000 && Q2_input>=10000)||(Q2_input<=-10000 && Q2_input>-100000))
	{
		IsFiveDigit = 1;
	}
	

	            
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input)
{
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	GPA = 0;

		 if (Q3_input <= 100 && Q3_input >= 90)
		 {
			 GPA = 4;
		 }
		 else if (Q3_input <= 89 && Q3_input >= 80)
		 {
			 GPA = 3;
		 }
		 else if (Q3_input <= 79 && Q3_input >= 70)
		 {
			GPA = 2;
		 }
		 else if (Q3_input <= 69 && Q3_input >= 60)
		 {
			GPA = 1;
		 }
		 else if (Q3_input <= 59 && Q3_input >= 50)
		 {
			GPA = 0;
		 }
		 else
		 {
			 GPA = -1;
		 }
	// Do your coding below to calculate the GPA variable value
	
	 
	
	
	// finally, we return the GPA
		 return GPA;
}
//===============================================================================================
double Q4(int Q4_input)
{
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	double d ;
	int term = 1;
	if (Q4_input>0)
	{
		for (d=1;d<=Q4_input;d++)
		{
					pi = pi+term*4/(d*2-1);
					term  = term*(-1);
		}
	}
	else
	{
		pi = -1;
	}
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5()
{
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	int side1, side2, side3;
	for (side1=1;side1 <= 400;side1++)
	{
		for (side2 = side1;side2 <= 400;side2++)
		{
			for (side3=1;side3<=400;side3++)
			{
				if (side1*side1 + side2*side2 == side3*side3)
				{
					totNumTribles += 1;
				}
			}
		}
	}


	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[])
{
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    
	    int k, factor, thesum;
	   	for (k=1;k< Q6_input;k++)
	   	{
	   	    thesum = 0;
	   	    for (factor=1;factor<k;factor++)
	   	    {
	   	    	if (k%factor == 0)
	   	    	{
	   	    		thesum += factor;
	   	    	}
	   	    }
	   	    if (thesum == k)
	   	    {
	   	    	perfect[counts] = k;
	   	    	counts += 1;

	   	    }
	   	 }
	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input)

{
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	int  digit_rev, digit_input, remain,num_val,f;
		digit_input = 1000000;
		digit_rev = 1;
		remain = Q7_input;

		for (f=0;f<7;f++)
		{
			num_val = remain/digit_input;  
			remain %= digit_input;		
			reversedInt += (num_val * digit_rev); 	
			digit_input /= 10;				
			digit_rev *= 10;
		}
		return reversedInt;
}
int Q7b(int Q7b_input)
{
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	int digit_input ,digit_rev,digit_num, num_val, remain,g;

		digit_input = 1;
		digit_rev = 1;
		digit_num = 1;
		remain = Q7b_input;

		while (Q7b_input/digit_input>=10)
		{
			digit_num++;
			digit_input *= 10;  
		}

		for (g=0;g<digit_num;g++)
		{
			num_val = remain/digit_input;  
			remain %= digit_input;
			reversedInt += (num_val * digit_rev);
			digit_input /= 10;
			digit_rev *= 10;
		}
	
	return reversedInt;

}
