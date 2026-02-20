#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& login, const std::string& password)
    : User(login, password, "ADMIN") {}

void Admin::displayMenu() const {
    std::cout << "\n===== MENU ADMIN =====\n";
    std::cout << "1. Ajouter un étudiant\n";
    std::cout << "2. Supprimer un étudiant\n";
    std::cout << "3. Modifier un étudiant\n";
    std::cout << "4. Voir tous les étudiants\n";
    std::cout << "0. Se déconnecter\n";
    std::cout << "Choix : ";
}

void Admin::addStudent(StudentManager& manager) const {
    std::string nom, prenom;
    std::cout << "Nom : ";
    std::cin >> nom;
    std::cout << "Prénom : ";
    std::cin >> prenom;
    manager.addStudent(nom, prenom);
    std::cout << "Étudiant ajouté avec succès.\n";
}

void Admin::removeStudent(StudentManager& manager) const {
    int id;
    std::cout << "ID de l'étudiant à supprimer : ";
    std::cin >> id;
    if (manager.removeStudent(id))
        std::cout << "Étudiant supprimé.\n";
    else
        std::cout << "Étudiant non trouvé.\n";
}

void Admin::modifyStudent(StudentManager& manager) const {
    int id;
    std::cout << "ID de l'étudiant à modifier : ";
    std::cin >> id;
    std::string nom, prenom;
    std::cout << "Nouveau nom : ";
    std::cin >> nom;
    std::cout << "Nouveau prénom : ";
    std::cin >> prenom;
    if (manager.modifyStudent(id, nom, prenom))
        std::cout << "Étudiant modifié.\n";
    else
        std::cout << "Étudiant non trouvé.\n";
}

void Admin::listAllStudents(StudentManager& manager) const {
    manager.listAllStudents();
}