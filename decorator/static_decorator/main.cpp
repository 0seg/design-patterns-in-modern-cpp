
#include <iostream>
#include <utility>

// Concrete Component
class EmailNotifier {
public:
    void send() {
        std::cout << "Sending email\n";
    }
};

// Static Decorator
template<typename T>
class LoggingDecorator {
private:
    T notifier_;

public:
    explicit LoggingDecorator(T notifier)
        : notifier_(std::move(notifier)) {}

    void send() {
        std::cout << "Logging notification...\n";
        notifier_.send();
    }
};

// Static Decorator
template<typename T>
class SMSDecorator {
private:
    T notifier_;

public:
    explicit SMSDecorator(T notifier)
        : notifier_(std::move(notifier)) {}

    void send() {
        notifier_.send();
        std::cout << "Sending SMS\n";
    }
};

int main() {
    auto notifier =
        SMSDecorator(
            LoggingDecorator(
                EmailNotifier{}
            )
        );

    notifier.send();

    return 0;
}
