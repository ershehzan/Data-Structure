<<<<<<< HEAD
#include <iostream>  // Include the input-output stream library for cin and cout
using namespace std;

int main()
{
    int n, i, j; // n will store the number of rows, i and j are loop counters

    cout << "Enter the number : "; // Prompt the user to enter the number of rows
    cin >> n;                      // Read the value of n from user input

    // Outer loop: controls the number of rows (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: prints numbers in decreasing order from the current row number (i) down to 1
        for (j = i; j >= 1; j--)
        {
            cout << j << " "; // Print the current value of j followed by a space
        }
        cout << endl; // Move to the next line after printing each row
    }
    return 0; // Indicate successful completion of the program
}

/* Output Example for n = 5:
=======
#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
// Loop run from row to 1  
        for (j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)
1 
2 1 
3 2 1 
4 3 2 1 
<<<<<<< HEAD
5 4 3 2 1 
*/
=======
5 4 3 2 1    */
>>>>>>> 549b0d8 (file update)
