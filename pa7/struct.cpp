// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same

// Bugs to fix : 9

#include <iostream>
#include <string>
using namespace std; // add namespace

struct car {
  char *name;
  int modelYear;
  float speed;
};

int main(void) {
  char n[20];
  int a;
  float w;

  struct car c;
  car *cPtr = &c;

  cout << "What is your favorite car's name: ";
  cin >> n;
  c.name = n; //add c before

  cout << "When was it launched : ";
  cin >> a; //change >> to << 
  // change cout to cin
  c.modelYear = a;

  cout << "How much speed does it give : ";
  cin >> w; // change << to >>
  c.speed = w; //set c.speed equal to w

  cout << "Car's name is " << c.name << ", and should be the same as "
       << cPtr->name << ".\n"; //use ->

  cout << "Car's model year is " << c.modelYear //change to c
       << ", and should be the same as " << a << ".\n"; //add a
  cout << "Car's speed is " << c.speed << ", and should be the same as " << w
       << ".\n";
}