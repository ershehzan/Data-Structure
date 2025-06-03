#include <iostream>
using namespace std;

int main()
{
    // Declare variables:
    // n: total number of rows for the pattern
    // i: iterator for rows
    // j: iterator for columns/spaces/numbers
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n;

    // Outer loop: iterate through each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Print leading spaces in each row to center align the numbers
        // Each space is represented by two spaces ("  ") for better alignment
        // For row i, print (n - i) sets of double spaces
        for (j = 1; j <= n - i; j++)
            cout << "  ";

        // Print numbers in increasing order from 1 up to i
        // Example for i = 3: 1 2 3
        for (j = 1; j <= i; j++)
            cout << j << " ";

        // Print numbers in decreasing order from (i-1) down to 1
        // This continues the symmetry after the peak value
        // Example for i = 3: 2 1
        for (j = i - 1; j >= 1; j--)
            cout << j << " ";

        // Move to the next line after completing the current row
        cout << endl;
    }

    // Return 0 to indicate successful program execution
    return 0;
}

/* Output Example (for n = 5):

        1 
      1 2 1 
    1 2 3 2 1        
  1 2 3 4 3 2 1      
1 2 3 4 5 4 3 2 1 

*/
