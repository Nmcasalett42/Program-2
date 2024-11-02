#ifndef PARKINGGARAGE_H
#define PARKINGGARAGE_H

#include "LinkedList.h"
#include "Storage.h"
#include "Vehicle.h"
#include <iostream>

class ParkingGarage 
{
private:
    LinkedList<Storage<Vehicle>> lots;

public:
    //adds parking lot to garage
    void addParkingLot(const Storage<Vehicle>& lot) { lots.insert(lot); }

    //shows all lots in garage
    void displayGarage() const 
    {
        cout << "Parking Garage contains the following lots:\n";
        lots.display();
    }

    //removes a parkinglot from garage
    void removeParkingLot(const Storage<Vehicle>& lot) { lots.remove(lot); }
};
#endif