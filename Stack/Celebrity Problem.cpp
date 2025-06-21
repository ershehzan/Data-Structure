#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class encapsulates the celebrity problem logic
class Solution {
public:
    // Function to find the celebrity in the party
    // M: adjacency matrix where M[i][j] == 1 means person i knows person j
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i); // Initially, everyone is a celebrity candidate
        }

        // Step 2: Eliminate non-celebrities
        // Compare two people at a time and remove at least one non-celebrity
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (M[a][b] == 1) {
                // a knows b, so a cannot be celebrity
                st.push(b);
            } else {
                // a does NOT know b, so b cannot be celebrity
                st.push(a);
            }
        }

        // Step 3: Validate the potential celebrity
        // If stack is empty, there is no celebrity
        if (st.empty()) return -1;

        int candidate = st.top();
        st.pop();

        // Check if candidate is a celebrity:
        // 1. Candidate should not know anyone else.
        // 2. Everyone else should know the candidate.
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // If candidate knows someone, or someone doesn't know candidate, return -1
                if (M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;
            }
        }

        // If all checks pass, return the celebrity's index
        return candidate;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the matrix (row-wise, 0 or 1):" << endl;
    // Input the acquaintance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    // Find and print the celebrity (if any)
    int result = solution.celebrity(M);
    if (result == -1)
        cout << "There is no celebrity." << endl;
    else
        cout << "Celebrity is person: " << result << endl;
    return 0;
}
