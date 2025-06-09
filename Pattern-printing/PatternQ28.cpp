#include <iostream>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Declare variables:
    // n: total number of rows for the pattern (height of the pyramid)
    // i: iterator for rows
    // j: iterator for columns/spaces/stars
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n;

    // Outer loop: iterate through each row from n down to 1
    // This creates an inverted pyramid
    for (i = n; i >= 1; i--)
    {
        // Print leading spaces in each row to center-align the stars
        // Each "space" is actually two spaces ("  ") for proper alignment with "* "
        // For row i, print (n - i) sets of double spaces
        for (j = 1; j <= n - i; j++)
            cout << "  ";

        // Print stars in each row
        // The number of stars in row i is (2 * i - 1)
        // Each star is followed by a space for correct spacing
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "* ";

        // Move to the next line after printing all spaces and stars for the current row
        cout << endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}

/* Output Example (for n = 5):

* * * * * * * * *    
=======
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = n; i >= 1; i--)
    {
        // space print
        for (j = 1; j <= n - i; j++)

            cout << "  ";
        // star print
        for (j = 1; j <= 2 * i - 1; j++)

            cout << "* ";

        cout << endl;
    }
    return 0;
}
/* Output

 * * * * * * * * *    
>>>>>>> 549b0d8 (file update)
  * * * * * * *      
    * * * * *        
      * * * 
        * 

<<<<<<< HEAD
*/
=======
   */
>>>>>>> 549b0d8 (file update)
