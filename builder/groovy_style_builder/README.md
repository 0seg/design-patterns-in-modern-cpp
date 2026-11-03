# Groovy-Style Builder

A C++20 implementation inspired by the Groovy-Style Builder pattern.

## Overview

The Builder pattern separates the construction of an object from its final representation.

This implementation uses lambdas to provide a declarative configuration interface, allowing different parts of a `Server` object to be configured independently.

## Key Concepts

- **Lambdas:** Pass configuration logic as function arguments.
- **Function pointers:** Accept functions with a specific signature.
- **References:** Modify the original configuration objects without copying them.
- **Method chaining:** Return `*this` to continue configuring the same builder.
- **Encapsulation:** Keep the construction process inside `ServerBuilder`.

## Example

```cpp
Server server = ServerBuilder{}
    .configureNetwork([](NetworkConfig& config) {
        config.host = "localhost";
        config.port = 8080;
    })
    .configureSecurity([](SecurityConfig& config) {
        config.enabled = true;
        config.maxAttempts = 5;
    })
    .build();
```
