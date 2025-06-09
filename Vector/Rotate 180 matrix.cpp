#include <iostream>
#include <vector>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Initialize a 4x4 matrix with given integers
=======
int main()
{
>>>>>>> 549b0d8 (file update)
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
<<<<<<< HEAD
    
    // Get the size of the matrix (number of rows/columns)
    int n = matrix.size();

    // Step 1: Rotate the matrix 180 degrees vertically
    // This involves swapping elements in each column from top to bottom
    for (int j = 0; j < n; j++) // Iterate over all columns
    {
        int start = 0, end = n - 1; // Pointers to the first and last row
        while (start < end) // Continue until the pointers meet
        {
            // Swap the elements in the current column between the 'start' and 'end' rows
            swap(matrix[start][j], matrix[end][j]);
            start++; // Move the 'start' pointer down
            end--;   // Move the 'end' pointer up
        }
    }

    // Step 2: Rotate the matrix 180 degrees horizontally
    // This involves swapping elements in each row from left to right
    for (int i = 0; i < n; i++) // Iterate over all rows
    {
        int start = 0, end = n - 1; // Pointers to the first and last column
        while (start < end) // Continue until the pointers meet
        {
            // Swap the elements in the current row between the 'start' and 'end' columns
            swap(matrix[i][start], matrix[i][end]);
            start++; // Move the 'start' pointer to the right
            end--;   // Move the 'end' pointer to the left
        }
    }

    // Step 3: Output the final matrix after the 180-degree rotation
    cout << "Matrix after 180 degree rotation:" << endl;
    for (int i = 0; i < 4; i++) // Iterate over all rows
    {
        for (int j = 0; j < 4; j++) // Iterate over all columns in the current row
        {
            // Print each element of the matrix
            cout << matrix[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    return 0; // Indicate successful program termination
=======
    int n = matrix.size();
    //  rotate the matrix 180 degrees

    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {

            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    cout << "Matrix after 180 degree rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
>>>>>>> 549b0d8 (file update)
}
