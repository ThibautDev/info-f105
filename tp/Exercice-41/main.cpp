#include <iostream>

void swap_pointer(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void swap_reference(int &x, int &y) {
  int &temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 1;
  int b = 2;

  std::cout << a << b << std::endl;

  swap_pointer(&a, &b);

  std::cout << a << b << std::endl;

  swap_pointer(&a, &b);

  std::cout << a << b << std::endl;
}