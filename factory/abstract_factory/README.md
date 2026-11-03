# Abstract Factory

## Overview

Abstract Factory is a creational design pattern that provides an interface for creating families of related objects without specifying their concrete classes.

It allows the client to work with different product families while depending only on abstract interfaces.

## Structure

- **Abstract Products:** Define interfaces for each product category (`Character`, `Weapon`, `Environment`).
- **Concrete Products:** Implement the abstract product interfaces for a specific family.
- **Abstract Factory:** Declares methods for creating each type of product (`GameFactory`).
- **Concrete Factories:** Implement the creation methods for a specific product family (`MedievalFactory`, `FuturisticFactory`, `SciFiFactory`).
- **Client:** Uses the abstract factory interface without depending on concrete implementations.

## Implementation

This example implements a game system with three product families:

- **Medieval:** Medieval characters, weapons, and environments.
- **Futuristic:** Futuristic characters, weapons, and environments.
- **Sci-Fi:** Sci-Fi characters, weapons, and environments.

Each factory creates a complete family of related products.

The `initializeGame()` function receives a `GameFactory` reference and works with any concrete factory through polymorphism.

## Key Concepts

- Encapsulates the creation of related objects.
- Promotes programming to interfaces rather than concrete implementations.
- Uses polymorphism to support different product families.
- Uses `std::unique_ptr` for automatic resource management.
- Allows new product families to be added without modifying the client code.

