
#include <iostream>
#include <memory>
#include <utility>

// Component
class Notifier {
public:
    virtual ~Notifier() = default;
    virtual void send() = 0;
};

// Concrete Component
class EmailNotifier : public Notifier {
public:
    void send() override {
        std::cout << "Sending email\n";
    }
};

// Base Decorator
class NotifierDecorator : public Notifier {
protected:
    std::unique_ptr<Notifier> notifier_;

public:
    explicit NotifierDecorator(std::unique_ptr<Notifier> notifier)
        : notifier_(std::move(notifier)) {}
};

// Concrete Decorator
class SMSDecorator : public NotifierDecorator {
public:
    using NotifierDecorator::NotifierDecorator;

    void send() override {
        notifier_->send();
        std::cout << "Sending SMS\n";
    }
};

// Concrete Decorator
class LoggingDecorator : public NotifierDecorator {
public:
    using NotifierDecorator::NotifierDecorator;

    void send() override {
        std::cout << "Logging notification...\n";
        notifier_->send();
    }
};

int main() {
    std::unique_ptr<Notifier> notifier =
        std::make_unique<LoggingDecorator>(
            std::make_unique<SMSDecorator>(
                std::make_unique<EmailNotifier>()
            )
        );

    notifier->send();

    return 0;
}
