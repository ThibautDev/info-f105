#include <iostream>

int main() {
  int a, b;

  std::cout << "a: ";
  std::cin >> a;

  std::cout << "b: ";
  std::cin >> b;

  if (b != 0) {
    if (a%b) {
      std::cout << "a/b est non-entier" << std::endl;
    } else {
      std::cout << "a n’est pas un multiple de b" << std::endl; //texte probablement pas bon mais logique ok
    }
  }

  return 0;
}
