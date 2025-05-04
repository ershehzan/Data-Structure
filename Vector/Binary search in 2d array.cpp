// Program to perform binary search in a 2D matrix
#include <iostream>  // Include library for input-output operations
#include <vector>    // Include library for using the vector container
using namespace std; // Use the standard namespace to simplify code

int main()
{
    /*
     * Initialize a 4x4 2D vector (matrix) with sample values.
     * The matrix is assumed to be sorted row-wise and column-wise for binary search to work.
     */
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    int x; // Variable to store the element to be searched

    // Prompt the user to enter the element to search in the matrix
    cout << "Enter the element to be searched: ";
    cin >> x;

    // Dimensions of the matrix (rows: n, columns: m)
    int n = 4, m = 4;

    /*
     * Define the search space for binary search.
     * Treat the 2D matrix as a flattened 1D array for simplicity.
     * `start` points to the first element, and `end` points to the last element.
     */
    int start = 0, end = n * m - 1;

    // Perform binary search within the defined search space
    while (start <= end)
    {
        // Calculate the middle index of the current search space
        int mid = (start + end) / 2;

        /*
         * Map the 1D index `mid` to the corresponding 2D indices (`row_index`, `col_index`).
         * `row_index` is determined by dividing `mid` by the number of columns.
         * `col_index` is determined by taking the remainder when `mid` is divided by the number of columns.
         */
        int row_index = mid / m;
        int col_index = mid % m;

        // Access the element at the calculated 2D indices
        int k = arr[row_index][col_index];

        // Check if the current element matches the target value `x`
        if (k == x)
        {
            // If the element is found, print its position and exit the program
            cout << "Element found at index: " << mid << endl; // The index in the flattened array
            return 0;
        }
        else if (k < x) // If the current element is less than `x`
        {
            // Narrow the search space to the upper half
            start = mid + 1;
        }
        else // If the current element is greater than `x`
        {
            // Narrow the search space to the lower half
            end = mid - 1;
        }
    }

    // If the loop ends, the element is not found in the matrix
    cout << "Element not found." << endl;

    return 0; // Indicate successful program termination
}
