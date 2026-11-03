# Classic Builder

A C++20 implementation of the Classic Builder pattern.

## Overview

The Builder pattern separates the construction of a complex object from its final representation.

The Classic Builder allows an object to be configured step by step through separate methods before producing the final product.

## Key Concepts

- **Separation of concerns:** The construction process is separated from the `Computer` class.
- **Encapsulation:** The `Computer` class keeps its data members private.
- **Validation:** The builder validates configuration values before assigning them.
- **Object construction:** `build()` returns the completed `Computer` object by value.

## Example

```cpp
ComputerBuilder builder;

builder.setCPU("Intel Core i9");
builder.setGPU("NVIDIA GeForce RTX 3080");
builder.setRAM(32);
builder.setStorage(1024);

Computer computer = builder.build();
```

