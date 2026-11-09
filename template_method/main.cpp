
#include <iostream>
#include <string>

// ABSTRACT CLASS
class CaffeineBeverage {
public:
    // TEMPLATE METHOD
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();

        if (customerWantsCondiments()) {
            addCondiments();
        }

        std::cout << "Beverage ready!\n";
    }

protected:
    // Shared operations
    void boilWater() {
        std::cout << "Boiling water...\n";
    }

    void pourInCup() {
        std::cout << "Pouring into cup...\n";
    }

    // Abstract operations
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // Hook
    virtual bool customerWantsCondiments() {
        return true;
    }

    virtual ~CaffeineBeverage() = default;
};

// CONCRETE CLASS: COFFEE
class Coffee : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "Brewing coffee grounds...\n";
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk...\n";
    }
};

// CONCRETE CLASS: TEA
class Tea : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "Steeping tea leaves...\n";
    }

    void addCondiments() override {
        std::cout << "Adding lemon...\n";
    }

    bool customerWantsCondiments() override {
        return false;
    }
};

int main() {
    std::cout << "=== Preparing Coffee ===\n";

    Coffee coffee;
    coffee.prepareRecipe();

    std::cout << "\n=== Preparing Tea ===\n";

    Tea tea;
    tea.prepareRecipe();

    return 0;
}
