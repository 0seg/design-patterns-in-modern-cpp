# Boost.Flyweight — Text Formatting

## Overview

This project demonstrates the Flyweight design pattern using the **Boost.Flyweight** library.

The pattern reduces memory usage by sharing common data between objects instead of storing duplicate copies.

## Structure

```text
boost-flyweight/
├── main.cpp
└── README.md
```

## Text Properties

- Character and position (Extrinsic State)
- Font, size, and color (Intrinsic State)
- Shared text styles
- Automatic reuse of equivalent styles

## Boost.Flyweight Implementation

### main.cpp

Defines a custom `TextStyle` type and uses `boost::flyweight<TextStyle>` to manage shared instances.

The `TextStyle` type provides:

- `operator==` to compare styles.
- `hash_value()` to generate hash values.

Boost.Flyweight uses these operations to identify equivalent values and reuse their shared representation.

The main function creates multiple characters and demonstrates that characters with identical styles share the same underlying object.

## Key Concepts

- Flyweight design pattern
- Boost.Flyweight
- Intrinsic and Extrinsic State
- Object sharing
- Custom equality and hashing
- Memory optimization

