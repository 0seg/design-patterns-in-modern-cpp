# Adapter

## Overview

The Adapter pattern allows incompatible interfaces to work together by providing a compatible interface without modifying the original class.

This example also demonstrates caching to avoid repeating expensive operations.

## Structure

- **AudioPlayer:** Target interface expected by the client.
- **LegacyAudioLibrary:** Existing class with an incompatible interface.
- **AudioAdapter:** Adapts the legacy interface to AudioPlayer.
- **Client:** Uses the AudioPlayer interface without depending on the legacy implementation.

## Implementation

`AudioAdapter` implements `AudioPlayer` and uses composition to contain `LegacyAudioLibrary`.

When the client calls `play()`, the adapter delegates the operation to the legacy library.

An `std::unordered_map` stores previously loaded audio data. If a file is requested again, the cached result is reused.

## Key Concepts

- Adapter Pattern
- Composition
- Polymorphism
- Interface Compatibility
- std::unordered_map
- Caching
- std::unique_ptr

