
// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with for.
#include <cmath> // standard math library
#include <iomanip>
#include <iostream>
using namespace std;

int main() 
{
  double amount;           // amount on deposit at end of each year
  double principal = 24.0; // initial amount before interest
  double rate = 0;         // annual interest rate

  // display headers
  cout << "Year" << setw(21) << "rate" << setw(20) << "Amount on deposit"
       << endl;

  // set floating-point number format
  cout << fixed << setprecision(2);

  // calculate for rates 2% to 12%
  // calculate amount on deposit for each of 397 years
  for (double rate = .02; rate <= .12; rate += .01) {
    for (unsigned int year = 1; year <= 397; ++year) {
      // calculate new amount for specified year
      amount = principal * pow(1.0 + rate, year);
      // display the year and the amount
      cout << setw(4) << year << setw(20) << rate << setw(30) << amount << endl;
      // calculate new amount for specified year
    }
    principal = 24.0;
  } // end for
} // end main