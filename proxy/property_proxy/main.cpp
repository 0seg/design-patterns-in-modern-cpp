
#include <iostream>
#include <functional>
#include <string>
#include <utility>

// Property Proxy
template <typename T>
class Property {
public:
    using Validator = std::function<bool(const T&)>;
    using ChangeCallback = std::function<void(const T&, const T&)>;

private:
    T value_;
    Validator validator_;
    ChangeCallback onChange_;

public:
    Property(
        T initialValue,
        Validator validator = nullptr,
        ChangeCallback onChange = nullptr
    )
        : value_(std::move(initialValue)),
          validator_(std::move(validator)),
          onChange_(std::move(onChange)) {}

    // Read operation
    operator T() const {
        return value_;
    }

    // Write operation
    Property& operator=(const T& newValue) {
        if (validator_ && !validator_(newValue)) {
            std::cout << "Invalid property value!\n";
            return *this;
        }

        T oldValue = value_;
        value_ = newValue;

        if (onChange_) {
            onChange_(oldValue, value_);
        }

        return *this;
    }
};

// Client
class Player {
public:
    Property<int> health{
        100,

        // Validation
        [](const int& value) {
            return value >= 0 && value <= 100;
        },

        // Change notification
        [](const int& oldValue, const int& newValue) {
            std::cout << "Health changed: "
                      << oldValue << " -> " << newValue << '\n';
        }
    };
};

int main() {
    Player player;

    std::cout << "Initial health: "
              << player.health << "\n\n";

    std::cout << "Assigning valid value:\n";
    player.health = 75;

    std::cout << "\nAssigning invalid value:\n";
    player.health = -50;

    std::cout << "\nAssigning another invalid value:\n";
    player.health = 150;

    std::cout << "\nCurrent health: "
              << player.health << '\n';

    return 0;
}
