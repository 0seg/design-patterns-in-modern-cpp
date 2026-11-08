# Command Design Pattern

A C++ implementation of the **Command Design Pattern**, demonstrating how requests can be encapsulated as objects instead of being executed through direct method calls.

## Overview

The Command pattern decouples the object that requests an operation from the object that performs it.

Each operation is represented by a command object that implements a common interface. This allows commands to be executed, stored, undone, and combined.

## Implementation

This project includes:

- **Command:** Defines the common `execute()` and `undo()` interface.
- **Concrete Commands:** Implements specific operations such as writing, deleting, and saving.
- **Receiver:** `TextEditor`, which performs the actual operations.
- **Invoker:** `CommandHistory`, which executes commands and stores them.
- **Undo Operations:** Reverts previously executed commands.
- **Composite Command:** Combines multiple commands into a single macro operation.

## Key Concepts

- Encapsulation of requests as objects.
- Separation between request sender and request receiver.
- Runtime command execution.
- Command history and undo operations.
- Composite commands and macro execution.
- Polymorphism and smart pointer ownership.

