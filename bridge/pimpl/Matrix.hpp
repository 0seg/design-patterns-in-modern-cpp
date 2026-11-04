#pragma once

#include <memory>
#include <cstddef>

class Matrix {
private:
    class Impl;
    std::unique_ptr<Impl> impl_;

public:
    Matrix(std::size_t rows, std::size_t cols);
    ~Matrix();

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    void set(std::size_t row, std::size_t col, double value);
    double get(std::size_t row, std::size_t col) const;

    std::size_t rows() const;
    std::size_t cols() const;

    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;

    Matrix transpose() const;

    double trace() const;
    double determinant() const;

    void print() const;
};