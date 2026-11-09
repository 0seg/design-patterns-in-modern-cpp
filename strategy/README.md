# Strategy — Sorting Algorithms

## Overview

**Strategy** is a behavioral design pattern that defines a family of algorithms, encapsulates each one in a separate class, and makes them interchangeable.

It allows an object to change the algorithm it uses without modifying its implementation.

## Problem

A class that implements multiple algorithms using conditional statements can become difficult to maintain and extend.

Adding new algorithms requires modifying existing code, increasing coupling and complexity.

## Solution

The Strategy pattern encapsulates each algorithm behind a common interface.

The Context maintains a reference to the selected strategy and delegates the operation to it.

Strategies can be replaced at runtime without changing the Context.

## Components

- **Strategy:** Abstract interface that defines the common algorithm contract.
- **ConcreteStrategy:** Implements a specific algorithm.
- **Context:** Maintains the selected strategy and delegates operations to it.

## Implementation

This project implements a sorting system with three interchangeable algorithms:

- `BubbleSort`: Sorts elements using repeated comparisons and swaps.
- `QuickSort`: Uses partitioning and recursion to sort elements.
- `MergeSort`: Divides the collection into smaller parts and merges them in sorted order.

The `Sorter` class acts as the Context and uses `std::unique_ptr<SortingStrategy>` to manage the selected strategy.

The sorting algorithm can be changed at runtime using `setStrategy()`.

## Key Concepts

- Behavioral design pattern.
- Algorithm encapsulation.
- Runtime polymorphism.
- Composition and delegation.
- Interchangeable algorithms.
- Smart pointers (`std::unique_ptr`).

