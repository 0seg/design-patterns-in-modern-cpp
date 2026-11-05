
#include <iostream>
#include <string>
#include <map>
#include <vector>

// Flyweight: Intrinsic State
struct TextStyle {
    std::string font;
    int size;
    std::string color;
    bool bold;
};

// Context: Extrinsic State + Flyweight reference
struct Character {
    char symbol;
    int position;
    const TextStyle* style;
};

// Flyweight Factory
class TextStyleFactory {
private:
    std::map<std::string, TextStyle> styles_;

public:
    const TextStyle* getStyle(
        const std::string& font,
        int size,
        const std::string& color,
        bool bold
    ) {
        std::string key = font + "_" +
                          std::to_string(size) + "_" +
                          color + "_" +
                          std::to_string(bold);

        auto it = styles_.find(key);

        if (it != styles_.end()) {
            return &it->second;
        }

        auto [style, inserted] = styles_.emplace(
            key, TextStyle{font, size, color, bold}
        );

        return &style->second;
    }

    std::size_t count() const {
        return styles_.size();
    }
};

// Client
class Document {
private:
    std::vector<Character> characters_;

public:
    void addCharacter(
        char symbol,
        int position,
        const TextStyle* style
    ) {
        characters_.push_back({symbol, position, style});
    }

    void print() const {
        for (const auto& character : characters_) {
            std::cout << character.symbol
                      << " | Position: " << character.position
                      << " | Font: " << character.style->font
                      << " | Size: " << character.style->size
                      << " | Color: " << character.style->color
                      << " | Bold: " << std::boolalpha
                      << character.style->bold << '\n';
        }
    }
};

int main() {
    TextStyleFactory factory;
    Document document;

    // Shared styles
    const TextStyle* normal = factory.getStyle(
        "Arial", 12, "Black", false
    );

    const TextStyle* heading = factory.getStyle(
        "Arial", 20, "Blue", true
    );

    const TextStyle* emphasis = factory.getStyle(
        "Roboto", 14, "Red", true
    );

    // Document characters
    std::string text = "Hello Flyweight";

    for (std::size_t i = 0; i < text.size(); ++i) {
        const TextStyle* style = normal;

        if (i < 5) {
            style = heading;
        } else if (i >= 6) {
            style = emphasis;
        }

        document.addCharacter(
            text[i],
            static_cast<int>(i),
            style
        );
    }

    document.print();

    std::cout << "\nDocument Statistics:\n";
    std::cout << "Characters: " << text.size() << '\n';
    std::cout << "Unique styles: " << factory.count() << '\n';

    std::cout << "\nShared style verification:\n";
    std::cout << std::boolalpha;
    std::cout << "Normal and heading are different: "
              << (normal != heading) << '\n';

    std::cout << "Normal style is reused: "
              << (factory.getStyle("Arial", 12, "Black", false)
                  == normal) << '\n';

    return 0;
}
