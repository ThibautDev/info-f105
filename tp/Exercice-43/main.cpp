#include <iostream>

int sq(int);

int sq(int n) {
    return n*n;
}

int main() {
    int sqInput;

    std::cin >> sqInput;
    std::cout << sq(sqInput) << std::endl;

    return 0;
}