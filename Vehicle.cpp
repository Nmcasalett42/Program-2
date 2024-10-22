#include "Vehicle.h"

// Constructor
Vehicle::Vehicle(string license, string make, string model)
    : licensePlate(license), make(make), model(model) {}

// Getters
string Vehicle::getLicensePlate() const { return licensePlate; }
string Vehicle::getMake() const { return make; }
string Vehicle::getModel() const { return model; }

// Operator overloads
bool Vehicle::operator<(const Vehicle& other) const {
    return licensePlate < other.licensePlate;
}

bool Vehicle::operator>(const Vehicle& other) const {
    return licensePlate > other.licensePlate;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return licensePlate == other.licensePlate;
}

ostream& operator<<(ostream& os, const Vehicle& v) {
    os << "Vehicle [License Plate: " << v.licensePlate << ", Make: " << v.make << ", Model: " << v.model << "]";
    return os;
}