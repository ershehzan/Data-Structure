#include <iostream>
using namespace std;
<<<<<<< HEAD

int main()
{
    // i = row index, j = column index
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the value of n from user input

    // Loop for each row from 1 to n
    for (i = 1; i <= n; i++)
    {
        // Print spaces for right alignment
        // For row i, print (n - i) sets of two spaces
        for (j = 1; j <= n - i; j++)
            cout << "  ";

        // Print the row number, i times, each followed by a space
        for (j = 1; j <= i; j++)
        {
            cout << i << " ";
        }

        // Move to the next line after completing the current row
        cout << endl;
    }
    return 0; // Indicate successful program execution
}

/* Output Example for n = 5
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

            cout << "  ";
        // number print
        for (j = 1; j <= i; j++)
        {

            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)

        1 
      2 2 
    3 3 3 
  4 4 4 4 
5 5 5 5 5 
<<<<<<< HEAD

*/
=======
   */
>>>>>>> 549b0d8 (file update)
