# Interpreter Design Pattern — Handmade Interpreter

A small arithmetic interpreter implemented in C++20 to explore the **Interpreter Design Pattern**.

The project demonstrates how a language can be represented through objects that define its grammar and how those objects interpret expressions recursively.

## The Problem

When building a system that needs to evaluate expressions, writing a large collection of conditional statements for every possible expression quickly becomes difficult to maintain.

For example, consider:

```text
5 + 3 * 2
```

The program needs to understand:
- What each symbol represents.
- How operators relate to each other.
- Which operations have higher precedence.
- How to evaluate nested expressions.

The Interpreter Design Pattern provides a structured way to represent and evaluate a language using an object-oriented grammar.

## Design Pattern: Interpreter

The **Interpreter Pattern** defines a representation for a language's grammar and provides an interpreter that uses this representation to evaluate sentences in that language.

In this project, arithmetic expressions are represented as an Abstract Syntax Tree (AST).

Each node represents either:
- A literal value.
- A binary operation involving two expressions.

The expressions implement a common interface:

```cpp
struct Expression {
    virtual ~Expression() = default;
    virtual int interpret() const = 0;
};
```

This interface defines the operation that every expression must support: interpreting itself and returning a result.

## Class Structure

### Expression

The abstract base class for all expression nodes.

It defines the common `interpret()` operation, allowing different expression types to be evaluated through the same interface.

### NumberExpression

Represents a literal integer.

Its interpretation simply returns the stored value.

```text
NumberExpression(5) → 5
```

### BinaryExpression

Represents a binary operation between two expressions.

It contains:
- A left expression.
- A right expression.
- An operator.

Its `interpret()` method recursively evaluates both children and applies the corresponding operation.

For example:

```text
BinaryExpression(5, +, 3)
             |
             v
             8
```

## How It Works

The interpreter processes an input expression through several stages:

```text
Input
  |
  v
Lexer
  |
  v
Tokens
  |
  v
Parser
  |
  v
Abstract Syntax Tree
  |
  v
Expression::interpret()
  |
  v
Result
```

The Lexer and Parser prepare the expression representation. The Interpreter Pattern is demonstrated by the expression hierarchy and its recursive interpretation.

## Example

Consider the expression:

```text
5 + 3 * 2
```

The parser constructs the following AST:

```text
       +
      / \
     5   *
        / \
       3   2
```

Each node interprets its own expression:

1. `NumberExpression(3)` returns `3`.
2. `NumberExpression(2)` returns `2`.
3. `BinaryExpression(3, *, 2)` returns `6`.
4. `BinaryExpression(5, +, 6)` returns `11`.

Final result:

```text
11
```

This demonstrates recursive interpretation and how the AST preserves operator precedence.

## Grammar

The interpreter supports the following grammar:

```text
Expression = Term (("+" | "-") Term)*
Term       = Factor (("*" | "/") Factor)*
Factor     = Number | "(" Expression ")"
```

Supported operations:

| Operator | Operation |
|---|---|
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `()` | Grouping |

## Usage

Example session:

```text
> 5 + 3 * 2
= 11

> (10 + 5) * 2
= 30

> 100 / (5 + 5)
= 10

> 10 / 0
Error: Division by zero
```

Type `exit` to close the interpreter.

## Key Design Pattern Concepts

This implementation explores:

- **Abstract Expression:** the common interface defining `interpret()`.
- **Terminal Expression:** `NumberExpression`, representing literal values.
- **Nonterminal Expression:** `BinaryExpression`, representing operations composed of other expressions.
- **Recursive Interpretation:** expressions evaluate their child expressions.
- **Polymorphism:** different expression types share the same interface.
- **Composition:** complex expressions are built from simpler expressions.

## Limitations

- Integer arithmetic only.
- No variables or assignments.
- No floating-point values.
- No functions or user-defined operators.
- No unary operators.

