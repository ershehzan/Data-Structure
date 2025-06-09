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
        // For row i, print (n - i) spaces (single space, not double)
        for (j = 1; j <= n - i; j++)
            cout << " ";
        // Print stars for the current row, each followed by a space
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
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

            cout << " " ;
        // star print
        for (j = 1; j <= i; j++)
        {

            cout << "* " ;
        }
        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)

    * 
   * * 
  * * * 
 * * * * 
* * * * * 

<<<<<<< HEAD
*/
=======
   */
>>>>>>> 549b0d8 (file update)
