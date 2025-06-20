#include <iostream>
#include <vector>
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

    // --- Step 1: Reverse each column (vertical flip) ---
    // This loop reverses the order of elements in each column
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]); // Swap top and bottom elements in the column
            start++;
            end--;
        }
    }

    // --- Step 2: Reverse each row (horizontal flip) ---
    // This loop reverses the order of elements in each row
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]); // Swap left and right elements in the row
            start++;
            end--;
        }
    }

    // After both flips, the matrix is rotated by 180 degrees

    // --- Output the rotated matrix ---
    cout << "Matrix after 180 degree rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " "; // Print each element
        }
        cout << endl; // Move to the next row
    }

    return 0; // End of program
}
