
#include <iostream>
#include <memory>

// Implementor
class Device {
public:
    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;
    virtual ~Device() = default;
};

// Concrete Implementors
class TV : public Device {
public:
    void turnOn() const override {
        std::cout << "TV is ON\n";
    }

    void turnOff() const override {
        std::cout << "TV is OFF\n";
    }
};

class Radio : public Device {
public:
    void turnOn() const override {
        std::cout << "Radio is ON\n";
    }

    void turnOff() const override {
        std::cout << "Radio is OFF\n";
    }
};

// Abstraction
class RemoteControl {
protected:
    std::unique_ptr<Device> device_;

public:
    explicit RemoteControl(std::unique_ptr<Device> device)
        : device_(std::move(device)) {}

    virtual void togglePower() const = 0;
    virtual ~RemoteControl() = default;
};

// Refined Abstractions
class BasicRemote : public RemoteControl {
public:
    using RemoteControl::RemoteControl;

    void togglePower() const override {
        device_->turnOn();
    }
};

class AdvancedRemote : public RemoteControl {
public:
    using RemoteControl::RemoteControl;

    void togglePower() const override {
        device_->turnOn();
        std::cout << "Advanced remote activated\n";
    }

    void turnOff() const {
        device_->turnOff();
    }
};

int main() {
    std::unique_ptr<RemoteControl> basicRemote =
        std::make_unique<BasicRemote>(
            std::make_unique<TV>()
        );

    std::unique_ptr<RemoteControl> advancedRemote =
        std::make_unique<AdvancedRemote>(
            std::make_unique<Radio>()
        );

    std::cout << "Basic Remote:\n";
    basicRemote->togglePower();

    std::cout << "\nAdvanced Remote:\n";
    advancedRemote->togglePower();

    return 0;
}
