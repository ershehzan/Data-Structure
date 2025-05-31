#include <iostream>  // Include for input and output operations
using namespace std;

int main()
{
    int n, i, j; // n = number of rows, i and j are loop counters

    cout << "Enter the number : "; // Prompt user for the number of rows
    cin >> n;                      // Read user input

    // Outer loop: controls the number of rows (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Calculate the character to print for the current row ('a' for 1st row, 'b' for 2nd, etc.)
        char name = 'a' + i - 1;

        // Inner loop: print the character 'name' i times in the current row
        for (j = 1; j <= i; j++)
        {
            cout << name << " "; // Print the character followed by a space
        }
        cout << endl; // After each row, move to the next line
    }
    return 0; // Indicate successful program completion
}

/* Output Example for n = 5:
a
b b
c c c
d d d d
e e e e e
*/
