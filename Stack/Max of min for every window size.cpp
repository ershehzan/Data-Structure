#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Solution class to encapsulate the logic
class Solution {
  public:
    // Function to compute the maximum of minimums for every window size
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0); // Initialize result array with zeros

        // Outer loop for each window size (from 1 to n)
        for (int i = 0; i < n; i++) {
            // Inner loop to consider all windows of current size (i+1)
            for (int j = 0; j < n - i; j++) {
                int num = INT_MAX; // To store the minimum in the current window

                // Find the minimum value in the current window of size (i+1)
                for (int k = j; k < i + 1 + j; k++) {
                    num = min(num, arr[k]);
                }

                // Update the answer for current window size with the maximum of minimums
                ans[i] = max(ans[i], num);
            }
        }
        // Return the result vector
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input array elements
    }
    // Get the result for all window sizes
    vector<int> result = solution.maxOfMins(arr);
    cout << "Max of min for every window size: ";
    for (int x : result) {
        cout << x << " "; // Output results for each window size
    }
    cout << endl;
    return 0;
}
