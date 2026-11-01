
#include <iostream>

// Interface Segregation Principle (ISP)

struct Readable {
    virtual void read() const = 0;
    virtual ~Readable() = default;
};

struct Writable {
    virtual void write() const = 0;
    virtual ~Writable() = default;
};

struct Deletable {
    virtual void deleteFile() const = 0;
    virtual ~Deletable() = default;
};

// Only implements the required interface.
struct ReadOnlyFile : Readable {
    void read() const override {
        std::cout << "Reading file...\n";
    }
};

// Implements multiple required interfaces.
struct ReadWriteFile : Readable, Writable, Deletable {
    void read() const override {
        std::cout << "Reading file...\n";
    }

    void write() const override {
        std::cout << "Writing file...\n";
    }

    void deleteFile() const override {
        std::cout << "Deleting file...\n";
    }
};

int main() {
    ReadOnlyFile readOnly;
    ReadWriteFile readWrite;

    readOnly.read();

    readWrite.read();
    readWrite.write();
    readWrite.deleteFile();

    return 0;
}
