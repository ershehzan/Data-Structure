#include <iostream>
using namespace std;

int main()
{
    // Declare variables:
    // n: total number of rows and columns for the pattern (since this is a square)
    // i: iterator for rows
    // j: iterator for columns/numbers
    int n, i, j;

    // Prompt the user to enter the size of the pattern (n x n)
    cout << "Enter a number :";
    cin >> n;

    // Outer loop: iterate through each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: print numbers from 1 to n for each column in the current row
        for (j = 1; j <= n; j++)
        {
            cout << j << " "; // Print the current column number followed by a space
        }
        // Move to the next line after printing all columns for the current row
        cout << endl;
    }

    // Return 0 to indicate successful program execution
    return 0;
}

/* Output Example (for n = 5):

1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 

*/
