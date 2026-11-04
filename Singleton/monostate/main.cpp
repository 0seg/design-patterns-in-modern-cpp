#include <iostream>

class GameSettings {
private:
    inline static int volume_ = 100;
    inline static bool fullscreen_ = false;

public:
    void setVolume(int volume) const {
        volume_ = volume;
    }

    int getVolume() const {
        return volume_;
    }

    void setFullscreen(bool fullscreen) const {
        fullscreen_ = fullscreen;
    }

    bool isFullscreen() const {
        return fullscreen_;
    }
};

int main() {
    GameSettings settings1;
    GameSettings settings2;

    // Modify shared state through the first object
    settings1.setVolume(50);
    settings1.setFullscreen(true);

    // Read the same state through the second object
    std::cout << std::boolalpha;

    std::cout << "Settings 1:\n";
    std::cout << "Volume: " << settings1.getVolume() << '\n';
    std::cout << "Fullscreen: " << settings1.isFullscreen() << '\n';

    std::cout << "\nSettings 2:\n";
    std::cout << "Volume: " << settings2.getVolume() << '\n';
    std::cout << "Fullscreen: " << settings2.isFullscreen() << '\n';

    // Verify that these are different objects
    std::cout << "\nSame object: "
              << (&settings1 == &settings2) << '\n';

    return 0;
}
