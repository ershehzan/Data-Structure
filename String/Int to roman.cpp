#include <iostream>
#include <string>
#include <vector>
using namespace std;

<<<<<<< HEAD
// Class to provide a solution for converting an integer to a Roman numeral
class Solution {
public:
    /*
    Function: intToRoman
    Converts an integer to its Roman numeral representation.
    Parameters:
        - int num: The integer to be converted (assumes 1 <= num <= 3999).
    Returns:
        - A string representing the Roman numeral equivalent of the input integer.
    */
    string intToRoman(int num) {
        // Predefined values and their corresponding Roman numeral symbols.
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = ""; // Resultant Roman numeral string
        
        // Iterate through each value-symbol pair
        for (size_t i = 0; i < values.size(); i++) {
            // While the input number is greater than or equal to the current value,
            // append the corresponding Roman numeral symbol and reduce the number.
            while (num >= values[i]) {
                result += symbols[i]; // Append the Roman numeral symbol
                num -= values[i];     // Subtract the value from the number
            }
        }
        
        return result; // Return the final Roman numeral string
=======
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        for (size_t i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
>>>>>>> 549b0d8 (file update)
    }
};

int main() {
<<<<<<< HEAD
    Solution solution; // Create an instance of the Solution class
    int num;           // Variable to store the user input

    // Prompt the user to enter an integer
    cout << "Enter an integer: ";
    cin >> num;

    // Convert the integer to its Roman numeral equivalent
    string roman = solution.intToRoman(num);

    // Display the result
    cout << "Roman numeral: " << roman << endl;

    return 0; // Exit the program
}
=======
    Solution solution;
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    string roman = solution.intToRoman(num);
    cout << "Roman numeral: " << roman << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)
