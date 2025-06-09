#include <iostream>
#include <vector>
#include <string>
using namespace std;

<<<<<<< HEAD
// Class implementing the KMP (Knuth-Morris-Pratt) string matching algorithm
class Solution {
public:
    /*
    Function: lpsfind
    Computes the Longest Prefix Suffix (LPS) array for the given pattern string.
    The LPS array is used to optimize the KMP algorithm by avoiding redundant comparisons.
    Parameters:
        - vector<int>& lps: Reference to the LPS array to be computed.
        - string s: The pattern string for which the LPS array is computed.
    */
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0; // Pointer for prefix
        int suf = 1; // Pointer for suffix

        // Traverse the pattern string to compute the LPS array
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                // If characters match, increment prefix and suffix pointers
                lps[suf] = pre + 1; // Update LPS value for the current suffix
                pre++;
                suf++;
            } else {
                // Handle mismatches
                if (pre == 0) {
                    // If no prefix exists, set LPS value to 0
                    lps[suf] = 0;
                    suf++;
                } else {
                    // Backtrack the prefix pointer using the LPS array
=======
class Solution {
public:
    void lpsfind(vector<int> &lps, string s) {
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
    }

<<<<<<< HEAD
    /*
    Function: strStr
    Finds the starting index of the first occurrence of the `needle` string in the `haystack` string.
    Uses the KMP algorithm for efficient string matching.
    Parameters:
        - string haystack: The main string in which to search.
        - string needle: The pattern string to be searched for.
    Returns:
        - An integer representing the starting index of the first occurrence of `needle` in `haystack`.
          If `needle` is not found, returns -1.
    */
    int strStr(string haystack, string needle) {
        // If the needle is empty, return 0 (as per common convention)
        if (needle.empty()) return 0;

        // Initialize the LPS array for the needle
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle); // Compute the LPS array for the needle

        int first = 0;  // Pointer for the haystack
        int second = 0; // Pointer for the needle

        // Traverse the haystack and needle to find a match
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                // If characters match, move both pointers forward
                first++;
                second++;
            } else {
                // Handle mismatches
                if (second == 0) {
                    // If no prefix exists, move the haystack pointer
                    first++;
                } else {
                    // Backtrack the needle pointer using the LPS array
                    second = lps[second - 1];
                }
            }
        }

        // Check if the entire needle was found in the haystack
        if (second == needle.size())
            return first - second; // Return the starting index of the match
        else
            return -1; // Return -1 if no match is found
=======
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        if (second == needle.size())
            return first - second;
        else
            return -1;
>>>>>>> 549b0d8 (file update)
    }
};

int main() {
    Solution solution;
    string haystack, needle;

<<<<<<< HEAD
    // Prompt the user to enter the haystack string
    cout << "Enter the haystack string: ";
    cin >> haystack;

    // Prompt the user to enter the needle string
    cout << "Enter the needle string: ";
    cin >> needle;

    // Find the first occurrence of the needle in the haystack
    int result = solution.strStr(haystack, needle);

    // Print the result
=======
    cout << "Enter the haystack string: ";
    cin >> haystack;

    cout << "Enter the needle string: ";
    cin >> needle;

    int result = solution.strStr(haystack, needle);

>>>>>>> 549b0d8 (file update)
    if (result != -1) {
        cout << "The needle is found at index: " << result << endl;
    } else {
        cout << "The needle is not found in the haystack." << endl;
    }

<<<<<<< HEAD
    return 0; // Exit the program
}
=======
    return 0;
}
>>>>>>> 549b0d8 (file update)
