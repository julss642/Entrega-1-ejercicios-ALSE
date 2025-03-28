#ifndef CUBE_H
#define CUBE_H
#include <string>
using namespace std;
class Cube {
private:
    double length; // Private attribute

public:
    string colour;
    // Constructor
    Cube(double l = 1.0); 

    // Getter and Setter
    double getLength() const;
    void setLength(double l);

    // Methods to calculate volume and surface area
    double getVolume() const;
    double getSurfaceArea() const;
};

#endif // CUBE_H
