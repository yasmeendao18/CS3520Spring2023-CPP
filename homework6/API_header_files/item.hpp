#include <string>

class Item {
private:
    std::string item_name;
    double item_price;
public:
    Item(const std::string& name, double price);
    std::string get_name() const;
    // get price of item
    double get_price() const;
};