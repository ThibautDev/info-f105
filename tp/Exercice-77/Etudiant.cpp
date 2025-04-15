#include "Etudiant.hpp"

Etudiant::Etudiant(std::string nom, std::string prenom) {
    this->_nom = nom;
    this->_prenom = prenom;
    for(int i = 0; i < 10; i++) {
        this->_tabnote[i] = 0;
    };
};

void Etudiant::affichage() {
    std::cout << "Nom: " << _nom << std::endl;
    std::cout << "Prénom: " << _prenom << std::endl;
}