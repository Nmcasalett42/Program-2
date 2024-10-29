#ifndef PARKINGGARAGE_H
#define PARKINGGARAGE_H

#include "ParkingLot.h"
#include "Vehicle.h"
#include "LinkedList.h"

class ParkingGarage {
private:
    LinkedList<Storage<Vehicle>> parkingLots; //A linked list of the parking lot
public:
    ParkingGarage() = default;

    void addVehicleToLot(const Vehicle& vehicle);
    void removeVehicleFromLot(const Vehicle& vehicle);
    void displayGarage() const;
};

#endif
