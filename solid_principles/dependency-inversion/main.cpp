
#include <iostream>

// Dependency Inversion Principle (DIP)
struct Database {
    virtual void saveData() = 0;
    virtual ~Database() = default;
};

struct MySQLDatabase : Database {
    void saveData() override {
        std::cout << "Saving to MySQL\n";
    }
};

struct PostgreSQLDatabase : Database {
    void saveData() override {
        std::cout << "Saving to PostgreSQL\n";
    }
};

struct MongoDatabase : Database {
    void saveData() override {
        std::cout << "Saving to MongoDB\n";
    }
};

// Depends on an abstraction, not a concrete database.
struct UserService {
private:
    Database& database;

public:
    explicit UserService(Database& db) : database(db) {}

    void registerUser() {
        database.saveData();
    }
};

int main() {
    MySQLDatabase mysql;
    PostgreSQLDatabase postgres;
    MongoDatabase mongo;

    UserService service1(mysql);
    UserService service2(postgres);
    UserService service3(mongo);

    service1.registerUser();
    service2.registerUser();
    service3.registerUser();

    return 0;
}
