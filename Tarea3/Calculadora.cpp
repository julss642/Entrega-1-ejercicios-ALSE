#include <iostream>
#include <stdexcept> // Para std::invalid_argument
#include <cstdlib>   // Para std::stod
using namespace std;

// Función para sumar dos números
float suma(int a, int b) {
    return a + b;
}

// Función para restar dos números
float resta(int a, int b) {
    return a - b;
}

// Función para multiplicar dos números
float multiplicacion(int a, int b) {
    return a * b;
}

// Función para dividir dos números
float division(int a, int b) {
    return a / b;
}

// Definición de un tipo de función callback
typedef float (*CallbackFuntion)(int, int);

// Función que ejecuta una función callback con dos parámetros
float ejecutarCallback(CallbackFuntion funcion, int a, int b) {
    return funcion(a, b);
}

int main(int argc, char const *argv[]) {
    // Verificar que se pasen exactamente 3 argumentos (num1, operacion, num2)
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <num1> <operacion> <num2>" << endl;
        return 1;
    }

    int a, b;
    char operacion;

    try {
        // Convertir los argumentos a enteros y operación
        a = stoi(argv[1]);
        operacion = argv[2][0];
        b = stoi(argv[3]);

        cout << "a: " << a << " b: " << b << " operacion: " << operacion << endl;
    } catch (const std::exception& e) {
        // Manejo de errores en caso de que los argumentos no sean válidos
        cout << "Error al leer los datos, ingreselos de la forma (a operacion b)" << endl;
        cout << "Error: " << e.what() << endl;
        cout << "Ingrese a y b como numeros enteros y operacion como un caracter" << endl;
        return 1;
    }

    CallbackFuntion funcion = nullptr;
    string nombreFuncion[2] = {"", ""};

    // Seleccionar la función adecuada según la operación
    switch (operacion) {
    case '+':
        funcion = suma;
        nombreFuncion[0] = "suma";
        nombreFuncion[1] = "+";
        break;
    
    case '-':
        funcion = resta;
        nombreFuncion[0] = "resta";
        nombreFuncion[1] = "-";
        break;
    
    case '*':
        funcion = multiplicacion;
        nombreFuncion[0] = "multiplicacion";
        nombreFuncion[1] = "*";
        break;

    case '/':
        if (b == 0) {
            // Verificar división por cero
            cout << "No se puede dividir por 0" << endl;
            return 1;
        }
        funcion = division;
        nombreFuncion[0] = "division";
        nombreFuncion[1] = "/";
        break;

    default:
        // Manejo de operación no válida
        cout << "Operacion no valida, ingreselo de la forma (a operacion b)" << endl;
        return 1;
    }

    // Ejecutar la función seleccionada y mostrar el resultado
    cout << "La " << nombreFuncion[0] << " de " << a << " " << nombreFuncion[1] << " " << b << " es: " << ejecutarCallback(funcion, a, b) << endl;
    return 0;
}