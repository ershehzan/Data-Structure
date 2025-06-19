#include <bits/stdc++.h>  // Include all standard libraries (common in competitive programming)
using namespace std;

// Define a Solution class to encapsulate the Boyer-Moore Voting Algorithm logic
class Solution {
public:
    // Function to find the majority element in the array
    int majorityElement(vector<int>& nums) {
        int can, count = 0, n = nums.size();

        // Step 1: Find a candidate using Boyer-Moore Voting Algorithm
        // The idea is to cancel out each occurrence of an element which is not the majority element
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                can = nums[i];   // Set the current element as candidate
                count = 1;       // Reset count for new candidate
            } else if (can == nums[i]) {
                count++;         // Increment count if current element matches candidate
            } else {
                count--;         // Decrement count for a different element
            }
        }

        // Step 2: Verify if the candidate is actually the majority element
        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == can) {
                count++;         // Count occurrences of the candidate
            }
        }

        // Return the candidate if it occurs more than n/2 times, otherwise return -1
        return (count > n / 2) ? can : -1;  // Return -1 if no majority element exists
    }
};

// Driver Code: demonstrates how to use the Solution class
int main() {
    vector<int> nums = {3, 2, 3};   // Example array to test the algorithm
    Solution obj;
    cout << "Majority Element: " << obj.majorityElement(nums) << endl;  // Output result

    return 0;   // End program
}
