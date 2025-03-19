#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            
            int total = digit1 + digit2 + carry;
            carry = total / 10;
            result.insert(result.begin(), (total % 10) + '0');
            
            i--;
            j--;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "456";
    string num2 = "77";
    cout << solution.addStrings(num1, num2) << endl; // Salida esperada: "533"
    return 0;
}