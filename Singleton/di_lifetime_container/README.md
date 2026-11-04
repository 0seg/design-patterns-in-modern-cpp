# Singleton Lifetime in DI Container

## Overview

Singleton Lifetime is a Dependency Injection concept in which a container creates and manages a single instance of a service.

The same instance is reused whenever it is requested during the lifetime of the container.

## Structure

- **DIContainer:** Creates, stores, and manages the Logger instance.
- **Logger:** Provides logging functionality and tracks its construction and destruction.
- **UserService:** Receives the Logger through constructor injection.
- **OrderService:** Receives the same Logger instance through constructor injection.

## Implementation

This example implements a simple Dependency Injection Container that manages a Logger using `std::unique_ptr`.

The `getLogger()` method lazily creates the Logger when it is first requested. Subsequent requests return a reference to the existing instance.

Both services receive the Logger through constructor injection and use the same object.

When the container is destroyed, its `std::unique_ptr` automatically destroys the Logger.

## Key Concepts

- Dependency Injection Container
- Singleton Lifetime
- Constructor Injection
- Object Ownership
- Object Lifetime
- Lazy Initialization
- RAII
- `std::unique_ptr`

