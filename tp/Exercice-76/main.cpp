#include <iostream>
#include "Person.hpp"

int main() {
    Person p = Person(true, "Props", "Thibaut", true, 2006, false);
    p.display();
    return 0;
}