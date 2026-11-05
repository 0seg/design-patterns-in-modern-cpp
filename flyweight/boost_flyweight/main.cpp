
#include <boost/flyweight.hpp>
#include <boost/functional/hash.hpp>

#include <iostream>
#include <string>

// Intrinsic State
struct TextStyle {
    std::string font;
    int size;
    std::string color;

    bool operator==(const TextStyle& other) const {
        return font == other.font &&
               size == other.size &&
               color == other.color;
    }
};

// Hash function for TextStyle
std::size_t hash_value(const TextStyle& style) {
    std::size_t seed = 0;

    boost::hash_combine(seed, style.font);
    boost::hash_combine(seed, style.size);
    boost::hash_combine(seed, style.color);

    return seed;
}

// Context: Extrinsic State + Flyweight
struct Character {
    char symbol;
    int position;

    boost::flyweight<TextStyle> style;

    void draw() const {
        const TextStyle& currentStyle = style.get();

        std::cout << "Character: " << symbol
                  << " | Position: " << position
                  << " | Font: " << currentStyle.font
                  << " | Size: " << currentStyle.size
                  << " | Color: " << currentStyle.color
                  << '\n';
    }
};

int main() {
    using SharedStyle = boost::flyweight<TextStyle>;

    // Characters with shared styles
    Character c1{'H', 0, SharedStyle(TextStyle{"Arial", 12, "Black"})};
    Character c2{'e', 1, SharedStyle(TextStyle{"Arial", 12, "Black"})};
    Character c3{'l', 2, SharedStyle(TextStyle{"Arial", 12, "Black"})};
    Character c4{'o', 3, SharedStyle(TextStyle{"Roboto", 16, "Blue"})};

    c1.draw();
    c2.draw();
    c3.draw();
    c4.draw();

    // Verify shared instances
    std::cout << "\nShared Flyweights:\n";
    std::cout << std::boolalpha;

    std::cout << "c1 and c2 share style: "
              << (&c1.style.get() == &c2.style.get()) << '\n';

    std::cout << "c1 and c3 share style: "
              << (&c1.style.get() == &c3.style.get()) << '\n';

    std::cout << "c1 and c4 share style: "
              << (&c1.style.get() == &c4.style.get()) << '\n';

    return 0;
}
