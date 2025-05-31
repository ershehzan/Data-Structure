#include <iostream> // Include the input-output stream library for cin and cout
using namespace std; // Use the standard namespace to avoid prefixing std::

int main()
{
    int n; // Variable to store the size of the pattern (number of rows and columns)
    cin >> n; // Read the value of n from user input

    int row, col, count = 1; // row and col are loop counters, count is used for printing numbers in sequence

    // Outer loop to iterate through each row
    for (row = 1; row <= n; row++)
    {
        // Inner loop to iterate through each column in the current row
        for (col = 1; col <= n; col++)
        {
            cout << count << " "; // Print the current value of count followed by a space
            count++; // Increment count for the next cell in the pattern
        }
        cout << endl; // Move to the next line after printing all columns in the current row
    }

    // Return 0 is optional in main, but signifies successful completion
}
