#include <iostream>
#include "_matrix.h"

int main() {
    Matrix<int> m(3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m.add(1, i, j);
        }
    }

    Matrix<int> m1(2, 2);

    Matrix<int> m2(3, 3);

    try {
        m2 = m + m1;
    } catch (int i) {
        return i;
    }

//    Matrix<int> m3(std::move(m));
//
//    try {
//        std::cout << m3(2, 0) << std::endl;
//    } catch (std::exception &e) {
//        std::cout << ": " << e.what() << std::endl;
//    }

    return 0;
}