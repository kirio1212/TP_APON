#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "Admin.h"
#include "Professor.h"
#include "Student.h"
#include "StudentManager.h"
#include "FileManager.h"


std::unique_ptr<User> authenticate() {
    std::vector<std::string> lines = FileManager::readLines("users.txt");
    std::string login, password;
    std::cout << "Login : ";
    std::cin >> login;
    std::cout << "Mot de passe : ";
    std::cin >> password;

    for (const auto& line : lines) {
        if (line.empty()) continue;
        size_t pos1 = line.find(';');
        size_t pos2 = line.find(';', pos1+1);
        if (pos1 == std::string::npos || pos2 == std::string::npos) continue;

        std::string fileLogin = line.substr(0, pos1);
        std::string filePassword = line.substr(pos1+1, pos2-pos1-1);
        std::string fileRole = line.substr(pos2+1);

        if (fileLogin == login && filePassword == password) {
            if (fileRole == "ADMIN") {
                 return std::unique_ptr<Admin>(new Admin(login, password));
            } else if (fileRole == "PROF") {
                return std::unique_ptr<Professor>(new Professor(login, password));
            } else if (fileRole == "STUDENT") {
                int studentId = std::stoi(login);
               return std::unique_ptr<Student>(new Student(login, password, studentId));
            }
        }
    }
    return nullptr;
}

int main() {
    StudentManager manager("students.txt", "grades.txt");

    while (true) {
        std::cout << "\n=== GESTION ÉTUDIANTS ===\n";
        auto user = authenticate();
        if (!user) {
            std::cout << "Identifiants incorrects.\n";
            continue;
        }

        bool loggedIn = true;
        while (loggedIn) {
            user->displayMenu();
            int choix;
            std::cin >> choix;

            
            if (user->getRole() == "ADMIN") {
                Admin* admin = dynamic_cast<Admin*>(user.get());
                switch (choix) {
                    case 1: admin->addStudent(manager); break;
                    case 2: admin->removeStudent(manager); break;
                    case 3: admin->modifyStudent(manager); break;
                    case 4: admin->listAllStudents(manager); break;
                    case 0: loggedIn = false; break;
                    default: std::cout << "Choix invalide.\n";
                }
            }
            else if (user->getRole() == "PROF") {
                Professor* prof = dynamic_cast<Professor*>(user.get());
                switch (choix) {
                    case 1: prof->listAllStudents(manager); break;
                    case 2: prof->modifyGrade(manager); break;
                    case 0: loggedIn = false; break;
                    default: std::cout << "Choix invalide.\n";
                }
            }
            else if (user->getRole() == "STUDENT") {
                Student* student = dynamic_cast<Student*>(user.get());
                switch (choix) {
                    case 1: student->viewMyGrades(manager); break;
                    case 0: loggedIn = false; break;
                    default: std::cout << "Choix invalide.\n";
                }
            }
        }
    }
    return 0;
}