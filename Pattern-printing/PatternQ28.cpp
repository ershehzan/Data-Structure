#include <iostream>
using namespace std;

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
  * * * * * * *      
    * * * * *        
      * * * 
        * 

*/
