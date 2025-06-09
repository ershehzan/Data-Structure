<<<<<<< HEAD
#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    int n, i, j; // Declare integers for the number of rows (n) and loop counters (i, j)

    cout << "Enter the number : "; // Prompt the user to enter the number of rows
    cin >> n; // Read the user's input and store it in n

    // Outer loop: Runs from 1 to n to print each row
    for (i = 1; i <= n; i++)
    {
        // Inner loop: Prints '*' characters for the current row
        // The number of '*' printed in each row equals the current row number (i)
        for (j = 1; j <= i; j++) // Loop runs from 1 up to the current row number
        {
            cout << "* "; // Print an asterisk followed by a space
        }
        cout << endl; // After printing all '*' for the current row, move to the next line
    }
    return 0; // Indicate that the program ended successfully
}

/* Output Example for n = 5:
*
* *
* * *
* * * *
* * * * *
*/
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

        for (j = 1; j <= i; j++)// Loop run from 1 to no. of rows
        {
            cout << "* ";
        }
        cout << endl;
    }
        return 0;
    }
    /* Output
* 
* * 
* * * 
* * * * 
* * * * *    */
>>>>>>> 549b0d8 (file update)
