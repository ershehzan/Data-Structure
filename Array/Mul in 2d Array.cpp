#include <iostream>
using namespace std;

int main()
{
    // First 2D array
    int arr1[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Second 2D array
    int arr2[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    int ans[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = arr1[i][j] * arr2[i][j];
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
