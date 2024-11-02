#include "Vehicle.h"

using namespace std;

//constructor for Vehicle Class...PARAMETERIZED
Vehicle::Vehicle(string license, string make, string model)
    : licensePlate(license), make(make), model(model) {}