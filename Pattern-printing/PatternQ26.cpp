#include <iostream>
using namespace std;
<<<<<<< HEAD

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
=======
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // space print
        for (j = 1; j <= n - i; j++)

            cout << " ";
        // star print
        for (j = 1; j <= 2 * i - 1; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)

    *
   ***
  *****
 *******
*********

<<<<<<< HEAD
*/
=======
   */
>>>>>>> 549b0d8 (file update)
