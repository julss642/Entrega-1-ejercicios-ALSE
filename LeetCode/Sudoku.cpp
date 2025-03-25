#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<vector<bool>> rows(9, vector<bool>(9, false));
            vector<vector<bool>> cols(9, vector<bool>(9, false));
            vector<vector<bool>> boxes(9, vector<bool>(9, false));
            
            for (int i = 0; i < 9; i++) {   
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '0' - 1;
                        int k = i / 3 * 3 + j / 3;
                        if (rows[i][num] || cols[j][num] || boxes[k][num]) {
                            return false;
                        }
                        rows[i][num] = cols[j][num] = boxes[k][num] = true;
                    }
                }
            }
            return true;
            
        }
};
int main(int, char **)
{
    Solution mySol; // Crear una instancia de la clase Solution
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << mySol.isValidSudoku(board) << endl;
    return 0; // Retorna 0 indicando que el programa terminó correctamente
    
}