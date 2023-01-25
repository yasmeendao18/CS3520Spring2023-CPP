//debug code 1
//Yasmeen Dao 1/24/23
#include <iostream>
#include <limits>
using namespace std;

int main() {
  /* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with
'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

  // Check for possible compiler errors, logical errors and rectify them
  // Re-factor the code by adding few comments (make it readable) and
  // provide list of most important fixes (in comments)

  int limit = 10, even_product = 1, odd_product = 1, sum = 0;
  // FIX: set the initial limit to 10, the even and odd product to 1
  // so that the limit reflects the max of 10
  char c;
  cout << "The value of limit is " << limit << endl;
  for (int i = 1; i <= limit; ++i) {
    // FIX: started the for loop at 1 because the problem asks for numbers 1 to
    // 10
    if (i % 2 == 0) {
      // changed both if statements to use module in calculation to be easier to
      // find the remainder; if remainder = 0 then even number and if remainder
      // = 1      // then odd number
      even_product *= i;
      // FIX: changed even_product to multiply by each i because question asked
      // for the product of all the even numbers
    }
    if (i % 2 == 1) {
      odd_product *= i;
      // FIX: changed odd_product to multiply by each i because question asked
      // for the product of all the odd numbers
    }
  }
  sum = even_product + odd_product;
  cout << "The Sum = " << sum << endl;
  // FIX: not sure if significant but just changed format of the output

  for (char c = 'Z'; c >= 'B'; c -= 2) {
    // FIX: changed the loop to start with Z and end with B and print every
    // other letter; added c-=2 to choose every other letter.
    cout << c << " ";
  }
  return 0;
} // end main