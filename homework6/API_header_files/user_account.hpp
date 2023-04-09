#include <customer.h>
#include <string>

class UserAcc {
private:
    std::string username_;
    std::string password_;

public:
    UserAcc(const string username, const string password);
    // information about customer
    std::string set_username() const;
    std::string set_password() const;
    std::string get_username() const;
    std::string get_password() const;
    // favorite items that user can add to 
    std::vector<std::string> favorites() const;
    void get_favorites(std::vector<std::string> favorites);

};
