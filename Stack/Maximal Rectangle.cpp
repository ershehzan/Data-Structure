#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Helper function to compute the largest rectangle in a histogram (O(n) using stack)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // stack to store indices
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Maintain increasing stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                ans = max(ans, heights[index] * width);
            }
            st.push(i);
        }

        // Process remaining bars in stack
        while (!st.empty()) {
            int index = st.top();
            st.pop();
            int width = st.empty() ? n : (n - st.top() - 1);
            ans = max(ans, heights[index] * width);
        }

        return ans;
    }

    // Main function to find maximal rectangle in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> h(col, 0); // histogram heights
        int ans = 0;

        // Build histogram row by row
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    h[j] = 0;  // reset height
                else
                    h[j]++;   // accumulate height
            }

            // For each updated histogram, find max area
            ans = max(ans, largestRectangleArea(h));
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<char>> matrix(m, vector<char>(n));
    cout << "Enter the matrix (each row as a string of 0s and 1s):" << endl;
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = row[j];  // Store character ('0' or '1')
        }
    }

    int result = solution.maximalRectangle(matrix);
    cout << "Maximal rectangle area: " << result << endl;
    return 0;
}
