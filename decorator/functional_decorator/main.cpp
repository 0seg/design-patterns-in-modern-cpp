
#include <iostream>
#include <functional>

using Operation = std::function<void()>;

// Concrete Operation
Operation sendEmail = []() {
    std::cout << "Sending email\n";
};

// Functional Decorator
Operation addLogging(Operation operation) {
    return [operation]() {
        std::cout << "Logging notification...\n";
        operation();
    };
}

// Functional Decorator
Operation addSMS(Operation operation) {
    return [operation]() {
        operation();
        std::cout << "Sending SMS\n";
    };
}

// Functional Decorator
Operation addEncryption(Operation operation) {
    return [operation]() {
        std::cout << "Encrypting message...\n";
        operation();
    };
}

int main() {
    Operation notifier = addSMS(
        addLogging(
            addEncryption(sendEmail)
        )
    );

    notifier();

    return 0;
}
