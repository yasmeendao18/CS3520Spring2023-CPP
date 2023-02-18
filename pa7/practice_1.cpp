
// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25

// TODO: Fix the bugs and make sure the program runs as expected.
// Provide a brief comment identifying each bug fixed.

#include <iostream>
using namespace std;  //add namespace

bool func(int); // change to bool
// remove char x from parameter
int main() { //remove void
  int input; // change data type to int
  // remove it set to 1001
  bool returned_val = false; // declare returned value
  cout << "enter an integer please ";
  cin >> input;// get the user input
  returned_val = func(input); //change function to func not func2
 // set parameter to input instead of return_value_function
 if (returned_val) {
    cout << "It is not a palindrome" << endl; // add quotations for cout statement
      // add semi-colon after endl
  } else {
    cout << "It is a palindrome" << endl;
  }

  return 0; // add semi colon
}

// the return value of your func should be true / false only
bool func(int input)  //change function to bool because returning true or false
// change parameter to input
{  // change to int before
  //int n; // don't need variable n
  int given_number; // add semi-colon
  given_number = input; //set given_number equal to the input
  // change to int given_number
  int temp = 0; // separate variables
  int remainder = 0; //declare variable remainder
  while (input != 0) // change to not equals
  {
    remainder = input % 10; // change to input % 10
    temp = (temp * 10) + remainder;
    input = input / 10; // change to input / 10
  }
  if (given_number==temp) // change given number equal to temp
  {
    return false;
  } else 
  {
    return true;
  }
}
