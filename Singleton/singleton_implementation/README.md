# Singleton

## Overview

Singleton is a creational design pattern that ensures a class has only one instance and provides a global access point to that instance.

It is useful when exactly one shared object is required throughout the application, such as a logger, configuration manager, or resource manager.

## Structure

- **Private Constructor:** Prevents objects from being created directly outside the class.
- **Static Instance:** Holds the single instance of the class.
- **Static Access Method:** Provides global access to the instance.
- **Deleted Copy Operations:** Prevent copying the instance.

## Implementation

This example implements a `Logger` class using the Singleton pattern.

The `getInstance()` method returns a reference to a local static instance. Since the instance is initialized only once, every call returns the same object.

The copy constructor and copy assignment operator are deleted to prevent creating copies of the Singleton instance.

## Key Concepts

- Private Constructor
- Static Local Variables
- Static Member Functions
- Object Lifetime
- References
- Deleted Copy Operations
- Thread-Safe Initialization (C++11)
