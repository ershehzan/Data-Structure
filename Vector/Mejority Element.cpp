#include <iostream>
#include <vector>

using namespace std;

<<<<<<< HEAD
// Class to solve the problem of finding the majority element
class Solution
{
public:
    // Function to find the majority element in the given vector
    // Majority Element: An element that appears more than n/2 times in the array
=======
class Solution
{
public:
>>>>>>> 549b0d8 (file update)
    int majorityElement(vector<int> &nums)
    {
        int can, count = 0, n = nums.size();

<<<<<<< HEAD
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
=======
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                count = 1;
                can = nums[i];
            }
            else
            {
>>>>>>> 549b0d8 (file update)
                if (can == nums[i])
                {
                    count++;
                }
                else
                {
<<<<<<< HEAD
                    // Otherwise, decrement the count
=======
>>>>>>> 549b0d8 (file update)
                    count--;
                }
            }
        }
<<<<<<< HEAD
        // Return the candidate, which is the majority element
=======
>>>>>>> 549b0d8 (file update)
        return can;
    }
};

int main()
{
<<<<<<< HEAD
    // Example input vector containing integers
    vector<int> nums = {3, 2, 3, 2, 3, 4, 5, 3, 2, 2, 2, 3};

    // Create an instance of the Solution class
    Solution sol;

    // Find and print the majority element in the vector
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;

    return 0; // Exit the program
}
=======
    vector<int> nums = {3, 2, 3,2,3,4,5,3,2,2,2,3};
    Solution sol;
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
>>>>>>> 549b0d8 (file update)
