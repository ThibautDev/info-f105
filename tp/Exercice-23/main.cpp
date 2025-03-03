#include <iostream>

int f1(int param) {
  static int x1 = param;
  x1--;
  return x1;
}

int f2() {
  int x1 = 0;
  x1++;
  return x1;
}

int main() {
  f1(3);
  int x2 = f1(f2());
  std::cout << x2 << std::endl;
  return 0;
}
