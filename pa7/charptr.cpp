// This program should read any string (including spaces) from the user and
// print it using a character pointer The program is setup to use pointer offset
// notation to get each character of the string

// Number of bugs/errors : 8
#include <iostream> // add iostream
#include <stdio.h>  // change stdio to stdio.h
#include <string>

using namespace std;

int main() // remove void from the front of int
{
  char s[20];
  char *cPtr; // add star in front of cPtr

  cout << "enter string: ";
  cin.getline(s, 20); // change cin to getline
  cPtr =
      s; // change cptr to pointer to store address of first character in string
  // define char cPtr in this line
  while (*cPtr != '\0') { // add * to cPtr to access value of address
    cout << *cPtr;
    cPtr++; // add * before here to access value
  }
  cout << "\n";
  return 0;
} // end of main