
#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age{};

    struct Address {
        std::string street;
        std::string city;
    } address;

    struct Job {
        std::string company;
        std::string position;
    } job;
};

class PersonPersonalBuilder {
private:
    Person& person;

public:
    explicit PersonPersonalBuilder(Person& person)
        : person(person) {}

    PersonPersonalBuilder& setName(const std::string& name) {
        person.name = name;
        return *this;
    }

    PersonPersonalBuilder& setAge(int age) {
        person.age = age;
        return *this;
    }
};

class PersonAddressBuilder {
private:
    Person& person;

public:
    explicit PersonAddressBuilder(Person& person)
        : person(person) {}

    PersonAddressBuilder& at(const std::string& street) {
        person.address.street = street;
        return *this;
    }

    PersonAddressBuilder& in(const std::string& city) {
        person.address.city = city;
        return *this;
    }
};

class PersonJobBuilder {
private:
    Person& person;

public:
    explicit PersonJobBuilder(Person& person)
        : person(person) {}

    PersonJobBuilder& at(const std::string& company) {
        person.job.company = company;
        return *this;
    }

    PersonJobBuilder& as(const std::string& position) {
        person.job.position = position;
        return *this;
    }
};

class PersonBuilder {
private:
    Person person;

public:
    PersonPersonalBuilder personal() {
        return PersonPersonalBuilder{person};
    }

    PersonAddressBuilder address() {
        return PersonAddressBuilder{person};
    }

    PersonJobBuilder employment() {
        return PersonJobBuilder{person};
    }

    Person build() const {
        return person;
    }
};

int main() {
    PersonBuilder builder;

    builder.personal()
        .setName("John")
        .setAge(25);

    builder.address()
        .at("123 Main Street")
        .in("New York");

    builder.employment()
        .at("OpenAI")
        .as("Software Engineer");

    Person person = builder.build();

    std::cout << "Name: " << person.name << '\n';
    std::cout << "Age: " << person.age << '\n';
    std::cout << "Street: " << person.address.street << '\n';
    std::cout << "City: " << person.address.city << '\n';
    std::cout << "Company: " << person.job.company << '\n';
    std::cout << "Position: " << person.job.position << '\n';

    return 0;
}
