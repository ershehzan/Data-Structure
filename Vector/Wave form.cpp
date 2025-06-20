#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialize a 2D vector (matrix) with values
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "wave form" << endl;

    // Traverse the matrix column by column
    for (int j = 0; j < 4; j++)
    {
        // If the column index is even, traverse from top to bottom
        if (j % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        // If the column index is odd, traverse from bottom to top
        else
        {
            for (int i = 2; i >= 0; i--)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
    return 0;
}
