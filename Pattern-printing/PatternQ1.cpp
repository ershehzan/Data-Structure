<<<<<<< HEAD
#include <iostream>  // Include for standard input and output operations
using namespace std;

int main()
{
    // i = row loop variable, j = column loop variable
    int n, i, j; // n will store the size of the pattern, i and j are loop counters

    cout << "Enter a number :"; // Prompt user to enter the size of the pattern
    cin >> n;                   // Take input for n

    // Outer loop for rows, iterates n times (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop for columns, also iterates n times (from 1 to n)
        for (j = 1; j <= n; j++)
        {
            cout << j * j << "  "; // Print the square of column number (j^2) with spacing
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}

/* Output Example for n = 5:
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
            cout << j * j << "  ";
        }
        cout << endl;
    }

    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
<<<<<<< HEAD
1  4  9  16  25 
*/
=======
1  4  9  16  25 */
>>>>>>> 549b0d8 (file update)
