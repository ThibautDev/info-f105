#include <iostream>

int diff(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int e(int epsilone) {
    int n = 0;
    float sum = 0;
    while (n <= epsilone) {
        sum += 1 / diff(n);
        n++;
    }
    return sum;
}

int main() {
    std::cout << e(40) << std::endl;
    return 0;
}