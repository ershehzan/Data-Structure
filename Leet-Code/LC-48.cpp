<<<<<<< HEAD
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
    int n = matrix.size(); // Get the size of the matrix (number of rows or columns)

    // Step 1: Transpose the matrix (swap rows with columns)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap element at (i, j) with element at (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row to complete the 90-degree rotation
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        // Use two pointers to reverse elements in the row
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }

    // Print the rotated matrix
    cout << "Matrix after 90 degree rotation:" << endl;
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
=======
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
// reverse the matrix
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

    cout << "Matrix after 90 degree rotation:" << endl;
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
>>>>>>> 549b0d8 (file update)
