# Builder Pattern

## Overview

The Builder pattern is a creational design pattern that allows complex objects to be constructed step by step.

It separates the construction process from the final product.

## Problem

Constructors with many parameters can become difficult to read, maintain, and extend, especially when objects contain optional configuration values.

## Implementation

This example uses a `ComputerBuilder` to configure a `Computer` step by step.

The builder provides:

- CPU configuration
- GPU configuration
- RAM configuration
- Storage configuration
- Final object creation through `build()`

It also demonstrates Fluent Builder through method chaining.

## Key Concepts

- **Product:** `Computer`, the final object.
- **Builder:** `ComputerBuilder`, responsible for construction.
- **Method chaining:** Configuration methods return a reference to the builder.
- **build():** Returns the completed product.

## Example

```cpp
Computer computer = ComputerBuilder{}
    .setCPU("Intel Core i9")
    .setGPU("NVIDIA GeForce RTX 3080")
    .setRAM(32)
    .setStorage(1024)
    .build();
```

