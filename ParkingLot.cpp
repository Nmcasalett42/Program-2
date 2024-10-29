#include "ParkingLot.h"
#include <iostream>

template <typename T>
void Storage<T>::addVehicle(const T& vehicle) {
    vehicles.insert(vehicle);
}

template <typename T>
void Storage<T>::removeVehicle(const T& vehicle) {
    vehicles.remove(vehicle);
}

template <typename T>
void Storage<T>::displayVehicles() const {
    std::cout << "Vehicles in this lot:" << std::endl;
    vehicles.display();
}

// Explicit template instantiation to avoid link errors
template class Storage<Vehicle>;
