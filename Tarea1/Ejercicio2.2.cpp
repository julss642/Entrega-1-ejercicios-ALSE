#include <iostream>

int main() {
    int a; // Variable para almacenar el número ingresado por el usuario

    // Solicitar al usuario que ingrese un número entero
    std::cout << "Ingrese un número entero: ";
    std::cin >> a; // Leer el número ingresado desde la entrada estándar

    // Verificar si el número es par y positivo
    if (a % 2 == 0 && a > 0) {
        std::cout << "El número es par y positivo." << std::endl; // Imprimir si el número es par y positivo
    } else {
        std::cout << "El número no es par y positivo." << std::endl; // Imprimir si el número no es par y positivo
    }

    return 0; // Indicar que el programa terminó correctamente
}