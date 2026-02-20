#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string login;
    std::string password;
    std::string role; 

public:
    User(const std::string& login, const std::string& password, const std::string& role);
    virtual ~User() {}


    std::string getLogin() const;
    std::string getPassword() const;
    std::string getRole() const;

    
    bool checkPassword(const std::string& pwd) const;

    virtual void displayMenu() const = 0;
};

#endif