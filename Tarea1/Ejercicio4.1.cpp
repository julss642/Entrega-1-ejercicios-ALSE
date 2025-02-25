#include <iostream>
int main() {
    int a[5];
    for (int i = 0; i < 5; i++){
        std::cout << "Ingrese un número entero: ";
        std::cin >> a[i];
    }
    int suma = 0;
    for (int i = 0; i < 5; i++){
        suma += a[i];
    }
    bool esPar = suma%2 == 0;
    bool esPositivo = suma > 0;

    std::cout << "La suma de los números ingresados es: " << suma << std::endl;
    std::cout << (esPar? "Es par" : "No es par") << std::endl;
    std::cout << (esPositivo? "Es positivo" : "No es positivo") << std::endl;
    return 0;
}
