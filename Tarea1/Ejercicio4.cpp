#include <iostream>

int main() {
    int a[5]; // Arreglo para almacenar los cinco números ingresados por el usuario

    // Leer cinco números enteros desde la entrada estándar
    for (int i = 0; i < 5; i++) {
        std::cout << "Ingrese un número entero: ";
        std::cin >> a[i];
    }

    int suma = 0; // Variable para almacenar la suma de los números

    // Calcular la suma de los números ingresados
    for (int i = 0; i < 5; i++) {
        suma += a[i];
    }

    // Determinar si la suma es par
    bool esPar = suma % 2 == 0;

    // Determinar si la suma es positiva
    bool esPositivo = suma > 0;

    // Imprimir la suma de los números ingresados
    std::cout << "La suma de los números ingresados es: " << suma << std::endl;

    // Imprimir si la suma es par o impar
    std::cout << (esPar ? "Es par" : "No es par") << std::endl;

    // Imprimir si la suma es positiva o negativa
    std::cout << (esPositivo ? "Es positivo" : "No es positivo") << std::endl;

    return 0; // Indicar que el programa terminó correctamente
}
