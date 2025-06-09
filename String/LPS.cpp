<<<<<<< HEAD
// This program finds the length of the longest prefix which is also a suffix (LPS) in a given string.
// The LPS problem is a common preprocessing step in the Knuth-Morris-Pratt (KMP) string matching algorithm.

=======
// This program finds the longest prefix which is also a suffix in a given string.
>>>>>>> 549b0d8 (file update)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

<<<<<<< HEAD
// Class implementing the solution for finding the Longest Prefix Suffix (LPS).
class Solution {
public:
    /*
    Function: longestPrefixSuffix
    Computes the length of the longest prefix which is also a suffix (LPS) for a given string.
    Parameters:
        - string &s: Reference to the input string.
    Returns:
        - An integer representing the length of the LPS.
    */
    int longestPrefixSuffix(string &s) {
        // Initialize a vector to store the LPS values for each index of the string.
        vector<int> lps(s.size(), 0);

        int pre = 0; // Pointer for the prefix.
        int suf = 1; // Pointer for the suffix.

        // Loop through the string to compute the LPS array.
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                // If the prefix and suffix characters match:
                lps[suf] = pre + 1; // Update the LPS value for the suffix index.
                pre++;              // Move the prefix pointer forward.
                suf++;              // Move the suffix pointer forward.
            } else {
                // If the characters do not match:
                if (pre == 0) {
                    // If no prefix exists, set LPS value to 0 for the current suffix index.
                    lps[suf] = 0;
                    suf++; // Move the suffix pointer forward.
                } else {
                    // If a prefix exists, backtrack the prefix pointer using the LPS array.
=======
class Solution {
public:
    int longestPrefixSuffix(string &s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
>>>>>>> 549b0d8 (file update)
                    pre = lps[pre - 1];
                }
            }
        }
<<<<<<< HEAD

        // The last value in the LPS array represents the length of the longest prefix which is also a suffix.
=======
>>>>>>> 549b0d8 (file update)
        return lps[s.size() - 1];
    }
};

int main() {
<<<<<<< HEAD
    Solution solution; // Create an instance of the Solution class.
    string input;      // Variable to store the user input string.

    // Prompt the user to enter a string.
    cout << "Enter a string: ";
    cin >> input;

    // Compute the length of the longest prefix which is also a suffix.
    int result = solution.longestPrefixSuffix(input);

    // Display the result.
    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0; // Exit the program.
}
=======
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solution.longestPrefixSuffix(input);
    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)
