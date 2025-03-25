#include <iostream>
#include <vector>
using namespace std;

// Clase que contiene la solución para validar un tablero de Sudoku
class Solution {
    public:
        // Método que verifica si un tablero de Sudoku es válido
        bool isValidSudoku(vector<vector<char>>& board) {
            // Vectores para rastrear los números usados en filas, columnas y cajas 3x3
            vector<vector<bool>> rows(9, vector<bool>(9, false));
            vector<vector<bool>> cols(9, vector<bool>(9, false));
            vector<vector<bool>> boxes(9, vector<bool>(9, false));
            
            // Recorre cada celda del tablero
            for (int i = 0; i < 9; i++) {   
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') { // Si la celda no está vacía
                        int num = board[i][j] - '0' - 1; // Convierte el carácter a un índice (0-8)
                        int k = i / 3 * 3 + j / 3; // Calcula el índice de la caja 3x3
                        
                        // Verifica si el número ya está en la fila, columna o caja
                        if (rows[i][num] || cols[j][num] || boxes[k][num]) {
                            return false; // Si ya está, el tablero no es válido
                        }
                        
                        // Marca el número como usado en la fila, columna y caja
                        rows[i][num] = cols[j][num] = boxes[k][num] = true;
                    }
                }
            }
            return true; // Si pasa todas las verificaciones, el tablero es válido
        }
};

int main(int, char **)
{
    Solution mySol; // Crear una instancia de la clase Solution
    
    // Tablero de Sudoku de ejemplo
    vector<vector<char>> board = {
        {'5','3','.','1','7','2','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    // Llama al método isValidSudoku y muestra el resultado
    cout << mySol.isValidSudoku(board) << endl;
    
    return 0; // Retorna 0 indicando que el programa terminó correctamente
}