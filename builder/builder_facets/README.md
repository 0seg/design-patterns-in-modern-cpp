# Builder Facets

A C++20 implementation of the Builder Facets pattern.

## Overview

Builder Facets extends the Builder pattern by dividing object construction into multiple specialized builders.

Each facet is responsible for configuring a specific part of the final object, while all facets operate on the same underlying object.

## Key Concepts

- **Specialized builders:** Separate configuration responsibilities into different facets.
- **References:** Each facet receives a reference to the same object.
- **Method chaining:** Facet methods return references to their current builder.
- **Shared object:** Different facets modify different parts of the same product.
- **Object construction:** The main builder provides `build()` to return the completed object by value.

## Example

```cpp
PersonBuilder builder;

builder.personal()
    .setName("John")
    .setAge(25);

builder.address()
    .at("123 Main Street")
    .in("New York");

builder.employment()
    .at("OpenAI")
    .as("Software Engineer");

Person person = builder.build();
```

