
#include <iostream>
#include <ctime>

class Vehicle {
protected:
    std::time_t timeOfEntry;
    int ID;

public:
    Vehicle(int id) : ID(id) {
        timeOfEntry = std::time(nullptr);
    }

    virtual ~Vehicle() {}

    int getID() const {
        return ID;
    }

    virtual int getParkingDuration() const {
        return static_cast<int>(std::difftime(std::time(nullptr), timeOfEntry));
    }
};

class Car : public Vehicle {
public:
    using Vehicle::Vehicle;

    int getParkingDuration() const override {
        return static_cast<int>(Vehicle::getParkingDuration() * 0.9); // 10% reduction
    }
};

class Bus : public Vehicle {
public:
    using Vehicle::Vehicle;

    int getParkingDuration() const override {
        return static_cast<int>(Vehicle::getParkingDuration() * 0.75); // 25% reduction
    }
};

class Motorbike : public Vehicle {
public:
    using Vehicle::Vehicle;

    int getParkingDuration() const override {
        return static_cast<int>(Vehicle::getParkingDuration() * 0.85); // 15% reduction
    }
};

int main() {
    Vehicle* car = new Car(1);
    Vehicle* bus = new Bus(2);
    Vehicle* motorbike = new Motorbike(3);

    std::cout << "Car ID: " << car->getID() << ", Parking Duration: " << car->getParkingDuration() << " seconds\n";
    std::cout << "Bus ID: " << bus->getID() << ", Parking Duration: " << bus->getParkingDuration() << " seconds\n";
    std::cout << "Motorbike ID: " << motorbike->getID() << ", Parking Duration: " << motorbike->getParkingDuration() << " seconds\n";

    delete car;
    delete bus;
    delete motorbike;

    return 0;
}
