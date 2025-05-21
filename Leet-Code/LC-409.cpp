#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This class solves the problem of finding the length of the longest palindrome 
// that can be built with the letters of a given string.
class Solution
{
public:
    // Function to find the length of the longest possible palindrome
    int longestPalindrome(string s)
    {
        // Arrays to count the occurrences of each lowercase and uppercase letter
        vector<int> lower(26, 0); // For 'a' to 'z'
        vector<int> upper(26, 0); // For 'A' to 'Z'

        // Count the frequency of each character in the input string
        for (int i = 0; i < s.size(); i++)
        {
            // If the character is lowercase, increment the corresponding count
            if (s[i] >= 'a')
                lower[s[i] - 'a']++;
            else // Otherwise, it's uppercase; increment its count
                upper[s[i] - 'A']++;
        }

        int count = 0; // To store the length of the palindrome
        bool odd = 0;  // To check if there's at least one character with an odd count

        // Process lowercase letter counts
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] % 2 == 0) // If the count is even, use all occurrences
            {
                count += lower[i];
            }
            else // If the count is odd, use (count - 1) to keep it even
            {
                count += lower[i] - 1;
                odd = 1; // Mark that there's an odd occurrence (for possible center of the palindrome)
            }
        }

        // Process uppercase letter counts (similar logic as lowercase)
        for (int i = 0; i < 26; i++)
        {
            if (upper[i] % 2 == 0)
            {
                count += upper[i];
            }
            else
            {
                count += upper[i] - 1;
                odd = 1; // Mark that there's an odd occurrence
            }
        }

        // If there was any character with an odd count, one odd character can be placed in the middle of the palindrome
        return count + odd;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Call the function and display the result
    int result = solution.longestPalindrome(input);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;

    return 0;
}
