
#pragma once

#include <cstddef>

class Matrix {
private:
    class Impl;

    alignas(std::max_align_t) std::byte storage_[64];

    Impl* impl();
    const Impl* impl() const;

public:
    Matrix(std::size_t rows, std::size_t cols);
    ~Matrix();

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    Matrix(Matrix&&) = delete;
    Matrix& operator=(Matrix&&) = delete;

    void set(std::size_t row, std::size_t col, double value);
    double get(std::size_t row, std::size_t col) const;

    std::size_t rows() const;
    std::size_t cols() const;

    void print() const;
};
