
#include <iostream>
#include <string>

// Request
struct Request {
    std::string type;
    std::string description;
};

// Abstract Handler
class Handler {
protected:
    Handler* next_ = nullptr;

public:
    virtual ~Handler() = default;

    void setNext(Handler* handler) {
        next_ = handler;
    }

    virtual void handle(const Request& request) = 0;
};

// Concrete Handler
class BasicSupport : public Handler {
public:
    void handle(const Request& request) override {
        if (request.type == "basic") {
            std::cout << "[Basic Support] Handling: "
                      << request.description << '\n';
            return;
        }

        std::cout << "[Basic Support] Cannot handle request.\n";

        if (next_) {
            next_->handle(request);
        }
    }
};

// Concrete Handler
class TechnicalSupport : public Handler {
public:
    void handle(const Request& request) override {
        if (request.type == "technical") {
            std::cout << "[Technical Support] Handling: "
                      << request.description << '\n';
            return;
        }

        std::cout << "[Technical Support] Cannot handle request.\n";

        if (next_) {
            next_->handle(request);
        }
    }
};

// Concrete Handler
class Manager : public Handler {
public:
    void handle(const Request& request) override {
        if (request.type == "admin") {
            std::cout << "[Manager] Handling: "
                      << request.description << '\n';
            return;
        }

        std::cout << "[Manager] Cannot handle request.\n";
        std::cout << "No handler could process this request.\n";
    }
};

int main() {
    BasicSupport basic;
    TechnicalSupport technical;
    Manager manager;

    // Build the chain
    basic.setNext(&technical);
    technical.setNext(&manager);

    Request requests[] = {
        {"basic", "Reset password"},
        {"technical", "Database connection failure"},
        {"admin", "Approve system access"},
        {"unknown", "Unknown problem"}
    };

    for (const Request& request : requests) {
        std::cout << "\nNew request: "
                  << request.type << '\n';

        basic.handle(request);
    }

    return 0;
}
