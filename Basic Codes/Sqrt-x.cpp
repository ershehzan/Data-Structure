// Include the necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a Solution class that will contain our square root calculation logic
class Solution {
public:
    // Function to compute the integer part of the square root of a non-negative integer x
    int mySqrt(int x) {
        long long start = 0, end = x, ans = 0; // Initialize search boundaries and answer variable
        
        // Use binary search to find the square root
        while (start <= end) {
            // Calculate the middle value to avoid overflow
            long long mid = start + (end - start) / 2;
            // Calculate the square of the mid value
            long long square = (long long)mid * mid;  // Explicitly cast mid to long long
            
            // If mid*mid equals x, we've found the exact square root
            if (square == x) {
                return mid;
            } 
            // If mid*mid is less than x, move to the right half
            else if (square < x) {
                ans = mid;       // Store the current mid as the closest answer so far
                start = mid + 1; // Move the start to mid + 1 to search higher values
            } 
            // If mid*mid is greater than x, move to the left half
            else {
                end = mid - 1;   // Move the end to mid - 1 to search lower values
            }
        }
        // Return the integer part of the square root
        return ans;
    }
};

int main() {
    int x;
    cout << "Enter a number: ";   // Prompt the user for input
    cin >> x;                     // Read the input number
    
    Solution s1;                  // Create an instance of the Solution class
    int result = s1.mySqrt(x);    // Call the mySqrt function to compute the square root

    // Output the result to the user
    cout << "Square root of " << x << " is: " << result << endl;
    return 0;                     // Indicate successful program execution
}
