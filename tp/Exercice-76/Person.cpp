#include "Person.hpp"


Person::Person(bool g, std::string n, std::string p, bool ne, int a, bool s) {
    this->_genre = g;
    this->_nom = n;
    this->_prenom = p;
    this->_ne = ne;
    this->_annee = a;
    this->_situation_matrimoniale = s;
};

Person::~Person(){};

void Person::display() {
    // Example implementation
    std::cout << "Nom: " << _nom << std::endl;
    std::cout << "Prénom: " << _prenom << std::endl;
    std::cout << "Genre: " << (_genre ? "Homme" : "Femme") << std::endl;
    std::cout << (_ne ? "Né" : "Née") << " en " << _annee << std::endl;
    std::cout << "Situation matrimoniale: " << (_situation_matrimoniale ? "Marié(e)" : "Célibataire") << std::endl;
}