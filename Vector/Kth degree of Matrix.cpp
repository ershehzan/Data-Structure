#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
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
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
<<<<<<< HEAD
    /*
     * Initialize a 4x4 matrix with sample values.
     * This matrix will be rotated k times (90 degrees clockwise per rotation).
     */
=======
>>>>>>> 549b0d8 (file update)
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

<<<<<<< HEAD
    int k; // Variable to store the number of 90-degree rotations

    // Prompt the user to enter the value of k
    cout << "Enter the value of k: ";
    cin >> k;

    // Normalize k to be within 0 to 3 (as rotating 4 times results in the original matrix)
    k = k % 4; // Use modulo operation to limit k within the range [0, 3]
    if (k < 0) // Handle negative rotations (convert to equivalent positive rotations)
=======
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    k = k % 4; // Normalize k to be within 0 to 3
    if (k < 0)
>>>>>>> 549b0d8 (file update)
    {
        k += 4;
    }

<<<<<<< HEAD
    // Perform k rotations
    for (int i = 0; i < k; i++) // Rotate the matrix k times
    {
        rotate(matrix); // Call the rotate function for each 90-degree rotation
    }

    // Output the rotated matrix
    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix); // Print the final rotated matrix

    return 0; // Indicate successful program termination
}
=======
    for (int i = 0; i < k; i++)
    {
        rotate(matrix);
    }

    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix);

    return 0;
}
>>>>>>> 549b0d8 (file update)
