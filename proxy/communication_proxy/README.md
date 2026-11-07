# Proxy — Communication Proxy

## Overview

A **Communication Proxy** is a structural design pattern that represents a remote object and manages communication between the client and that object.

It hides communication details behind an interface similar to the one provided by the real object.

## Problem

When an application communicates with a remote service, it may need to handle:

- Sending requests.
- Receiving responses.
- Network communication.
- Serialization and deserialization.
- Communication errors.

Managing these details directly inside the client can make the application more complex.

## Solution

The Communication Proxy acts as an intermediary between the client and the remote object.

The client calls methods on the proxy, while the proxy handles the communication with the remote service.

## Components

- **Subject:** Common interface used by the client and proxy.
- **RealSubject:** Represents the remote object that performs the actual operation.
- **Communication Proxy:** Sends requests and receives responses from the remote object.
- **Client:** Interacts with the proxy through the common interface.

## Implementation

This example simulates a banking application that retrieves an account balance.

- `Account` defines the common interface.
- `RemoteAccount` represents the server-side object.
- `AccountProxy` manages the request and response flow.
- `main()` acts as the client.

The implementation simulates communication in the same process. It does not establish an actual network connection.

## Key Concepts

- Remote Object Access
- Client-Server Communication
- Request and Response
- Interface Abstraction
- Delegation
- Communication Separation

