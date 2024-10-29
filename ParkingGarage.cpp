#include "ParkingGarage.h"
#include <iostream>

void ParkingGarage::addVehicleToLot(const Vehicle& vehicle) {
    if (parkingLots.isEmpty()) {
        Storage<Vehicle> newLot;
        newLot.addVehicle(vehicle);
        parkingLots.insert(newLot);
    } else {
        // Add vehicle to the first lot for simplicity
        parkingLots.getHead()->data.addVehicle(vehicle);
    }
}

void ParkingGarage::removeVehicleFromLot(const Vehicle& vehicle) {
    ListNode<Storage<Vehicle>>* lotNode = parkingLots.getHead();
    while (lotNode != nullptr) {
        lotNode->data.removeVehicle(vehicle);
        lotNode = lotNode->next;
    }
}

void ParkingGarage::displayGarage() const {
    ListNode<Storage<Vehicle>>* lotNode = parkingLots.getHead();
    int lotNumber = 1;
    while (lotNode != nullptr) {
        std::cout << "Parking Lot " << lotNumber << ":\n";
        lotNode->data.displayVehicles();
        lotNode = lotNode->next;
        lotNumber++;
    }
}
