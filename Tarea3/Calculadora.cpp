#include <iostream>
#include <stdexcept> // Para std::invalid_argument
#include <cstdlib>   // Para std::stod
using namespace std;

float suma(int a, int b) {
    return a + b;
}
float resta(int a, int b) {
    return a - b;
}
float multiplicacion(int a, int b) {
    return a * b;
}
float division(int a, int b) {
    return a / b;
}

typedef float (*CallbackFuntion)(int, int);

float ejecutarCallback(CallbackFuntion funcion, int a, int b) {
    return funcion(a, b);
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <num1> <operacion> <num2>" << endl;
        return 1;
    }

    int a, b;
    char operacion;

    try {
        a = stoi(argv[1]);
        operacion = argv[2][0];
        b = stoi(argv[3]);

        cout << "a: " << a << " b: " << b << " operacion: " << operacion << endl;
    } catch (const std::exception& e) {
        cout << "Error al leer los datos, ingreselos de la forma (a operacion b)" << endl;
        cout << "Error: " << e.what() << endl;
        cout << "Ingrese a y b como numeros enteros y operacion como un caracter" << endl;
        return 1;
    }

    CallbackFuntion funcion = nullptr;
    string nombreFuncion[2] = {"", ""};
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
            cout << "No se puede dividir por 0" << endl;
            return 1;
        }
        funcion = division;
        nombreFuncion[0] = "division";
        nombreFuncion[1] = "/";
        break;

    default:
        cout << "Operacion no valida, ingreselo de la forma (a operacion b)" << endl;
        return 1;
    }

    cout << "La " << nombreFuncion[0] << " de " << a << " " << nombreFuncion[1] << " " << b << " es: " << ejecutarCallback(funcion, a, b) << endl;
    return 0;
}