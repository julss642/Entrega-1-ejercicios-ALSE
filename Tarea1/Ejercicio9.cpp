#include <iostream>

// Función para calcular el MCD usando el algoritmo de Euclides
int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b; // Guardar el valor de b en una variable temporal
        b = a % b;    // Asignar a b el residuo de a dividido por b
        a = temp;     // Asignar a a el valor original de b
    }
    return a; // Cuando b es 0, a contiene el MCD
}

int main() {
    int a[2]; // Arreglo para almacenar los dos números ingresados por el usuario
    for (int i = 0; i < 2; i++) {
        std::cout << "Ingrese un número entero: ";
        std::cin >> a[i]; // Leer un número entero desde la entrada estándar
    }

    int mcd = calcularMCD(a[0], a[1]); // Calcular el MCD de los dos números
    std::cout << "El MCD de " << a[0] << " y " << a[1] << " es: " << mcd << std::endl; // Imprimir el resultado

    return 0; // Indicar que el programa terminó correctamente
}