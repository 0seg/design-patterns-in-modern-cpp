
#include <iostream>
#include <memory>

// Product
class Transport {
public:
    virtual void deliver() const = 0;
    virtual ~Transport() = default;
};

// Concrete Products
class Truck : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by truck.\n";
    }
};

class Ship : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by ship.\n";
    }
};

// Creator
class Logistics {
public:
    virtual std::unique_ptr<Transport> createTransport() const = 0;

    void planDelivery() const {
        auto transport = createTransport();
        transport->deliver();
    }

    virtual ~Logistics() = default;
};

// Concrete Creators
class RoadLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

int main() {
    RoadLogistics roadLogistics;
    SeaLogistics seaLogistics;

    roadLogistics.planDelivery();
    seaLogistics.planDelivery();

    return 0;
}
