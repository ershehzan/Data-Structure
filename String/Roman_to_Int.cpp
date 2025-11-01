#include <iostream>  // Include the input-output stream library
#include <string>    // Include the string library for handling strings
using namespace std; // Use the standard namespace to simplify code

// Class to provide a solution for converting Roman numerals to integers
class Solution{
public:
    // Helper function to map a Roman numeral character to its integer value
    // Parameters:
    // c - a Roman numeral character (e.g., 'I', 'V', 'X', etc.)
    // Returns: the integer value corresponding to the Roman numeral
    int nums(char c) {
        if (c == 'I')
            return 1; // 'I' represents 1
        else if (c == 'V')
            return 5; // 'V' represents 5
        else if (c == 'X')
            return 10; // 'X' represents 10
        else if (c == 'L')
            return 50; // 'L' represents 50
        else if (c == 'C')
            return 100; // 'C' represents 100
        else if (c == 'D')
            return 500; // 'D' represents 500
        else
            return 1000; // 'M' represents 1000
    }

    // Function to convert a Roman numeral string to its integer value
    // Parameters:
    // s - the Roman numeral string (e.g., "IX", "XLII", etc.)
    // Returns: the integer value corresponding to the Roman numeral
    int romanToInt(string s) {
        
        if (s.empty())
            return 0; // Return 0 for empty input to avoid out-of-bounds access

        int sum = 0;   // Variable to store the resulting integer value
        int index = 0; // Index to traverse the Roman numeral string

        // Process each character in the string except the last one
        while (index < s.size() - 1) {
            // If the current numeral is smaller than the next numeral,
            // subtract its value from the sum (e.g., "IV" -> 4)
            if (nums(s[index]) < nums(s[index + 1]))
                sum -= nums(s[index]);
            else
                // Otherwise, add its value to the sum
                sum += nums(s[index]);

            // Move to the next character in the string
            index++;
        }

        // Add the value of the last numeral to the sum
        sum += nums(s[index]);

        // Return the resulting integer value
        return sum;
    }
};

int main()
{
    Solution solution;   // Create an instance of the Solution class
    string romanNumeral; // Variable to store the user-input Roman numeral

    // Prompt the user to enter a Roman numeral
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral; // Read the Roman numeral from the user

    // Convert the Roman numeral to its integer value
    int result = solution.romanToInt(romanNumeral);

    // Display the resulting integer value
    cout << "The integer value is: " << result << endl;

    return 0; // End of the program
}
