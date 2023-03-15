#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	FILE *input_file = fopen(filename, "r");
	fscanf(input_file, "%d", sizePtr);
	class_list = calloc(*sizePtr, sizeof(student));
	
	for(int i = 0; i < *sizePtr; i++)
	{
		class_list[i] = (student *)calloc(1, sizeof(student));
		fscanf(input_file, "%d", &(class_list[i] -> student_id));
		fscanf(input_file, "%s", class_list[i] -> first_name);
		fscanf(input_file, "%s", class_list[i] -> last_name);
	}
	
	fclose(input_file);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	for(int i = 0; i < size; i++)
	{
			if (list[i] -> student_id == idNo)
			{
				return i;
			}
	}
	/*write your implementation here and update the return accordingly*/
	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	FILE *input_file = fopen(filename, "r");
		for(int i = 0; i < size; i++)
		{

			int stuID;
			int position;
			fscanf(input_file, "%d", &stuID);


			position = find(stuID, list, size);


			fscanf(input_file, "%d", &(list[position] -> project1_grade));
			fscanf(input_file, "%d", &(list[position] -> project2_grade));
		}

		fclose(input_file);
}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	for(int i = 0; i < size; i++)
	{
		list[i] -> final_grade = ((double)list[i] -> project1_grade + (double)list[i] -> project2_grade) / 2.0;
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *output_file = fopen(filename, "w");
	fprintf(output_file, "%d\n", size);
	for(int i = 0; i < size; i++)
	{
		fprintf(output_file, "%d %f\n", list[i] -> student_id, list[i] -> final_grade);
	}
	fclose(output_file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int location;

	location = find(idNo, list, *sizePtr);
	if(location == -1)
	{
		printf("Student %d is not in the list\n", idNo);
	}
	else
	{
		free(list[location]);
		(*sizePtr) --;

		for (int i = location; i< *sizePtr; i++)
		{
			list[i] = list[i+1];
		}
	}

}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i = 0; i < *sizePtr; i++)
	{
		free(list[i]);
	}
	free(list);
	*sizePtr = 0;
}
