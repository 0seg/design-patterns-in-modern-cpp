
#include <iostream>
#include <string>
#include <memory>

// Abstract Products
struct Character {
    std::string name;
    int health;
    int attack;

    Character(const std::string& name, int health, int attack)
        : name(name), health(health), attack(attack) {}

    virtual void display() const = 0;
    virtual ~Character() = default;
};

struct Weapon {
    std::string name;
    int damage;

    Weapon(const std::string& name, int damage)
        : name(name), damage(damage) {}

    virtual void display() const = 0;
    virtual ~Weapon() = default;
};

struct Environment {
    std::string name;
    std::string description;

    Environment(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    virtual void display() const = 0;
    virtual ~Environment() = default;
};

// Medieval Products
struct MedievalCharacter : public Character {
    MedievalCharacter(const std::string& name, int health, int attack)
        : Character(name, health, attack) {}

    void display() const override {
        std::cout << "Medieval character: " << name
                  << " | Health: " << health
                  << " | Attack: " << attack << '\n';
    }
};

struct MedievalWeapon : public Weapon {
    MedievalWeapon(const std::string& name, int damage)
        : Weapon(name, damage) {}

    void display() const override {
        std::cout << "Medieval weapon: " << name
                  << " | Damage: " << damage << '\n';
    }
};

struct MedievalEnvironment : public Environment {
    MedievalEnvironment(const std::string& name, const std::string& description)
        : Environment(name, description) {}

    void display() const override {
        std::cout << "Medieval environment: " << name
                  << " | " << description << '\n';
    }
};

// Futuristic Products
struct FuturisticCharacter : public Character {
    FuturisticCharacter(const std::string& name, int health, int attack)
        : Character(name, health, attack) {}

    void display() const override {
        std::cout << "Futuristic character: " << name
                  << " | Health: " << health
                  << " | Attack: " << attack << '\n';
    }
};

struct FuturisticWeapon : public Weapon {
    FuturisticWeapon(const std::string& name, int damage)
        : Weapon(name, damage) {}

    void display() const override {
        std::cout << "Futuristic weapon: " << name
                  << " | Damage: " << damage << '\n';
    }
};

struct FuturisticEnvironment : public Environment {
    FuturisticEnvironment(const std::string& name, const std::string& description)
        : Environment(name, description) {}

    void display() const override {
        std::cout << "Futuristic environment: " << name
                  << " | " << description << '\n';
    }
};

// Sci-Fi Products
struct SciFiCharacter : public Character {
    SciFiCharacter(const std::string& name, int health, int attack)
        : Character(name, health, attack) {}

    void display() const override {
        std::cout << "Sci-Fi character: " << name
                  << " | Health: " << health
                  << " | Attack: " << attack << '\n';
    }
};

struct SciFiWeapon : public Weapon {
    SciFiWeapon(const std::string& name, int damage)
        : Weapon(name, damage) {}

    void display() const override {
        std::cout << "Sci-Fi weapon: " << name
                  << " | Damage: " << damage << '\n';
    }
};

struct SciFiEnvironment : public Environment {
    SciFiEnvironment(const std::string& name, const std::string& description)
        : Environment(name, description) {}

    void display() const override {
        std::cout << "Sci-Fi environment: " << name
                  << " | " << description << '\n';
    }
};

// Abstract Factory
struct GameFactory {
    virtual std::unique_ptr<Character> createCharacter() const = 0;
    virtual std::unique_ptr<Weapon> createWeapon() const = 0;
    virtual std::unique_ptr<Environment> createEnvironment() const = 0;

    virtual ~GameFactory() = default;
};

// Concrete Factories
struct MedievalFactory : public GameFactory {
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<MedievalCharacter>("Medieval Hero", 100, 50);
    }

    std::unique_ptr<Weapon> createWeapon() const override {
        return std::make_unique<MedievalWeapon>("Sword", 75);
    }

    std::unique_ptr<Environment> createEnvironment() const override {
        return std::make_unique<MedievalEnvironment>(
            "Castle", "A medieval castle environment."
        );
    }
};

struct FuturisticFactory : public GameFactory {
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<FuturisticCharacter>("Futuristic Hero", 100, 50);
    }

    std::unique_ptr<Weapon> createWeapon() const override {
        return std::make_unique<FuturisticWeapon>("Laser Gun", 75);
    }

    std::unique_ptr<Environment> createEnvironment() const override {
        return std::make_unique<FuturisticEnvironment>(
            "Space Station", "A futuristic space station environment."
        );
    }
};

struct SciFiFactory : public GameFactory {
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<SciFiCharacter>("Sci-Fi Hero", 100, 50);
    }

    std::unique_ptr<Weapon> createWeapon() const override {
        return std::make_unique<SciFiWeapon>("Plasma Rifle", 75);
    }

    std::unique_ptr<Environment> createEnvironment() const override {
        return std::make_unique<SciFiEnvironment>(
            "Alien Planet", "A mysterious alien planet environment."
        );
    }
};

// Client: works with the abstract factory
void initializeGame(const GameFactory& factory) {
    auto character = factory.createCharacter();
    auto weapon = factory.createWeapon();
    auto environment = factory.createEnvironment();

    character->display();
    weapon->display();
    environment->display();
}

int main() {
    MedievalFactory medievalFactory;
    FuturisticFactory futuristicFactory;
    SciFiFactory scifiFactory;

    std::cout << "--- Medieval Game ---\n";
    initializeGame(medievalFactory);

    std::cout << "\n--- Futuristic Game ---\n";
    initializeGame(futuristicFactory);

    std::cout << "\n--- Sci-Fi Game ---\n";
    initializeGame(scifiFactory);

    return 0;
}
