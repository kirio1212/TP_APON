#include "StudentManager.h"
#include "FileManager.h"
#include <iostream>
#include <sstream>
#include <algorithm>

StudentManager::StudentManager(const std::string& studentsFile, const std::string& gradesFile)
    : studentsFile(studentsFile), gradesFile(gradesFile) {
    loadStudents();
    loadGrades();
}

void StudentManager::loadStudents() {
    students.clear();
    std::vector<std::string> lines = FileManager::readLines(studentsFile);
    for (const auto& line : lines) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string token;
        StudentInfo s;
        std::getline(ss, token, ';');
        s.id = std::stoi(token);
        std::getline(ss, s.nom, ';');
        std::getline(ss, s.prenom, ';');
        students.push_back(s);
    }
}

void StudentManager::saveStudents() {
    std::vector<std::string> lines;
    for (const auto& s : students) {
        lines.push_back(std::to_string(s.id) + ";" + s.nom + ";" + s.prenom);
    }
    FileManager::writeLines(studentsFile, lines);
}

void StudentManager::loadGrades() {

    for (auto& s : students) {
        s.note = 0.0f;
    }
    std::vector<std::string> lines = FileManager::readLines(gradesFile);
    for (const auto& line : lines) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string token;
        int id;
        float note;
        std::getline(ss, token, ';');
        id = std::stoi(token);
        std::getline(ss, token, ';');
        note = std::stof(token);
    
        auto it = std::find_if(students.begin(), students.end(), [id](const StudentInfo& s) {
            return s.id == id;
        });
        if (it != students.end()) {
            it->note = note;
        }
    }
}

void StudentManager::saveGrades() {
    std::vector<std::string> lines;
    for (const auto& s : students) {
        lines.push_back(std::to_string(s.id) + ";" + std::to_string(s.note));
    }
    FileManager::writeLines(gradesFile, lines);
}

int StudentManager::getNextId() {
    int maxId = 0;
    for (const auto& s : students) {
        if (s.id > maxId) maxId = s.id;
    }
    return maxId + 1;
}

void StudentManager::addStudent(const std::string& nom, const std::string& prenom) {
    StudentInfo s;
    s.id = getNextId();
    s.nom = nom;
    s.prenom = prenom;
    s.note = 0.0f;
    students.push_back(s);
    saveStudents();
    saveGrades(); // Pour inclure la note par défaut
}

bool StudentManager::removeStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(), [id](const StudentInfo& s) {
        return s.id == id;
    });
    if (it != students.end()) {
        students.erase(it);
        saveStudents();
        saveGrades();
        return true;
    }
    return false;
}

bool StudentManager::modifyStudent(int id, const std::string& nom, const std::string& prenom) {
    auto it = std::find_if(students.begin(), students.end(), [id](const StudentInfo& s) {
        return s.id == id;
    });
    if (it != students.end()) {
        it->nom = nom;
        it->prenom = prenom;
        saveStudents();
        return true;
    }
    return false;
}

void StudentManager::listAllStudents() const {
    std::cout << "\nListe des étudiants :\n";
    for (const auto& s : students) {
        std::cout << "ID: " << s.id << " | " << s.nom << " " << s.prenom << " | Note: " << s.note << "\n";
    }
}

bool StudentManager::setGrade(int id, float note) {
    auto it = std::find_if(students.begin(), students.end(), [id](const StudentInfo& s) {
        return s.id == id;
    });
    if (it != students.end()) {
        it->note = note;
        saveGrades();
        return true;
    }
    return false;
}

void StudentManager::displayStudentGrade(int id) const {
    auto it = std::find_if(students.begin(), students.end(), [id](const StudentInfo& s) {
        return s.id == id;
    });
    if (it != students.end()) {
        std::cout << "Votre note : " << it->note << "\n";
    } else {
        std::cout << "Étudiant non trouvé.\n";
    }
}