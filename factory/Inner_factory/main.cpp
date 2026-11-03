
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age{};

    Person(const std::string& name, int age)
        : name(name), age(age) {}

public:
    class Factory {
    public:
        static Person create(const std::string& name, int age) {
            if (name.empty() || age <= 0) {
                throw std::invalid_argument("Invalid person data");
            }

            return Person{name, age};
        }
    };

    void display() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "Age: " << age << '\n';
    }
};

int main() {
    Person person = Person::Factory::create("John", 25);

    person.display();

    return 0;
}
