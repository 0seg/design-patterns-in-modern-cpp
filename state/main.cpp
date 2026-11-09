
#include <iostream>
#include <memory>
#include <string>

// Forward declaration
class VendingMachine;

// STATE
class State {
public:
    virtual void insertMoney(VendingMachine& machine) = 0;
    virtual void selectProduct(VendingMachine& machine) = 0;
    virtual void dispense(VendingMachine& machine) = 0;

    virtual ~State() = default;
};

// CONTEXT
class VendingMachine {
private:
    std::unique_ptr<State> currentState;

public:
    explicit VendingMachine(std::unique_ptr<State> initialState)
        : currentState(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState);
    }

    void insertMoney() {
        currentState->insertMoney(*this);
    }

    void selectProduct() {
        currentState->selectProduct(*this);
    }

    void dispense() {
        currentState->dispense(*this);
    }
};

// Forward declarations of concrete states
class NoMoneyState;
class HasMoneyState;
class ProductSelectedState;
class DispensingState;

// CONCRETE STATE: NO MONEY
class NoMoneyState : public State {
public:
    void insertMoney(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine) override;
    void dispense(VendingMachine& machine) override;
};

// CONCRETE STATE: HAS MONEY
class HasMoneyState : public State {
public:
    void insertMoney(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine) override;
    void dispense(VendingMachine& machine) override;
};

// CONCRETE STATE: PRODUCT SELECTED
class ProductSelectedState : public State {
public:
    void insertMoney(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine) override;
    void dispense(VendingMachine& machine) override;
};

// CONCRETE STATE: DISPENSING
class DispensingState : public State {
public:
    void insertMoney(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine) override;
    void dispense(VendingMachine& machine) override;
};

// NO MONEY IMPLEMENTATION
void NoMoneyState::insertMoney(VendingMachine& machine) {
    std::cout << "Money inserted.\n";
    machine.setState(std::make_unique<HasMoneyState>());
}

void NoMoneyState::selectProduct(VendingMachine&) {
    std::cout << "Insert money first.\n";
}

void NoMoneyState::dispense(VendingMachine&) {
    std::cout << "You must select a product first.\n";
}

// HAS MONEY IMPLEMENTATION
void HasMoneyState::insertMoney(VendingMachine&) {
    std::cout << "Money already inserted.\n";
}

void HasMoneyState::selectProduct(VendingMachine& machine) {
    std::cout << "Product selected.\n";
    machine.setState(std::make_unique<ProductSelectedState>());
}

void HasMoneyState::dispense(VendingMachine&) {
    std::cout << "Select a product first.\n";
}

// PRODUCT SELECTED IMPLEMENTATION
void ProductSelectedState::insertMoney(VendingMachine&) {
    std::cout << "Money already inserted.\n";
}

void ProductSelectedState::selectProduct(VendingMachine&) {
    std::cout << "A product is already selected.\n";
}

void ProductSelectedState::dispense(VendingMachine& machine) {
    std::cout << "Starting product delivery...\n";
    machine.setState(std::make_unique<DispensingState>());
    machine.dispense();
}

// DISPENSING IMPLEMENTATION
void DispensingState::insertMoney(VendingMachine&) {
    std::cout << "Please wait. Product is being dispensed.\n";
}

void DispensingState::selectProduct(VendingMachine&) {
    std::cout << "Please wait. Product is being dispensed.\n";
}

void DispensingState::dispense(VendingMachine& machine) {
    std::cout << "Product dispensed successfully!\n";
    std::cout << "Returning to initial state.\n";
    machine.setState(std::make_unique<NoMoneyState>());
}

int main() {
    VendingMachine machine(std::make_unique<NoMoneyState>());

    machine.selectProduct();

    std::cout << "\n--- First purchase ---\n";
    machine.insertMoney();
    machine.selectProduct();
    machine.dispense();

    std::cout << "\n--- Second purchase ---\n";
    machine.insertMoney();
    machine.selectProduct();
    machine.dispense();

    return 0;
}
