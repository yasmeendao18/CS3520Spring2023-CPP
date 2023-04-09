#include <vector>
#include "Item.h"

class Menu {
private:
    std::string item_name; 
    std::vector<Item> m_items;
public:
    string get_name();
    // add item to menu
    void add_item(Item item);
    // all items on menu
    std::vector<Item> get_items() const;
};