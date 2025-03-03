#include <iostream>

int main(int argc , char * argv[]) {
    int a, b, c;
    a = std::atoi(argv[1]);
    b = std::atoi(argv[2]);
    c = std::atoi(argv[3]);

    if (a > b) {
        std::swap(a, b);
    }

    if (b > c) {
        std::swap(b, c);
    }

    if (a > b) {
        std::swap(a, b);
    }

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}
