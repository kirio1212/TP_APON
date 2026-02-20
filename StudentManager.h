#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include <string>


struct StudentInfo {
    int id;
    std::string nom;
    std::string prenom;
    float note; 
};

class StudentManager {
private:
    std::vector<StudentInfo> students;
    std::string studentsFile;
    std::string gradesFile;

    void loadStudents();
    void saveStudents();
    void loadGrades();
    void saveGrades();
    int getNextId();

public:
    StudentManager(const std::string& studentsFile, const std::string& gradesFile);
    void addStudent(const std::string& nom, const std::string& prenom);
    bool removeStudent(int id);
    bool modifyStudent(int id, const std::string& nom, const std::string& prenom);
    void listAllStudents() const;
    bool setGrade(int id, float note);
    void displayStudentGrade(int id) const;
};

#endif