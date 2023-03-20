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

// overload /
// vector <Group> operator/(Group &a,int num){
// Group split;
//  for(int i= 0; i< a.get_size(); i++)
//   {
//     split.addEmployee(a.people[i]);
    
//   }
// split = a.people[i]/2; 
//   // return vector of new group
// return v; 
// }


// cout and cin
std::ostream& operator<< (std::ostream& out, const Employee& value ){
out<<value.name<<"="<<value.email<<endl;
return out;
}
std::istream& operator>> (std::istream& in, Employee& value ){
in >> value.name >> value.email;
return in;
}

int main() {
  // create two groups
  Employee anne;
  Employee dave;
  Employee fred;
  Group a;
  Group b; 
  anne.set_name("anne");
  anne.set_email("anne@gmail");
  anne.set_desig("code");
  anne.set_groupid("abcd");
  anne.set_salary(100);
  dave.set_name("dave");
  dave.set_email("dave@gmail");
  dave.set_desig("manager");
  dave.set_groupid("abced");
  dave.set_salary(200);
  a.addEmployee(anne); 
  a.addEmployee(fred); 
  b.addEmployee(dave); 
  cout << "group a size is " << a.get_size()<<endl; 
  cout << "group b size is " << b.get_size()<<endl;
  // test + operation
  Group c = a + b; 
  cout << "added groups have size of " << c.get_size()<<endl;
  // test - operation
  cout << "removing 1 employee from group a..."<<endl;
  a = a-1;
  cout<<"size of group a is now " << a.get_size()<<endl;

}