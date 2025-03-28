#include <iostream>
#include "src/point2d.cpp" // Incluir la implementación de la clase point2d
using namespace std;

int main() {
    // Crear dos objetos point2d con coordenadas iniciales
    point2d P1(3, 4), P2(1, 2);

    // Mostrar las coordenadas de P1 y P2
    P1.display("P1"); // Imprime: P1(3, 4)
    P2.display("P2"); // Imprime: P2(1, 2)

    // Multiplicar P1 por un escalar (10) y mostrar el resultado
    P1 = P1 * 10;
    cout << "P1 * 10 = " << P1 << endl; // Imprime: P1 * 10 = (30, 40)

    // Dividir P1 por un escalar (10) y mostrar el resultado
    P1 = P1 / 10;
    cout << "P1 / 10 = " << P1 << endl; // Imprime: P1 / 10 = (3, 4)

    // Sumar P1 y P2, almacenar el resultado en P3, y mostrarlo
    point2d P3 = P1 + P2;
    cout << "P1 + P2 = " << P3 << endl; // Imprime: P1 + P2 = (4, 6)

    // Comparar si P1 y P2 son iguales
    cout << "P1 == P2: " << (P1 == P2) << endl; // Imprime: P1 == P2: 0 (falso)

    // Comparar si P1 y P2 son diferentes
    cout << "P1 != P2: " << (P1 != P2) << endl; // Imprime: P1 != P2: 1 (verdadero)

    // Calcular la distancia entre P1 y P2
    cout << "P1.distance(P2): " << P1.distance(P2) << endl; // Imprime la distancia entre P1 y P2

    // Calcular la distancia entre P1 y las coordenadas de P3
    cout << "P1.distance(P3.x, P3.y): " << P1.distance(P3.getx(), P3.gety()) << endl; // Imprime la distancia entre P1 y P3

    // Calcular el punto medio entre P1 y P2
    cout << "P1.midpoint(P2): " << P1.midpoint(P2) << endl; // Imprime el punto medio entre P1 y P2

    // Calcular el punto medio entre P1 y las coordenadas de P3
    cout << "P1.midpoint(P3.x, P3.y): " << P1.midpoint(P3.getx(), P3.gety()) << endl; // Imprime el punto medio entre P1 y P3

    // Calcular el vector unitario de P1
    cout << "P1.unitary(): " << P1.unitary() << endl; // Imprime el vector unitario de P1

    return 0; // Finalizar el programa
}