#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Helper function to compute the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st; // Stack to keep indices of the bars
    int maxArea = 0; // Initialize max area as 0

    for (int i = 0; i <= n; i++) {
        // For the last bar, use height 0 as a sentinel to pop all remaining bars
        int h = (i == n) ? 0 : heights[i];
        // Maintain increasing stack; if current bar is lower, calculate area for previous bars
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()]; // Height of the bar to compute area
            st.pop();
            // Calculate width: if stack is empty, width is current index; else, width is difference between current and stack top - 1
            int width = st.empty() ? i : i - st.top() - 1;
            // Calculate area with popped bar as the smallest bar
            maxArea = max(maxArea, height * width);
        }
        st.push(i); // Push current bar's index
    }
    return maxArea;
}

// Main function to compute the maximal rectangle of 1's in a binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int maxRect = 0; // To keep track of the largest rectangle found
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> heights(n, 0); // Vector to store histogram heights for each row

    // Process each row of the matrix
    for (int i = 0; i < m; i++) {
        // Build/update the histogram for this row
        for (int j = 0; j < n; j++) {
            // If current cell is '1', increase height; else, reset height to 0
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        // For the current histogram, calculate the largest rectangle area
        int area = largestRectangleArea(heights);
        // Update maxRect if a larger area is found
        maxRect = max(maxRect, area);
    }
    return maxRect;
}

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    cout << "Enter matrix row by row (as 0 and 1):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j]; // Read each cell as char
        }
    }
    int result = maximalRectangle(matrix);
    cout << "Maximal rectangle area is: " << result << endl;
    return 0;
}
