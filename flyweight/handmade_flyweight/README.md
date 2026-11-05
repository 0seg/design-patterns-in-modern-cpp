# Handmade Flyweight — Forest

## Overview

This project demonstrates a manual implementation of the Flyweight design pattern through a forest simulation.

The pattern reduces memory usage by sharing common data between objects instead of storing duplicate copies.

## Structure

```text
handmade-flyweight/
├── main.cpp
└── README.md
```

## Tree Properties

- Tree type and texture (Intrinsic State)
- Tree position (Extrinsic State)
- Shared tree type instances
- Automatic reuse of existing tree types

## Handmade Flyweight Implementation

### main.cpp

Defines the `TreeType` flyweight, individual `Tree` objects, and a `TreeFactory` that manages shared instances using `std::map`.

The main function creates multiple trees and demonstrates how identical tree types reuse the same object.

## Key Concepts

- Flyweight design pattern
- Intrinsic and Extrinsic State
- Flyweight Factory
- Object sharing
- `std::map`
- Pointers and references
- Memory optimization