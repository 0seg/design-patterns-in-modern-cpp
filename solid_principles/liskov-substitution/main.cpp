
#include <iostream>

// Liskov Substitution Principle (LSP)
struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

struct Rectangle : Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

struct Square : Shape {
private:
    double side;

public:
    explicit Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }
};

// Works with any Shape implementation.
void printArea(const Shape& shape) {
    std::cout << shape.area() << '\n';
}

int main() {
    Rectangle rectangle(10, 5);
    Square square(5);

    printArea(rectangle);
    printArea(square);

    return 0;
}
