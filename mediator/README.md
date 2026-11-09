# Mediator — Chat Communication

## Overview

The **Mediator** is a behavioral design pattern that centralizes communication between different objects.

Instead of allowing objects to communicate directly with each other, they communicate through a mediator that coordinates their interactions.

## Problem

When multiple objects need to communicate, they may become tightly coupled.

For example, in a chat application, users need to send messages to other users.

If every user needs to know about every other user, the system becomes harder to maintain and extend.

## Solution

The Mediator acts as a central communication point between objects.

Each object communicates with the mediator, which handles the interaction with the other participants.

This reduces direct dependencies between objects.

## Components

- **Mediator:** Defines the interface for communication.
- **ConcreteMediator:** Implements the communication logic and coordinates the participants.
- **Colleague:** Represents objects that communicate through the mediator.
- **Client:** Creates and configures the mediator and its participants.

## Implementation

This example simulates a chat application where users communicate through a central chat room.

- `ChatMediator` defines the communication interface.
- `ChatRoom` implements the mediator and distributes messages.
- `User` represents a participant in the chat.
- `main()` creates the chat room, registers users, and sends messages.

Users do not communicate directly with each other. All messages are handled by the `ChatRoom`.

## Key Concepts

- Communication Centralization
- Reduced Coupling
- Object Coordination
- Behavioral Design Pattern
- Interface Abstraction
- Separation of Responsibilities