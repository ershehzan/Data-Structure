#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Solution class to perform addition of two large numbers represented as strings
class Solution
{
public:
    // Helper function to add two numeric strings where num1 is guaranteed to be at least as long as num2
    string add(string num1, string num2)
    {
        string ans; // To store the result (in reverse order)
        int index1 = num1.size() - 1, index2 = num2.size() - 1; // Start from the end of both strings
        int sum, carry = 0;

        // Add digits from both strings as long as num2 has digits left
        while (index2 >= 0)
        {
            // Convert char digits to integers, add them along with carry
            sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            carry = sum / 10; // Calculate new carry
            char c = '0' + sum % 10; // Get the digit to append to result
            ans += c;
            index1--, index2--;
        }
        // If num1 is longer, continue adding remaining digits of num1 with carry
        while (index1 >= 0)
        {
            sum = (num1[index1] - '0') + carry;
            carry = sum / 10;
            char c = '0' + sum % 10;
            ans += c;
            index1--;
        }
        // If there's a remaining carry, append it
        if (carry)
            ans += '1';
        // The result is in reverse order, so reverse it before returning
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Main function to add two strings, always calls add() with the larger string first
    string addStrings(string num1, string num2)
    {
        // Ensure the first argument is not shorter than the second
        if (num1.size() < num2.size())
            return add(num2, num1);
        else
            return add(num1, num2);
    }
};

int main()
{
    Solution solution;
    string num1, num2;

    // Prompt user for the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Prompt user for the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Call the addStrings function to compute the sum
    string result = solution.addStrings(num1, num2);
    cout << "The sum of the two numbers is: " << result << endl;

    return 0;
}
