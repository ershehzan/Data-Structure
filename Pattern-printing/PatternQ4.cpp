#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare variables: n for size of the square, i/j as loop counters

    cout << "Enter a number :"; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // Outer loop: iterates over each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: iterates from n down to 1 for each column
        // This prints numbers in descending order on each row
        for (j = n; j >= 1; j--) // Decrement j from n to 1
        {
            cout << j << " "; // Print the current value of j followed by a space
        }
        cout << endl; // Move to the next line after each row is printed
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5:
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
*/
