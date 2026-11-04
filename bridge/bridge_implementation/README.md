# Bridge Pattern

## Overview

The Bridge pattern separates an abstraction from its implementation, allowing both to evolve independently.

It uses composition to connect two separate class hierarchies.

## Structure

- **Abstraction:** Defines the high-level interface (`RemoteControl`).
- **Refined Abstraction:** Extends the abstraction with specialized behavior (`BasicRemote`, `AdvancedRemote`).
- **Implementor:** Defines the interface for concrete implementations (`Device`).
- **Concrete Implementor:** Provides specific implementations (`TV`, `Radio`).

## Implementation

This example separates remote controls from electronic devices.

`RemoteControl` contains a `std::unique_ptr<Device>`, allowing different remote controls to work with different device implementations.

New remote controls and devices can be introduced independently without modifying the existing hierarchies.

## Key Concepts

- Bridge Pattern
- Abstraction and Refined Abstraction
- Implementor and Concrete Implementor
- Composition
- Polymorphism
- Dependency Inversion
- std::unique_ptr
- Independent Class Hierarchies
