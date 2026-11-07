# Proxy — Property Proxy

## Overview

This project demonstrates the Property Proxy technique in C++ using operator overloading.

A Property Proxy acts as an intermediary between the client and an object's value, allowing operations such as reading and writing to be intercepted.

## Structure

```text
property-proxy/
├── main.cpp
└── README.md
```

## Components

- `Property<T>`: Generic Property Proxy that controls access to a value.
- `Validator`: Function used to validate new values.
- `ChangeCallback`: Function executed when the property changes.
- `Player`: Client class that exposes a property through the Proxy.

## Implementation

### Property<T>

The generic Property class provides:

- `operator T()`: Converts the Proxy into its underlying value for reading.
- `operator=`: Intercepts assignments.
- Validation before modifying the stored value.
- Change notifications through a callback.

### Example

The `Player` class contains a health property restricted to values between 0 and 100.

Invalid assignments are rejected, while valid changes trigger a notification.

## Key Concepts

- Proxy design pattern
- Property Proxy
- Operator overloading
- Templates
- `std::function`
- Lambda expressions
- Value validation
- Change notifications
