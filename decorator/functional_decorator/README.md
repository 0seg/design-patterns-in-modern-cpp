# Functional Decorator — Notifications

## Overview

This project demonstrates the Functional Decorator design pattern through a notification system.

Decorators use functions and lambdas to add responsibilities to an existing operation without modifying its original implementation.

## Structure

```text
functional-decorator/
├── main.cpp
└── README.md
```

## Notification Operations

- Email notification
- Notification logging
- SMS notification
- Message encryption
- Functional decorator composition

## Functional Decorator Implementation

### main.cpp

Defines a notification operation using `std::function` and several functional decorators. Each decorator receives an operation and returns a new operation with additional behavior.

## Key Concepts

- Functional Decorator pattern
- Lambda expressions
- `std::function`
- Function composition
- Higher-order functions
- Runtime composition