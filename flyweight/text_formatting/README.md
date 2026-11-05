# Flyweight — Text Formatting

## Overview

This project demonstrates the Flyweight design pattern through a simple text formatting system.

The pattern reduces memory usage by sharing common formatting data between characters instead of storing duplicate copies.

## Structure

```text
text-formatting/
├── main.cpp
└── README.md
```

## Components

- `TextStyle`: Shared formatting data (Intrinsic State).
- `Character`: Individual character, position, and style reference (Extrinsic State).
- `TextStyleFactory`: Creates and reuses shared styles.
- `Document`: Stores and displays document characters.

## Implementation

The document contains multiple characters that can share the same text style.

The `TextStyleFactory` uses `std::map` to store unique styles and return existing instances when an equivalent style is requested.

The main function creates a document with different formatting styles and displays the number of unique styles.

## Key Concepts

- Flyweight design pattern
- Intrinsic and Extrinsic State
- Flyweight Factory
- Object sharing
- `std::map`
- Memory optimization

