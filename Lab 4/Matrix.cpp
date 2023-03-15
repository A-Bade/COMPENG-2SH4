
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col )

{

	rowsNum=row;
	colsNum=col;
	matrixData=NULL;
	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/
	if(row>0)
	{
		rowsNum = row;
	}
	else
	{
		rowsNum = 3;
	}

	if(col>0)
	{
		colsNum = col;
	}
	else
	{
		colsNum = 3;
	}

	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	for (int i = 0 ; i < rowsNum; ++i )
	{
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
	}

	for (int i = 0 ; i < rowsNum ; i++ )
	{
		for (int j = 0 ; j < colsNum ; j++ )
		{
			matrixData[i][j]=0;
		}
	}





}


Matrix::Matrix(int row, int col, int** table)
{

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	rowsNum=row;
	colsNum=col;
	matrixData=NULL;

	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	 for (int i = 0 ; i < rowsNum; ++i)
	 {
		 matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	 }

	 for (int i = 0 ; i < rowsNum ; ++i )
	 {
		 for (int j = 0 ; j < colsNum ; ++j )
		 {
			 matrixData[i][j] =* (*(table + i) + j);
		 }
	 }

}

int Matrix::getElement(int i, int j)
{

	if((i >= 0 && i < rowsNum) && (j >= 0 && j < colsNum))
	{
		return matrixData[i][j];
	}
	else
	{
		throw std::out_of_range( "Invalid indexes." );
		return -1;
	}

}

bool Matrix::setElement(int x, int i, int j){

	if((i >= 0 && i < rowsNum)&&(j >= 0 && j < colsNum))
	{
		matrixData[i][j] = x;
		return true;
	}
	else
	{
		return false;
	}
}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */
	Matrix copy = Matrix(rowsNum,colsNum);

	for (int i = 0; i < rowsNum; i++)
	{
		for (int j = 0; j < colsNum; j++)
		{
			copy.setElement(getElement(i,j), i, j);
		}
	}
    return  copy;


}


void Matrix::addTo( Matrix m )
{
	if((rowsNum == m.rowsNum)&&(colsNum == m.colsNum))
	{
		for (int i=0;i<rowsNum;i++)
		{
			for (int j=0;j<colsNum;j++)
			{
				matrixData[i][j] += m.getElement(i, j);
			}
		}
	}
	else
	{
		throw std::invalid_argument("Invalid operation");
	}
}


Matrix Matrix::subMatrix(int i, int j)
{

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */
	Matrix subM = Matrix (i+1,j+1);

	if((i < 0 || i >= rowsNum) || (j < 0 || j >= colsNum))
	{
		throw std::out_of_range("Submatrix not defined");
	}
	else
	{
		for (int m = 0; m <= i+1; m++)
		{
			for (int n = 0; n <= j+1; n++)
			{
				subM.setElement(getElement(m, n), m, n);
			}
		}
	}



    return  subM;
}


int Matrix::getsizeofrows(){


	/* update below return */
	return -1;
}


int Matrix::getsizeofcols(){



	/* update below return */
    return -1;
}


bool Matrix::isUpperTr()
{

	/* write your implementation here and update return accordingly */
	for (int i = 1; i < rowsNum; i++)
	{
		for (int j = 0; (j < i); j++)
		{
			if(matrixData[i][j] != 0)
			{
				return false;
			}
		}
	}
	  return true;
}


string Matrix::toString()
{

	string output;

	for (int i = 0; i < rowsNum; ++i)
	{
		for(int j = 0; j < colsNum; ++j)
		{
			output += (to_string(matrixData[i][j]) + " ");
		}
		output += "\n";
	}
	//return output;
	 return output;
}
