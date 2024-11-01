//Authors: Noah Casaletta and Noah Davis
//Date: November 1, 2024


#include "Vehicle.h"
#include "Storage.h"
#include "LinkedList.h"
#include "ParkingLotManager.h"
#include "SmartPointer.h"

using namespace std;

int main() 
{
    ParkingLotManager manager;

    // Create vehicles
    Vehicle car1("ABC123", "Toyota", "Camry");
    Vehicle car2("XYZ789", "Honda", "Civic");
    Vehicle car3("LMN456", "Ford", "Focus");

    // Create storage lot and add vehicles
    Storage<Vehicle> lot1;
    lot1.addVehicle(car1);
    lot1.addVehicle(car2);
    lot1.addVehicle(car3);

    // Display unsorted vehicles
    cout << "Unsorted vehicles in Lot 1:" << endl;
    lot1.displayVehicles();

    // Sort vehicles by license plate in ascending order
    cout << "\nSorted vehicles in ascending order:" << endl;
    lot1.getLinkedList().sortAscending();
    lot1.displayVehicles();

    // Sort vehicles by license plate in descending order
    cout << "\nSorted vehicles in descending order:" << endl;
    lot1.getLinkedList().sortDescending();
    lot1.displayVehicles();

    // Custom sort by make and model
    cout << "\nCustom sorted vehicles (by make):" << endl;
    lot1.getLinkedList().sortCustom([](const Vehicle& a, const Vehicle& b) 
    {
        return a.getMake() < b.getMake();
    });
    lot1.displayVehicles();

    return 0;
}