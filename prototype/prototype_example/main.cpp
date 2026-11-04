
#include <iostream>
#include <string>
#include <memory>

// Abstract Product
struct Character {
    std::string name;
    int health;
    int attack;

    Character(const std::string& name, int health, int attack)
        : name(name), health(health), attack(attack) {}

    virtual std::unique_ptr<Character> clone() const = 0;

    virtual ~Character() = default;
};

// Concrete Prototypes
struct Warrior : public Character {
    Warrior() : Character("Warrior", 100, 20) {}

    std::unique_ptr<Character> clone() const override {
        return std::make_unique<Warrior>(*this);
    }
};

struct Mage : public Character {
    Mage() : Character("Mage", 70, 30) {}

    std::unique_ptr<Character> clone() const override {
        return std::make_unique<Mage>(*this);
    }
};

// Display Character Information
void displayCharacterInfo(const Character& character) {
    std::cout << "Character: " << character.name << '\n';
    std::cout << "Health: " << character.health << '\n';
    std::cout << "Attack: " << character.attack << '\n';
}

int main() {
    // Create original characters
    std::unique_ptr<Character> warrior = std::make_unique<Warrior>();
    std::unique_ptr<Character> mage = std::make_unique<Mage>();

    // Clone existing characters
    std::unique_ptr<Character> clonedWarrior = warrior->clone();
    std::unique_ptr<Character> clonedMage = mage->clone();

    // Modify cloned characters
    clonedWarrior->name = "Elite Warrior";
    clonedWarrior->health = 150;

    clonedMage->name = "Dark Mage";
    clonedMage->health = 120;

    // Display original characters
    std::cout << "=== Original Characters ===\n";
    displayCharacterInfo(*warrior);
    std::cout << '\n';
    displayCharacterInfo(*mage);

    // Display cloned characters
    std::cout << "\n=== Cloned Characters ===\n";
    displayCharacterInfo(*clonedWarrior);
    std::cout << '\n';
    displayCharacterInfo(*clonedMage);

    return 0;
}
