#include <iostream>
#include <vector>
using namespace std;

// Rotates the matrix by 90 degrees clockwise
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose the matrix: swap elements across the diagonal
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row to complete 90-degree rotation
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
}

// Prints the matrix to the console
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " "; // Print each element in the row
        }
        cout << endl; // Newline after each row
    }
}

int main()
{
    // Initialize a 4x4 matrix with values from 1 to 16
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int k;
    cout << "Enter the value of k: ";
    cin >> k; // User enters the number of 90-degree rotations

    k = k % 4; // Only 0-3 rotations needed (as rotating 4 times results in the original matrix)
    if (k < 0) // Handle negative rotations
    {
        k += 4;
    }

    // Perform the rotation k times
    for (int i = 0; i < k; i++)
    {
        rotate(matrix);
    }

    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix); // Output the rotated matrix

    return 0; // Program ends
}
