#include <string>
#include <vector>
#include "Customer.h"
#include "Menu.h"
#include "item.h"
#include "Delivery.h"
#include "Payment.h"

class Order {
private:
    int id_;
    bool status; 
    std::string acessType; 
    std::string customer_name_;
    std::vector<std::string> items_;

public:
    Order(Customer customer, Menu menu, Delivery delivery, Payment payment);
    // access_type is delivery options
    string get_access_type(); 
    // vector of items 
    std::vector<std::string> get_items() const;
    int get_id() const;
    // total order price amount
    double get_totalPrice() const;
    // status of order, i.e. confirmed, in process
    bool get_status(); 
    // add new item to order
    void add_Item(); 
};





