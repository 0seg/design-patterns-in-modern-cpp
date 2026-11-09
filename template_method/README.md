# Template Method — Beverage Preparation

## Overview

**Template Method** is a behavioral design pattern that defines the skeleton of an algorithm in a base class, allowing subclasses to implement or customize specific steps without changing the overall algorithm structure.

## Problem

When multiple classes implement algorithms with similar structures, common operations may be duplicated across different implementations.

This makes the code harder to maintain and increases the effort required to modify shared behavior.

## Solution

The Template Method pattern centralizes the algorithm structure in a base class.

Subclasses implement specific operations while the base class controls the execution order.

## Components

- **AbstractClass:** Defines the template method and declares operations that subclasses must implement.
- **ConcreteClass:** Implements the specific operations required by the algorithm.
- **Hook:** An optional method that subclasses can override to customize the algorithm.

## Implementation

This project implements a beverage preparation system.

The `CaffeineBeverage` class defines the preparation algorithm through `prepareRecipe()`.

Two concrete classes implement the specific preparation steps:

- `Coffee`: Brews coffee grounds and adds sugar and milk.
- `Tea`: Steeps tea leaves and adds lemon.

The template method controls the execution order, while subclasses customize individual steps.

The `customerWantsCondiments()` method demonstrates how hooks allow optional customization.

## Key Concepts

- Behavioral design pattern.
- Inheritance and polymorphism.
- Template methods.
- Abstract classes.
- Hooks.
- Inversion of control.

