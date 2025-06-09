#include <iostream>
#include <vector>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Initialize a 4x4 matrix with given integers
    // This is the original matrix that will be rotated
=======
int main()
{
>>>>>>> 549b0d8 (file update)
    vector<vector<int>> matrix = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};
<<<<<<< HEAD
    
    // Determine the size of the matrix (number of rows/columns)
    int n = matrix.size();

    // Create a temporary matrix 'ans' to store the rotated result
    // This is a 2D array of size n x n
    int ans[n][n];

    // Step 1: Perform a 90-degree rotation
    // Iterate over each element of the original matrix
    for (int i = 0; i < n; i++) // Loop through rows
    {
        for (int j = 0; j < n; j++) // Loop through columns
        {
            // Formula to rotate the matrix 90 degrees clockwise
            // Move the element from position (i, j) in the original matrix
            // to position (j, n - 1 - i) in the rotated matrix
=======
    int n = matrix.size();
    int ans[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
>>>>>>> 549b0d8 (file update)
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

<<<<<<< HEAD
    // Step 2: Output the rotated matrix
    cout << "Matrix after 90 degree rotation:" << endl;
    for (int i = 0; i < 4; i++) // Loop through rows of the rotated matrix
    {
        for (int j = 0; j < 4; j++) // Loop through columns of the rotated matrix
        {
            // Print each element of the rotated matrix
            cout << ans[i][j] << " ";
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}
=======
    cout << "Matrix after 90 degree rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}
>>>>>>> 549b0d8 (file update)
