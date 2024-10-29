#include <iostream>
#include "ParkingGarage.h"
#include "Vehicle.h"

using namespace std;

int main(){
    ParkingGarage garage;
    int choice;
    string license, make, model;

    cout << "Hello, and welcome to the Parking lot! \n";
    cout << "What would you like to do today? \n";

    do{
        cout << "1. Add a vehicle to the lot\n";
        cout << "2. Remove a vehicle from the parking lot\n";
        cout << "3. Display all vehicles in the parking lot\n";
        cout << "4. Exit the lot\n";
        cin >> choice;

        switch(choice){
            case 1: {
                cout << "Enter the license plate of the car: ";
                cin >> license;
                cout << "Enter the make of the car: ";
                cin >> make;
                cout << "Enter the model of the car: ";
                cin >> model;

                Vehicle newVehicle(license, make, model);
                garage.addVehicleToLot(newVehicle);

                cout << "Vehicle added to a parking lot.\n";
                break;
            }

            case 2: {
                cout << "Enter license plate of vehicle to remove: ";
                cin >> license;

                Vehicle tempVehicle(license, "", "");
                garage.removeVehicleFromLot(tempVehicle);

                cout << "Vehicle removed from a parking lot.\n";
                break;
            }

            case 3: {
                garage.displayGarage();
                break;
            }

            case 4: {
                cout << "Leaving the Parking Lot, Goodbye.";
                break;
            }

            default: {
                cout <<"That is not a valid choice, please pick again. \n";
                break;
            }

        }
    } while (choice != 4);

    return 0;
    
}