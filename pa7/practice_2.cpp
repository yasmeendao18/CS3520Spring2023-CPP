// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10

#include <iostream>
using namespace std;
void display(int (Matrix)[3][3], int size); //change int matrix
// get rid of the * from matrix
// initialize all matrix to [3][3]

int main(void) {
  int size = 3;
  int Matrix[3][3];
  cout << "Enter 9 elements of the matrix:" << endl; //change cin to cout
  for (int i = 0; i < size; i++) 
  { //add int
    //int j = 0;
    for (int j = 0;j < size; j++) 
    {
      cin >> Matrix[i][j]; //flip i and j
    }
  }
  display(Matrix,3); //call matrix and 3
  return 0;
}

void display(int (Matrix)[3][3], int size) { //change to int size
  for (int i = 0; i < size; i++) { //add semi-colon after size
    for (int j = 0; j < size; j++)  // change to j++
    {
      cout << Matrix[i][j] << ", ";
    }
    cout << endl; //add semi colon
  }
}
