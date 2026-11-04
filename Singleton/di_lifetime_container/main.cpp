
#include <iostream>
#include <memory>
#include <string>

class Logger {
public:
    Logger() {
        std::cout << "Logger created\n";
    }

    ~Logger() {
        std::cout << "Logger destroyed\n";
    }

    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << '\n';
    }
};

class UserService {
private:
    Logger& logger_;

public:
    explicit UserService(Logger& logger)
        : logger_(logger) {}

    void createUser() const {
        logger_.log("User created");
    }
};

class OrderService {
private:
    Logger& logger_;

public:
    explicit OrderService(Logger& logger)
        : logger_(logger) {}

    void createOrder() const {
        logger_.log("Order created");
    }
};

class DIContainer {
private:
    std::unique_ptr<Logger> logger_;

public:
    Logger& getLogger() {
        if (!logger_) {
            logger_ = std::make_unique<Logger>();
        }

        return *logger_;
    }
};

int main() {
    DIContainer container;

    {
        // Inject the same Logger instance into both services
        UserService userService(container.getLogger());
        OrderService orderService(container.getLogger());

        userService.createUser();
        orderService.createOrder();

        // Verify that both requests return the same instance
        const bool sameInstance =
            &container.getLogger() == &container.getLogger();

        std::cout << std::boolalpha;
        std::cout << "Same Logger instance: "
                  << sameInstance << '\n';
    }

    std::cout << "Services destroyed\n";

    return 0;
}
