#ifndef AIR_VEHICLE_H
#define AIR_VEHICLE_H

#include "Vehicle.h"

class AirVehicle : public Vehicle {
private:
    int altitude;  // Altitude in meters
    bool isMultirotor;   // Type of air vehicle

public:
    // Constructor
    AirVehicle(string b, int s, int alt);

    // Override display method
    void display() const override;
};

#endif // AIR_VEHICLE_H
