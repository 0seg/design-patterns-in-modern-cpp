
#include <iostream>
#include <string>
#include <vector>


class User;

class ChatMediator {
public:
    virtual void sendMessage(
        const std::string& message,
        User* sender
    ) = 0;

    virtual ~ChatMediator() = default;
};


class User {
private:
    std::string name;
    ChatMediator* mediator;

public:
    User(const std::string& name, ChatMediator* mediator)
        : name(name), mediator(mediator) {}

    void send(const std::string& message) {
        std::cout << name << " sends: " << message << '\n';
        mediator->sendMessage(message, this);
    }

    void receive(const std::string& message) {
        std::cout << name << " received: "
                  << message << '\n';
    }

    const std::string& getName() const {
        return name;
    }
};


class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;

public:
    void addUser(User* user) {
        users.push_back(user);
    }

    void sendMessage(
        const std::string& message,
        User* sender
    ) override {

        for (User* user : users) {
            if (user != sender) {
                user->receive(message);
            }
        }
    }
};



int main() {

    ChatRoom chat;

    User alice("Alice", &chat);
    User bob("Bob", &chat);
    User charlie("Charlie", &chat);

    chat.addUser(&alice);
    chat.addUser(&bob);
    chat.addUser(&charlie);

    alice.send("Hello everyone!");

    std::cout << '\n';

    bob.send("Hey Alice!");

    return 0;
}
