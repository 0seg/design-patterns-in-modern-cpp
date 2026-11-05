
#include "Matrix.h"

#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>
#include <vector>

namespace {

std::size_t checked_element_count(std::size_t rows, std::size_t cols) {
    if (rows != 0 &&
        cols > std::numeric_limits<std::size_t>::max() / rows) {
        throw std::length_error("Matrix dimensions are too large");
    }

    return rows * cols;
}

}

// Hidden implementation
class Matrix::Impl {
public:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;

    Impl(std::size_t rows, std::size_t cols)
        : rows_(rows),
          cols_(cols),
          data_(checked_element_count(rows, cols), 0.0) {}

    void set(std::size_t row, std::size_t col, double value) {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }

        data_[row * cols_ + col] = value;
    }

    double get(std::size_t row, std::size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }

        return data_[row * cols_ + col];
    }
};

// Construct Impl inside Matrix's storage
Matrix::Matrix(std::size_t rows, std::size_t cols) {
    static_assert(
        sizeof(Impl) <= sizeof(storage_),
        "Impl is too large for Matrix storage"
    );

    static_assert(
        alignof(Impl) <= alignof(std::max_align_t),
        "Impl requires greater alignment"
    );

    new (static_cast<void*>(storage_)) Impl(rows, cols);
}

// Destroy the object constructed inside storage
Matrix::~Matrix() {
    impl()->~Impl();
}

// Recover the pointer to the hidden implementation
Matrix::Impl* Matrix::impl() {
    return std::launder(
        reinterpret_cast<Impl*>(storage_)
    );
}

const Matrix::Impl* Matrix::impl() const {
    return std::launder(
        reinterpret_cast<const Impl*>(storage_)
    );
}

// Element access
void Matrix::set(std::size_t row, std::size_t col, double value) {
    impl()->set(row, col, value);
}

double Matrix::get(std::size_t row, std::size_t col) const {
    return impl()->get(row, col);
}

// Dimensions
std::size_t Matrix::rows() const {
    return impl()->rows_;
}

std::size_t Matrix::cols() const {
    return impl()->cols_;
}

// Display
void Matrix::print() const {
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            std::cout << get(i, j) << '\t';
        }

        std::cout << '\n';
    }
}
