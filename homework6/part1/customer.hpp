#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <item>
#include <string>

class Customer {
private:
    std::string name_;
    std::string address_;
    std::string phone_number_;

public:
    Customer(const string& name, const string& address, const string& phone_number);
    // information about customer
    std::string set_name() const; 
    std::string set_address() const;
    std::string set_phone_number() const; 
    std::string get_name() const;
    std::string get_address() const;
    std::string get_phone_number() const;
    // place order of items
    void place_order(); 
};

#endif

