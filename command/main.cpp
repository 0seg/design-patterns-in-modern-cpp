
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

// Receiver

class TextEditor {
private:
    std::string text_;

public:
    void write(const std::string& text) {
        text_ += text;
    }

    std::string eraseLast(std::size_t count) {
        if (count > text_.size()) {
            count = text_.size();
        }

        std::string removed = text_.substr(text_.size() - count);
        text_.erase(text_.size() - count);

        return removed;
    }

    void restore(const std::string& text) {
        text_ += text;
    }

    void save() const {
        std::cout << "Document saved.\n";
    }

    void show() const {
        std::cout << "Document: \"" << text_ << "\"\n";
    }
};

// Command

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;

    virtual ~Command() = default;
};

// Concrete Command: Write

class WriteCommand : public Command {
private:
    TextEditor& editor_;
    std::string text_;

public:
    WriteCommand(TextEditor& editor, std::string text)
        : editor_(editor), text_(std::move(text)) {}

    void execute() override {
        editor_.write(text_);
    }

    void undo() override {
        editor_.eraseLast(text_.size());
    }
};

// Concrete Command: Delete

class DeleteCommand : public Command {
private:
    TextEditor& editor_;
    std::size_t count_;
    std::string removedText_;

public:
    DeleteCommand(TextEditor& editor, std::size_t count)
        : editor_(editor), count_(count) {}

    void execute() override {
        removedText_ = editor_.eraseLast(count_);
    }

    void undo() override {
        editor_.restore(removedText_);
    }
};

// Concrete Command: Save

class SaveCommand : public Command {
private:
    TextEditor& editor_;

public:
    explicit SaveCommand(TextEditor& editor)
        : editor_(editor) {}

    void execute() override {
        editor_.save();
    }

    void undo() override {
        // Saving has no reversible effect in this example.
    }
};

// Composite Command: Macro

class MacroCommand : public Command {
private:
    std::vector<std::unique_ptr<Command>> commands_;

public:
    void add(std::unique_ptr<Command> command) {
        commands_.push_back(std::move(command));
    }

    void execute() override {
        for (auto& command : commands_) {
            command->execute();
        }
    }

    void undo() override {
        for (auto it = commands_.rbegin();
             it != commands_.rend();
             ++it) {
            (*it)->undo();
        }
    }
};

// Invoker: Command History

class CommandHistory {
private:
    std::vector<std::unique_ptr<Command>> history_;

public:
    void execute(std::unique_ptr<Command> command) {
        command->execute();
        history_.push_back(std::move(command));
    }

    void undo() {
        if (history_.empty()) {
            std::cout << "Nothing to undo.\n";
            return;
        }

        history_.back()->undo();
        history_.pop_back();
    }
};

// Client

int main() {
    TextEditor editor;
    CommandHistory history;

    std::cout << "=== Command Pattern ===\n\n";

    // Individual commands
    std::cout << "--- Individual Commands ---\n";

    history.execute(
        std::make_unique<WriteCommand>(editor, "Hello ")
    );

    history.execute(
        std::make_unique<WriteCommand>(editor, "World!")
    );

    editor.show();

    // Undo last command
    std::cout << "\n--- Undo ---\n";

    history.undo();
    editor.show();

    // Delete command
    std::cout << "\n--- Delete Command ---\n";

    history.execute(
        std::make_unique<DeleteCommand>(editor, 3)
    );

    editor.show();

    // Undo deletion
    std::cout << "\n--- Undo Delete ---\n";

    history.undo();
    editor.show();

    // Macro command
    std::cout << "\n--- Macro Command ---\n";

    auto macro = std::make_unique<MacroCommand>();

    macro->add(
        std::make_unique<WriteCommand>(editor, " from ")
    );

    macro->add(
        std::make_unique<WriteCommand>(editor, "Command Pattern")
    );

    macro->add(
        std::make_unique<SaveCommand>(editor)
    );

    history.execute(std::move(macro));

    editor.show();

    // Undo entire macro
    std::cout << "\n--- Undo Macro ---\n";

    history.undo();
    editor.show();

    // Undo previous command
    std::cout << "\n--- Undo Previous Command ---\n";

    history.undo();
    editor.show();

    return 0;
}
