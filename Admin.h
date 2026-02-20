#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "StudentManager.h"

class Admin : public User {
public:
    Admin(const std::string& login, const std::string& password);
    void displayMenu() const override;

    void addStudent(StudentManager& manager) const;
    void removeStudent(StudentManager& manager) const;
    void modifyStudent(StudentManager& manager) const;
    void listAllStudents(StudentManager& manager) const;
};

#endif