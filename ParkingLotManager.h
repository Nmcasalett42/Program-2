#pragma once
#include "LinkedList.h"
#include "Storage.h"
#include "Vehicle.h"

class ParkingLotManager 
{
private:
    LinkedList<Storage<Vehicle >> parkingLots;
    LinkedList<LinkedList<Storage<Vehicle> >> parkingGarages;

public:
    // Add a new parking lot
    void addParkingLot(const Storage<Vehicle>& lot) { parkingLots.insert(lot); }

    // Remove an existing parking lot
    void removeParkingLot(const Storage<Vehicle>& lot) { parkingLots.remove(lot); }

    // Display all parking lots
    void displayParkingLots() const 
    {
        cout << "Displaying all parking lots:" << endl;
        parkingLots.display();
    }

    // Add a new parking garage
    void addParkingGarage(const LinkedList<Storage<Vehicle>>& garage) { parkingGarages.insert(garage); }

    // Remove a parking garage
    void removeParkingGarage(const LinkedList<Storage<Vehicle>>& garage) { parkingGarages.remove(garage); }

    // Display all parking garages
    void displayParkingGarages() const 
    {
        cout << "Displaying all parking garages:" << endl;
        parkingGarages.display();
    }
};