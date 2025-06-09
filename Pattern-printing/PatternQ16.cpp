#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
<<<<<<< HEAD

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the input value for n

    // Outer loop for each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print the current row's numbers
        // The number of times the number is printed decreases with each row
        // For row i, print (n - i + 1) times
        for (j = 1; j <= n - (i - 1); j++)
        {
            // Print the current row number followed by a space
            cout << i << " ";
        }
        // Move to the next line after completing the current row
        cout << endl; 
    }

    return 0; // Indicate successful execution
}

/* Output Example for n = 5
=======
    cout << "Enter the number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print decreasing numbers in each row
        for (j = 1; j <= n - (i - 1); j++)
        {
            cout << i << " ";
        }
        cout << endl; // Move to the next line after printing stars for the current row
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)
1 1 1 1 1 
2 2 2 2 
3 3 3 
4 4 
<<<<<<< HEAD
5 
*/
=======
5   */
>>>>>>> 549b0d8 (file update)
