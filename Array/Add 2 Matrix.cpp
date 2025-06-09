<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{
    // First 2D array (matrix) with 3 rows and 3 columns, initialized with given values
    int arr1[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Second 2D array (matrix) with 3 rows and 3 columns, initialized with given values
    int arr2[3][3] = {11, 23, 33,
                      41, 55, 61,
                      74, 85, 99};

    // Resultant matrix to store the sum of arr1 and arr2
    int ans[3][3];

    // Loop through each row
    for (int i = 0; i < 3; i++)
    {
        // Loop through each column of the current row
        for (int j = 0; j < 3; j++)
        {
            // Add corresponding elements from arr1 and arr2 and store in ans
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // Output the resulting matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " "; // Print each element followed by a space
        }
    }

    return 0; // End of program
}
=======
#include <iostream>
using namespace std;

int main()
{
    // First 2D array
    int arr1[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Second 2D array
    int arr2[3][3] = {11, 23, 33,
                      41, 55, 61,
                      74, 85, 99};

    int ans[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}
>>>>>>> 549b0d8 (file update)
