// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with
the last 4 digits Example : If areacode = 617, exchange = 424 Output : "I am
calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <limits>
using namespace std;

int main() {
  int digit1, digit2, digit3, digit4;
  int areaCode, exchange;
  std::cout << "Hello, I am a telemarketing calling making program.\n";
  std::cout << "Enter a three-digit area code ";
  std::cin >> areaCode;
  // FIX: moved cin areaCode to under the cout asking for area code
  std::cout << "Enter a three-digit exchange to call ";
  std::cin >> exchange;
  // FIX: moved cin exchange to under the cout asking for exchange code
  cout << "I am calling to tell you to buy a subscription to Dogs Monthly!\n";
  for (digit1 = 0; digit1 <= 9; ++digit1) {
    // FIX: changed digit1 max to be less than or equal to 9 instead of 10
    // because 9 is the highest digit for a phone number
    for (digit2 = 0; digit2 <= 9; ++digit2) {
      for (digit3 = 0; digit3 <= 9; ++digit3) 
      {
        // FIX: changed digit3 to for loop to make it easier to loop through
        // FIX: changed digit3 incrememnt to ++ instead of -- because numbers
        // are increasing
        for (digit4 = 0; digit4 <= 9; ++digit4) {
          // FIX: changed the rest of the digits to start at 0 and have a max of
          // 9 FIX: added for loop for digit 4
          cout << "Dialing (" << areaCode << ") " << exchange << " - " << digit1
               << digit2 << digit3 << digit4 << " " << endl;
          // FIX: reorganized output to add the 4 digits to the end of the area
          // and exchange codes.
        }
      }
    }
  }
  std::cout << "\nCalls completed" << endl;
  return 0;
}
