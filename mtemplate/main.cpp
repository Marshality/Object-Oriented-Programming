#include <iostream>
#include "_matrix.h"
#include "_iterator.h"

int main() {
    Matrix<int> m = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    for (auto it = m.begin(); it < m.end(); it++) {
        std::cout << *it << " ";
    }

    return 0;
}