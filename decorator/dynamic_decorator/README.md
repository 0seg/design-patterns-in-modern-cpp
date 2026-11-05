# Dynamic Decorator — Notifications

## Overview

This project demonstrates the Dynamic Decorator design pattern through a notification system.

Decorators dynamically add responsibilities to an object without modifying its original class. Multiple decorators can be combined using a common interface.

## Structure

```text
dynamic-decorator/
├── main.cpp
└── README.md
```

## Notification Operations

- Email notification
- SMS notification
- Notification logging
- Dynamic decorator composition

## Dynamic Decorator Implementation

### main.cpp

Defines the component interface, concrete component, base decorator, and concrete decorators. The main function combines decorators at runtime using `std::unique_ptr`.

## Key Concepts

- Dynamic Decorator pattern
- Runtime composition
- Polymorphism
- Inheritance
- Delegation
- Composition
- `std::unique_ptr`
- Dynamic dispatch