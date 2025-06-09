<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;

/*
 * This class contains a solution for the problem of finding numbers with an even number of digits.
 * The primary method, `findNumbers`, iterates through a vector of integers and counts how many
 * of them have an even number of digits.
 */
class Solution
{
public:
    /*
     * Function to count numbers with an even number of digits in a given vector.
     *
     * Parameters:
     * - nums: A vector of integers to be checked.
     *
     * Returns:
     * - An integer representing the count of numbers with an even number of digits.
     */
    int findNumbers(vector<int> &nums)
    {
        int count = 0; // Initialize a counter to keep track of numbers with even digits

        // Iterate through each number in the vector
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i]; // Get the current number
            int digits = 0;    // Initialize a variable to count the digits of the number

            // Count the digits of the current number
            while (num > 0)
            {
                num /= 10; // Remove the last digit by dividing by 10
                digits++;  // Increment the digit counter
            }

            // Check if the number of digits is even
            if (digits % 2 == 0)
            {
                count++; // Increment the count if the number has an even number of digits
            }
        }

        return count; // Return the total count
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define a vector of integers to test the solution
    vector<int> nums = {12, 345, 2, 6, 7896};

    // Call the findNumbers function and store the result
    int result = solution.findNumbers(nums);

    // Print the result
    cout << "The count of numbers with an even number of digits is: " << result << endl;

    return 0; // Exit the program successfully
}
=======
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int digits = 0;
            while (num > 0)
            {
                num /= 10;
                digits++;
            }
            if (digits % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {12, 345, 2, 6, 7896};
    int result = solution.findNumbers(nums);
    cout << "The count of numbers with an even number of digits is: " << result << endl;
    return 0;
}
>>>>>>> 549b0d8 (file update)
