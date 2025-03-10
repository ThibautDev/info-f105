#include <iostream>

int main() {
    const int size_table = 20;

    int tab[size_table] = {};
    tab[1] = 1;

    for (int i = 2; i < size_table; i++) {
        tab[i] = tab[i - 1] + tab[i - 2];
    }

    for (int i = 0; i < size_table; i++) {
        std::cout << tab[i] << std::endl;
    }

    return 0;
}
