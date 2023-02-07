// Yasmeen Dao
// 2/7/23 Rolls dice and counts frequency of roll
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

// variables
int dice1 = 0;
int dice2 = 0;
int sum = 0; 
// aray for number of times sum appears
//13 for sums 2-12
const int size = 13;
int sum_arr[size] = {0}; 

// roll function
void roll(){
  // roll dice 36000 times
  for(int i =0; i <=36000; ++i)
    {
    dice1 = rand() % 6 + 1;
    //cout<<"dice1 is"<<" "<<dice1<<endl;
    dice2 = rand() % 6 + 1;
   // cout<<"dice2 is"<<" "<<dice2<<endl;
    sum = dice1 + dice2;
    //cout<<"sum is "<< sum;
    sum_arr[sum]++; 
    }
 }; 

int main() 
{
  /* Pseudocode: 
    - randomly generate number for first die
    - randomly generate number for second die
    - sum the two rolls
    - roll two dice 36,000 times
    - use array or vector to tally the number of times each possible sum appears
    - print in tabular form with tally and percentage of times particular number appears

  */
  srand (time(NULL));

  // call function
  roll();

  cout<<"Sum "<< " "<<"Total" <<"  "<<" Percent Frequency"<<endl;
 
  // tally number of times sum appears
  for (int num = 2; num < size; num++)
    {
      // calculate frequency
      cout << num << setw(8)<< sum_arr[num]<< setw(15) <<
      100.0 * sum_arr[num] / 36000 << " "<< "%" << endl;
    }
} // end of main