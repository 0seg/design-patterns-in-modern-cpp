# Shrink-Wrapped Pimpl

A C++ implementation of the Shrink-Wrapped Pimpl idiom using a mathematical `Matrix` class.

## Overview

Shrink-Wrapped Pimpl is a variation of the traditional Pimpl idiom.

Instead of dynamically allocating the implementation through a pointer, it reserves a fixed-size block of storage inside the public object.

The hidden implementation is constructed directly inside this storage using placement new.

## Project Structure

```text
shrink-wrapped-pimpl/
├── Matrix.h
├── Matrix.cpp
├── main.cpp
└── README.md
```

## Key Concepts

### 1. Raw Storage

```cpp
alignas(std::max_align_t) std::byte storage_[64];
```

Reserves 64 bytes inside the `Matrix` object.

The storage is not itself an `Impl` object. It is memory reserved for constructing one.

### 2. Alignment

`alignas` ensures that the storage has sufficient alignment for the implementation type.

Compile-time assertions verify that `Impl` fits within the reserved storage and does not require greater alignment.

### 3. Placement New

```cpp
new (static_cast<void*>(storage_)) Impl(rows, cols);
```

Constructs the implementation inside existing memory instead of allocating a separate block for `Impl`.

### 4. Object Lifetime

The implementation is explicitly destroyed:

```cpp
impl()->~Impl();
```

This is necessary because placement new does not automatically manage the lifetime of the object stored in the reserved memory.

### 5. std::launder

`std::launder` obtains a usable pointer to the object constructed inside the raw storage.

## Important Details

- The implementation remains hidden from users of the public header.
- No separate dynamic allocation is required for the `Impl` object.
- The internal `std::vector` still dynamically allocates memory for matrix elements.
- Copy and move operations are disabled in this example.
- The fixed storage size limits the size of the implementation.

## Traditional Pimpl vs Shrink-Wrapped Pimpl

| Traditional Pimpl | Shrink-Wrapped Pimpl |
|---|---|
| Uses a pointer to `Impl` | Uses internal reserved storage |
| Dynamically allocates `Impl` | Constructs `Impl` in existing memory |
| Smaller public object | Larger public object |
| More flexible implementation size | Fixed storage capacity |

## Build

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Matrix.cpp main.cpp -o matrix
```

Run:

```bash
./matrix
```

## Main Takeaway

Shrink-Wrapped Pimpl demonstrates how C++ allows objects to be constructed and destroyed inside preallocated storage.

It combines implementation hiding with low-level memory management concepts such as alignment, placement new, raw storage, and object lifetime.