#include <iostream>
using namespace std;
<<<<<<< HEAD

int main()
{
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the value of n from user input

    // Loop for each row from 1 to n
    for (i = 1; i <= n; i++)
    {
        // First inner loop: print spaces for right alignment
        // For row i, print (n - i) sets of two spaces to align the numbers
        for (j = 1; j <= n - i; j++)
        {
            cout << "  "; // Two spaces for each slot to match the output format
        }

        // Second inner loop: print numbers in decreasing order from i down to 1
        // Each number is followed by a space for better alignment
=======
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
    //space print
        for (j = 1; j <= n-i; j++)
        {
            cout << "  ";
        }
>>>>>>> 549b0d8 (file update)
        for (j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
<<<<<<< HEAD

        // Move to the next line after completing the current row
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5
=======
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
5 4 3 2 1
<<<<<<< HEAD

*/
=======
   */
>>>>>>> 549b0d8 (file update)
