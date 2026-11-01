# Liskov Substitution Principle (LSP)

## Definition

The Liskov Substitution Principle is one of the five SOLID design principles.

It states that:

> Objects of a superclass should be replaceable with objects of its subclasses without altering the correctness of the program.

## Main Idea

Derived classes must be able to replace their base classes without breaking the expected behavior of the program.

## Key Points

- Derived classes must respect the base class contract.
- Preserve expected behavior and guarantees.
- Avoid strengthening preconditions.
- Avoid weakening postconditions.
- Use inheritance only when the derived class is behaviorally compatible with the base class.

## Important

LSP is not just about sharing an interface or inheriting methods.

It is about ensuring that derived classes behave consistently with the expectations established by their base classes.

