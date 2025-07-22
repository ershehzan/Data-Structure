#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n); // NSR - Index of next smaller element to the right
        vector<int> left(n);  // NSL - Index of next smaller element to the left
        stack<int> st;

        // Step 1: Compute Next Smaller to Right (NSR)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i; // For index on top, current i is the next smaller
                st.pop();
            }
            st.push(i);
        }
        // Remaining indices have no smaller element to the right
        while (!st.empty()) {
            right[st.top()] = n; // Use n as the boundary
            st.pop();
        }

        // Step 2: Compute Next Smaller to Left (NSL)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i; // For index on top, current i is the previous smaller
                st.pop();
            }
            st.push(i);
        }
        // Remaining indices have no smaller element to the left
        while (!st.empty()) {
            left[st.top()] = -1; // Use -1 as the boundary
            st.pop();
        }

        // Step 3: Compute maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            // Width = right[i] - left[i] - 1
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = solution.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;

    return 0;
}
