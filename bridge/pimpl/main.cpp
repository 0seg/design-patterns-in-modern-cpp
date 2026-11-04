#include "Matrix.h"

#include <iostream>

int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "\nA + B:\n";
    A.add(B).print();

    std::cout << "\nA * B:\n";
    A.multiply(B).print();

    std::cout << "\nTranspose of A:\n";
    A.transpose().print();

    std::cout << "\nTrace of A: "
              << A.trace() << '\n';

    std::cout << "Determinant of A: "
              << A.determinant() << '\n';

    return 0;
}