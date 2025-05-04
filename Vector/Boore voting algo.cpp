// Program implementing the Boyer-Moore Voting Algorithm to find the majority element in an array
#include <bits/stdc++.h> // Include all standard libraries (not recommended for large projects)
using namespace std;     // Use the standard namespace to simplify code

// Class containing the solution for finding the majority element
class Solution {
public:
    /*
     * Function to find the majority element in an array.
     * A majority element is an element that appears more than n/2 times, where n is the size of the array.
     * If no such element exists, the function returns -1.
     */
    int majorityElement(vector<int>& nums) {
        int can, count = 0, n = nums.size(); // Variables to store the candidate, its count, and array size

        // Step 1: Find a candidate using Boyer-Moore Voting Algorithm
        /*
         * The algorithm maintains a `count` for the potential majority element.
         * - When `count` is 0, a new candidate is selected.
         * - If the current element matches the candidate, increment the count.
         * - Otherwise, decrement the count.
         */
        for (int i = 0; i < n; i++) {
            if (count == 0) {        // If no candidate is currently selected
                can = nums[i];       // Set the current element as the candidate
                count = 1;           // Initialize its count to 1
            } else if (can == nums[i]) { // If the current element matches the candidate
                count++;             // Increment the count
            } else {                 // If the current element does not match the candidate
                count--;             // Decrement the count
            }
        }

        // Step 2: Verify if the candidate is the majority element
        /*
         * After identifying a candidate, we count its occurrences in the array.
         * If its count is greater than n/2, it is the majority element.
         * Otherwise, no majority element exists.
         */
        count = 0; // Reset the count
        for (int i = 0; i < n; i++) {
            if (nums[i] == can) { // Count occurrences of the candidate in the array
                count++;
            }
        }

        // Return the candidate if it is the majority element; otherwise, return -1
        return (count > n / 2) ? can : -1;
    }
};

// Driver Code
int main() {
    vector<int> nums = {3, 2, 3}; // Sample input array
    Solution obj;                // Create an instance of the Solution class
    cout << "Majority Element: " << obj.majorityElement(nums) << endl; // Call the function and print the result

    return 0; // Indicate successful program termination
}
