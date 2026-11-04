
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Database {
private:
    std::string name_;

    explicit Database(const std::string& name)
        : name_(name) {
        std::cout << "Database created: " << name_ << '\n';
    }

    inline static std::unordered_map<std::string, std::unique_ptr<Database>> instances_;

public:
    static Database& getInstance(const std::string& key) {
        auto it = instances_.find(key);

        if (it == instances_.end()) {
            auto instance = std::unique_ptr<Database>(
                new Database(key)
            );

            it = instances_.emplace(key, std::move(instance)).first;
        }

        return *it->second;
    }

    void connect() const {
        std::cout << "Connected to " << name_ << '\n';
    }

    const std::string& getName() const {
        return name_;
    }

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

int main() {
    // Request instances using different keys
    Database& databaseA = Database::getInstance("DatabaseA");
    Database& databaseB = Database::getInstance("DatabaseB");

    // Request an existing instance
    Database& databaseA2 = Database::getInstance("DatabaseA");

    databaseA.connect();
    databaseB.connect();
    databaseA2.connect();

    // Verify instance identity
    std::cout << std::boolalpha;

    std::cout << "\nDatabase A and A2 are the same: "
              << (&databaseA == &databaseA2) << '\n';

    std::cout << "Database A and B are the same: "
              << (&databaseA == &databaseB) << '\n';

    return 0;
}
