#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution class to generate all combinations of well-formed parentheses
class Solution {
public:
    // Recursive helper function to build the parentheses combinations
    // n: total number of pairs of parentheses
    // l: current number of '(' used
    // r: current number of ')' used
    // ans: vector to store all valid combinations
    // temp: current string being built
    void parenthesis(int n, int l, int r, vector<string>& ans, string& temp) {
        // Base case: if the length of temp equals 2*n, a valid combination is formed
        if (l + r == 2 * n) {
            ans.push_back(temp);  // Add the current combination to the answer list
            return;
        }
        // If we can still add '(', do so and recurse
        if (l < n) {
            temp.push_back('('); // Choose '('
            parenthesis(n, l + 1, r, ans, temp); // Recurse with one more '('
            temp.pop_back(); // Backtrack: remove the last character to try other options
        }
        // If we can add ')', i.e., there are more '(' than ')', do so and recurse
        if (r < l) {
            temp.push_back(')'); // Choose ')'
            parenthesis(n, l, r + 1, ans, temp); // Recurse with one more ')'
            temp.pop_back(); // Backtrack: remove the last character to try other options
        }
    }

    // Main function to be called for generating parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // Stores all valid combinations
        string temp;        // Temporary string to build each combination
        parenthesis(n, 0, 0, ans, temp); // Start recursion with 0 '(' and 0 ')'
        return ans;         // Return the result
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: "; // Prompt user for number of pairs
    cin >> n;

    vector<string> result = solution.generateParenthesis(n); // Generate combinations
    cout << "Generated Parentheses:" << endl;
    for (const string& s : result) {
        cout << s << endl; // Print each valid combination
    }

    return 0; // Indicate successful execution
}
