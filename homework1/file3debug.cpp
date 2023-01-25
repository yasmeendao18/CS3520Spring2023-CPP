//debug code 3
//Yasmeen Dao 1/24/23
/*  This program should determine if a number is a prime or composite number
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite
   number" depending on the number */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <limits>
using namespace std;

int main(void) {
  int num, i;
  bool factor_found = false;
  // FIX: lowercase boolean false
  cout << "Enter Number:\n";
  cin >> num;
  if (num == 0 || num == 1)
  // FIX: changed logic in if statement to 'or' instead of 'and'
  //  because either 0 or 1 are not prime or composite
  // the number doesn't have to be both 0 and 1
  {
    cout << num << " is not prime or composite";
    // FIX: added semi-colon after cout statement
  } else {
    for (i = 2; i < num; i++)
    // FIX: added semi-colon after num instead of comma
    {
      if (num % i == 0) {
        factor_found = true;
        // FIX: lower-case boolean true
        cout << "is a composite number\n";
        break;
      }
    }
    if (not factor_found)
    // FIX: added parantheses around not factor_found
    {
      cout << "is a prime number\n";
      // FIX: added semi-colon after cout statement
    }
  }
}