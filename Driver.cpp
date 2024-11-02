//Authors: Noah Casaletta and Noah Davis
//Date: November 1, 2024
#include "Vehicle.h"
#include "Storage.h"
#include "LinkedList.h"
#include "ParkingLotManager.h"
#include "ParkingGarage.h"
#include "SmartPointer.h"
#include <iostream>

using namespace std;

// Displays the user menu
void displayMenu() 
{
    cout << "\n--- Parking Lot Manager ---\n";
    cout << "1. Add a vehicle to a lot\n";
    cout << "2. Remove a vehicle from a lot\n";
    cout << "3. Display all vehicles in a lot\n";
    cout << "4. Display all parking lots\n";
    cout << "5. Display parking garage\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}


int main()
{
    ParkingLotManager manager; // Parking lot manager instance
    Storage<Vehicle> lot1;     // Example storage lot
    bool running = true;       // Program loop control

    // Main program loop
    while (running) 
    {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: 
        {
            // Adding a vehicle to a lot
            string license, make, model;
            cout << "Enter vehicle license plate: ";
            cin >> license;
            cout << "Enter vehicle make: ";
            cin >> make;
            cout << "Enter vehicle model: ";
            cin >> model;
            Vehicle newVehicle(license, make, model);
            lot1.addVehicle(newVehicle);
            manager.addParkingLot(lot1);
            cout << "Vehicle added.\n";
            break;
        }
        case 2: 
        {
            // Removing a vehicle from a lot
            string license;
            cout << "Enter the license plate of the vehicle to remove: ";
            cin >> license;
            Vehicle vehicleToRemove(license, "", "");
            lot1.removeVehicle(vehicleToRemove);
            cout << "Vehicle removed.\n";
            break;
        }
        case 3:
            // Displaying all vehicles in a lot
            cout << "Displaying all vehicles in the lot:\n";
            lot1.displayVehicles();
            break;
        case 4:
            // Displaying all parking lots
            cout << "Displaying all parking lots:\n";
            manager.displayParkingLots();
            break;
        case 5:
            // Displaying the parking garage
            cout << "Displaying parking garage:\n";
            manager.displayParkingGarage();
            break;
        case 6:
            // Exiting the program
            running = false;
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}