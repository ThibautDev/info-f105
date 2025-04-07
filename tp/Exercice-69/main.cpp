#include <iostream>

struct Etudiant {
    std::string prenom;
    std::string nom;
    unsigned matricule;
    float notes [6];
};

int main() {
    Etudiant e = {"Lucas", "Un long nom en de", 609518, {20, 0, 20, 20, 20, 20}};

    std::cout << e.nom << std::endl;
    return 0;
}