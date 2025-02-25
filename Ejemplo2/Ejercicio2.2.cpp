#include <iostream>
int main() {
    int a;
    std::cout << "Ingrese un número entero: ";
    std::cin >> a;
    if (a%2 == 0 && a > 0){
        std::cout << "El número es par y positivo." << std::endl;
    } else {
        std::cout << "El número no es par y positivo." << std::endl;
    }
}