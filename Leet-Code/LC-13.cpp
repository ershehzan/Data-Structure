#include <iostream>
#include <string>
using namespace std;

// Solution class to convert Roman numerals to integers
class Solution {
public:
    // Helper function to return the integer value of a single Roman numeral character
    int nums(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else
            return 1000; // for 'M'
    }

    // Function to convert a Roman numeral string to an integer
    int romanToInt(string s) {
        int sum = 0, index = 0;

        // Traverse the string except the last character
        while (index < s.size() - 1) {
            // If the current character's value is less than the next character's value,
            // subtract it (handles cases like IV = 4, IX = 9, etc.)
            if (nums(s[index]) < nums(s[index + 1]))
                sum -= nums(s[index]);
            else
                // Otherwise, add its value to the sum
                sum += nums(s[index]);

            index++;
        }
        // Add the value of the last character
        sum += nums(s[index]);
        return sum;
    }
};

int main() {
    Solution solution;
    string romanNumeral;

    // Prompt user for input
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    // Convert the Roman numeral to an integer and display the result
    int result = solution.romanToInt(romanNumeral);
    cout << "The integer value is: " << result << endl;

    return 0;
}
