#include <iostream>
#include <vector>
using namespace std;

// Definición de la clase Solution
class Solution {
public:
    // Método para encontrar dos números en el vector que sumen el objetivo
    vector<int> twoSum(vector<int>& nums, int target) {
        int const longitud = nums.size(); // Obtener la longitud del vector
        // Bucle anidado para comprobar todas las combinaciones de dos números
        for(int i = 0; i < longitud - 1; i++){
            for (int j = i + 1; j < longitud; j++){
                // Si la suma de nums[i] y nums[j] es igual al objetivo, devolver los índices
                if (nums[i] + nums[j] == target){
                    //Retorno de los indices que cumplen con la condición
                    return {i, j};
                }
            }
        }
        // Si no se encuentra ninguna combinación, devolver un vector vacío
        return {};
    }
};

int main(int, char **)
{
    Solution mySol; // Crear una instancia de la clase Solution
    vector<int> myVec = {0, 1, 5, 2, 3, 4, 6, 8}; // Definir un vector de enteros
    vector<int> result = mySol.twoSum(myVec, 5); // Llamar al método twoSum con el vector y el objetivo

    // Comprobar si se encontró una solución
    if (!result.empty()) {
        // Si se encontró una solución, imprimir los índices
        cout << "Indices: " << result[0] << ", " << result[1] << "\n";
    } else {
        // Si no se encontró una solución, imprimir un mensaje
        cout << "No solution found\n";
    }

    return 0; // Finalizar el programa
}