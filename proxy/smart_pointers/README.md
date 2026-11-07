# Proxy — Smart Pointers

## Overview

This project demonstrates how C++ smart pointers relate to the Proxy design pattern and resource management.

Smart pointers provide an intermediary interface to objects while managing their lifetime and ownership automatically.

## Structure

```text
smart-pointers/
├── main.cpp
└── README.md
```

## Components

- `Image`: Common interface (Subject).
- `RealImage`: Real object that loads and displays an image.
- `ImageProxy`: Virtual Proxy that delays image creation.
- `ImageCache`: Manages a shared image resource.

## Smart Pointer Implementations

### std::unique_ptr

Used by `ImageProxy` to maintain exclusive ownership of `RealImage`.

The image is created lazily using `std::make_unique` and automatically destroyed when the Proxy is destroyed.

### std::shared_ptr

Used by `ImageCache` to demonstrate shared ownership of a `RealImage` instance.

Multiple pointers can share ownership of the same object.

### std::weak_ptr

Observes a shared object without extending its lifetime.

The `lock()` method attempts to obtain a temporary `shared_ptr` when the object is still alive.

## Key Concepts

- Proxy design pattern
- Virtual Proxy
- Smart pointers
- Exclusive ownership
- Shared ownership
- Non-owning references
- Lazy initialization
- RAII
- Automatic resource management

