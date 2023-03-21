#include <iostream>
#include <vector>

using namespace std; 


// Employee is a separate class with employee name, unique email, designation, salary, and which group they are member of (identified by group id). 

class Employee{
private:
  string name, email, designation, group_id; 
  int salary; 
public:

 //getters and setters
  Employee& set_name(string n) {(*this).name=n; return *this;}
  Employee& set_email(string em) {(*this).email=em; return *this;}
  Employee& set_desig(string des) {(*this).designation=des; return *this;}
  Employee& set_groupid(string id) {(*this).group_id=id; return *this;}
  Employee& set_salary(int sal) {(*this).salary=sal; return *this;}
  //get salary
  int get_salary() {return salary;} //in-line
  string get_groupid() {return group_id;} //in-line
  void output() const {cout<<salary<<endl;} //-inline

// friend
friend std::istream& operator>> (std::istream& in, Employee& value);
friend std::ostream& operator<< (std::ostream& out, const Employee&value);

// friend Employee operator++(Employee& one); //pre-increment
// Employee operator++(int dummyValue); //post-increment

};

// which includes a group's name, unique group number, focus area or responsibility, and a list of employees of that group 
class Group{
private:
  string name, task;
  int unique_gnum; // unique group num
  // list of employees of that group
  vector<Employee> people;

public:
  //getters and setters
  Group& set_name(string nam) {(*this).name=nam; return *this;}
  Group& set_task(string t) {(*this).task=t; return *this;}
  Group& set_unique_gnum(int in) {(*this).unique_gnum=in; return *this;}  
  int get_unique_gnum() {return unique_gnum;} //in-line
  int get_size() {return this->people.size();}

  Group addEmployee(Employee &e); 
  // friend functions
  friend Group operator+(Group &a, Group &b);
  friend Group operator-(Group &a, const int &num);
  friend vector <Group> operator/(Group &a, int num);
  friend ostream & operator << (ostream &out, const Group &c);
  friend istream & operator >> (istream &in,  Group &c);

};

// add one employee to people vector
Group Group::addEmployee(Employee &e){
  this->people.push_back(e); 
  return *this; 
}

//overload +
Group operator+(Group &a, Group &b){
  Group newGroup; 
  // cout << a.people.size()<<endl; 
  for(int i= 0; i< a.get_size(); i++)
    {
      newGroup.addEmployee(a.people[i]);
    }
  
  for(int i= 0; i< b.get_size(); i++)
  {
    newGroup.addEmployee(b.people[i]);
  }
    
  return newGroup;
}

// overload -, group loses x(2) employees
  Group operator-(Group &a, const int &num)
{
// Employee salary;
  for(int i= 0; i< num; i++)
  { 
    // removes the last added employee
    a.people.pop_back(); 
  }
  return a;
}

//overload /
vector <Group> operator/(Group &a,int num){
vector <Group> newGroup;
for(int j = 0; j < num; j++){
newGroup.push_back(Group()); 
int new_id;
string new_name;
cout << "Enter new groupid "<< endl;
cin >> new_id;
cout << "Enter new group name "<<endl;
cin >> new_name; 
newGroup[j].set_name(new_name);
newGroup[j].set_unique_gnum(new_id);
}
  
int added = 0;
while(added < a.people.size())
{
  for (int i =0; i< newGroup.size(); i++)
    {
      if(added < a.people.size())
      {
        newGroup[i].addEmployee(a.people[added]);
        //newGroup[i].people.back().set_groupid(newGroup[i].get_unique_gnum());
        added++;
      }
    }
}
  return newGroup; 
}

// cout and cin
std::ostream& operator<< (std::ostream& out, const Employee& c ){
out<<c.name<<endl;
// out<<c.name<<":"<<c.unique_gnum<<endl;
return out;
}
std::istream& operator>> (std::istream& in, Employee& c ){
cout<<"Enter name for employee: ";
in >> c.name; //>> value.email;
return in;
}

int main() {
  Employee anne;
  Employee dave;
  Employee fred;
  Employee jack;
  Employee sam;
  Employee bob;
  Employee pam;
  Employee sally;
  Employee mike;
  // create two groups
  Group a;
  Group b; 
  anne.set_name("anne");
  anne.set_email("anne@gmail");
  anne.set_desig("coder");
  anne.set_groupid("abcd");
  anne.set_salary(100);
  dave.set_name("dave");
  dave.set_email("dave@gmail");
  dave.set_desig("manager");
  dave.set_groupid("abced");
  dave.set_salary(200);
  a.addEmployee(anne); 
  a.addEmployee(fred); 
  a.addEmployee(jack); 
  a.addEmployee(pam); 
  b.addEmployee(dave); 
  b.addEmployee(bob);
  b.addEmployee(sally);
  b.addEmployee(mike);
  b.addEmployee(sam);
  cout<<"Example for + operation:" <<endl;
  cout << "group a size is " << a.get_size()<<endl; 
  cout << "group b size is " << b.get_size()<<endl;
  // test + operation
  Group c = a + b; 
  cout << "added groups have size of " << c.get_size()<<endl;
  // test - operation
  cout << endl;
  cout<<"Example for - operation: " <<endl;
  cout << "removing 1 employee from group a..."<<endl;
  a = a-1;
  cout<<"size of group a is now " << a.get_size()<<endl;

  cout<<endl;

  cout<<"Example for split group" << endl;
  int num_divide;
  cout<<"enter number to divide by ";
  // choose 2
  cin>> num_divide;
  vector<Group> sp = a/num_divide; 
  // for (auto s: sp)
  // {
  //   cout<<s<<endl;
  // }
  
  cout<<endl;
  
  cout<<"Example for cout and cin:" <<endl;
  Employee e;
  cin >> e;
  cout << "Employee name is: ";
  cout << e;
  a.addEmployee(e); 
  cout<<e<<"is in group a";
  
}