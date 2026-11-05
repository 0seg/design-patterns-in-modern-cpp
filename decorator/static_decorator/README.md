# Static Decorator — Notifications

## Overview

This project demonstrates the Static Decorator design pattern through a notification system.

Decorators add responsibilities to an object using templates and composition. Unlike Dynamic Decorator, the structure is determined at compile time.

## Structure

```text
static-decorator/
├── main.cpp
└── README.md
```

## Notification Operations

- Email notification
- Notification logging
- SMS notification
- Static decorator composition

## Static Decorator Implementation

### main.cpp

Defines the concrete component and two template-based decorators. The main function combines them using nested composition.

## Key Concepts

- Static Decorator pattern
- Templates
- Compile-time composition
- Class templates
- Composition
- `std::move`
- Class Template Argument Deduction (CTAD)