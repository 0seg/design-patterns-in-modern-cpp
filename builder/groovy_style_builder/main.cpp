
#include <iostream>
#include <string>

struct NetworkConfig {
    std::string host;
    int port{};
};

struct SecurityConfig {
    bool enabled{};
    int maxAttempts{};
};

struct LoggingConfig {
    bool enabled{};
    std::string level;
};

struct Server {
    NetworkConfig network;
    SecurityConfig security;
    LoggingConfig logging;
};

class ServerBuilder {
private:
    Server server;

public:
    ServerBuilder& configureNetwork(void (*configure)(NetworkConfig&)) {
        configure(server.network);
        return *this;
    }

    ServerBuilder& configureSecurity(void (*configure)(SecurityConfig&)) {
        configure(server.security);
        return *this;
    }

    ServerBuilder& configureLogging(void (*configure)(LoggingConfig&)) {
        configure(server.logging);
        return *this;
    }

    Server build() const {
        return server;
    }
};

int main() {
    Server server = ServerBuilder{}
        .configureNetwork([](NetworkConfig& config) {
            config.host = "localhost";
            config.port = 8080;
        })
        .configureSecurity([](SecurityConfig& config) {
            config.enabled = true;
            config.maxAttempts = 5;
        })
        .configureLogging([](LoggingConfig& config) {
            config.enabled = true;
            config.level = "debug";
        })
        .build();

    std::cout << "Server configuration\n";
    std::cout << "Host: " << server.network.host << '\n';
    std::cout << "Port: " << server.network.port << '\n';
    std::cout << "Security: " << server.security.enabled << '\n';
    std::cout << "Max attempts: " << server.security.maxAttempts << '\n';
    std::cout << "Logging: " << server.logging.enabled << '\n';
    std::cout << "Log level: " << server.logging.level << '\n';
}
