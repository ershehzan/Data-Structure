#include <iostream>  // Include the library for input and output operations
using namespace std;

int main()
{
    int n, i, j; // n = number of rows, i and j are loop counters

    cout << "Enter the number : "; // Prompt the user to enter the number of rows
    cin >> n;                      // Read the input value for n

    // Outer loop: controls the number of rows (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: prints the current row number (i), i times in the current row
        for (j = 1; j <= i; j++)
        {
            cout << i << " "; // Print the current row number followed by a space
        }
        cout << endl; // Move to the next line after finishing each row
    }
    return 0; // Indicate successful completion of the program
}

/* Output Example for n = 5:
1       
2 2     
3 3 3   
4 4 4 4 
5 5 5 5 5 
*/
