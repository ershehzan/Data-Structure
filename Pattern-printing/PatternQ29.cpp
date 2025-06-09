#include <iostream>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Declare variables:
    // n: total number of rows for the upper/lower half of the pattern
    // i: iterator for rows
    // j: iterator for columns/spaces/stars
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n;

    // First half of the pattern (upper half) - Inverted pyramid
    // Loop from n down to 1 (top to center)
    for (i = n; i >= 1; i--)
    {
        // Print stars on the left side
        // For row i, print i stars
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle
        // The number of spaces increases as i decreases
        // Each "space" is actually two spaces ("  ") for correct alignment with "* "
        // For row i, print (2 * n - 2 * i) sets of double spaces
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side (mirrored)
        // Same number as the left side
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Move to the next line after completing the current row
        cout << endl;
    }

    // Second half of the pattern (lower half) - Normal pyramid
    // Loop from 1 up to n (center to bottom)
    for (i = 1; i <= n; i++)
    {
        // Print stars on the left side
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Print spaces in the middle
        // The number of spaces decreases as i increases
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // Print stars on the right side (mirrored)
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Move to the next line after completing the current row
        cout << endl;
    }

    // Return 0 to indicate successful program execution
    return 0;
}

/* Output Example (for n = 8):
=======
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;
    // opp loop from n to 1
    for (i = n; i >= 1; i--)
    {
        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        // space print
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
    // opp loop from 1 to n
    for (i = 1; i <= n; i++)
    {
        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        // space print
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)

* * * * * * * * * * * * * * * * 
* * * * * * *     * * * * * * * 
* * * * * *         * * * * * * 
* * * * *             * * * * * 
* * * *                 * * * * 
* * *                     * * * 
* *                         * * 
*                             * 
*                             * 
* *                         * * 
* * *                     * * * 
* * * *                 * * * * 
* * * * *             * * * * * 
* * * * * *         * * * * * * 
* * * * * * *     * * * * * * * 
* * * * * * * * * * * * * * * * 

<<<<<<< HEAD
*/
=======
   */
>>>>>>> 549b0d8 (file update)
