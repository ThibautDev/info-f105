# include <iostream>

class Etudiant {
private:
    std::string _nom;
    std::string _prenom;
    float _tabnote[10];

public:
    Etudiant(std::string nom, std::string prenom);
    ~Etudiant();

    void affichage();
    float moyenne(); // a faire
    bool exae_quo(const Etudiant& E); // a faire
};