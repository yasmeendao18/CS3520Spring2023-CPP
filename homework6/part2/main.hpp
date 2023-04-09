#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <algorithm>

template <typename T>
class Repository {


public:
    // implement rule of 5

    // default constructor
    Repository() = default;
    // copy constructor
    Repository(const Repository& other);
    // move constructor
    Repository(Repository&& other) ;
    // copy assignment operator
    Repository& operator=(const Repository& other);
    // move assignment operator
    Repository& operator=(Repository&& other);
    // destructor
    ~Repository() = default;

    //template functions
    void add(const T& item, const std::string& info);
    void add(const std::vector<std::pair<T, std::string>>& items);
    int order(const T& item) const;
    void remove(const T& item);
    void remove(const std::vector<T>& items);
    int size() const;

private:
    // vector to contain collection of element pairs
    // template type T and string
    std::vector<std::pair<T, std::string>> m_items; // member variables
};

// copy constructor 
// creates new instance of Repository class
template <typename T>
Repository<T>::Repository(const Repository& other) {
    m_items = other.m_items;
}

// move constructor
// transfers ownership of m_items from one object to other
template <typename T>
Repository<T>::Repository(Repository&& other) {
    m_items = std::move(other.m_items);
}

// copy assignment operator
// assigns different types of objects from one repository to another
template <typename T>
Repository<T>& Repository<T>::operator=(const Repository& other) {
    m_items = other.m_items;
    return *this;
}

// move assignment operator
// transfers ownership of objects between different instances
template <typename T>
Repository<T>& Repository<T>::operator=(Repository&& other){
    m_items = std::move(other.m_items);
    return *this;
}

// add an item
template <typename T>
void Repository<T>::add(const T& item, const std::string& info) {
    auto it = std::find_if(m_items.begin(), m_items.end(), [&](const std::pair<T, std::string>& a) { // use [&] to access every variable by reference
        return a.first == item;
    });
    if (it == m_items.end()) {
        // add item to end of container
        m_items.emplace_back(item, info);
    } else {
        it->second = info;
    }
}

// add several items
template <typename T>
void Repository<T>::add(const std::vector<std::pair<T, std::string> >& items) {
    for (const auto& item : items) {
        add(item.first, item.second);
    }
}

// order the items
template <typename T>
int Repository<T>::order(const T& item) const {
    auto it = std::find_if(m_items.begin(), m_items.end(), [&](const std::pair<T, std::string>& a) { // use [&] to access every variable by reference
        return a.first == item;
    });
    if (it == m_items.end()) {
        return -1;
    } else {
        return static_cast<int>(std::distance(m_items.begin(), it));
    }
}

// remove an item
template <typename T>
void Repository<T>::remove(const T& item) {
    m_items.erase(std::remove_if(m_items.begin(), m_items.end(), [&](const std::pair<T, std::string>& a) {
        return a.first == item;
    }), m_items.end());
}

// remove all occurances of item from items
// several items
template <typename T>
void Repository<T>::remove(const std::vector<T>& items) {
    for (const auto& item : items) {
        remove(item);
    }
}

// return the number of items in repository
template <typename T>
int Repository<T>::size() const {
    return m_items.size();
}

#endif  // REPOSITORY_H
