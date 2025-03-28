#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;  // Protected: Accessible by derived classes
    int speed;     // Private: Cannot be accessed directly by derived classes

public:
    // Constructor
    Vehicle(string b, int s);
    Vehicle(string b);

    // Virtual Destructor (important for polymorphism)
    //virtual ~Vehicle();

    // Getter & Setter
    int getSpeed() const;
    void setSpeed(int s);

    // Virtual method for displaying info
    virtual void display() const;
};

#endif // VEHICLE_H
