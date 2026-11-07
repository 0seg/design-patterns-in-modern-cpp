
#include <iostream>
#include <string>
#include <stdexcept>

// Subject
class Account {
public:
    virtual double getBalance() const = 0;
    virtual ~Account() = default;
};

// Simulated remote server
class RemoteAccount {
private:
    double balance_;

public:
    explicit RemoteAccount(double balance)
        : balance_(balance) {}

    double getBalance() const {
        std::cout << "[Server] Processing balance request...\n";
        return balance_;
    }
};

// Communication Proxy
class AccountProxy : public Account {
private:
    const RemoteAccount& server_;

    double sendRequest() const {
        std::cout << "[Proxy] Sending request to server...\n";

        // Simulate remote method execution
        double response = server_.getBalance();

        std::cout << "[Proxy] Receiving server response...\n";

        return response;
    }

public:
    explicit AccountProxy(const RemoteAccount& server)
        : server_(server) {}

    double getBalance() const override {
        return sendRequest();
    }
};

// Client
int main() {
    RemoteAccount server(2500.50);

    AccountProxy account(server);

    std::cout << "=== COMMUNICATION PROXY ===\n\n";

    std::cout << "[Client] Requesting account balance...\n";

    double balance = account.getBalance();

    std::cout << "\n[Client] Account balance: "
              << balance << '\n';

    return 0;
}
