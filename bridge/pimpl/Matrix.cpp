#include "Matrix.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

// Hidden implementation
class Matrix::Impl {
public:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;

    Impl(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data_(rows * cols, 0.0) {}

    double& at(std::size_t row, std::size_t col) {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }

        return data_[row * cols_ + col];
    }

    double at(std::size_t row, std::size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }

        return data_[row * cols_ + col];
    }
};

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : impl_(std::make_unique<Impl>(rows, cols)) {}

Matrix::~Matrix() = default;

// Element access
void Matrix::set(std::size_t row, std::size_t col, double value) {
    impl_->at(row, col) = value;
}

double Matrix::get(std::size_t row, std::size_t col) const {
    return impl_->at(row, col);
}

// Dimensions
std::size_t Matrix::rows() const {
    return impl_->rows_;
}

std::size_t Matrix::cols() const {
    return impl_->cols_;
}

// Addition
Matrix Matrix::add(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix result(rows(), cols());

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result.set(i, j, get(i, j) + other.get(i, j));
        }
    }

    return result;
}

// Subtraction
Matrix Matrix::subtract(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix result(rows(), cols());

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result.set(i, j, get(i, j) - other.get(i, j));
        }
    }

    return result;
}

// Multiplication
Matrix Matrix::multiply(const Matrix& other) const {
    if (cols() != other.rows()) {
        throw std::invalid_argument("Invalid dimensions for multiplication");
    }

    Matrix result(rows(), other.cols());

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < other.cols(); ++j) {
            double sum = 0.0;

            for (std::size_t k = 0; k < cols(); ++k) {
                sum += get(i, k) * other.get(k, j);
            }

            result.set(i, j, sum);
        }
    }

    return result;
}

// Transpose
Matrix Matrix::transpose() const {
    Matrix result(cols(), rows());

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result.set(j, i, get(i, j));
        }
    }

    return result;
}

// Trace
double Matrix::trace() const {
    if (rows() != cols()) {
        throw std::invalid_argument("Trace requires a square matrix");
    }

    double sum = 0.0;

    for (std::size_t i = 0; i < rows(); ++i) {
        sum += get(i, i);
    }

    return sum;
}

// Determinant using Gaussian elimination
double Matrix::determinant() const {
    if (rows() != cols()) {
        throw std::invalid_argument("Determinant requires a square matrix");
    }

    const std::size_t n = rows();

    std::vector<double> temp = impl_->data_;
    double det = 1.0;

    for (std::size_t i = 0; i < n; ++i) {
        std::size_t pivot = i;

        for (std::size_t j = i + 1; j < n; ++j) {
            if (std::abs(temp[j * n + i]) >
                std::abs(temp[pivot * n + i])) {
                pivot = j;
            }
        }

        if (std::abs(temp[pivot * n + i]) < 1e-12) {
            return 0.0;
        }

        if (pivot != i) {
            for (std::size_t k = 0; k < n; ++k) {
                std::swap(temp[i * n + k], temp[pivot * n + k]);
            }

            det *= -1.0;
        }

        const double diagonal = temp[i * n + i];
        det *= diagonal;

        for (std::size_t j = i + 1; j < n; ++j) {
            const double factor = temp[j * n + i] / diagonal;

            for (std::size_t k = i + 1; k < n; ++k) {
                temp[j * n + k] -= factor * temp[i * n + k];
            }
        }
    }

    return det;
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