#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize a 4x4 matrix with given integers
    // This is the original matrix that will be rotated
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    // Get the size of the matrix (number of rows/columns)
    int n = matrix.size();

    // Step 1: Transpose the matrix
    // Transposition involves swapping elements at (i, j) with (j, i)
    for (int i = 0; i < n; i++) // Iterate through rows
    {
        for (int j = i + 1; j < n; j++) // Iterate through columns above the diagonal
        {
            // Swap the elements to perform transposition
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row of the transposed matrix
    // Reversing a row flips its elements horizontally
    for (int i = 0; i < n; i++) // Iterate through rows
    {
        int start = 0, end = n - 1; // Pointers to the first and last elements in the row
        while (start < end) // Continue until the pointers meet
        {
            // Swap the elements at the start and end pointers
            swap(matrix[i][start], matrix[i][end]);
            start++; // Move the start pointer to the right
            end--;   // Move the end pointer to the left
        }
    }

    // Step 3: Transpose the matrix again
    // This step ensures that the matrix is rotated another 90 degrees
    for (int i = 0; i < n; i++) // Iterate through rows
    {
        for (int j = i + 1; j < n; j++) // Iterate through columns above the diagonal
        {
            // Swap the elements to perform transposition
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 4: Reverse each row of the newly transposed matrix
    // This completes the 180-degree rotation of the matrix
    for (int i = 0; i < n; i++) // Iterate through rows
    {
        int start = 0, end = n - 1; // Pointers to the first and last elements in the row
        while (start < end) // Continue until the pointers meet
        {
            // Swap the elements at the start and end pointers
            swap(matrix[i][start], matrix[i][end]);
            start++; // Move the start pointer to the right
            end--;   // Move the end pointer to the left
        }
    }

    // Step 5: Output the final matrix after 180-degree rotation
    cout << "Matrix after 180 degree rotation:" << endl;
    for (int i = 0; i < 4; i++) // Iterate through rows
    {
        for (int j = 0; j < 4; j++) // Iterate through columns in the current row
        {
            // Print each element of the matrix
            cout << matrix[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    return 0; // Indicate successful program termination
}
