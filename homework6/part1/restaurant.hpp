#ifndef RESTAURANT_H
#ifndef RESTAURANT_H

#include <string>
#include <vector>
#include "menu.h"


class Restaurant{
private:
 // _ allows for same names to be used 
    std::string name_;
    std::string address_;
    std::string phone_;
public:
  Restaurant(const string& name, const string& address, const string& phone);
  // get restaurant information
  std::string get_name() const;
  std::string get_address() const;
  std::string get_phone() const;
  // get the menu of restaurants
  vector<string> get_menu() const;
};

#endif