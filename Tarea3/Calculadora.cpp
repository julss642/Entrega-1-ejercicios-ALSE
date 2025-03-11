#include <iostream>
using namespace std;

int suma(int a, int b) {
    return a + b;
}
int resta(int a, int b) {
    return a - b;
}
float multiplicacion(int a, int b) {
    return a * b;
}
float division(int a, int b) {
    return a / b;
}

int main(int argc, char const *argv[]) {
    int a = stod(argv[1]);
    int b = stod(argv[3]);
    char operacion = argv[2][0];
    try
    {
        cin >> a >> operacion >> b;
        if (cin.fail()) {
            throw invalid_argument("Entrada no valida");
        }

        cout << "a: " << a << " b: " << b << " operacion: " << operacion << endl;
    }
    catch(const std::exception& e)
    {

        cout << "Error al leer los datos, ingreselos de la forma (a operacion b)" << endl;
        cout << "Error: " << e.what() << endl;
        cout << "Ingrese a y b como numeros enteros y operacion como un caracter" << endl;
        return 1;
    }
    
    switch (operacion)
    {
    case '+':
        cout << "La suma de " << a << " + " << b << " es: " << suma(a, b) << endl;
        break;
    
    case '-':
        cout << "La resta de " << a << " - " << b << " es: " << resta(a, b) << endl;
        break;
    
    case '*':
        cout << "La multiplicacion de " << a << " * " << b << " es: " << multiplicacion(a, b) << endl;
        break;

    case '/':
        if (b == 0) {
            cout << "No se puede dividir por 0" << endl;
            return 1;
        }
        cout << "La division de " << a << " / " << b << " es: " << division(a, b) << endl;
        break;

    default:
        cout << "Operacion no valida, ingreselo de la forma (a operacion b)" << endl;
        return 1;
        break;
    }

    return 0;
}