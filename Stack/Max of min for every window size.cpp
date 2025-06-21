#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Solution class to find the maximum of minimums for every window size
class Solution {
  public:
    // Function to compute max of minimums for every window size (from 1 to n)
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0); // ans[i] will store the result for window size (i+1)

        // Outer loop for different window sizes (i+1)
        for (int i = 0; i < n; i++) {
            // Loop for each window of size (i+1)
            for (int j = 0; j < n - i; j++) {
                int num = INT_MAX; // Store minimum value in the current window
                // Loop to find minimum in the current window
                for (int k = j; k < i + 1 + j; k++) {
                    num = min(num, arr[k]);
                }
                // Update the answer for this window size with the maximum of found minimums
                ans[i] = max(ans[i], num);
            }
        }
        return ans; // Return the result vector
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
        cin >> arr[i];
    }
    // Call the function to get the result
    vector<int> result = solution.maxOfMins(arr);
    cout << "Max of min for every window size: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
