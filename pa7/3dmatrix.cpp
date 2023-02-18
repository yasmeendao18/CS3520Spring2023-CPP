// Program to read 3-dimensional matrix and display the elements as 1x3 N matrix
// TODO
// initialize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
#include <math.h>

using namespace std; //added namespace

#define SIZE 7

// void update_3d(double Matrix_3d[][SIZE][SIZE],int size); 
// void display_1d(double Matrix_3d[][SIZE][SIZE],int size); 
void update_3d(double ***matrix, int size);
void display_1d(double ***matrix, int size); // triple array

int main(void) {
	//prompt the use to enter appropriate dimensions and initialize the matrix accordingly
  int userval = 0; 
  cout<<"Enter matrix size: ";
  cin>>userval;
  
	//double Matrix_3d[SIZE][SIZE][SIZE] = {};
  // triple pointer reference in array
  double ***new_array = (double ***) malloc(userval * sizeof(double**));
  for(int i = 0; i<userval; i++)
    {
      new_array[i] = (double**)malloc(userval * sizeof(double*));
      for(int j = 0; j < userval; j++)
        {
          new_array[i][j] = (double*) malloc(userval * sizeof(double));
        }
    }
	//initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(new_array, userval);
	//display the values
	display_1d(new_array, userval);
  return 0;


} //end of main

void update_3d(double ***matrix, int size)
{
	cout<<"Entering 3N elements of the matrix:"<<endl;
 int i = 0;
	for (; i < size; i++)
    {
      int j = 0;
      for (; j < size; j++)
	  {
	      int k = 0;
	      for (; k < size; k++)
		    {    
          // use random number generator
          matrix[i][j][k] = rand() % 30; 
          cin>>matrix[i][j][k];
	      }
      }
    }
}

//update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.
void display_1d(double ***matrix, int size) // change to ***matrix
{ //matrix, other args
	
	for (int i = 0; i < pow(size,3); i++) 
  {
      int a = i%size;
      int b = i/pow(size,2);
      int c = (i-(b*pow(size,2)))/size;
      cout<<"matrix["<<b<<"]["<<c<<"] ["<<a<<"]"<<endl;
    cout<<"Address is: " << *(*(matrix+b)+c)+a <<" Value is: "<< matrix[a][b][c]<<endl;
  } //end of for

} // end of display_1d method
