#include <iostream>

int main() {
    char letter;

    std::cin >> letter;

    switch (letter)
    {
    case 'A':
        std::cout << "Ada" << std::endl;
        break;
    
    case 'B':
        std::cout << "Bernard" << std::endl;
        break;

    case 'C':
        std::cout << "Cécile" << std::endl;
        break;
    
    case 'D':
        std::cout << "Daniel" << std::endl;
        break;

    case 'E':
        std::cout << "Etienne" << std::endl;
        break;

    case 'F':
        std::cout << "Florian" << std::endl;
        break;
    
    case 'G':
        std::cout << "Gerard" << std::endl;
        break;

    case 'H':
        std::cout << "Herve" << std::endl;
        break;

    case 'I':
        std::cout << "Isaac" << std::endl;
        break;

    case 'J':
        std::cout << "Jeremy" << std::endl;
        break;

    default:
        break;
    }
}