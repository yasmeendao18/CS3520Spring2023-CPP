// This program allocated memory for an NxM integer array dynamicaly
// The program then prints the 2D array in a matrix form using a combination of
// * and [] operators Note: You can't use ** or [][] for printing the values
// (use a combination of * and [] only.

// Number of bugs/errors : 6

#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int N = 3, M = 5;
  int i, j;
  int **d_array = (int **)malloc(N * sizeof(int *));   // Allocating memory for 2D array (N rows) // add pointer
  for (i = 0; i < N; i++) // changed comma to semi colon, changed M to N
    d_array[i] = (int *)malloc(M * sizeof(int *)); // Allocating memory for each row with M columns)
  // Initializing 2D array using [ ][ ] notation
  printf("Initializing array values!\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      *(d_array[i]+j) = i + j; // added semi-colon to end
      // removed & and added another pointer to d_array
    }
  }
  // Accessing 2D array using a combination of * and [] notation
  printf("\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) { // change to M
      cout << *(d_array[i] + j);
    }
    cout << "\n";
  }

  // Deallocating 2D array
  for (i = 0; i < N; i++)
    free(d_array[i]); //add bracket i for d_array
  free(d_array);
}
