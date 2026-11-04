# Monostate

## Overview

Monostate is a design pattern that allows multiple instances of a class to share the same internal state.

Unlike Singleton, which restricts a class to a single instance, Monostate allows multiple objects while keeping their data shared through static members.

## Structure

- **Monostate Class:** Defines the shared state using static data members.
- **Instances:** Multiple objects that access and modify the same shared state.
- **Client:** Creates instances and interacts with the shared data.

## Implementation

This example implements a `GameSettings` class using the Monostate pattern.

The class contains two static data members:

- `volume_`: Stores the shared audio volume.
- `fullscreen_`: Stores the shared fullscreen setting.

Multiple `GameSettings` objects can be created, but modifying the state through one object affects all other instances.

The example also compares object addresses to demonstrate that the instances are different objects despite sharing the same state.

## Key Concepts

- Monostate Pattern
- Static Data Members
- Shared State
- Object Identity
- Encapsulation
- `inline static` (C++17)

