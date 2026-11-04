
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <utility>

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

// Prototype Factory
struct CharacterFactory {
private:
    std::unordered_map<std::string, std::unique_ptr<Character>> prototypes;

public:
    void registerPrototype(
        const std::string& type,
        std::unique_ptr<Character> prototype
    ) {
        prototypes[type] = std::move(prototype);
    }

    std::unique_ptr<Character> createCharacter(
        const std::string& type
    ) const {
        auto it = prototypes.find(type);

        if (it != prototypes.end()) {
            return it->second->clone();
        }

        std::cout << "Prototype not found for type: " << type << '\n';
        return nullptr;
    }

    bool removePrototype(const std::string& type) {
        return prototypes.erase(type) > 0;
    }
};

// Display Character Information
void displayCharacterInfo(const Character& character) {
    std::cout << "Character: " << character.name << '\n';
    std::cout << "Health: " << character.health << '\n';
    std::cout << "Attack: " << character.attack << '\n';
}

int main() {
    CharacterFactory factory;

    // Register prototypes
    factory.registerPrototype("Warrior", std::make_unique<Warrior>());
    factory.registerPrototype("Mage", std::make_unique<Mage>());

    // Create characters
    std::unique_ptr<Character> warrior = factory.createCharacter("Warrior");
    std::unique_ptr<Character> mage = factory.createCharacter("Mage");

    // Modify cloned characters
    if (warrior) {
        warrior->name = "Elite Warrior";
        warrior->health = 150;
    }

    if (mage) {
        mage->name = "Dark Mage";
        mage->health = 120;
    }

    // Display characters
    if (warrior) {
        std::cout << "=== Created Warrior ===\n";
        displayCharacterInfo(*warrior);
    }

    if (mage) {
        std::cout << "\n=== Created Mage ===\n";
        displayCharacterInfo(*mage);
    }

    // Test nonexistent prototype
    auto dragon = factory.createCharacter("Dragon");

    // Remove a prototype
    factory.removePrototype("Mage");

    return 0;
}
