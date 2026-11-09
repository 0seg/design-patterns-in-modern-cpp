#include <iostream>
#include <string>
#include <vector>
#include <utility>


class Memento {
private:
    std::string savedText;

public:
    explicit Memento(const std::string& text)
        : savedText(text) {}

    const std::string& getState() const {
        return savedText;
    }
};


class Document {
private:
    std::string text;

public:
    void write(const std::string& newText) {
        text = newText;
    }

    void show() const {
        std::cout << "Document: " << text << '\n';
    }

    Memento save() const {
        return Memento(text);
    }

    void restore(const Memento& memento) {
        text = memento.getState();
    }
};


class History {
private:
    std::vector<Memento> snapshots;

public:
    void save(const Document& document) {
        snapshots.push_back(document.save());
    }

    bool undo(Document& document) {
        if (snapshots.empty()) {
            return false;
        }

        document.restore(snapshots.back());
        snapshots.pop_back();

        return true;
    }
};



int main() {

    Document document;
    History history;

    document.write("Hello");
    history.save(document);

    document.show();

    document.write("Hello World");
    history.save(document);

    document.show();

    document.write("Hello C++");
    document.show();

    std::cout << "\nUndo operation:\n";

    if (history.undo(document)) {
        document.show();
    }

    std::cout << "\nAnother undo operation:\n";

    if (history.undo(document)) {
        document.show();
    }

    return 0;
}
