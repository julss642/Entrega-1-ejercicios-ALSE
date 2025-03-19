#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Función para sumar dos números representados como cadenas
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1; // Índice para recorrer num1 desde el último dígito
        int j = num2.size() - 1; // Índice para recorrer num2 desde el último dígito
        int carry = 0; // Variable para almacenar el acarreo
        string res = ""; // Cadena donde se almacenará el resultado

        // Bucle mientras haya dígitos en num1, num2 o un acarreo pendiente
        while (i >= 0 || j >= 0 || carry) {
            long sum = 0; // Variable para almacenar la suma parcial

            // Si aún hay dígitos en num1, se suma el valor del dígito correspondiente
            if (i >= 0) {
                sum += (num1[i] - '0'); // Convierte el carácter a número
                i--; // Mueve el índice al siguiente dígito
            }

            // Si aún hay dígitos en num2, se suma el valor del dígito correspondiente
            if (j >= 0) {
                sum += (num2[j] - '0'); // Convierte el carácter a número
                j--; // Mueve el índice al siguiente dígito
            }

            sum += carry; // Agrega el acarreo acumulado
            carry = sum / 10; // Calcula el nuevo acarreo
            sum = sum % 10; // Obtiene el dígito de la unidad

            // Agrega el dígito al inicio de la cadena resultado
            res = to_string(sum) + res;
        }

        return res; // Devuelve la suma como cadena
    }
};

int main(int, char **) {
    Solution mySol; // Se crea una instancia de la clase Solution
    string num1 = "4205"; // Primer número como cadena
    string num2 = "456";  // Segundo número como cadena

    // Llama a la función y muestra el resultado en pantalla
    cout << mySol.addStrings(num1, num2) << endl;

    return 0; // Retorna 0 indicando que el programa terminó correctamente
}