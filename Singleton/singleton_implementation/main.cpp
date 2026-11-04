
#include <iostream>
#include <string>

class Logger {
private:
    Logger() {
        std::cout << "Logger created\n";
    }

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << '\n';
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

int main() {
    Logger& logger1 = Logger::getInstance();
    logger1.log("Application started");

    Logger& logger2 = Logger::getInstance();
    logger2.log("User logged in");

    std::cout << std::boolalpha;
    std::cout << "Same instance: "
              << (&logger1 == &logger2) << '\n';

    return 0;
}
