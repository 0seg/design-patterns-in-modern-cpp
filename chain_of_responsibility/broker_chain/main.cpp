
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

// Statistics
enum class Statistic {
    attack,
    defense
};

// Event Broker
class Event {
private:
    using Callback = std::function<void(Statistic, class Creature&, int&)>;

    std::vector<std::pair<int, Callback>> handlers_;
    int nextId_ = 0;

public:
    int subscribe(Callback callback) {
        int id = nextId_++;
        handlers_.push_back({id, std::move(callback)});
        return id;
    }

    void unsubscribe(int id) {
        handlers_.erase(
            std::remove_if(
                handlers_.begin(),
                handlers_.end(),
                [id](const auto& handler) {
                    return handler.first == id;
                }
            ),
            handlers_.end()
        );
    }

    void notify(Statistic statistic, class Creature& creature, int& value) {
        // Copy callbacks to allow safe subscription changes during notification.
        auto handlers = handlers_;

        for (auto& handler : handlers) {
            handler.second(statistic, creature, value);
        }
    }
};

// Game / Broker
class Game {
public:
    Event queries;
};

// Creature
class Creature {
private:
    Game& game_;

public:
    std::string name;
    int attack;
    int defense;

    Creature(Game& game, const std::string& name, int attack, int defense)
        : game_(game),
          name(name),
          attack(attack),
          defense(defense) {}

    int getAttack() {
        int result = attack;
        game_.queries.notify(Statistic::attack, *this, result);
        return result;
    }

    int getDefense() {
        int result = defense;
        game_.queries.notify(Statistic::defense, *this, result);
        return result;
    }
};

// Base Modifier
class CreatureModifier {
protected:
    Game& game_;
    Creature& creature_;
    int subscriptionId_;

public:
    CreatureModifier(Game& game, Creature& creature)
        : game_(game), creature_(creature), subscriptionId_(-1) {}

    virtual ~CreatureModifier() {
        if (subscriptionId_ != -1) {
            game_.queries.unsubscribe(subscriptionId_);
        }
    }
};

// Concrete Modifier
class DoubleAttackModifier : public CreatureModifier {
public:
    DoubleAttackModifier(Game& game, Creature& creature)
        : CreatureModifier(game, creature) {

        subscriptionId_ = game_.queries.subscribe(
            [this](Statistic statistic, Creature& target, int& value) {
                if (&target == &creature_ &&
                    statistic == Statistic::attack) {
                    value *= 2;
                }
            }
        );
    }
};

// Concrete Modifier
class IncreaseDefenseModifier : public CreatureModifier {
public:
    IncreaseDefenseModifier(Game& game, Creature& creature)
        : CreatureModifier(game, creature) {

        subscriptionId_ = game_.queries.subscribe(
            [this](Statistic statistic, Creature& target, int& value) {
                if (&target == &creature_ &&
                    statistic == Statistic::defense) {
                    value += 3;
                }
            }
        );
    }
};

// Client
int main() {
    Game game;

    Creature goblin{game, "Goblin", 2, 2};

    std::cout << "=== BROKER CHAIN ===\n\n";

    std::cout << "Base statistics:\n";
    std::cout << "Attack: " << goblin.attack << '\n';
    std::cout << "Defense: " << goblin.defense << "\n\n";

    {
        DoubleAttackModifier doubleAttack{game, goblin};
        IncreaseDefenseModifier increaseDefense{game, goblin};

        std::cout << "With modifiers:\n";
        std::cout << "Attack: " << goblin.getAttack() << '\n';
        std::cout << "Defense: " << goblin.getDefense() << "\n\n";

        std::cout << "Base values remain unchanged:\n";
        std::cout << "Attack: " << goblin.attack << '\n';
        std::cout << "Defense: " << goblin.defense << "\n\n";
    }

    std::cout << "After modifiers are destroyed:\n";
    std::cout << "Attack: " << goblin.getAttack() << '\n';
    std::cout << "Defense: " << goblin.getDefense() << '\n';

    return 0;
}
