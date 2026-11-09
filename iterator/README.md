# Iterator — Generic Iterator

## Overview

The **Iterator** is a behavioral design pattern that provides a way to access elements of a collection sequentially without exposing its internal representation.

It separates the traversal logic from the collection itself.

## Problem

When working with collections, clients need a way to access their elements.

Without an iterator, the client may need to know how the collection stores its elements and how to traverse them.

This creates unnecessary dependencies between the client and the collection.

## Solution

The Iterator provides a separate object responsible for traversing the collection.

The client uses the iterator to access elements one at a time, without directly managing the traversal process.

## Components

- **Iterator:** Defines the interface for accessing elements sequentially.
- **Concrete Iterator:** Implements the traversal logic and keeps track of the current position.
- **Aggregate:** Represents the collection of elements.
- **Client:** Uses the iterator to traverse the collection.

## Implementation

This example implements a generic iterator using C++ templates.

- `Iterator<T>` provides a reusable iterator for different element types.
- `std::vector<T>` represents the collection.
- `hasNext()` checks whether more elements are available.
- `next()` returns the next element and advances the iterator.
- `main()` acts as the client and demonstrates iteration over integers and strings.

The implementation supports different element types but uses `std::vector` as its underlying collection.

## Key Concepts

- Sequential Traversal
- Behavioral Design Pattern
- Iterator Abstraction
- Generic Programming
- C++ Templates
- Encapsulation
- Separation of Responsibilities