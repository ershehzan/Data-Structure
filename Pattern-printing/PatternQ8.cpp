#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare integers for the size of the pattern (n) and loop counters (i, j)
    
    // Extra variable to keep track of the current number to print
    int count = 1;
    
    cout << "Enter a number : "; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // Outer loop: iterates over each row (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: iterates over each column (from 1 to n)
        for (j = 1; j <= n; j++)
        {
            // Print the current count, followed by a space
            cout << count << " ";
            count++; // Increment count for the next number

            // Alternate solution: You could also use the formula below to print the same pattern
            // cout << (i - 1) * n + j << " "; 
        }
        cout << endl; // Move to the next line after each row is printed
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5:
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
