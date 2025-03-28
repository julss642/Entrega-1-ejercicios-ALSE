#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numDoors;
    int numWheels;

public:
    // Constructor
    Car(string b, int s, int doors, int wheels = 4);
    // Destructor
    ~Car();
    // Getter & Setter
    int getNumDoors() const;
    void setNumDoors(int doors);
    int getNumWheels() const;
    void setNumWheels(int wheels);

    // Override display method
    void display() const override;
};

#endif // CAR_H
