
#include "Matrix.h"

#include <iostream>

int main() {
    Matrix A(2, 2);

    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "\nDimensions: "
              << A.rows() << " x " << A.cols() << '\n';

    std::cout << "\nElement at (1, 0): "
              << A.get(1, 0) << '\n';

    A.set(1, 0, 10.0);

    std::cout << "\nMatrix A after modification:\n";
    A.print();

    return 0;
}
