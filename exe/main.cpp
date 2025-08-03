#include "libs/matrixlib/matrix.h"
#include <iostream>

using namespace math;

int main() {
    std::cout << "Matrix Library Demo" << std::endl;

    // Create two 3x3 matrices
    Matrix A(3, 3);
    Matrix B(3, 3);

    // Fill matrices with values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A(i, j) = i * 3 + j + 1;
            B(i, j) = 9 - (i * 3 + j);
        }
    }

    // Perform operations
    Matrix sum = A + B;
    Matrix product = A * B;

    std::cout << "Matrix A:\\n" << A << std::endl;
    std::cout << "Matrix B:\\n" << B << std::endl;
    std::cout << "A + B:\\n" << sum << std::endl;
    std::cout << "A * B:\\n" << product << std::endl;

    return 0;
}
