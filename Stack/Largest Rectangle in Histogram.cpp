#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class to solve the Largest Rectangle in Histogram problem
class Solution {
public:
    // Function to compute the area of the largest rectangle in the histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n); // Stores the index of the next smaller element to the right for each bar
        vector<int> left(n);  // Stores the index of the next smaller element to the left for each bar
        stack<int> st;

        // Find next smaller to the right for every bar
        for (int i = 0; i < n; i++) {
            // Pop bars from stack until we find a bar shorter than current
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i; // For st.top(), the next smaller is i
                st.pop();
            }
            st.push(i); // Push current index to stack
        }
        // For bars with no smaller bar to the right, set right limit as n
        while (!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // Find next smaller to the left for every bar
        for (int i = n - 1; i >= 0; i--) {
            // Pop bars from stack until we find a bar shorter than current
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i; // For st.top(), the next smaller is i
                st.pop();
            }
            st.push(i); // Push current index to stack
        }
        // For bars with no smaller bar to the left, set left limit as -1
        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        int ans = 0; // To store the maximum area found
        // Calculate area for each bar as height * width (between next smaller to left and right)
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
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
    // Compute and print the largest rectangle area
    int result = solution.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}
