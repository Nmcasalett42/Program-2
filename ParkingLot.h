#include "LinkedList.h"
#include "Vehicle.h"

template <typename T>
class Storage {
private:
    LinkedList<T> vehicles;

public:
    void addVehicle(const T& vehicle) {
        vehicles.insert(vehicle);
    }

    void removeVehicle(const T& vehicle) {
        vehicles.remove(vehicle);
    }

    void displayVehicles() const {
        vehicles.display();
    }
};
