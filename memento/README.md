# Memento — Document State

## Overview

The **Memento** is a behavioral design pattern that allows an object to save and restore its previous state without exposing its internal implementation.

It stores snapshots of an object's state so that it can be recovered later.

## Problem

When an application needs to restore previous states of an object, it must preserve information about its earlier versions.

For example, a text editor may need to support undo operations.

Managing and restoring these states directly from outside the object can expose its internal details and create unnecessary dependencies.

## Solution

The Memento pattern introduces an object that stores a snapshot of the Originator's state.

A separate object, called the Caretaker, manages these snapshots without modifying their internal contents.

The Originator is responsible for creating and restoring its own states.

## Components

- **Originator:** The object whose state needs to be saved and restored.
- **Memento:** Stores a snapshot of the Originator's state.
- **Caretaker:** Manages and stores the Mementos without modifying their contents.

## Implementation

This example simulates a simple text editor that supports undo operations.

- `Document` represents the Originator and manages the document content.
- `Memento` stores a snapshot of the document's text.
- `History` acts as the Caretaker and manages the saved snapshots.
- `main()` demonstrates saving document states and restoring previous versions.

The implementation uses a vector to store snapshots and allows the document to return to previously saved states.

## Key Concepts

- State Preservation
- Object Restoration
- Encapsulation
- Snapshots
- Undo Operations
- Behavioral Design Pattern