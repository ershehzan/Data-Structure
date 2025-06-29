#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class containing the function to reverse a string using a stack
class Solution {
public:
    // Function to reverse a vector of characters in-place using a stack
    void reverseString(vector<char>& s) {
        stack<char> st; // Stack to hold characters temporarily

        // Step 1: Push all characters of the vector onto the stack
        for (size_t i = 0; i < s.size(); i++) {
            st.push(s[i]); // Push each character; last character will be on top
        }

        int i = 0; // Index for placing reversed characters back into vector

        // Step 2: Pop characters from the stack and update the vector
        while (!st.empty()) {
            s[i] = st.top(); // Place the top character from the stack into the vector
            st.pop();        // Remove the character from the stack
            i++;             // Move to next index in the vector
        }
    }
};

int main() {
    Solution solution;
    int n; // Number of characters in the string

    cout << "Enter the number of characters: ";
    cin >> n; // Read the number of characters

    vector<char> s(n); // Vector to hold the characters of the string

    cout << "Enter the characters (no spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> s[i]; // Input each character individually
    }

    // Call the function to reverse the string
    solution.reverseString(s);

    // Output the reversed string
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c; // Print each character of the reversed string
    }
    cout << endl;

    return 0; // Indicate successful program termination
}
