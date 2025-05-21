#include <iostream>      // For input and output stream
#include <vector>        // For using the vector container
#include <algorithm>     // For possible algorithms, not used in this code
using namespace std;

int main()
{
    // Initialize a 2D vector (matrix) with 3 rows and 4 columns
    // The matrix looks like:
    // 1  2  3  4
    // 5  6  7  8
    // 9 10 11 12
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "wave form" << endl; // Output header text

    // Traverse each column of the matrix
    for (int j = 0; j < 4; j++)
    {
        // If the column index is even, print from top to bottom
        if (j % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                // Print element at row i and column j
                cout << matrix[i][j] << " ";
            }
        }
        // If the column index is odd, print from bottom to top
        else
        {
            for (int i = 2; i >= 0; i--)
            {
                // Print element at row i and column j
                cout << matrix[i][j] << " ";
            }
        }
        // Space after each column's traversal (optional, can help in formatting)
    }

    return 0; // End of program
}
