#include <iostream>
#include "_matrix.h"

int main() {
    Matrix<int> m(3, 3, 2);
    Matrix<int> m2(3, 3, 5);

    m2 *= 10;

    m2.add(8, 1, 1);
    m2.show();

    return 0;
}