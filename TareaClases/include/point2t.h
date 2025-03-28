#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
using namespace std;

// Definición de la clase point2d
class point2d {
private:
    int x;  // Coordenada x (privada)
    int y;  // Coordenada y (privada)

public:
    // Constructores
    point2d(void); // Constructor por defecto
    point2d(int x = 0, int y = 0); // Constructor con parámetros (valores predeterminados: 0, 0)
    point2d(const point2d&); // Constructor de copia

    // Métodos Getter y Setter para acceder y modificar las coordenadas
    int getx() const; // Obtener el valor de x
    void setx(int x); // Establecer el valor de x
    int gety() const; // Obtener el valor de y
    void sety(int y); // Establecer el valor de y

    // Sobrecarga de operadores aritméticos
    point2d operator+(const point2d& other); // Suma de dos puntos
    point2d operator*(const float& other);   // Multiplicación por un escalar
    point2d operator/(const float& other);   // División por un escalar

    // Sobrecarga del operador de asignación
    point2d& operator=(const point2d& other); // Asignación entre objetos point2d

    // Sobrecarga de operadores de comparación
    friend int operator!=(const point2d& a, const point2d& b); // Comparación de desigualdad
    friend int operator==(const point2d& a, const point2d& b); // Comparación de igualdad

    // Sobrecarga del operador de inserción en el flujo de salida
    friend ostream& operator<<(ostream&, const point2d&); // Imprimir un punto en un flujo de salida

    // Métodos de la clase
    float distance(const point2d& other = point2d(0, 0)); // Calcular la distancia a otro punto (por defecto al origen)
    float distance(int x, int y); // Calcular la distancia a un punto dado por coordenadas
    point2d midpoint(const point2d& other = point2d(0, 0)); // Calcular el punto medio con otro punto (por defecto al origen)
    point2d midpoint(int x, int y); // Calcular el punto medio con un punto dado por coordenadas
    point2d unitary(); // Calcular el vector unitario del punto

    // Método para mostrar información del punto
    void display(string name); // Mostrar las coordenadas del punto con un nombre
};

#endif // POINT2D_H