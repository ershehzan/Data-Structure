#include <iostream>      // For standard input and output streams
#include <vector>        // For using the vector container
using namespace std;

int main()
{
    // Initialize a 4x4 matrix with values from 1 to 16
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int n = matrix.size(); // Get the size of the matrix (number of rows/columns)

    // --- Step 1: Transpose the matrix ---
    // Transposing means converting rows to columns and vice versa.
    // Only need to swap elements above the main diagonal to avoid double-swapping.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap element at (i, j) with element at (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // --- Step 2: Reverse each column to achieve 90 degree anticlockwise rotation ---
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        // Reverse the elements in the current column
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Print the matrix after rotation
    cout << "Matrix after 90 degree Anticlock wise rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
