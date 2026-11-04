# Prototype

## Overview

Prototype is a creational design pattern that allows new objects to be created by copying existing instances instead of constructing them from scratch.

It is useful when object initialization is complex or when predefined configurations need to be reused.

## Structure

- **Prototype:** Defines an interface for cloning objects.
- **Concrete Prototypes:** Implement the cloning operation.
- **Client:** Creates new objects by requesting clones from existing instances.

## Implementation

This example implements a character system with two concrete prototypes:

- `Warrior`
- `Mage`

Both inherit from the abstract `Character` class and implement the `clone()` method.

The cloning operation uses `std::make_unique` and the copy constructor to create a new instance with the same initial state.

The cloned characters can then be modified independently of their original instances.

## Key Concepts

- **Polymorphism:** Allows different character types to be cloned through a common interface.
- **clone():** Defines how an object creates a copy of itself.
- **Copy Constructor:** Copies the state of an existing object into a new instance.
- **std::unique_ptr:** Provides automatic memory management and exclusive ownership.
- **const Correctness:** The cloning operation does not modify the original object.

