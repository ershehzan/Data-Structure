#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare variables: n for size of the pattern, i/j as loop counters

    cout << "Enter the number : "; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // First half: from 1 to n rows
    for (i = 1; i <= n; i++)
    {
        // Print stars on the left side
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after each row is printed
    }

    // Second half: from n-1 down to 1
    for (i = n - 1; i >= 1; i--)
    {
        // Print stars on the left side
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after each row is printed
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5:
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * * *         * * 
* *             * * 
*                 *  
*/
