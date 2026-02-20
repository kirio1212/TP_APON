#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "User.h"
#include "StudentManager.h"

class Professor : public User {
public:
    Professor(const std::string& login, const std::string& password);
    void displayMenu() const override;

    void listAllStudents(StudentManager& manager) const;
    void modifyGrade(StudentManager& manager) const;
};

#endif