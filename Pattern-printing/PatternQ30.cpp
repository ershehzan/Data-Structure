<<<<<<< HEAD
#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare variables: n for size of the pattern, i/j as loop counters

    cout << "Enter the number : "; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // First half: from 1 to n rows (upper part of the pattern)
    for (i = 1; i <= n; i++)
    {
        // Print stars on the left side of the pattern
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle; the number of spaces decreases as i increases
        // Each "space" is two spaces ("  ") for alignment with "* "
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side (mirrored from the left)
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after printing the current row
    }

    // Second half: from n-1 down to 1 (lower part of the pattern)
    for (i = n - 1; i >= 1; i--)
    {
        // Print stars on the left side
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle; the number of spaces increases as i decreases
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side (mirrored from the left)
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after printing the current row
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5:
=======
#include <iostream>
using namespace std;
int main()
{
    // i=row   j=column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;
    // loop 1 to n
    for (i = 1; i <= n; i++)
    {
        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print space
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
    // loop n-1 to 1
    for (i = n - 1; i >= 1; i--)
    {
        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print space
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}
/* Output

>>>>>>> 549b0d8 (file update)
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 *  
<<<<<<< HEAD
*/
=======

   */
>>>>>>> 549b0d8 (file update)
