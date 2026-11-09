# State — Vending Machine

## Overview

**State** is a behavioral design pattern that allows an object to change its behavior when its internal state changes.

Instead of implementing multiple conditional statements to handle different states, each state encapsulates its own behavior.

## Problem

An object may behave differently depending on its current state.

Implementing all these behaviors inside a single class can lead to complex conditional logic (`if`, `else`, and `switch` statements).

As the number of states increases, maintaining and extending the code becomes more difficult.

## Solution

The State pattern moves state-specific behavior into separate classes.

The main object, known as the **Context**, maintains a reference to its current state and delegates operations to it.

When the state changes, the Context replaces its current state object.

## Components

- **State:** Abstract interface that defines the operations available in each state.
- **ConcreteState:** Implements behavior associated with a specific state.
- **Context:** Maintains the current state and delegates operations to it.

## Implementation

This project implements a vending machine with four states:

- `NoMoneyState`: Waits for the user to insert money.
- `HasMoneyState`: Allows the user to select a product.
- `ProductSelectedState`: Handles the product delivery request.
- `DispensingState`: Dispenses the product and returns the machine to its initial state.

The `VendingMachine` class acts as the Context, while `std::unique_ptr` manages the lifetime of the current state.

## Key Concepts

- Behavioral design pattern.
- State-specific behavior.
- Runtime polymorphism.
- Composition and delegation.
- State transitions.
- Smart pointers (`std::unique_ptr`).

