#ifndef PARKINGLOTMANAGER_H
#define PARKINGLOTMANAGER_H

#include "LinkedList.h"
#include "Storage.h"
#include "ParkingGarage.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

class ParkingLotManager {
private:
    LinkedList<Storage<Vehicle>> parkingLots;
    ParkingGarage parkingGarage;

public:
    //adds lot to the manager and garage
    void addParkingLot(const Storage<Vehicle>& lot) {
        parkingLots.insert(lot);
        parkingGarage.addParkingLot(lot);
    }

    //removes lot from manager and garage
    void removeParkingLot(const Storage<Vehicle>& lot) {
        parkingLots.remove(lot);
        parkingGarage.removeParkingLot(lot);
    }

    //shows all lots managed by manager
    void displayParkingLots() const {
        cout << "Displaying all parking lots:" << endl;
        parkingLots.display();
    }

    //shows all lots in garage
    void displayParkingGarage() const {
        parkingGarage.displayGarage();
    }
};
#endif