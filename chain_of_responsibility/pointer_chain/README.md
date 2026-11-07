# Chain of Responsibility — Pointer Chain

## Overview

The Chain of Responsibility pattern allows multiple objects to process a request without the sender needing to know which object will handle it.

Each handler can process the request or pass it to the next handler in the chain.

## Implementation

This example implements a technical support system with three handlers:

- **BasicSupport:** Handles basic requests.
- **TechnicalSupport:** Handles technical issues.
- **Manager:** Handles administrative requests.

## Structure

```text
BasicSupport
     |
     v
TechnicalSupport
     |
     v
Manager
```

## Key Concepts

- **Handler:** Defines the common interface.
- **Concrete Handlers:** Implement specific responsibilities.
- **Next Pointer:** Connects handlers in the chain.
- **Delegation:** Passes requests to the next handler when necessary.
