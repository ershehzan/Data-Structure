<<<<<<< HEAD
#include <iostream>  // Include the input-output stream library for cin and cout
using namespace std; // Use the standard namespace

int main()
{
    int n; // Variable to store the size of the pattern (number of rows and columns)
    cin >> n; // Read the value of n from user input

    int row, col; // Loop variables for rows and columns

    // Outer loop to iterate through each row (from 1 to n)
    for (row = 1; row <= n; row++)
    {
        // Inner loop to iterate through each column in the current row (from 1 to n)
        for (col = 1; col <= n; col++)
        {
            cout << row * row << " "; // Print the square of the current row number, followed by a space
        }
        cout << endl; // Move to the next line after printing all columns in the current row
    }

    // (Optional) main returns 0 by default in C++, indicating successful completion
}
=======
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int row, col;
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= n; col++)
        {
            cout << row*row << " ";
        }
        cout << endl;
    }
}
>>>>>>> 549b0d8 (file update)
