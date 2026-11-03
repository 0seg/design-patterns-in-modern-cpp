# Factory Method

## Overview

Factory Method is a creational design pattern that defines an interface for creating objects while allowing subclasses to decide which concrete class to instantiate.

It separates object creation from the business logic that uses the object.

## Key Concepts

- **Product:** Defines the common interface for created objects.
- **Concrete Products:** Implement the Product interface.
- **Creator:** Declares the factory method and defines operations that use the created product.
- **Concrete Creators:** Override the factory method to instantiate specific products.
- **Polymorphism:** Allows the Creator to work with different concrete products.
- **Smart Pointers:** `std::unique_ptr` manages dynamically created objects safely.

## Example
This example models a logistics system with two transportation methods:

- `Truck`: Delivers cargo by road.
- `Ship`: Delivers cargo by sea.

The `Logistics` class defines the factory method `createTransport()` and implements `planDelivery()`.

`RoadLogistics` creates a `Truck`, while `SeaLogistics` creates a `Ship`.

