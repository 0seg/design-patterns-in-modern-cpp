# Pimpl Idiom — Matrix

## Overview

This project demonstrates the Pimpl (Pointer to Implementation) idiom through a mathematical Matrix class.

Pimpl separates the public interface from the internal implementation, hiding data structures and implementation-specific dependencies from header files.

## Structure

```text
pimpl/
├── Matrix.h
├── Matrix.cpp
├── main.cpp
└── README.md
```

## Matrix Operations

- Matrix construction with configurable dimensions.
- Element access and modification.
- Matrix addition and subtraction.
- Matrix multiplication.
- Matrix transpose.
- Matrix trace.
- Matrix determinant using Gaussian elimination.

## Pimpl Implementation

### Matrix.hpp

Contains the public interface and a forward declaration of the private implementation class.

The implementation is owned through `std::unique_ptr<Impl>`.

### Matrix.cpp

Defines the hidden `Impl` class, including matrix dimensions, internal storage, and mathematical operations.

The matrix data is stored in a `std::vector<double>` using row-major layout.

### main.cpp

Demonstrates the public Matrix interface without exposing implementation details.

## Key Concepts

- Pimpl idiom
- Forward declarations
- Incomplete types
- `std::unique_ptr`
- Encapsulation
- Compilation dependencies
- Row-major matrix storage
- Gaussian elimination
