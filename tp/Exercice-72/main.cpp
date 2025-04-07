#include <iostream>


struct Personne {
    std::string prenom;
    std::string nom;
};

struct Assistant;

struct Professeur {
    Personne personne;
    Assistant* assistant;
};

struct Assistant {
    Personne personne;
    Professeur* superviseur;
};

int main() {
    return 0;
}