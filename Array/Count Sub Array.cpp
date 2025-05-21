#include <iostream>
#include <vector>
using namespace std;

// Solution class encapsulates the logic to count specific subarrays in a vector
class Solution {
public:
    // This method counts the number of subarrays of length 3
    // where the second element is even and (first + third) equals half of the second element.
    int countSubarrays(vector<int>& nums) {
        int count = 0;              // Initialize the counter for valid subarrays
        int n = nums.size();        // Get the size of the input vector
        
        // Loop through the vector, considering each triplet of consecutive elements
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];        // First element of the triplet
            int second = nums[i + 1];   // Second (middle) element
            int third = nums[i + 2];    // Third element
            
            // Check if the second element is even
            // and the sum of the first and third equals half the second element
            if (second % 2 == 0 && first + third == second / 2) {
                count++;    // If condition is met, increment the counter
            }
        }
        
        return count;   // Return the total count of valid subarrays
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 4, 2, 6, 8, 4}; // Example input vector
    
    // Call the method to count valid subarrays and store the result
    int result = solution.countSubarrays(nums);
    
    // Output the result to the console
    cout << "Count of valid subarrays: " << result << endl;
    return 0;
}
