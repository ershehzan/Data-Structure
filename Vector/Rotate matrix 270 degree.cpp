// Rotate Matrix 90 degree Anticlockwise
// same as Rotate Matrix 270 degree Clockwise

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
        {13, 14, 15, 16}
    };

    int n = matrix.size(); // Size of the matrix

    // --- Step 1: Reverse each column (vertical flip) ---
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]); // Swap top and bottom elements in each column
            start++;
            end--;
        }
    }

    // --- Step 2: Reverse each row (horizontal flip) ---
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]); // Swap left and right elements in each row
            start++;
            end--;
        }
    }

    // --- Step 3: Transpose the matrix (swap across the diagonal) ---
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // --- Step 4: Reverse each row again (horizontal flip) ---
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

    // Print the resulting matrix after 270 degree rotation
    cout << "Matrix after 270 degree rotation:" << endl;
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
