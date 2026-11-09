#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Observer {
public:
    virtual void update(const std::string& news) = 0;

    virtual ~Observer() = default;
};


class Subject {
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;

    virtual ~Subject() = default;
};


class User : public Observer {
private:
    std::string name;

public:
    explicit User(const std::string& name)
        : name(name) {}

    void update(const std::string& news) override {
        std::cout << name << " received news: "
                  << news << '\n';
    }
};


class NewsChannel : public Subject {
private:
    std::vector<Observer*> observers;
    std::string latestNews;

public:
    void subscribe(Observer* observer) override {
        if (observer != nullptr) {
            observers.push_back(observer);
        }
    }

    void unsubscribe(Observer* observer) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void publishNews(const std::string& news) {
        latestNews = news;

        std::cout << "\nNews published: "
                  << latestNews << "\n\n";

        notify();
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(latestNews);
        }
    }
};


int main() {

    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");

    NewsChannel channel;

    // Subscribe users
    channel.subscribe(&alice);
    channel.subscribe(&bob);
    channel.subscribe(&charlie);

    // Publish first news
    channel.publishNews("New C++ standard released!");

    // Unsubscribe Bob
    channel.unsubscribe(&bob);

    // Publish second news
    channel.publishNews("New technology conference announced!");

    return 0;
}
