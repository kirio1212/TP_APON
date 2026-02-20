#include "Student.h"
#include <iostream>

Student::Student(const std::string& login, const std::string& password, int id)
    : User(login, password, "STUDENT"), id(id) {}

void Student::displayMenu() const {
    std::cout << "\n===== MENU ÉTUDIANT =====\n";
    std::cout << "1. Voir mes notes\n";
    std::cout << "0. Se déconnecter\n";
    std::cout << "Choix : ";
}

void Student::viewMyGrades(StudentManager& manager) const {
    manager.displayStudentGrade(id);
}

int Student::getId() const {
    return id;
}