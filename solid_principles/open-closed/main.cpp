```cpp
#include <iostream>

// Open-Closed Principle: open for extension, closed for modification.
struct Discount {
    virtual double applyDiscount(double price) const = 0;
    virtual ~Discount() = default;
};

// Each class provides its own discount calculation.
struct ClientDiscount : Discount {
    double applyDiscount(double price) const override {
        return price * 0.9;
    }
};

struct StudentDiscount : Discount {
    double applyDiscount(double price) const override {
        return price * 0.8;
    }
};

struct ClientVIPDiscount : Discount {
    double applyDiscount(double price) const override {
        return price * 0.7;
    }
};

// Works with any Discount implementation.
double calculateTotal(const Discount& discount, double price) {
    return discount.applyDiscount(price);
}

int main() {
    constexpr double price = 100.0;

    ClientDiscount client;
    StudentDiscount student;
    ClientVIPDiscount vip;

    std::cout << calculateTotal(client, price) << '\n';
    std::cout << calculateTotal(student, price) << '\n';
    std::cout << calculateTotal(vip, price) << '\n';

    return 0;
}
```