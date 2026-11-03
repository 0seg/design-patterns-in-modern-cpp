# Inner Factory

## Overview

Inner Factory is a creational technique where a nested class is responsible for creating instances of its enclosing class.

It keeps object creation logic inside the class related to the object being constructed.

## Key Concepts

- **Nested Class:** A class declared inside another class.
- **Encapsulation:** Keeps construction logic within the related type.
- **Private Constructor:** Controls how objects can be created.
- **Static Factory Method:** Allows object creation without instantiating the Factory.
- **Validation:** Checks input data before creating an object.

## Implementation

This example uses a `Person` class with a nested `Factory` class.

The constructor of `Person` is private, so objects cannot be created directly from outside the class.

`Person::Factory::create()` validates the input and returns a fully constructed `Person` object.

