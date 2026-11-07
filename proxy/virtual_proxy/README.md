# Proxy — Virtual Proxy

## Overview

A **Virtual Proxy** is a structural design pattern that represents an expensive object and delays its creation until it is actually needed.

This technique is known as **Lazy Initialization**.

Instead of creating an expensive object immediately, the proxy stores the information required to create it later.

## Problem

Creating objects can be expensive in terms of memory and processing.

For example, loading images from disk may involve:
- Reading large files.
- Allocating memory.
- Decoding image data.

If an application creates every image immediately, it may waste resources on images that the user never opens.

## Solution

The Virtual Proxy acts as an intermediary between the client and the real object.

It creates the real object only when the client first requests it.

Subsequent requests reuse the existing object.

## Components

- **Subject:** Common interface implemented by both the proxy and the real object.
- **RealSubject:** The actual object that performs the expensive operation.
- **Proxy:** Controls when the real object is created and delegates operations to it.
- **Client:** Uses the object through the common interface.

## Implementation

This example simulates an image viewer.

- `Image` defines the common interface.
- `RealImage` represents an image loaded from disk.
- `ImageProxy` delays image creation until `display()` is called.

The proxy uses `std::unique_ptr` to manage the lifetime of the real image.

The `if (!image_)` condition ensures that the image is created only once.

## Key Concepts

- Lazy Initialization
- Virtual Proxy
- Resource Management
- `std::unique_ptr`
- Delegation
- Object Lifetime

