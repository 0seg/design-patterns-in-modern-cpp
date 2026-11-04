# Prototype Factory

## Overview

Prototype Factory is a creational design pattern that combines a prototype registry with the Prototype pattern.

It allows objects to be created by cloning previously registered instances instead of constructing them from scratch.

It is useful when different object configurations need to be reused and created dynamically.

## Structure

- **Prototype:** Defines an interface for cloning objects.
- **Concrete Prototypes:** Implement the cloning operation.
- **Prototype Factory:** Stores and manages registered prototypes and creates new instances by cloning them.
- **Client:** Requests objects from the factory using a key.

## Implementation

This example implements a character creation system with two concrete prototypes:

- Warrior
- Mage

The `CharacterFactory` stores prototypes in an `std::unordered_map`, using strings as keys.

It provides three main operations:

- `registerPrototype()`: Registers a prototype in the factory.
- `createCharacter()`: Finds a prototype and returns an independent clone.
- `removePrototype()`: Removes a registered prototype.

Cloning is performed through the virtual `clone()` method, which returns a `std::unique_ptr<Character>`.

## Key Concepts

- Prototype Registry
- Polymorphism
- Virtual Cloning
- `std::unique_ptr`
- `std::unordered_map`
- `std::move`
- Object Ownership

