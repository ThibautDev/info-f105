#include <iostream>

struct Etudiant {
    std::string prenom;
    std::string nom;
    unsigned matricule;
    float notes [6];
};

void creer_sebesta_ptr(Etudiant *e) {
    e->prenom = "hello";
}

int main() {
    Etudiant e = {"Lucas", "Un long nom en de", 609518, {20, 0, 20, 20, 20, 20}};
    
    creer_sebesta_ptr(&e);
    
    std::cout << e.prenom << std::endl;
    return 0;
}