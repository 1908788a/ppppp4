
#include <iostream>
#include <vector>

class ParkingLot {
    std::vector<Vehicle*> vehicles;
    int capacity;

public:
    ParkingLot(int cap) : capacity(cap) {}

    ~ParkingLot() {
        for (auto vehicle : vehicles) {
            delete vehicle;
        }
    }

    bool parkVehicle(Vehicle* v) {
        if (vehicles.size() < capacity) {
            vehicles.push_back(v);
            return true;
        } else {
            std::cout << "The lot is full!" << std::endl;
            return false;
        }
    }

    void unparkVehicle(int id) {
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if ((*it)->getID() == id) {
                delete *it;
                vehicles.erase(it);
                return;
            }
        }
        std::cout << "Vehicle not in the lot" << std::endl;
    }
};

// Sample usage of ParkingLot class within the main function
int main() {
    ParkingLot lot(10);

    lot.parkVehicle(new Car(1));
    lot.parkVehicle(new Bus(2));
    lot.parkVehicle(new Motorbike(3));

    lot.unparkVehicle(2); // Unpark the bus

    return 0;
}
