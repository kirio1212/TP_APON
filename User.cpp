#include "User.h"
#include <iostream>

User::User(const std::string& login, const std::string& password, const std::string& role)
    : login(login), password(password), role(role) {}

std::string User::getLogin() const {
    return login;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getRole() const {
    return role;
}

bool User::checkPassword(const std::string& pwd) const {
    return password == pwd;
}