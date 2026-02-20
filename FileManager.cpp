#include "FileManager.h"
#include <fstream>
#include <iostream>

std::vector<std::string> FileManager::readLines(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (!file.is_open()) {

        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

void FileManager::writeLines(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'écrire dans " << filename << "\n";
        return;
    }
    for (const auto& line : lines) {
        file << line << "\n";
    }
    file.close();
}