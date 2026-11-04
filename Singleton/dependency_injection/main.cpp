
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

    void log(const std::string& message) const {
        std::cout << "[LOG]: " << message << '\n';
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

class UserService {
private:
    Logger& logger_;

public:
    explicit UserService(Logger& logger)
        : logger_(logger) {}

    void createUser(const std::string& username) const {
        logger_.log("Creating user: " + username);
        logger_.log("User created: " + username);
    }

    const Logger& getLogger() const {
        return logger_;
    }
};

class OrderService {
private:
    Logger& logger_;

public:
    explicit OrderService(Logger& logger)
        : logger_(logger) {}

    void createOrder(const std::string& orderId) const {
        logger_.log("Creating order: " + orderId);
        logger_.log("Order created: " + orderId);
    }

    const Logger& getLogger() const {
        return logger_;
    }
};

int main() {
    // Get the Singleton instance
    Logger& logger = Logger::getInstance();

    // Inject the same instance into both services
    UserService userService(logger);
    OrderService orderService(logger);

    // Execute services
    userService.createUser("fani");
    std::cout << '\n';

    orderService.createOrder("order_123");
    std::cout << '\n';

    // Verify both services use the same Logger instance
    const bool sameInstance =
        &userService.getLogger() == &orderService.getLogger();

    std::cout << std::boolalpha;
    std::cout << "Same Logger instance: " << sameInstance << '\n';

    return 0;
}
