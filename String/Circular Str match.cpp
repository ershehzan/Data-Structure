// Circular string matching
// This program checks if a given pattern string can be found as a circular substring within another string.

#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
// The LPS array helps optimize the pattern matching process in the KMP algorithm.
void lpsfind(vector<int>& lps, string txt) {
    int prefix = 0, suffix = 1; // Initialize pointers for prefix and suffix.
    
    // Process the input string `txt` to generate the LPS array.
    while (suffix < txt.size()) {
        if (txt[prefix] == txt[suffix]) { 
            // When characters match, increment prefix and suffix pointers.
            lps[suffix] = prefix + 1; // Update LPS value for `suffix`.
            prefix++;
            suffix++;
        } else {
            // Handle mismatches.
            if (prefix == 0) {
                // If no prefix exists, set LPS value to 0 and move suffix pointer.
                lps[suffix] = 0;
                suffix++;
            } else {
                // If a prefix exists, backtrack using the LPS array.
                prefix = lps[prefix - 1];
            }
        }
    }
}

int main() {
    // Input strings
    string txt = "cdeabroab"; // Main text string
    string pattern = "abcde"; // Pattern string to search for

    // Append the text to itself to simulate a circular string.
    txt += txt;

    // Initialize the LPS array for the pattern.
    vector<int> lps(pattern.size(), 0);
    lpsfind(lps, pattern); // Compute the LPS array for the pattern.

    int first = 0, second = 0; // Initialize pointers for the text and pattern.

    // Perform pattern matching using the KMP algorithm.
    while (second < pattern.size() && first < txt.size()) {
        if (pattern[second] == txt[first]) {
            // When characters match, move both pointers.
            second++;
            first++;
        } else {
            // Handle mismatches.
            if (second == 0) {
                // If no prefix exists, move the text pointer.
                first++;
            } else {
                // If a prefix exists, backtrack using the LPS array.
                second = lps[second - 1];
            }
        }
    }

    // Check if the entire pattern was found in the text.
    if (second == pattern.size())
        cout << "Matching"; // The pattern is found as a circular substring.
    else
        cout << "Not Matching"; // The pattern is not found.
}
