
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

    int countOverstayingVehicles(int maxParkingDuration) {
        int count = 0;
        for (auto vehicle : vehicles) {
            if (vehicle->getParkingDuration() > maxParkingDuration) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    ParkingLot lot(10);

    lot.parkVehicle(new Car(1));
    lot.parkVehicle(new Bus(2));
    lot.parkVehicle(new Motorbike(3));

    int overstayedThreshold = 15; // Example threshold
    std::cout << "Overstayed vehicles: " << lot.countOverstayingVehicles(overstayedThreshold) << std::endl;

    return 0;
}
