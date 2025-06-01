#include <iostream>
using namespace std;

int main()
{
    // i = row index, j = column index
    int n, i, j;

    // Prompt the user to enter the size of the pattern (number of rows and columns)
    cout << "Enter a number :";
    cin >> n; // Read the value of n from user input

    // Outer loop: iterate through each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: iterate through each column (from 1 to n)
        for (j = 1; j <= n; j++)
        {
            // Print the row number followed by a space
            cout << i << " ";
        }
        // After printing all columns for the current row, move to the next line
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5
1 1 1 1 1 
2 2 2 2 2 
3 3 3 3 3 
4 4 4 4 4 
5 5 5 5 5 
*/
