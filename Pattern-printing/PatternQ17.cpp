#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the value of n from user input

    // Outer loop for each row, runs from 1 to n
    for (i = 1; i <= n; i++)
    {
        // Inner loop prints numbers starting from n down to (n - i + 1)
        // For each row, it prints one more number than the previous row
        for (j = n; j >= n - i + 1; j--)
        {
            // Print the current value of j followed by a space
            cout << j << " ";
        }
        // After printing all numbers in the current row, move to the next line
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5
5 
5 4 
5 4 3 
5 4 3 2 
5 4 3 2 1
*/
