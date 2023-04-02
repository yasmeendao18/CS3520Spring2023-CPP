// Debug T-1
// Function template subtracts objects from each other. The function works on any object which has '-' opertor defined.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;
template <class T>
T add(T x, T y) // add T before y
{
   T sum; //change U to T
   sum = x + y;
   return sum;
}
class Person
{
   friend ostream &operator<<(ostream &, const Person &);

private: 
   string lastName;
   string firstName;
   int age;

public:
   void setValues(string, string, int);
   Person operator+(Person); // change to Person with capital P
};


ostream &operator<<(ostream &out, const Person &per) //add const before Person for const reference to the Person
{
  out << per.firstName << " " << per.lastName << " " << per.age << " years old" << endl;
  return out; // add return statement
}
void Person::setValues(string last, string first, int age)
{
   lastName = last;
   firstName = first;
   this->age = age; // use "this" to get the age of member varibale instead of varible of same name
}
Person Person::operator+(Person p)
{
   Person temp;
   temp.lastName = "of Age"; 
   temp.firstName = "Sum";
   temp.age = age + p.age; //change age to temp.age, age calculation incorrect
   return temp;
}

int main()
{
   int a = 7, b = 26, c;
   double d = 39.25, e = 2.01, f;
   Person g, h, i;
   g.setValues("Mitchell", "Donald", 40);
   h.setValues("Clayton", "Rita", 35);
   c = add(a, b);
   f = add(d, e);
   i = add(g, h);
   cout << c << endl;
   cout << f << endl;
   cout << i << endl;
   return 0;
}
