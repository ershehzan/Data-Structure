#include <iostream>
#include <vector>

using namespace std;

// Solution class containing the function to find the majority element
class Solution
{
public:
    // Function to find the majority element in the vector nums
    int majorityElement(vector<int> &nums)
    {
        int can, count = 0, n = nums.size(); // 'can' stores candidate, 'count' is its count, 'n' is the vector size

        // Moore's Voting Algorithm: Find a potential majority candidate
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                // If count drops to 0, take current element as new candidate
                count = 1;
                can = nums[i];
            }
            else
            {
                // If current element matches candidate, increment count
                if (can == nums[i])
                {
                    count++;
                }
                else
                {
                    // If not, decrement count
                    count--;
                }
            }
        }
        // The candidate 'can' is returned as the majority element
        // (Assumes the input always has a majority element as per problem statement)
        return can;
    }
};

int main()
{
    // Example vector of numbers
    vector<int> nums = {3, 2, 3, 2, 3, 4, 5, 3, 2, 2, 2, 3};
    Solution sol;
    // Display the majority element found in the vector
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
