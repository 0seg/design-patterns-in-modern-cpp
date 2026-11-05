# Shrink-Wrapped Pimpl — Matrix

## Overview

This project demonstrates the Shrink-Wrapped Pimpl idiom through a mathematical Matrix class.

Shrink-Wrapped Pimpl reserves storage inside the public object for its hidden implementation, avoiding a separate dynamic allocation for the implementation object.

## Structure

```text
shrink-wrapped-pimpl/
├── Matrix.h
├── Matrix.cpp
├── main.cpp
└── README.md
```

## Matrix Operations

- Matrix construction with configurable dimensions.
- Element access and modification.
- Matrix dimension retrieval.
- Matrix display.

## Shrink-Wrapped Pimpl Implementation

### Matrix.hpp

Contains the public interface, a forward declaration of the private implementation class, and a fixed-size aligned storage buffer using `std::byte`.

### Matrix.cpp

Defines the hidden `Impl` class, including matrix dimensions and internal storage.

The implementation object is constructed directly inside the reserved storage using placement new.

### main.cpp

Demonstrates the public Matrix interface without exposing implementation details.

## Key Concepts

- Shrink-Wrapped Pimpl idiom
- Raw storage
- `std::byte`
- `alignas`
- Placement new
- `std::launder`
- Object lifetime
- Explicit destruction
- Memory alignment
- Incomplete types