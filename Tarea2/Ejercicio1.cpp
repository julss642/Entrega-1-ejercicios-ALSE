#include <iostream>
#include <vector>
#include <array>

int main() {
    std::vector<std::array<float, 2>> compras; // Vector para almacenar las compras
    std::array<float, 2> compra; // Arreglo para almacenar el precio individual de cada objeto y cuantos se compraron

    // Leer datos de varias compras
    char continuar;
    do {
        std::cout << "Ingrese el precio del objeto: ";
        std::cin >> compra[0]; // Leer el precio del objeto desde la entrada estándar
        std::cout << "Ingrese la cantidad de objetos comprados: ";
        std::cin >> compra[1]; // Leer la cantidad de objetos comprados desde la entrada estándar
        compras.push_back(compra); // Agregar la compra al vector

        std::cout << "¿Desea ingresar otra compra? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    float subtotal = 0; // Variable para almacenar el subtotal de las compras

    // Imprimir las compras ingresadas
    std::cout << "Compras ingresadas:" << std::endl;
    for (const auto& c : compras) {
        subtotal += c[0] * c[1]; // Calcular el subtotal sumando el precio de cada compra
    }
    std::cout << "SubTotal: " << subtotal << std::endl; // Imprimir el subtotal	
    float impuesto = subtotal*0.8; // Calcular el impuesto aplicando el 8% al subtotal
    std::cout << "Impuesto: " << impuesto << std::endl; // omitir el impuesto
    float total = subtotal + impuesto; // Calcular el total sumando el impuesto al subtotal
    std::cout << "Total: " << total << std::endl; // omitir el total
    if (total > 100) {
        std::cout << "Se aplicó un descuento del 10%." << std::endl; // Imprimir si se aplicó un descuento
        total *= 0.9; // Aplicar un descuento del 10% al total
        std::cout << "Total con descuento: " << total << std::endl; // omitir el total con descuento
    }
    return 0; // Indicar que el programa terminó correctamente
}