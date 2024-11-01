#pragma once
#include "LinkedList.h"
#include "Vehicle.h"

using namespace std;

template <typename T>
class Storage 
{
private:
    LinkedList<T> vehicles;

public:
    void addVehicle(const T& vehicle) { vehicles.insert(vehicle); }
    void removeVehicle(const T& vehicle) { vehicles.remove(vehicle); }
    void displayVehicles() const { vehicles.display(); }
    bool isEmpty() const { return vehicles.isEmpty(); }

    // Provide access to the underlying LinkedList for sorting
    LinkedList<T>& getLinkedList() { return vehicles; }
};