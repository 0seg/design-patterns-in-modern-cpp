# Fluent Builder

A C++20 implementation of the Fluent Builder pattern.

## Overview

The Builder pattern separates object construction from its final representation.

The Fluent Builder approach allows objects to be configured through method chaining, providing a readable and expressive construction interface.

## Key Concepts

- **Method chaining:** Builder methods return `UserBuilder&` to allow consecutive calls.
- **References:** `return *this` returns a reference to the current builder.
- **Encapsulation:** The `User` class keeps its data members private.
- **Validation:** The builder validates input before assigning values.
- **Object construction:** `build()` returns the completed `User` object by value.

## Example

```cpp
User user = UserBuilder{}
    .setName("fani")
    .setEmail("fani123@test.com")
    .setAge(25)
    .build();
```

