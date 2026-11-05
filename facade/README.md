# Facade Pattern — Video Converter

## Overview

This project demonstrates the Facade design pattern through a video conversion system.

The Facade provides a simplified interface to a complex subsystem by coordinating multiple classes behind a single operation.

## Structure

```text
facade/
├── main.cpp
└── README.md
```

## Video Conversion Operations

- Video file loading
- Video decoding
- Video frame processing
- Audio processing
- Video encoding

## Facade Implementation

### main.cpp

Defines several subsystem classes responsible for individual video conversion operations. The `VideoConverter` facade coordinates these classes and exposes a single `convert()` method to the client.

## Key Concepts

- Facade design pattern
- Subsystem coordination
- Interface simplification
- Encapsulation
- Composition
- Separation of responsibilities