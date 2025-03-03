#include <iostream>

int main() {
    int fino1, fino2, fino3, i;

    std::cout << "Fibonacci while :" << std::endl;

    fino1 = 0;
    fino2 = 1;
    fino3 = fino1 + fino2;

    i = 1;

    while (i <= 16) {
        std::cout << i << ' ' << fino3 << std::endl;
        fino1 = fino2;
        fino2 = fino3;
        fino3 = fino1 + fino2;
        i++;
    }
    
    std::cout << std::endl << "Fibonacci do while :" << std::endl;

    fino1 = 0;
    fino2 = 1;
    fino3 = fino1 + fino2;

    i = 1;

    do  {
        std::cout << i << ' ' << fino3 << std::endl;
        fino1 = fino2;
        fino2 = fino3;
        fino3 = fino1 + fino2;
        i++;
    } while (i <= 16);

    std::cout << std::endl << "Fibonacci for :" << std::endl;

    fino1 = 0;
    fino2 = 1;
    fino3 = fino1 + fino2;

    for (i = 1; i <= 16; i++) {
        std::cout << i << ' ' << fino3 << std::endl;
        fino1 = fino2;
        fino2 = fino3;
        fino3 = fino1 + fino2;
    }

    return 0;
}