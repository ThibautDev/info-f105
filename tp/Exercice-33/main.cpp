#include <iostream>

int main() {
    const int size = 42;
    char test[size]; 
    std::cin >> test;

    std::cout << test << std::endl; //Methode 1
    
    for (int i = 0; i < size; i++) std::cout << test[i]; //Methode 2

    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
      if (*(test + 1)) {
        std::cout << *(test + i);
      }
    } //Methode 3

    std::cout << std::endl;
    return 0;
}

