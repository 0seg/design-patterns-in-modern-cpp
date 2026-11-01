# Interface Segregation Principle (ISP)

## Definition

The Interface Segregation Principle is one of the five SOLID design principles.

It states that:

> Clients should not be forced to depend on interfaces they do not use.

## Main Idea

Interfaces should be small, specific, and focused on the needs of their clients.

Classes should only implement the operations they actually need.

## Key Points

- Avoid large interfaces with unrelated operations.
- Split interfaces into smaller and more specific ones.
- Do not force classes to implement unnecessary methods.
- Reduce unnecessary dependencies.
- Use multiple interfaces when a class requires different capabilities.

## Important

ISP does not mean creating as many interfaces as possible.

It means designing focused interfaces that represent specific capabilities and avoid unnecessary dependencies.

