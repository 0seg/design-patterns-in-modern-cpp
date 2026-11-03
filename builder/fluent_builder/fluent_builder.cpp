
#include <iostream>
#include <string>
#include <stdexcept>

struct User {
private:
    std::string name;
    std::string email;
    int age{};

public:
    // Read-only access to the user information.
    const std::string& getName() const { return name; }
    const std::string& getEmail() const { return email; }
    int getAge() const { return age; }

    // Allows the builder to configure private members.
    friend struct UserBuilder;
};

struct UserBuilder {
private:
    User user;

public:
    // Configure the name.
    UserBuilder& setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty");
        }

        user.name = name;
        return *this;
    }

    // Configure the email.
    UserBuilder& setEmail(const std::string& email) {
        user.email = email;
        return *this;
    }

    // Configure age with a positive value.
    UserBuilder& setAge(int age) {
        if (age <= 0) {
            throw std::invalid_argument("Age must be positive");
        }

        user.age = age;
        return *this;
    }

    // Finalize and return the constructed User object.
    User build() const {
        return user;
    }
};

int main() {
    User user = UserBuilder{}
        .setName("fani")
        .setEmail("fani123@test.com")
        .setAge(25)
        .build();

    std::cout << "User Name: " << user.getName() << '\n';
    std::cout << "User Email: " << user.getEmail() << '\n';
    std::cout << "User Age: " << user.getAge() << '\n';

    return 0;
}
