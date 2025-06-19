#include <iostream>      // For input/output stream
#include <vector>        // For using the vector container
using namespace std;

int main()
{
    // Initialize a 4x4 2D vector with increasing values
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    int x; // Variable to store the element to search for

    // Prompt user to enter the element to be searched
    cout << "Enter the element to be searched: ";
    cin >> x; // Read the element

    int n = 4, m = 4; // Define the number of rows (n) and columns (m)

    // Set the search range in 1D representation of the 2D array (from 0 to n*m-1)
    int start = 0, end = n * m - 1;

    // Perform binary search on the 2D array as if it was a 1D array
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate the middle index

        // Convert the 1D mid index to 2D indices (row and column)
        int row_index = mid / m;
        int col_index = mid % m;

        int k = arr[row_index][col_index]; // Get the value at the calculated position

        if (k == x)
        {
            // If the element is found, print its position (as a 1D index) and exit
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (k < x)
        {
            // If the value is less than the target, search in the right half
            start = mid + 1;
        }
        else
        {
            // If the value is greater than the target, search in the left half
            end = mid - 1;
        }
    }

    // If the element is not found, program ends without any message
    return 0;
}
