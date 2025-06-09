<<<<<<< HEAD
#include <iostream>  // Include for standard input and output
=======
#include <iostream>
>>>>>>> 549b0d8 (file update)
using namespace std;

int main()
{
<<<<<<< HEAD
    int i, j, n; // i and j are loop counters, n is the number of rows

    cout << "Enter the number : "; // Prompt the user to enter the number of rows
    cin >> n;                      // Read the value of n

    // Outer loop: controls the number of rows (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: prints decreasing numbers in each row
        // First row prints 1 to n, second row prints 1 to n-1, and so on
        for (j = 1; j <= n - (i - 1); j++)
        {
            cout << j << " "; // Print the current number followed by a space
        }
        cout << endl; // Move to the next line after each row
    }
    return 0; // Indicate successful program completion
}

/* Output Example for n = 5:
=======
    int i, j, n;
    cout << "Enter the number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print decreasing numbers in each row
        for (j = 1; j <= n - (i - 1); j++)
        {
            cout << j << " ";
        }
        cout << endl; // Move to the next line after printing stars for the current row
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)
1 2 3 4 5
1 2 3 4
1 2 3
1 2
<<<<<<< HEAD
1
*/
=======
1  */
>>>>>>> 549b0d8 (file update)
