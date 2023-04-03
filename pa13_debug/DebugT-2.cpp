// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;
template <class T>

void findBiggest(T a, T b, T c) //change int b to T b
{
   T large = a;
   if (b > large) 
      large = b;
   if (c > large) //change to > instead of <
      large = c;
   cout << "The largest of " << a << " " << b << " " << c << " is " << large << endl; //change a to large
}
template <class T>
void findBiggest(T a, T b)
{
   T large = b;
   if (a > large) 
      large = a;
   cout << "The larger of " << a << " " << b << " is " << large << endl; //should be large
}
class BankAccount
{
   friend ostream &operator<<(ostream &, const BankAccount &);

private:
   string name;
   int amount;

public:
   BankAccount(const string&, const int); //add string parameter
   bool operator>(const BankAccount &);
};
BankAccount::BankAccount(const string &name, const int amount)
{
   this->name = name; // add this
   this->amount = amount; // add this
}
ostream &operator<<(ostream &out, const BankAccount &bh)
{
   out << "Name: " <<bh.name << " Amount: " << bh.amount << endl; //change to bh.name and bh.amount
   return out;
}
bool BankAccount::operator>(const BankAccount &bh)
{
   bool flag = false; //should be = instead of ==
   if (amount > bh.amount)
      flag = true;
   return flag;
}
int main()
{
   BankAccount bAA("A", 800);
   BankAccount bAB("B", 120);
   BankAccount bAC("C", 500);
   findBiggest(bAA, bAB);
   findBiggest(bAB, bAC);
   findBiggest(bAC, bAA);
   findBiggest(bAA, bAB, bAC);
   return 0;
}
