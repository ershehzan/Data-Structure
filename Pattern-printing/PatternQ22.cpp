#include <iostream>
using namespace std;

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
        // Inner loop: print spaces to right-align the stars
        // For row i, print (n - i) sets of two spaces
        for (j = 1; j <= n - i; j++)
            cout << "  ";

        // Inner loop: print stars for the current row, i times
        for (j = 1; j <= i; j++) {
            cout << "* ";
        }

        // Move to the next line after completing the current row
        cout << endl;
    }
    return 0; // Indicate successful program execution
}

/* Output Example for n = 5

        * 
      * * 
    * * * 
  * * * * 
* * * * * 

*/
