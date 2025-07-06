#include <iostream>
using namespace std;

// Function to print the elements of a 2D array
// arr: 2D array to print
// row: number of rows in the array
// col: number of columns in the array
void print(int arr[][4], int row, int col)
{
    // Loop through each row
    for (int i = 0; i < row; i++)
    {
        // Loop through each column in the current row
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " "; // Print the current element followed by a space
    }
    // Note: This function prints all elements in one line.
}

int main()
{
    // Declare and initialize a 2D array with 3 rows and 4 columns
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Print a comment to clarify the meaning of i and j
    // i = row index, j = column index
    // Loop to print the array elements row by row
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " "; // Print current element followed by a space
    }

    // Call the print function to print the array elements again
    print(arr, 3, 4);

    return 0; // End of the program
}
