#ifndef DELIVERY_H
#define DELIVERY_H

#include <restaurant.h>
#include <customer.h>
#include <string>

class Delivery {
private:
  std::string address;
  bool status; 
public:
  Delivery();
  Delivery(std::string address, bool status);
  // address from customer
  std::string getAddress();
  void setAddress(std::string address);
  // get order from restaurant
  vector<string> get_order() const; 
  // status of delivery i.e delivered, on the way
  bool get_status();
};

#endif