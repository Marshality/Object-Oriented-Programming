#include <iostream>
#include "_matrix.h"
#include "_iterator.h"

int main() {
    Matrix<int> m(3, 3, 8);
    Matrix<int> m2(m);
    Matrix<int> m3(2, 2);
    Matrix<int> m4(5);

    std::cout << "\nIndex:\n" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << &m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nIterator:\n" << std::endl;

    for (auto it = m.begin(); it < m.end(); it++) {
        std::cout << *it << " ";
        it++;
        std::cout << *it << " ";
        it++;
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    for (auto it = m.begin(); it < m.end(); it++) {
        std::cout << &*it << " ";
        it++;
        std::cout << &*it << " ";
        it++;
        std::cout << &*it << std::endl;
    }

    return 0;
}