# Composite — File System

## Overview

This project demonstrates the Composite design pattern through a simplified file system.

The pattern allows individual files and folders to be treated through a common interface. Folders can contain both files and other folders.

## Structure

```text
file-system/
├── FileSystem.hpp
├── FileSystem.cpp
├── main.cpp
└── README.md
```

## File System Operations

- File creation
- Folder creation
- Adding files and folders
- Recursive folder size calculation

## Composite Implementation

### file_system.hpp

Defines the `FileSystemComponent` interface and its concrete implementations: `File` and `Folder`.

### file_system.cpp

Implements file and folder operations, including recursive size calculation.

### main.cpp

Creates a file system hierarchy and calculates the total size of the root folder.

## Key Concepts

- Composite design pattern
- Component interface
- Leaf objects
- Composite objects
- Polymorphism
- Recursive composition
- Ownership with `std::unique_ptr`