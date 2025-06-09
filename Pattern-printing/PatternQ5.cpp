<<<<<<< HEAD
#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare variables: n for size of the square, i/j as loop counters

    cout << "Enter a number :"; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // Outer loop: iterates over each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: iterates over each column (from 1 to n)
        for (j = 1; j <= n; j++)
        {
            cout << " * "; // Print an asterisk with spaces for formatting
        }
        cout << endl; // Move to the next line after each row is printed
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5:
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
*/
=======
#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int n, i, j;
    cout << "Enter a number :";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        // Nested loop
        for (j = 1; j <= n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

    return 0;
}
/*Output
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1  */
>>>>>>> 549b0d8 (file update)
