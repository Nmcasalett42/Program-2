#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string licensePlate;
    string make;
    string model;

public:
    // Constructors
    Vehicle() = default;
    Vehicle(string license, string make, string model);

    // Getter methods
    string getLicensePlate() const;
    string getMake() const;
    string getModel() const;

    // Operator overloads
    bool operator<(const Vehicle& other) const;
    bool operator>(const Vehicle& other) const;
    bool operator==(const Vehicle& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v) 
    {
        os << "Vehicle License Plate: " << v.licensePlate << ", Make: " << v.make << ", Model: " << v.model << "]";
        return os;
    }
};
