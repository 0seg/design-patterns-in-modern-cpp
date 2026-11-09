# Observer — News Notification System

## Overview

The **Observer** is a behavioral design pattern that defines a one-to-many dependency between objects.

When the state of one object changes, all its registered observers are automatically notified.

It allows objects to receive updates without being tightly coupled to the object that generates them.

## Problem

When multiple objects need to react to changes in another object, directly managing their communication can create unnecessary dependencies.

For example, a news channel may need to notify multiple users whenever a new article is published.

Without Observer, the channel would need to manage each user individually, making the system harder to extend and maintain.

## Solution

The Observer pattern introduces a Subject that maintains a list of observers.

When the Subject changes its state, it notifies all registered observers through a common interface.

Observers can subscribe or unsubscribe dynamically without modifying the Subject's implementation.

## Components

- **Subject:** Defines the interface for subscribing, unsubscribing, and notifying observers.
- **ConcreteSubject:** Maintains the state and manages the registered observers.
- **Observer:** Defines the interface for receiving updates.
- **ConcreteObserver:** Implements the notification behavior.

## Implementation

This example simulates a news notification system.

- `Observer` defines the interface for receiving notifications.
- `Subject` defines the subscription and notification operations.
- `User` represents a subscriber that receives news updates.
- `NewsChannel` manages subscribers and publishes news.
- `main()` creates users, registers subscriptions, and publishes news.

Users receive notifications whenever the channel publishes new content. They can also unsubscribe to stop receiving future updates.

## Key Concepts

- One-to-Many Dependency
- Event Notifications
- Subscription Management
- Loose Coupling
- Interface Abstraction
- Behavioral Design Pattern