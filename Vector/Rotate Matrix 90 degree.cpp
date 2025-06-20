#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize a 4x4 matrix with values from 0 to 15
    vector<vector<int>> matrix = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};
    int n = matrix.size(); // Get the size of the matrix (number of rows/columns)

    int ans[n][n]; // Create a 2D array to store the rotated result

    // --- Rotate the matrix by 90 degrees clockwise ---
    // For each element at (i, j) in the original matrix,
    // it is mapped to (j, n-1-i) in the rotated matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j]; // Assign rotated position
        }
    }

    // --- Output the rotated matrix ---
    cout << "Matrix after 90 degree rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " "; // Print each element in the current row
        }
        cout << endl; // Move to the next row
    }

    return 0; // End of program
}
