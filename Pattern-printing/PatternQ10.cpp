<<<<<<< HEAD
#include <iostream>  // Include the library for input and output operations
using namespace std;

int main()
{
    int n, i, j; // n will store the number of rows, i and j are loop counters

    cout << "Enter the number : "; // Prompt the user to enter the number of rows
    cin >> n;                      // Read the number from user input

    // Outer loop: controls the number of rows (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: prints numbers from 1 up to the current row number (i)
        for (j = 1; j <= i; j++)
        {
            cout << j << " "; // Print the current number followed by a space
        }
        cout << endl; // After printing each row, move to the next line
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
// Loop run from 1 to no. of rows 
        for (j = 1; j <= i; j++)
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
1 2       
1 2 3     
1 2 3 4   
<<<<<<< HEAD
1 2 3 4 5 
*/
=======
1 2 3 4 5    */
>>>>>>> 549b0d8 (file update)
