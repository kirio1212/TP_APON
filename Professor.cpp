#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& login, const std::string& password)
    : User(login, password, "PROF") {}

void Professor::displayMenu() const {
    std::cout << "\n===== MENU PROFESSEUR =====\n";
    std::cout << "1. Voir tous les étudiants\n";
    std::cout << "2. Modifier une note\n";
    std::cout << "0. Se déconnecter\n";
    std::cout << "Choix : ";
}

void Professor::listAllStudents(StudentManager& manager) const {
    manager.listAllStudents();
}

void Professor::modifyGrade(StudentManager& manager) const {
    int id;
    float note;
    std::cout << "ID de l'étudiant : ";
    std::cin >> id;
    std::cout << "Nouvelle note : ";
    std::cin >> note;
    if (manager.setGrade(id, note))
        std::cout << "Note mise à jour.\n";
    else
        std::cout << "Étudiant non trouvé.\n";
}