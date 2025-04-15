# include <iostream>

class Person {
private:
    bool _genre;
    std::string _nom;
    std::string _prenom;
    bool _ne;
    int _annee;
    bool _situation_matrimoniale;

public:
    Person(bool, std::string, std::string, bool, int, bool);
    ~Person();
    void display();
};