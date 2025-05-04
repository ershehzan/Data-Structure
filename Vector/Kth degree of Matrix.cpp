// Program to rotate a matrix k times (90 degrees clockwise per rotation)
#include <iostream>  // Include library for input-output operations
#include <vector>    // Include library for using the vector container
using namespace std; // Use the standard namespace to simplify code

/*
 * Function to rotate the matrix by 90 degrees clockwise.
 * This is achieved in two steps:
 * 1. Transposing the matrix: Rows become columns and vice versa.
 * 2. Reversing each row to complete the 90-degree rotation.
 */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // Get the size of the matrix (n x n)

    // Step 1: Transpose the matrix
    /*
     * Transpose involves swapping elements at positions (i, j) with (j, i).
     * This converts rows into columns and vice versa.
     */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]); // Swap elements to transpose the matrix
        }
    }

    // Step 2: Reverse each row
    /*
     * To achieve the 90-degree clockwise rotation, reverse the elements in each row.
     * For each row, swap the elements at the start and end, moving toward the center.
     */
    for (int i = 0; i < n; i++) // Iterate through each row
    {
        int start = 0, end = n - 1; // Define pointers for the start and end of the row

        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]); // Swap elements at the start and end
            start++; // Move the start pointer to the right
            end--;   // Move the end pointer to the left
        }
    }
}

/*
 * Function to print the matrix.
 * This function iterates through each element of the matrix and displays it.
 */
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size(); // Get the size of the matrix (n x n)
    for (int i = 0; i < n; i++) // Loop through each row
    {
        for (int j = 0; j < n; j++) // Loop through each column
        {
            cout << matrix[i][j] << " "; // Print the element followed by a space
        }
        cout << endl; // Move to the next line after printing a row
    }
}

int main()
{
    /*
     * Initialize a 4x4 matrix with sample values.
     * This matrix will be rotated k times (90 degrees clockwise per rotation).
     */
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int k; // Variable to store the number of 90-degree rotations

    // Prompt the user to enter the value of k
    cout << "Enter the value of k: ";
    cin >> k;

    // Normalize k to be within 0 to 3 (as rotating 4 times results in the original matrix)
    k = k % 4; // Use modulo operation to limit k within the range [0, 3]
    if (k < 0) // Handle negative rotations (convert to equivalent positive rotations)
    {
        k += 4;
    }

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
