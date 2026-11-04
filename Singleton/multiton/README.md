# Multiton

## Overview

Multiton is a creational design pattern that manages a limited set of instances, allowing one instance per unique identifier.

Unlike Singleton, which restricts a class to a single instance, Multiton allows multiple instances while ensuring that each key always refers to the same object.

## Structure

- **Multiton Class:** Controls instance creation and access.
- **Instance Registry:** Stores instances using unique identifiers.
- **Client:** Requests instances by providing a key.

## Implementation

This example implements a `Database` class using the Multiton pattern.

The class maintains a static `std::unordered_map` that associates each database identifier with its corresponding instance.

The `getInstance()` method checks whether an instance already exists for the requested key.

- If the key exists, the existing instance is returned.
- If the key does not exist, a new instance is created and registered.

The constructor is private to prevent direct object creation, while copy operations are deleted to prevent copying existing instances.

Instances are managed using `std::unique_ptr`.

## Key Concepts

- Multiton Pattern
- Static Data Members
- Instance Registry
- `std::unordered_map`
- `std::unique_ptr`
- Object Ownership
- Lazy Initialization
- Deleted Copy Operations
