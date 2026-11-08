# Chain of Responsibility — Broker Chain

## Overview

The Broker Chain implementation uses an event-based communication system to process requests dynamically.

Instead of connecting handlers directly through pointers, objects subscribe to a central event broker and receive relevant queries.

## Implementation

This example implements a creature statistics system with two modifiers:

- **DoubleAttackModifier:** Doubles the creature's attack.
- **IncreaseDefenseModifier:** Adds 3 points to its defense.

The modifiers are registered through an event broker and automatically unsubscribe when destroyed.

## Architecture

```text
Creature
   |
   v
Game / Broker
   |
   v
Event
   |
   +---- DoubleAttackModifier
   |
   +---- IncreaseDefenseModifier
```

## Key Concepts

- **Event Broker:** Centralizes communication between objects.
- **Observer:** Modifiers subscribe to statistic queries.
- **Dynamic Registration:** Handlers can subscribe and unsubscribe.
- **Temporary Modifications:** Statistics are calculated without permanently changing base values.
- **RAII:** Modifier destruction automatically unregisters its callback.
