#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the value of n from user input

    // Loop for each row from 1 to n
    for (i = 1; i <= n; i++)
    {
        // First inner loop: print spaces to right-align the numbers
        // For row i, print (n - i) spaces
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // Second inner loop: print numbers in decreasing order from i down to 1
        // Each number is followed by a space for better alignment
        for (j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        // Move to the next line after completing the current row
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5

    1 
   2 1 
  3 2 1 
 4 3 2 1 
5 4 3 2 1 

*/
