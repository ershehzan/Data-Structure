#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Celebrity Problem:
// A celebrity is a person who is known by everyone but knows no one.

class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);  // Each index represents a person
        }

        // Step 2: Eliminate non-celebrities using pairwise comparison
        while (st.size() > 1) {
            int a = st.top(); st.pop();  // Pop top person 'a'
            int b = st.top(); st.pop();  // Pop next top person 'b'

            if (M[a][b] == 1) {
                // If person 'a' knows 'b', then 'a' cannot be celebrity
                // So keep 'b' as a possible candidate
                st.push(b);
            } else {
                // If person 'a' doesn't know 'b', then 'b' cannot be celebrity
                // So keep 'a' as a possible candidate
                st.push(a);
            }
        }

        // Step 3: Validate the final candidate (if stack is not empty)
        if (st.empty()) return -1;  // No one left, no celebrity

        int candidate = st.top();  // Potential celebrity
        st.pop();

        // Check if candidate satisfies celebrity conditions:
        // 1. Candidate knows no one (row check)
        // 2. Everyone knows candidate (column check)
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // If candidate knows someone OR someone doesn't know candidate
                if (M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;  // Not a celebrity
            }
        }

        return candidate;  // Valid celebrity found
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    // Matrix to store who knows whom
    // M[i][j] = 1 means person i knows person j
    // M[i][j] = 0 means person i does NOT know person j
    vector<vector<int>> M(n, vector<int>(n));

    cout << "Enter the matrix (row-wise, 0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    int result = solution.celebrity(M);

    if (result == -1)
        cout << "There is no celebrity." << endl;
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}
