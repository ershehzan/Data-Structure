#include <iostream>
using namespace std;

int main()
{
    // Declare variables
    // n: total number of rows for the pattern
    // i: iterator for rows
    // j: iterator for columns/spaces/stars
    int n, i, j;

    // Prompt user to enter the number of rows
    cout << "Enter the number : ";
    cin >> n;

    // Outer loop for each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Print spaces before the stars in each row
        // For row i, print (n - i) spaces to center-align the stars
        for (j = 1; j <= n - i; j++)
            cout << " ";

        // Print stars in each row
        // The number of stars in row i is (2 * i - 1)
        // This creates an odd number of stars per row, forming a pyramid
        for (j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        // Move to the next line after printing all spaces and stars in the current row
        cout << endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}

/* Output Example (for n = 5):

    *
   ***
  *****
 *******
*********

*/
