#include <iostream>
#include <vector>

using namespace std;

// Class to solve the problem of finding the majority element
class Solution
{
public:
    // Function to find the majority element in the given vector
    // Majority Element: An element that appears more than n/2 times in the array
    int majorityElement(vector<int> &nums)
    {
        int can, count = 0, n = nums.size();

        // Iterate through all elements of the array
        for (int i = 0; i < n; i++)
        {
            // If the count is zero, update the candidate to the current element
            if (count == 0)
            {
                count = 1;      // Reset the count to 1
                can = nums[i];  // Set the candidate to the current element
            }
            else
            {
                // If the current element matches the candidate, increment the count
                if (can == nums[i])
                {
                    count++;
                }
                else
                {
                    // Otherwise, decrement the count
                    count--;
                }
            }
        }
        // Return the candidate, which is the majority element
        return can;
    }
};

int main()
{
    // Example input vector containing integers
    vector<int> nums = {3, 2, 3, 2, 3, 4, 5, 3, 2, 2, 2, 3};

    // Create an instance of the Solution class
    Solution sol;

    // Find and print the majority element in the vector
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;

    return 0; // Exit the program
}
