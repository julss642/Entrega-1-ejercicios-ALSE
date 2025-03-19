#include <iostream>
#include <vector>
using namespace std;

// Definición de la clase Solution
class Solution {
public:
    // Método que busca dos números en el vector cuya suma sea igual al objetivo
    vector<int> twoSum(vector<int>& nums, int target) {
        int const longitud = nums.size(); // Obtener la longitud del vector
        // Se utilizan dos bucles anidados para evaluar todas las combinaciones posibles
        for(int i = 0; i < longitud - 1; i++){
            for (int j = i + 1; j < longitud; j++){
                // Se verifica si la suma de los valores en las posiciones i y j es igual al objetivo
                if (nums[i] + nums[j] == target){
                    // Si se encuentra una combinación válida, se devuelven los índices correspondientes
                    return {i, j};
                }
            }
        }
        // Si no se encuentra ninguna pareja de números que sumen el objetivo, se retorna un vector vacío
        return {};
    }
};

int main(int, char **)
{
    Solution mySol; // Crear una instancia de la clase Solution
    vector<int> myVec = {0, 1, 5, 2, 3, 4, 6, 8}; // Se define un vector de enteros
    vector<int> result = mySol.twoSum(myVec, 5); // Se llama al método twoSum con el vector y el objetivo

    // Se verifica si el método retornó una solución válida
    if (!result.empty()) {
        // Si se encontró una solución, se imprimen los índices de los números que cumplen la condición
        cout << "Indices: " << result[0] << ", " << result[1] << "\n";
    } else {
        // Si no se encontró una solución, se imprime un mensaje
        cout << "No solution found\n";
    }

    return 0; // Finaliza la ejecución del programa
}