/*
Yasmeen Dao
CS3520 / pa6
Pointers and Structures
2/16/23
Partner Elizabeth Peters
*/
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

struct planet {
  unsigned int planet_number;
  char *planet_name;
  struct {
    char origin[10];
    int age;
  } personal, *personal_ptr = &personal;
} planet_record, *planet_ptr = &planet_record, all_records[5];

int main() {
  // part 2
  planet_record.planet_number = 2;
  planet_record.planet_name = (char *)new char[9];
  strcpy(planet_record.planet_name, "Saturn");
  planet_record.personal.age = 2000;
  strcpy(planet_record.personal.origin, "nebula");

  /*
  errors:
  1 error in cout << planet_ptr.personal_ptr->origin << endl;
  Needed to change to-> instead of . because prompt was asking for structure pointer not just
structure member. Otherwise no other errors in the part 1 initial comments for the code. 
  */

  // part 1
  cout<< "Part 1 code"<<endl;
  // a) planet_number of structure planet_record.
  cout << planet_record.planet_number << endl;
  // b) planet_number of the structure pointed to by planet_ptr.
  cout << (*planet_ptr).planet_number << endl;
  // c) last_name of structure planet_record.
  cout << planet_record.planet_name << endl;
  // d) last_name of member structure pointed to by planet_ptr.
  cout << (*planet_ptr).planet_name << endl;
  // e) age of the structure member personal of structure planet_record.
  cout << planet_record.personal.age << endl;
  // f) age of member pointed to by personal_ptr of the structure pointed to by
  // planet_ptr.
  cout << planet_ptr->personal_ptr->age << endl;
  // g) origin of the structure member personal of structure planet_record.
  cout << planet_record.personal.origin << endl;
  // h) origin of member pointed to by personal_ptr of the structure pointed to
  // by planet_ptr.
  cout << planet_ptr->personal_ptr->origin << endl;

  // part 3a
  // Initialize all members of all 5 planets stored in all_records and print
  // them neatly.
  // planet number
  all_records[0].planet_number = 1;
  all_records[1].planet_number = 2;
  all_records[2].planet_number = 3;
  all_records[3].planet_number = 4;
  all_records[4].planet_number = 5;

  // planet age
  all_records[0].personal.age = 1000;
  all_records[1].personal.age = 2000;
  all_records[2].personal.age = 3000;
  all_records[3].personal.age = 4000;
  all_records[4].personal.age = 5000;

  // planet origin
  strcpy(all_records[0].personal.origin, "nebula");
  strcpy(all_records[1].personal.origin, "big bang");
  strcpy(all_records[2].personal.origin, "pulsating");
  strcpy(all_records[3].personal.origin, "nebula");
  strcpy(all_records[4].personal.origin, "nebula");

  // planet name
  (all_records + 0)->planet_name = (char *)new char[strlen("Mercury") + 1]; //use this for strcpy
  strcpy(all_records[0].planet_name, "Mercury");
  (all_records + 1)->planet_name = (char *)new char[strlen("Venus") + 1];
  strcpy(all_records[1].planet_name, "Venus");
  (all_records + 2)->planet_name = (char *)new char[strlen("Earth") + 1];
  strcpy(all_records[2].planet_name, "Earth");
  (all_records + 3)->planet_name = (char *)new char[strlen("Mars") + 1];
  strcpy(all_records[3].planet_name, "Mars");
  (all_records + 4)->planet_name = (char *)new char[strlen("Saturn") + 1];
  strcpy(all_records[4].planet_name, "Saturn");

  cout<<endl;
  cout<<"Part 3a code"<<endl;
  // loop through array of all_records
  for (int i = 0; i < 5; i++) 
  {
    cout << all_records[i].planet_number << "," << all_records[i].personal.age<<","<<
      all_records[i].planet_name <<","<< all_records[i].personal.origin << endl;
  }

  // Part 3b
  // pointer that points to dynamically allocated array
  planet *all_planets = new planet[5];

  // planet number
  all_planets[0].planet_number = 1;
  all_planets[1].planet_number = 2;
  all_planets[2].planet_number = 3;
  all_planets[3].planet_number = 4;
  all_planets[4].planet_number = 5;

  // planet age
  all_planets[0].personal.age = 1000;
  all_planets[1].personal.age = 2000;
  all_planets[2].personal.age = 3000;
  all_planets[3].personal.age = 4000;
  all_planets[4].personal.age = 5000;

  // planet origin
  strcpy(all_planets[0].personal.origin, "nebula");
  strcpy(all_planets[1].personal.origin, "big bang");
  strcpy(all_planets[2].personal.origin, "pulsating");
  strcpy(all_planets[3].personal.origin, "nebula");
  strcpy(all_planets[4].personal.origin, "nebula");

  // planet name
  (all_planets + 0)->planet_name = (char *)new char[strlen("Mercury") + 1];
  strcpy(all_planets[0].planet_name, "Mercury");
  (all_planets + 1)->planet_name = (char *)new char[strlen("Venus") + 1];
  strcpy(all_planets[1].planet_name, "Venus");
  (all_planets + 2)->planet_name = (char *)new char[strlen("Earth") + 1];
  strcpy(all_planets[2].planet_name, "Earth");
  (all_planets + 3)->planet_name = (char *)new char[strlen("Mars") + 1];
  strcpy(all_planets[3].planet_name, "Mars");
  (all_planets + 4)->planet_name = (char *)new char[strlen("Saturn") + 1];
  strcpy(all_planets[4].planet_name, "Saturn");

  cout<<endl;
  cout<<"Part 3b code"<<endl;
  // print to newly create pointer
  for (int i = 0; i < 5; i++) 
  {
    cout << (all_planets + i)->planet_number<<","<<(all_planets + i)->personal.age<<","<<
       (all_planets + i)->planet_name<<","<<(all_planets + i)->personal.origin<<endl;
  }

} // end of main

