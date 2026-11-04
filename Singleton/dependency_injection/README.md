# Singleton in Dependency Injection

## Overview

This example combines the Singleton pattern with Dependency Injection (DI).

The Singleton pattern ensures that only one Logger instance exists, while Dependency Injection allows services to receive that instance externally instead of accessing it directly.

## Structure

- **Logger:** Implements the Singleton pattern and provides a single shared instance.
- **UserService:** Receives a Logger reference through constructor injection.
- **OrderService:** Receives the same Logger reference through constructor injection.
- **Client (main):** Retrieves the Singleton instance and injects it into both services.

## Implementation

The Logger class uses a private constructor and a static local instance to ensure a single instance throughout the application.

UserService and OrderService receive the Logger through their constructors and store it as a reference.

The main function retrieves the Singleton instance and injects it into both services.

Finally, the program verifies that both services reference the same Logger object.

## Key Concepts

- Singleton Pattern
- Dependency Injection
- Constructor Injection
- References
- Encapsulation
- Deleted Copy Operations
- Object Lifetime

