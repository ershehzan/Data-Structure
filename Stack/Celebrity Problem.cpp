#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class to solve the Celebrity Problem
class Solution {
public:
    // Function to find the celebrity in a party
    // M is a matrix where M[i][j] == 1 means person i knows person j
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();        // Number of people at the party
        stack<int> st;           // Stack to keep track of potential celebrities

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);          // Each person is a potential celebrity
        }

        // Step 2: Eliminate non-celebrities
        // Compare two people at a time and eliminate at least one who can't be a celebrity
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            // If person 'a' knows person 'b', then 'a' cannot be a celebrity, so keep 'b'
            if (M[a][b] == 1) {
                st.push(b);
            } else {
                // If person 'a' does NOT know 'b', then 'b' cannot be a celebrity, so keep 'a'
                st.push(a);
            }
        }

        // Step 3: Validate potential celebrity
        // If stack is empty, there is no celebrity
        if (st.empty()) return -1;

        int candidate = st.top(); // The remaining person might be the celebrity
        st.pop();

        // Check if the candidate is really a celebrity
        // Celebrity does not know anyone else, but everyone knows the celebrity
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // If candidate knows someone, or someone does NOT know candidate, candidate isn't a celebrity
                if (M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;
            }
        }

        // Candidate is confirmed as celebrity
        return candidate;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    // Input the relationship matrix
    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the matrix (row-wise, 0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    // Find the celebrity (if any)
    int result = solution.celebrity(M);
    if (result == -1)
        cout << "There is no celebrity." << endl;
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}
