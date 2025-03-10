#include <iostream>

int main() {
    int n = 4;
    int* p = new int[n + 1];
    for (int i = 0; i <= n; ++i) p[i] = i;
    std::cout << p[4] << std::endl;
    delete [] p; p = nullptr;
    std::cout << p[4] << std::endl;
    return 0;
}
