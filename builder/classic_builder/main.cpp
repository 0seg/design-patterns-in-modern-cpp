
#include <iostream>
#include <stdexcept>
#include <string>

struct Computer {
private:
    std::string cpu;
    std::string gpu;
    int ram{};
    int storage{};

    // Allows the builder to configure private members.
    friend struct ComputerBuilder;

public:
    // Read-only access to the computer configuration.
    const std::string& getCPU() const { return cpu; }
    const std::string& getGPU() const { return gpu; }
    int getRAM() const { return ram; }
    int getStorage() const { return storage; }
};

struct ComputerBuilder {
private:
    Computer computer;

public:
    // Configure the CPU.
    void setCPU(const std::string& cpu) {
        if (cpu.empty()) {
            throw std::invalid_argument("CPU cannot be empty");
        }

        computer.cpu = cpu;
    }

    // Configure the GPU.
    void setGPU(const std::string& gpu) {
        computer.gpu = gpu;
    }

    // Configure RAM with a positive value.
    void setRAM(int ram) {
        if (ram <= 0) {
            throw std::invalid_argument("RAM must be positive");
        }

        computer.ram = ram;
    }

    // Configure storage with a positive value.
    void setStorage(int storage) {
        if (storage <= 0) {
            throw std::invalid_argument("Storage must be positive");
        }

        computer.storage = storage;
    }

    // Return the constructed product.
    Computer build() const {
        return computer;
    }
};

int main() {
    try {
        ComputerBuilder builder;

        builder.setCPU("Intel Core i9");
        builder.setGPU("NVIDIA GeForce RTX 3080");
        builder.setRAM(32);
        builder.setStorage(1024);

        Computer computer = builder.build();

        std::cout << "CPU: " << computer.getCPU() << '\n';
        std::cout << "GPU: " << computer.getGPU() << '\n';
        std::cout << "RAM: " << computer.getRAM() << " GB\n";
        std::cout << "Storage: " << computer.getStorage() << " GB\n";
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Configuration error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
