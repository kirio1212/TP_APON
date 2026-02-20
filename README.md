Description

Application console C++ pour gérer des étudiants avec différents rôles (ADMIN, PROF, STUDENT). Les données sont stockées dans des fichiers texte.

git clone https://github.com/kirio1212/TP_APON.git cd TP_APON


g++ -std=c++11 -o gestion_etudiants main.cpp User.cpp Admin.cpp Professor.cpp Student.cpp StudentManager.cpp FileManager.cpp

./gestion_etudiants

Fichiers de données

users.txt (login ;  mot de passe ; role)

           admin    apon      ADMIN 
           prof     apon      PROF 
           1        apon      STUDENT 
           2        yanis     STUDENT 
           3        enzo      STUDENT
