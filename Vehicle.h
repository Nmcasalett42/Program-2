#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string licensePlate;
    string make;
    string model;

public:
    Vehicle() = default;
    Vehicle(string license, string make, string model)
        : licensePlate(license), make(make), model(model) {}

    string getLicensePlate() const { return licensePlate; }
    string getMake() const { return make; }
    string getModel() const { return model; }

    bool operator<(const Vehicle& other) const { return licensePlate < other.licensePlate; }
    bool operator>(const Vehicle& other) const { return licensePlate > other.licensePlate; }
    bool operator==(const Vehicle& other) const { return licensePlate == other.licensePlate; }

    friend ostream& operator<<(ostream& os, const Vehicle& v) {
        os << "Vehicle [License Plate: " << v.licensePlate << ", Make: " << v.make << ", Model: " << v.model << "]";
        return os;
    }
};
