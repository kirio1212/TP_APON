#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "StudentManager.h"

class Student : public User {
private:
    int id;
public:
    Student(const std::string& login, const std::string& password, int id);
    void displayMenu() const override;

    void viewMyGrades(StudentManager& manager) const;
    int getId() const;
};

#endif