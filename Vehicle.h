#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
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

    friend ostream& operator<<(ostream& os, const Vehicle& v)
    {
        os << "Vehicle License Plate: " << v.licensePlate << ", Make: " << v.make << ", Model: " << v.model << "]";
        return os;
    }
    //overload for output stream operator
    bool operator !=(const Vehicle& v)
    {
        if (this->licensePlate != v.licensePlate)
        {
            if (this->make != v.make)
            {
                if (this->model != v.model)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
            return false;
    }

    //overload for equality operator
    bool operator ==(const Vehicle& v)
    {
        if (this->licensePlate == v.licensePlate)
        {
            if (this->model == v.model)
            {
                if (this->make == v.make)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
            return false;
    }
};
#endif
