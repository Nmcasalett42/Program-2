#ifndef STORAGE_H
#define STORAGE_H

#include "LinkedList.h"
#include "Vehicle.h"
#include <iostream>

template <typename T>
class Storage {
private:
    LinkedList<T> vehicles;

public:
    //add vehicle to storage
    void addVehicle(const T& vehicle) { vehicles.insert(vehicle); }

    //remove from storage
    void removeVehicle(const T& vehicle) { vehicles.remove(vehicle); }

    //show whats in storage
    void displayVehicles() const { vehicles.display(); }

    //checks if storage is empty
    bool isEmpty() const { return vehicles.getSize() == 0; }

    LinkedList<T>& getLinkedList() { return vehicles; }

    //overloads the output stream operator for storage
    friend ostream& operator<<(ostream& os, const Storage<T>& storage) 
    {
        os << "Storage contains:\n";
        storage.vehicles.display();
        return os;
    }
};
#endif