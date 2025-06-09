<<<<<<< HEAD
// Program to rotate a matrix 90 degrees anticlockwise
#include <iostream>  // Include library for input-output operations
#include <vector>    // Include library for using the vector container
using namespace std; // Use the standard namespace to simplify code

int main()
{
    /*
     * Initialize a 4x4 matrix with sample values.
     * This matrix will be rotated 90 degrees anticlockwise.
     */
=======
#include <iostream>
#include <vector>
using namespace std;
int main()
{
>>>>>>> 549b0d8 (file update)
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
<<<<<<< HEAD
    
    int n = matrix.size(); // Get the size of the matrix (number of rows/columns)

    // Step 1: Transpose the matrix
    /*
     * Transpose involves swapping elements at positions (i, j) with (j, i).
     * This converts rows into columns and vice versa.
     */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]); // Swap elements to transpose the matrix
        }
    }

    // Step 2: Reverse the columns of the transposed matrix
    /*
     * To achieve a 90-degree anticlockwise rotation, we reverse the elements
     * in each column after transposing the matrix.
     */
    for (int j = 0; j < n; j++) { // Iterate through each column
        int start = 0, end = n - 1; // Define pointers for start and end of the column

        while (start < end) {
            // Swap elements at the top and bottom of the column
            swap(matrix[start][j], matrix[end][j]);
            start++; // Move start pointer downward
            end--;   // Move end pointer upward
        }
    }

    // Output the rotated matrix
    cout << "Matrix after 90 degree Anticlockwise rotation:" << endl;
    for (int i = 0; i < 4; i++) { // Loop through each row
        for (int j = 0; j < 4; j++) { // Loop through each column
            cout << matrix[i][j] << " "; // Print the element
        }
        cout << endl; // Move to the next line after printing a row
    }

    return 0; // Indicate successful program termination
}
=======
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
>>>>>>> 549b0d8 (file update)
